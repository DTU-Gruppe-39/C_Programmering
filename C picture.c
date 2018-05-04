#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>

int main() {

    IplImage* image1 = cvLoadImage("Sample1.jpg", CV_LOAD_IMAGE_COLOR);  // Loads an image from a file.

    if(image1== NULL) // Check for invalid input
    {
        printf("Could not open or find the image1\n") ;
        return -1;
    }

    void cvCvtColor(const CvArr* image1, CvArr* image1_gray, int BGR2GRAY); // Converts to greyscale.

    cvCalcHist(image1,); //Calculates histogram
    //void cvCalcHist(IplImage** image, CvHistogram* hist, int accumulate=0, const CvArr* mask=NULL )
}
