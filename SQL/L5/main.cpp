#include <iostream>
#include "pqxx/pqxx"

#include <windows.h>
#include <vector>
#pragma execution_character_set("utf-8")

struct Client {
    std::string firstName;
    std::string lastName;
    std::string email;
    std::vector<std::string> phones;
};

class Client_database {
private:
    std::unique_ptr<pqxx::connection> cn;
public:
    Client_database() {
        cn = std::make_unique<pqxx::connection>(
            "host=localhost "
            "port=5432 "
            "dbname=postgres "
            "user=postgres "
            "password=8880648"
        );
    }

    void dropTables() {
        pqxx::work table_phones(*cn);

        table_phones.exec(
            "DROP TABLE phones;"
            "DROP TABLE users;"
        );
        table_phones.commit();
    }

    void createTableUsers() {
        pqxx::work table_users(*cn);

        table_users.exec(
            "CREATE TABLE IF NOT EXISTS users ("
            "id SERIAL PRIMARY KEY,"
            "first_name VARCHAR(100) NOT NULL,"
            "last_name VARCHAR(100) NOT NULL,"
            "email VARCHAR(100) UNIQUE NOT NULL"
            ");"
        );
        table_users.commit();
    }

    void createTablePhones() {
        pqxx::work table_phones(*cn);

        table_phones.exec(
            "CREATE TABLE IF NOT EXISTS phones ("
            "phone_id SERIAL NOT NULL,"
            "client_id INT NOT NULL REFERENCES users(id),"
            "number text UNIQUE"
            ");"
        );
        table_phones.commit();
    }

    void addPhone(int clientId, const std::string& phone) {
        pqxx::work addPh(*cn);

        addPh.exec(
            "INSERT INTO phones(client_id, number) VALUES (" +
            addPh.esc(std::to_string(clientId)) + ", " + 
            addPh.esc(phone) + ");"
        );
        addPh.commit();
    }

    int addNewClient(const std::string& firstName,const std::string& lastName,const std::string& email) {
        pqxx::work addCl(*cn);

        addCl.exec(
            "INSERT INTO users(first_name, last_name, email) VALUES('" + addCl.esc(firstName) +
                "', '" + addCl.esc(lastName) + 
                "', '" + addCl.esc(email) + "');"
        );
        addCl.commit();

        pqxx::work getId(*cn);
        std::string value = getId.query_value<std::string>(
            "SELECT MAX(id) FROM users "
        );

        return std::stoi(value);
    }

    void printClients() {
        pqxx::work prt(*cn);
        auto coll = prt.query<int, std::string, std::string, std::string>("SELECT * FROM users");

        std::cout << "сисок клиентов:" << std::endl;
        std::cout << "id\tИмя\tФамилия\temail" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
            std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
        }
    }

    void printPhones() {
        pqxx::work prt(*cn);
        auto coll = prt.query<int, int, std::string>("SELECT * FROM phones");

        std::cout << "Список номеров" << std::endl;
        std::cout << "ID номера телефона\t" << "ID клиента\t" << "номер телефона" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t\t\t" << std::get<1>(elem) << "\t\t\t" << std::get<2>(elem) << std::endl;
        }
    }

    void changeDataClient(
        int id, const std::string& firstName, const std::string& lastName, const std::string& email
    ) {
        pqxx::work chanCl(*cn);

        chanCl.exec(
            "UPDATE users "
            "SET first_name = '" + chanCl.esc(firstName) + "', " +
            "last_name = '" + chanCl.esc(lastName) + "', " +
            "email = '" + chanCl.esc(email) + "'" +
            "WHERE id = " + chanCl.esc(std::to_string(id)) + ";"

        );
        chanCl.commit();
    }

    void deletePhone(std::string phone) {
        pqxx::work delPh(*cn);

        delPh.exec(
            "DELETE FROM phones "
            "WHERE number = '" + delPh.esc(phone) + "';"
        );
        delPh.commit();
    }

    void deleteClient(int id) {
        pqxx::work delPh(*cn);

        delPh.exec(
            "DELETE FROM phones "
            "WHERE client_id = " + delPh.esc(std::to_string(id)) + ";"
        );

        delPh.exec(
            "DELETE FROM users "
            "WHERE id = " + delPh.esc(std::to_string(id)) + ";"
        );

        delPh.commit();
    }

    void findClientFirstName(const std::string& firstName) {
        pqxx::work fndName(*cn);
        auto coll = fndName.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE first_name = '" + fndName.esc(firstName) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "Клиент с именем " << firstName << " не найден" << std::endl;
        }
        else {
            std::cout << "Клиент найден" << std::endl;
            std::cout << "id\tИмя\tФамилия\temail" << std::endl;
            for (const auto& elem : coll) {
                std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
                std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
            }
        }
    }

    void findClientLastName(std::string lastName) {

        pqxx::work fndlastName(*cn);
        auto coll = fndlastName.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE last_name = '" + fndlastName.esc(lastName) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "Клиент с фамилией " << lastName << " не найден" << std::endl;
        }
        else {
            std::cout << "Клиент найден" << std::endl;
            std::cout << "id\tИмя\tФамилия\temail" << std::endl;
            for (const auto& elem : coll) {
                std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
                std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
            }
        }   
    }

    void findClientEmail(std::string email) {

        pqxx::work fndeml(*cn);
        auto coll = fndeml.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE email = '" + fndeml.esc(email) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "Клиент с email " << email << " не найден" << std::endl;
        }
        else {
            std::cout << "Клиент найден" << std::endl;
            std::cout << "id\tИмя\tФамилия\temail" << std::endl;
            for (const auto& elem : coll) {
                std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
                std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
            }
        }
    }

    void findClientPhone(std::string phone) {

        pqxx::work fndPh(*cn);
        auto coll = fndPh.query<std::string, std::string, std::string>(
            "SELECT DISTINCT u.first_name, u.last_name, p.number FROM users u "
            "JOIN phones p ON p.client_id = u.id "
            "WHERE p.number = '" + fndPh.esc(phone) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "Клиент с телефоном " << phone << " не найден" << std::endl;
        }
        else {
            std::cout << "Клиент найден" << std::endl;
            std::cout << "Имя\t" << "Фамилия\t" << "номер телефона" << std::endl;
            for (const auto& elem : coll) {
                std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t" << std::get<2>(elem) << std::endl;
            }
        }     
    }
};

int main () {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Client c1;
    c1.firstName = "Иван";
    c1.lastName = "Иванов";
    c1.email = "ivan_007@mail.ru";

    Client c2;
    std::cout << "Введите имя клиента" << std::endl;
    std::cin >> c2.firstName;
    std::cout << "Введите фамилию" << std::endl;
    std::cin >> c2.lastName;
    std::cout << "Введите email" << std::endl;
    std::cin >> c2.email;
    
    std::map<int, Client> c;

    int clientId = 0;

    try {
        Client_database client_database;   

        client_database.dropTables(); //чтобы можно было несколько раз запускать эту программу и заногоо создавать таблицы
        client_database.createTableUsers();
        client_database.createTablePhones();

        //Добавление нового клиента
        clientId = client_database.addNewClient(c1.firstName, c1.lastName, c1.email);
        c[clientId] = c1;

        clientId = client_database.addNewClient(c2.firstName, c2.lastName, c2.email);
        c[clientId] = c2;

        client_database.printClients();
        client_database.printPhones();

        //добавление номера телефона для сущемтвующего клиента
        std::string phone;
        std::cout << "Введите id клиента, которому добавить телефон:" << std::endl;
        std::cin >> clientId;
        std::cout << "Введите номер телефона:" << std::endl;
        std::cin >> phone;
        c[clientId].phones.push_back(phone);

        client_database.addPhone(clientId, *(c[clientId].phones.end() - 1));
        client_database.printPhones();

        //поиск клиента по параметру
        std::string what;

        std::cout << "выберите по какому параметру искать клиента: first_name, last_name, email или phone" << std::endl;
        std::cin >> what;
        std::string value;

        if (what == "first_name") {
            std::cout << "Ввудите искомое имя:";
            std::cin >> value;
            client_database.findClientFirstName(value);
        }
        else if (what == "last_name") {
            std::cout << "Ввудите искомую фамилию:";
            std::cin >> value;
            client_database.findClientLastName(value);
        }
        else if (what == "email") {
            std::cout << "Ввудите искомый email:";
            std::cin >> value;
            client_database.findClientEmail(value);
        }
        else if (what == "phone") {
            std::cout << "Ввудите искомый телефон:";
            std::cin >> value;
            client_database.findClientPhone(value);
        }
        
        //просто добавление
        c[1].phones.push_back("12345678");
        c[2].phones.push_back("80077000000");

        client_database.addPhone(1, *(c[1].phones.end() - 1));
        client_database.addPhone(2, *(c[2].phones.end() - 1));
        client_database.printPhones();

        //изменение данных о клиенте
        std::cout << "Введите ID клиента, которого хотите изменить:" << std::endl;
        std::cin >> clientId;

        std::cout << "Введите имя клиента" << std::endl;
        std::cin >> c[clientId].firstName;
        std::cout << "Введите фамилию" << std::endl;
        std::cin >> c[clientId].lastName;
        std::cout << "Введите email" << std::endl;
        std::cin >> c[clientId].email;

        client_database.changeDataClient(
            clientId, c[clientId].firstName, c[clientId].lastName, c[clientId].email
        );
        client_database.printClients();

        //удаление номера
        client_database.printPhones();
        std::cout << "Введите ID клиента и номер телефона, который хотите удалить:" << std::endl;
        std::cin >> clientId;
        std::cin >> phone;
        client_database.deletePhone(phone);
        client_database.printPhones();
        c[clientId].phones.erase(std::find(c[clientId].phones.begin(), c[clientId].phones.end(), phone));

        //удаление клиента
        std::cout << "Введите ID клиента, которого хотите удалить:" << std::endl;
        std::cin >> clientId;
        client_database.deleteClient(clientId);
        client_database.printClients();
        client_database.printPhones();
        c.erase(clientId);

    }
    catch (std::exception& err) {
        std::cout << "Ошибка! ";
        std::cout << err.what();
    }
    return 0;
}