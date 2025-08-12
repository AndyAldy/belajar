#include <iostream>
#include "../include/koneksi.h"
#include "../include/jdbc/mysql_driver.h"
#include "../include/jdbc/cppconn/exception.h"

// --- FUNGSI "MANAJER & PELAYAN" ---
int main() {
    std::cout << "Aplikasi dimulai." << std::endl;

    // Memesan koneksi dari "dapur"
    sql::Connection* con = connectToDatabase();

    // Memeriksa hasilnya dan berinteraksi dengan pengguna
    if (con) { // 'if (con)' adalah cara singkat untuk 'if (con != nullptr)'
        std::cout << "Koneksi ke database berhasil dibuat!" << std::endl;
        delete con;
        std::cout << "Koneksi ditutup." << std::endl;
    } else {
        std::cout << "Gagal menyambungkan ke database. Cek log teknis." << std::endl;
        return 1;
    }

    std::cout << "Aplikasi selesai." << std::endl;
    return 0;
}