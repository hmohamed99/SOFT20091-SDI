#include <Qapplication.h>
#include <QPushButton>
//#include "source2.h"
#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include "QApp.h"
#include "TreeView.h"


int main(int argc, char** argv) 
{
	QApplication xapps(argc, argv);
	//QUrl OpenThis = "file:///C:/Documents and Settings/All Users/";
	
	QString Path = QDir::currentPath();
	QAPP QA; //** This somehow Works **//
	//QA.Setlocation(); /** seems to work as a quick hack to acces member functions from main **/
	TreeView TV;// (/*Path*/);// ("E:\Project\Misc\QtConsoleApplication3\imgs");
	

	return xapps.exec(); //** This somehow Works **//
}