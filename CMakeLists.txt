# Version minimale de Cmake
cmake_minimum_required(VERSION 3.3)

# Nom du projet
project(projet)

# On indique où se trouve les en-têtes
include_directories(include)

# On construit la liste des fichiers sources à partir du contenu du dossier src
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# On choisit un type de compilation par défaut
if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Release)
endif()

# On indique les options de compilation générales
set(CMAKE_CXX_FLAGS "-std=c++17")

# On indique les options de compilations pour des compilations spécifiques
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fno-sanitize=vptr")

# On affiche un message à l'appel de cmake
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message("   Compiler CXX:         ${CMAKE_CXX_COMPILER}")
message("   Compiler CXX flags:         ${CMAKE_CXX_FLAGS}")

if(CMAKE_BUILD_TYPE MATCHES "DEBUG")
        message("   Compiler CXX debug flags:   ${CMAKE_CXX_FLAGS_DEBUG}")
endif(CMAKE_BUILD_TYPE MATCHES "DEBUG")

if(CMAKE_BUILD_TYPE MATCHES "RELEASE")
        message("   Compiler CXX release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
endif(CMAKE_BUILD_TYPE MATCHES "RELEASE")

# On crée la bibliothèque projet.a
add_library(projet ${SOURCE_FILES})

# On génère l'exécutable principal
add_executable(run src/main.cpp)

# On lui lie la bibilohèque projet.a
target_link_libraries(run projet)

# On ajoute des tests unitaires
include(CTest)
enable_testing()

file(GLOB_RECURSE TEST_FILES test/*.cpp)

foreach(test_full_path ${TEST_FILES})
        get_filename_component(test_filename ${test_full_path} NAME)
        string(CONCAT test_filename "test/" ${test_filename})
        get_filename_component(test_name ${test_filename} NAME_WE)
        add_executable(${test_name} ${test_filename})
        add_test(${test_name} ${test_name})
        target_link_libraries(${test_name} projet)
endforeach()




