#include <iostream>
#include <stdexcept>

// Sertakan "kontrak" kita sendiri
#include "../include/koneksi.h"

// Sertakan header dari MySQL Connector yang dibutuhkan untuk implementasi
#include "../include/jdbc/mysql_driver.h"
#include "../include/jdbc/cppconn/exception.h"

// --- IMPLEMENTASI FUNGSI "KOKI" ---
// Ini adalah kode yang sama persis seperti sebelumnya,
// tapi sekarang berada di file terpisah.
sql::Connection* connectToDatabase() {
    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "andy", "andyaldy0904");
        con->setSchema("db_belajarcpp");

        return con;

    } catch (sql::SQLException &e) {
        std::cerr << "# KESALAHAN TEKNIS: " << e.what();
        std::cerr << " (MySQL error code: " << e.getErrorCode();
        std::cerr << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        return nullptr;
    }
}