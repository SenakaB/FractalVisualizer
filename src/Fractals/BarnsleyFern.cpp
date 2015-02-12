/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/08/2015				*
 *							*
 ********************************************************/


#include "../../include/Fractals/BarnsleyFern.hpp"




inline void
BarnsleyFern::SetPixel ( const int y, const int x, float val )
{
	if( x < 0 || y < 0 || m_buffer.cols <= x || m_buffer.rows <= y )
		return;
	float* p_pixel = ( float* ) m_buffer.data;
	int idx = ( y * m_buffer.cols ) + ( x );
	p_pixel[ idx ] = val;
	return;
}





inline float
BarnsleyFern::GetPixel ( const int y, const int x )
{
	if( x < 0 || y < 0 || m_buffer.cols <= x || m_buffer.rows <= y )
		return -1;
	float* p_pixel = ( float* ) m_buffer.data;
	int idx = ( y * m_buffer.cols ) + ( x );
	return p_pixel[ idx ];
}





void
BarnsleyFern::NormalizeBuffer ()
{
	float* p_data = ( float* ) m_buffer.data;
	int bufSize = m_buffer.rows * m_buffer.cols;
	float maxVal = -1;
	for( int px = 0; px < bufSize; ++px )
		if( p_data[ px ] > maxVal )
			maxVal = p_data[ px ];
	for( int px = 0; px < bufSize; ++px )
		p_data[ px ] /= maxVal;
	return;
}


int
BarnsleyFern::LeafGenerator ()
{
	double oldX = 0.0;
	double oldY = 0.0;
	for( int i = 0; i < m_sqrtIters; ++i )
	{
		for( int j = 0; j < m_sqrtIters; ++j )
		{
			double x, y;
			int opt = rand() % 100;
			if( opt < STEM_PROB )
			{
				x = 0.0;
				y = 0.16 * oldY;
			}
			else if( opt < STEM_PROB + SMALLER_LEAFLET_PROB )
			{
				x = ( 0.85 * oldX ) + ( 0.04 * oldY );
				y = ( -0.04 * oldX ) + ( 0.85 * oldY ) + 1.6;
			}
			else if( opt < STEM_PROB + SMALLER_LEAFLET_PROB + LARGEST_LEFT_LEAFLET_PROB )
			{
				x = ( 0.2 * oldX ) + ( -0.26 * oldY );
				y = ( 0.23 * oldX ) + ( 0.22 * oldY ) + 1.6;
			}
			else
			{
				x = ( -0.15 * oldX ) + ( 0.28 * oldY );
				y = ( 0.26 * oldX ) + ( 0.24 * oldY ) + 0.44;
			}
			int px = ( ( int ) ( m_buffer.cols * ( x - X_START ) / ( X_END - X_START ) ) );
			int py = m_buffer.rows - ( ( int ) ( m_buffer.rows * ( y - Y_START ) / ( Y_END - Y_START ) ) );
	
			if( m_additive )
			{
				float curVal = GetPixel( py, px );
				SetPixel( py, px, curVal + 1.0f );
			}
			else
				SetPixel( py, px, 1.0f );
			oldX = x;
			oldY = y;
		}
	}

	if( m_additive )
		NormalizeBuffer();
	return 0;
}





BarnsleyFern::BarnsleyFern ( int detailLevel, int sqrtIters, bool additive )
{
	m_sqrtIters = sqrtIters;
	m_detailLevel = detailLevel;
	m_additive = additive;

	int gridSize = ( int ) pow( 10, m_detailLevel );
	m_buffer = Mat::zeros( gridSize, gridSize, CV_32FC1 );
	
	LeafGenerator();
	return;
}



double
BarnsleyFern::Eval ( double x, double y )
{
	int xc = ( ( int ) ( m_buffer.cols * ( x - X_START ) / ( X_END - X_START ) ) );
	int yc = ( ( int ) ( m_buffer.rows * ( y - Y_START ) / ( Y_END - Y_START ) ) );


	return GetPixel( yc, xc ); 
}





void
BarnsleyFern::IncrementDetailLevel ()
{
	return;
}


void
BarnsleyFern::DecrementDetailLevel ()
{
	return;
}



void
BarnsleyFern::SetInitialPlotRange ( PlotRange& range )
{
	range.xStart = X_START;
	range.xEnd = X_END;
	range.yStart = Y_START;
	range.yEnd = Y_END;
	return;
}


