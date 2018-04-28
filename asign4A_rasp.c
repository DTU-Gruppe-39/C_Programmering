/********************************************************************************
|  CLASS:         62409 C programming for Java programmers
|  PROGRAM:       lab28.c   
|  DATE:          MAR 2018
|  DESCRIPTION:   Capture video
********************************************************************************/
#include "opencv2/highgui/highgui.hpp" //  required for OpenCV functions
#include <stdio.h>                     // Standard I/O - required for printf() function
#include "opencv2/imgproc/imgproc_c.h"

int main()
{
	CvCapture* capture;
	int c;
	

	// Read the video stream
	capture = cvCaptureFromCAM( 0 );
	cvNamedWindow("Video",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Video1",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("VideoRes",CV_WINDOW_AUTOSIZE);
	
	
	IplImage* res;
	
	
	
	if( capture )
	{
		IplImage* frame = cvQueryFrame( capture );
		IplImage* old_frame = frame;
		
		res = cvCreateImage(cvSize(frame->width, frame->height), 8, 3);
		while(1)
		{	
			
			
			
			cvAbsDiff(old_frame, frame, res);  //Calculates the per-element absolute difference between two arrays
			//bluring the differnece image
            //cvSmooth(res, res, CV_BLUR, ); 
            //apply threshold to discard small unwanted movements
            cvThreshold(res, res, 25, 255, CV_THRESH_BINARY);
			
			
			cvShowImage( "Video", frame );
			cvShowImage( "Video1", old_frame );
			cvShowImage( "VideoRes", res );
			
			
			
			old_frame = frame;
			frame = cvQueryFrame( capture );
			if( !frame )
				break;
			//Convert the image to grayscale.
            //cvCvtColor(frame,frame, CV_RGB2GRAY);
			
			
			// Press 'c' to escape
			c = cvWaitKey(10);
			if( (char)c == 'c' ) { break; }			
		}
	}
	
	cvReleaseCapture( &capture ); // release memory.
	cvReleaseImage(&res); // release memory.
    cvDestroyWindow("Video"); //destroy windows
    cvDestroyWindow("Video1"); //destroy windows
    cvDestroyWindow("VideoRes"); //destroy windows
	
	return 0;
}
