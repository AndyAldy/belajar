#ifndef KONEKSI_H
#define KONEKSI_H

// Kita perlu menyertakan header dari MySQL Connector di sini
// karena kita akan menggunakan tipe data 'sql::Connection'
#include "jdbc/cppconn/connection.h"

// Deklarasi fungsi "koki" kita.
// Ini adalah janji bahwa di suatu tempat akan ada fungsi
// bernama connectToDatabase yang akan mengembalikan pointer sql::Connection.
sql::Connection* connectToDatabase();

#endif // KONEKSI_H