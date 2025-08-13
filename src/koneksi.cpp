#include "../include/koneksi.h"
#include <iostream>

MYSQL* connectToDatabase() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        std::cerr << "mysql_init() gagal" << std::endl;
        return NULL;
    }

    // Coba koneksi ke database.
    // Parameter: connection, host, user, password, database, port, unix_socket, client_flag
    if (mysql_real_connect(con, "127.0.0.1", "root", "andyaldy0904", "db_belajarcpp", 3306, NULL, 0) == NULL) {
        std::cerr << "mysql_real_connect() gagal: " << mysql_error(con) << std::endl;
        mysql_close(con);
        return NULL;
    }

    return con;
}