#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    dataBase = new QSqlDatabase();
    table = new QTableWidget();
    headers << "Название фильма" << "Описание фильма";
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
    if (request == "") {
        tableModel->setTable("film");
        tableModel->select();
        fillTable(tableModel, table);
    } else {
        queryModel->setQuery(request, *dataBase);
        fillTable(queryModel, table);
    }
    table->show();
    emit sig_SendDataFromDB(table, 0);
}

void DataBase::fillTable(const QAbstractTableModel* model, QTableWidget* tableWidget) {
    table->clear();
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(headers);

    table->setRowCount(model->rowCount());
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 1; col <= 2; ++col) {
            QString text = model->data(model->index(row, col)).toString();
            QTableWidgetItem *item = new QTableWidgetItem(text);
            tableWidget->setItem(row, col, item);
        }
    }
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
