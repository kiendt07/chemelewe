cmake_minimum_required(VERSION 3.5)

project(weight)
include_directories()
set(SourceFile read.c main.c read.h)

add_executable(completed ${SourceFile})