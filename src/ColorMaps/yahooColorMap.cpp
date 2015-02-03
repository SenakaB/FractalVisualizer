/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include "../../include/ColorMaps/yahooColorMap.hpp"

Scalar
YahooColorMap::GetColor ( double value )
{
	Scalar hsv = ToHSV( Scalar( 255, 0, 115 ) );				// Brightest color in our branding
	//Scalar hsv = ToHSV( Scalar( 144, 0, 64 ) );				// Logo color
	double m = sqrt( value );
	m = sqrt( m );
	//m = sqrt( m );
	hsv[ 2 ] *= m;
	return ToBGR( hsv );
}


