#include "include/ClusterWidget.hpp"

ClusterWidget::ClusterWidget() {
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
			hDividerLine[i]->setFrameShadow(QFrame::Sunken);
			hDividerLine[i]->setContentsMargins(0, 0, 0, 0);
			mainVBox->addWidget(hDividerLine[i]);
		}
	}

	for (int i = 0; i < 9; i++) {
		QFont tileFont;

		tileLabel[i] = new QLabel(QString::number(i));
		tileLabel[i]->setAlignment(Qt::AlignCenter);
		tileLabel[i]->setMinimumSize(40, 40);
		tileLabel[i]->setContentsMargins(0, 0, 0, 0);

		tileFont.setPointSize(12);
		tileFont.setFamily("SansSerif");
		tileLabel[i]->setFont(tileFont);

		hBoxRow[i / 3]->addWidget(tileLabel[i]);

		if (i % 3 != 2) {
			vDividerLine[vDividerNum] = new QFrame();
			vDividerLine[vDividerNum]->setFrameShape(QFrame::VLine);
			vDividerLine[vDividerNum]->setFrameShadow(QFrame::Sunken);
			vDividerLine[vDividerNum]->setContentsMargins(0, 0, 0, 0);
			hBoxRow[i / 3]->addWidget(vDividerLine[vDividerNum]);
			vDividerNum++;
		}
	}
}
