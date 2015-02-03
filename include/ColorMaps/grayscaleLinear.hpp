/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/





#include <cstdio>

#include "../colorMap.hpp"

#ifndef __GRAYSCALELINEAR_HPP__INCLUDED__
#define __GRAYSCALELINEAR_HPP__INCLUDED__

class GrayscaleLinear : ColorMap
{
	public :
		Scalar GetColor ( double value );
};

#endif

