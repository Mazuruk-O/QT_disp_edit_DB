#include "person_disease_model.h"

PersonDiseaseModel::PersonDiseaseModel()
{

}

PersonDiseaseModel::PersonDiseaseModel(QObject *parent, QSqlDatabase db)
{
    setTable("person_disease");

    this->setRelation(1,QSqlRelation("guide_disease","id_guide_disease","desease"));

    setEditStrategy(QSqlTableModel::OnFieldChange);

    setHeaderData( 0, Qt::Horizontal,"Id");

    setHeaderData( 1, Qt::Horizontal,"     Name disease     ");

    setHeaderData( 2, Qt::Horizontal,"     Date start     "  );

    setHeaderData( 3, Qt::Horizontal,"     Date end     ");

    setHeaderData( 4, Qt::Horizontal,"     Person Name     ");
}
