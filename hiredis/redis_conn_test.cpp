#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hiredis/hiredis.h>

int main(int argc,char **argv)
{
    unsigned int j;
    redisContext *conn;
    redisReply *reply;
    if (argc < 3){
        printf("Usage: example {instance_ip_address} 6379 {password}\n");
        exit(0);
    }
    const char *hostname = argv[1];
    const int port = atoi(argv[2]);
    const char *password = argv[3];
    struct timeval timeout = {1, 500000};   // 1.5seconds;
    conn = redisConnectWithTimeout(hostname, port, timeout);
    if (conn == NULL || conn->err) {
        if(conn){
            printf("Connection error: %s\n", conn->errstr);
            redisFree(conn);
        }
        else{
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }
    /*AUTH*/
    reply = (redisReply*)redisCommand(conn, "AUTH %s",password);
    printf("AUTH:%s\n",reply->str);
    freeReplyObject(reply);
    
    /*SET*/
    reply = (redisReply*)redisCommand(conn,"SET %s %s","welcome","Hello, DCS for Redis");
    printf("SET: %s\n",reply->str);
    freeReplyObject(reply);
    redisFree(conn);
    return 0;
}
