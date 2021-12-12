add_executable(SetTest
    set_test.cpp
)

target_link_libraries(SetTest
    libbenchmark.a
    libabsl.a
)

install(TARGETS
    SetTest
    DESTINATION bin/
)


#set(head_files
## install的头文件
#)

#install(TARGETS
    #${head_files}
    #DESTINATION ${DCMAKE_INSTALL_PREFIX}/include
#)
