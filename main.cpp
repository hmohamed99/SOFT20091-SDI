#include <Qapplication.h>
#include <QPushButton>

#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include "QApp.h"



int main(int argc, char** argv) //** Main function from which all other Interface constructors and objects are called **//
{
	QApplication xapps(argc, argv); 
	
	QAPP QA; 
	QA.Setlocation(); 
	QA.SetupView(); /**Instantiate the child QTreeView widget **/

	return xapps.exec(); 
}