#ifndef PERSON_DISEASE_H
#define PERSON_DISEASE_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class PersonDiseaseModel : public QSqlRelationalTableModel
{
public:
    PersonDiseaseModel();
    PersonDiseaseModel(QObject *parent,QSqlDatabase db);
};

#endif // PERSON_DISEASE_H
