/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include <algorithm>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#ifndef __COLORMAP_HPP__INCLUDED__
#define __COLORMAP_HPP__INCLUDED__

class ColorMap
{
	protected :
		Scalar ToHSV ( const Scalar& bgr );
		Scalar ToBGR ( const Scalar& hsv );


	public :
		virtual Scalar GetColor ( double value ) = 0;
		
		

		int TestColorConversion ();
};

#endif

