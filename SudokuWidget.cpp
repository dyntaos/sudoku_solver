#include "include/SudokuWidget.hpp"

SudokuWidget::SudokuWidget() {
	int vDividerNum = 0;

	mainVBox = new QVBoxLayout();
	setLayout(mainVBox);
	setContentsMargins(0, 0, 0, 0);

	mainVBox->setSizeConstraint(QLayout::SetFixedSize);
	mainVBox->setSpacing(0);
	mainVBox->setContentsMargins(0, 0, 0, 0);

	for (int i = 0; i < 3; i++) {
		hBoxRow[i] = new QHBoxLayout();
		hBoxRow[i]->setSpacing(0);
		hBoxRow[i]->setContentsMargins(0, 0, 0, 0);
		mainVBox->addLayout(hBoxRow[i]);
		if (i < 2) {
			hDividerLine[i] = new QFrame();
			hDividerLine[i]->setFrameShape(QFrame::HLine);
			hDividerLine[i]->setFrameShadow(QFrame::Plain);
			hDividerLine[i]->setContentsMargins(0, 0, 0, 0);
			hDividerLine[i]->setLineWidth(2);
			mainVBox->addWidget(hDividerLine[i]);
		}
	}

	for (int i = 0; i < 9; i++) {
		clusters[i] = new ClusterWidget();
		hBoxRow[i / 3]->addWidget(clusters[i]);
		if (i % 3 != 2) {
			vDividerLine[vDividerNum] = new QFrame();
			vDividerLine[vDividerNum]->setFrameShape(QFrame::VLine);
			vDividerLine[vDividerNum]->setFrameShadow(QFrame::Plain);
			vDividerLine[vDividerNum]->setContentsMargins(0, 0, 0, 0);
			vDividerLine[vDividerNum]->setLineWidth(2);
			hBoxRow[i / 3]->addWidget(vDividerLine[vDividerNum]);
			vDividerNum++;
		}
	}
}
