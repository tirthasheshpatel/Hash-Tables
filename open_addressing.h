#ifndef GUARD_OPEN_ADDRESSING_H
#define GUARD_OPEN_ADDRESSING_H

#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

// Making the `size_t` keyword easier to interpret.
typedef size_t size_type;

size_type open_address_linear_probing(size_type, size_type);
size_type open_address_quadratic_probing(size_type, size_type);
size_type open_address_double_hashing(size_type, size_type);

// A function to find Hash Code of the key
// using linear probing. Used by hash tables
// in which collision is resolved by open addressing.
size_type open_address_linear_probing(size_type key, size_type probe)
{
    /*
     * Arguments: `key`   (size_type) -> Key to be hashed
     *            `probe` (size_type) -> Probe number assigned to the key.
     * Hashes the provided key using Linear Probing method
     * used to resolve collisions in hash tables using 
     * open addressing. The equation used to hash the key is:
     * `h(k) = ( h'(k) + probe ) modulo `M` where `k` = key
     * `h` = hash function, `h'` = other hash function, `M` = slots in the hash table
     * and `probe` = probe number of key `k`.
     * Returns:           (size_type) -> Hash Code of key.
     */
    return (hash_by_multiplication_method(key) + probe)%M;
}

// A function to find the hash code of a key
// using Quadratic Probing. Used by hash tables
// in which collision is resolved through
// open addressing.
size_type open_address_quadratic_probing(size_type key, size_type probe)
{
    /*
     * Arguments: `key`   (size_type) -> Key to be hashed.
     *            `probe` (size_type) -> Probe number assigned to the key.
     * Hashes the provided key using Quadratic Probing method
     * used to resolve collisions in hash tables using
     * open addressing. The equation used to hash the key is:
     * `h(k) = ( h'(k) + a*(probe) + b*(probe^2)) modulo M`
     * where `M` = Slots in the table, `k` = Key to be hashed,
     * `h'` = hash function, `a` and `b` = arbitary constants,
     * `probe` = Probe number of key `k`.
     * Returns:          (size_type) -> Hash Code of the key.
     */
    return (hash_by_multiplication_method(key) + 4*probe + 5*probe*probe)%M;
}

// A function to find the hash of a key
// using Double Hashing method used to 
// resolve the collisions in hash tables.
size_type open_address_double_hashing(size_type key, size_type probe)
{
    /*
     * Arguments: `key`   (size_type) -> Key to be hashed.
     *            `probe` (size_type) -> Probe number assigned to the key.
     * Hashes the provided key using two other hash functions
     * used to resolve collisions by providing the property of
     * almost random behaviour. It is used in hash tables
     * using Open Addressing to resolve collisions.
     * Returns:           (size_type) -> Hash Code of the key.
     */
    return ( hash_by_multiplication_method(key) + probe*hash_by_division_method(key) )%M;
}

#endif