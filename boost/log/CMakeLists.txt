add_executable(TestBoostLog test_log.cpp)

target_link_libraries(TestBoostLog
    ${Boost_LIBRARIES}
)

install(TARGETS
    TestBoostLog
    DESTINATION bin/
)