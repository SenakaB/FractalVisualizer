/********************************************************
 *							*
 *	Created by : Senaka Buthpitiya			*
 *	Created on : 02/01/2015				*
 *							*
 ********************************************************/



#include <iostream>

#include <opencv2/opencv.hpp>

#include "../include/definitions.hpp"
#include "../include/plot.hpp"

#include "../include/fractal.hpp"
#include "../include/Fractals/MandlebrotSet.hpp"
#include "../include/Fractals/burningShip.hpp"
#include "../include/Fractals/SierpinskiCarpet.hpp"
#include "../include/Fractals/BarnsleyFern.hpp"

#include "../include/colorMap.hpp"
#include "../include/ColorMaps/grayscaleLinear.hpp"
#include "../include/ColorMaps/grayscaleLogarithmic.hpp"
#include "../include/ColorMaps/YahooColorMap.hpp"


using namespace std;
using namespace cv;


#define SCR_W			1100
#define SCR_H			800
//#define SCR_W			330
//#define SCR_H			240

#define FRAME_W			SCR_W
#define FRAME_H			SCR_H







void FracVizMouseClickCallbackFunc ( int event, int x, int y, int flags, void* p_userdata )
{
	if  ( event == EVENT_LBUTTONDOWN )
	{
		Plot* p_plot = ( Plot* ) p_userdata;
		double plotX = ( p_plot->m_range.xEnd - p_plot->m_range.xStart ) * ( ( double ) x ) / SCR_W + p_plot->m_range.xStart;
		double plotY = ( p_plot->m_range.yEnd - p_plot->m_range.yStart ) * ( ( double ) y ) / SCR_H + p_plot->m_range.yStart;

		p_plot->ZoomIn( plotY, plotX, 16.0 );
		Mat frame = p_plot->GenerateFrame( FRAME_H, FRAME_W );
		imshow( "FracViz", frame );
	}
	else if  ( event == EVENT_RBUTTONDOWN )
	{	
		Plot* p_plot = ( Plot* ) p_userdata;
		p_plot->ZoomOut( 16.0 );
		Mat frame = p_plot->GenerateFrame( FRAME_H, FRAME_W );
		imshow( "FracViz", frame );
	}
	else if  ( event == EVENT_MBUTTONDOWN )
	{
		Plot* p_plot = ( Plot* ) p_userdata;
		Mat frame = p_plot->GenerateFrame( FRAME_H, FRAME_W );
		time_t  timev;
		time( &timev );
		stringstream ss;
		ss << "./output/" << timev << ".jpg";
		imwrite( ss.str(), frame );
		cout << "Image saved as " << ss.str() << "." << endl;
	}
	else if ( event == EVENT_MOUSEMOVE )
	{
		//cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
	}
	return;
}





int main ( int argc, char** argv )
{
	//Fractal* p_fractal = ( Fractal* ) new MandlebrotSet( 256 ); //1024 );
	//Fractal* p_fractal = ( Fractal* ) new BurningShip( 256 );
	//Fractal* p_fractal = ( Fractal* ) new SierpinskiCarpet( 4, 1 );
	Fractal* p_fractal = ( Fractal* ) new BarnsleyFern( 4, 10000, true );
	
	//ColorMap* p_colorMap = ( ColorMap* ) new GrayscaleLinear();
	//ColorMap* p_colorMap = ( ColorMap* ) new GrayscaleLog();
	ColorMap* p_colorMap = ( ColorMap* ) new YahooColorMap();



	
	Plot plot( p_fractal, p_colorMap );
	p_fractal->SetInitialPlotRange( plot.m_range );


	
	
	namedWindow( "FracViz", CV_WINDOW_AUTOSIZE );

	Mat frame = plot.GenerateFrame( FRAME_H, FRAME_W );

	imshow( "FracViz", frame );

	setMouseCallback( "FracViz", FracVizMouseClickCallbackFunc, &plot );


	waitKey( 0 );
	destroyAllWindows();
	
	return 0;
}

