add_executable(TestConnect test_connect.cpp)

target_link_libraries(TestConnect
    ${LIBMONGOCXX_LIBRARIES}
)

install(TARGETS
    TestConnect
    DESTINATION bin/
)