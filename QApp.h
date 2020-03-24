#pragma once
//#ifndef QAPP
//#define QAPP
#include <qwidget.h>
#include <QPushButton>
#include <QMainWindow>
#include <qurl.h>
#include <QSplitter>
#include <QListView.h>
#include <qfilesystemmodel.h>
#include <qsplitter.h>
#include <QStandardItemModel>
#include <QListView>

#include "CustomItemListModel.h"

class QAPP : public QSplitter /*QMainWindow*//*, public QObject*///, public TreeView
{
	Q_OBJECT
public:
	//explicit QAPP(parent = 0);
	explicit QAPP(QWidget* /*= QW*/  /*QSplitter**/ /*QW*/ parent = 0);
	void Setlocation();
	//void OpeningDir();
	void SetupView(); //* Crude member function to allow the File Dialog to recieve signals and access slot from the mian QAPP class *//

	//void DebugMode();

	bool isbusy = false; //* test to allow for the ability to prevent process termination : could be used as a experimental feature allow other signals to hook into (e.g. to prevent data corruption during operations e.g.)*//
	
	QUrl Url;
	QFile FileHandler;
	//QString Path2 = QDir::relativeFilePath(QDir::currentPath() + "/Imgs");
	const QString Path2 = QDir::currentPath() +"/Imgs/"; //* can be set as const as may not need to be changed *//
	QWidget* TestWidget = nullptr;
	//QList<QDir> InputImages;
	QList<QString> InputImages/*(Qt::ItemIsEditable)*/;
	//QStringList InputImages;
	//QStandardItemModel InputImages;
	//QList<QStandardItem> InputImages;
	//QAbstractListModel *InputImages = nullptr;
	//QList<QModelIndex> InputImages; /**Lazy linkedList **/
	//QAbstractListModel> InputImages; /**Lazy linkedList **/
	//QModelIndexList InputImages; /*https://doc.qt.io/qt-5/qmodelindex.html#QModelIndexList-typedef
	QList<QImage> InputThumb;
	QFile/*<QImage>*/ Imgs;
	QPushButton* AddImgs = nullptr; 
	QPushButton* Exit = nullptr;
	//QDesktopServices QD;// = nullptr;
	
	QPushButton* Add = nullptr;
	QPushButton* Close = nullptr;
	QPushButton* OpenRoot = nullptr;

	//QPoint<QMouseEvent> QM;
	//QPoint *QM = nullptr;
	QPoint QM;
	QAbstractItemModel* A = nullptr;
	//ItemGridModel *A = nullptr;
	//CustomCustomItemListModel* A = nullptr;
	//CustomCustomItemListModel A;
	//QStandardItemModel QIM;
signals:
	void on_opened_state(const bool a);
//private slots:
	//void on_opened_dir(/*QUrl OpenThis*/);
	
	

private slots:
	/*void SetupView();*/
	void OpenedDir();
	void ClosedDir();
	void Filehandler(QModelIndex Index/*QMouseEvent::*//*QFileSystemModel::fileInfo*/);
	//void OpenedRoot();

void CloseMain();
private:
	//QDesktopServices *QD = nullptr;
	//QDesktopServices QD;// = nullptr;
	QFileSystemModel* FileSystem = nullptr;
	
	//QListView* FileTree = nullptr;
	QListView* FileTree = nullptr;
	//QListView FileTree;// = nullptr;
	//QWidget* QW ;
	QAbstractItemView* FileView = nullptr;

	
};
//#endif // !QAPP
