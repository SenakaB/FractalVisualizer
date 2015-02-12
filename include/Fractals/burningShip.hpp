/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/08/2015				*
 *							*
 ********************************************************/


#ifndef __BURNINGSHIP_HPP__INCLUDED__
#define __BURNINGSHIP_HPP__INCLUDED__

#include <iostream>
#include <complex>

#include "../fractal.hpp"


using namespace std;



class BurningShip : Fractal
{
	public :
		BurningShip( int maxIters = 512 );

		double Eval ( double x, double y );

		void IncrementDetailLevel ();
		void DecrementDetailLevel ();

		void SetInitialPlotRange ( PlotRange& range );



	private :
		int m_maxIters;
};

#endif

