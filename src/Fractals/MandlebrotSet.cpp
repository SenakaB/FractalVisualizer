/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include "../../include/Fractals/MandlebrotSet.hpp"



MandlebrotSet::MandlebrotSet ( int maxIters )
{
	m_maxIters = maxIters;
	return;
}



double
MandlebrotSet::Eval ( double x, double y )
{
	complex< double > c( x, y );
	complex< double > z( 0.0, 0.0 );
	int iters;
	for( iters = 0; abs( z ) < 4.0 && iters < m_maxIters; ++iters, z = ( z * z ) + c );
	double retVal;
	if( iters == m_maxIters || iters == 0 )
		retVal = 0.0;
	else
		retVal = ( ( double )( iters ) ) / m_maxIters;
	return retVal;
}



void
MandlebrotSet::IncrementDetailLevel ()
{
	m_maxIters *= 2;
	return;
}



void
MandlebrotSet::DecrementDetailLevel ()
{
	m_maxIters /= 2;
	return;
}



void
MandlebrotSet::SetInitialPlotRange ( PlotRange& range )
{
	range.xStart = -2.5;
	range.xEnd = 0.8;
	range.yStart = -1.2;
	range.yEnd = 1.2;
	return;
}



