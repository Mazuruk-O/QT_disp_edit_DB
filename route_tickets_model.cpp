#include "route_tickets_model.h"

RouteTicketsModel::RouteTicketsModel()
{

}

RouteTicketsModel::RouteTicketsModel(QObject *parent, QSqlDatabase db)
{
    setTable("route_tickets");

    this->setRelation(1,QSqlRelation("route_list","route_list_id","start_sity_id"));

    this->setRelation(2,QSqlRelation("route_list","route_list_id","end_sity_id"));

    this->setRelation(3,QSqlRelation("route_list","route_list_id","transport_name_id"));

    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");

    setHeaderData( 1, Qt::Horizontal,"     Start sity     ");

    setHeaderData( 2, Qt::Horizontal,"     End sity     "  );

    setHeaderData( 3, Qt::Horizontal,"     Transport type     ");

    setHeaderData( 4, Qt::Horizontal,"     Price     ");

    setHeaderData( 5, Qt::Horizontal,"     Place     ");
}
