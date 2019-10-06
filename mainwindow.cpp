#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "windows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userLogin="root";
    userPassword="1234";
    userHost="localhost";
    localPortDB=3306;
    remotePort=2233;
    sshTunelConfigForDB ="ssh\\plink -P %1 -L %2:localhost:3306 %3@%4 -N -pw %5 < ssh\\config.ini";

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("QDataBase_Ind1");
    db.setHostName("localhost");
    db.setUserName(userLogin);
    db.setPassword(userPassword);
    db.setPort(localPortDB);
}

MainWindow::~MainWindow()
{
    db.close();
    dbTunel.close();

    delete guideDiseaseModel;
    delete personDiseaseModel;
    delete routeListModel;
    delete routeTicketsModel;
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    QString msgDB;

    msgDB=sshTunelConfigForDB.arg(remotePort).arg(localPortDB).arg(userLogin).arg(userHost).arg(userPassword);

    qDebug()<<msgDB;

    dbTunel.start(msgDB);

    int i;

    for(i=0;i<30;i++)
      {
        Sleep(250);
        DBConnectionState = db.open();
        if(true==DBConnectionState)
            break;
      }

    if(true==DBConnectionState)
       {
         ui->statusConnectLabel->setText("Status: connect successfully!");
         ///table disease
         guideDiseaseModel = new GuideDiseaseModel(this,db);
         ui->diseaseTableView->setModel(guideDiseaseModel);
         ui->diseaseTableView->resizeColumnsToContents();

         ///table person disease
         personDiseaseModel = new PersonDiseaseModel(this,db);
         ui->personDiseaseTableView->setModel(personDiseaseModel);
         ui->personDiseaseTableView->resizeColumnsToContents();

         ///table route list
         routeListModel = new RouteListModel(this,db);
         ui->routeListTableView->setModel(routeListModel);
         ui->routeListTableView->resizeColumnsToContents();

         ///table route tickets
         routeTicketsModel = new RouteTicketsModel(this,db);
         ui->routeTicketTableView->setModel(routeTicketsModel);
         ui->routeTicketTableView->resizeColumnsToContents();

         routeTicketsModel->select();
         routeListModel->select();
         guideDiseaseModel->select();
         personDiseaseModel->select();

       }
    else
    {
      ui->lineEditForOutError->setText("Not connect. \nDB Error: " + db.lastError().text());
      ui->statusConnectLabel->setText("Status: not connect. Check Error page.")
      qDebug()<<"\nDB Error: "<<db.lastError().text();
    }
}

void MainWindow::on_disconnectButton_clicked()
{
    db.close();
    dbTunel.close();

    delete guideDiseaseModel;
    delete personDiseaseModel;
    delete routeListModel;
    delete routeTicketsModel;

    ui->lineEditForOutError->setText("Not connect.");
}
