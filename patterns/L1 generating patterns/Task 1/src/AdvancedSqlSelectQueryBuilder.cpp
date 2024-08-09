#include <iostream>
#include "AdvancedSqlSelectQueryBuilder.h"

std::string AdvancedSqlSelectQueryBuilder::BuildQuerryWithModOperators(const std::string &key,
        const std::string &what) {
    std::string querry = SqlSelectQueryBuilder::BuildQuery();

    int position = querry.find("=", querry.find(key));

    if (what == "smaller") {
        querry[position] = '<';
    } else if (what == "bigger") {
        querry[position] = '>';
    }

    return querry;
}