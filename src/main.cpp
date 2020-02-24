#include <QtWidgets/qapplication.h>
#include <QPushButton>
#include "source2.h"
#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>


/**
 * \basic function to open a provided directory in windows file explorer
 */

void OpenDir(QUrl Dir, QDesktopServices QD) 
{
	printf("Test!");
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
	

	widget.setMinimumSize(400, 200); 
	
	QPushButton* button = new QPushButton("Test!", &widget); /** Initialise button objects and adds then to the Widget object with a pointer */
	QPushButton button2(button);
	
	button->setGeometry(50, 50, 180, 120);
	button->setText("Button");
	button->setToolTip("Main QPushButton Object");

	button2.setGeometry(10, 20, 120, 20);
	button2.setText("Button2");
	button2.setToolTip("Click Me Please!");
	
	
	TestClass TC(64);		//** \Ignore this: (A test to load classes from a header, and has nothing to do with the Main application) 
	TestClass TC2(1024);

	printf("%i \n", TC.dbl(2));
	printf("%i \n", TC.mult(4));
	printf("%i \n", TC.pwr(2));
	
	printf("%u \n", TC2.pwr(4l));

	OpenDir(TestDir, QD);
	
	widget.show(); // \Show Widget class object 

	return xapps.exec();
}