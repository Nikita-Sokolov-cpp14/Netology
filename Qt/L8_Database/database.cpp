#include "database.h"
#include <qheaderview.h>

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    dataBase = new QSqlDatabase();
    table = new QTableView();
}

DataBase::~DataBase()
{
    delete dataBase;
    delete table;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
    tableModel = new QSqlTableModel(this, *dataBase);
    queryModel = new QSqlQueryModel(this);
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);
}

/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{
    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}

/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    int typeRequest;
    if (request == "") {
        tableModel->setTable("film");
        tableModel->select();
        table->setModel(tableModel);
        typeRequest = 0;
    } else {
        queryModel->setQuery(request, *dataBase);
        table->setModel(queryModel);
        typeRequest = 1;
    }

    emit sig_SendDataFromDB(table, typeRequest);
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
