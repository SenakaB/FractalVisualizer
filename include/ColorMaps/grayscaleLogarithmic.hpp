/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/




#include <cstdio>

#include "../definitions.hpp"
#include "../colorMap.hpp"

#ifndef __GRAYSCALELOGARITHMIC_HPP__INCLUDED__
#define __GRAYSCALELOGARITHMIC_HPP__INCLUDED__

class GrayscaleLog : ColorMap
{
	public :
		Scalar GetColor ( double value );
};

#endif

