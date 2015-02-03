#include "../../include/ColorMaps/grayscaleLogarithmic.hpp"

Scalar
GrayscaleLog::GetColor ( double value )
{
	double m = log( value );
	return Scalar( ( int ) 255 * m, ( int ) 255 * m, ( int ) 255 * m );
}

