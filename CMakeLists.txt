cmake_minimum_required(VERSION 3.19)
project(KinoTeatras)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinoTeatras main.cpp Filmas.h Filmas.cpp Klientas.cpp Klientas.h Bilietas.cpp Bilietas.h database/sqlite3.c database/sqlite3.h Database.cpp Database.h)