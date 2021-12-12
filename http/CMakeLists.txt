add_executable(HttpEchoServer
    http_echo_server.cpp
)
install(TARGETS
    HttpEchoServer
    DESTINATION bin/    
)
