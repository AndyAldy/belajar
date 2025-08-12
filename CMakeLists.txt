# Tentukan versi minimum CMake yang dibutuhkan
cmake_minimum_required(VERSION 3.10)

# Definisikan nama proyek Anda
project(BelajarCPP VERSION 1.0)

# Atur standar C++ yang akan digunakan (misalnya C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tentukan lokasi folder output untuk file .exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Daftarkan semua file .cpp di dalam folder src secara otomatis
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Buat program executable bernama "AplikasiSaya" dari semua file sumber
add_executable(AplikasiSaya ${SOURCES})

# Beritahu CMake di mana harus mencari file header (.h)
# Ini akan menambahkan folder 'include' ke dalam search path
target_include_directories(AplikasiSaya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Beritahu CMake di mana harus mencari file library (.lib)
# Berdasarkan file Anda, library-nya ada di dalam lib64/vs14
target_link_directories(AplikasiSaya PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib64/vs14)

# Tautkan (link) library yang dibutuhkan oleh program Anda
# Kita akan menautkan library statis MySQL dan library SSL/Crypto yang menjadi dependensinya
target_link_libraries(AplikasiSaya PRIVATE mysqlcppconn-static libssl libcrypto)