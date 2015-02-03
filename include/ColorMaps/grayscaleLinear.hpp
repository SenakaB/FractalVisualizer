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

