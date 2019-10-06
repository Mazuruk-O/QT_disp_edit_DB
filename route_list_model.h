#ifndef ROUTE_LIST_MODEL_H
#define ROUTE_LIST_MODEL_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class RouteListModel : public QSqlRelationalTableModel
{
public:
    RouteListModel();
    RouteListModel(QObject *parent,QSqlDatabase db);
};


#endif // ROUTE_LIST_MODEL_H
