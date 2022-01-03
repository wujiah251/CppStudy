add_executable(TestConnect test_connect.cpp)

target_link_libraries(TestConnect
    ${LIBMONGOCXX_LIBRARIES}
)

add_executable(TestCRUD test_crud.cpp)

target_link_libraries(TestCRUD
    ${LIBMONGOCXX_LIBRARIES}
)

add_executable(TestTransaction test_transaction.cpp)

target_link_libraries(TestTransaction
    ${LIBMONGOCXX_LIBRARIES}
)


install(TARGETS
    TestConnect
    TestCRUD
    TestTransaction
    DESTINATION bin/
)