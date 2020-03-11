#include <Qapplication.h>
#include <QPushButton>

#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include <qsplitter>

#include "QApp.h"

QAPP::QAPP(QWidget* parent) : QSplitter(parent)/*, QApplication(argc, argv)*/ //Do not fully understand this unfortuately: seems to be very common with many Applications based on the QT Framework
{
	AddImgs = new QPushButton(this); /** Places button within the "Parent" QMaiNWindow /**Must include this to ensure Button is placed corerctly within the QWidget/QmaiNWindow and not as a seperate QObject!**/
	//AddImgs->setGeometry(50, 50, 300, 30);
	Exit = new QPushButton(this);
	AddImgs->setFixedSize(300, 30);
	//AddImgs->setMaximumSize(300, 30);
	//Exit->setMaximumSize(300, 30);
	
	//Exit->setGeometry(50, 100, 300, 30);
	Exit->setFixedSize(300, 30);
	//Exit->setLocale
	
	//TreeView TV;
	/**Must have QObjects as pointers otherwise connection methods cannot be accessed correctly**/
	{
		AddImgs->setText("Open");
		Exit->setText("Exit");
		//setOrientation(Qt::Vertical);
		//connect(AddImgs, SIGNAL(clicked()), this, SLOT(OpenedDir()));
		connect(QAPP::AddImgs, &QPushButton::clicked, this, &QAPP::OpenedDir);
		//connect(Exit, SIGNAL(clicked()), this, SLOT(CloseMain()));
		connect(QAPP::Exit, &QPushButton::clicked, this, &QAPP::CloseMain);
		

	}
		//setMinimumSize(400, 800);
	//QW->setMinimumSize(200, 200);
	//addWidget(QW);
	QAPP::show();

}



/** Experiment to setup TV As a child widget as a workaround/bypass for the connection problem where Signals/Slots cannot be made between different classes of QObject**/
/** Slots may not be able to call other Objects **/
/** this should be its own class and not as a member function of the main QAPP class: but allows full Connection functionality to be achieved in this way **/
void QAPP::SetupView()
{
	FileTree = new QTreeView(this);
	/** use pointer trick with push buttons to allow Widgets to be embedded: **/
	//InputImages = new QList<QDir>;
	//InputImages.
	Add = new QPushButton(FileTree); //* Allows the QPushButton to be added to the TreeView even though it technically belongs to the Main QAPP header *//
	//* QEvent::MouseButtonDblClick ClickOpen *//
	FileSystem = new QFileSystemModel;// (FileSystem);
	FileSystem->setRootPath(Path2);
	//FileTree = new QTreeView(this);
	//FileSystem->
	Add->setGeometry(10, 10, 380, 50); /** very imprecise positioning **/
	FileTree->setGeometry(430, 70, 520, 450); /** very imprecise positioning **/
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
		FileTree->setDragDropMode(QAbstractItemView::DragDrop); //* https://https://doc.qt.io/qt-5/qabstractitemview.html#DragDropMode-enum *//
		FileTree->setDropIndicatorShown(true); //https://doc.qt.io/qt-5/model-view-programming.html#using-drag-and-drop-with-item-views
	}
	//QMouseEvent e(QEvent::Type(4), Qt::MouseButton button);
	//connect(Add, SIGNAL(clicked()), this, SLOT(ClosedDir()));
	//FileSystem->canDropMimeData(true);
	//connect(FileSystem, &QFileSystemModel::dropMimeData, this, )
	connect(Add, &QPushButton::clicked, this, &QAPP::ClosedDir);
	//connect(FileTree, SIGNAL(QEvent::Type(4)), this, SLOT(ClosedDir()));
	//connect(FileTree, SIGNAL(event.DoubleClicked(true)), this, SLOT(ClosedDir()));
	//connect(FileTree, SIGNAL(mouseDoubleClickEvent), this, SLOT(ClosedDir()));

	//*Get index of Itemmodel to return Filename
	//*Newer suntax of Pointers required to access interited slots from QAbstractItemModel
	connect(FileTree, &QTreeView::doubleClicked, this, &QAPP::TestSlot); //*https://doc.qt.io/qt-5/qabstractitemview.html#mouseDoubleClickEvent
	//connect(FileTree, &QTreeView::event., this, SLOT(ClosedDir()));
	//connect(keyPressEvent, SIGNAL(key(), this, SLOT(TestSlot()));
	FileTree->setModel(FileSystem);
	FileTree->setRootIndex(FileSystem->index(Path2));
	FileTree->setRootIsDecorated(FileSystem);
	QDirIterator It(Path2, QDirIterator::Subdirectories);

	while (It.hasNext()) 
	{
		//QFile f()
		InputImages.append(It.next()); //* https://doc.qt.io/qt-5/qdiriterator.html#next *//
		qDebug() << It.filePath(); //* Bad Reference Link: https://stackoverflow.com/questions/8052460/recursively-iterate-over-all-the-files-in-a-directory-and-its-subdirectories-in *//
		//InputThumb.append(Imgs.open(InputImages.at(1)) //*QList of Iamages
		//InputThumb.append(QFile::open(InputImages.at(1)) //*QList of Iamages
	}
	qDebug() << "Found: " << InputImages.size() << "Images" << endl; //*Returned Image size is bugged *//
	//InputImages.append(FileSystem);


	//setMinimumSize(600, 400);
	FileTree->setMinimumSize(600, 400);
	FileTree->hide();
	
}


void QAPP::OpenedDir() 
{
	//parent::
	qDebug() << "Opened: " << Path2 << endl;
	addWidget(FileTree);
	FileTree->show();
	isbusy = true;
	//setMinimumSize(1000, 800); //* overridden by QSplitterClass as it only resizes for a split second*//

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
	isbusy = false;
	//~TreeView();
	//this->minimumSize();
	//this->setMinimumSize(400, 600); 
	this->setFixedSize(400, 600); //* can't make this resize dynamically *//
	AddImgs->setText("Open");
	Exit->setText("Exit"); //* Could use a pointer to prevent needless Redefinitions *//
	//show();
	/*QAPP::close();*/
}
void QAPP::TestSlot()
{
	AddImgs->setText("Clicked Item");
	//*qDebug << QAbstractItemView::currentIndex;
	FileTree->currentIndex;
}
void QAPP::Setlocation() /**called automatically by the constructor **/
{
	/*AddImgs->setText("Open");
	AddImgs->resize (100, 100);*/
	Url = "file:///C:/Documents and Settings/All Users/";
	printf("Main QAPP Loaded");
}
void QAPP::CloseMain()
{
	if (!isbusy)
		QAPP::close();
	else
	{
		printf("File Dialog is Open!");
		Exit->setText("Wait for close");
	}

}