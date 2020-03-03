#pragma once
//#ifndef QAPP
//#define QAPP
#include <qwidget.h>
#include <QPushButton>
#include <QMainWindow>
#include <qurl.h>
#include <QSplitter>
#include <qtreeview.h>
#include <qfilesystemmodel.h>

class QAPP : public QMainWindow/*, public QObject*///, public TreeView
{
	Q_OBJECT
public:
	explicit QAPP(/*QWidget*/ QSplitter* parent = 0); 
	void Setlocation();
	//void OpeningDir();
	void SetupView();
	
	QUrl Url;
	QString Path2 = QDir::currentPath();
	//QWidget* TestWidget = nullptr;
	
	QPushButton* AddImgs = nullptr; 
	//QPushButton AddImgs; 
	
	QPushButton* Add = nullptr;
	QPushButton* Close = nullptr;

signals:
	void on_opened_state(const bool a);
//private slots:
	//void on_opened_dir(/*QUrl OpenThis*/);
	
	

private slots:
	/*void SetupView();*/
	void OpenedDir();
	void ClosedDir();
	void TestSlot();
private:
	//QDesktopServices QD;
	QFileSystemModel* FileSystem = nullptr;
	QTreeView* FileTree = nullptr;
	
	
};
//#endif // !QAPP
