#pragma once

#include <QAbstractItemModel>
/** https://doc.qt.io/qt-5/model-view-programming.html#a-read-only-example-model*/
/** This directly Overides QALM to allow for the ability to act as a special Read-Only Version/Alternative*/
/** Could use this as an array of Qimages for thumbnails */
/** This does not support images at the moment */
class CustomItemListModel : public QAbstractListModel/*QAbstractItemModel*/ 
{
	Q_OBJECT
	//Q_OVERRIDE
	//Q_PROPERTY(CONSTANT)
public:
	//ItemListModel(QStringList &strings, QObject *parent = nullptr) : QAbstractListModel(parent), stringList(strings) {} /** Refrences needed */
	CustomItemListModel(QList<QString> &strings, QObject *parent = 0) : QAbstractListModel(parent), List(strings) {} /** Refrences needed */
	//ItemListModel(QList<QUrl> &loc, QObject *parent = 0) : QAbstractListModel(parent), Url(loc) {} /** Refrences needed */
	//ItemListModel(QList<int> &strings, QObject *parent = 0) : QAbstractItemModel(parent), num(strings) {} /** Mya hve conversion problem from Strings to ints */
	
	//ItemListModel(QList<QImage> &imgs, QObject *parent = nullptr) : QAbstractListModel(parent), Image(imgs) {} /** Allows for QImages to be accepted as an argument as well */
	/*void*/ Qt::ItemFlags flags(const QModelIndex& index) const override
	{
		return Qt::FontRole, Qt::ItemIsDragEnabled, Qt::ItemIsEnabled; // , /*Qt::IBeamCursor;*/// , Qt::FontRole = fsize;
		//set Qt::ItemIsDragEnabled;
	}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		qDebug("Returned Rows");
		//qDebug(parent.row());
		return List.count();
	}
	/*{
		Q_ASSERT(checkIndex(parent));

	}*/
	/** Must be const With Pointer*/
	/** https://doc.qt.io/qt-5/qmodelindex.html#data */
	/*QList<QVariant>*/ 
	QVariant data(const QModelIndex &index, int role) const override /** these methdos are set as override as they need to dierctly override that of QALM to act as a true Custom/Alternate instance if it */
	{ 
		//if (!index.isValid())
		Q_ASSERT(index.isValid()); /** Special macro to abort the Overriden method if Index Invalid: https://www.kdab.com/new-in-qt-5-11-improvements-to-the-model-view-apis-part-1/*/
		/*{
			qDebug("Invalid Index Data");
			return QVariant();
		}*/
		//Q_ASSERT(Qt::DisplayRole);
				
		if (index.row() >= List.size())
			//if (index.row() >= Image.size())
		//Q_ASSERT(index.isValid());
			//return QVarient;
			return this;

		if (role == Qt::DisplayRole) /** can be used to change/handle/manipulate the retunred Filenames/Represented Obejcts in the ViewModel */
		{
			qDebug("Role Valid");
			//return List.at(index.row());
			return index.row(); //* Could replace this with FileName ot even another object such as a thumbnail */
		}

		//return Image.at(index.row());
		else
			qDebug("Non-matching Role");
			return QVariant(); 
	}
	/** https://doc.qt.io/qt-5/qabstractitemmodel.html#headerData */
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		{
			Q_ASSERT(role != Qt::DisplayRole);
			Q_ASSERT(Qt::Horizontal);
			//if (role != Qt::DisplayRole)
			/*{
				qDebug("Bad Role");
				return QVariant();
			}*/

			/*if (orientation == Qt::Horizontal)
			{*/
				qDebug("Horizontal");
				return QStringLiteral("Column %1").arg(section);
			//}
//			else
			Q_ASSERT(Qt::Vertical);
			//{
				qDebug("Vertical");
				return QStringLiteral("Row %1").arg(section);
			//}
		}
	}

	//int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	//QModelIndex parent(const QModelIndex& index) const override;

	//QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;


private: /** Functions as the Argument list for this Overriding class: it is also possible to use mroe than one accepted/Specified argment with accompanying constructors*/
	//QStringList stringList;
	QList<QString> List; /**This must match the Argument(s) provided to this class otherwise the Object will not be constructed properly */
	//QList<QUrl> Url; /**This must match the Argument(s) provided to this class otherwise the Object will not be constructed properly */
	//QList<int> num; /**This must match the Argument(s) provided to this class otherwise the Object will not be constructed properly */
	//QList<QImage> Image; /**This must match the Argument(s) provided to this class otherwise the Object will not be constructed properly */
	int *fsize = nullptr;// = 10;
};
