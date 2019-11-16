/*
 * @author: tirthasheshpatel
 * @e-mail: tirthasheshpatel@gmail.com
 * Summary: Implemented hash tables and resolved
 *          collisions using (primarily) chaining
 *          and open addressing.
 */

#ifndef GUARD_BACKEND_H
#define GUARD_BACKEND_H


// Including necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashing.h"
#include "lil.h"
#include "open_addressing.h"

/**
 * Arguments
 * ---------
 * `table` (list_iterator)  -> A hash table with slots M.
 * `key`   (size_type)      -> A key to be stored in the table.
 * `value` (int)            -> Value to be stored at the key.
 * `raw_key` (conost char*) -> Key as string to be inserted.
 * ---------
 * Stores the entered key into the hash table in O(1) time.
 * The hash table resolves collisions through `Chaining` and `Open Addressing`.
 * The keys are stored in a doubly linked list.
 */
list_iterator* insert_in_hash_table(list_iterator *table, size_type key, int value, const char raw_key[])
{
    // Check if key to be stored is valid.
    if(key <= 0)
    {
        printf("NegativeKeyError: \tThe value of key can't be negative\n");
        printf("\t\tfound: %lu < 0\n", key);
        printf("\t\t [backend: encountered during insertion]\n");
        return table;
    }

    // Find the 14-bit hash code of the key `key` using multiplication method.
    size_type hash = hash_by_multiplication_method(key);

    // The hash code of the key is now our new key or the 
    // index where the original key is to be stored
    // in the hash tables.
    if(table[hash]->key == -1) // Check if the slot is empty
    {
        // If empty, store the key in the first node of the doubly linked list.
        table[hash]->key = key;
        strcpy(table[hash]->raw_key, raw_key);
        table[hash]->value = value;
        table[hash]->next = 0; // No next and previous node is present.
        table[hash]->prev = 0;
        return table;
    }

    // If the slot is not empty, add a node to the list and store the key there.
    table[hash] = insert_in_front_of_the_doubly_linked_list(table[hash], key, value, raw_key);
    return table;
}


// Delete a key from the slot of the table in a average-case time O(ALPHA)
// where ALPHA = load factor = N/M. N = No of keys to be inserted, M = Slots present.
list_iterator* delete_from_hash_table(list_iterator *table, size_type key)
{
    // Find the hash code of a key `key` using Multiplication Method.
    size_type hash = hash_by_multiplication_method(key);
    // Delete element from the doubly linked
    // list present at the hashed slot.
    // This function runs in linear time by first searching
    // for the key and deleting the found node if any.
    table[hash] = delete_from_the_doubly_linked_list(table[hash], key);
    return table;
}

/**
 * Arguments
 * ---------
 * `table`   (list_iterator) -> An object of Hash Table.
 * `key`     (size_type)     -> A key to be stored in the hash table.
 * ---------
 * 
 * Hashes the key and searches for the original key in the hashed slot
 * using search function of doubly linked list. Searches for a key in the 
 * hash table in linear time.
 * 
 * Returns
 * -------
 * `element` (list_iterator) -> The found node where the key is present.
 * -------
 */
list_iterator search_in_hash_table(list_iterator *table, size_type key)
{
    // Hash the key.
    size_type hash = hash_by_multiplication_method(key);
    // Search in the doubly linked list from the start.
    list_iterator element = search_from_start_in_the_doubly_linked_list(table[hash], key);
    return element; // return element if found otherwise return empty pointer.
}

void display_hash_table(list_iterator* table)
{
    printf("{");
    for(int i=0;i<M;i++)
    {
        list_iterator temp = table[i];
        while(temp != 0)
        {
            if(temp->key == -1)
            {
                temp = temp->next;
                continue;
            }
            printf("'%s': %d, ", temp->raw_key, temp->value);
            temp = temp->next;
        }
    }
    printf("}\n");
}

/**
 * Arguments
 * ---------
 * `key` (const char*)   -> A character array to be converted to int
 * ---------
 * 
 * Converts an array of characters to integer using policy
 * `i * key[i]`.
 * 
 * Returns
 * -------
 * `int_key` (size_type)    -> A integer representation of the key
 * -------
 */
size_type string_to_int(const char key[])
{
    size_type length = strlen(key);
    size_type int_key = 0;
    for(int i=length-1;i>=0;i--)
    {
        int_key += ((size_type)(pow(2, i)))*((size_type)key[i]);
    }
    return int_key;
}


#endif