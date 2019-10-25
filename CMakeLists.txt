cmake_minimum_required(VERSION 3.15)
project(cs2100_proyecto_grafos_biblioteca_la_reencarnacion_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cs2100_proyecto_grafos_biblioteca_la_reencarnacion_2_0
        Coordenadas.h
        Edge.h
        Grapho.h
        macros.h
        main.cpp
        MST.h
        Node.h)
