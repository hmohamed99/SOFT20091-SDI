#include <Qapplication.h>
#include <QPushButton>
//#include "source2.h"
#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include "QApp.h"
#include "TreeView.h"

//#include "source2.h"
/**Stolen from here:/
/**https://sourcegraph.com/github.com/MultiMC/MultiMC5@6cb956b45b97ba685d9cef96484747544615e724/-/blob/application/InstanceWindow.cpp#L72
	*https://www.youtube.com/watch?v=qEGRYYx0RBw
	*https://www.youtube.com/watch?v=FMs4-oedxKo
	*https://evileg.com/en/post/87/
	**/

QAPP::QAPP(QWidget* parent) : QMainWindow(parent)/*, QApplication(argc, argv)*/ //Do not fully understand this unfortuately: seems to be very common with many Applications based on the QT Framework
{
	AddImgs = new QPushButton(this); /** Places button within the "Parent" QMaiNWindow /**Must include this to ensure Button is placed corerctly within the QWidget/QmaiNWindow and not as a seperate QObject!**/
	AddImgs->setGeometry(50, 50, 300, 30);
	/**Must have QBP as pointers otehrwise connect is not acceisbel for some reason**/
	{
		AddImgs->setText("Open");
		/** https://wiki.qt.io/How_to_Use_QPushButton **/
		/** this somehow functions without a dedicated Signal Function **/
		connect(AddImgs, SIGNAL(clicked(bool)), this, SLOT(on_opened_dir(/*"file:///C:/Documents and Settings/All Users/";*/)));
		/** set set default state of QBP to TRUE so the next Signal triggers when the QBP is toggled to false again isneta dof just checking for true)**/

	}
		/*QW->*/setMinimumSize(400, 800);
	/*QW->*/show();

}


void QAPP::on_opened_dir(/*QUrl OpenThis*/)
{
	QAPP QP;
	QDesktopServices QD; //** very bad practice Might case a memory leak?**/
	/** Could be changed to instead initialise a new teeView widget for the file browser) **/
	QD.openUrl(Url);
	AddImgs->setText("Close");
	//emit OpeningDir();
	//TreeView TV(QDir::currentPath()); /** cant seem to call another contruct within a memeber function of a seperate class **/


}


void QAPP::Setlocation() /**called automatically by the constructor **/
{
	/*AddImgs->setText("Open");
	AddImgs->resize (100, 100);*/
	Url = "file:///C:/Documents and Settings/All Users/";
	printf("Mian QAPP");
}