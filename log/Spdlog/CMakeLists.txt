add_executable(TestSpdlog
    test_spdlog.cpp
)

target_link_libraries(TestSpdlog
    libspdlog.a
)

install(TARGETS
    TestSpdlog
    DESTINATION bin/
)