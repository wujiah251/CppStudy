#include <unistd.h>
#include "mylog/log.h"

int main()
{
    LOG_INIT("Log", "test", INFO);
    LOG_DEBUG("debug");
    LOG_INFO("info");
    LOG_NORMAL("NORMAL");
    LOG_WARN("WARN");
    LOG_ERROR("ERROR");
    for (int i = 0; i < 100000; ++i)
    {
        LOG_INFO("TEST1");
    }
    sleep(10);
    return 0;
}