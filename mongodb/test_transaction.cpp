#include <iostream>
#include <vector>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/exception/logic_error.hpp>
#include <mongocxx/exception/operation_exception.hpp>

int main(int argc, char **argv)
{
    /* Parameters */
    std::string collection0_name = "coll_0";
    int N_INSERTS = 1;
    /* Init connection */

    static mongocxx::instance inst{};
    mongocxx::uri client_uri = mongocxx::uri("mongodb://localhost:30012");
    mongocxx::client client = mongocxx::client(client_uri);

    /* Reinit collection */

    mongocxx::database db = client["db_0"];
    mongocxx::collection coll = db["coll_0"];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "Hello"
        << "MongoDB"
        << bsoncxx::builder::stream::finalize;
    coll.insert_one(doc_value.view()); /* insert a dummy doc */
    coll.delete_many({});              /* delete all docs */

    /* Create session */

    mongocxx::client_session session = client.start_session();

    /* Start transaction */

    session.start_transaction();

    /* Create bulk operations */

    mongocxx::bulk_write bulk_op = db[collection0_name].create_bulk_write(session);

    /* Fill insert bulk operations */

    for (int i = 0; i < N_INSERTS; i++)
    {

        mongocxx::model::insert_one insert_one{
            bsoncxx::builder::basic::make_document(
                    bsoncxx::builder::basic::kvp("field0", i),
                    bsoncxx::builder::basic::kvp("field1", i),
                    bsoncxx::builder::basic::kvp("field2", i))};

        bulk_op.append(insert_one);
    }

    /* Execute transaction */

    //try
    //{
    bulk_op.execute();
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Bulk write exception: " << e.what() << std::endl;
    //     session.abort_transaction();
    // }

    session.commit_transaction();

    return 0;
}
