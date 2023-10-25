#pragma once

#include <string>

namespace mongocxx {
class database;
}

class Db {
private:
  mongocxx::database db_inst;

public:
  Db(const string &URI);
};