#pragma once
#include <vector>
#include <map>

#include "SqlSelectQueryData.h"

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::vector<std::string> &columns);
    SqlSelectQueryBuilder &AddColumn(const std::string &column);
    SqlSelectQueryBuilder& AddFrom(const std::string &from);
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string> &where);
    std::string BuildQuery();
private:
    SqlSelectQueryData sqlSelectQueryData;
};