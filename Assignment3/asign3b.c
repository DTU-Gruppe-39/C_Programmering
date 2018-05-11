
#include "opencv2/highgui/highgui.hpp" //  required for OpenCV functions
#include <stdio.h>
#include <stdlib.h>
#include <cv.h>                   // Standard I/O - required for printf() function
#include "opencv2/imgproc/imgproc_c.h"

IplImage* image_grey;
IplImage* image;

int main()
{
	FILE *fp;
	CvCapture* capture;

	// Read the video stream
	capture = cvCaptureFromCAM( 0 );

	if( capture )
	{
		image = cvQueryFrame( capture );
		image_grey = cvCreateImage( cvSize(image->width, image->height), IPL_DEPTH_8U, 1);

			//Convert the image to grayscale.
            cvCvtColor(image,image_grey, CV_RGB2GRAY);
            int histArray[256];
            //int width = image_grey->width;
            int height = image_grey->height;

            for(int w = 0; w < height; w++) {
				for(int h = 0; h <= height; h++) {
					int index = (int) cvGetReal2D(image_grey, w, h);
					histArray[index] += 1;
					//printf("[%d][%d]: %f     ", w, h, scal);
				}
			}
			 /****************************************************************************
			 Create file if not exits
			 ****************************************************************************/
				   fp = fopen("HISTOGRAM.SOL", "ab+");

				   if (fp == NULL)
				   {
					  perror("Error while opening the file.\n");
					  exit(EXIT_FAILURE);
				   }
				   
				   fseek(fp, 0, SEEK_SET);

				   fprintf(fp, "%d    (update when values are correct)\n", 255);
				   fprintf(fp, "%dx%d     (only 480x480, due to crash if width greater than 480)\n", image_grey->width, image_grey->height);

				 for(int j = 0; j < 256; j++) {
					//printf("%d er: %d\n", j, histArray[j]);
					 fprintf(fp, "%d %d\n", j, histArray[j]);
				 }

				   fclose(fp);
	}

	cvReleaseCapture( &capture ); // release memory.
	cvReleaseImage(&image_grey); // release memory.

	return 0;
}
