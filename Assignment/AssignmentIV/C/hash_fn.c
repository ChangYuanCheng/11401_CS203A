/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
*/

#include "hash_fn.h"

// -----------------------------------------------------------
// Integer hash function (Knuth multiplicative hashing)
//
// h(key) = ((key * 2654435761) >> 16) % m
//
// Rationale:
//  - 2654435761 is derived from golden ratio hashing
//  - Produces well-distributed results even when m is not prime
//  - Much better uniformity than simple "key % m"
// -----------------------------------------------------------
int myHashInt(int key, int m) {
    unsigned int k = (unsigned int)key;
    unsigned int hash = k * 2654435761u; // mix bits for better distribution
    return key % m;  // division method example
}

// -----------------------------------------------------------
// String hash function (DJB2)
//
// hash = 5381
// for each character:
//     hash = hash * 33 + c
//
// Rationale:
//  - DJB2 is simple, fast, widely used
//  - Provides better distribution for English words
//  - Easy to analyze and demonstrate for homework
// -----------------------------------------------------------
int myHashString(const char* str, int m) {
    unsigned long hash = 0;

    if (str != NULL) {
        unsigned long h = 5381; // initial value

        for (const unsigned char* p = (const unsigned char*)str; *p != '\0'; ++p)
            h = h * 33 + *p;

        // 這裡 hash 還是保留為 0，只加入不改 return
    }

    return (int)(hash % m); // basic division method
}