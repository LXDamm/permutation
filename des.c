//
// Created by kvasarnomad on 5/15/21.
//

#include <inttypes.h>
#include <stdio.h>
#include "des.h"

const uint8_t IP[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
};

const uint8_t IP_INVERSE[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25
};

DesBlock new_block(uint64_t data) {
    DesBlock block;
    block.data = data;
    return block;
}

DesBlock permutation(DesBlock src_block, uint8_t p[64]) {
    DesBlock des_block = { 0x0 };
    uint8_t src_lsb_shift;
    uint64_t src_lsb_bit;
    for (uint8_t i = 0; i < 64; i++) {
        src_lsb_shift = IP[i] - 1;
        src_lsb_bit = (src_block.data >> src_lsb_shift) & 0b1;
        des_block.data = des_block.data | (uint64_t)src_lsb_bit << i;
    }
    return des_block;
}

DesBlock ip(DesBlock message_block) {
    return permutation(message_block, IP);
}

DesBlock ip_inverse(DesBlock message_block) {
    return permutation(message_block, IP_INVERSE);
}