#include "include/MainWindow.hpp"


MainWindow::MainWindow() {
	mainWidget = new QWidget();
	//mainVBox = new QVBoxLayout(mainWidget);
	mainVBox = new QVBoxLayout();
	clusterWidget[0] = new ClusterWidget();
	mainVBox->addLayout(clusterWidget[0]);
	mainWidget->setLayout(mainVBox);
	setCentralWidget(mainWidget);
}