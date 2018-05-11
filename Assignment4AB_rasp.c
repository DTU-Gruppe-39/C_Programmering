/********************************************************************************
|  CLASS:         62409 C programming for Java programmers
|  PROGRAM:       lab28.c   
|  DATE:          MAR 2018
|  DESCRIPTION:   Capture video
********************************************************************************/
#include "opencv2/highgui/highgui.hpp" //  required for OpenCV functions
#include <stdio.h>  
#include <stdlib.h>
#include <cv.h>                   // Standard I/O - required for printf() function
#include "opencv2/imgproc/imgproc_c.h"
#include <unistd.h>
#include <time.h>

CvSeq* contours = 0;
CvMemStorage* storage = NULL;
IplImage* res;
IplImage* old_grey;
IplImage* frame_grey;
IplImage* image;

int main()
{
	CvCapture* capture;
	int c;
	int movements = 0;
	int pics = 1;
	char path[25] = "Pictures/image.jpg";
	char logPath[19];
	char ch[6];
	int len;
	FILE *fp;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	
	CvScalar color;
	CvFont time_font;
	time_t curtime;

	//setup text on frame
	color = CV_RGB(235,235,235);
	cvInitFont( &time_font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 2, 8);
	
	
	//create storage for contours
    storage = cvCreateMemStorage(0);
	
	

	// Read the video stream
	capture = cvCaptureFromCAM( 0 );
	cvNamedWindow("Video",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Video1",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("VideoRes",CV_WINDOW_AUTOSIZE);
	
	
	
	
	
	
	if( capture )
	{
		IplImage* frame = cvQueryFrame( capture );
		IplImage* old_frame = frame;
		
		frame_grey = cvCreateImage( cvSize(frame->width, frame->height), IPL_DEPTH_8U, 1);  
		old_grey = cvCreateImage( cvSize(frame->width, frame->height), IPL_DEPTH_8U, 1);  
		res = cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_8U, 1);
		
		cvCvtColor(frame,frame_grey, CV_RGB2GRAY);
		cvCvtColor(old_frame,old_grey, CV_RGB2GRAY);
		while(1)
		{	
			
			
			
			cvAbsDiff(old_grey, frame_grey, res);  //Calculates the per-element absolute difference between two arrays
			//bluring the differnece image
            cvSmooth(res, res, CV_BLUR, 3, 0, 0, 0); 
            //apply threshold to discard small unwanted movements
            //60 is good, 70 is good, 150 is way to high
            cvThreshold(res, res, 60, 255, CV_THRESH_BINARY);
            
             //find contours
             movements = cvFindContours(res, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_NONE, cvPoint(0,0));
			//printf(" movements: %d ", movements);
			
			if (movements > 5) {
				//sleep 1 second
				sleep(1);
				
				   /****************************************************************************
				   Create file if not exits
				   ****************************************************************************/
				   
				   //%B month
				   //%Y year
				   time (&rawtime);
				   timeinfo = localtime (&rawtime);
				   strftime (buffer,80,"%Y%B",timeinfo);
				   
				   sprintf(logPath, "log%s.txt", buffer);
				   
				   fp = fopen(logPath, "ab+");
				   

				   if (fp == NULL)
				   {
					  perror("Error while opening the file.\n");
					  exit(EXIT_FAILURE);
				   }
				   
				   fseek(fp, 0, SEEK_END); // seek to end of file
				   len = ftell(fp); // get current file pointer
				   fseek(fp, 0, SEEK_SET);
				   
				   if (len == 0) {
					 fputs("0 ", fp);
					 fputs("\n", fp);
				   }

				   fclose(fp);
				   
				   usleep(5000);
					
					
				   /****************************************************************************
				   Edit the first line of the file, aka the number of activities
				   ****************************************************************************/

				   fp = fopen(logPath, "r+"); // read and write mode

				   if (fp == NULL)
				   {
					  perror("Error while opening the file.\n");
					  exit(EXIT_FAILURE);
				   }
				   
				   fgets(ch, 6, fp);
				   sprintf(ch, "%d", (atoi(ch) + 1));
				   fseek(fp, 0, SEEK_SET);
				   fputs(ch, fp);

				   fclose(fp);



				   /****************************************************************************
				   Add the new lines
				   ****************************************************************************/

				   fp = fopen(logPath, "a"); // Append mode

				   if (fp == NULL)
				   {
					  perror("Error while opening the file.\n");
					  exit(EXIT_FAILURE);
				   }


				   time (&rawtime);
				   timeinfo = localtime (&rawtime);

				   strftime (buffer,80,"%F %X\n",timeinfo);
				   fputs(buffer, fp);

				   fclose(fp);
				   
				   
				   
				//Save image
				time(&curtime);
				//Make sure to avoid putting text on frame that is going to be used for comparison 
				//Make a copy of detected frame
				image = frame;
				cvPutText(image, strtok(ctime(&curtime), "\n"), cvPoint( 10, 20 ), &time_font, color);
				printf("Saved");
				sprintf(path, "Pictures/image%d.jpg", pics);
				cvSaveImage(path, image, 0);
				//Then sleep 4 seconds
				sleep(4);
				pics++;
			}
			
			cvShowImage( "Video", frame_grey );
			cvShowImage( "Video1", old_grey );
			cvShowImage( "VideoRes", res );
			/*
			if (!(run % 40)) {
				printf("run er: %d", run);
				old_grey = frame_grey;
				if (run > 400) {
					run = 0;
				}
			}
			*/
			//old_grey = frame_grey;
			old_frame = frame;
			frame = cvQueryFrame( capture );
			if( !frame )
				break;
			//Convert the image to grayscale.
            cvCvtColor(frame,frame_grey, CV_RGB2GRAY);
			//cvCvtColor(old_frame,old_grey, CV_RGB2GRAY);
			
			// Press 'c' to escape
			c = cvWaitKey(10);
			if( (char)c == 'c' ) { break; }		
			
			//clear memory and contours
              cvClearMemStorage( storage );
              contours = 0;	
              
			//printf("run er: %d", run);
		}
	}
	
	cvReleaseCapture( &capture ); // release memory.
	cvReleaseImage(&res); // release memory.
	cvReleaseImage(&old_grey); // release memory.
	cvReleaseImage(&frame_grey); // release memory.
    cvDestroyWindow("Video"); //destroy windows
    cvDestroyWindow("Video1"); //destroy windows
    cvDestroyWindow("VideoRes"); //destroy windows
	
	return 0;
}
