cmake_minimum_required(VERSION 3.17)
project(lifegame-sfml)

set(files 
    main.cpp
    Game.cpp
    Board.cpp

)

set(CMAKE_PREFIX_PATH "C:/Programming/SFML-2.5.0-sources/SFML-2.5.0/sfml-build")

find_package(SFML COMPONENTS system graphics REQUIRED)

set(SFML_STATIC_LIBRARIES TRUE)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    add_executable(${PROJECT_NAME} ${files})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system)
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB BINARY_REP_DLLS "C:/Programming/SFML-2.5.0-sources/SFML-2.5.0/sfml-build/lib/*.dll")
file(COPY ${BINARY_REP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
