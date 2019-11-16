#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "hash_table.h"

using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

int main(int argc, char* argv[])
{
    Table* table = 0;
    // double* ins = (double*)calloc(1000000, sizeof(double));
    FILE* ins = fopen("insert_time.csv", "w");
    fputs("iteration,time(nanoseconds)\n", ins);
    table = init_table(table);
    double cpu_time_used;

    /**
     * Test 1: Average Time taken to insert 1M keys.
     */
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    long long time_taken = (long long)duration_cast<nanoseconds>(end-start).count();
    for(long long i=0;i<1000000;i++)
    {
        char buffer[33];
        itoa(i, buffer, 2);
        if(i%1000 == 500) start = high_resolution_clock::now();
        table = insert(table, buffer, i);
        if(i%1000 == 0 && i!=0)
        {
            end = high_resolution_clock::now();
            time_taken = (long long)duration_cast<nanoseconds>(end-start).count();
            fprintf(ins, "%lld,%lld\n", i/1000, time_taken);
        }
    }
    fclose(ins);

    FILE* srh = fopen("search_time.csv", "w");
    fputs("iteration,time(nanoseconds)\n", srh);
    /**
     * Test 2: Searching 1M elements in the table.
     */
    for(long long i=0;i<1000000;i++)
    {
        char buffer[33];
        itoa(i, buffer, 2);
        if(i%1000 == 500) start = high_resolution_clock::now();
        search(table, buffer);
        if(i%1000 == 0 && i!=0)
        {
            end = high_resolution_clock::now();
            time_taken = (long long)duration_cast<nanoseconds>(end-start).count();
            fprintf(srh, "%lld,%lld\n", i/1000, time_taken);
        }
    }
    fclose(srh);

    FILE* del = fopen("delete_time.csv", "w");
    fputs("iteration,time(nanoseconds)\n", del);
    /**
     * Test 3: Deleting 1M elements from the table
     */
    for(long long i=0;i<1000000;i++)
    {
        char buffer[33];
        itoa(i, buffer, 2);
        if(i%1000 == 500) start = high_resolution_clock::now();
        table = _delete(table, buffer);
        if(i%1000 == 0 && i!=0)
        {
            end = high_resolution_clock::now();
            time_taken = (long long)duration_cast<nanoseconds>(end-start).count();
            fprintf(del, "%lld,%lld\n", i/1000, time_taken);
        }
    }
    fclose(del);
}