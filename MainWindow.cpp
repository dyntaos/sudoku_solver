#include "include/MainWindow.hpp"


MainWindow::MainWindow() {
	mainWidget = new QWidget();
	mainVBox = new QVBoxLayout();
	mainVBox->setContentsMargins(0, 0, 0, 0);
	mainVBox->setSpacing(0);
	sudokuWidget = new SudokuWidget();
	mainVBox->addWidget(sudokuWidget);
	mainWidget->setLayout(mainVBox);
	setContentsMargins(0, 0, 0, 0);
	setCentralWidget(mainWidget);
}