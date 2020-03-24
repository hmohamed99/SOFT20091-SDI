//#include "CustomItemListModel.h"
///**https://doc.qt.io/qt-5/model-view-programming.html#a-read-only-example-model*/
///*This is a disly bad clone/copy.paste of the guide/tutorial due to the compelxity 
//* of the constructon of this instance of QAbstractlistmodel and really needs to be improved to amroe original standard
//* Howveer at the same time as the Header of this Q_Object needs to override that of the QSLM class this may not be as much 
//* of an issue as initially expected anyway ( Asthe Methdos  ust be the same name as that of the class to allow for said class to be Overridden
//
//    QAbtractListModel Must be subclassed to be dierctly usable and the included QStringListModel class allowed for Editing, 
//    hence why this subclass of QSLM exists to allow for read-Only Access instead
//
//    Many of the Variabels and pointers are declaired as const t allow for Read-Only Functionality
//
//    This may also act as aform of modified Linked List
//*/
////* https://doc.qt.io/qt-5/model-view-programming.html#read-only-access*/
////Qt::ItemFlags CustomItemListModel::flags(const QModelIndex& index) const
////{
////    //index.Ite
////    return Qt::ItemIsEnabled, Qt::ItemIsSelectable;
////}
//
////int CustomItemListModel::rowCount(const QModelIndex& parent) const
////{
////    qDebug("Returned Rows");
////    return List.count();
////}
//
////QVariant CustomItemListModel::data(const QModelIndex& index, int role) const
////{
////    if (!index.isValid())
////    {
////        qDebug("Invalid Index Data");
////        return QVariant();
////    }
////
////    if (index.row() >= List.size())
////    //if (index.row() >= Image.size())
////        return QVariant();
////
////    if (role == Qt::DisplayRole)
////    {
////        qDebug("Role Valid");
////        return List.at(index.row());
////    }
////        //return Image.at(index.row());
////    else
////        return QVariant();
////}
//
////QVariant CustomItemListModel::headerData(int section, Qt::Orientation orientation, int role) const
////{
////    if (role != Qt::DisplayRole)
////    {
////        qDebug("Bad Role");
////        return QVariant();
////    }
////
////    if (orientation == Qt::Horizontal)
////    {
////        qDebug("Horizontal");
////        return QStringLiteral("Column %1").arg(section);
////    }
////    else
////    {
////        qDebug("Vertical");
////        return QStringLiteral("Row %1").arg(section);
////    }
////}
//
////int CustomItemListModel::columnCount(const QModelIndex& parent) const
////{
////    //return List.count(); /** only 1-Dimensional */
////    return parent.row(); /** only 1-Dimensional */
////}
//
////QModelIndex CustomItemListModel::parent(const QModelIndex& index) const
////{
////    if (!index.isValid())
////    {
////        qDebug("Invalid Parent Index");
////        return QModelIndex();
////    }
////    //node = 
////    /*if (index.parent() = _Notnull_)
////        return QModelIndex();*/
////    else
////        qDebug("Returned Index");
////        return index.parent(); //* https://doc.qt.io/qt-5/qabstractitemmodel.html#parent */
////}
//////
/////** https://stackoverflow.com/questions/27872325/qabstractitemmodel-index-and-parent-methods */
///////** https://www.hardcoded.net/articles/using_qtreeview_with_qabstractitemmodel */
/////**https://doc.qt.io/qt-5/qabstractitemmodel.html#index*/
////QModelIndex CustomItemListModel::index(int row, int column, const QModelIndex& parent) const
////{
////    //if (parent.row() && parent.column() )
////    if (!parent.isValid())
////    {
////        qDebug("Invalid Index");
////        //printf("Invalid Parent Index \n");
////        //printf("%s, %i", "Invalid Index \n", row);#
////        return QModelIndex().parent();// this->createIndex(row, column, parent)
////
////    }
////    else
////        //return List.at(index.row());
////    {
////        qDebug("Creating Index");
////        return createIndex(row, column, parent.internalPointer()); /** this OK: https://doc.qt.io/qt-5/qabstractitemmodel.html#createIndex/ */
////    }
////
////}