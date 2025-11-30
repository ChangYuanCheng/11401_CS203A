/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // hash = (key * 2654435761) >> 16
    // 這樣可以讓數值分佈較平均
    unsigned int k = static_cast<unsigned int>(key);
    unsigned int hash = k * 2654435761u;
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
   {
        // 正常版本 (DJB2 字串 hash)
        // 從 5381 開始，對每個字元做 hash = hash * 33 + c
        unsigned long h = 5381;
        for (unsigned char c : str) 
        h = h * 33 + c;
    }
        
    return static_cast<int>(hash % m);  // basic division method
}
