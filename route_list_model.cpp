#include "route_list_model.h"

RouteListModel::RouteListModel()
{

}

RouteListModel::RouteListModel(QObject *parent, QSqlDatabase db)
{
    setTable("route_list");

    this->setRelation(1,QSqlRelation("city","start_sity_id","name_sity"));

    this->setRelation(2,QSqlRelation("city","end_sity_id","name_sity"));

    this->setRelation(3,QSqlRelation("transport_type","transport_type_id","transport_name"));

    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");

    setHeaderData( 1, Qt::Horizontal,"     Start sity     ");

    setHeaderData( 2, Qt::Horizontal,"     End sity     "  );

    setHeaderData( 3, Qt::Horizontal,"     Transport type     ");
}
