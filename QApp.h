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
	void Setlocation();
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
