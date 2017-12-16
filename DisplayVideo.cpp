#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;

using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "usage: DisplayVideo.out <file>" << endl;
        return -1;
    }

    VideoCapture vCap;// (argv[1]);
    std::string fileName (argv[1]);
    cout << "Video file is " << fileName << endl;
    if (!vCap.open(fileName))
    {
        cerr << "Cannot open video" << endl;
        return -1;
    }
    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        vCap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}
