#include "QtWidgetsApplication1.h"
#include <QMouseEvent>
#include <windows.h>
#include <windowsx.h>

#define MARGIN 3

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setMinimumSize(45, 45);
	this->setStyleSheet("background:#ff0000");
	//this->setFixedWidth(500);
	//this->setMinimumHeight(500);
}

//int boundaryWidth = 4;

bool QtWidgetsApplication1::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	MSG* msg = (MSG*)message;
	switch (msg->message)
	{
	case WM_NCHITTEST:
		int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
		int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
		if (xPos < boundaryWidth && yPos < boundaryWidth)                    //左上角
			*result = HTTOPLEFT;
		else if (xPos >= width() - boundaryWidth&&yPos < boundaryWidth)          //右上角
			*result = HTTOPRIGHT;
		else if (xPos < boundaryWidth&&yPos >= height() - boundaryWidth)         //左下角
			*result = HTBOTTOMLEFT;
		else if (xPos >= width() - boundaryWidth&&yPos >= height() - boundaryWidth)//右下角
			*result = HTBOTTOMRIGHT;
		else if (xPos < boundaryWidth)                                     //左边
			*result = HTLEFT;
		else if (xPos >= width() - boundaryWidth)                              //右边
			*result = HTRIGHT;
		else if (yPos < boundaryWidth)                                       //上边
			*result = HTTOP;
		else if (yPos >= height() - boundaryWidth)                             //下边
			*result = HTBOTTOM;
		else              //其他部分不做处理，返回false，留给其他事件处理器处理
			return false;
		return true;
	}
	return false;         //此处返回false，留给其他事件处理器处理
}

void QtWidgetsApplication1::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		isClicked = true;
		clickPos = e->pos();
	}
}
void QtWidgetsApplication1::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		isClicked = false;
	}
}
void QtWidgetsApplication1::mouseMoveEvent(QMouseEvent *e)
{
	if (isClicked)
		move(e->pos() + pos() - clickPos);
}

