#include "naive_db.h"


void die(const char *message)
{
    if (errno) {
        perror(message);
    } 
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(Address *addr){
    printf("\nID: %d\nSet: %d\nName: %s\nEmail: %s\n", addr->id, addr->set, addr->name, addr->email);
}

void Database_load(Connection *conn){
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    /*
    ptr − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
    size − This is the size in bytes of each element to be read.
    nmemb − This is the number of elements, each one with a size of size bytes.
    stream − This is the pointer to a FILE object that specifies an input stream.
    */
    int rc = fread(conn->db, sizeof(Database), 1, conn->file);
    if (rc != 1){
        die("Failed to load database.");
    }
}

Connection *Database_open(const char *filename, char mode){
    Connection *conn = malloc(sizeof(Connection));
    if (!conn){
        die("Memory error");
    }
    conn->db = malloc(sizeof(Database));
    if (!conn->db){
        die("Memory error");
    }

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } 
    else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file){
        die("Failed to open the file");
    }

    return conn;
}

void Database_close(Connection *conn)
{
    if (conn) {
        if (conn->file){
            fclose(conn->file);
        }

        if (conn->db){
            // free all the memory from the database
            free(conn->db);
            // db is an array of addresses
        }
        free(conn);
    }
}

void Database_write(Connection *conn)
{
    rewind(conn->file);
    //rewind() moves the file pointer back to the beginning of the file

    //write db to conn->file
    int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);
    /*
    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
        ptr − This is the pointer to the array of elements to be written.
        size − This is the size in bytes of each element to be written.
        nmemb − This is the number of elements, each one with a size of size bytes.
        stream − This is the pointer to a FILE object that specifies an output stream.
    */
    if (rc != 1){
        die("Failed to write database.");
    }
    rc = fflush(conn->file);
    /*
    Buffering works in such a way that the contents of an output buffer are only written 
    to the stdout stream or FILE object ONCE the buffer is FULL, or there is a new line 
    character at the end of it.
    */
    if (rc == -1){
        die("Cannot flush database.");
    }
}

void Database_create(Connection *conn){
    // Given an initialized Connection struct, create the empty rows and add them to the 
    // Connection struct's database
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        Address addr = {.id = i,.set = 0 };
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(Connection *conn, int id, const char *name, const char *email){
    // Set one of the rows(row id = id) in the Connection struct's database

    Address *addr = &conn->db->rows[id];
    if (addr->set){
        die("Already set, delete it first");
    }
    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    // The last character is NOT going to be \0, so when we use it, it could not end where we meant to end it
    // char *strncpy(char *dest, const char *src, size_t n)
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if (!res){
        die("Name copy failed");
    }

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res){
        die("Email copy failed");
    }
}

void Database_get(Connection *conn, int id){
    // Print one of the rows in the conn->database
    Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } 
    else {
        die("ID is not set");
    }
}

void Database_delete(Connection *conn, int id){
    // Empty the database row at the input id
    Address addr = {.id = id,.set = 0 };
    conn->db->rows[id] = addr;
}

void Database_list(Connection *conn){
    // Print all the "set" rows in the connection's database
    int i = 0;
    Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[]){
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    // c=create, g=get, s=set, d=del, l=list
    char *filename = argv[1];
    char action = argv[2][0]; // First character in the third argument passed into the command line
    Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3) {
        id = atoi(argv[3]);
    }
    if (id >= MAX_ROWS) {
        die("There's not that many records.");
    }

    switch (action) {
        // Create a database
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        // Get one of the rows from the database
        case 'g':
            if (argc != 4)
                die("Need an id to get");

            Database_get(conn, id);
            break;

        // Set one of the rows from the database requires a name and email passed into the terminal
        case 's':
            if (argc != 6)
                die("Need id, name, email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        // Delete a database row 
        case 'd':
            if (argc != 4){
                die("Need id to delete");
            }
            Database_delete(conn, id);
            Database_write(conn);
            break;

        // List or print the rows in the database
        case 'l':
            Database_list(conn);
            break;

        default:
            die("Invalid action: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}