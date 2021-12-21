add_library(ipb_arithmatic subtract.cpp sum.cpp)
add_executable(test_ipb_arithmetic main.cpp)
target_link_libraries (test_ipb_arithmetic ipb_arithmatic)