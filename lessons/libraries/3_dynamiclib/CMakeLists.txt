project(caos-libraries)

add_library(point SHARED point.c)
add_executable(program main.c)
target_link_libraries(program point)
