cmake_minimum_required(VERSION 3.27)
project(.)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(. main.cpp
        Sourcefiles/Word.cpp
        Headers/Word.hpp
        Sourcefiles/Game.cpp
        Headers/Game.hpp
        Sourcefiles/GUI.cpp
        Headers/GUI.hpp
        Sourcefiles/Timer.cpp
        Headers/Timer.hpp
        Sourcefiles/GameOver.cpp
        Headers/GameOver.hpp
        Sourcefiles/WinScreen.cpp
        Headers/WinScreen.hpp
        Sourcefiles/MainMenu.cpp
        Headers/MainMenu.hpp

)
set(SFML_STATIC_LIBRARIES TRUE)
target_link_libraries(. sfml-graphics)