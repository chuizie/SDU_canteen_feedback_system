cmake_minimum_required(VERSION 3.5)

project(Final_work_qt_cmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        homepage.cpp
        homepage.h
        homepage.ui
        admin.h
        admin.cpp
        users.h
        users.cpp
        dishes.h
        dishes.cpp
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Final_work_qt_cmake
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        adminlogin.h adminlogin.cpp adminlogin.ui
        userslogin.h userslogin.cpp userslogin.ui
        adminsignup.h adminsignup.cpp adminsignup.ui
        adminfunc.h adminfunc.cpp adminfunc.ui
        dishesadd.h dishesadd.cpp dishesadd.ui
        dishesdelete.h dishesdelete.cpp dishesdelete.ui
        admindelete.h admindelete.cpp admindelete.ui
        usersdelete.h usersdelete.cpp usersdelete.ui
        commentshow.h commentshow.cpp commentshow.ui
        adminpasswordchange.h adminpasswordchange.cpp adminpasswordchange.ui
        userssignup.h userssignup.cpp userssignup.ui
        usersfinc.h usersfinc.cpp usersfinc.ui
        dishesshow.h dishesshow.cpp dishesshow.ui
        dishessearch.h dishessearch.cpp dishessearch.ui
        commentsubmit.h commentsubmit.cpp commentsubmit.ui
        userspasswordchange.h userspasswordchange.cpp userspasswordchange.ui
        dishesshownew.h dishesshownew.cpp dishesshownew.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Final_work_qt_cmake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Final_work_qt_cmake SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Final_work_qt_cmake
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Final_work_qt_cmake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Final_work_qt_cmake)
endif()
set_target_properties(Final_work_qt_cmake PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Final_work_qt_cmake
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Final_work_qt_cmake)
endif()
