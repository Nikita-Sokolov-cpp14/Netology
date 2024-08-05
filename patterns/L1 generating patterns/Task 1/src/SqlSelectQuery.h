#pragma once
#include <string>
#include <vector>
#include <map>

class SqlSelectQuery {
public:
    std::vector<std::string> columns;
    std::string tableName;
    std::map<std::string, std::string> where;

    std::string makeQuerry();
private:
    std::string querry_;
};