#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QtWidgets>
#include <QLabel>

#include "include/ClusterWidget.hpp"


class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
		MainWindow();

	protected:

	private:
		QWidget *mainWidget;
		QVBoxLayout *mainVBox;
		ClusterWidget *clusterWidget[9];
};

#endif // __MAINWINDOW_H