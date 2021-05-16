//
// Created by kvasarnomad on 5/15/21.
//

#pragma once

#include <stdint.h>

typedef struct DesBlock {
    uint64_t data;
} DesBlock;

DesBlock new_block(uint64_t data);
DesBlock permutation(DesBlock block, uint8_t p[64]);
DesBlock ip(DesBlock message_block);
DesBlock ip_inverse(DesBlock message_block);
