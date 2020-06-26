#include "include/SudokuWidget.hpp"

SudokuWidget::SudokuWidget(BoardModel& model) {
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

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			clusters[i][j] = new ClusterWidget(model, i, j);
			hBoxRow[i]->addWidget(clusters[i][j]);
			if (j != 2) {
				vDividerLine[vDividerNum] = new QFrame();
				vDividerLine[vDividerNum]->setFrameShape(QFrame::VLine);
				vDividerLine[vDividerNum]->setFrameShadow(QFrame::Plain);
				vDividerLine[vDividerNum]->setContentsMargins(0, 0, 0, 0);
				vDividerLine[vDividerNum]->setLineWidth(2);
				hBoxRow[i]->addWidget(vDividerLine[vDividerNum]);
				vDividerNum++;
			}
		}
	}
}

void SudokuWidget::setTileValue(int x, int y, const QString & val) {
	//TODO Validate args
	clusters[x / 3][y / 3]->setTileValue(x % 3, y % 3, val);
}

void SudokuWidget::drawModel(const BoardModel & model) {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (model.hasTileValue(x, y)) {
				setTileValue(x, y, QString::number(model.getTileValue(x, y)));
			} else {
				setTileValue(x, y, "");
			}
		}
	}
}