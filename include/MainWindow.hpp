#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QtWidgets>
#include <QSpacerItem>
#include <QPushButton>

#include "include/SudokuWidget.hpp"
#include "include/BoardModel.hpp"
#include "include/Subscriber.hpp"


class MainWindow : public QMainWindow, public Subscriber {
	Q_OBJECT

	public:
		MainWindow(BoardModel & sudokuBoard);


	protected:
		BoardModel& sudokuBoard;
		void notified();

	private:
		QWidget *mainWidget;
		QHBoxLayout *mainBox;
		SudokuWidget *sudokuWidget;
		QSpacerItem *gridSpacer;

		QWidget *solveButtonsGroup;
		QVBoxLayout *solveButtonVBox;
		QPushButton *solveConstraint;
		QPushButton *solveSearch;
		QPushButton *solveConstraintSearch;

		QLabel *labelStats;

	private slots:
		void handleButtonClicked();
};

#endif // __MAINWINDOW_H