/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/





#include "../../include/ColorMaps/grayscaleLogarithmic.hpp"

Scalar
GrayscaleLog::GetColor ( double value )
{
	double m = log( value );
	return Scalar( ( int ) 255 * m, ( int ) 255 * m, ( int ) 255 * m );
}

