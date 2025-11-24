cmake_minimum_required(VERSION 3.21.1)

project(MonkeyWriter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(${CMAKE_PROJECT_NAME}
   mainwindow.cpp
   mainwindow.ui
   menu.cpp
   workingArea.cpp
   main.cpp
   appresources.qrc
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
   WIN32_EXECUTABLE ON
   MACOSX_BUNDLE OFF
)
