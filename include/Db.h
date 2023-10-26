#pragma once

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <string>

class Db {
private:
  mongocxx::database db_inst;

public:
  Db(const std::string &URI);
  ~Db();
};