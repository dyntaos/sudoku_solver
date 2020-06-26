#include "include/MainWindow.hpp"

#include <QtDebug> //TODO: Remove

MainWindow::MainWindow(Board & sudokuBoard) : sudokuBoard(sudokuBoard) {
	mainWidget = new QWidget();

	mainBox = new QHBoxLayout();
	mainBox->setContentsMargins(0, 0, 0, 0);
	mainBox->setSpacing(0);

	sudokuWidget = new SudokuWidget();
	mainBox->addWidget(sudokuWidget);

	gridSpacer = new QSpacerItem(30, 30);
	mainBox->addSpacerItem(gridSpacer);

	mainBox->setAlignment(Qt::AlignTop);

	solveButtonsGroup = new QWidget();

	mainBox->addWidget(solveButtonsGroup);

	solveButtonVBox = new QVBoxLayout();
	solveButtonsGroup->setLayout(solveButtonVBox);

	solveConstraint = new QPushButton("Solve Constraints");
	solveConstraint->setObjectName("solveConstraint");
	solveButtonVBox->addWidget(solveConstraint);

	solveSearch = new QPushButton("Solve Search");
	solveSearch->setObjectName("solveSearch");
	solveButtonVBox->addWidget(solveSearch);

	solveConstraintSearch = new QPushButton("Solve Constraints + Search");
	solveConstraintSearch->setObjectName("solveConstraintSearch");
	solveButtonVBox->addWidget(solveConstraintSearch);

	QObject::connect(solveConstraint, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
	QObject::connect(solveSearch, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
	QObject::connect(solveConstraintSearch, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));

	labelStats = new QLabel("Statistics:");
	solveButtonVBox->addWidget(labelStats);

	mainWidget->setLayout(mainBox);

	setContentsMargins(20, 20, 20, 20);
	setCentralWidget(mainWidget);

}

void MainWindow::handleButtonClicked() {
	QString objName = ((QPushButton*) sender())->objectName();

	if (objName == "solveConstraint") {
		qDebug() << "solveConstraint clicked" << endl;

	} else if (objName == "solveSearch") {
		qDebug() << "solveSearch clicked" << endl;

	} else if (objName == "solveConstraintSearch") {
		qDebug() << "solveConstraintSearch clicked" << endl;

	} else {
		qDebug() << "Warning: Unknown sender to handleButtonClicked()" << endl;
	}
}