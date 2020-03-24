#include <Qapplication.h>
#include <QPushButton>

#include <iostream>
#include <QtCore>
#include <qdesktopservices.h>
#include <qobject.h>
#include <qsplitter>
#include <QMouseEvent>
#include "CustomItemListModel.h"
#include "ItemGridModel.h"
#include "QApp.h"

//#define DEBUG_MODE

QAPP::QAPP(QWidget* parent) : QSplitter(parent)/*, QApplication(argc, argv)*/ //Do not fully understand this unfortuately: seems to be very common with many Applications based on the QT Framework
{
	TestWidget = new QWidget(this); /** Imbedded widget to allow more precision/ over Button an dobject placement */
	TestWidget->setMinimumSize(500, 500);
	//A = new QStringListModel(InputImages);

	AddImgs = new QPushButton(TestWidget); /** Places button within the "Parent" QMaiNWindow /**Must include this to ensure Button is placed corerctly within the QWidget/QmaiNWindow and not as a seperate QObject!**/
	//AddImgs->setGeometry(50, 50, 300, 30);
	//QDesktopServices QD;
	//QD = new QDesktopServices();
	//QM = new QPoint();
	Exit = new QPushButton(TestWidget);
	AddImgs->setGeometry(50, 50, 300, 30);
	//AddImgs->setFixedSize(300, 30);
	//AddImgs->setMaximumSize(300, 30);
	//Exit->setMaximumSize(300, 30);
	
	Exit->setGeometry(50, 100, 300, 30);
	//Exit->setFixedSize(300, 30);
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
		//connect(QAPP::OpenRoot, &QPushButton::clicked, this, &QAPP::OpenedRoot);
		

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
	FileTree = new QListView(this); /** currently considering to refatcor this into a QListVoew for simplistity and poentially improved interfacing with teh QList */
	//InputImages = new Qlist<QString>(this);
	/** use pointer trick with push buttons to allow Widgets to be embedded: **/
	Add = new QPushButton(FileTree); /** Allows the QPushButton to be added to the TreeView even though it technically belongs to the Main QAPP header */
	/** QEvent::MouseButtonDblClick ClickOpen */

	Add->setGeometry(10, 10, 380, 50); /** very imprecise positioning **/
	FileTree->setGeometry(430, 70, 520, 450); /** very imprecise positioning **/
	//QListView(parent)
	{
		FileTree->setAlternatingRowColors(true);
		//FileTree->dragDropOverwriteMode//
		FileTree->setGridSize(QSize(100, 30));
		FileTree->setResizeMode(QListView::Adjust);
	}
	connect(Add, &QPushButton::clicked, this, &QAPP::ClosedDir);

	/**Get index of Itemmodel to return Filename
	/**Newer suntax of Pointers required to access interited slots from QAbstractItemModel
	/** Don't need to pass parameters to the called signal/slot with this specila pointer.reference method **/
	connect(FileTree, &QListView::doubleClicked, /*&QAPP::FileTree->indexAt*/this, &QAPP::Filehandler/*(QAPP::FileSystem->fileInfo)*/); /**https://doc.qt.io/qt-5/qabstractitemview.html#mouseDoubleClickEvent*/
	
	
	QDirIterator It(Path2, /*QList<QString>(),*/ QDirIterator::NoIteratorFlags); //https://doc.qt.io/qt-5/qdiriterator.html#next
	
	/** Could be its own Function in theory for better degree of refactoring */
	/**8 error hansling here if QList length and acuall Diercory conets do not mtach/Desync */
	//int a = 0;
	while (It.hasNext()) /** MaiN While loop for instantiating the LinkedList with File Directories via QDirIterator */
	{
		//QFile f()
		InputImages.append(It.next()); /** https://doc.qt.io/qt-5/qdiriterator.html#next */
		//It.next();
		//A->insertRow(a);
		//InputImages.append(It.fileName()); /** https://doc.qt.io/qt-5/qdiriterator.html#next */
		//InputImages.append(It.fileInfo()); /** https://doc.qt.io/qt-5/qdiriterator.html#next */
		//A->insertRow(a++);
		qDebug() << It.fileName(); /** Bad Reference Link: https://stackoverflow.com/questions/8052460/recursively-iterate-over-all-the-files-in-a-directory-and-its-subdirectories-in */
		
		//InputThumb.append(Imgs.open(InputImages.at(1)) /**QList of Iamages
		//InputThumb.append(QFile::open(InputImages.at(1)) /**QList of Iamages
	}
	//a = 0;
	//A->insertColumn(0);
	//A->flags(Qt::ItemIsEditable)
	//A->dataChanged(FileTree);
	//qDebug() << CustomItemListModel::hasIndex;
	//A = new QStringListModel(InputImages); /**https://doc.qt.io/qt-5/model-view-programming.html#using-a-model*/
	//A = new CustomItemListModel(InputImages); /**https://doc.qt.io/qt-5/model-view-programming.html#using-a-model*/
	//A->insertColumn(1);
	//A = new QStandardItemModel(InputImages); /**https://doc.qt.io/qt-5/model-view-programming.html#using-a-model*/
	//A = new ItemGridModel(InputImages);
	//qDebug(QModelIndex::internalId())
	A = new CustomItemListModel(InputImages);
	//A->checkIndex(
	//A = new ItemGridModel(InputImages);
	//A->index(InputImages.size(), 1, InputImages);
	//A = new QStringli(InputImages);
	FileTree->setModel(A);
	//A->index()
	//qDebug() << A->hasIndex()
	qDebug() << A->rowCount();
	qDebug() << A->columnCount();
	////qDebug() << A->checkIndex();
	//qDebug() << "Found: " << InputImages.size() << "Images" << endl; /**Returned Image size is bugged */

	//InputImages.append(FileSystem);


	//setMinimumSize(600, 400);
	FileTree->setMinimumSize(600, 400);
	FileTree->hide();

	//DebugMode();
	
}

//void QAPP::DebugMode()
//{
//#ifdef DEBUG_MODE
//	OpenRoot = new QPushButton(TestWidget);
//	OpenRoot->setGeometry(50, 150, 300, 30);
//	OpenRoot->setText("Open Root");
//#endif
//}


void QAPP::OpenedDir() 
{
	//parent::
	qDebug() << "Opened: " << Path2 << endl;
	addWidget(FileTree);
	FileTree->show();
	isbusy = true;
	//setMinimumSize(1000, 800); /** overridden by QSplitterClass as it only resizes for a split second*//

	/* Don't actually need this slot here: Expandable can be set with itemsExpandable()*/
	/* Slots are only needed for carrying out actions/events with another Slot/Signal/ or other similar Event has occurred or if the Widget is already Initialised */
	//FileTree->Expandall(); /** TreeView will not update its state unless the updates are done within a slot? *//
	/** Expanding TreeView seems to be CPU intensive */
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
	this->setFixedSize(400, 600); /** can't make this resize dynamically */
	AddImgs->setText("Open");
	Exit->setText("Exit"); /** Could use a pointer to prevent needless Redefinitions */
	//show();
	/*QAPP::close();*/
}
void QAPP::Filehandler(QModelIndex Index) /** Experimental Slot for handling and pass infomation derived from the ModelIndex: this may be a good apsing for a future metdhod of handling/passing file information to external methods */
{
	//AddImgs->setText("Clicked Item");
	//QMouseEvent::pos;
	//QString V = Index.
	//QString V = Index.row();
	qDebug() << Index.column();
	qDebug() << Index.data();
	qDebug() << "Row" << Index.row();
	/** hacky method to get the Current Index passed to this specific slot where the Selected File now becomes the corrisponding Index of the InputImages QList */
	/** 
	this is considered Hacky ATM due to a bug this approach introduces wher the QList 
	will Desync with the TreeView if sorted: this could be fixed by either sorting the QList 
	when this occurs or to have the QAbtractItemModel reflect the QLists current state 
	*/
	//QString V = InputImages.at(Index.row()+2); /** Bad link again: https://stackoverflow.com/questions/40285104/qt5-get-value-of-item-clicked-in-a-listview */
	QString V = InputImages.at(Index.row()); /** Bad link again: https://stackoverflow.com/questions/40285104/qt5-get-value-of-item-clicked-in-a-listview */
	//QUrl V = InputImages.at(Index.row()); /** Bad link again: https://stackoverflow.com/questions/40285104/qt5-get-value-of-item-clicked-in-a-listview *//
										 /**https://doc.qt.io/qt-5/qmodelindex.html#row*//*/*/
	//int V = Index.row();
	//QDesktopServices QD;
	//qDebug() << V;
	////Imgs.open(V, QIODevice::WriteOnly);
	QImage QI(V);
	qDebug() << QI.size();
	qDebug() << QI.format();
	qDebug() << QI.bits();
	qDebug() << QI.depth() << "Bit Depth";
	//qDebug() << QI.byteCount() << "Bytes";
	qDebug() << QI.width()<< "*" << QI.height() << "*" << QI.depth() << "/ 8 ="<< QI.sizeInBytes() << "Bytes (Uncompressed Bitmap)"; /** The retruned Image size is not actually bugged and is the size of the Uncompressed Bitmap: https://doc.qt.io/qt-5/qimage.html#sizeInBytes */
	AddImgs->setText(V);
	//QI.load(V);
	//QD.openUrl(V);
	//Imgs.fileName();
	//QM ->QMouseEvent::pos;
		//qDebug << QAbstractItemView::currentIndex;
		//QString a = FileTree->currentIndex();
		//FileHandler.open(FileSystem->sibling(1, 1));
		//int a = QM.x();
	//FileHandler.open(FileSystem->fetchMore(FileTree->currentIndex()));
	//qDebug << FileTree->SelectRows;
}
//@Depreciated
void QAPP::Setlocation() /**called automatically by the constructor **/
{
	/*AddImgs->setText("Open");
	AddImgs->resize (100, 100);*/
	Url = "file:///C:/Documents and Settings/All Users/";
	printf("Main QAPP Loaded");
}

//void QAPP::OpenedRoot()
//{
//	QDesktopServices QD;
//	QD.openUrl(QDir::currentPath());
//}
void QAPP::CloseMain() /** Experimental Failsafe Slot for aborting closes if the isBusy bool is true */
{
	if (!isbusy)
	{
		QAPP::close();
		qApp->quit();
		//qApp->destroyed();
		QAPP::destroy();
		
	}
	else
	{
		//printf("File Dialog is Open!");
		qWarning() << "File Dialog is Open!";
		Exit->setText("Wait for close");
	}

}