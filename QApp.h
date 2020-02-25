#pragma once
//#ifndef QAPP
//#define QAPP
#include <qwidget.h>
#include <QPushButton>
#include <QMainWindow>
#include <qurl.h>
class QAPP : public QMainWindow
{
	Q_OBJECT
public:
	explicit QAPP(/*QDesktopServices QD, */QWidget* parent = 0); //PointerBlackMagic
	//QDesktopServices QD;
	//QWidget* QW =nullptr;
	//QPushButton* AddImgs = nullptr; /**PointerBlackMagic Must be pounet othrwise connect isn;t accesible for some reasion**/
	//QUrl OpenThis;// = "file:///C:/Documents and Settings/All Users/";
	/*int x = 100;
	int y = 100;*/void Setlocation();
	QUrl Url;
signals:
	void OpeningDir();

	private
slots:
	void on_opened_dir(/*QUrl OpenThis*/);

private:
	
private:
	QPushButton* AddImgs = nullptr; //PointerBlackMagic
	//QDesktopServices QD;


};



//#endif // !QAPP
