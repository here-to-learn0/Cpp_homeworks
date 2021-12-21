add_library(image image_class.cpp)
target_link_libraries(image io_tools)
# add_executable(main main.cpp)
# target_link_libraries (main image io_tools ${OpenCV_LIBS})