/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/





#include "../include/plot.hpp"


Plot::Plot ( Fractal* p_fractal, ColorMap* p_colorMap )
{
	mp_fractal = p_fractal;
	mp_colorMap = p_colorMap;
	m_range.xStart = NAN;
	m_range.xEnd = NAN;
	m_range.yStart = NAN;
	m_range.yEnd = NAN;
	return;
}




Mat
Plot::GenerateFrame ( int frameHeight, int frameWidth )
{
	Mat frame = Mat::zeros( frameHeight, frameWidth, CV_8UC3 );
	if( m_range.xStart == NAN || m_range.yStart == NAN || m_range.xEnd == NAN || m_range.yEnd == NAN )
		return frame;

	Point pt;
	for( pt.y = 0; pt.y < frameHeight; ++pt.y )
	{
		for( pt.x = 0; pt.x < frameWidth; ++pt.x )
		{	
			double x = ( ( ( m_range.xEnd - m_range.xStart ) * pt.x ) / frameWidth ) + m_range.xStart;
			double y = ( ( ( m_range.yEnd - m_range.yStart ) * pt.y ) / frameHeight ) + m_range.yStart;
			double retVal = mp_fractal->Eval( x, y );
			Scalar bgr = mp_colorMap->GetColor( retVal );
			SetPixel( frame, pt, bgr );
		}
	}

	return frame;

}




inline void
Plot::SetPixel ( Mat& frame, const Point& pt, const Scalar bgr )
{
	if( pt.x < 0 || pt.y < 0 || frame.cols <= pt.x || frame.rows <= pt.y )
		return;
	uint8_t* p_pixel = (uint8_t *) frame.data;
	int cn = frame.channels();
	int idx = ( pt.y * frame.cols * cn ) + ( pt.x * cn );
	p_pixel[ idx     ] = bgr[ 0 ];
	p_pixel[ idx + 1 ] = bgr[ 1 ];
	p_pixel[ idx + 2 ] = bgr[ 2 ];
	return;
}


