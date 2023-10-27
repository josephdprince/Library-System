#include <Db.h>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

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
    db_inst = (*client)["LibrarySystem"];

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
    std::cout << std::setw(25) << jsonObj["genre"].dump() << std::setw(55)
              << jsonObj["name"].dump() << std::setw(35)
              << jsonObj["author"].dump() << std::setw(7)
              << jsonObj["bookNum"].dump() << std::endl;
  }
  std::cout << std::endl;
}