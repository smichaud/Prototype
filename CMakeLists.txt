cmake_minimum_required(VERSION 2.8)
project(Prototype)

add_definitions(-std=c++11)
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


set(CMAKE_AUTOMOC ON)
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
QT4_WRAP_UI(UI_SOURCE_FILES ui/mainwindow.ui)

find_package(OpenCV REQUIRED)

find_package(PCL 1.3 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


file(GLOB_RECURSE SOURCE_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

include_directories(${HEADER_FILES})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})
