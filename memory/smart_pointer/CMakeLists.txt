add_executable(SharedPtrTest
    shared_ptr_test.cpp
)

add_executable(UniquePtrTest
    unique_ptr_test.cpp
)

add_executable(WeakPtrTest
    weak_ptr_test.cpp
)


install(TARGETS
    SharedPtrTest
    UniquePtrTest
    WeakPtrTest
    DESTINATION bin/
)
