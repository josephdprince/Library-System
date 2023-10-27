#include <Db.h>
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
    mongocxx::client conn{uri, client_options};
    db_inst = conn["libsystem"];

    // Ping the database.
    const auto ping_cmd = bsoncxx::builder::basic::make_document(
        bsoncxx::builder::basic::kvp("ping", 1));
    db_inst.run_command(ping_cmd.view());
    std::cout
        << "Pinged your deployment. You successfully connected to MongoDB!"
        << std::endl;

    auto coll = db_inst["Books"];
    auto cursor = coll.find({});

    for (auto doc : cursor) {
      std::cout << "Printing" << std::endl;
      std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed)
                << std::endl;
    }
    std::cout << "I did it?" << std::endl;
  } catch (const std::exception &e) {
    // Handle errors
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void Db::printDocs(std::string &collName) {
  auto coll = db_inst.collection(collName);
  auto cursor = coll.find({});

  for (auto doc : cursor) {
    std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed)
              << std::endl;
  }
  std::cout << std::endl;
}