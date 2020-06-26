#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QtWidgets>
#include <QSpacerItem>
#include <QPushButton>

#include "include/SudokuWidget.hpp"
#include "include/board.hpp"


class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
		MainWindow(Board & sudokuBoard);


	protected:
		Board& sudokuBoard;

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