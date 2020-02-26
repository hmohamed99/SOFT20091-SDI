#pragma once

#include <qtreeview.h>
#include <QFileSystemModel>
#include <QPushButton>
#include <qlistwidget.h>

/**
(Exit FileDirView, return main focus to Main QWindowWidget, send img locs to OpenCV Setup and MainWigdet
*void on_closed_state(); make thsi pilic methods for all widgets/instances/Objects? 
	-To avoid repetitiom of functon spam for subnested Widgets/Instances/Objects
Open Pre-Configured Img Loc/Url, initialise as a basic treeView Array Could use special optimized LinkedList varients such as Intrusive linked lists e.g.... 
*https://www.data-structures-in-practice.com/intrusive-linked-lists/
	very bad link remove later: https://old.reddit.com/r/programming/comments/25xpre/bjarne_stroustrup_why_you_should_avoid_linked/
	https://www.codeofhonor.com/blog/avoiding-game-crashes-related-to-linked-lists
**/
class TreeView : public QTreeView
{
	Q_OBJECT
public:
	explicit TreeView(/*QString Path, */QWidget* parent = 0); /** Prevents implict conversion or invalid paramaters from being used when instaniating an object **/
	/*virtual*/ void Items(/*QAbstractItemModel* model*//*, this*/);
	//void DropEvent(QDropEvent* event);
	QString Path2 = QDir::currentPath();
signals:

private slots:

	//void on_opened_state();
	//void sort_asc();
	//void sort_desc();
	//void last_modif();
	//void size_type();

private:
	/** could use buttons if time is an issue **/
	//QList* SortOptions = nullptr; /** Why ptrs? **/
	
	QFileSystemModel* FileSystem = nullptr;
	QTreeView* FileTree = nullptr;
	QPushButton* Add = nullptr;
	//QString MainFolder;// = "E:\Project\Misc\QtConsoleApplication3\imgs";
	int ItmCount = NULL;
	//QWidget* QW = nullptr;
	//QListWidget* QLW = nullptr;
};