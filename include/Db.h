#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

class Db {
private:
  mongocxx::client *client;
  mongocxx::database db_inst;

public:
  Db(std::string &URI);
  ~Db();

  void LibDisplayAll();
};