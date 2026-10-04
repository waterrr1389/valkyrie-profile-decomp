#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"

typedef struct { s8 b[3]; } B3;
typedef struct { s8 b[4]; } B4;
typedef struct { s8 b[5]; } B5;
typedef struct { s8 b[6]; } B6;
typedef struct { s8 b[7]; } B7;
typedef struct { s8 b[8]; } B8;
typedef struct { s8 b[9]; } B9;
typedef struct { s8 b[10]; } B10;
typedef struct { s8 b[11]; } B11;
typedef struct { s8 b[12]; } B12;
typedef struct { s8 b[13]; } B13;
typedef struct { s8 b[14]; } B14;
typedef struct { s8 b[15]; } B15;
typedef struct { s8 b[16]; } B16;
typedef struct { s8 b[17]; } B17;
typedef struct { s8 b[18]; } B18;

s32 func_8001ACF8(s32 arg0, u8 *ctx, s32 size) {
    u8 *out;
    u8 *in;
    u8 *start;
    s32 nbits;
    s32 bitbuf;
    s32 i;
    s32 len;
    s32 value;
    u8 b1;
    s32 code;

    if (*(u8 *)(ctx + 0x19) != 0) {
        return 1;
    }
    out = *(u8 **)(ctx + 0xC);
    in = *(u8 **)(ctx + 0x10);
    nbits = *(s32 *)(ctx + 4);
    bitbuf = *(s32 *)(ctx + 0);
    start = out;
    while (1) {
        if (out - start >= size) {
            goto done;
        }
        if (--nbits != 0) {
            bitbuf >>= 1;
        } else {
            nbits = 8;
            bitbuf = *in++;
        }
        if (bitbuf & 1) {
            *out++ = *in++;
            continue;
        }
        b1 = in[1];
        value = in[0] | ((b1 & 0xF) << 8);
        if (value == 0) {
            *(u8 *)(ctx + 0x19) = 1;
            goto done;
        }
        code = b1 >> 4;
        len = code + 3;
        in += 2;
        if (value >= 0x10) {
            switch (code) {
            case 0:
                *(B3 *)out = *(B3 *)(out - value);
                out += 3;
                break;
            case 1:
                *(B4 *)out = *(B4 *)(out - value);
                out += 4;
                break;
            case 2:
                *(B5 *)out = *(B5 *)(out - value);
                out += 5;
                break;
            case 3:
                *(B6 *)out = *(B6 *)(out - value);
                out += 6;
                break;
            case 4:
                *(B7 *)out = *(B7 *)(out - value);
                out += 7;
                break;
            case 5:
                *(B8 *)out = *(B8 *)(out - value);
                out += 8;
                break;
            case 6:
                *(B9 *)out = *(B9 *)(out - value);
                out += 9;
                break;
            case 7:
                *(B10 *)out = *(B10 *)(out - value);
                out += 10;
                break;
            case 8:
                *(B11 *)out = *(B11 *)(out - value);
                out += 11;
                break;
            case 9:
                *(B12 *)out = *(B12 *)(out - value);
                out += 12;
                break;
            case 10:
                *(B13 *)out = *(B13 *)(out - value);
                out += 13;
                break;
            case 11:
                *(B14 *)out = *(B14 *)(out - value);
                out += 14;
                break;
            case 12:
                *(B15 *)out = *(B15 *)(out - value);
                out += 15;
                break;
            case 13:
                *(B16 *)out = *(B16 *)(out - value);
                out += 16;
                break;
            case 14:
                *(B17 *)out = *(B17 *)(out - value);
                out += 17;
                break;
            case 15:
                *(B18 *)out = *(B18 *)(out - value);
                out += 18;
                break;
            }
        } else {
            for (i = 0; i < len; i++) {
                *out = *(out - value);
                out++;
            }
        }
    }
done:
    *(u8 **)(ctx + 0xC) = out;
    *(u8 **)(ctx + 0x10) = in;
    *(s32 *)(ctx + 4) = nbits;
    *(s32 *)(ctx + 0) = bitbuf;
    return *(u8 *)(ctx + 0x19) != 0;
}


s32 func_8001B1F8(s32 arg0, u8 *ctx, s32 size) {
    u8 *out;
    u8 *in;
    u8 *start;
    u8 *end;
    s32 nbits;
    s32 bitbuf;
    s32 i;
    s32 len;
    s32 value;
    u8 b1;
    s32 code;
    s32 byte;
    s32 n;

    if (*(u8 *)(ctx + 0x19) != 0) {
        return 1;
    }
    out = *(u8 **)(ctx + 0xC);
    in = *(u8 **)(ctx + 0x10);
    end = *(u8 **)(ctx + 0x14);
    nbits = *(s32 *)(ctx + 4);
    bitbuf = *(s32 *)(ctx + 0);
    start = out;
    while (1) {
        if (out >= end) {
            goto done;
        }
        if (out - start >= size) {
            goto done;
        }
        if (--nbits != 0) {
            bitbuf >>= 1;
        } else {
            nbits = 8;
            bitbuf = *in++;
        }
        if (bitbuf & 1) {
            *out++ = *in++;
            continue;
        }
        b1 = in[1];
        value = in[0] | ((b1 & 0xF) << 8);
        code = b1 >> 4;
        len = code + 3;
        if (len < 18) {
            if (value >= 0x10) {
                switch (code) {
                case 0:
                    *(B3 *)out = *(B3 *)(out - value);
                    out += 3;
                    break;
                case 1:
                    *(B4 *)out = *(B4 *)(out - value);
                    out += 4;
                    break;
                case 2:
                    *(B5 *)out = *(B5 *)(out - value);
                    out += 5;
                    break;
                case 3:
                    *(B6 *)out = *(B6 *)(out - value);
                    out += 6;
                    break;
                case 4:
                    *(B7 *)out = *(B7 *)(out - value);
                    out += 7;
                    break;
                case 5:
                    *(B8 *)out = *(B8 *)(out - value);
                    out += 8;
                    break;
                case 6:
                    *(B9 *)out = *(B9 *)(out - value);
                    out += 9;
                    break;
                case 7:
                    *(B10 *)out = *(B10 *)(out - value);
                    out += 10;
                    break;
                case 8:
                    *(B11 *)out = *(B11 *)(out - value);
                    out += 11;
                    break;
                case 9:
                    *(B12 *)out = *(B12 *)(out - value);
                    out += 12;
                    break;
                case 10:
                    *(B13 *)out = *(B13 *)(out - value);
                    out += 13;
                    break;
                case 11:
                    *(B14 *)out = *(B14 *)(out - value);
                    out += 14;
                    break;
                case 12:
                    *(B15 *)out = *(B15 *)(out - value);
                    out += 15;
                    break;
                case 13:
                    *(B16 *)out = *(B16 *)(out - value);
                    out += 16;
                    break;
                case 14:
                    *(B17 *)out = *(B17 *)(out - value);
                    out += 17;
                    break;
                }
            } else {
                for (i = 0; i < len; i++) {
                    *out = *(out - value);
                    out++;
                }
            }
        } else {
            byte = value & 0xFF;
            if (value < 0x100) {
                byte = in[2];
                n = value + 19;
                in++;
            } else {
                n = (value >> 8) + 3;
            }
            byte = byte | (byte << 8);
            if ((s32)out & 1) {
                *out++ = (u8)byte;
                if (n & 1) {
                    i = 1;
                    while (i < n) {
                        *(u16 *)out = (u16)byte;
                        out += 2;
                        i += 2;
                    }
                } else {
                    i = 1;
                    while (i < n - 1) {
                        *(u16 *)out = (u16)byte;
                        out += 2;
                        i += 2;
                    }
                    if (i < n) {
                        *out++ = (u8)byte;
                    }
                }
            } else {
                i = 0;
                while (i < n - 1) {
                    *(u16 *)out = (u16)byte;
                    out += 2;
                    i += 2;
                }
                if (i < n) {
                    *out++ = (u8)byte;
                }
            }
        }
        in += 2;
    }
done:
    *(u8 **)(ctx + 0xC) = out;
    *(u8 **)(ctx + 0x10) = in;
    *(s32 *)(ctx + 4) = nbits;
    *(s32 *)(ctx + 0) = bitbuf;
    if (out >= *(u8 **)(ctx + 0x14)) {
        *(u8 *)(ctx + 0x19) = 1;
        return 1;
    }
    return 0;
}
