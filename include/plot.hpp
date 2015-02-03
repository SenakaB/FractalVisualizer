/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/




#include <opencv2/opencv.hpp>

#include "./fractal.hpp"
#include "./colorMap.hpp"

using namespace cv;


#ifndef __PLOT_HPP__INCLUDED__
#define __PLOT_HPP__INCLUDED__

struct PlotRange
{
	double xStart, xEnd;
	double yStart, yEnd;
};

class Plot
{
	protected :
		Fractal* 	mp_fractal;
		ColorMap*	mp_colorMap;
		
		inline void SetPixel ( Mat& frame, const Point& pt, const Scalar bgr );

	public : 
		PlotRange 	m_range;


		Plot ( Fractal* p_fractal, ColorMap* p_colorMap );
		Mat GenerateFrame ( int frameHeight, int frameWidth );
};


#endif

