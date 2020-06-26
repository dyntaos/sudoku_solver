#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QtWidgets>
#include <QLabel>

#include "include/SudokuWidget.hpp"


class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
		MainWindow();

	protected:

	private:
		QWidget *mainWidget;
		QVBoxLayout *mainVBox;
		SudokuWidget *sudokuWidget;
};

#endif // __MAINWINDOW_H