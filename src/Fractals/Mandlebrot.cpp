/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include "../../include/Fractals/Mandlebrot.hpp"



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



