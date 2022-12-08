cmake_minimum_required(VERSION 3.24)
project(clion)

set(CMAKE_CXX_STANDARD 17)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.2.0
    )
    FetchContent_MakeAvailable(raylib)
endif ()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG v4.2.6
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif ()

# This is the main part:
set(SOURCES src/Main.cpp include/math/Operation.h src/math/operations/Addition.cpp include/math/operations/Addition.h include/screen/State.h src/screen/ui_elements/Button.cpp include/screen/ui_elements/Button.h src/screen/Screen.cpp include/screen/Screen.h src/math/operations/Subtraction.cpp include/math/operations/Subtraction.h src/math/operations/Multiplication.cpp include/math/operations/Multiplication.h src/screen/ui_elements/Textbox.cpp include/screen/ui_elements/Textbox.h src/math/expressions/ExpressionTree.cpp include/math/expressions/ExpressionTree.h src/math/expressions/ExpressionNode.cpp include/math/expressions/ExpressionNode.h)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif ()

# That's it! You should have an example executable that you can run. Have fun!