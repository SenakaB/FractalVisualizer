#include <iostream>

#include <opencv2/opencv.hpp>

#include "../include/definitions.hpp"
#include "../include/plot.hpp"

#include "../include/fractal.hpp"
#include "../include/Fractals/Mandlebrot.hpp"

#include "../include/colorMap.hpp"
#include "../include/ColorMaps/grayscaleLinear.hpp"
#include "../include/ColorMaps/grayscaleLogarithmic.hpp"
#include "../include/ColorMaps/yahooColorMap.hpp"


using namespace std;
using namespace cv;


#define SCR_W			1100
#define SCR_H			800
//#define SCR_W			330
//#define SCR_H			240

#define FRAME_W			SCR_W
#define FRAME_H			SCR_H







void FracVizMouseClickCallbackFunc ( int event, int x, int y, int flags, void* userdata )
{
	if  ( event == EVENT_LBUTTONDOWN )
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if  ( event == EVENT_RBUTTONDOWN )
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if  ( event == EVENT_MBUTTONDOWN )
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if ( event == EVENT_MOUSEMOVE )
	{
		//cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
	}
	return;
}





int main ( int argc, char** argv )
{
	Fractal* p_fractal = ( Fractal* ) new MandlebrotSet( 256 ); //1024 );
	//ColorMap* p_colorMap = ( ColorMap* ) new GrayscaleLinear();
	//ColorMap* p_colorMap = ( ColorMap* ) new GrayscaleLog();
	ColorMap* p_colorMap = ( ColorMap* ) new YahooColorMap();




	Plot plot( p_fractal, p_colorMap );
	plot.m_range.xStart = -2.5;
	plot.m_range.xEnd = 0.8;
	plot.m_range.yStart = -1.2;
	plot.m_range.yEnd = 1.2;

	
	
	namedWindow( "FracViz", CV_WINDOW_AUTOSIZE );

	Mat frame = plot.GenerateFrame( FRAME_H, FRAME_W );

	imshow( "FracViz", frame );

	setMouseCallback( "FracViz", FracVizMouseClickCallbackFunc, &plot );


	waitKey( 0 );
	destroyAllWindows();
	
	return 0;
}

