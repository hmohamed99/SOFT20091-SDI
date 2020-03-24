#include <Qapplication>
#include <QPushButton>

#include <iostream>
#include <QtCore>
#include <qdesktopservices>
#include <qobject>
#include "QApp.h"



int main(int argc, char** argv) /** Main function from which all other Interface constructors and objects are called **/
{
	QApplication xapps(argc, argv); /** QAPPlictaion Constructor: this is in main for now as 
	
									for not entrely understiod reasons calling it from other classes become convulted and unreliable 
									this is current suspected to be due to not having a sufficient global scope where all subsequent QObjects are dierctly Visable*/
	
	QAPP QA; 
	QA.Setlocation(); 
	QA.SetupView(); /**Instantiate the child QListView widget: Unfortuately this crude method will be implemented for now as other widgets can't seem to be called reliably from other classes  as they are not visible to the QApplictaion constructor**/
	//QA.DebugMode();

	return xapps.exec(); 
}