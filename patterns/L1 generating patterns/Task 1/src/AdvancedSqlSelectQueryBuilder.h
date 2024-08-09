#pragma once
#include "SqlSelectQueryBuilder.h"

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
    std::string BuildQuerryWithModOperators(const std::string &key, const std::string &what);
};
