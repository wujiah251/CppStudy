include_directories(
    ${PROJECT_SOURCE_DIR}/simhash
    ${PROJECT_SOURCE_DIR}/simhash/cppjieba
    ${PROJECT_SOURCE_DIR}/simhash/dict
    ${PROJECT_SOURCE_DIR}/simhash/limonp
    )

add_executable(SimhashDemo demo.cpp)

install(TARGETS
    SimhashDemo
    DESTINATION bin/
    )

add_subdirectory(test)
