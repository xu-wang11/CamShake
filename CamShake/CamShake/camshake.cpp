#include "camshake.h"

CamShake::CamShake(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(this->ui.ContinuousBtn, SIGNAL(clicked()), this, SLOT(startConCam()));
	connect(this->ui.DiscreteBtn, SIGNAL(clicked()), this, SLOT(startDisCam()));
	connect(this->ui.StopBtn, SIGNAL(clicked()), this, SLOT(stopCam()));
}

CamShake::~CamShake()
{

}
void CamShake::startConCam()
{
	//control racing game etc
	this->ui.label_hint->setText("Continuous control running!");
	this->cam->isContinuous = true;
	this->ui.ContinuousBtn->setDisabled(true);
	this->ui.DiscreteBtn->setDisabled(true);
	this->ui.label_detection->setVisible(true);
	this->cam->isExist = false;
	this->cam->start();
}
void CamShake::startDisCam()
{
	//control ppt etc
	this->ui.label_hint->setText("Discrete control running!");
	this->cam->isContinuous = false;
	this->ui.ContinuousBtn->setDisabled(true);
	this->ui.DiscreteBtn->setDisabled(true);
	this->ui.label_detection->setVisible(true);
	this->cam->isExist = false;
	this->cam->start();
}
void CamShake::stopCam()
{
	if(this->cam->isExist)
		return;
	this->ui.ContinuousBtn->setDisabled(false);
	this->ui.DiscreteBtn->setDisabled(false);
	this->cam->isExist = true;
	this->ui.label_hint->setText("This head-control widget is used for triggering key event.");
	this->ui.label_detection->setVisible(false);
	//this->cam->quit();
}
void CamShake::closeEvent(QCloseEvent* evn)
{
	this->cam->isExist = true;
	while(this->cam->isRunning());
}