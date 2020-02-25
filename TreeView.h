#pragma once

#include <qtreeview.h>
#include <QFileSystemModel>
#include <QPushButton>
#include <qlistwidget.h>
class TreeView : public QTreeView
{
	Q_OBJECT
public:
	explicit TreeView(/*QString Path, */QWidget* parent = 0); /** rpevents implict conversion or invalid paramaters from being used when instanciating an object **/
	//TreeView(QWidget parent);
	/*virtual*/ void Items(/*QAbstractItemModel* model*//*, this*/);
	//void DropEvent(QDropEvent* event);
	QString Path2 = QDir::currentPath();
signals:

private slots:
	///**(Exit FileDirView, return main focus to Main QWindowWidget, send img locs to OpenCV Setup and MainWigdet **/
	//void on_closed_state(); /** make thsi pilic methods for all widgets/instances/Objects? -To avoid repetitiom of functon spam for subnested Widgets/Instances/Objects**/
	///** https://www.data-structures-in-practice.com/intrusive-linked-lists/ **/
	///** very bad link remove later: https://old.reddit.com/r/programming/comments/25xpre/bjarne_stroustrup_why_you_should_avoid_linked/ **/
	///** https://www.codeofhonor.com/blog/avoiding-game-crashes-related-to-linked-lists **/
	///**Open rpecinfigured Img Loc/Url, initialise a sa basic treeView Array Could use special optimized LinkedList varients such as Intrusive linked lists e.g.... **/
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
	//QListView
	//QString MainFolder;// = "E:\Project\Misc\QtConsoleApplication3\imgs";
	int ItmCount = NULL;
	//QWidget* QW = nullptr;
	//QListWidget* QLW = nullptr;
};