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
#include <mongocxx/pool.hpp>
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main(int argc, char **argv)
{
    /* Parameters */
    std::string collection0_name = "coll_0";
    int N_INSERTS = 1;
    /* Init connection */

    static mongocxx::instance inst{};
    mongocxx::uri client_uri = mongocxx::uri("mongodb://localhost:30011,localhost:30012,localhost:30013/");
    mongocxx::client client = mongocxx::client(client_uri);

    /* Reinit collection */
    mongocxx::pool pool{client_uri};
    mongocxx::pool::entry entry = pool.acquire();
    mongocxx::database db0 = (*entry)["db_0"];
    mongocxx::database db = client["db_0"];
    // mongocxx::collection coll = db["coll_0"];
    // auto builder = bsoncxx::builder::stream::document{};
    // bsoncxx::document::value doc_value = builder
    //                                      << "Hello"
    //                                      << "MongoDB"
    //                                      << bsoncxx::builder::stream::finalize;
    // coll.insert_one(doc_value.view()); /* insert a dummy doc */
    // // coll.delete_many({});              /* delete all docs */
    // /* Create session */
    // mongocxx::client_session session = client.start_session();
    // /* Start transaction */
    // session.start_transaction();
    // /* Create bulk operations */
    // mongocxx::bulk_write bulk_op = db[collection0_name].create_bulk_write(session);
    // /* Fill insert bulk operations */
    // for (int i = 0; i < N_INSERTS; i++)
    // {
    //     mongocxx::model::insert_one insert_one{
    //         bsoncxx::builder::basic::make_document(
    //             bsoncxx::builder::basic::kvp("field0", i),
    //             bsoncxx::builder::basic::kvp("field1", i),
    //             bsoncxx::builder::basic::kvp("field2", i))};
    //     bulk_op.append(insert_one);
    // }
    // /* Execute transaction */
    // try
    // {
    //     bulk_op.execute();
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Bulk write exception: " << e.what() << std::endl;
    //     session.abort_transaction();
    // }
    // session.commit_transaction();
    /*
    coll: coll_1
    {
        "name" : "mongodb",
        "array" : [
            "1" : "1",
            "2" : "2"
        ]
    }
    */
    mongocxx::collection coll1 = db["coll_1"];
    mongocxx::client_session session1 = client.start_session();
    document builder{};
    auto before = builder << "name"
                          << "mongodb"
                          << "array" << open_array;
    before = before << open_document << "1" << 1 << close_document;
    before = before << open_document << "2" << 2 << close_document;
    auto doc = before << close_array << finalize;
    session1.start_transaction();
    try
    {
        coll1.insert_one(doc.view());
    }
    catch (std::exception &e)
    {
        std::cout << "exception:" << e.what() << std::endl;
        session1.abort_transaction();
    }
    session1.commit_transaction();
    return 0;
}
