#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
}Address;


typedef struct{
    struct Address rows[MAX_ROWS];
}Database;

typedef struct{
    FILE *file;
    struct Database *db;
}Connection;
