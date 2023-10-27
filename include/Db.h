#pragma once

#include "Book.h"
#include <cstdint>
#include <string>
#include <vector>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <nlohmann/json.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;
using json = nlohmann::json;

class Db {
private:
  mongocxx::client *client;
  mongocxx::database db_inst;

public:
  Db(std::string &URI);
  ~Db();

  void LibDisplayAll();
  void LibDisplayGenre(std::string &genre);
  void LibInsertBook(std::string &title, std::string &author,
                     std::string &genre, int &bookID);
  void LibRemoveBook(int &id);
  Book *FindBookById(int &id);
  void LibGetPopular();
  void output(json jsonObj);
};