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
#include <qsplitter.h>

class QAPP : public QSplitter /*QMainWindow*//*, public QObject*///, public TreeView
{
	Q_OBJECT
public:
	//explicit QAPP(parent = 0);
	explicit QAPP(QWidget* /*= QW*/  /*QSplitter**/ /*QW*/ parent = 0);
	void Setlocation();
	//void OpeningDir();
	void SetupView(); //* Crude member function to allow the File Dialog to recieve signals and access slot from the mian QAPP class *//

	bool isbusy = false; //* test to allow for the ability to prevent process termination : could be used as a experimental feature allow other signals to hook into (e.g. to prevent data corruption during operations e.g.)*//
	
	QUrl Url;
	QFile FileHandler;
	//QString Path2 = QDir::relativeFilePath(QDir::currentPath() + "/Imgs");
	const QString Path2 = QDir::currentPath() +"/Imgs"; //* can be set as const as may not need to be changed *//
	QWidget* TestWidget = nullptr;
	//QList<QDir> InputImages;
	QList<QString> InputImages;
	QList<QImage> InputThumb;
	QFile/*<QImage>*/ Imgs;
	QPushButton* AddImgs = nullptr; 
	QPushButton* Exit = nullptr;
	//QDesktopServices QD;// = nullptr;

	QPushButton* Add = nullptr;
	QPushButton* Close = nullptr;
	//QPoint<QMouseEvent> QM;
	//QPoint *QM = nullptr;
	QPoint QM;
signals:
	void on_opened_state(const bool a);
//private slots:
	//void on_opened_dir(/*QUrl OpenThis*/);
	
	

private slots:
	/*void SetupView();*/
	void OpenedDir();
	void ClosedDir();
	void Filehandler(QModelIndex Index/*QMouseEvent::*//*QFileSystemModel::fileInfo*/);
	
void CloseMain();
private:
	//QDesktopServices *QD = nullptr;
	//QDesktopServices QD;// = nullptr;
	QFileSystemModel* FileSystem = nullptr;
	QTreeView* FileTree = nullptr;
	//QTreeView FileTree;// = nullptr;
	//QWidget* QW ;
	QAbstractItemView* FileView = nullptr;

	
};
//#endif // !QAPP
