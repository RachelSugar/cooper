#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	std::cout << "Hello, world!" << std::endl;
	
	return app.exec();
}
