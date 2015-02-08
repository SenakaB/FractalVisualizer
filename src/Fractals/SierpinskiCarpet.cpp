#include "../../include/Fractals/SierpinskiCarpet.hpp"




inline void
SierpinskiCarpet::SetPixel ( const int y, const int x, int val )
{
	if( x < 0 || y < 0 || m_buffer.cols <= x || m_buffer.rows <= y )
		return;
	uint8_t* p_pixel = ( uint8_t* ) m_buffer.data;
	int idx = ( y * m_buffer.cols ) + ( x );
	p_pixel[ idx ] = val;
	return;
}





inline int
SierpinskiCarpet::GetPixel ( const int y, const int x )
{
	if( x < 0 || y < 0 || m_buffer.cols <= x || m_buffer.rows <= y )
		return -1;
	uint8_t* p_pixel = ( uint8_t* ) m_buffer.data;
	int idx = ( y * m_buffer.cols ) + ( x );
	return p_pixel[ idx ];
}





int
SierpinskiCarpet::CarpetRecursion ( int y1, int x1, int y2, int x2 )
{
	int segmentSize = ( x2 - x1 ) / 3;
	if( segmentSize == 0 )
		return 0;

	for( int y = y1 + segmentSize; y < y1 + 2 * segmentSize; ++y )
		for( int x = x1 + segmentSize; x < x1 + 2 * segmentSize; ++x )
			SetPixel( y, x, 0 );
	
	CarpetRecursion( y1, x1, y1 + segmentSize, x1 + segmentSize );
	CarpetRecursion( y1, x1 + segmentSize, y1 + segmentSize, x1 + 2 * segmentSize );
	CarpetRecursion( y1, x1 + 2 * segmentSize, y1 + segmentSize, x2 );


	CarpetRecursion( y1 + segmentSize, x1, y1 + 2 * segmentSize, x1 + segmentSize );
	CarpetRecursion( y1 + segmentSize, x1 + segmentSize, y1 + 2 * segmentSize, x1 + 2 * segmentSize );
	CarpetRecursion( y1 + segmentSize, x1 + 2 * segmentSize, y1 + 2 * segmentSize, x2 );

	CarpetRecursion( y1 + 2 * segmentSize, x1, y2, x1 + segmentSize );
	CarpetRecursion( y1 + 2 * segmentSize, x1 + segmentSize, y2, x1 + 2 * segmentSize );
	CarpetRecursion( y1 + 2 * segmentSize, x1 + 2 * segmentSize, y2, x2 );
	
	return 0;
}





SierpinskiCarpet::SierpinskiCarpet ( int detailLevel, int lineThickness )
{
	m_detailLevel = detailLevel;
	int gridSize = ( int ) pow( 10, m_detailLevel );
	m_buffer = Mat::ones( 2 * gridSize, 2 * gridSize, CV_8U );

	CarpetRecursion( 0, 0, 2 * gridSize, 2 * gridSize );
	return;
}



double
SierpinskiCarpet::Eval ( double x, double y )
{
	if( x < -1.0 || y < -1.0 || x > 1.0 || y > 1.0 )
		return 0.0;
	int mult = 1;
	for( int i = 0; i < m_detailLevel; ++i )
		mult *= 10;
	int xc = ( int ) mult * ( x + 1.0 );
	int yc = ( int ) mult * ( y + 1.0 );

	return GetPixel( yc, xc ); 
	//return;
}





void
SierpinskiCarpet::IncrementDetailLevel ()
{
	return;
}


void
SierpinskiCarpet::DecrementDetailLevel ()
{
	return;
}



void
SierpinskiCarpet::SetInitialPlotRange ( PlotRange& range )
{
	range.xStart = -1.1;
	range.xEnd = 1.1;
	range.yStart = -0.8;
	range.yEnd = 0.8;
	return;
}


