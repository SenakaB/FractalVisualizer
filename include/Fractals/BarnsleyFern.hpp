/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/08/2015				*
 *							*
 ********************************************************/

#ifndef __BARNSLEYFERN_HPP__INCLUDED__
#define __BARNSLEYFERN_HPP__INCLUDED__


#include <iostream>
#include <cstdlib>

#include <opencv2/opencv.hpp>

#include "../fractal.hpp"


using namespace std;
using namespace cv;


class BarnsleyFern : Fractal
{
	public :
		BarnsleyFern( int detialLevel = 4, int sqrtIters = 10000, bool additive = false );

		double Eval ( double x, double y );

		void IncrementDetailLevel ();
		void DecrementDetailLevel ();

		void SetInitialPlotRange ( PlotRange& range );



	private :
		int m_detailLevel;
		Mat m_buffer;
		int m_sqrtIters;
		bool m_additive;

		const int STEM_PROB 			= 1;
		const int SMALLER_LEAFLET_PROB		= 85;
		const int LARGEST_LEFT_LEAFLET_PROB	= 7;
		const int LARGEST_RIGHT_LEAFLET_PROB	= 7;

		const double X_START 			= -7.0;
		const double X_END 			= 7.0;
		const double Y_START 			= 0.0;
		const double Y_END 			= 10.0;

		inline void SetPixel ( const int y, const int x, float val );
		inline float GetPixel ( const int y, const int x );
		void NormalizeBuffer ();
		int LeafGenerator ();
};

#endif

