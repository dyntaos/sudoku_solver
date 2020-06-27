#include "include/ClusterWidget.hpp"

using namespace std;

ClusterWidget::ClusterWidget(BoardModel& model, int x, int y) : model(model), xCoord(x), yCoord(y) {
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

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			QFont tileFont;

			tileLabel[i][j] = new QClickableLabel();
			tileLabel[i][j]->setCoordinates((getXCoordinate() * 3) + i, (getYCoordinate() * 3) + j);
			tileLabel[i][j]->setText("");
			tileLabel[i][j]->setAlignment(Qt::AlignCenter);
			tileLabel[i][j]->setMinimumSize(40, 40);
			tileLabel[i][j]->setContentsMargins(0, 0, 0, 0);
			QObject::connect(tileLabel[i][j], SIGNAL(clicked()), this, SLOT(handleLabelClicked()));
			QObject::connect(tileLabel[i][j], SIGNAL(focusOut()), this, SLOT(handleLabelFocusOut()));
			QObject::connect(tileLabel[i][j], SIGNAL(keyRelease(QKeyEvent*)), this, SLOT(handleLabelKeyRelease(QKeyEvent*)));

			tileFont.setPointSize(12);
			tileFont.setFamily("SansSerif");
			tileLabel[i][j]->setFont(tileFont);

			hBoxRow[i]->addWidget(tileLabel[i][j]);

			if (j != 2) {
				vDividerLine[vDividerNum] = new QFrame();
				vDividerLine[vDividerNum]->setFrameShape(QFrame::VLine);
				vDividerLine[vDividerNum]->setFrameShadow(QFrame::Sunken);
				vDividerLine[vDividerNum]->setContentsMargins(0, 0, 0, 0);
				hBoxRow[i]->addWidget(vDividerLine[vDividerNum]);
				vDividerNum++;
			}
		}
	}
}

/**
 * throws std::out_of_range if x or y argument is not in 0 to 8
 */
void ClusterWidget::setTileValue(int x, int y, const QString & val) {
	if (x < 0 || x > 8 || y < 0 || y > 8) {
		throw out_of_range("Tile coordinate is outside of range.");
	}
	tileLabel[x][y]->setText(val);
}

void ClusterWidget::handleLabelClicked() {
	qDebug() << "Label clicked" << endl;
	QClickableLabel *l = ((QClickableLabel*) sender());
	l->setStyleSheet("QLabel { background-color: white; }");
	l->setFocus(Qt::FocusReason::MouseFocusReason);
}

void ClusterWidget::handleLabelFocusOut() {
	qDebug() << "Label lost focus" << endl;
	QClickableLabel *l = ((QClickableLabel*) sender());
	l->setStyleSheet("QLabel { background-color: window; }");
}

void ClusterWidget::handleLabelKeyRelease(QKeyEvent *event) {
	QClickableLabel *l = ((QClickableLabel*) sender());
	int key = 0;

	qDebug() << "Label key released [" << event->key() << "]" << endl;

	switch (event->key()) {
		case Qt::Key_Return:
		case Qt::Key_Enter:
		case Qt::Key_Escape:
			qDebug() << "Enter key released" << endl;
			l->clearFocus();
			return;

		case Qt::Key_Delete:
		case Qt::Key_Backspace:
			qDebug() << "Delete key released" << endl;
			model.clearTileValue(l->getXCoordinate(), l->getYCoordinate());
			l->clearFocus();
			return;

		case Qt::Key_1:
			key = 1;
			break;

		case Qt::Key_2:
			key = 2;
			break;

		case Qt::Key_3:
			key = 3;
			break;

		case Qt::Key_4:
			key = 4;
			break;

		case Qt::Key_5:
			key = 5;
			break;

		case Qt::Key_6:
			key = 6;
			break;

		case Qt::Key_7:
			key = 7;
			break;

		case Qt::Key_8:
			key = 8;
			break;

		case Qt::Key_9:
			key = 9;
			break;

		default:
			return;
	}
	qDebug() << key << " key released" << endl;
	try {
		model.setTileValue(l->getXCoordinate(), l->getYCoordinate(), key);
	} catch (const std::runtime_error & e) {

	}
	l->clearFocus();
}