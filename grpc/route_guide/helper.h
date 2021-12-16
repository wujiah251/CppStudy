#ifndef GRPC_ROUTE_GUIDE_HELPER_H_
#define GRPC_ROUTE_GUIDE_HELPER_H_

#include <vector>
#include <string>

namespace routeguide {
    class Feature;
    std::string GetDbFileContent(int argc, char** argv);
    void ParseDb(const std::string& db, std::vector<Feature>* feature_list);

}// namespce routeguide

#endif
