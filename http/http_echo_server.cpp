#include <httplib.h>
#include <string>
using std::string;
using namespace httplib;

int main(int argc, char* argv[])
{
    if(argc<3)
    {
        printf("Please input ip and port\n");
        exit(-1);
    }
    char* ip=argv[1];
    int port=atoi(argv[2]);
    Server server;
    server.Get("/echo",[](const Request& req, Response& resp)
            {
                auto input =req.body;
                resp.set_content(input,"text/plain");
            });
    server.Get("/hello",[](const Request& req, Response& resp)
            {
                resp.set_content("hello world!\n","text/plain");
            });
    server.listen(ip,port);
}
