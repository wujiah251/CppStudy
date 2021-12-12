add_executable(RedisConnTest
    redis_conn_test.cpp
)

add_executable(RedisAsyncTest
    redis_async_test.cpp
)

target_link_libraries(RedisConnTest
    libhiredis.a
)
target_link_libraries(RedisAsyncTest
    libhiredis.a
    libae.a
    libevent.a
)


install(TARGETS
    RedisConnTest
    RedisAsyncTest
    DESTINATION bin/
)
