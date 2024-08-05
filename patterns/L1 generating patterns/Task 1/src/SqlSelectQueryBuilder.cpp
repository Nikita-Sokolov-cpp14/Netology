#include "SqlSelectQueryBuilder.h"

void SqlSelectQueryBuilder::AddColumn(const std::vector<std::string>& columns) {
    sqlSelectQuery.columns = columns;
}

void SqlSelectQueryBuilder::AddFrom(const std::string& from) {
    sqlSelectQuery.from = from;
}

void SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& where) {
    sqlSelectQuery.where = where;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    return sqlSelectQuery.makeQuerry();
}