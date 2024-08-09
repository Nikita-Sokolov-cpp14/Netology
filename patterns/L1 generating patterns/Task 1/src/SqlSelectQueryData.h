#pragma once
#include <string>
#include <vector>
#include <map>

struct SqlSelectQueryData {
    std::vector<std::string> columns;
    std::string tableName;
    std::map<std::string, std::string> where;
};