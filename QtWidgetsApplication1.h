#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);

	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *e);

private:
    Ui::QtWidgetsApplication1Class ui;
	int boundaryWidth = 4;
	QPoint clickPos;
	bool isClicked = false;

};
