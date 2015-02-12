/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/08/2015				*
 *							*
 ********************************************************/



#include "../../include/Fractals/burningShip.hpp"



BurningShip::BurningShip ( int maxIters )
{
	m_maxIters = maxIters;
	return;
}



double
BurningShip::Eval ( double x, double y )
{
	complex< double > c( x, y );
	complex< double > z( 0.0, 0.0 );
	int iters;
	for( iters = 0; abs( z ) < 4.0 && iters < m_maxIters; ++iters )
	{
		z = complex< double >( abs( z.real() ), abs( z.imag() ) );
		z = ( z * z ) + c;
	}
	double retVal;
	if( iters == m_maxIters || iters == 0 )
		retVal = 0.0;
	else
		retVal = ( ( double )( iters ) ) / m_maxIters;
	return retVal;
}



void
BurningShip::IncrementDetailLevel ()
{
	m_maxIters *= 2;
	return;
}



void
BurningShip::DecrementDetailLevel ()
{
	m_maxIters /= 2;
	return;
}



void
BurningShip::SetInitialPlotRange ( PlotRange& range )
{
	range.xStart = -2.125;
	range.xEnd = 1.75;
	range.yStart = -2.0;
	range.yEnd = 1.0;
	return;
}



