#pragma once

#include <QAbstractItemModel>
//#include <QtGlobal>
/**https://doc.qt.io/qt-5/model-view-programming.html#a-read-only-example-model*/
/** This directly Overides QALM to allow for the ability to act as a special Read-Only Version/Alternative*/
/** Could use this as an array of Qimages for thumbnails */
/** This does not support images at the moment */
class ItemGridModel : public QAbstractItemModel
{
	Q_OBJECT
	//Q_PROPERTY(CONSTANT)
public:
	//ItemListModel(QStringList &strings, QObject *parent = nullptr) : QAbstractListModel(parent), stringList(strings) {} /** Refrences needed */
	ItemGridModel(QList<QString>& strings, QObject* parent = 0) : QAbstractItemModel(parent), List(strings) {} /** Refrences needed */
	//ItemListModel(QList<QUrl> &loc, QObject *parent = 0) : QAbstractListModel(parent), Url(loc) {} /** Refrences needed */
	//ItemListModel(QList<int> &strings, QObject *parent = 0) : QAbstractItemModel(parent), num(strings) {} /** Mya hve conversion problem from Strings to ints */
	//using QAbstractItemModel::QAbstractItemModel;
	//ItemListModel(QList<QImage> &imgs, QObject *parent = nullptr) : QAbstractListModel(parent), Image(imgs) {} /** Allows for QImages to be accepted as an argument as well */
	/** https://www.kdab.com/new-in-qt-5-11-improvements-to-the-model-view-apis-part-1/ 
	*https://www.kdab.com/new-in-qt-5-11-improvements-to-the-model-view-apis-part-2/
	*/
	Qt::ItemFlags flags(const QModelIndex& index) const override
	{
		return Qt::ItemIsEnabled, Qt::ItemIsSelectable;
	}

	int rowCount(const QModelIndex& parent) const override /** Must be const With Pointer*/
	{ 
		Q_ASSERT(checkIndex(parent));
		if (!parent.isValid())
			return 0;
		else
			return List.count();
	}
	/** https://doc.qt.io/qt-5/qmodelindex.html#data */
	QVariant data(const QModelIndex& index, int role) const override /** these methdos are set as override as they need to dierctly override that of QALM to act as a true Custom/Alternate instance if it */
	{
		Q_ASSERT(checkIndex(index, QAbstractItemModel::CheckIndexOption::IndexIsValid));
			    if (index.row() >= List.size())
			        //if (index.row() >= Image.size())
			        return QVariant();
			
			    if (role == Qt::DisplayRole)
			    {
			        qDebug("Role Valid");
			        return List.at(index.row());
			    }
			    //return Image.at(index.row());
			    else
			        return QVariant();
	}
	/** https://doc.qt.io/qt-5/qabstractitemmodel.html#headerData */
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		
			if (role != Qt::DisplayRole)
			{
				qDebug("Bad Role");
				return QVariant();
			}

			if (orientation == Qt::Horizontal)
			{
				qDebug("Horizontal");
				return QStringLiteral("Column %1").arg(section);
			}
			else
			{
				qDebug("Vertical");
				return QStringLiteral("Row %1").arg(section);
			}
		
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		Q_ASSERT(checkIndex(parent, QAbstractItemModel::CheckIndexOption::IndexIsValid));
		return parent.row();
	}

	QModelIndex parent(const QModelIndex& index) const override
	{
		Q_ASSERT(checkIndex(index));
	
		qDebug("Returned Index");
		return index.parent(); //* https://doc.qt.io/qt-5/qabstractitemmodel.html#parent */
		

	}

	QModelIndex index(int row, int column, const QModelIndex& parent) const override
	{
		Q_INVOKABLE Q_ASSERT(checkIndex(parent));
		
		if (row < 0)
		{
			qDebug("bad/Invalid Row!");
			return QModelIndex();
		}
		if (column < 0)
		{ 
			qDebug("bad/Invalid Column!");
			return QModelIndex();
		}
			
		else
		{
			qDebug("Creating Index");
			//Q_ASSERT(hasIndex()
			//return createIndex(row, column).data(role; /** this OK: https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex/ */
			//return createIndex(row, column).data.internalPointer(); /** this OK: https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex/ */
			/** https://doc.qt.io/qt-5/qobject.html#Q_INVOKABLE */
			//Q_INVOKABLE return createIndex(row, column, data//Q_INVOKABLE setData(parent, Qt::DisplayRole)); /** this OK: https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex/ */
			quintptr sub = parent.row();
			//Q_ASSERT(valid)
			Q_INVOKABLE return createIndex(row, column, sub);
		}

	}


private: /** Functions as the Argument list for this Overriding class: it is also possible to use mroe than one accepted/Specified argment with accompanying constructors*/
	QList<QString> List; /**This must match the Argument(s) provided to this class otherwise the Object will not be constructed properly */
};
