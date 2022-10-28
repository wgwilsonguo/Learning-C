#include "naive_db.h"



// Helper function to print out errors:
void die(const char *message){
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

void print_address(Address *input_address){
    printf("ID: %d\nSet: %d\nName: %s\nEmail: %s", input_address->id, input_address->set, input_address->name, input_address->email);
}

void database_load(Connection *conn){
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    /*
    ptr − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.

    size − This is the size in bytes of each element to be read.

    nmemb − This is the number of elements, each one with a size of size bytes.

    stream − This is the pointer to a FILE object that specifies an input stream.
    */
    int rc = fread(conn->db, sizeof(Connection), 1, conn->file);
    if (rc != 1)
        die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file");

    return conn;
}


















