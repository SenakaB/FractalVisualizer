/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/


#ifndef __FRACTAL_HPP__INCLUDED__
#define __FRACTAL_HPP__INCLUDED__

#include "./plotRange.hpp"

class Fractal
{
	public :
		virtual double Eval( double x, double y ) = 0;

		virtual void IncrementDetailLevel () = 0;
		virtual void DecrementDetailLevel () = 0;

		virtual void SetInitialPlotRange ( PlotRange& range ) = 0;
};


#endif

