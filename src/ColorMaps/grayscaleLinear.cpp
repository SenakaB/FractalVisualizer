#include "../../include/ColorMaps/grayscaleLinear.hpp"

Scalar
GrayscaleLinear::GetColor ( double value )
{
	int v = value * 255;
	return Scalar( v, v, v );
}

