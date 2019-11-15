#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_table.h"

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    Table* table = 0;
    table = insert(table, "sunidhi", 10);
    table = insert(table, "tirth", 20);
    table = insert(table, "shreyanshi", 0);
    table = insert(table, "vansh", 30);
    display(table);
    table = _delete(table, "tirth");
    display(table);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("\n\nProgram terminated in %0.10lf milliseconds\n\n", cpu_time_used);
}