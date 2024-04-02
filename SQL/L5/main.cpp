#include <iostream>
#include "pqxx/pqxx"

#include <windows.h>
#pragma execution_character_set("utf-8")

class Clt {
private:
    std::unique_ptr<pqxx::connection> cn;
public:
    Clt() {
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
            "email VARCHAR(100) NOT NULL"
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

    void addPhone() {
        pqxx::work addPh(*cn);
        std::string phone, clientId;

        std::cout << "������� id �������, �������� �������� �������" << std::endl;
        std::cin >> clientId;
        std::cout << "������� ����� ��������" << std::endl;
        std::cin >> phone;
        addPh.exec(
            "INSERT INTO phones(client_id, number) VALUES (" + addPh.esc(clientId) + ", " + addPh.esc(phone) + ");"
        );
        addPh.commit();
    }

    void addNewClient() {
        pqxx::work addCl(*cn);
        std::string firstName, lastName, email;

        std::cout << "������� ��� �������" << std::endl;
        std::cin >> firstName;
        std::cout << "������� �������" << std::endl;
        std::cin >> lastName;
        std::cout << "������� email" << std::endl;
        std::cin >> email;

        addCl.exec(
            "INSERT INTO users(first_name, last_name, email) VALUES('" + addCl.esc(firstName) +
                "', '" + addCl.esc(lastName) + 
                "', '" + addCl.esc(email) + "');"
        );
        addCl.commit();
    }

    void printClients() {
        pqxx::work prt(*cn);
        auto coll = prt.query<int, std::string, std::string, std::string>("SELECT * FROM users");

        std::cout << "id\t���\t�������\temail" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
            std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
        }
    }

    void printPhones() {
        pqxx::work prt(*cn);
        auto coll = prt.query<int, int, std::string>("SELECT * FROM phones");

        std::cout << "ID ������ ��������\t" << "ID �������\t" << "����� ��������" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t\t\t" << std::get<1>(elem) << "\t\t\t" << std::get<2>(elem) << std::endl;
        }
    }

    void changeDataClient() {
        pqxx::work chanCl(*cn);
        std::string firstName, lastName, email;
        std::string id;

        std::cout << "������� ID �������, �������� ������ ��������:" << std::endl;
        std::cin >> id;

        std::cout << "������� ��� �������" << std::endl;
        std::cin >> firstName;
        std::cout << "������� �������" << std::endl;
        std::cin >> lastName;
        std::cout << "������� email" << std::endl;
        std::cin >> email;

        chanCl.exec(
            "UPDATE users "
            "SET first_name = '" + chanCl.esc(firstName) + "', " +
            "last_name = '" + chanCl.esc(lastName) + "', " +
            "email = '" + chanCl.esc(email) + "'" +
            "WHERE id = " + chanCl.esc(id) + ";"

        );
        chanCl.commit();
    }

    void deletePhone() {
        pqxx::work delPh(*cn);
        std::string id;

        std::cout << "������� ID ������ ��������, ������� ������ �������:" << std::endl;
        std::cin >> id;

        delPh.exec(
            "DELETE FROM phones "
            "WHERE phone_id = " + delPh.esc(id) + ";"
        );
        delPh.commit();
    }

    void deleteClient() {
        pqxx::work delPh(*cn);
        std::string id;

        std::cout << "������� ID �������, �������� ������ �������:" << std::endl;
        std::cin >> id;

        delPh.exec(
            "DELETE FROM phones "
            "WHERE client_id = " + delPh.esc(id) + ";"
        );

        delPh.exec(
            "DELETE FROM users "
            "WHERE id = " + delPh.esc(id) + ";"
        );

        delPh.commit();
    }

    void findClientFirstName() {

        std::string firstName;

        std::cout << "������� ��� �������, �������� ������ �����:" << std::endl;
        std::cin >> firstName;

        pqxx::work fndName(*cn);
        auto coll = fndName.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE first_name = '" + fndName.esc(firstName) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "������ � ������ " << firstName << " �� ������" << std::endl;
        }
        else {
            std::cout << "������ ������" << std::endl;
        }

        std::cout << "id\t���\t�������\temail" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
            std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
        }
    }

    void findClientLastName() {
        std::string lastName;

        std::cout << "������� ������� �������, �������� ������ �����:" << std::endl;
        std::cin >> lastName;

        pqxx::work fndlastName(*cn);
        auto coll = fndlastName.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE last_name = '" + fndlastName.esc(lastName) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "������ � �������� " << lastName << " �� ������" << std::endl;
        }
        else {
            std::cout << "������ ������" << std::endl;
        }

        std::cout << "id\t���\t�������\temail" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
            std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
        }
    }

    void findClientEmail() {
        std::string email;

        std::cout << "������� email �������, �������� ������ �����:" << std::endl;
        std::cin >> email;

        pqxx::work fndeml(*cn);
        auto coll = fndeml.query<int, std::string, std::string, std::string>(
            "SELECT * FROM users "
            "WHERE email = '" + fndeml.esc(email) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "������ � email " << email << " �� ������" << std::endl;
        }
        else {
            std::cout << "������ ������" << std::endl;
        }

        std::cout << "id\t���\t�������\temail" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t";
            std::cout << std::get<2>(elem) << "\t" << std::get<3>(elem) << std::endl;
        }
    }

    void findClientPhone() {
        std::string phone;

        std::cout << "������� ����� �������� �������, �������� ������ �����:" << std::endl;
        std::cin >> phone;

        pqxx::work fndPh(*cn);
        auto coll = fndPh.query<std::string, std::string, std::string>(
            "SELECT DISTINCT u.first_name, u.last_name, p.number FROM users u "
            "JOIN phones p ON p.client_id = u.id "
            "WHERE p.number = '" + fndPh.esc(phone) + "';"
        );

        if (coll.begin() == coll.end()) {
            std::cout << "������ � ��������� " << phone << " �� ������" << std::endl;
        }
        else {
            std::cout << "������ ������" << std::endl;
        }

        std::cout << "���\t" << "�������\t" << "����� ��������" << std::endl;
        for (const auto& elem : coll) {
            std::cout << std::get<0>(elem) << "\t" << std::get<1>(elem) << "\t" << std::get<2>(elem) << std::endl;
        }
    }

    void find() {
        std::string what;

        std::cout << "�������� �� ������ ��������� ������ �������: first name, last name, email ��� phone" << std::endl;
        std::cin >> what;

        if (what == "first name") { findClientFirstName(); }
        else if (what == "last name") { findClientLastName(); }
        else if (what == "email") { findClientEmail(); }
        else if (what == "phone") { findClientPhone(); }
    }
};

int main () {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    try {
        Clt client_database;

        client_database.dropTables();
        client_database.createTableUsers();
        client_database.createTablePhones();

        client_database.addNewClient();
        client_database.printClients();
        client_database.addPhone();

        client_database.find();

        client_database.addPhone();
        client_database.addPhone();
        client_database.printPhones();

        client_database.changeDataClient();
        client_database.printClients();
        client_database.printPhones();

        client_database.deletePhone();
        client_database.printPhones();

        client_database.deleteClient();
        client_database.printClients();
        client_database.printPhones();


    }
    catch (std::exception& err) {
        std::cout << "������! ";
        std::cout << err.what();
    }


    return 0;
}