#include "SqlSelectQueryBuilder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::vector<std::string> &columns) {
    sqlSelectQueryData.columns = columns;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumn(const std::string &column) {
    sqlSelectQueryData.columns.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string &from) {
    sqlSelectQueryData.tableName = from;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(
        const std::map<std::string, std::string> &where) {
    sqlSelectQueryData.where = where;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    std::string querry = "SELECT";

    if (!sqlSelectQueryData.columns.empty()) {
        for (auto& val : sqlSelectQueryData.columns) {
            querry += " " + val;
            if (val != sqlSelectQueryData.columns.back()) {
                querry += ",";
            }
        }
    } else {
        querry += " *";
    }

    querry += " FROM " + sqlSelectQueryData.tableName;

    querry += " WHERE ";
    for (auto& val : sqlSelectQueryData.where) {
        querry += val.first + " = " + val.second + " ";
        if (val != *sqlSelectQueryData.where.rbegin()) {
            querry += "AND ";
        }
    }

    querry += ";";
    return querry;
}