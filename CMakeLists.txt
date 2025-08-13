# Tentukan versi minimum CMake
cmake_minimum_required(VERSION 3.10)

# Definisikan nama proyek
project(AplikasiDatabaseCanggih)

# Atur standar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tentukan lokasi folder output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Pengaturan manual untuk path MariaDB Connector
include_directories("C:/Program Files/MariaDB/MariaDB Connector C 64-bit/include")
link_directories("C:/Program Files/MariaDB/MariaDB Connector C 64-bit/lib")

# Cari semua file .cpp di dalam folder src secara otomatis
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Buat program executable bernama "AplikasiSaya" dari semua file sumber
add_executable(AplikasiSaya ${SOURCES})

# --------------------------------------------------------------------
# ----> INI BARIS FINALNYA <----
# Sambungkan library MariaDB DAN SEMUA library Windows yang dibutuhkannya
target_link_libraries(AplikasiSaya PRIVATE mariadbclient ws2_32 secur32 crypt32 bcrypt Shlwapi)
# --------------------------------------------------------------------