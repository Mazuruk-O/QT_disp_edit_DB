#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRelation>
#include "guide_disease_model.h"
#include "person_disease_model.h"
#include "route_list_model.h"
#include "route_tickets_model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString userLogin;
    QString userPassword;
    QString userHost;
    int     localPortDB;
    int     remotePort;
    bool    DBConnectionState;
    QString sshTunelConfigForDB;
    QProcess dbTunel;
    /// 31
    GuideDiseaseModel* guideDiseaseModel;
    /// 32
    PersonDiseaseModel* personDiseaseModel;
    /// 33
    RouteListModel* routeListModel;
    /// 34
    RouteTicketsModel* routeTicketsModel;
};
#endif // MAINWINDOW_H
