#include "../include/colorMap.hpp"


Scalar
ColorMap::ToHSV ( const Scalar& bgr )
{
	Scalar 		hsv;
	double 		cmin, cmax, delta;

	cmin = min( min( bgr[ 0 ], bgr[ 1 ] ), bgr[ 2 ] );
	cmax = max( max( bgr[ 0 ], bgr[ 1 ] ), bgr[ 2 ] );

	hsv[ 2 ] = cmax;							// v
	delta = cmax - cmin;
	if( cmax > 0.0 )
	{
		// NOTE: if cmax is == 0, this divide would cause a crash
		hsv[ 1 ] = ( delta / cmax );					// s
	}
	else									// if max is 0, then r = g = b = 0 THEN s = 0, v is undefined
	{
	    hsv[ 1 ] = 0.0;
	    hsv[ 0 ] = NAN;							// its now undefined
	    return hsv;
	}
	if( bgr[ 2 ] >= cmax )							// > is bogus, just keeps compilor happy
		hsv[ 0 ] = ( bgr[ 1 ] - bgr[ 0 ] ) / delta;			// between yellow & magenta
	else if( bgr[ 1 ] >= cmax )
		hsv[ 0 ] = 2.0 + ( bgr[ 0 ] - bgr[ 2 ] ) / delta;		// between cyan & yellow
	else
		hsv[ 0 ] = 4.0 + ( bgr[ 2 ] - bgr[ 1 ] ) / delta;		// between magenta & cyan
	hsv[ 0 ] *= 60.0;							// degrees

	if( hsv[ 0 ] < 0.0 )
		hsv[ 0 ] += 360.0;
	return hsv;
}










Scalar
ColorMap::ToBGR ( const Scalar& hsv )
{
	double		hh, p, q, t, ff;
	long		i;
	Scalar		bgr;

	if( hsv[ 1 ] <= 0.0 )							// < is bogus, just shuts up warnings
	{
		bgr[ 2 ] = hsv[ 2 ];
		bgr[ 1 ] = hsv[ 2 ];
		bgr[ 0 ] = hsv[ 2 ];
		return bgr;
	}
	hh = hsv[ 0 ];
	if( hh >= 360.0 )
		hh = 0.0;
	hh /= 60.0;
	i = ( long ) hh;
	ff = hh - i;
	p = hsv[ 2 ] * ( 1.0 - hsv[ 1 ] );
	q = hsv[ 2 ] * ( 1.0 - ( hsv[ 1 ] * ff ) );
	t = hsv[ 2 ] * ( 1.0 - ( hsv[ 1 ] * ( 1.0 - ff ) ) );

	switch( i )
	{
		case 0:
			bgr[ 2 ] = hsv[ 2 ];
			bgr[ 1 ] = t;
			bgr[ 0 ] = p;
			break;
		case 1:
			bgr[ 2 ] = q;
			bgr[ 1 ] = hsv[ 2 ];
			bgr[ 0 ] = p;
			break;
		case 2:
			bgr[ 2 ] = p;
			bgr[ 1 ] = hsv[ 2 ];
			bgr[ 0 ] = t;
			break;
		case 3:
			bgr[ 2 ] = p;
			bgr[ 1 ] = q;
			bgr[ 0 ] = hsv[ 2 ];
			break;
		case 4:
			bgr[ 2 ] = t;
			bgr[ 1 ] = p;
			bgr[ 0 ] = hsv[ 2 ];
			break;
		case 5:
		default:
			bgr[ 2 ] = hsv[ 2 ];
			bgr[ 1 ] = p;
			bgr[ 0 ] = q;
			break;
	}
	return Scalar( ( int ) bgr[ 0 ], ( int ) bgr[ 1 ], ( int ) bgr[ 2 ] );					// convert to int as the program uses RGB-chars only
	//return bgr;
} 











int
ColorMap::TestColorConversion ()
{
	cout << "RGB -> HSV -> RGB" << endl;

	for( int b = 0; b < 256; b += 16 )
		for( int g = 0; g < 256; g += 16 )
			for( int r = 0; r < 256; r += 16 )
			{
				Scalar hsv = ToHSV( Scalar( b, g, r ) );
				Scalar bgr = ToBGR( hsv );
				if( 	( bgr[ 0 ] < b - 1 ) || ( bgr[ 0 ] > b + 1 ) ||
					( bgr[ 1 ] < g - 1 ) || ( bgr[ 1 ] > g + 1 ) ||
					( bgr[ 2 ] < r - 1 ) || ( bgr[ 2 ] > r + 1 ) 	)
				{
					cout << "Error:" << endl;
					cout << b << ", " << g << ", " << r << endl;
					cout << hsv[ 0 ] << ", " << hsv[ 1 ] << ", " << hsv[ 2 ] << endl;
					cout << bgr[ 0 ] << ", " << bgr[ 1 ] << ", " << bgr[ 2 ] << endl;
					return -1;
				}



			}


	cout << "HSV -> RGB -> HSV" << endl;
	for( int h = 1; h < 360; ++h )
		for( float s = 0.0f; s <= 1.0f; s += 0.1 )
			for( float v = 0.0f; v <= 1.0f; v += 0.1 )
			{
				Scalar bgr = ToHSV( Scalar( h, s, v ) );
				Scalar hsv = ToBGR( bgr );
				if( 	( hsv[ 0 ] != h ) ||
					( hsv[ 1 ] < s - 0.01 ) || ( hsv[ 1 ] > s + 0.01 ) || 
					( hsv[ 2 ] < v - 0.01 ) || ( hsv[ 2 ] > v + 0.01 ) )
				{
					cout << "Error:" << endl;
					cout << h << ", " << s << ", " << v << endl;
					cout << bgr[ 0 ] << ", " << bgr[ 1 ] << ", " << bgr[ 2 ] << endl;
					cout << hsv[ 0 ] << ", " << hsv[ 1 ] << ", " << hsv[ 2 ] << endl;
					return -1;
				}



			}
	cout << "Passed." << endl;
	return 0;
}

