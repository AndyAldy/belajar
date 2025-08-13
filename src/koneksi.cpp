#include "../include/koneksi.h"
#include <iostream>

const char* DB_HOST = "127.0.0.1";
const char* DB_USER = "root";
const char* DB_PASS = "andyaldy0904";
const char* DB_NAME = "db_belajarcpp";
const unsigned int DB_PORT = 3306;

MYSQL* connectToDatabase() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        std::cerr << "mysql_init() gagal" << std::endl;
        return NULL;
    }

    // Coba koneksi ke database.
    // Parameter: connection, host, user, password, database, port, unix_socket, client_flag
    if (mysql_real_connect(con, DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT, NULL, 0) == NULL) {
        std::cerr << "mysql_real_connect() gagal: " << mysql_error(con) << std::endl;
        mysql_close(con);
        return NULL;
    }

    return con;
}       return NULL;