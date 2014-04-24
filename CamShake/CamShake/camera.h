#ifndef CAMERA_H_
#define CAMERA_H_
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <qthread.h>
#include <stdio.h> 

class CamShake;
class Camera:public QThread
{
	 Q_OBJECT
public:
	CvMemStorage* storage;
	CvHaarClassifierCascade* cascade;

	char* cascade_name;
	int GetKey;
	int KeydownList;
	CvPoint prev;
	int threshold;
	int status;
	CamShake* window;
	bool isExist;
	bool isContinuous;

	Camera(QObject *parent = NULL):threshold(12), status(0)
	{
		prev.x = 0;
		prev.y = 0;
		KeydownList = -1;
		cascade_name = "haarcascade_frontalface_alt.xml";
		isExist = true;
	}

	void con_detect_and_draw(IplImage* img);
	void dis_detect_and_draw(IplImage* img);
	void put_text_onscreen(IplImage* img, const char* text,int x, int y);
	void allkey_up();

protected:
	void run();
};
#endif