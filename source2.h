#ifndef SOURCE_2
#define SOURCE_2
#endif // !SOURCE_2

#include <QObject>
#include <QDebug>
//#include <qwidget.h>
#include <qapplication.h>

class Base : public QApplication/*public QApplication*///, public QPushButton
{
	Q_OBJECT
public:
	explicit Base(QWidget* parent = NULL); //**/

	//QPushButton button;

	//void SendSignal(QUrl aa);
															
signals:
	//void ClickListener(/*QPushButton QB*/);

public slots:
	//void SlotButton(/*QPushButton QB*/);

	//void SlotMessage(QUrl aa);

};
//#endif //SOURCE_2