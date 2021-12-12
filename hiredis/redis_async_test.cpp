#ifdef __cplusplus
extern "C"{
#endif

#include <hiredis/hiredis.h>
#include <hiredis/adapters/ae.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>

#ifdef __cplusplus
}
#endif


void connectCallback(const redisAsyncContext *c, int status);
void disconnectCallback(const redisAsyncContext *c, int status);
void getCallback(redisAsyncContext *c, void *r, void *privdata);


int main()
{
    // 异步调用上下文
    redisAsyncContext *c = redisAsyncConnect("127.0.0.1",6379);
    auto loop = aeCreateEventLoop(10);
    redisAeAttach(loop, c);
    redisAsyncSetConnectCallback(c, connectCallback);
    redisAsyncSetDisconnectCallback(c, disconnectCallback);
    redisAsyncCommand(c, getCallback, (char*)"end-1","GET key");
    return 0;
}

void connectCallback(const redisAsyncContext *c, int status)
{
    printf("Connected...\n");
}

void disconnectCallback(const redisAsyncContext *c, int status)
{
    printf("Disconnected...\n");
}

void getCallback(redisAsyncContext *c, void *r, void *privdata)
{
    redisReply *reply = (redisReply*)r;
    if(reply == NULL)return;
    printf("argv[%s]: %s\n", (char*)privdata, reply->str);
    redisAsyncDisconnect(c);
}

