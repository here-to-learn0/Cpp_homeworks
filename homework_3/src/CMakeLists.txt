add_library(html_writer html_writer.cpp image_browser.cpp)
add_library(image_browser html_writer.cpp image_browser.cpp)
add_executable(output main.cpp)
target_link_libraries (output html_writer image_browser)