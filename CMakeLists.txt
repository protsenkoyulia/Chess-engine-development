cmake_minimum_required(VERSION 3.28)
project(chess_engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(chess_engine main.cpp
        UI/Board.cpp
        UI/Piece.h
        UI/Piece.cpp
        BASE/chess.cpp
        BASE/variant.cpp
)
target_link_libraries(chess_engine
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

