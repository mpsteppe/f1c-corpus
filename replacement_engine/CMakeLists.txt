cmake_minimum_required(VERSION 3.24)
project(F1CReplacementEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(f1c_engine_core STATIC
    src/bootstrap/application.cpp
    src/config/ini_document.cpp
    src/content/inventory.cpp
    src/logging/logger.cpp
    src/platform/install_root.cpp
)
target_include_directories(f1c_engine_core PUBLIC include)
target_compile_definitions(f1c_engine_core PRIVATE UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX)

if(MSVC)
    target_compile_options(f1c_engine_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(f1c_engine_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(f1c_replacement WIN32 src/winmain.cpp)
target_link_libraries(f1c_replacement PRIVATE f1c_engine_core shell32)
target_compile_definitions(f1c_replacement PRIVATE UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX)
if(MINGW)
    target_link_options(f1c_replacement PRIVATE -municode)
endif()
set_target_properties(f1c_replacement PROPERTIES OUTPUT_NAME "F1ChallengeReplacement")

include(CTest)
if(BUILD_TESTING)
    add_executable(f1c_engine_tests tests/bootstrap_tests.cpp)
    target_link_libraries(f1c_engine_tests PRIVATE f1c_engine_core)
    add_test(NAME f1c_engine_tests COMMAND f1c_engine_tests)
endif()
