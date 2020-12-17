cmake_minimum_required(VERSION 3.13)
project(poo2_2020_2_ui_reactiva)

# Archivos del Projecto
set(PROJECT_SOURCE
        main.cpp
        app.cpp app.h component.cpp component.h button.cpp button.h my_app.cpp my_app.h label.cpp label.h)

# C++ Standard se sugiere 11 o 14
set(CMAKE_CXX_STANDARD 14)

# Runtime folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DEBUG})

# SFML folders
set(SFML_ROOT "~/DevLibraries/SFML/32bit/SFML-2.5.1")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

if (APPLE)
    set(SFML_DIR "${SFML_ROOT}/Frameworks/SFML.framework/Resources/CMake")
else()
    set(SFML_DIR "${SFML_ROOT}/lib/CMake/SFML")
endif()

link_directories(${SFML_LIBRARY_DIR})
include_directories(${SFML_INCLUDE_DIR})

# Instrucciones para generar el ejecutable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})

find_package(SFML 2.5.1
        COMPONENTS
            system
            window
            graphics
        REQUIRED)

target_link_libraries (${PROJECT_NAME}
        sfml-system
        sfml-window
        sfml-graphics
        )

configure_file(./Oxanium-Regular.ttf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
