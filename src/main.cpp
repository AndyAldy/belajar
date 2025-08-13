#include "../include/koneksi.h"
#include <iostream>

int main() {
    std::cout << "Aplikasi dimulai." << std::endl;

    if (mysql_library_init(0, NULL, NULL)) {
        std::cerr << "Tidak bisa menginisialisasi library MariaDB" << std::endl;
        mysql_library_end();
        return 1;
    }

    MYSQL* con = connectToDatabase();

    if (con) {
        std::cout << "Koneksi ke database berhasil!" << std::endl;
        mysql_close(con);
    } else {
        std::cout << "Gagal menyambungkan ke database." << std::endl;
    }

    mysql_library_end();
    std::cout << "Aplikasi selesai." << std::endl;
    return 0;
}