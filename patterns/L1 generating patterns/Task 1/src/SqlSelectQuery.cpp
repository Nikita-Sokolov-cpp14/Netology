#include "SqlSelectQuery.h"

std::string SqlSelectQuery::makeQuerry() {
    querry_ = "SELECT";

    if (!columns.empty()) {
        for (auto val : columns) {
            querry_ += " " + val;
        }
    } else {
        querry_ += " *";
    }

    querry_ += " FROM " + tableName;

    querry_ += " WHERE";
    for (auto val : where) {
        querry_ += val.first() + " = " + val.second();
    }

    querry_ += ";";
    return querry_;
}
