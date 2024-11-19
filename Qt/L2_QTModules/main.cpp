#include <QCoreApplication>
#include <iostream>
#include <QSqlQuery>
#include <QTcpServer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpServer tcpserver;
    QSqlQuery querry;

    std::cout << "qyerry is null: " << querry.isNull(0) << std::endl;
    std::cout << "tcpserver: " << tcpserver.serverError() << std::endl;

    querry.finish();
    tcpserver.close();
    return a.exec();
}
