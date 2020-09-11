cmake_minimum_required(VERSION 3.17)
project(kpi_lab1)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(kpi_lab1 main.cpp PictureProcessing.cpp PictureProcessing.h)

# linking
target_link_libraries(kpi_lab1 ${OpenCV_LIBS})