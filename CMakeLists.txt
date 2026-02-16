# Copyright (C) 2026, Bruce MacKinnon KC1FSZ
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# ( at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
cmake_minimum_required(VERSION 3.13)
project(ampersand C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Wpedantic -g -O0)

# ----- hello-1 ---------------------------------------------------------------

add_executable(hello-1
  src/tests/hello-1.cpp
  src/g711.c
  src/g72x.c
  src/g726_32.c
)

target_include_directories(hello-1 PRIVATE src)
