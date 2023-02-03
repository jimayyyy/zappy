cmake_minimum_required(VERSION 3.17)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(ImportRaylib)
project(zappy_gui)
include_directories(Buttons PARSER encaps connection SCREENS SCREENS/MENU SCREENS/SETTINGS SCREENS/TITLE)
add_executable(zappy_gui
        encaps/Shape.cpp
        encaps/Model.cpp
        encaps/Case.cpp
        encaps/Map.cpp
        encaps/Text.cpp
        SCREENS/HandlingScreen.cpp
        SCREENS/Screen.cpp
        SCREENS/MENU/Menu.cpp
        SCREENS/TITLE/Title.cpp
        connection/connection.cpp
        Buttons/Buttons.cpp
        Buttons/ButtonsScreen.cpp
        DisplayModule.cpp
        SCREENS/window.cpp
        PARSER/Parser.cpp
        connection/GetInfoConnection.cpp
        main.cpp
        )
target_link_libraries(${PROJECT_NAME} raylib)