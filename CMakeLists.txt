cmake_minimum_required(VERSION 3.10.3)

project(astroner)

set(HPPS "engine/bullet.hpp" "engine/others.hpp" "engine/player.hpp")
set(CPPS "src/main.cpp")

include_directories("./engine/" "./src/")
add_executable(${PROJECT_NAME} ${HPPS} ${CPPS}) 

target_link_libraries(${PROJECT_NAME} sfml-system sfml-audio sfml-graphics sfml-window)

