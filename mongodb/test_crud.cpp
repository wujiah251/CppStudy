#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main()
{
    /* 初始化，创建一个客户端连接 */
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);

    /* 访问指定的数据库和集合 */
    mongocxx::database db = client["test_db"];
    mongocxx::collection coll = db["test_collection"];
    // db.drop();

    // 创建一个json文档
    // 创建一个json文档（Document）
    // {
    //    "name" : "MongoDB",
    //    "type" : "database",
    //    "count" : 5,
    //    "versions": [ "v1.0", "v2.0", "v3.0" ],
    //    "info" : {
    //                "x" : 1314,
    //                "y" : 520
    //             }
    // }
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "name" << "MongoDB"
        << "type" << "database"
        << "count" << 5
        << "versions" << bsoncxx::builder::stream::open_array
            << "v1.0" << "v2.0" << "v3.0"
        << close_array
        << "info" << bsoncxx::builder::stream::open_document
            << "x" << 1314
            << "y" << 520
        << bsoncxx::builder::stream::close_document
        << bsoncxx::builder::stream::finalize;
    bsoncxx::document::view view = doc_value.view();
    bsoncxx::document::element element = view["name"];
    // 插入文档
    bsoncxx::stdx::optional<mongocxx::result::insert_one> insert_one_result = coll.insert_one(doc_value.view());
    bsoncxx::oid oid = insert_one_result->inserted_id().get_oid().value;
    std::string insert_id = oid.to_string();
    std::cout << "Insert one document, return id is " << insert_id << std::endl;

    // 查询单个文档
    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result = coll.find_one({});
    bsoncxx::document::view view2 = maybe_result->view();
    auto find_one_id = view2["_id"].get_oid().value.to_string();
    std::cout << "\nfind one document, return id is " << find_one_id << std::endl;

    // 查询所有文档
    std::cout << "\nfind all documents, return values:\n";
    mongocxx::cursor cursor = coll.find({});
    for(bsoncxx::document::view docView : cursor) {
        std::cout << bsoncxx::to_json(docView) << std::endl;
    }
    // 查询匹配过滤器的文档
    // {"count":5}
    bsoncxx::stdx::optional<bsoncxx::document::value> find_one_result =
        coll.find_one(document{} << "count" << 5 << finalize);
    if(find_one_result) {
        std::cout << "\nspecify query filter, find_one() return values:" << std::endl;
        std::cout << bsoncxx::to_json(find_one_result->view()) << std::endl;
    }

    // 复杂过滤器
    // 5 <= count < 10
    auto filter = document{} << "count" << open_document << 
        "$gte" << 5 << "$lte" << 10 << close_document << finalize;
    auto order = document{};// << "_id" << -1 << finalize;
    auto field = document{} << "_id" << 1 << "count" << 1 << finalize;
    mongocxx::options::find ops = mongocxx::options::find{};
    ops.sort(order.view()).projection(field.view()).limit(3);
    mongocxx::cursor cur = coll.find(filter.view(), ops);
    std::cout << "\nspecify query filter, find() return values:\n";
    for(bsoncxx::document::view docView : cur){
        std::cout << bsoncxx::to_json(docView) << std::endl;
    }
    // 更新单个文档
    mongocxx::stdx::optional<mongocxx::result::update> update_one_result = 
        coll.update_one(document{} << "count" << 1 << finalize,
                        document{} << "$set" << open_document << 
                        "name" << "MongoDB更新测试" << close_document << finalize);
    
    bsoncxx::stdx::optional<mongocxx::result::update> update_many_result = 
        coll.update_many(
            document{} << "count" << open_document << 
                "$lt" << 5 << close_document << finalize,
            document{} << "$inc" <<  open_document << 
                "count" << 1 << close_document << finalize);
    if(update_many_result){
        std::cout << "\nupdate " << update_many_result->modified_count() << " documents\n";
    }
    // 删除单个文档
    mongocxx::stdx::optional<mongocxx::result::delete_result> delete_one_result =
        coll.delete_one(document{} << "count" << 5 << finalize);
    if(delete_one_result){
        std::cout << "\ndelete " << delete_one_result->deleted_count() << " document\n";
    }
    return 0;
}