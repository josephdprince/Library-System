#include <Db.h>
#include <iomanip>
#include <iostream>

Db::Db(std::string &URI) {
  try {
    // Create an instance.
    mongocxx::instance inst{};

    const auto uri = mongocxx::uri{URI};

    // Set the version of the Stable API on the client.
    mongocxx::options::client client_options;
    const auto api = mongocxx::options::server_api{
        mongocxx::options::server_api::version::k_version_1};
    client_options.server_api_opts(api);

    // Setup the connection and get a handle on the "admin" database.
    client = new mongocxx::client{uri, client_options};

    // Put your db name here
    db_inst = (*client)[""];

    // Ping the database.
    const auto ping_cmd = bsoncxx::builder::basic::make_document(
        bsoncxx::builder::basic::kvp("ping", 1));
    db_inst.run_command(ping_cmd.view());
    std::cout
        << "Pinged your deployment. You successfully connected to MongoDB!"
        << std::endl;

  } catch (const std::exception &e) {
    // Handle errors
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

Db::~Db() { delete client; }

void Db::LibDisplayAll() {
  std::cout << std::right << std::setw(25) << "Genre" << std::right
            << std::setw(55) << "Title" << std::right << std::setw(35)
            << "Author" << std::right << std::setw(7) << "ID" << std::endl;
  std::cout
      << "--------------------------------------------------------------------"
         "-------------------------------------------------------------"
      << std::endl;

  mongocxx::collection coll = db_inst["Books"];
  mongocxx::cursor cursor = coll.find({});

  for (auto doc : cursor) {
    json jsonObj = json::parse(
        bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed));
    output(jsonObj);
  }
  std::cout << std::endl;
}

void Db::LibDisplayGenre(std::string &genre) {
  mongocxx::collection coll = db_inst["Books"];
  mongocxx::cursor cursor = coll.find(make_document(kvp("genre", genre)));

  for (auto doc : cursor) {
    json jsonObj = json::parse(
        bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed));

    output(jsonObj);
  }
}

void Db::LibInsertBook(std::string &title, std::string &author,
                       std::string &genre, int &bookID) {
  mongocxx::collection coll = db_inst["Books"];
  auto result = coll.insert_one(make_document(
      kvp("name", title), kvp("author", author), kvp("genre", genre),
      kvp("bookNum", bookID), kvp("rating", 0), kvp("numReviews", 0)));
  assert(result);
}

void Db::LibRemoveBook(int &id) {
  mongocxx::collection coll = db_inst["Books"];
  coll.delete_one(make_document(kvp("bookNum", id)));
}

Book *Db::FindBookById(int &id) {
  mongocxx::collection coll = db_inst["Books"];
  auto cursor = coll.find_one(make_document(kvp("bookNum", id)));
  auto doc = cursor->view();

  if (doc.empty()) {
    return nullptr;
  }

  json jsonObj =
      json::parse(bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed));
  return new Book(jsonObj["name"].dump(), jsonObj["author"].dump(),
                  jsonObj["genre"].dump(), stoi(jsonObj["bookNum"].dump()),
                  stod(jsonObj["rating"].dump()),
                  stoi(jsonObj["numReviews"].dump()));
}

void Db::LibGetPopular() {
  mongocxx::collection coll = db_inst["Books"];
  auto cursor =
      coll.find(make_document(kvp("rating", make_document(kvp("$gte", 3.5)))));

  for (auto doc : cursor) {
    json jsonObj = json::parse(
        bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed));

    output(jsonObj);
  }
}

void Db::output(json jsonObj) {
  std::cout << std::setw(25) << jsonObj["genre"].dump() << std::setw(55)
            << jsonObj["name"].dump() << std::setw(35)
            << jsonObj["author"].dump() << std::setw(7)
            << jsonObj["bookNum"].dump() << std::endl;
}