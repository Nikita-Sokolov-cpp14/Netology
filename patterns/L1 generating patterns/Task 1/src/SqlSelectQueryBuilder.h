#pragma once
#include <vector>
#include <map>

#include "SqlSelectQuery.h"

class SqlSelectQueryBuilder {
public:
    void AddColumn(const std::vector<std::string>& columns);
    void AddFrom(const std::string& from);
    void AddWhere(const std::map<std::string, std::string>& where);
    std::string BuildQuery();
private:
    SqlSelectQuery sqlSelectQuery;
};