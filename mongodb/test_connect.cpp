#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/cursor.hpp>

int main(int argc, char *argv[])
{
    using bsoncxx::builder::basic::kvp;
    using bsoncxx::builder::basic::make_document;

    mongocxx::instance inst;

    try
    {
        const auto uri = mongocxx::uri{(argc >= 2) ? argv[1] : mongocxx::uri::k_default_uri};

        auto client = mongocxx::client{uri};
        auto admin = client["test"];
        auto result = admin.run_command(make_document(kvp("isMaster", 1)));
        std::cout << bsoncxx::to_json(result) << std::endl;

        return EXIT_SUCCESS;
    }
    catch (const std::exception &xcp)
    {
        std::cout << "connection failed: " << xcp.what() << std::endl;
        return EXIT_FAILURE;
    }
}