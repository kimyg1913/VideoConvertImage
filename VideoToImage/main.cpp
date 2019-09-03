//#include <opencv/cv.h>
//#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
#include <windows.h>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	Mat frame;
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap("./Video.mp4");
	int count = 0;
	
	while(1)
	{
		cv::Mat frame;

		// get a new frame from camera
		cap >> frame;

		if (frame.empty())
			break;

		string path = "./ImageFrame/";
		CreateDirectory(path.c_str(), 0);

		string filename;
		filename = cv::format("capture%04d.jpg", count++);
	
		cv::imshow("WebCam Frame Capture", frame);
		char c = (char)waitKey(25);	//대기
		if (c == 27)
			break;
		imwrite((path + filename).c_str() , frame);

	
	}

	cap.release();

	return 0;
}


int FrameExtractionFromVideo(const char * filePath)
{
	Mat frame;
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap("DirectX2D.avi");

	string sFilePath = filePath;
	string rFileName;
	string fileName;

	for (std::string::reverse_iterator rit = sFilePath.rbegin(); rit != sFilePath.rend(); ++rit)
	{
		if (*rit == '/')
		{
			break;
		}

		rFileName += *rit;
	}

	for (std::string::reverse_iterator rit = rFileName.rbegin(); rit != rFileName.rend(); ++rit)
	{
		fileName += *rit;
	}

	int fps;
	int count = 0; //카운트

	while (1)
	{

		cv::Mat frame;

		// get a new frame from camera
		cap >> frame;

		string path = "./ImageFrame/";
		CreateDirectory(path.c_str(), 0);

		string filename;
		filename = cv::format("capture%04d.jpg", count++);

		cv::imshow("WebCam Frame Capture", frame);

		imwrite((path + filename).c_str(), frame);

		if (!cap.grab())
			break;
	}

	cap.release();

	return 1;
}