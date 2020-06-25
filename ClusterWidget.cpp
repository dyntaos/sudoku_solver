#include "include/ClusterWidget.hpp"

ClusterWidget::ClusterWidget() {
	int vDividerNum = 0;

	setSizeConstraint(QLayout::SetMinimumSize);
	setSpacing(0);

	for (int i = 0; i < 3; i++) {
		hBoxRow[i] = new QHBoxLayout();
		addLayout(hBoxRow[i]);
	}

	for (int i = 0; i < 9; i++) {
		tileLabel[i] = new QLabel(QString::number(i));
		tileLabel[i]->setAlignment(Qt::AlignCenter);
		hBoxRow[i / 3]->addWidget(tileLabel[i]);
		if (i % 3 != 2) {
			vDividerLine[vDividerNum] = new QFrame();
			vDividerLine[vDividerNum]->setFrameShape(QFrame::VLine);
			hBoxRow[i / 3]-> addWidget(vDividerLine[vDividerNum]);
			vDividerNum++;
		}
	}
}