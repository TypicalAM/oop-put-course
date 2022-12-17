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

# This is the main part:
set(SOURCES src/Main.cpp include/math/Operation.h src/math/operations/Addition.cpp include/math/operations/Addition.h include/screen/State.h src/screen/ui_elements/Button.cpp include/screen/ui_elements/Button.h src/screen/Screen.cpp include/screen/Screen.h src/math/operations/Subtraction.cpp include/math/operations/Subtraction.h src/math/operations/Multiplication.cpp include/math/operations/Multiplication.h src/screen/ui_elements/Textbox.cpp include/screen/ui_elements/Textbox.h src/math/expressions/ExpressionParseError.cpp include/math/expressions/ExpressionParseError.h src/math/expressions/OperatorToken.cpp include/math/expressions/OperatorToken.h src/math/expressions/ExpressionTokens.cpp include/math/expressions/ExpressionTokens.h src/math/expressions/ExpressionParser.cpp include/math/expressions/ExpressionParser.h src/math/expressions/NumericToken.cpp include/math/expressions/NumericToken.h src/math/operations/Division.cpp include/math/operations/Division.h src/math/operations/Modulus.cpp include/math/operations/Modulus.h src/math/operations/Exponentiation.cpp include/math/operations/Exponentiation.h src/math/operations/LogicalOR.cpp include/math/operations/LogicalOR.h src/math/operations/LogicalAND.cpp include/math/operations/LogicalAND.h)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif ()