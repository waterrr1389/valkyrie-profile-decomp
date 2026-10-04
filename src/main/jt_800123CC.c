#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"

typedef struct { u8 b[3]; } U3;
typedef struct { u8 b[4]; } U4;
typedef struct { u8 b[5]; } U5;
typedef struct { u8 b[6]; } U6;
typedef struct { u8 b[7]; } U7;
typedef struct { u8 b[8]; } U8;
typedef struct { u8 b[9]; } U9;
typedef struct { u8 b[10]; } U10;
typedef struct { u8 b[11]; } U11;
typedef struct { u8 b[12]; } U12;
typedef struct { u8 b[13]; } U13;
typedef struct { u8 b[14]; } U14;
typedef struct { u8 b[15]; } U15;
typedef struct { u8 b[16]; } U16;
typedef struct { u8 b[17]; } U17;
typedef struct { u8 b[18]; } U18;

s32 func_800123CC(u8 *unused, u8 *src, u8 *dst) {
    s32 bits;
    s32 nbits;
    s32 i;
    s32 cmd;
    s32 dist;
    s32 len;

    bits = 0;
    nbits = 1;
    for (;;) {
        nbits--;
        bits >>= 1;
        if (nbits == 0) {
            nbits = 8;
            bits = *src++;
        }
        if (bits & 1) {
            *dst++ = *src++;
            continue;
        }
        dist = src[0] | ((src[1] & 0xF) << 8);
        if (dist == 0) {
            break;
        }
        cmd = src[1] >> 4;
        len = cmd + 3;
        if (dist >= 0x10) {
            switch (cmd) {
            case 0:
                *(U3 *)dst = *(U3 *)(dst - dist);
                dst += 3;
                break;
            case 1:
                *(U4 *)dst = *(U4 *)(dst - dist);
                dst += 4;
                break;
            case 2:
                *(U5 *)dst = *(U5 *)(dst - dist);
                dst += 5;
                break;
            case 3:
                *(U6 *)dst = *(U6 *)(dst - dist);
                dst += 6;
                break;
            case 4:
                *(U7 *)dst = *(U7 *)(dst - dist);
                dst += 7;
                break;
            case 5:
                *(U8 *)dst = *(U8 *)(dst - dist);
                dst += 8;
                break;
            case 6:
                *(U9 *)dst = *(U9 *)(dst - dist);
                dst += 9;
                break;
            case 7:
                *(U10 *)dst = *(U10 *)(dst - dist);
                dst += 10;
                break;
            case 8:
                *(U11 *)dst = *(U11 *)(dst - dist);
                dst += 11;
                break;
            case 9:
                *(U12 *)dst = *(U12 *)(dst - dist);
                dst += 12;
                break;
            case 10:
                *(U13 *)dst = *(U13 *)(dst - dist);
                dst += 13;
                break;
            case 11:
                *(U14 *)dst = *(U14 *)(dst - dist);
                dst += 14;
                break;
            case 12:
                *(U15 *)dst = *(U15 *)(dst - dist);
                dst += 15;
                break;
            case 13:
                *(U16 *)dst = *(U16 *)(dst - dist);
                dst += 16;
                break;
            case 14:
                *(U17 *)dst = *(U17 *)(dst - dist);
                dst += 17;
                break;
            case 15:
                *(U18 *)dst = *(U18 *)(dst - dist);
                dst += 18;
                break;
            }
        } else {
            for (i = 0; i < len; i++) {
                *dst = *(dst - dist);
                dst++;
            }
        }
        src += 2;
    }
    return 1;
}
