add_executable(TestThreadPool
    test_thread_pool.cpp
    )

install(TARGETS
    TestThreadPool
    DESTINATION bin/
    )
