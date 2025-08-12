# Tentukan versi minimum CMake yang dibutuhkan
cmake_minimum_required(VERSION 3.10)

# Definisikan nama proyek Anda
project(AplikasiDatabaseCanggih)

# Atur agar kita menggunakan standar C++ versi 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tentukan lokasi folder output agar file .exe diletakkan di sana
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Cari semua file .cpp di dalam folder src secara otomatis
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Buat program executable bernama "AplikasiSaya" dari semua file sumber
add_executable(AplikasiSaya ${SOURCES})

# Memberitahu compiler bahwa kita akan me-link Connector/C++ secara statis
target_compile_definitions(AplikasiSaya PRIVATE STATIC_CONCPP)

# Beritahu CMake di mana folder "include" kita berada
target_include_directories(AplikasiSaya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Beritahu CMake di mana folder "lib" kita berada
target_link_directories(AplikasiSaya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib64/vs14)

# --------------------------------------------------------------------------------- #
# ----> INI BAGIAN PERBAIKANNYA <----
# Atur properti Runtime Library agar sesuai dengan jenis build
# Ini akan mengganti flag MDd/MD menjadi MTd/MT
set_property(TARGET AplikasiSaya PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# --------------------------------------------------------------------------------- #

# Tautkan (link) library yang dibutuhkan oleh program kita
target_link_libraries(AplikasiSaya PRIVATE mysqlcppconn-static libssl libcrypto)