#ifndef __SUDOKUWIDGET_HPP
#define __SUDOKUWIDGET_HPP

#include <stdexcept>
#include <QtWidgets>
#include <QLine>

#include "include/ClusterWidget.hpp"
#include "include/BoardModel.hpp"

class SudokuWidget : public QWidget {
	public:
		SudokuWidget(BoardModel& model);
		void setTileValue(int x, int y, const QString & val);
		void drawModel(const BoardModel & model);
	protected:
		QVBoxLayout *mainVBox;
		QHBoxLayout *hBoxRow[3];
		QFrame *vDividerLine[6];
		QFrame *hDividerLine[2];
		ClusterWidget *clusters[3][3];
	private:

};


#endif // __SUDOKUWIDGET_HPP