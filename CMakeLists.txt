cmake_minimum_required(VERSION 3.22)
project(r4_cub3d C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(r4_cub3d
        inc/cub3d.h

        utils/libft.h
        utils/get_next_line.c
        utils/get_next_line_utils.c
        main.c
        )
