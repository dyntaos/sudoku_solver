#ifndef __CLUSTERWIDGET_HPP
#define __CLUSTERWIDGET_HPP

#include <stdexcept>
#include <QtWidgets>
#include <QLine>

#include "include/BoardModel.hpp"
#include "include/QClickableLabel.hpp"

class ClusterWidget : public QWidget {
	Q_OBJECT
	public:
		ClusterWidget(BoardModel& model, int x, int y);
		void setTileValue(int x, int y, const QString & val);

		int getXCoordinate() const {return xCoord;}
		int getYCoordinate() const {return yCoord;}

	protected:
		QVBoxLayout *mainVBox;
		QHBoxLayout *hBoxRow[3];
		QFrame *vDividerLine[6];
		QFrame *hDividerLine[2];
		QClickableLabel *tileLabel[3][3];

		BoardModel& model;

	private:
		int xCoord = 0, yCoord = 0;

	private slots:
		void handleLabelClicked();
		void handleLabelFocusOut();
		void handleLabelKeyRelease(QKeyEvent *event);

};


#endif // __CLUSTERWIDGET_HPP