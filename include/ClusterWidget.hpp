#ifndef __CLUSTERWIDGET_HPP
#define __CLUSTERWIDGET_HPP

#include <QtWidgets>
#include <QLine>
#include <QLabel>

class ClusterWidget : public QWidget {
	public:
		ClusterWidget();
	protected:
		QVBoxLayout *mainVBox;
		QHBoxLayout *hBoxRow[3];
		QFrame *vDividerLine[6];
		QFrame *hDividerLine[2];
		QLabel *tileLabel[9];
	private:

};


#endif // __CLUSTERWIDGET_HPP