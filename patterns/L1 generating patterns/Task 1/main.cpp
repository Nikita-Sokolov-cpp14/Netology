#include "SqlSelectQueryData.h"
#include "SqlSelectQueryBuilder.h"
#include "AdvancedSqlSelectQueryBuilder.h"
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

    std::cout << "Querry 1: " << std::endl;
    static_assert_(sqlSelectQueryBuilder.BuildQuery());


    SqlSelectQueryBuilder sqlSelectQueryBuilder2;

    sqlSelectQueryBuilder2.AddColumn("C1").AddColumn("C2");
    sqlSelectQueryBuilder2.AddFrom("Table");
    sqlSelectQueryBuilder2.AddWhere(wheres);

    std::cout << "Querry 2: " << std::endl;
    static_assert_(sqlSelectQueryBuilder2.BuildQuery());

    AdvancedSqlSelectQueryBuilder advancedSqlSelectQueryBuilder3;

    advancedSqlSelectQueryBuilder3.AddColumn("C1").AddColumn("C2");
    advancedSqlSelectQueryBuilder3.AddFrom("Table");
    advancedSqlSelectQueryBuilder3.AddWhere(wheres);

    std::cout << "Querry 3: " << std::endl;
    static_assert_(advancedSqlSelectQueryBuilder3.BuildQuerryWithModOperators("id", "smaller"));
    std::cout << "Querry 4: " << std::endl;
    static_assert_(advancedSqlSelectQueryBuilder3.BuildQuerryWithModOperators("id", "bigger"));

    return 0;
}