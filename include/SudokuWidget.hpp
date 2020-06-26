#ifndef __SUDOKUWIDGET_HPP
#define __SUDOKUWIDGET_HPP

#include <QtWidgets>
#include <QLine>

#include "include/ClusterWidget.hpp"

class SudokuWidget : public QWidget {
	public:
		SudokuWidget();
	protected:
		QVBoxLayout *mainVBox;
		QHBoxLayout *hBoxRow[3];
		QFrame *vDividerLine[6];
		QFrame *hDividerLine[2];
		ClusterWidget *clusters[9];
	private:

};


#endif // __SUDOKUWIDGET_HPP