#ifndef __CLUSTERWIDGET_HPP
#define __CLUSTERWIDGET_HPP

#include <QtWidgets>
#include <QLine>
#include <QLabel>

class ClusterWidget : public QVBoxLayout {
	public:
		ClusterWidget();
	protected:
		QHBoxLayout *hBoxRow[3];
		QFrame *vDividerLine[6];
		QLabel *tileLabel[9];
	private:

};


#endif // __CLUSTERWIDGET_HPP