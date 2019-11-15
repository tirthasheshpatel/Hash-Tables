#ifndef GUARD_HASHING_H
#define GUARD_HASHING_H

/*
 * @author: tirthasheshpatel
 * @e-mail: tirthasheshpatel@gmail.com
 * Summary: Implemented hash tables and resolved
 *          collisions using (primarily) chaining
 *          and open addressing.
 */

// Including necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining `M` which is the number of slots 
// in our hash table. Because we extract a
// 14-bit least significant bits of the hashed
// key, the maximum size of the slots, hash
// function would hash to, becomes 2^14.
#define M 16385

// The constant A which is used to perform
// hash by multiplication method is defined
// as `PHI` (conjugate of the golden number) 
// as stated in Knuth(2003) and cited in the
// book `Introduction to Algorithms` Section 11.3
#define PHI 0.6180339887

// Making the `size_t` keyword easier to interpret.
typedef size_t size_type;

size_type hash_by_division_method(size_type);
size_type hash_by_multiplication_method(size_type);

/**
 * Arguments
 * ---------
 * `key` (size_type) -> A integer key to be hashed.
 * ---------
 * 
 * Hashes the given key using the division method for hashing.
 * A function to find the Hash Code of a integer key
 * using the division method.
 * 
 * h(k) = k modulo m;
 * 
 * where m is the size of the hash table.
 * 
 * Returns
 * -------
 * (size_type)       -> Hashed key.
 * -------
 */
size_type hash_by_division_method(size_type key)
{
	return key%M;
}

// A function to find the hash code of the
// key using multiplication method proposed
// in the book `Introduction to algorithms`.
/**
 * Arguments
 * ---------
 * `key` (size_type) -> A integer key to be Hashed.
 * ---------
 * 
 * Hashes and returns the entered key using the multiplication method.
 * 
 * Returns
 * -------
 * hash_code (size_type) -> 14-bit Hash Code of the given key.
 * -------
 */
size_type hash_by_multiplication_method(size_type key)
{
    // Set the bit-width 32 because at the end
    // we are going to multiply two 32 bit integers
    // to get a 64 bit long integer. Using 64 bit 
    // integer may lead to possible loss of data.
    long long w = 4294967296; // Bit-width w = 2^32

    // Now, we have a constant A = PHI, that we 
    // need to convert in the form ` s / w `
    // such that `s` is the nearest integer that can
    // be represented as ` A * w `. As
    // `A = PHI`, we have `s = floor(PHI * w)`.
    // Then, we multiply the key with obtained `s`
    // => `l = key * s`
    // Now, we have `l = w * r1 + r0` where
    // `r0` is the fractional part of `l`.
    // We extract 14 most significant bits of `r0` 
    // to get our 14 bit hash key.
    return  ( ( ( (size_type)fmod((key*floor(PHI*w)),w) ) >> (32-14) ) );
}

#endif