#include <stdio.h>
#include <inttypes.h>

#include "des.h"


int main() {
    /*DesBlock message_block = new_block(0b0000000100100011010001010110011110001001101010111100110111101111);
    DesBlock ip_block = ip(message_block);
    DesBlock ip_inverse_block = ip_inverse(ip_block);*/
    uint8_t _ip[8] = {
            1, 2, 3, 4, 5, 6, 7, 8
    };
    uint8_t ip[64] = {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
    };
    uint64_t src_message = 0x0123456789ABCDEF;
    uint64_t des_message = 0x00;

    uint8_t src_lsb_shift;
    uint8_t src_lsb_bit;

    printf("%" PRIx64 "\n", src_message);
    for (uint8_t i = 0; i < 64; i++) {
        src_lsb_shift = ip[i] - 1;
        src_lsb_bit = (src_message >> src_lsb_shift) & 0b1;
        des_message = des_message | (uint64_t)src_lsb_bit << i;
    }
    printf("%" PRIx64 "\n", des_message);
    return 0;
}
