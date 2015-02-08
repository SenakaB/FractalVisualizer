/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include <iostream>
#include <complex>

#include "../fractal.hpp"


using namespace std;

#ifndef __MANDLEBROT_HPP__INCLUDED__
#define __MANDLEBROT_HPP__INCLUDED__

class MandlebrotSet : Fractal
{
	public :
		MandlebrotSet( int maxIters = 1000 );

		double Eval ( double x, double y );

		void IncrementDetailLevel ();
		void DecrementDetailLevel ();

		void SetInitialPlotRange ( PlotRange& range );



	private :
		int m_maxIters;
};

#endif

