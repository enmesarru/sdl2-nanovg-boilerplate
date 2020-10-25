set(TestName geometry_test)

file(GLOB Sources
    "test.cpp"
)
add_executable(${TestName} ${Sources})
target_link_libraries(${TestName} gtest_main binary_library)
target_include_directories(${TestName} PUBLIC ../include)
add_test(${TestName} ${TestName})