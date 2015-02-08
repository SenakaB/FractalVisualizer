/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/05/2015				*
 *							*
 ********************************************************/



#include <iostream>
#include <complex>

#include <opencv2/opencv.hpp>

#include "../fractal.hpp"


using namespace std;
using namespace cv;

#ifndef __SIERPINSKICARPET_HPP__INCLUDED__
#define __SIERPINSKICARPET_HPP__INCLUDED__

class SierpinskiCarpet : Fractal
{
	public :
		SierpinskiCarpet( int detialLevel = 4, int lineThickness = 1 );

		double Eval ( double x, double y );

		void IncrementDetailLevel ();
		void DecrementDetailLevel ();

		void SetInitialPlotRange ( PlotRange& range );



	private :
		int m_detailLevel;
		int m_lineThickness;
		Mat m_buffer;



		inline void SetPixel ( const int y, const int x, int val );
		inline int GetPixel ( const int y, const int x );
		int CarpetRecursion ( int y1, int x1, int y2, int x2 );
};

#endif

