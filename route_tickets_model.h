#ifndef ROUTE_TICKETS_MODEL_H
#define ROUTE_TICKETS_MODEL_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class RouteTicketsModel : public QSqlRelationalTableModel
{
public:
    RouteTicketsModel();
    RouteTicketsModel(QObject *parent,QSqlDatabase db);
};

#endif // ROUTE_TICKETS_MODEL_H
