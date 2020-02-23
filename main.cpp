#include <QtWidgets/qapplication.h>
#include <QPushButton>
#include "source2.h"
#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
/**
 * \using.h prefix may be Bad practice for Importing Headers an other dependencies
 */

//class QApp: QPushButton, QWidget/*, QApplication*/ //Please ignore this class: (was a Failed attempt to use a class to clone multiple windows)
//{
//public:
//	QPushButton A;
//	QWidget B;
//	//QApplication C(); 
//
//	//QApplication QA(int a, char** b)
//	//{
//	//	//C.applicationPid();
//	//	QA->
//	//}
//
//	QApp(/*QApplication C(int a, char** b)*/)
//	{
//		QW();
//		QBP();
//		//QA(argc, argv);
//		/*A.setGeometry(10, 10, 20, 20);
//		B.setFixedSize(100, 200);*/
//		B.show();
//		//return A, B;
//
//		
//	}
//	QWidget QW()
//	{
//		B.setFixedSize(100, 200);
//		printf("\n, QW");
//	}
//	QPushButton QBP(/*QPushButton A*/)
//	{
//		/*QPushButton A;*/
//		A.setGeometry(10, 10, 20, 20);
//		printf("\n, QBP");
//	}
//	
//
//};

/**
 * \basic function to open a provided directory in windows file explorer
 */

void OpenDir(QUrl Dir, QDesktopServices QD) 
{
	//printf("Test!");
	QD.openUrl(Dir);
	//QLatin1String("Test!");
};

/** 
 * \Main Application Function
 */

int main(int argc, char** argv) 
{
    /** 
	 * \Construct main QApp Class
	 */
	 
	QApplication xapps(argc, argv); 
	QWidget widget; /** *\Initialise Widget window */
	QSignalMapper QS; 

	QDesktopServices QD; // \used for faile and directory handling
	QObject Signal;

	QUrl TestDir("file:///C:/Documents and Settings/All Users/"); // \test user Directory to open

	//QEvent QE = (button->clicked());

	// \This is a window directory so May need to Replace this with a different string to function correctly:
	

//	//signals  
	widget.setMinimumSize(400, 200); 
	
	QPushButton* button = new QPushButton("Test!", &widget); // \Initialise button objects and adds then to the Widget object with a pointer
	QPushButton button2(button);
	
	button->setGeometry(50, 50, 180, 120);
	button->setText("Button");
	button->setToolTip("Main QPushButton Object");

	button2.setGeometry(10, 20, 120, 20);
	button2.setText("Button2");
	button2.setToolTip("Click Me Please!");



//tried to load a Qapplication as a object which didn't construct the the Qapplictaion Class dependency properly

	/*app ap;
	MyClass(argc, argv);
	/*QApp Application;
	Application.QW();
	Application.QBP();*/
	//QApp->widget;
	//app->application;// (argc, argv);// ->apps;*/*/

	//	//MyClass* app = new MyClass(argc, argv);
//	//QS.event(button2.clicked());
//	//MyClass* app = new MyClass(QApplication( argc, argv);
//	//MyClass* app = new QApplication( argc, argv);
//	//button->setGeometry(50, 50, 80, 80);
//	//xappswidg->setMinimumSize(100, 100);
//	////app->
//	//app->widgett.show();*/
	
	
	TestClass TC(64);		// \Ignore this: (A test to load classes from a header, and has nothing to do with the Main application) 
	TestClass TC2(1024);

	printf("%i \n", TC.dbl(2));
	printf("%i \n", TC.mult(4));
	printf("%i \n", TC.pwr(2));
	
	printf("%u \n", TC2.pwr(4l));

	//widget.setWindowFlags(Qt::Window);
	
	//QD.openUrl/*(QUrl(*/(TestDir)/*, QUrl::TolerantMode))*/
	

	//QD.openUrl/*(QUrl(*/(TestDir)/*, QUrl::TolerantMode))*/;

	OpenDir(TestDir, QD);
	
	widget.show(); // \Show Widget class object 

	//QObject::connect(button2, SIGNAL(clicked(int)), QD, SLOT(QS()));
	//QObject::connect(button2, &QPushButton::clicked, QD, &QDesktopServices::openUrl(TestDir));
	//QObject::connect(button, SIGNAL(clicked(), QD, SLOT(OpenDir(TestDir, GD))))
//
	return xapps.exec();//app->exec(apps); //app->~MyClass; // app->apps.exec;
//	return xapps.exec();//application.exec;//app->exec(apps); //app->~MyClass; // app->apps.exec;
	


}