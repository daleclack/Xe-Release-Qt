cmake_minimum_required(VERSION 3.5)

project(XeRelease_Qt5 VERSION 17.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/branchdialog.cc
        src/branchdialog.h
        src/branchdialog.ui
        src/config.hh
        src/main.cc
        src/mainwindow.cc
        src/mainwindow.h
        src/mainwindow.ui
        src/xeapi.hh
        src/xeapi.cc
        src/xerelease.hh
        src/xerelease.cc
        json_nlohmann/json.hpp
        xe_resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(XeRelease_Qt5
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        icon.rc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET XeRelease_Qt5 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(XeRelease_Qt5 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(XeRelease_Qt5
            ${PROJECT_SOURCES}
            icon.rc
        )
    endif()
endif()

target_link_libraries(XeRelease_Qt5 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(XeRelease_Qt5 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER io.qt5.daleclack
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS XeRelease_Qt5
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(XeRelease_Qt5)
endif()
