add_executable(TestLoad load_test.cpp)

install(TARGETS
    TestLoad
    DESTINATION bin/
    )
