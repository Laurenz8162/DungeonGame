cmake_minimum_required(VERSION 3.16)

project(DungeonGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Group all sources in one place (no duplicate combatscreen.h!)
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        GUI/menu.cpp
        GUI/menu.h
        source/characters.cpp
        source/characters.h
        GUI/combatscreen.cpp
        GUI/combatscreen.h
        GUI/combatscreen.ui
        source/combat.cpp
        source/combat.h
        source/oldcombat.h
        GUI/resources.qrc
)

# Define the target ONCE with all sources
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DungeonGame
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(DungeonGame SHARED ${PROJECT_SOURCES})
    else()
        add_executable(DungeonGame ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(DungeonGame PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DungeonGame)
endif()
set_target_properties(DungeonGame PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DungeonGame
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DungeonGame)
endif()