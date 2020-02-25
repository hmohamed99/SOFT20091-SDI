#include <qtreeview.h>

#include "TreeView.h"


//TreeView::TreeView(QWidget* parent) :
//	/*QTreeView(parent)*/QTreeView (parent)
//{
//	///** needs to be a better format later to allow proatbility **/
//	///** coudl also be defined upon runtime by the use if missing (like an install step **/
//	//Path->setRootPath("E:\Project\Misc\QtConsoleApplication3\imgs");
//	//FileTree = new QTreeView(this);
//	////setMinimumSize(100, 200);
//	//FileTree->setModel(Path);
//	//FileTree->setMinimumSize(100, 200);
//	////FileTree->show();
//	//show();
//	//Treeview::QTreeView;
//	{
//		setAllColumnsShowFocus(true);
//		setAutoExpandDelay(100);
//		setSortingEnabled(true);
//		setHeaderHidden(false);
//		columnWidth(100);
//		setRootIsDecorated(true);
//		setSortingEnabled(true);
//	}
//	QWidget;
//	{
//		
//	}
//
//
//
//}

/** https://doc.qt.io/qt-5/model-view-programming.html#using-views-with-an-existing-model 
	http://www.java2s.com/Code/Cpp/Qt/UsingQTreeView.htm
	https://stackoverflow.com/questions/12357756/qfilesystemmodel-setrootpath
	https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex
	https://doc.qt.io/qt-5/qfilesystemmodel.html#setRootPath
	https://doc.qt.io/qt-5/qtreeview.html
**/

TreeView::TreeView(/*QString Path2,*/ QWidget* parent) : QTreeView (parent) /**COntructors can inherit from other classes **/
//TreeView::TreeView(QWidget parent) /**COntructors can inherit from other classes **/
{
	//Path = QDir::currentPath(); override
	Add = new QPushButton(this);
	FileSystem = new QFileSystemModel;// (FileSystem);
	//Path2 = QDir::currentPath();
	FileSystem->setRootPath(Path2);
	FileTree = new QTreeView(this);
	//FileTree->blockSignals(true);
	//Path->setRootPath("E:\Project\Misc\QtConsoleApplication3\imgs");
	//FileTree->blockSignals(false);
	//QLW = new QListWidget(this);
	//QW = new QWidget(this);
	//QW->setMaximumSize(100, 200);
	Add->setGeometry(10, 10, 380, 50); /** very imprecise positioning **/
	FileTree->setGeometry(30, 70, 340, 300); /** very imprecise positioning **/
	/*QTreeView(parent);*/
	{
		setAllColumnsShowFocus(true);
				setAutoExpandDelay(1);
				setSortingEnabled(true);
				setHeaderHidden(false);
				columnWidth(10);
				setModel(FileSystem);
				setColumnHidden(100, false);
				setRootIsDecorated(true);
				setSortingEnabled(true);
	}
	//MainFolder = Path;
	//FileTree->
	FileTree->setModel(FileSystem);
	FileTree->setRootIndex(FileSystem->index(Path2));
	setMinimumSize(400, 400);
	show();
}

//void TreeView::DropEvent(QDropEvent* event)
//{
//	//QListWidget::dropEvent(event);
//	QLW->dropEvent(event);
//}

void TreeView::Items(/*QAbstractItemModel* model*//*, this*/)
{
	//rootDirectory 
	//FileTree->setModel(model);
	//QTreeView::setModel(model);
	/** This mya be pohrribly broken by forcibly inserting /associating tye mdoel with the QFileSystemModel **/
	//FileSystem->setRootPath(MainFolder); /** may not intialise as main constructor.memebers might not be called yet**/
	 /** may not intialise as main constructor.memebers might not be called yet**/
	//setRoot
	
	//QTreeView::setModel(model);
	
}


