#include "guide_disease_model.h"

GuideDiseaseModel::GuideDiseaseModel()
{

}

GuideDiseaseModel::GuideDiseaseModel(QObject *parent, QSqlDatabase db)
{
    setTable("guide_disease");

    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");

    setHeaderData( 1, Qt::Horizontal,"     Name     ");
}
