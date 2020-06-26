#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "include/MainWindow.hpp"
#include "include/board.hpp"


int main(int argc, char *argv[]) {
	Board sudokuModel;
	QApplication app(argc, argv);
	QCommandLineParser parser;
	MainWindow mainWindow(sudokuModel);

	QCoreApplication::setOrganizationName("Kale Yuzik");
	QCoreApplication::setApplicationName("Sudoku Solver");
	QCoreApplication::setApplicationVersion("0.1");

	parser.setApplicationDescription(QCoreApplication::applicationName());
	parser.addHelpOption();
	parser.addVersionOption();
	//parser.addPositionalArgument("file", "The sudoku file to open.");
	parser.process(app);

	//if (!parser.positionalArguments().isEmpty()) {
	//	mainWindow.loadFile(parser.positionalArguments().first());
	//}
	mainWindow.show();

	return app.exec();
}