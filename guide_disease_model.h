#ifndef GUIDE_DISEASE_MODEL_H
#define GUIDE_DISEASE_MODEL_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class GuideDiseaseModel : public QSqlRelationalTableModel
{
public:
    GuideDiseaseModel();
    GuideDiseaseModel(QObject *parent,QSqlDatabase db);
};

#endif // GUIDE_DISEASE_MODEL_H
