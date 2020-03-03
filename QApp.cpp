#include <Qapplication.h>
#include <QPushButton>

#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include <qsplitter>

#include "QApp.h"

QAPP::QAPP(/*QWidget*/ QSplitter* parent) : QMainWindow(parent)/*, QApplication(argc, argv)*/ //Do not fully understand this unfortuately: seems to be very common with many Applications based on the QT Framework
{
	AddImgs = new QPushButton(this); /** Places button within the "Parent" QMaiNWindow /**Must include this to ensure Button is placed corerctly within the QWidget/QmaiNWindow and not as a seperate QObject!**/
	AddImgs->setGeometry(50, 50, 300, 30);
	
	//TreeView TV;
	/**Must have QObjects as pointers otherwise connection methods cannot be accessed correctly**/
	{
		AddImgs->setText("Open");
		connect(AddImgs, SIGNAL(clicked()), this, SLOT(OpenedDir()));
		

	}
		setMinimumSize(400, 800);
	show();

}



/** Experiment to setup TV As a child widget as a workaround/bypass for the connection problem where Signals/Slots cannot be made between different classes of QObject**/
/** Slots may not be able to call other Objects **/
/** this should be its own class and not as a member function of the main QAPP class: but allows full Connection functionality to be achieved in this way **/
void QAPP::SetupView()
{
	FileTree = new QTreeView();
	/** use pointer trick with push buttons to allow Widgets to be embedded: **/
	
	Add = new QPushButton(FileTree); //* Allows the QPushButton to be added to the TreeView even though it technically belongs to the Main QAPP header *//

	FileSystem = new QFileSystemModel;// (FileSystem);
	FileSystem->setRootPath(Path2);
	//FileTree = new QTreeView(this);
	
	Add->setGeometry(10, 10, 380, 50); /** very imprecise positioning **/
	FileTree->setGeometry(30, 70, 740, 700); /** very imprecise positioning **/
	//QTreeView(parent)
	{
		FileTree->setAllColumnsShowFocus(true);
		FileTree->setAutoExpandDelay(1);
		FileTree->setSortingEnabled(true);
		FileTree->setHeaderHidden(false);
		FileTree->columnWidth(10);
		FileTree->setModel(FileSystem);
		FileTree->setColumnHidden(100, false);
		//FileTree->setRootIsDecorated(true); //* Redundant: Root is set as decorated by default *//
		FileTree->setSortingEnabled(true);
		FileTree->setExpandsOnDoubleClick(true);
		FileTree->itemsExpandable();
		//FileTree->setAnimated(true);
		//FileTree->adjustSize();
		
	}
	connect(Add, SIGNAL(clicked()), this, SLOT(ClosedDir()));
	//connect(keyPressEvent, SIGNAL(key(), this, SLOT(TestSlot()));
	FileTree->setModel(FileSystem);
	FileTree->setRootIndex(FileSystem->index(Path2));
	FileTree->setRootIsDecorated(FileSystem);
	setMinimumSize(600, 400);

	
}


void QAPP::OpenedDir() 
{
	FileTree->show();
	/* Don't actually need this slot here: Expandable can be set with itemsExpandable()*/
	/* Slots are only needed for carrying out actions/events with another Slot/Signal/ or other similar Event has occurred or if the Widget is already Initialised */
	//FileTree->Expandall(); //* TreeView will not update its state unless the updates are done within a slot? *//
	//* Expanding TreeView seems to be CPU intensive *//
	AddImgs->setText("Opened");
	Add->setText("Close");
	//hide();
}

void QAPP::ClosedDir()
{
	FileTree->hide();
	//~TreeView();
	
	AddImgs->setText("Open");
	//show();
}
void QAPP::TestSlot()
{
	AddImgs->setText("Clicked Item");
}
void QAPP::Setlocation() /**called automatically by the constructor **/
{
	/*AddImgs->setText("Open");
	AddImgs->resize (100, 100);*/
	Url = "file:///C:/Documents and Settings/All Users/";
	printf("Main QAPP Loaded");
}