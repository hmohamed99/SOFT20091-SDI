#include <qtreeview.h>
#include "QApp.h"
#include "TreeView.h"

/** https://doc.qt.io/qt-5/model-view-programming.html#using-views-with-an-existing-model 
	http://www.java2s.com/Code/Cpp/Qt/UsingQTreeView.htm
	https://stackoverflow.com/questions/12357756/qfilesystemmodel-setrootpath
	https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex
	https://doc.qt.io/qt-5/qfilesystemmodel.html#setRootPath
	https://doc.qt.io/qt-5/qtreeview.html
**/

TreeView::TreeView(/*QString Path2,*/ QWidget* parent) : QTreeView (parent) /**COntructors can inherit from other classes **/
{
	Add = new QPushButton(this);
	FileSystem = new QFileSystemModel;// (FileSystem);
	FileSystem->setRootPath(Path2);
	FileTree = new QTreeView(this);
	Add->setGeometry(10, 10, 380, 50); /** very imprecise positioning **/
	FileTree->setGeometry(30, 70, 540, 300); /** very imprecise positioning **/
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
	//connect()
	//MainFolder = Path;
	//FileTree->
	FileTree->setModel(FileSystem);
	FileTree->setRootIndex(FileSystem->index(Path2));
	setMinimumSize(600, 400);
	show();
}

void TreeView::OpeningDir()
{
	printf("TreeView Loaded");
	show();
}

void TreeView::Items(/*QAbstractItemModel* model*//*, this*/)
{
	
}


