#include "SqlSelectQuery.h"
#include "SqlSelectQueryBuilder.h"
#include <iostream>

void static_assert_(const std::string& querry) {
    std::cout << "Querry: " << querry << std::endl;
}

int main() {
    SqlSelectQueryBuilder sqlSelectQueryBuilder;

    std::vector<std::string> columns;
    columns.push_back("Col1");
    columns.push_back("Col2");

    std::map<std::string, std::string> wheres;
    wheres["id"] = "12";
    wheres["Name"] = "Sanya";
    
    sqlSelectQueryBuilder.AddColumn(columns);
    sqlSelectQueryBuilder.AddFrom("Table");
    sqlSelectQueryBuilder.AddWhere(wheres);

    static_assert_(sqlSelectQueryBuilder.BuildQuery());
    return 0;
}