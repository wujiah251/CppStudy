#ifndef LOGGER_H_
#define LOGGER_H_

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>
#include <memory>

// spd带行号的打印，同时输出控制台和文件(定义三级日志等级)
// #define INFO(...)                                                  \
//     SPDLOG_LOGGER_INFO(spdlog::default_logger_raw(), __VA_ARGS__); \
//     SPDLOG_LOGGER_INFO(spdlog::get("daily_logger"), __VA_ARGS__)
// #define WARN(...)                                                  \
//     SPDLOG_LOGGER_WARN(spdlog::default_logger_raw(), __VA_ARGS__); \
//     SPDLOG_LOGGER_WARN(spdlog::get("daily_logger"), __VA_ARGS__)
// #define ERROR(...)                                                  \
//     SPDLOG_LOGGER_ERROR(spdlog::default_logger_raw(), __VA_ARGS__); \
//     SPDLOG_LOGGER_ERROR(spdlog::get("daily_logger"), __VA_ARGS__)

#define INFO(...) \
    SPDLOG_LOGGER_INFO(spdlog::get("daily_logger"), __VA_ARGS__)
#define WARN(...) \
    SPDLOG_LOGGER_WARN(spdlog::get("daily_logger"), __VA_ARGS__)
#define ERROR(...) \
    SPDLOG_LOGGER_ERROR(spdlog::get("daily_logger"), __VA_ARGS__)

void LoggerInit()
{
    // 按文件大小
    //auto file_logger = spdlog::rotating_logger_mt("daily_logger", "logs/log.txt", 1024 * 1024 * 20,  5);

    // 每天0:00 am 新建一个日志文件
    auto logger = spdlog::daily_logger_mt("daily_logger", "./Log/spdlog.txt", 0, 0);

    // 遇到warn级别以上的日志进行持久化，防止日志丢失
    logger->flush_on(spdlog::level::warn);

    //日志每3秒钟向磁盘持久化
    spdlog::flush_every(std::chrono::seconds(3));

    // 设置默认的logger
    // auto console = spdlog::stdout_color_mt("console");
    // spdlog::set_default_logger(console);

    // 设置日志输出级别
    spdlog::set_level(spdlog::level::info);

    // 设置日志格式
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S][%l][%s:%#] %v");
}

void LoggerDrop()
{
    spdlog::drop_all();
}

int main()
{
    LoggerInit();
    INFO("INFO log. Num is {}", 1);
    WARN("WARN log. Num is {}", 2);
    ERROR("ERROR log. Num is {}", "3");
    ERROR("ERROR log. Num is {}", "4");
    LoggerDrop();
    return 0;
}

#endif /*LOGGER_H_ */
