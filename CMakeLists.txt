cmake_minimum_required(VERSION 3.22)
project(FlashForge VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_add_executable(flashforge
src/main.cpp
)
target_link_libraries(flashforge PRIVATE Qt6::Widgets)
install(TARGETS flashforge RUNTIME DESTINATION bin)
