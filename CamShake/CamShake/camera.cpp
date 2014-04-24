#include "camera.h"
#include "camshake.h"
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <math.h> 
#include <float.h> 
#include <limits.h> 
#include <time.h> 
#include <ctype.h>
#include <fstream>
#include <Windows.h>
 
void Camera::run()
{
	cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 ); 

	CvCapture* pCap = cvCaptureFromCAM(0);//这里-1也可以，不过我的电脑装的有CyberLink YouCam软件，

	if (pCap == NULL){
		return ;
	} 

    if( !cascade ) { 
        fprintf( stderr, "ERROR: Could not load classifier cascade\n" ); 
        return ; 
    } 
    storage = cvCreateMemStorage(0); 
  
    // IplImage 是结构体类型，用来保存一帧图像的信息，也就是一帧
    // 图像的所有像素值构成的一个矩阵

    IplImage *frame, *frame_copy = 0;
     
     // 创建一个窗口，用“result”作为窗口的标识符
    //cvNamedWindow("Camera", 1 );

	 frame = cvQueryFrame(pCap);
	 while (pCap && !isExist)  {
		frame = cvQueryFrame(pCap);
			
		if(isContinuous)
			con_detect_and_draw(frame); 
		else
			dis_detect_and_draw(frame);
		GetKey = cvWaitKey(10);
		if(GetKey == 27){
			break;
		}
	 }

	 cvReleaseCapture(&pCap);
     //cvDestroyWindow("Camera");
     return;
}
void Camera::dis_detect_and_draw(IplImage* img)
{
	//用于控制PPT
	double scale=1.2; 
    static CvScalar colors[] = { 
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
    };//Just some pretty colors to draw with


    //Image Preparation 
    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
    cvCvtColor(img,gray, CV_BGR2GRAY); 
    cvResize(gray, small_img, CV_INTER_LINEAR);

    cvEqualizeHist(small_img,small_img); //直方图均衡

    //Detect objects if any 

    cvClearMemStorage(storage); 
    CvSeq* objects = cvHaarDetectObjects(small_img,cascade,storage,1.1,1,CV_HAAR_DO_CANNY_PRUNING,cvSize(150,150));


    //Loop through found objects and draw boxes around them 
    for( int i = 0; i < (objects? objects->total : 0); i++ ) 
    { 
        CvRect* r = (CvRect*)cvGetSeqElem(objects, i); 
        CvPoint center; 
        int radius; 
        center.x = cvRound((r->x + r->width*0.5)*scale); 
        center.y = cvRound((r->y + r->height*0.5)*scale); 
        radius = cvRound((r->width + r->height)*0.25*scale); 
        cvCircle(img, center, radius, colors[i%8], 3, 8, 0);
		if(prev.x == 0 && prev.y == 0)//初始状态
		{   
			prev = center;
			break;
		}
		else
		{
			allkey_up();
			if(center.x - prev.x < -threshold)
			{
				if(center.y - prev.y > threshold)
				{
					keybd_event(39,0,0,0);
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					keybd_event(39,0,0,0);
					keybd_event(38,0,0,0);
				}
				else
				{
					keybd_event(39,0,0,0);
				}
			}
			else if(center.x - prev.x > threshold)
			{
				if(center.y - prev.y > threshold)
				{
					keybd_event(37,0,0,0);
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					keybd_event(37,0,0,0);
					keybd_event(38,0,0,0);
				}
				else
				{
					keybd_event(37,0,0,0);
				}
			}
			else
			{
				if(center.y - prev.y > threshold)
				{
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					keybd_event(38,0,0,0);
				}
			}
		}
		prev = center;
		break;
    }
	

	cvConvertImage(img, img, CV_CVTIMG_SWAP_RB);
	int labelW = this->window->ui.label_detection->size().width();
	int labelH = this->window->ui.label_detection->size().height();
	QImage temImg((const unsigned char*)img->imageData, (img->width), (img->height), QImage::Format_RGB888);
	QImage newImg = temImg.scaled(labelW, labelH);
	this->window->ui.label_detection->setPixmap(QPixmap::fromImage(newImg));
	this->window->update();
    cvReleaseImage(&gray); 
    cvReleaseImage(&small_img); 
}

void Camera::con_detect_and_draw(IplImage* img)
{
	//用于控制赛车游戏等
	double scale=1.2; 
    static CvScalar colors[] = { 
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
    };//Just some pretty colors to draw with


    //Image Preparation 
    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
    cvCvtColor(img,gray, CV_BGR2GRAY); 
    cvResize(gray, small_img, CV_INTER_LINEAR);

    cvEqualizeHist(small_img,small_img); //直方图均衡

    //Detect objects if any 

    cvClearMemStorage(storage); 
    CvSeq* objects = cvHaarDetectObjects(small_img,cascade,storage,1.1,1,CV_HAAR_DO_CANNY_PRUNING,cvSize(150,150));


    //Loop through found objects and draw boxes around them 
    for( int i = 0; i < (objects? objects->total : 0); i++ ) 
    { 
        CvRect* r = (CvRect*)cvGetSeqElem(objects, i); 
        CvPoint center;
        int radius; 
        center.x = cvRound((r->x + r->width*0.5)*scale); 
        center.y = cvRound((r->y + r->height*0.5)*scale); 
        radius = cvRound((r->width + r->height)*0.25*scale); 
        cvCircle(img, center, radius, colors[i%8], 3, 8, 0);
		if(prev.x == 0 && prev.y == 0)//初始状态
		{   
			prev = center;
			break;
		}
		else
		{
			if(KeydownList != -1)
				keybd_event(KeydownList,0,0,0);
			
			if(center.x - prev.x < -(0.5*threshold))
			{
				if(center.y - prev.y > threshold)
				{
					allkey_up();
					keybd_event(39,0,0,0);
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					allkey_up();
					keybd_event(39,0,0,0);
					keybd_event(38,0,0,0);
				}
				else if (center.x - prev.x < -(threshold))
				{
					//弹起左键同时按下右键
					keybd_event(37,0,KEYEVENTF_KEYUP,0); //left
					keybd_event(39,0,0,0);
					KeydownList = 39;
					
				}
				else
				{
					//弹起左键
					keybd_event(37,0,KEYEVENTF_KEYUP,0); //left
					KeydownList = -1;
				}
			}
			else if(center.x - prev.x > 0.5*threshold)
			{
				if(center.y - prev.y > threshold)
				{
					allkey_up();
					keybd_event(37,0,0,0);
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					allkey_up();
					keybd_event(37,0,0,0);
					keybd_event(38,0,0,0);
				}
				else if (center.x - prev.x > threshold)
				{
					//弹起右键同时按下左键
					keybd_event(39,0,KEYEVENTF_KEYUP,0); //right
					keybd_event(37,0,0,0);
					KeydownList = 37;
					put_text_onscreen(img,"right",0,0);
				}
				else
				{
					keybd_event(39,0,KEYEVENTF_KEYUP,0); //right
					KeydownList = -1;
				}
			}
			else
			{
				if(center.y - prev.y > threshold)
				{
					keybd_event(40,0,0,0);
				}
				else if (center.y - prev.y < -threshold)
				{
					keybd_event(38,0,0,0);
				}
			}
		}
		prev = center;
		break;
    }
	

    //cvShowImage( "Camera", img ); 
	cvConvertImage(img, img, CV_CVTIMG_SWAP_RB);
	int labelW = this->window->ui.label_detection->size().width();
	int labelH = this->window->ui.label_detection->size().height();
	QImage temImg((const unsigned char*)img->imageData, (img->width), (img->height), QImage::Format_RGB888);
	QImage newImg = temImg.scaled(labelW, labelH);
	this->window->ui.label_detection->setPixmap(QPixmap::fromImage(newImg));
	this->window->update();
    cvReleaseImage(&gray); 
    cvReleaseImage(&small_img);
}

void Camera::allkey_up()
{
	keybd_event(37,0,KEYEVENTF_KEYUP,0); //left
	keybd_event(38,0,KEYEVENTF_KEYUP,0); //up
	keybd_event(39,0,KEYEVENTF_KEYUP,0); //right
	keybd_event(40,0,KEYEVENTF_KEYUP,0); //down
}

void Camera::put_text_onscreen(IplImage* img, const char* text, int x, int y)
{
	CvFont font;    
    double hScale=1;   
    double vScale=1;    
    int lineWidth=2; //线条      
    // 初始化字体   
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);//初始化字体，准备写到图片上的   
    // cvPoint 为起笔的x，y坐标   
    cvPutText(img,text,cvPoint(x,y),&font,CV_RGB(255,0,0));
}