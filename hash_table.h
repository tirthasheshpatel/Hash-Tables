#ifndef GUARD_HASH_TABLE_H
#define GUARD_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "backend.h"

Table* init_table(Table*);
Table* insert(Table*, const char*, int);
Table* _delete(Table*, const char*);
int search(Table*, const char*);
void update(Table*, const char*, int);
void display(Table* table);

typedef struct _hash_table
{
    list_iterator *slots;
    int size;
}Table;

Table* init_table(Table* table)
{
    if(0 == table)
    {
        table = (Table*)malloc(sizeof(Table));
        table->size = 0;
        table->slots = (list_iterator*)malloc(M*sizeof(list_iterator));
        for(int i=0;i<M;i++)
        {
            table->slots[i] = (list_iterator)malloc(sizeof(struct Node));
            // printf("Node allocated\n");
            table->slots[i]->key = -1;
            table->slots[i]->next = 0;
            table->slots[i]->prev = 0;
            strcpy(table->slots[i]->raw_key, "");
            table->slots[i]->value = -1;
        }
    }
    return table;
}

Table* insert(Table* table, const char key[], int value)
{
    if(0 == table) table = init_table(table);
    size_type int_key = string_to_int(key);
    list_iterator temp = search_in_hash_table(table->slots, int_key);
    if(temp!=0)
    {
        printf("Key already present in the table!\n");
        return table;
    }
    table->slots = insert_in_hash_table(table->slots, int_key, value, key);
    table->size++;
    return table;
}

Table* _delete(Table* table, const char key[])
{
    if(0 == table) return table;
    size_type int_key = string_to_int(key);
    table->slots = delete_from_hash_table(table->slots, int_key);
    table->size--;
    return table;
}

int search(Table* table, const char key[])
{
    if(0 == table)
    {
        printf("Table empty!");
        exit(1);
    }
    size_type int_key = string_to_int(key);
    list_iterator element = search_in_hash_table(table->slots, int_key);
    if(element == 0)
    {
        printf("%s not found\n", key);
        return INT_MIN;
    }
    return element->value;
}

void update(Table* table, const char key[], int new_value)
{
    // Not implemented yet!
    return;
}

void display(Table* table)
{
    display_hash_table(table->slots);
}

#endif