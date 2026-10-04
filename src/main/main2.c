#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"


void func_80015294(u8 *arg0) {
    s32 a0;
    s32 v0;
    s32 prod1;
    s32 prod2;
    s32 q1;
    s32 q2;

    v0 = *(s8 *)(arg0 + 0x5A);
    a0 = *(u8 *)(arg0 + 0x53);
    a0 += (a0 * (v0 < 0 ? v0 << 9 : v0 << 10)) >> 16;
    v0 = *(s8 *)(arg0 + 0x12);
    a0 += (a0 * (v0 < 0 ? v0 << 9 : v0 << 10)) >> 16;
    if (a0 >= 0xF1) {
        a0 = 0xF0;
    }
    *(u8 *)(arg0 + 0x5B) = a0;
    if (a0 < 0x50) {
        a0 <<= 1;
        if (a0 < 0x50) {
            a0 <<= 1;
        }
    }
    q2 = 0x7735940 / (a0 * 0x18D4);
    *(s32 *)(arg0 + 0x323C) = q2;
    q1 = 0x7735940 / (a0 * 0x18);
    *(u16 *)(arg0 + 0x58) = q1;
    SetRCnt(0xF2000002, q1 & 0xFFFF, 0x1000);
}


void func_80015398(u8 *arg0) {
    u32 b;
    u32 q;
    u32 cur;
    u32 mask;
    u32 key;
    u32 off;
    s32 v;
    s32 n;
    s32 k;

    if (*(u8 *)(arg0 + 0x87) == 0) {
        if (SpuStGetVoiceStatus() == 0) {
            *(s32 *)(arg0 + 0x3260) = 0;
        }
        do {
            n = *(s32 *)(arg0 + 0x2C) + 1;
            *(u16 *)(arg0 + 0x3238) = 0;
            *(s32 *)(arg0 + 0x3250) = 0;
            *(s32 *)(arg0 + 0x3254) = 0;
            *(s32 *)(arg0 + 0x2C) = n;
            func_80015754(arg0);
            q = *(u32 *)(arg0 + 0x54) + *(u16 *)(arg0 + 0x58);
            *(u32 *)(arg0 + 0x54) = q;
            if (q > 0xFE4F) {
                *(u32 *)(arg0 + 0x54) = q + 0xFFFF01B0;
                *(u16 *)(arg0 + 0x3238) = 2;
            }
            if (*(u32 *)(arg0 + 0x40) & 1) {
                b = *(u8 *)(arg0 + 0x5B);
                if (b < 0x50) {
                    if (b < 0x28) {
                        v = *(s32 *)(arg0 + 0x2C) & 3;
                    } else {
                        v = *(s32 *)(arg0 + 0x2C) & 1;
                    }
                    if (v != 0) {
                        goto skip_inc;
                    }
                }
                *(u16 *)(arg0 + 0x3238) = *(u16 *)(arg0 + 0x3238) + 1;
            }
        skip_inc:
            v = *(u8 *)(arg0 + 0x10DE);
            if (v != 0) {
                *(u8 *)(arg0 + 0x10DE) = v - 1;
            }
            v = *(s16 *)(arg0 + 0x3238);
            if (v != 0) {
                if (*(s16 *)(arg0 + 0x3238) & 2) {
                    if (*(u8 *)(arg0 + 0x10DC) != 0) {
                        k = *(s32 *)(arg0 + 0x8C) + 1;
                        *(s32 *)(arg0 + 0x8C) = k;
                        if (k >= 0xC1) {
                            *(u8 *)(arg0 + 0x10DC) = 0;
                        }
                    } else {
                        *(s32 *)(arg0 + 0x8C) = 0;
                    }
                    *(u16 *)(arg0 + 0x323A) = 0x800;
                    func_800188BC(arg0);
                    func_80016F40(arg0, arg0 + 0x64, 0x18, 0x20);
                    func_80016F40(arg0, arg0 + 0x6C, 0, 0x18);
                    func_80016F40(arg0, arg0 + 0x5C, 0, 0x18);
                }
                if (*(u16 *)(arg0 + 0x3238) & 1) {
                    *(u16 *)(arg0 + 0x323A) = 0;
                    *(u16 *)(arg0 + 0x82) = *(u16 *)(arg0 + 0x82) + 1;
                }
                func_80015C1C(arg0);
                func_80015608(arg0);
                SpuSetKey(0, *(s32 *)(arg0 + 0x3254));
                func_8001711C(arg0);
                func_80014948(arg0);
            } else {
                SpuSetKey(0, *(s32 *)(arg0 + 0x3254));
            }
            cur = *(u32 *)(arg0 + 0x3250);
            mask = cur & *(u32 *)(arg0 + 0x3254);
            off = cur & ~mask;
            *(u32 *)(arg0 + 0x3250) = off;
            key = off | *(u32 *)(arg0 + 0x3258);
            *(u32 *)(arg0 + 0x3250) = key;
            SpuSetKey(1, key);
            *(u32 *)(arg0 + 0x3258) = mask;
            n = *(u16 *)(arg0 + 0x3242) - 1;
            *(u16 *)(arg0 + 0x3242) = n;
        } while ((s16)n != -1);
        *(u16 *)(arg0 + 0x3242) = 0;
    }
}


void func_80015608(u8 *arg0) {
    s32 i;
    s32 n;
    s32 end;
    u8 *p;
    u8 *q;
    u32 t;
    u8 v2;
    s32 v;

    switch (*(s16 *)(arg0 + 0x3238)) {
    case 1:
        i = 0;
        end = 0x18;
        break;
    case 2:
        i = 0x18;
        end = 0x20;
        break;
    default:
        i = 0;
        end = 0x20;
        break;
    }
    n = i;
    if (n < end) {
        do {
            p = arg0 + n * 0x58;
            if (*(s8 *)(p + 0xB6) != 0) {
                t = *(u8 *)(p + 0xBB);
                t += *(u8 *)(p + 0xDE);
                *(u8 *)(p + 0xBB) = t;
                if ((t & 0xFF) >= 0x40) {
                    *(u8 *)(p + 0xBB) = t - 0x40;
                }
                v = *(u8 *)(p + 0xBA);
                *(s32 *)(p + 0xB0) = 0;
                if (v == 0 || (v = v - 1, *(u8 *)(p + 0xBA) = v, (v & 0xFF) == 0)) {
                    q = p;
                loop:
                    if (*(s8 *)(q + 0xB6) != 0) {
                        func_80015D18(arg0, n);
                        if (*(u8 *)(q + 0xBA) == 0) {
                            goto loop;
                        }
                    }
                }
                *(s32 *)(p + 0xAC) = *(s32 *)(p + 0xAC) + *(s32 *)(p + 0xB0);
                v2 = *(u8 *)(p + 0xE9);
                *(u8 *)(p + 0xE9) = 0;
                *(u8 *)(p + 0xEA) = v2;
            }
            n++;
        } while (n < end);
    }
}


void func_80015754(u8 *arg0) {
    u32 f;
    s32 i;
    s32 n;
    u8 *p;
    u8 *q;

    f = *(u32 *)(arg0 + 4);
    if (f != 0) {
        if (f & 0xFF) {
            if (*(s32 *)(arg0 + 0x40) & 1) {
                func_80018394(arg0);
                return;
            }
            *(u8 *)(arg0 + 4) = 0;
            func_80015B04(arg0);
        }
        if (f & 0xFF00) {
            *(u8 *)(arg0 + 5) = 0;
            func_80015A50(arg0);
        }
        if (f & 0xFF0000) {
            *(u8 *)(arg0 + 6) = 0;
            *(u8 *)(arg0 + 0x52) = *(u8 *)(arg0 + 0x11);
            i = 0;
            do {
                ((u8 *)arg0)[i * 0x58 + 0xE9] |= 0x32;
                i++;
            } while (i < 0x20);
        }
        if (f >> 24) {
            *(u8 *)(arg0 + 7) = 0;
            func_80015294(arg0);
        }
    }
    f = *(u32 *)(arg0 + 8);
    if (f != 0) {
        if (f & 0xFF) {
            *(u8 *)(arg0 + 8) = 0;
            *(u8 *)(arg0 + 0x62) = 0;
            *(u16 *)(arg0 + 0x60) = 0;
            *(s8 *)(arg0 + 0x5E) = 1;
            *(u16 *)(arg0 + 0x5C) = *(u16 *)(arg0 + 0x16);
        } else if (f & 0xFF00) {
            *(u8 *)(arg0 + 9) = 0;
            *(u8 *)(arg0 + 0x63) = 0;
            *(u16 *)(arg0 + 0x60) = 0;
            *(s8 *)(arg0 + 0x5E) = -1;
            *(u16 *)(arg0 + 0x5C) = *(u16 *)(arg0 + 0x16);
        }
        if (f & 0xFF0000) {
            *(u8 *)(arg0 + 0xA) = 0;
            *(u8 *)(arg0 + 0x6A) = 0;
            *(u16 *)(arg0 + 0x68) = 0;
            *(s8 *)(arg0 + 0x66) = 1;
            *(u16 *)(arg0 + 0x64) = *(u16 *)(arg0 + 0x18);
        } else if (f >> 24) {
            *(u8 *)(arg0 + 0xB) = 0;
            *(u8 *)(arg0 + 0x6B) = 0;
            *(u16 *)(arg0 + 0x68) = 0;
            *(s8 *)(arg0 + 0x66) = -1;
            *(u16 *)(arg0 + 0x64) = *(u16 *)(arg0 + 0x18);
        }
    }
    f = *(u32 *)(arg0 + 0xC);
    if (f != 0) {
        if (f & 0xFF) {
            *(u8 *)(arg0 + 0xC) = 0;
            func_80018394(arg0);
        }
        if (f & 0xFF00) {
            *(u8 *)(arg0 + 0xD) = 0;
            func_800181DC(arg0);
        }
        if (f & 0xFF0000) {
            s32 v;

            v = *(s16 *)(arg0 + 0x14);
            *(u8 *)(arg0 + 0xE) = 0;
            if (v == 0) {
                n = *(s32 *)(arg0 + 0x10E8);
                *(s32 *)(arg0 + 0x40) &= ~1;
                if (n < 0x18) {
                    do {
                        if (*(s8 *)(arg0 + n * 0x38 + 0xBBE) != 0 && !(*(s32 *)(arg0 + n * 0x38 + 0xB98) & 0x800)) {
                            func_800184E8(arg0, n);
                        }
                        n++;
                    } while (n < 0x18);
                }
            } else {
                *(u16 *)(arg0 + 0x70) = 0;
                *(s8 *)(arg0 + 0x6E) = -1;
                *(u8 *)(arg0 + 0x73) = *(u8 *)(arg0 + 0x13);
                *(u16 *)(arg0 + 0x6C) = 0x7800 / v;
            }
        }
        if (f >> 24) {
            s32 v;

            v = *(s16 *)(arg0 + 0x14);
            *(u8 *)(arg0 + 0xF) = 0;
            if (v == 0) {
                func_800181DC(arg0);
                *(s32 *)(arg0 + 0x40) |= 1;
            } else {
                *(u16 *)(arg0 + 0x70) = 0;
                *(u8 *)(arg0 + 0x6E) = 1;
                *(u16 *)(arg0 + 0x6C) = 0x7800 / v;
            }
        }
    }
    if (*(s8 *)(arg0 + 0x10) != 0) {
        *(u8 *)(arg0 + 0x10) = 0;
        i = 0;
        do {
            ((u8 *)arg0)[i * 0x58 + 0xE9] |= 0x32;
            i++;
        } while (i < 0x20);
    }
}

void func_80015A50(u8 *arg0) {
    u8 *p;
    s32 *src;
    s32 *dst;
    s32 i;
    s32 v;

    p = *(u8 **)(arg0 + 0x1C);
    i = 0x20F;
    src = (s32 *)(arg0 + 0x8D4);
    dst = (s32 *)(p + 0x83C);
    do {
        v = *src;
        src--;
        i--;
        *dst = v;
        dst--;
    } while (i >= 0);
    p += 0x840;
    *(s32 *)p = *(s32 *)(arg0 + 0x30);
    p += 4;
    *(s32 *)p = (*(s16 *)(arg0 + 0x78) << 16) | *(s16 *)(arg0 + 0x7A);
    p += 4;
    *(s32 *)p = (*(s16 *)(arg0 + 0x7E) << 16) | *(s16 *)(arg0 + 0x80);
    p += 4;
    *(s32 *)p = (*(s16 *)(arg0 + 0x82) << 16) | *(s16 *)(arg0 + 0x84);
    p += 4;
    *(u8 *)p = *(u8 *)(arg0 + 0x53);
    ((u8 *)p)[1] = *(u8 *)(arg0 + 0x5A);
    ((u8 *)p)[2] = *(s32 *)(arg0 + 0x40);
    *(s32 *)((u8 *)p + 4) = *(s32 *)(*(s32 *)(arg0 + 0x30) + 4);
}


void func_80015B04(u8 *arg0) {
    u8 *p;
    s32 *src;
    s32 *dst;
    s32 i;
    s32 v;

    i = 0x20F;
    p = *(u8 **)(arg0 + 0x1C);
    src = (s32 *)(p + 0x83C);
    dst = (s32 *)(arg0 + 0x8D4);
    do {
        v = *src;
        src--;
        i--;
        *dst = v;
        dst--;
    } while (i >= 0);
    p += 0x840;
    *(s32 *)(arg0 + 0x34) = *(s32 *)p;
    p += 4;
    *(u16 *)(arg0 + 0x78) = *(u16 *)(p + 2);
    *(u16 *)(arg0 + 0x7A) = *(s32 *)p;
    p += 4;
    *(u16 *)(arg0 + 0x7E) = *(u16 *)(p + 2);
    *(u16 *)(arg0 + 0x80) = *(s32 *)p;
    p += 4;
    *(u16 *)(arg0 + 0x82) = *(u16 *)(p + 2);
    *(u16 *)(arg0 + 0x84) = *(s32 *)p;
    p += 4;
    *(u8 *)(arg0 + 0x53) = *(u8 *)p;
    *(u8 *)(arg0 + 0x5A) = *(u8 *)(p + 1);
    if (!(*(u8 *)(p + 2) & 1)) {
        *(u8 *)(arg0 + 0x88) = 1;
    }
    *(s32 *)(arg0 + 0x90) = *(s32 *)(p + 4);
    *(s32 *)(arg0 + 0x40) &= ~1;
    DisableEvent(*(s32 *)(arg0 + 0x20));
    *(s32 *)(arg0 + 0x3254) = 0;
    func_80018394(arg0);
    SpuSetKey(0, *(s32 *)(arg0 + 0x3254));
    EnableEvent(*(s32 *)(arg0 + 0x20));
}


void func_80015C1C(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x18; i++) {
        if (*(u8 *)(arg0 + i * 0x38 + 0xBC1) != 0 && *(s8 *)(arg0 + i * 0x38 + 0xBBE) != 0) {
            if (*(s16 *)(arg0 + 0x3238) == 3 ||
                (*(u32 *)(arg0 + i * 0x38 + 0xB98) & 0x800) == *(u16 *)(arg0 + 0x323A)) {
                s32 v;

                v = *(u8 *)(arg0 + i * 0x38 + 0xBC1) - 1;
                *(u8 *)(arg0 + i * 0x38 + 0xBC1) = v;
                if ((v & 0xFF) == 0) {
                    u8 *t;

                    t = arg0 + *(u8 *)(arg0 + i * 0x38 + 0xBBF) * 0x58;
                    if (!(*(u32 *)(t + 0x98) & 0x100)) {
                        func_800184E8(arg0, i);
                    } else {
                        (*(u16 *)(arg0 + i * 0x38 + 0xBBC))++;
                        (*(u8 *)(arg0 + i * 0x38 + 0xBC1))++;
                    }
                }
            }
        }
    }
}

#ifdef NON_MATCHING
void func_80015D18(void *arg0_, s32 arg1) {
    extern s32 func_80017EE8(u8 *, s32, s32 *);
    extern s32 func_80018350(u8 *, s32);
    extern u8 *func_80017488(u8 *, s32);
    extern void func_80016BAC(u8 *, s32);
    u8 *arg0 = arg0_;
    s32 sp10;
    u8 *s0;
    u8 *t;
    s32 s4;
    s8 s3;
    u8 v;

    s0 = arg0 + arg1 * 0x58;
    v = **(u8 **)(s0 + 0xA0);
    if (v < 0x80) {
        *(u8 *)(s0 + 0xBD) = v;
        *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
        s4 = func_80017EE8(arg0, arg1, &sp10);
        if (s4 == -1) {
            *(u8 **)(s0 + 0xA0) += *(u8 *)(s0 + 0xEB);
            if (*(u8 *)(s0 + 0xEB) == 1) {
                *(u8 **)(s0 + 0xA0) += 2;
            }
            return;
        }
        if (sp10 == 0) {
            *(s8 *)(s0 + 0xBE) = 0;
            *(u8 *)(s0 + 0xE9) |= 0xF;
            *(s32 *)(s0 + 0xB0) += 1;
            if (*(s32 *)(arg0 + 0x40) & 8) {
                *(s8 *)(s0 + 0xBE) = func_80018350(arg0, 5) - 2;
            } else {
                s3 = *(s8 *)(s0 + 0xB7);
                if (s3 != 0 && (func_80018350(arg0, 0x80) & 0xFF) < s3) {
                    *(s8 *)(s0 + 0xBE) = func_80018350(arg0, 5) - 2;
                }
            }
            s0 = arg0 + arg1 * 0x58;
            *(s8 *)(s0 + 0xD7) = 0;
            if (*(u32 *)(s0 + 0x98) & 0x4000) {
                *(s8 *)(s0 + 0xD7) = func_80018350(arg0, 7) - 3;
            }
            t = arg0 + s4 * 0x38;
            *(u8 *)(t + 0xBC3) = *(u8 *)(s0 + 0xBD);
            switch (*(u8 *)(s0 + 0xEB)) {
            case 1:
                *(u8 *)(t + 0xBC0) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
                *(u8 *)(t + 0xBC1) = *(u8 *)(s0 + 0xEF);
                *(u8 **)(s0 + 0xA0) += 3;
                break;
            case 2:
                *(u16 *)(t + 0xBC0) = *(u16 *)(s0 + 0xEE);
                *(u8 **)(s0 + 0xA0) += 2;
                break;
            case 3:
                *(u8 *)(t + 0xBC0) = *(u8 *)(s0 + 0xEE);
                *(u8 *)(t + 0xBC1) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
                *(u8 **)(s0 + 0xA0) += 3;
                break;
            default:
                s0 = arg0 + arg1 * 0x58;
                *(u8 *)(t + 0xBC0) = *((u8 *)*(u8 **)(s0 + 0xA0) + 3);
                *(u8 *)(t + 0xBC1) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
                *(u8 **)(s0 + 0xA0) += 4;
                break;
            }
            s0 = arg0 + arg1 * 0x58;
            t = arg0 + s4 * 0x38;
            *(s32 *)(t + 0xB98) = *(s32 *)(s0 + 0x98);
            *(s32 *)(t + 0xBBC) = (arg1 << 24) + (*(s8 *)(s0 + 0xB6) << 16);
            *(s32 *)(t + 0xBC4) = *(s32 *)(s0 + 0xDC);
            *(s32 *)(t + 0xBCC) = 0;
            *(s32 *)(t + 0xBC8) = *(s32 *)(s0 + 0xE0);
            if (!(*(u32 *)(s0 + 0x98) & 2)) {
                if (*(u32 *)(s0 + 0x98) & 0x20000) {
                    *(s32 *)(arg0 + 0x325C) |= 1 << s4;
                    *(s32 *)(t + 0xBA0) = *(s32 *)(s0 + 0xC4);
                    *(s32 *)(t + 0xBA4) = *(s32 *)(s0 + 0xC8);
                    return;
                }
                if (*(s32 *)(s0 + 0xA4) != 0) {
                    *(s32 *)(arg0 + 0x3250) |= 1 << s4;
                }
            }
        } else {
            u8 v2;

            s0 = arg0 + arg1 * 0x58;
            t = arg0 + s4 * 0x38;
            if (*(u8 *)(s0 + 0xEB) < 3) {
                v2 = *(u8 *)(s0 + 0xEF);
            } else {
                v2 = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            }
            *(u8 *)(t + 0xBC1) = v2;
            *(u8 *)(t + 0xBBE) = *(u8 *)(s0 + 0xB6);
            *(s32 *)(t + 0xB98) = *(s32 *)(s0 + 0x98);
            *(u8 **)(s0 + 0xA0) += *(u8 *)(s0 + 0xEB);
            if (*(u8 *)(s0 + 0xEB) == 1) {
                *(u8 **)(s0 + 0xA0) += 2;
            }
        }
    } else {
        switch (v) {
        case 0x80:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xEB) = 4;
            if (!(*(u32 *)(s0 + 0x98) & 0x800)) {
                *(u16 *)(s0 + 0xB4) += 1;
                if (arg1 == 0) {
                    *(u16 *)(arg0 + 0x82) = 0;
                    *(u16 *)(arg0 + 0x80) = *(u16 *)(s0 + 0xB4);
                }
                if (func_800182E8(arg0, arg1) != 0 && func_800182B8(arg0) != 0) {
                    func_80018394(arg0);
                    return;
                }
            } else {
                func_8001844C(arg0, arg1);
                return;
            }
            break;
        case 0x81:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xE3) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x82:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(arg0 + 0x5A) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            func_80015294(arg0);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x83:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 4;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(s16 *)(s0 + 0xB8) =
                *((u8 *)*(u8 **)(s0 + 0xA0) + 2) + (*((u8 *)*(u8 **)(s0 + 0xA0) + 3) << 8);
            *(u8 **)(s0 + 0xA4) = func_80017488(arg0, arg1);
            if (*(u8 **)(s0 + 0xA4) != NULL) {
                *(u16 *)(s0 + 0xCC) = *(u16 *)(*(u8 **)(s0 + 0xA4) + 2);
                *(u16 *)(s0 + 0xCE) = *(u16 *)(*(u8 **)(s0 + 0xA4) + 4);
                *(u8 **)(s0 + 0xA4) += 7;
            }
            *(u8 **)(s0 + 0xA0) += 4;
            return;
        case 0x84:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 1;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xD0) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x85:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 0x12;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xD8) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x86:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 0x12;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xD9) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x87:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 0x32;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xDF) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x88:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*(s8 *)(s0 + 0xD2) == 0) {
                *(u8 *)(s0 + 0xBB) = 0;
            }
            *(u8 *)(s0 + 0xD2) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x89:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*((u8 *)*(u8 **)(s0 + 0xA0) + 2) != 0) {
                *(u32 *)(s0 + 0x98) |= 0x100;
            } else {
                *(u32 *)(s0 + 0x98) &= ~0x100;
                func_8001814C(arg0, arg1);
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x8A:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u16 *)(arg0 + 0x78) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2) << 8;
            *(u16 *)(arg0 + 0x7A) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2) << 8;
            func_800151D4(arg0);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x8D:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xC2) = 0xFF;
            *(u16 *)(s0 + 0xC0) = *(u16 *)(s0 + 0xB4);
            *(u8 **)(s0 + 0xA8) = *(u8 **)(s0 + 0xA0);
            if (arg1 == 0) {
                *(u16 *)(arg0 + 0x84) = *(u16 *)(arg0 + 0x82);
            }
            *(u8 **)(s0 + 0xA0) += 1;
            return;
        case 0x8E:
            s0 = arg0 + arg1 * 0x58;
            if (*(u8 *)(s0 + 0xC2) == 0xFF) {
                *(u8 *)(s0 + 0xC2) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            }
            *(u8 *)(s0 + 0xC2) -= 1;
            if (*(u8 *)(s0 + 0xC2) != 0) {
                *(u16 *)(s0 + 0xB4) = *(u16 *)(s0 + 0xC0);
                *(u8 **)(s0 + 0xA0) = *(u8 **)(s0 + 0xA8);
                if (arg1 == 0) {
                    *(u16 *)(arg0 + 0x7E) += 1;
                    *(u16 *)(arg0 + 0x82) = *(u16 *)(arg0 + 0x84);
                }
                *(u8 **)(s0 + 0xA0) += 1;
                return;
            }
            *(u8 **)(s0 + 0xA0) += 2;
            return;
        case 0x8F:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 **)(s0 + 0xA0) += 2;
            return;
        case 0x90:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*((u8 *)*(u8 **)(s0 + 0xA0) + 2) != 0) {
                *(u32 *)(s0 + 0x98) |= 0x20;
            } else {
                *(u32 *)(s0 + 0x98) &= ~0x20;
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x91:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            switch (*((u8 *)*(u8 **)(s0 + 0xA0) + 2)) {
            case 1:
                *(u16 *)(arg0 + 0x7C) = 1;
                break;
            case 2:
                *(u16 *)(arg0 + 0x7C) = 0x100;
                break;
            case 3:
                *(u16 *)(arg0 + 0x7C) = 0x101;
                break;
            default:
                *(u16 *)(arg0 + 0x7C) = 0;
                break;
            }
            func_800151D4(arg0);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x92:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 0x12;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            switch (*((u8 *)*(u8 **)(s0 + 0xA0) + 2)) {
            case 1:
                *(u32 *)(s0 + 0x98) = (*(u32 *)(s0 + 0x98) | 0x80) & ~0x40;
                break;
            case 2:
                *(u32 *)(s0 + 0x98) = (*(u32 *)(s0 + 0x98) & ~0x80) | 0x40;
                break;
            case 3:
                *(u32 *)(s0 + 0x98) |= 0xC0;
                break;
            default:
                *(u32 *)(s0 + 0x98) &= ~0xC0;
                break;
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x93:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*((u8 *)*(u8 **)(s0 + 0xA0) + 2) != 0) {
                *(u32 *)(s0 + 0x98) |= 0x10;
            } else {
                *(u32 *)(s0 + 0x98) &= ~0x10;
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x94:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xDC) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 *)(s0 + 0xDD) = *((u8 *)*(u8 **)(s0 + 0xA0) + 3);
            *(u8 *)(s0 + 0xDE) = *((u8 *)*(u8 **)(s0 + 0xA0) + 4);
            *(u8 **)(s0 + 0xA0) += 5;
            return;
        case 0x95:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 1;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xD4) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x96:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xD3) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x97:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xE9) |= 4;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u16 *)(s0 + 0xCC) =
                *((u8 *)*(u8 **)(s0 + 0xA0) + 2) + (*((u8 *)*(u8 **)(s0 + 0xA0) + 3) << 8);
            *(u16 *)(s0 + 0xCE) =
                *((u8 *)*(u8 **)(s0 + 0xA0) + 4) + (*((u8 *)*(u8 **)(s0 + 0xA0) + 5) << 8);
            *(u8 **)(s0 + 0xA0) += 6;
            return;
        case 0x99:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*((u8 *)*(u8 **)(s0 + 0xA0) + 2) != 0) {
                *(u32 *)(s0 + 0x98) |= 0x4000;
            } else {
                *(u32 *)(s0 + 0x98) &= ~0x4000;
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x9A:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            if (*((u8 *)*(u8 **)(s0 + 0xA0) + 2) != 0) {
                if (!(*(u32 *)(s0 + 0x98) & 0x8000)) {
                    func_80016BAC(arg0, arg1);
                }
            } else {
                if (*(u32 *)(s0 + 0x98) & 0x8000) {
                    *(u32 *)(s0 + 0x98) &= 0xFFFF7FFF;
                    *(u8 *)(s0 + 0xB6) = 0;
                }
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        case 0x9B:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xBA) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xE4) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            *(u8 *)(s0 + 0xE5) = *((u8 *)*(u8 **)(s0 + 0xA0) + 3);
            *(u8 *)(s0 + 0xE6) = *((u8 *)*(u8 **)(s0 + 0xA0) + 4);
            *(u8 *)(s0 + 0xE7) = *((u8 *)*(u8 **)(s0 + 0xA0) + 5);
            *(u8 *)(s0 + 0xE8) = *((u8 *)*(u8 **)(s0 + 0xA0) + 6);
            *(u8 **)(s0 + 0xA0) += 7;
            return;
        case 0x9E:
            s0 = arg0 + arg1 * 0x58;
            *(u8 *)(s0 + 0xEF) = *((u8 *)*(u8 **)(s0 + 0xA0) + 1);
            *(u8 *)(s0 + 0xEE) = *((u8 *)*(u8 **)(s0 + 0xA0) + 2);
            if (*(u8 *)(s0 + 0xEF) == 0) {
                if (*(u8 *)(s0 + 0xEE) == 0) {
                    *(u8 *)(s0 + 0xEB) = 4;
                } else {
                    *(u8 *)(s0 + 0xEB) = 3;
                }
            } else {
                if (*(u8 *)(s0 + 0xEE) == 0) {
                    *(u8 *)(s0 + 0xEB) = 1;
                } else {
                    *(u8 *)(s0 + 0xEB) = 2;
                }
            }
            *(u8 **)(s0 + 0xA0) += 3;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80015D18);
#endif


typedef struct {
    s32 unk0;
    u8 pad4[0x14 - 4];
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x1E - 0x1C];
    s8 unk1E;
    u8 pad1F[0x22 - 0x1F];
    u8 unk22;
    u8 pad23;
    u8 unk24;
    u8 pad25[0x3C - 0x25];
    u8 unk3C;
    u8 pad3D[3];
    u8 unk40;
    u8 pad41[0x47 - 0x41];
    u8 unk47;
    u8 pad48[0x4C - 0x48];
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 pad53[0x58 - 0x53];
} Trk;

typedef struct {
    u8 pad[0x98];
    Trk trk[32];
} Seq;

void func_80016BAC(Seq *arg0, s32 arg1) {
    volatile s32 n;
    u8 *src;
    u8 *dst;
    u8 *end;
    s32 c;

    if (arg1 < 0x18) {
        n = func_80018870(arg0, 0, 0x18);
    } else {
        n = func_80018870(arg0, 0x18, 0x20);
    }
    if (n != -1) {
        src = (u8 *)&arg0->trk[arg1];
        dst = (u8 *)&arg0->trk[n];
        end = dst + 0x58;
        do {
            *dst++ = *src++;
        } while (dst < end);
        arg0->trk[n].unk0 |= 0x8000;
        arg0->trk[n].unk22 += arg0->trk[arg1].unk4C;
        arg0->trk[n].unk24 += arg0->trk[arg1].unk4D;
        arg0->trk[n].unk3C = arg0->trk[arg1].unk4E;
        arg0->trk[n].unk40 = arg0->trk[arg1].unk4F;
        arg0->trk[n].unk47 = arg0->trk[arg1].unk50;
        if (n < arg1) {
            arg0->trk[n].unk18 = 0;
            if (arg0->trk[n].unk22 != 0) {
                arg0->trk[n].unk22--;
            }
            for (;;) {
                c = arg0->trk[n].unk22 == 0 && arg0->trk[n].unk1E != 0;
                if (!c) {
                    break;
                }
                func_80015D18(arg0, n);
            }
            arg0->trk[n].unk14 += arg0->trk[n].unk18;
            arg0->trk[n].unk52 = arg0->trk[n].unk51;
            arg0->trk[n].unk51 = 0;
        }
    }
}

#ifdef NON_MATCHING
void func_80016F40(void *arg0_, void *arg1_, s32 arg2, s32 arg3) {
    u8 *arg0 = arg0_;
    u8 *arg1 = arg1_;
    s32 v;
    s32 v1;

    if (*(s8 *)(arg1 + 2) == 0) {
        return;
    }
    if (*(s8 *)(arg1 + 2) == 1) {
        if (*(u8 *)(arg1 + 6) == 0x7F) {
            *(u8 *)(arg1 + 2) = 0;
            return;
        }
        v = *(u16 *)(arg1 + 4);
        v1 = *(u16 *)(arg1);
        v += v1;
        v1 = v << 16;
        *(u16 *)(arg1 + 4) = v;
        if ((v1 >> 16) < 0x100) {
            return;
        }
        *(u8 *)(arg1 + 6) += v1 >> 24;
        if ((*(u8 *)(arg1 + 6) & 0xFF) >= 0x80) {
            *(u8 *)(arg1 + 6) = 0x7F;
        }
        *(u16 *)(arg1 + 4) = *(u8 *)(arg1 + 4);
        for (; arg2 < arg3; arg2++) {
            *(u8 *)(arg0 + arg2 * 0x58 + 0xE9) |= 0x12;
        }
        return;
    }
    if (!(*(s8 *)(arg1 + 7) < *(s8 *)(arg1 + 6))) {
        if (arg1 == arg0 + 0x5C) {
            *(u8 *)(arg1 + 2) = 0;
            func_80018394(arg0);
            return;
        }
        if (arg1 == arg0 + 0x64) {
            func_800183E0(arg0, 0xFF000000);
            *(u8 *)(arg0 + 0x6A) = 0x7F;
        }
        return;
    }
    v = *(u16 *)(arg1 + 4);
    v1 = *(u16 *)(arg1);
    v += v1;
    v1 = v << 16;
    *(u16 *)(arg1 + 4) = v;
    if ((v1 >> 16) < 0x100) {
        return;
    }
    *(u8 *)(arg1 + 6) -= v1 >> 24;
    if ((s8)*(u8 *)(arg1 + 6) < *(s8 *)(arg1 + 7)) {
        *(u8 *)(arg1 + 6) = *(s8 *)(arg1 + 7);
    }
    *(u16 *)(arg1 + 4) = *(u8 *)(arg1 + 4);
    for (; arg2 < arg3; arg2++) {
        *(u8 *)(arg0 + arg2 * 0x58 + 0xE9) |= 0x12;
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80016F40);
#endif


typedef struct {
    s32 voice;
    s32 mask;
    u16 unk08;
    u16 unk0A;
    u8 pad0C[8];
    u16 unk14;
    u8 pad16[6];
    s32 unk1C;
    u8 pad20[0x1A];
    u16 unk3A;
    u16 unk3C;
} VoiceAttr;

void func_8001711C(u8 *arg0) {
    VoiceAttr attr;
    u8 *e;
    u8 *s5;
    s32 s3;
    s32 s6;
    s32 v;
    u8 s0;
    u8 s1;

    s6 = 0;
    attr.mask = 0x60093;
    for (s3 = 0x17; s3 >= 0; s3--) {
        e = arg0 + s3 * 0x38;
        s6 *= 2;
        if (*(s8 *)(e + 0xBBE) != 0) {
            v = *(s32 *)(e + 0xB98);
            if (v & 0x20) {
                s6++;
            }
            if (*(s16 *)(arg0 + 0x3238) == 3 || (v & 0x800) == *(u16 *)(arg0 + 0x323A)) {
                s0 = *(u8 *)(e + 0xBBF);
                s5 = arg0 + s0 * 0x58;
                s1 = *(u8 *)(s5 + 0xEA);
                if (s1 & 8) {
                    func_8001730C(arg0, s0, s3);
                }
                if (s1 & 1) {
                    func_80017564(arg0, s0, s3);
                }
                if (s1 & 2) {
                    func_80017914(arg0, s0, s3);
                }
                if (*(s8 *)(s5 + 0xD2) != 0) {
                    func_80017CA0(arg0, s0, s3);
                    s1 |= 1;
                }
                if (*(s32 *)(e + 0xB98) & 0x10) {
                    func_80017D80(arg0, s3);
                    s1 |= 1;
                }
                if (s1 & 0xFF) {
                    attr.voice = 1 << s3;
                    attr.unk1C = *(s32 *)(*(u32 *)(e + 0xB9C) + 4);
                    attr.unk3A = *(u16 *)(s5 + 0xCC);
                    attr.unk3C = *(u16 *)(s5 + 0xCE);
                    attr.unk14 = *(u16 *)(e + 0xBB8);
                    attr.unk08 = *(u16 *)(e + 0xBB0);
                    attr.unk0A = *(u16 *)(e + 0xBB2);
                    SpuSetVoiceAttr(&attr);
                }
            }
        }
    }
    SpuSetReverbVoice(1, s6);
    SpuSetReverbVoice(0, ~s6);
}

void func_8001730C(u8 *arg0, s32 arg1, s32 arg2)
{
  u8 *elem;
  u8 *ent;
  u8 *e;
  u8 *e2;
  u8 *e3;
  u8 *p;
  u8 *q;
  s32 i;
  s32 count;
  s32 t2;
  s32 w;
  elem = arg0 + (arg1 * 0x58);
  p = *((u8 **) (elem + 0xA4));
  if (p == ((void *) 0))
  {
    e = arg0 + (arg2 * 0x38);
    *((s32 *) (e + 0xB9C)) = 0;
    return;
  }
  q = p;
  count = q[0];
  ent = arg0 + (arg2 * 0x38);
  t2 = *((u8 *) (ent + 0xBC3));
  q += 1;
  if (!((*((s32 *) (ent + 0xB98))) & 4))
  {
    w = *((s32 *) (elem + 0xBC));
    t2 += (((s8) w) + ((s8) (w >> 16))) + ((s8) (w >> 24));
  }
  for (i = 0; i < count; i++)
  {
    if ((((q[0] <= t2) && (q[1] >= t2)) && ((*((u8 *) (ent + 0xBC0))) >= q[2])) && ((*((u8 *) (ent + 0xBC0))) <= q[3]))
    {
 do { *((u8 **) (ent + 0xB9C)) = q; if ((*((s32 *) (ent + 0xB98))) & 0x1000) { *((u8 *) (ent + 0xBC3)) = q[0xF]; *((u8 *) (ent + 0xBC1)) = q[0x10]; *((u8 *) (ent + 0xBC7)) = q[0x11]; } } while (0);
      return;
    }
    q += 0x14;
  }

  e3 = arg0 + (arg2 * 0x38);
  e2 = arg0 + (arg1 * 0x58);
  *((s32 *) (e3 + 0xB9C)) = (*((s32 *) (e2 + 0xA4))) + 1;
}

#ifdef NON_MATCHING
u16 *func_80017488(u8 *arg0, s32 arg1) {
    extern s8 D_8002B730[];
    extern s8 D_8002B73C[];
    s8 *t1;
    u16 *v0;
    u16 *a1;
    u8 *t0;
    s32 t2;
    s32 t3;
    s32 adv;
    s32 a2;
    s32 a3;
    s32 v1;
    s32 t4;
    if (*(u8 *)(arg0 + 0x74) == 0) {
        t1 = D_8002B730;
    } else {
        t1 = D_8002B73C;
    }
    t2 = 0;
    t4 = 0xFFFF;
    t3 = arg1 * 0x58;
loop:
    if (t2 < 0xC) {
        v0 = NULL;
        a2 = *t1;
        a1 = *(u16 **)(arg0 + a2 * 0x30 + 0x12D0);
        v1 = *a1;
        t1++;
        if (v1 != t4) {
            t0 = arg0 + t3;
            a3 = (u32)(a2 - 8) < 4U;
            do {
                if (v1 == *(u16 *)(t0 + 0xB8)) {
                    if (a3 != 0) {
                        *a1 = 0xFFFF;
                    }
                    return a1;
                }
                adv = *((u8 *)a1 + 7) * 0x14 + 8;
                a1 = (u16 *)((u8 *)a1 + adv);
                v1 = *a1;
            } while (v1 != 0xFFFF);
        }
        t2++;
        goto loop;
    }
    return v0;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80017488);
#endif

#ifdef NON_MATCHING
#define E (((arg2 << 3) - arg2) << 3)
#define T (((((arg1 << 1) + arg1) << 2) - arg1) << 3)
void func_80017564(u8 *arg0, s32 arg1, s32 arg2) {
    extern s16 D_8002AA24[];
    u8 pad[0x20];
    s32 a0;
    s32 a3;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 d1;
    s32 d2;
    s32 n;
    s32 f;
    s32 x;

    if (!(*(u32 *)(arg0 + E + 0xB98) & 4)) {
        u32 w = *(u32 *)(arg0 + T + 0xBC);
        *(u8 *)(arg0 + E + 0xBBB) = w + (w >> 16) + (w >> 24);
    } else {
        *(u8 *)(arg0 + E + 0xBBB) = 0;
    }
    a3 = *(u8 *)(arg0 + E + 0xBC3) + *(s8 *)(arg0 + E + 0xBBB) +
         *(s8 *)(*(u32 *)(arg0 + E + 0xB9C) + 0xD);
    while (a3 < 0) {
        a3 += 0xC;
    }
    while (a3 >= 0x54) {
        a3 -= 0xC;
    }
    {
        u32 w = *(u32 *)(arg0 + T + 0xD0);
        a0 = *(s8 *)(arg0 + T + 0xD0) * (w >> 24) + (s8)(w >> 8) * 0xC;
    }
    t2 = D_8002AA24[a3] << 15;
    t1 = 0;
    if (a0 != 0) {
        if (a0 < 0) {
            a0 = __builtin_abs(a0);
            a3 -= a0 >> 6;
            while (a3 < 0) {
                a3 += 0xC;
            }
            while (a3 >= 0x54) {
                a3 -= 0xC;
            }
            d1 = D_8002AA24[a3];
            d2 = D_8002AA22[a3];
        } else {
            a3 += a0 >> 6;
            while (a3 < 0) {
                a3 += 0xC;
            }
            while (a3 >= 0x54) {
                a3 -= 0xC;
            }
            d1 = D_8002AA24[a3];
            d2 = D_8002AA26[a3];
        }
        t2 = d1 << 15;
        t1 = (((d2 << 15) - t2) >> 6) * (a0 % 64);
    }
    {
        u32 w = *(u32 *)(arg0 + T + 0xD4);
        a0 = *(s8 *)(arg0 + T + 0xD4) + (s8)(w >> 8) + (s8)(w >> 24) +
             *(s8 *)(*(u32 *)(arg0 + E + 0xB9C) + 0xE);
    }
    t0 = 0;
    if (a0 != 0) {
        if (a0 < 0) {
            s32 negative_span = -(a0 / 64) + 1;
            t0 = t2 - (D_8002AA24[a3 - negative_span] << 15);
            t0 /= negative_span << 6;
            t0 *= a0;
        } else {
            s32 positive_span = (a0 >> 6) + 1;
            s32 positive_quotient = ((D_8002AA24[a3 + positive_span] << 15) - t2) / (positive_span << 6);
            t0 = positive_quotient;
            t0 *= a0;
        }
    }
    x = (t2 + t1 + t0) >> 15;
    *(u16 *)(arg0 + E + 0xBB4) = x;
    f = *(s16 *)(arg0 + T + 0xEC);
    if (f != 0) {
        s32 scaled = ((x & 0xFFFF) * f) >> 13;
        if (scaled >= 0x4000) {
            scaled = 0x3FFF;
        }
        *(u16 *)(arg0 + E + 0xBB4) = scaled;
    } else {
        if ((x & 0xFFFF) >= 0x4000U) {
            do {
                *(u16 *)(arg0 + E + 0xBB4) = *(u16 *)(arg0 + E + 0xBB4) >> 1;
            } while (*(u16 *)(arg0 + E + 0xBB4) >= 0x4000U);
        }
    }
    {
        u16 value = *(u16 *)(arg0 + E + 0xBB4);
        *(u8 *)(arg0 + E + 0xBBA) = a3;
        *(u16 *)(arg0 + E + 0xBB8) = value;
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80017564);
#endif


void func_80017914(s32 arg0, s32 arg1, s32 arg2) {
    u8 *s2;
    u8 *q;
    u32 v;
    u32 x;
    u32 y;

    s2 = (u8 *)(arg0 + arg1 * 0x58);
    if (*(u8 *)(s2 + 0xEA) & 0x12) {
        func_80017A54(arg0, arg1, arg2);
    }
    q = (u8 *)(arg2 * 0x38 + arg0);
    v = *(u32 *)(q + 0xBC0);
    x = (u32)((v & 0xFF) * *(u8 *)(*(u32 *)(q + 0xB9C) + 0xC) * ((v >> 16) & 0xFF) *
              *(u8 *)(arg0 + (v >> 26) + 0x150C)) >> 21;
    y = (x * *(u8 *)(q + 0xBB7) << 16) + x * *(u8 *)(q + 0xBB6);
    *(u32 *)(q + 0xBAC) = y;
    *(u32 *)(q + 0xBB0) = y;
    if (*(s8 *)(arg0 + 0x52) == 0) {
        if (*(u32 *)(s2 + 0x98) & 0x80) {
            *(u16 *)(q + 0xBB0) = -*(u16 *)(q + 0xBB0);
        }
        if (*(u32 *)(s2 + 0x98) & 0x40) {
            *(u16 *)(q + 0xBB2) = -*(u16 *)(q + 0xBB2);
        }
    }
}

#define OFF (((arg2 << 3) - arg2) << 3)

void func_80017A54(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    u32 v;
    u32 x;
    u32 y;
    u32 z;
    u32 w;

    p = arg0 + arg1 * 0x58;
    if (*(u8 *)(p + 0xEA) & 0x32) {
        func_80017B90(arg0, arg1, arg2);
    }
    v = *(u32 *)(p + 0xD8);
    y = (v & 0xFF) * ((v >> 8) & 0xFF);
    z = y * ((v >> 16) & 0xFF);
    x = z * (v >> 24);
    x >>= 21;
    if (arg1 < 0x18) {
        w = x * *(u8 *)(arg0 + 0x50);
        w = w * *(u8 *)(arg0 + 0x62);
        x = w * *(u8 *)(arg0 + 0x72);
        x >>= 21;
    } else {
        w = x * *(u8 *)(arg0 + 0x51);
        x = w * *(u8 *)(arg0 + 0x6A);
        x >>= 13;
        if (x >= 0x100) {
            x = 0xFF;
        }
    }
    *(u8 *)(arg0 + OFF + 0xBC2) = x;
}

#ifdef NON_MATCHING
#define OFF (((arg2 << 3) - arg2) << 3)
void func_80017B90(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *q;
    s32 v;
    s32 pan;
    s32 d;

    if (*(s8 *)(arg0 + 0x52) == 2) {
        *(u16 *)(OFF + (s32)arg0 + 0xBB6) = 0x4040;
        return;
    }
    {
        s32 ix = arg1 * 0x58;
        v = *(s8 *)(arg0 + ix + 0xD6);
    }
    if (*(u32 *)(arg0 + OFF + 0xB98) & 0x40000) {
        pan = (*(u8 *)(arg0 + OFF + 0xBC3) - 0x20) << 1;
        if (pan < 0) {
            pan = 0;
        }
        if (pan >= 0x80) {
            pan = 0x7F;
        }
    } else {
        pan = *(s8 *)(arg0 + OFF + 0xBC7);
    }
    q = arg0 + arg2 * 0x38;
    d = v - 0x40;
    pan -= 0x40;
    if (d >= 0) {
        pan = pan * (0x80 - v);
    } else {
        pan = pan * v;
    }
    if (pan < 0) {
        pan += 0x3F;
    }
    pan >>= 6;
    pan = v + pan;
    *(u8 *)(q + 0xBB7) = pan;
    *(u8 *)(arg0 + OFF + 0xBB6) = 0x7F - *(u8 *)(arg0 + OFF + 0xBB7);
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80017B90);
#endif


#define OFF (((arg2 << 3) - arg2) << 3)

void func_80017CA0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 v;
    s32 d;

    p = arg0 + arg1 * 0x58;
    v = D_8002AAFC[*(u8 *)(p + 0xBB)] * *(s8 *)(p + 0xD2);
    if (v < 0) {
        d = *(u16 *)(arg0 + OFF + 0xBB4) - D_8002AA22[*(u8 *)(arg0 + OFF + 0xBBA)];
        *(s16 *)(arg0 + OFF + 0xBB8) = *(u16 *)(arg0 + OFF + 0xBB4) - ((d * __builtin_abs(v)) >> 15);
    } else {
        d = D_8002AA26[*(u8 *)(arg0 + OFF + 0xBBA)] - *(u16 *)(arg0 + OFF + 0xBB4);
        *(s16 *)(arg0 + OFF + 0xBB8) = *(u16 *)(arg0 + OFF + 0xBB4) + ((d * v) >> 15);
    }
}

#ifdef NON_MATCHING
void func_80017D80(u8 *p, s32 idx) {
    u8 *q;
    u8 t;
    u8 lim;
    s8 cur;
    s32 u;
    s32 val;

    q = p + idx * 56;
    t = *(u8 *)(q + 0xBC4);
    if (t != 0) {
        *(u8 *)(q + 0xBC4) = t - 1;
        return;
    }
    u = *(u8 *)(q + 0xBCD) + *(u8 *)(q + 0xBC6);
    *(u8 *)(q + 0xBCD) = u;
    if ((u8)u >= 0x40) {
        *(u8 *)(q + 0xBCD) = u - 0x40;
    }
    cur = *(s8 *)(q + 0xBCC);
    lim = *(u8 *)(q + 0xBC5);
    if (cur != (s8)lim) {
        *(s8 *)(q + 0xBCC) = cur + 1 + ((s8)lim >> 5);
        if (*(s8 *)(q + 0xBC5) < *(s8 *)(q + 0xBCC)) {
            *(s8 *)(q + 0xBCC) = *(s8 *)(q + 0xBC5);
        }
    }
    {
        u8 *r = p + idx * 56;

        val = D_8002AAFC[*(u8 *)(r + 0xBCD)] * *(s8 *)(r + 0xBCC);
        if (val < 0) {
            *(s16 *)(r + 0xBB8) = *(u16 *)(r + 0xBB4) -
                (((*(u16 *)(r + 0xBB4) - D_8002AA22[*(u8 *)(r + 0xBBA)]) * __builtin_abs(val)) >> 15);
        } else {
            *(s16 *)(r + 0xBB8) = *(u16 *)(r + 0xBB4) +
                (((D_8002AA26[*(u8 *)(r + 0xBBA)] - *(u16 *)(r + 0xBB4)) * val) >> 15);
        }
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80017D80);
#endif

#ifdef NON_MATCHING
s32 func_80017EE8(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 *track;
    u8 *e;
    u8 *q;
    s32 i;
    s8 max;
    s32 found;
    u32 v;
    u32 m;
    u32 cur;
    u8 *track2;

    track = arg0 + arg1 * 0x58;
    *arg2 = 0;
    if (*(u32 *)(track + 0xAC) != 0 && !(*(u32 *)(track + 0x98) & 0x1000)) {
        i = 0;
        q = track;
        e = arg0;
    loop:
        if (*(u8 *)(e + 0xBC3) != *(s8 *)(q + 0xBD)) goto next;
        if (*(u8 *)(e + 0xBBF) != (arg1 & 0xFF)) goto next;
        if (*(s8 *)(e + 0xBBE) == 0) goto next;
        if (*(u16 *)(e + 0xBBC) == 0) {
            goto success;
        }
        func_800184E8(arg0, i);
    next:
        i++;
        e += 0x38;
        if (i < 0x18) goto loop;
    }
    track2 = arg0 + arg1 * 0x58;
    if (*(u32 *)(track2 + 0x98) & 0x20000) {
        return *(u8 *)(track2 + 0xC3);
    }
    if (*(u32 *)(arg0 + 0x44) != *(u32 *)(arg0 + 0x48)) {
        q = *(u8 **)(arg0 + 0x44);
        v = *(u8 *)q;
        m = 1 << v;
        if (m & SpuStGetVoiceStatus()) {
            return -1;
        }
        q = *(u8 **)(arg0 + 0x44);
        if (q == arg0 - (*(s32 *)(arg0 + 0x10E8) - 0x1548)) cur = (u32)(arg0 + 0x1530);
        else cur = (u32)(q + 1);
        *(u32 *)(arg0 + 0x44) = cur;
        return v;
    }
    i = *(s32 *)(arg0 + 0x10E8);
    max = 0;
    if (i < 0x18) {
        do {
            e = arg0 + i * 0x38;
            if (*(s8 *)(e + 0xBCB) > max) {
                max = *(s8 *)(e + 0xBCB);
                found = i;
            }
            i++;
        } while (i < 0x18);
    }
    if (*(s8 *)(arg0 + arg1 * 0x58 + 0xE3) < max) goto take;
    return -1;
take:
    {
        func_800184E8(arg0, found);
        q = *(u8 **)(arg0 + 0x44);
        if (q == arg0 - (*(s32 *)(arg0 + 0x10E8) - 0x1548)) cur = (u32)(arg0 + 0x1530);
        else cur = (u32)(q + 1);
        goto store;
    }
success:
    *arg2 = 1;
    return i;
store:
    *(u32 *)(arg0 + 0x44) = cur;
    return found;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80017EE8);
#endif


void func_8001814C(u8 *arg0, s32 arg1) {
    u8 *p;
    s32 i;

    i = 0;
    do {
        p = arg0 + i * 0x38;
        if (*(s8 *)(p + 0xBBE) != 0 && *(u8 *)(p + 0xBBF) == (arg1 & 0xFF) && *(u16 *)(p + 0xBBC) != 0) {
            func_800184E8(arg0, i);
        }
        i++;
    } while (i < 0x18);
}

void func_800181DC(u8 *a0) {
    s32 i;

    i = *(s32 *)(a0 + 0x10E8);
    if (i >= 0x18) {
        return;
    }
    do {
        if (*(s8 *)(a0 + i * 0x38 + 0xBBE) != 0 &&
            (*(u32 *)(a0 + i * 0x38 + 0xB98) & 0x1800) == 0 &&
            *(u8 *)(a0 + i * 0x38 + 0xBC1) >= 6 &&
            *(s32 *)*(u8 **)(a0 + i * 0x38 + 0xB9C) + 8 != 0) {
            s32 k = *(u8 *)(a0 + i * 0x38 + 0xBBF) * 0x58;

            if (((*(u16 *)(a0 + k + 0xCE) >> 6) & 0x7F) >= 0x44) {
                *(u32 *)(a0 + 0x3250) |= 1 << i;
            }
        }
        i++;
    } while (i < 0x18);
}

s32 func_800182B8(u8 *arg0) {
    s32 i = 0;

L:
    if (*(s8 *)(arg0 + 0xB6) != 0) {
        return 0;
    }
    i++;
    if (i < 0x18) {
        arg0 += 0x58;
        goto L;
    }
    return 1;
}

s32 func_800182E8(u8 *arg0, s32 arg1) {
    u8 *temp_a2;
    u8 *temp_v0;
    s32 temp_a1;

    temp_a2 = arg0 + arg1 * 0x58;
    temp_v0 = *(s16 *)(temp_a2 + 0xB4) * 2 + *(s32 *)(temp_a2 + 0x9C);
    temp_a1 = (temp_v0[1] << 8) + temp_v0[0];
    *(s32 *)(temp_a2 + 0xA0) = temp_a1;
    if (temp_a1 != 0xFFFF) {
        *(s32 *)(temp_a2 + 0xA0) = temp_a1 + *(s32 *)(arg0 + 0x30);
        return 0;
    }
    *(u8 *)(temp_a2 + 0xB6) = 0;
    return 1;
}

typedef struct { u8 pad[0x4C]; u16 x, y; } Random;
s32 func_80018350(Random *p, s32 a) {
    s32 result;
    s32 b;
    switch (a) {
    case 0: return 0;
    default:
        b = p->y;
        p->y = p->x + b + 0x3711;
        p->x = b;
        return p->y % a;
    }
}


void func_80018394(u8 *arg0) {
    arg0[0x5E] = 0;
    arg0[0x66] = 0;
    arg0[0x6E] = 0;
    func_800183E0(arg0, 0xFFFFFF);
    *(s32 *)(arg0 + 0x40) &= ~1;
}


void func_800183E0(s32 a0, u32 a1) {
    s32 i = 0x1F;

    while (a1 != 0) {
        if (a1 & 0x80000000) {
            func_8001844C(a0, i);
        }
        a1 <<= 1;
        i--;
    }
}

typedef struct { u8 pad[0xBBE]; s8 active; u8 index; } Object;
typedef struct { u8 pad[0x1A]; u8 active; u8 tail[0x3D]; } Track;
typedef struct { u8 pad[0x9C]; Track tracks[24]; } State;
void func_8001844C(s32 p, s32 a) {
    s32 i;
    s32 q;
    ((State *)p)->tracks[a].active = 0;
    i = 0;
    do {
        q = (s32)p + i * 0x38;
        if (((Object *)q)->index == a && ((Object *)q)->active != 0) func_800184E8(p, i);
        i++;
    } while (i < 24);
}

void func_800184E8(u8 *arg0, s32 arg1)
{
  u8 *new_var;
  u8 *p;
  p = arg0 + (arg1 * 0x38);
  if ((*((s8 *) (p + 0xBBE))) != 0)
  {
    if (!((*((s32 *) (p + 0xB98))) & 0x20000))
    {
      ((void (*)())func_8001A144)();
    }
    *((s8 *) (p + 0xBBE)) = 0;
    new_var = (arg0 + ((*((u8 *) (p + 0xBBF))) * 0x58)) + 0xAC;
    *((s32 *) new_var) -= 1;
    if (!((*((s32 *) (p + 0xB98))) & 0x20000))
    {
      *((s32 *) (arg0 + 0x3254)) |= 1 << arg1;
    }
    else
    {
 do { *((s32 *) (arg0 + 0x3260)) |= 1 << arg1; } while (0);
    }
  }
}

#ifdef NON_MATCHING
void func_800185CC(void *arg0_, s32 arg1) {
    u8 *arg0 = arg0_;
    u8 *var_s3;
    s32 var_s4;
    s32 temp_v1;
    s32 temp_a2;

    *(s32 *)(arg0 + 0x10F4) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0x13);
    *(s32 *)(arg0 + 0x10FC) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0x14);
    *(s32 *)(arg0 + 0x1100) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0x15);
    func_8001514C();
    if (arg1 == 1) {
        func_800151D4(arg0);
    }
    if (arg1 == 0) {
        u8 *temp;
        s32 c;

        temp = *(u8 **)(arg0 + 0x30);
        *(s32 *)(arg0 + 0x40) = 0;
        c = temp[0xF];
        *(u8 *)(arg0 + 0x5A) = 0;
        *(s16 *)(arg0 + 0x7E) = 0;
        *(s16 *)(arg0 + 0x80) = 0;
        *(s16 *)(arg0 + 0x82) = 0;
        *(u8 *)(arg0 + 0x53) = c;
    }
    *(u8 *)(arg0 + 0x62) = 0x7F;
    *(u8 *)(arg0 + 0x6A) = 0x7F;
    *(u8 *)(arg0 + 0x72) = 0x7F;
    *(u8 *)(arg0 + 0x73) = 0;
    *(s16 *)(arg0 + 0x6C) = 0;
    *(s16 *)(arg0 + 0x70) = 0;
    *(s32 *)(arg0 + 0x4) = 0;
    *(s32 *)(arg0 + 0x8) = 0;
    *(s32 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0x10) = 0;
    func_80015294(arg0);
    var_s4 = 0;
    if (arg1 != 1) {
        var_s3 = *(u8 **)(arg0 + 0x30);
        var_s3 += (var_s3[9] << 8) + var_s3[8];
        do {
            func_800187EC(arg0, var_s4);
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xDA) = 0x7F;
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xDB) = 0x7F;
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xD6) = 0x40;
            if (var_s3[0] & 0x80) {
                *(s32 *)(arg0 + var_s4 * 0x58 + 0x98) |= 4;
            }
            if (var_s3[0] & 0x40) {
                *(s32 *)(arg0 + var_s4 * 0x58 + 0x98) |= 0x1000;
            }
            if (var_s3[0] & 2) {
                *(s32 *)(arg0 + var_s4 * 0x58 + 0x98) |= 0x40000;
            }
            if (var_s3[0] & 1) {
                *(s32 *)(arg0 + var_s4 * 0x58 + 0x98) |= 2;
            }
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xE3) = var_s3[1];
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xBC) = var_s3[2];
            *(u8 *)(arg0 + var_s4 * 0x58 + 0xBA) = var_s3[3] + 1;
            temp_v1 = var_s3[5];
            temp_a2 = var_s3[4];
            temp_v1 <<= 8;
            var_s3 += 6;
            *(u8 **)(arg0 + var_s4 * 0x58 + 0x9C) = *(u8 **)(arg0 + 0x30) + (temp_v1 + temp_a2);
            if (func_800182E8(arg0, var_s4) == 0) {
                *(u8 *)(arg0 + var_s4 * 0x58 + 0xB6) = 1;
            }
            var_s4++;
        } while (var_s4 < 0x18);
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_800185CC);
#endif

void func_800187EC(u8 *arg0, s32 arg1) {
    u32 i;
    u8 *p;

    for (i = 0; i < 0x16U; i++) {
        *(s32 *)(arg0 + arg1 * 0x58 + 0x98 + i * 4) = 0;
    }
    p = arg0 + arg1 * 0x58;
    *(u8 *)(p + 0xEB) = 4;
    *(u8 *)(p + 0xD3) = 0xC;
    *(s16 *)(p + 0xD8) = 0x7F7F;
    *(s32 *)(p + 0xDC) = 0x40041430;
    *(s32 *)(p + 0xE0) = 0x44030;
}

s32 func_80018870(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *var_a0;
    s32 var_v0;
    s32 off;

    if (arg1 < arg2) {
        off = ((((arg1 << 1) + arg1) << 2) - arg1) << 3;
        var_a0 = (u8 *)(off + (s32)arg0);
        do {
            var_v0 = arg1;
            if (*(s8 *)(var_a0 + 0xB6) != 0) {
                arg1++;
                var_a0 += 0x58;
            } else {
                return var_v0;
            }
        } while (arg1 < arg2);
    }
    return -1;
}

#ifdef NON_MATCHING
void func_800188BC(void *arg0_) {
    extern u8 func_80018DB4(u8 *, s32, u16, s8, s32);
    u8 *arg0 = arg0_;
    u32 pad[6];
    u8 *var_s1;
    u8 *s0;
    u8 *cmdptr;
    u8 *obj;
    u32 cmd;
    s32 idx;
    u8 oidx;
    u16 timer;
    s32 temp_s16;
    s32 shifted;
    u16 sum;
    s8 d;
    s32 off;

    off = 0;
    do {
        var_s1 = arg0 + off;
        if (*(s32 *)(var_s1 + 0x112C) != 0) {
            u16 wait = *(u16 *)(var_s1 + 0x113C);
            if (wait != 0) {
                *(u16 *)(var_s1 + 0x113C) = wait - 1;
                if (*(u16 *)(var_s1 + 0x113C) != 0) {
                    goto post;
                }
            }
            s0 = var_s1;
        cmd_loop:
            cmdptr = *(u8 **)(s0 + 0x112C);
            if (cmdptr == 0) {
                goto post;
            }
            {
                cmd = *(u32 *)cmdptr;
                switch (cmd >> 24) {
                case 0:
                    if (*(s8 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0xB6) != 0) {
                        goto set_timer;
                    }
                    *(s32 *)(s0 + 0x112C) = 0;
                    break;
                case 1:
                    *(u16 *)(s0 + 0x113C) = cmd;
                    *(s32 *)(s0 + 0x112C) = *(s32 *)(s0 + 0x112C) + 4;
                    break;
                case 2:
                    if (*(s8 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0xB6) != 0) {
                        goto set_timer;
                    }
                    *(s32 *)(s0 + 0x112C) = (s32)cmdptr + 4;
                    break;
                set_timer:
                    *(u16 *)(s0 + 0x113C) = 1;
                    goto after;
                case 3:
                    idx = func_80018DB4(arg0, cmd & 0xFFFF, *(u16 *)(s0 + 0x1140),
                                        *(s8 *)(s0 + 0x1142), *(s8 *)(s0 + 0x114A));
                    oidx = idx;
                    *(u8 *)(s0 + 0x1143) = oidx;
                    *(s32 *)(arg0 + oidx * 0x58 + 0x98) &= ~0x20000;
                    if (*(s32 *)(s0 + 0x1134) != 0) {
                        *(s32 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0x98) |= 0x20000;
                        *(s32 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0xC4) = *(s32 *)(s0 + 0x1134);
                        *(u8 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0xC3) = *(u8 *)(s0 + 0x114B);
                        *(s32 *)(arg0 + *(u8 *)(s0 + 0x1143) * 0x58 + 0xC8) = *(s32 *)(s0 + 0x1138);
                    }
                    *(s32 *)(s0 + 0x112C) = *(s32 *)(s0 + 0x112C) + 4;
                    break;
                }
            }
        after:
            if (*(u16 *)(s0 + 0x113C) == 0) {
                goto cmd_loop;
            }
            goto post;
        }
    post:
        if (*(u8 *)(var_s1 + 0x1148) != 0) {
            idx = *(u8 *)(var_s1 + 0x1143);
            *(u8 *)(var_s1 + 0x1148) = 0;
            if (idx != 0) {
                obj = arg0 + idx * 0x58;
                *(u8 *)(obj + 0xE9) |= 0x33;
                *(u8 *)(obj + 0xDA) = *(u8 *)(var_s1 + 0x1147);
                *(u8 *)(obj + 0xD6) = *(u8 *)(var_s1 + 0x1146);
                *(u16 *)(obj + 0xEC) = *(u16 *)(var_s1 + 0x1144);
                if (*(u8 *)(var_s1 + 0x1149) != 0) {
                    *(s32 *)(obj + 0x98) |= 0x80;
                } else {
                    *(s32 *)(obj + 0x98) &= ~0x80;
                }
            }
        }
        temp_s16 = *(s16 *)(var_s1 + 0x115C);
        if ((s16)temp_s16 != 0) {
            idx = *(u8 *)(var_s1 + 0x1143);
            *(s16 *)(var_s1 + 0x115C) = temp_s16 - 1;
            if (*(s32 *)(var_s1 + 0x112C) != 0 && idx != 0) {
                obj = arg0 + idx * 0x58;
                *(u8 *)(obj + 0xE9) |= 0x12;
                *(u8 *)(obj + 0xDB) = -(*(s16 *)(var_s1 + 0x115C) == 0) & 0x7F;
            }
        }
        if (*(s8 *)(var_s1 + 0x1156) == -1) {
            temp_s16 = *(s16 *)(var_s1 + 0x115E);
            if ((s16)temp_s16 == 0) {
                if (*(s8 *)(var_s1 + 0x115A) <= *(s8 *)(var_s1 + 0x115B)) {
                    *(s8 *)(var_s1 + 0x1156) = 0;
                    *(s8 *)(var_s1 + 0x115A) = 0;
                    *(s16 *)(var_s1 + 0x1152) = 0;
                    *(s32 *)(var_s1 + 0x112C) = 0;
                    func_8001844C(arg0, *(u8 *)(var_s1 + 0x1143));
                } else {
                    sum = *(u16 *)(var_s1 + 0x1158) + *(u16 *)(var_s1 + 0x1154);
                    *(u16 *)(var_s1 + 0x1158) = sum;
                    shifted = sum << 0x10;
                    if ((shifted >> 0x10) >= 0x100) {
                        d = *(u8 *)(var_s1 + 0x115A) - (shifted >> 0x18);
                        *(u8 *)(var_s1 + 0x115A) = d;
                        if (d < *(s8 *)(var_s1 + 0x115B)) {
                            *(u8 *)(var_s1 + 0x115A) = *(s8 *)(var_s1 + 0x115B);
                        }
                        *(u16 *)(var_s1 + 0x1158) = (u8)*(u16 *)(var_s1 + 0x1158);
                        *(u8 *)(arg0 + *(u8 *)(var_s1 + 0x1143) * 0x58 + 0xD8) = *(u8 *)(var_s1 + 0x115A);
                        *(u8 *)(arg0 + *(u8 *)(var_s1 + 0x1143) * 0x58 + 0xE9) |= 0x12;
                    }
                }
            } else {
                *(s16 *)(var_s1 + 0x115E) = temp_s16 - 1;
            }
        }
        temp_s16 = *(s16 *)(var_s1 + 0x1152);
        if ((s16)temp_s16 != 0) {
            *(s16 *)(var_s1 + 0x1152) = temp_s16 - 1;
            timer = *(u16 *)(var_s1 + 0x114E) + *(u16 *)(var_s1 + 0x1150);
            *(u16 *)(var_s1 + 0x114E) = timer;
            *(u16 *)(arg0 + *(u8 *)(var_s1 + 0x1143) * 0x58 + 0xEC) = timer;
            *(u8 *)(arg0 + *(u8 *)(var_s1 + 0x1143) * 0x58 + 0xE9) |= 1;
        }
        off += 0x34;
    } while (off < 0x1A0);
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_800188BC);
#endif

#ifdef NON_MATCHING
s32 func_80018DB4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx;
    u8 a2;
    s32 n;
    u8 *base;
    u8 *tbl;
    u8 *tbl2;

    a2 = arg2;
    idx = func_80018870(arg0, 0x18, 0x20);
    if (idx == -1) {
        return 0;
    }
    func_800187EC(arg0, idx);
    base = arg0 + idx * 0x58;
    *(u16 *)(base + 0xDA) = arg2 | 0x7F;
    *(u8 *)(base + 0xB6) = 1;
    *(u8 *)(base + 0xBA) = 2;
    *(s32 *)(base + 0x98) = 0x800;
    *(u8 *)(base + 0xE3) = 0xA;
    *(u8 *)(base + 0xD6) = a2;
    *(u8 *)(base + 0xBC) = arg3;
    if ((s8)arg4 == 0) {
        tbl2 = *(u8 **)(arg0 + 0x38);
        *(s32 *)(base + 0xA0) = (s32)(tbl2 + *(u16 *)(tbl2 + arg1 * 2));
    } else {
        n = (s8)arg4 - 1;
        tbl = *(u8 **)(arg0 + n * 0x30 + 0x12EC);
        *(s32 *)(base + 0xA0) = (s32)(tbl + *(u16 *)(tbl + arg1 * 2));
    }
    return idx;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80018DB4);
#endif


void func_80018EF0(void) {
    u8 *p;
    u8 *q;

    p = D_8002B750;
    if (p[0x10DC] == 1) {
        p[0x10DC] = 0;
    }
    if (D_8002B748 != NULL) {
        q = *(u8 **)(D_8002B748 + 4);
        (*(void (**)(u8 *, s32))(q + 0x1C))(D_8002B748 + *(s16 *)(q + 0x18), D_8002B74C);
    }
}


void func_80018F58(s32 arg0, u8 *arg1, s32 arg2) {
    D_8002B748 = arg1;
    D_8002B74C = arg2;
}

s32 func_80018F70(u8 *arg0) {
    return (*(u8 *)(arg0 + 0x10DE) | (*(u8 *)(arg0 + 0x10DC) | *(u8 *)(arg0 + 0x10DD))) != 0;
}

s32 func_80018F8C(u8 *arg0) {
    return *(u8 *)(arg0 + 0x10DD) != 0;
}

void func_80018F98(void) {
}


void func_80018FA0(Ctx *arg0, s32 arg1) {
    s32 i;

    if (arg1 < 4) {
        for (i = 0; i < 0x14; i++) {
            arg0->bank[arg1].unk2C[i] = i;
        }
    }
    arg0->bank[arg1].unk0 = arg0->bank[arg1].unk4;
    arg0->bank[arg1].unk8 = arg0->bank[arg1].unkC;
    arg0->bank[arg1].unk1C = arg0->bank[arg1].unk20;
    arg0->bank[arg1].unk24 = arg0->bank[arg1].unk28;
    arg0->bank[arg1].unk14 = arg0->bank[arg1].unk18;
    memset(arg0->bank[arg1].unk10, 0, arg0->bank[arg1].unk18 - arg0->bank[arg1].unk10);
    arg0->unk1574[arg1] = 0;
}


void func_80019060(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 off;
    s32 length;
    s32 idx;
    s32 entry;
    s32 end;
    s32 tmp;

    func_80018F58(arg0, arg2, arg3);
    tmp = *(s32 *)arg1;
    off = *(s16 *)(arg1 + 4);
    length = tmp - off;
    if (length == 0) {
        return;
    }
    idx = *(u8 *)(arg1 + 7);
    idx += 6;
    if (idx < 8) {
        s32 p;
        s32 a;
        s32 b;

        p = arg0 + idx * 0x30;
        a = *(s32 *)(p + 0x12D0);
        b = *(s32 *)(p + 0x12D8);
        *(s32 *)(p + 0x12CC) = a;
        *(s32 *)(p + 0x12D4) = b;
    } else {
        s32 v;

        idx = 7;
        v = *(s32 *)(arg0 + 0x1420);
        *(s32 *)(arg0 + 0x1424) = 0x34000;
        *(s32 *)(arg0 + 0x141C) = v;
    }
    entry = arg0 + idx * 0x30;
    func_80019740(arg0, *(s32 *)(entry + 0x12CC), arg1 + 0xC,
                  *(s32 *)(entry + 0x12D4));
    *(u8 *)(arg0 + 0x89) = 0;
    arg1 += off;
    end = *(s32 *)(entry + 0x12D4) + length;
    if (idx == 6) {
        *(u8 *)(arg0 + 0x157A) = 0;
    }
    if (end > 0x38000) {
        *(u8 *)(arg0 + 0x1578) = 0;
    }
    if (end > 0x40000) {
        *(u8 *)(arg0 + 0x1579) = 0;
    }
    if (end > 0x48000) {
        *(u8 *)(arg0 + 0x1574) = 0;
        *(u8 *)(arg0 + 0x89) += 1;
    }
    if (end > 0x52000) {
        *(u8 *)(arg0 + 0x1575) = 0;
        *(u8 *)(arg0 + 0x89) += 1;
    }
    if (end > 0x5C000) {
        *(u8 *)(arg0 + 0x1576) = 0;
        *(u8 *)(arg0 + 0x89) += 1;
    }
    if (end > 0x66000) {
        *(u8 *)(arg0 + 0x1577) = 0;
        *(u8 *)(arg0 + 0x89) += 1;
    }
    SpuSetTransferStartAddr(*(s32 *)(entry + 0x12D4));
    *(u8 *)(arg0 + 0x10DC) = 1;
    SpuRead(arg1, length);
}

s32 func_8001923C(u8 *p, s32 idx) {
    s32 a;
    s32 b;

    p += idx * 0x30;
    a = *(s32 *)(p + 0x12D4);
    b = *(s32 *)(p + 0x12D8);
    return 0xA000 - (a - b);
}


void func_80019268(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 off;
    s32 start;

    if (arg4 < 4) {
        off = arg4 * 0x30;
        start = *(s32 *)(arg0 + off + 0x12DC);
        memset((void *)start, 0,
               *(s32 *)(arg0 + off + 0x12E4) - start - 0x18);
    } else {
        func_80018FA0(arg0, arg4);
    }
    func_80018F58(arg0, arg2, arg3);
    func_800193A0(arg0, arg1, arg4, 0, arg5);
}


void func_80019334(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_80018F58(arg0, arg2, arg3);
    func_800193A0(arg0, arg1, arg4, 1, arg5);
}

#ifdef NON_MATCHING
void func_800193A0(u8 *arg0, s32 arg1_, s32 arg2, s32 arg3, s32 arg4) {
    u8 *arg1 = (u8 *)arg1_;
    u8 *buf;
    u8 *base;
    u8 *start;
    s32 count;
    s32 v;
    s32 len;
    struct {
        s32 mode;
        s32 pad14;
        s32 remaining;
        s32 pad1c;
        s32 save20;
        s32 pad24;
        s32 save28;
        s32 pad2c;
        s32 save30;
        s32 pad34[3];
        volatile s32 saved_a3;
    } frame;
#define save20 frame.save20
#define save28 frame.save28
#define save30 frame.save30
#define sp18 frame.remaining
#define saved_a3 frame.saved_a3
    s32 cmd;
    s32 a3;

    frame.mode = arg3;
    v = *(s32 *)arg1;
    arg1 += 4;
    buf = arg1;
    count = 0;
    base = arg0 + arg2 * 0x30;
    start = arg1;
    a3 = arg4;
    save20 = *(s32 *)(base + 0x12E0);
    save28 = *(s32 *)(base + 0x12E8);
    save30 = *(s32 *)(base + 0x12F0);
    arg1 = arg1 + (v - 4);
    v = *(s32 *)arg1;
    len = *(s16 *)(arg1 + 4);
    sp18 = v - len;

loop:
    cmd = *(u16 *)buf;
    if ((cmd & 0xFFFF) == 0x8000) {
        goto done;
    }
    if (cmd == 0) {
        goto next;
    }
    if (arg2 < 4) {
        v = count + a3;
        *(u8 *)(*(s32 *)(base + 0x12F8) + v) = v;
    }
    cmd = *(s16 *)buf;
    if (cmd < 0) {
        if ((cmd & 0xFFFF) != 0x8001) {
            u8 *q;
            s32 off;
            s32 w;

            q = buf;
            do {
                off = *(s16 *)q;
                q = start - (off << 1);
                off = *(s16 *)q;
            } while (off < 0);
            w = *(s32 *)(base + 0x12DC);
            *(u16 *)(w + (buf - start)) = *(u16 *)(w + (q - start));
            goto next;
        }
        cmd = *(s16 *)buf;
    }
    cmd = *(s16 *)buf;
    if (cmd > 0) {
        u8 *t;
        s32 w;
        s32 n;
        s32 sz;

        t = start + cmd;
        n = count * 2;
        v = a3 * 2;
        sz = *(s32 *)t;
        w = *(s32 *)(base + 0x12DC);
        t += 8;
        *(u16 *)(w + n + v) = *(s32 *)(base + 0x12E0) - w;
        *(s32 *)*(s32 *)(base + 0x12E0) = *(s32 *)(t - 4);
        v = (*(s32 *)(base + 0x12E8) - *(s32 *)(base + 0x12EC)) / 2;
        *(s32 *)(*(s32 *)(base + 0x12E0) + 4) = v | 0x03000000;
        *(s32 *)(*(s32 *)(base + 0x12E0) + 8) = 0;
        *(s32 *)(base + 0x12E0) = *(s32 *)(base + 0x12E0) + 0xC;
        *(s16 *)*(s32 *)(base + 0x12E8) =
            *(s32 *)(base + 0x12F0) - *(s32 *)(base + 0x12EC);
        *(s32 *)(base + 0x12E8) = *(s32 *)(base + 0x12E8) + 2;
        sz -= 8;
        saved_a3 = a3;
        ((void *(*)(void *, void *, u32, s32))memcpy)((void *)*(s32 *)(base + 0x12F0), t, (u32)sz, a3);
        *(s32 *)(base + 0x12F0) = *(s32 *)(base + 0x12F0) + sz;
        a3 = saved_a3;
    }
next:
    buf += 2;
    count++;
    goto loop;

done:
    if (frame.mode == 0) {
        v = (s32)(arg0 + arg2 * 0x30);
        *(s32 *)(v + 0x12E0) = save20;
        *(s32 *)(v + 0x12E8) = save28;
        *(s32 *)(v + 0x12F0) = save30;
    }
    if (arg2 < 8) {
        buf = (u8 *)*(s32 *)(arg0 + arg2 * 0x30 + 0x12CC);
        a3 = *(s32 *)(arg0 + arg2 * 0x30 + 0x12D4);
        v = (s32)(arg1 + 0xC);
    } else {
        *(u8 *)(arg0 + 0x87) = 1;
        v = *(s32 *)(arg0 + 0x44);
        *(u8 *)(arg0 + 0x86) = *(u8 *)v;
        v = *(s32 *)(arg0 + 0x10E8) - 0x1548;
        v = (*(s32 *)(arg0 + 0x44) == arg0 - v)
                ? (s32)(arg0 + 0x1530)
                : *(s32 *)(arg0 + 0x44) + 1;
        *(s32 *)(arg0 + 0x44) = v;
        v = (s32)(arg1 + 0xC);
        buf = (u8 *)*(s32 *)(arg0 + arg2 * 0x30 + 0x12CC);
        a3 = (*(u8 *)(arg0 + 0x86) << 8) | 0x70000;
        *(u8 *)(arg0 + 0x87) = 0;
    }
    func_80019740((s32)arg0, (s32 *)buf, (s32 *)v, a3);
    if (frame.mode != 0) {
        v = *(s32 *)(arg0 + arg2 * 0x30 + 0x12CC);
        *(s32 *)(arg0 + arg2 * 0x30 + 0x12CC) = v + (len - 0x10);
    }
    arg1 += len;
    if (arg2 < 8) {
        buf = arg0 + arg2 * 0x30;
        SpuSetTransferStartAddr(*(s32 *)(buf + 0x12D4));
        if (frame.mode != 0) {
            *(s32 *)(buf + 0x12D4) = *(s32 *)(buf + 0x12D4) + sp18;
        }
        *(u8 *)(arg0 + arg2 + 0x1574) = 0;
        *(u8 *)(arg0 + 0x10DC) = 1;
        SpuRead(arg1, sp18);
    }
    return (s32)arg1;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_800193A0);
#endif

void func_80019740(s32 arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    s32 v;
    u32 n;
    u32 j;
    u32 tmp[2];

    while (1) {
        v = *arg2;
        if (v == -1) {
            goto end;
        }
        j = 0;
        arg2++;
        *arg1++ = v;
        v = *arg2++;
        *arg1++ = v;
        n = (u32)v >> 24;
        if (n != 0) {
            do {
                *arg1++ = *arg2++;
                *arg1++ = *arg2++ + arg3;
                *arg1++ = *arg2++ + arg3;
                *arg1++ = *arg2++;
                *arg1++ = *arg2++;
                j++;
            } while (j < n);
        }
    }
end:
    *arg1 = v;
}

void func_800197F8(s32 arg0, s32 arg1) {
    *(u8 *)(arg0 + (arg1 >> 24) + 0x71) = 0;
}

void func_80019808(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    arg0 += arg1 * 0x30;
    p = *(u8 **)(arg0 + 0x12F8);
    p[arg2] = p[arg3];
}

#ifdef NON_MATCHING
s32 func_80019834(u8 *p, u8 *q, s32 a2, s32 a3, s32 a4) {
    extern s32 func_80019CF0(u8 *, s32, s32);
    u8 *ent;
    u8 *t;
    s32 mode;
    s32 size;
    s32 val;
    s32 idx;
    s32 i;
    s32 off;
    s32 res;

    mode = a3 + 0;
    t = q + *(s32 *)q;
    size = *(s32 *)t - *(s16 *)(t + 4);
    if (mode == 2 && size < 0x81) {
        return func_80019834(p, q, 0x7F40, 1, 0);
    }
    if (*(s32 *)(p + 0x44) == *(s32 *)(p + 0x48)) {
        return -1;
    }
    val = *(s32 *)(q + *(s16 *)(q + 4) + 8);
    if (mode == 2) {
        if (*(u8 *)(p + 0x10DC) != 0) {
            return -1;
        }
        if (*(u8 *)(p + 0x10DF) != 0) {
            return -1;
        }
        idx = func_80019CF0(p, 0x70000000, val);
        if (idx == 0) {
            return 0;
        }
        ent = p + (idx - 1) * 0x34;
        res = ((s32 (*)(u8 *, s32, s32, s32, s32))func_800193A0)(p, q, *(u8 *)(ent + 0x114B) + 8, 0, 0);
        *(u8 *)(ent + 0x114A) = *(u8 *)(ent + 0x114B) + 9;
        if (a4 != 0) {
            *(s32 *)a4 = (*(u8 *)(ent + 0x114B) + 9) << 24;
        }
    } else {
        if (func_80018F70(p) != 0) {
            i = 0;
            do {
                if (*(s32 *)(p + i * 0x34 + 0x112C) != 0) {
                    if (*(s32 *)(p + i * 0x34 + 0x1134) != 0) {
                        if (SpuStGetVoiceStatus() != 0) {
                            func_8001A174(p, i + 1);
                            *(u8 *)(p + 0x10DF) = 1;
                        }
                    }
                }
                i++;
            } while (i < 8);
            return -1;
        }
        idx = func_80019CF0(p, 0x6F000000, val);
        if (idx == 0) {
            return 0;
        }
        ent = p + (idx - 1) * 0x34;
        func_800193A0(p, q, *(u8 *)(ent + 0x114B) + 4, 0, 0);
        res = 0;
        *(u8 *)(ent + 0x114A) = *(u8 *)(ent + 0x114B) + 5;
        *(u8 *)(p + *(u8 *)(ent + 0x114B) + 0x76) = (a4 != 0);
        if (a4 != 0) {
            *(s32 *)a4 = (*(u8 *)(ent + 0x114B) + 5) << 24;
        }
    }
    if (mode != 0) {
        u8 *e;

        e = p + (idx - 1) * 0x34;
        *(u8 *)(e + 0x113E) = (u32)val >> 24;
        *(u8 *)(e + 0x113F) = (u32)val >> 16;
        *(s32 *)(e + 0x1134) = res;
        *(s32 *)(e + 0x1130) = (s32)q;
        *(s32 *)(e + 0x1138) = size;
        *(s16 *)(e + 0x114C) = val;
        *(s16 *)(e + 0x1140) = a2;
        *(u8 *)(e + 0x1142) = 0;
        *(s16 *)(e + 0x113C) = 0;
        *(u8 *)(e + 0x1143) = 0;
        *(u8 *)(e + 0x1156) = 0;
        *(s16 *)(e + 0x1152) = 0;
        *(u8 *)(e + 0x1147) = 0x7F;
        *(u8 *)(e + 0x115A) = 0x7F;
        *(u8 *)(e + 0x1148) = 0;
        *(s16 *)(e + 0x115C) = 0;
        off = 4;
        if (mode == 2) {
            off = 8;
        }
        off = *(u8 *)(e + 0x114B) + off;
        t = *(u8 **)(p + off * 0x30 + 0x12DC);
        off = (s32)t + *(s16 *)t + 4;
        if (mode == 2) {
            *(s32 *)(e + 0x112C) = off;
            *(u8 *)(e + 0x114B) = *(u8 *)(p + 0x86);
            *(u8 *)(p + 0x10DE) = 4;
        }
    }
    return idx;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80019834);
#endif

#ifdef NON_MATCHING
#define F(p, o, t) (*(t *)((u8 *)(p) + (o)))
typedef struct { u8 head[4]; s16 *data; u8 pad[0x18]; u8 *map; u8 tail[0xC]; } Bank_19B70;
typedef struct { u8 pad[0x12D8]; Bank_19B70 banks[8]; } State_19B70;
s32 func_80019B70(u8 *p, s32 a, s8 b, s16 c) {
    extern s32 func_80019CF0(void *, u32, u32);
    s32 offset;
    s32 result;
    u32 *stream;
    u32 word;
    s32 index;
    u32 bank;
    s16 *base;
    u8 *q, *first;
    bank = (u32)a >> 24;
    index = a & 0xFFFFFF;
    if (bank == 0) {
        first = F(p, 0x3C, u8 *);
        stream = (u32 *)((s32)*(s16 *)(first + index * 2) + (s32)first);
        goto ready;
    }
    if ((s32)bank < 5) index = ((State_19B70 *)p)->banks[bank - 1].map[index];
    offset = (base = ((State_19B70 *)p)->banks[bank - 1].data)[index];
    stream = (u32 *)((u8 *)base + offset);
    if (offset == 0) return 0;
ready:
    word = *stream++;
    result = func_80019CF0(p, a, word);
    if (result != 0) {
        q = p + (result - 1) * 0x34;
        F(q, 0x113E, u8) = word >> 24;
        F(q, 0x113F, u8) = word >> 16;
        F(q, 0x1134, s32) = 0;
        F(q, 0x1130, u32) = a;
        F(q, 0x114C, s16) = word;
        F(q, 0x1140, s16) = c;
        F(q, 0x1142, s8) = b;
        F(q, 0x113C, s16) = 0;
        F(q, 0x1143, u8) = 0;
        F(q, 0x1156, u8) = 0;
        F(q, 0x1152, s16) = 0;
        F(q, 0x1147, u8) = 0x7F;
        F(q, 0x115A, u8) = 0x7F;
        F(q, 0x1148, u8) = 0;
        F(q, 0x115C, s16) = 0;
        F(q, 0x114A, u8) = bank;
        F(q, 0x112C, u32 *) = stream;
    }
    return result;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80019B70);
#endif

#ifdef NON_MATCHING
s32 func_80019CF0(u8 *arg0, u32 arg1, s32 arg2) {
    s32 var_t0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_fp;
    s32 var_a3;
    s32 var_a0;
    s32 var_s0;
    u8 *var_a2;
    s32 t1;
    s32 v0;
    s32 v1;

    var_t0 = 0;
    var_s5 = -1;
    var_s4 = -1;
    var_a3 = -1;
    var_s3 = -1;
    var_s2 = -1;
    t1 = ((u32)arg2 >> 16) & 0xFF;
    var_a0 = 0;
    var_a2 = arg0;
    do {
        if (*(s32 *)(var_a2 + 0x112C) != 0) {
            v1 = *(s8 *)(var_a2 + 0x113E);
            if (var_t0 < v1) {
                var_t0 = v1;
                var_s7 = var_a0;
            }
            v0 = *(u8 *)(var_a2 + 0x114A);
            if (v0 == 5) {
                var_s5 = var_a0;
                var_s6 = v1;
            }
            if (v0 == 6) {
                var_s4 = var_a0;
                var_fp = v1;
            }
            v0 = *(s8 *)(var_a2 + 0x113F);
            if (v0 != 0 && v0 == t1) {
                var_s3 = var_a0;
            }
        } else {
            var_a3 = var_a0;
        }
        var_a0++;
        var_a2 += 0x34;
    } while (var_a0 < 8);

    if ((arg1 >> 24) == 0x70) {
        v0 = *(s32 *)(arg0 + 0x10EC);
        var_s2 = v0 & 1;
        *(s32 *)(arg0 + 0x10EC) = v0 + 1;
    }
    if ((arg1 >> 24) == 0x6F) {
        if (*(u8 *)(arg0 + 0x74) != 0) {
            if (var_s5 != -1 || *(u8 *)(arg0 + 0x76) != 0) {
                if (var_s4 == -1 && *(u8 *)(arg0 + 0x77) == 0) {
                    var_s2 = 1;
                    goto choose_one;
                }
                goto block_29;
            }
            goto choose_zero;
        } else {
            if (var_s4 == -1 && *(u8 *)(arg0 + 0x77) == 0) {
                var_s2 = 1;
            choose_one:
                *(u8 *)(arg0 + 0x74) = var_s2;
                goto block_47;
            }
            goto block_E7C;
        }
    block_E7C:
        if (var_s5 == -1 && *(u8 *)(arg0 + 0x76) == 0) {
        choose_zero:
            var_s2 = 0;
            *(u8 *)(arg0 + 0x74) = 0;
            goto block_47;
        }
    block_29:
        if (var_s3 != -1) {
            if (*(s8 *)(arg0 + var_s3 * 0x34 + 0x113E) < (arg2 >> 24)) {
                return 0;
            }
            ((void (*)(u8 *, s32, s32, s32))func_8001A174)(arg0, var_s3 + 1, var_a2, var_a3);
        }
        v1 = *(u8 *)(arg0 + 0x76);
        v0 = *(u8 *)(arg0 + 0x77);
        if ((v0 & v1) != 0) {
            return 0;
        }
        if (v1 != 0) {
            if ((u32)var_fp < ((u32)arg2 >> 24)) {
                return 0;
            }
            var_s2 = 1;
        } else if (v0 != 0) {
            if ((u32)var_s6 < ((u32)arg2 >> 24)) {
                return 0;
            }
            var_s2 = 0;
        } else if (var_fp < var_s6) {
            if ((u32)var_s6 < ((u32)arg2 >> 24)) {
                return 0;
            }
            var_s2 = 0;
        } else if (var_s6 < var_fp) {
            if ((u32)var_fp < ((u32)arg2 >> 24)) {
                return 0;
            }
            var_s2 = 1;
        } else {
            if ((u32)var_s6 < ((u32)arg2 >> 24)) {
                return 0;
            }
            var_s2 = *(u8 *)(arg0 + 0x74) < 1;
        }
        *(u8 *)(arg0 + 0x74) = var_s2;
        if (var_s2 == 0) {
            var_s0 = var_s5 + 1;
            func_8001A174(arg0, var_s0);
            *(u8 *)(arg0 + var_s5 * 0x34 + 0x114B) = 0;
        } else {
            var_s0 = var_s4 + 1;
            func_8001A174(arg0, var_s0);
            *(u8 *)(arg0 + var_s4 * 0x34 + 0x114B) = var_s2;
        }
        return var_s0;
    }
block_47:
    if (var_s3 == -1) {
        if (var_a3 == -1) {
            var_s0 = var_s7 + 1;
            ((void (*)(u8 *, s32, s32, s32))func_8001A174)(arg0, var_s0, var_a2, var_a3);
            *(u8 *)(arg0 + var_s7 * 0x34 + 0x114B) = var_s2;
        } else {
            *(u8 *)(arg0 + var_a3 * 0x34 + 0x114B) = var_s2;
            return var_a3 + 1;
        }
        return var_s0;
    }
    if (*(s8 *)(arg0 + var_s3 * 0x34 + 0x113E) < (arg2 >> 24)) {
        return 0;
    }
    if ((arg1 >> 24) == 0x70) {
        *(s16 *)(arg0 + 0x3264) = 0x64;
        if (*(s32 *)(arg0 + var_s3 * 0x34 + 0x1134) != 0) {
            u8 b = *(u8 *)(arg0 + var_s3 * 0x34 + 0x114B);
            if (*(s8 *)(arg0 + b * 0x38 + 0xBBE) == 0) {
                ((void (*)(u8 *, s32, s32, s32))func_8001A144)(arg0, b, var_a2, var_a3);
            }
        }
    }
    var_s0 = var_s3 + 1;
    func_8001A174(arg0, var_s0);
    *(u8 *)(arg0 + var_s3 * 0x34 + 0x114B) = var_s2;
    return var_s0;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_80019CF0);
#endif

typedef struct {
    u8 pad[0x112C];
    s32 unk112C;
    s32 unk1130;
    u8 pad2[0x34 - 8];
} Slot;

s32 func_8001A100(u8 *arg0, s32 arg1) {
    Slot *p;

    if (arg1 == 0 || (p = (Slot *)(arg0 + (arg1 - 1) * 0x34), p->unk112C == 0)) {
        return 0;
    }
    return p->unk1130;
}

void func_8001A144(s32 p, s32 val) {
    s32 cur;
    s32 end;

    cur = *(s32 *)(p + 0x48);
    *(u8 *)cur = val;
    end = *(s32 *)(p + 0x10E8) - 0x1548;
    if (*(s32 *)(p + 0x48) != p - end) {
        cur = *(s32 *)(p + 0x48) + 1;
    } else {
        cur = p + 0x1530;
    }
    *(s32 *)(p + 0x48) = cur;
}

#ifdef NON_MATCHING
void func_8001A174(u8 *obj, s32 a1) {
    u8 *e;
    s32 flags;
    s32 i;
    s32 v;
    flags = 0;
    if (a1 == 0) { return; }
    obj[0x87] = 1;
    e = obj + (a1 - 1) * 0x34;
    if (*(s32 *)(e + 0x112C) != 0) {
        if (*(u8 *)(e + 0x1143) != 0) {
            s32 k = *(u8 *)(e + 0x1143) * 0x58;
            v = *(u8 *)(e + 0x1143);
            *(u8 *)(obj + k + 0xB6) = 0;
            i = 0;
            do {
                if (*(u8 *)(obj + i * 0x38 + 0xBBF) == v &&
                    *(s8 *)(obj + i * 0x38 + 0xBBE) != 0) {
                    if ((*(u32 *)(obj + i * 0x38 + 0xB98) & 0x20000) == 0) {
                        func_8001A144(obj, i);
                        *(u8 *)(obj + i * 0x38 + 0xBBE) = 0;
                    }
                    *(s32 *)(obj + *(u8 *)(obj + i * 0x38 + 0xBBF) * 0x58 + 0xAC) -= 1;
                    flags |= 1 << i;
                }
                i++;
            } while (i < 0x18);
            e = obj + (a1 - 1) * 0x34;
            if (*(s32 *)(e + 0x1134) != 0) {
                if (flags != 0) { *(u32 *)(obj + 0x3260) |= flags; }
            } else {
                SpuSetKey(0, flags);
            }
        }
        e = obj + (a1 - 1) * 0x34;
        *(s32 *)(e + 0x112C) = 0;
    }
    obj[0x87] = 0;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main2", func_8001A174);
#endif

void func_8001A330(u8 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    u8 *p;
    s32 t;

    if (arg1 != 0) {
        p = arg0 + (arg1 - 1) * 0x34;
        if (*(s32 *)(p + 0x112C) != 0) {
            t = 0x7800 / arg2;
            *(u8 *)(p + 0x115A) = 0x7F;
            *(u16 *)(p + 0x1158) = 0;
            *(u8 *)(p + 0x115B) = 0;
            *(s8 *)(p + 0x1156) = -1;
            *(s16 *)(p + 0x115E) = arg3;
            *(s16 *)(p + 0x1154) = t;
        }
    }
}

void func_8001A398(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *p;
    s32 t;

    if (arg1 != 0) {
        p = arg0 + (arg1 - 1) * 0x34;
        if (*(s32 *)(p + 0x112C) != 0) {
            t = (arg2 * 0x11111) >> 16;
            *(s16 *)(p + 0x114E) = 0x2000;
            *(s16 *)(p + 0x1152) = t * 2;
            *(s16 *)(p + 0x1150) = 0x2000 / t;
        }
    }
}

void func_8001A410(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *p;
    s32 t;

    if (arg1 != 0) {
        p = arg0 + (arg1 - 1) * 0x34;
        if (*(s32 *)(p + 0x112C) != 0) {
            t = (arg2 * 0x11111) >> 16;
            *(s16 *)(p + 0x114E) = 0x2000;
            *(s16 *)(p + 0x1152) = t * 2;
            *(s16 *)(p + 0x1150) = -0x1000 / t;
        }
    }
}

void func_8001A488(u8 *a0, s32 a1, s16 a2) {
    u8 *p;

    if (a1 == 0) {
        return;
    }
    p = a0 + (a1 - 1) * 0x34;
    if (*(s32 *)(p + 0x112C) == 0) {
        return;
    }
    *(s16 *)(p + 0x115C) = a2;
}

void func_8001A4C4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, u8 arg5) {
    u8 *p;

    if (arg1 != 0) {
        p = arg0 + (arg1 - 1) * 0x34;
        if (*(s32 *)(p + 0x112C) != 0) {
            *(s32 *)(arg0 + arg1 * 0x34 + 0x1110) =
                (arg2 << 24) | ((arg3 & 0xFF) << 16) | (s16)arg4;
            p[0x1149] = arg5;
            p[0x1148] = 1;
        }
    }
}

s16 func_8001A544(s32 unused, s32 arg1, s32 arg2) {
    u8 *p;
    s16 v;
    u16 cur;
    s16 off;

    p = (u8 *)(arg2 * 2 + arg1) + 4;
    v = *(s16 *)p;
    cur = *(u16 *)p;
    if (v < 0) {
        do {
            if (cur == 0x8000) {
                return -1;
            }
            p = (u8 *)(arg1 - (s16)cur * 2) + 4;
            v = *(s16 *)p;
            cur = *(u16 *)p;
        } while (v < 0);
    }
    off = (s16)cur;
    if (off == 0) {
        return 0;
    }
    return *(s16 *)(off + arg1 + 8);
}

typedef struct {
    u8 pad[0x112C];
    s32 unk112C;
    u8 pad2[0x114C - 0x1130];
    s16 unk114C;
} Slot2;

s16 func_8001A5B4(u8 *arg0, s32 arg1) {
    Slot2 *p;

    if (arg1 == 0 || (p = (Slot2 *)(arg0 + (arg1 - 1) * 0x34), p->unk112C == 0)) {
        return 0;
    }
    return p->unk114C;
}


void func_8001A5F8(s32 *arg0, s32 arg1) {
    DisableEvent(arg0[8]);
    arg0[0xC95] = 0;
    func_80018394(arg0);
    SpuSetKey(0, arg0[0xC95]);
    arg0[0xC] = arg1;
    arg0[0xD] = arg1;
    func_800185CC(arg0, 0);
    arg0[0x10] |= 1;
    EnableEvent(arg0[8]);
}

void func_8001A670(u8 *arg0) {
    arg0[0xC] = 1;
}

#define F(p, o, t) (*(t *)((u8 *)(p) + (o)))
typedef struct { u8 pad[0x9C]; s32 a, b; u8 padA4[4]; s32 c; u8 padAC[10]; u8 active; u8 padB7[0x32]; u8 flags; } Entry;
void func_8001A67C(u8 *p, u8 *a, s16 b, s16 c) {
    s32 delta, i;
    u8 *old;
    s32 q;
    DisableEvent(F(p, 0x20, s32));
    old = F(p, 0x34, u8 *);
    F(p, 0x30, u8 *) = a;
    F(p, 0x34, u8 *) = a;
    delta = a - old;
    F(p, 0x16, s16) = 0x7800 / b;
    if (!c || F(p, 0x88, u8) || F(F(p, 0x30, u8 *), 4, s32) != F(p, 0x90, s32)) {
        F(p, 0x88, u8) = 0; F(p, 0x3254, s32) = 0;
        func_80018394(p); SpuSetKey(0, F(p, 0x3254, s32)); func_800185CC(p, 0);
    } else {
        func_800185CC(p, 1);
        i = 0;
        do {
            q = (s32)p + i * 0x58;
            ((Entry *)q)->a += delta;
            if (((Entry *)q)->b != 0xFFFF) { ((Entry *)q)->active = 1; ((Entry *)q)->b += delta; }
            ((Entry *)q)->c += delta; ((Entry *)q)->flags |= 0x3F;
            i++;
        } while (i < 24);
        F(p, 0xD, u8) = 1;
    }
    F(p, 8, u8) = 1; F(p, 0x40, s32) |= 1; EnableEvent(F(p, 0x20, s32));
}

void func_8001A7E0(u8 *arg0, s16 arg1) {
    arg0[0x9] = 1;
    *(s16 *)(arg0 + 0x16) = 0x7800 / arg1;
}

void func_8001A804(u8 *p, s16 a) {
    s16 b = a;
    if (a >= 2) b = a - 1;
    p[0xA] = 1;
    *(s16 *)(p + 0x18) = 0x7800 / b;
}

void func_8001A840(u8 *arg0, s16 arg1) {
    s16 v1;

    v1 = arg1;
    if (v1 >= 3) {
        v1 -= 2;
    }
    arg0[0xB] = 1;
    *(s16 *)(arg0 + 0x18) = 0x7800 / v1;
}

void func_8001A87C(u8 *arg0, s8 arg1, s16 arg2) {
    arg0[0x13] = arg1;
    *(s16 *)(arg0 + 0x14) = arg2;
    arg0[0xE] = 1;
}

void func_8001A890(u8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0x14) = arg1;
    *(u8 *)(arg0 + 0xF) = 1;
}

void func_8001A8A0(u8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0x40) |= 8;
    } else {
        *(s32 *)(arg0 + 0x40) &= ~8;
    }
}

void func_8001A8C8(u8 *arg0, u8 arg1) {
    *(u8 *)(arg0 + 0x12) = arg1;
    *(u8 *)(arg0 + 0x7) = 1;
}

void func_8001A8D8(u8 *arg0, u8 arg1, u32 arg2, u8 *arg3, s32 arg4) {
    u8 *p;

    p = arg0 + 0xE9;
    if (arg2 != 0) {
        do {
            if (arg2 & 1) {
                *arg3 = arg1;
                *p |= arg4;
            }
            arg2 >>= 1;
            arg3 += 0x58;
            p += 0x58;
        } while (arg2 != 0);
    }
}


void func_8001A91C(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xDA, 0x12);
}


void func_8001A948(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xDB, 0x12);
}


void func_8001A974(s32 a0, s32 a1, s32 a2) {
    func_8001A8D8(a0, a1 & 0xFF, a2, a0 + 0xD6, 0x32);
}


void func_8001A9A0(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xBF, 1);
}


void func_8001A9CC(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xD1, 1);
}


void func_8001A9F8(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xD5, 1);
}


void func_8001AA24(s32 arg0, s32 arg1, s32 arg2) {
    func_8001A8D8(arg0, arg1 & 0xFF, arg2, arg0 + 0xB7, 0);
}

void func_8001AA4C(void) {
}


void func_8001AA54(u8 *arg0, s32 arg1) {
    func_8001A8D8(arg0, 1, arg1, arg0 + 0xC2, 0);
}

void func_8001AA80(u8 *arg0, u8 arg1) {
    arg0[0x11] = arg1;
    arg0[6] = 1;
}

void func_8001AA90(u8 *arg0, s32 arg1, s32 arg2) {
    s32 hi;

    hi = (arg2 & 0xFF) << 8;
    *(s16 *)(arg0 + 0x50) = (arg1 & 0xFF) + hi;
    *(u8 *)(arg0 + 0x10) = 1;
}

u8 *func_8001AAB0(u8 *arg0) {
    return arg0 + 0x150C;
}

u8 *func_8001AAB8(u8 *arg0) {
    return arg0 + 4;
}

u8 *func_8001AAC0(u8 *arg0) {
    return arg0 + 0x20;
}

u8 *func_8001AAC8(u8 *arg0) {
    return arg0 + 0x98;
}

u8 *func_8001AAD0(u8 *arg0) {
    return arg0 + 0xB98;
}

u8 func_8001AAD8(u8 *arg0, s32 arg1) {
    return *(u8 *)(arg0 + arg1 + 0x1574);
}

void func_8001AAE8(u8 *arg0, s32 arg1, u8 arg2) {
    *(u8 *)(arg0 + arg1 + 0x1574) = arg2;
}

u8 func_8001AAF4(u8 *arg0) {
    return *(u8 *)(arg0 + 0x89);
}

void func_8001AB00(u8 *arg0) {
    *(s32 *)*(s32 **)(arg0 + 0x1390) = -1;
    *(s32 *)*(s32 **)(arg0 + 0x13C0) = -1;
    *(s32 *)*(s32 **)(arg0 + 0x1450) = -1;
    *(s32 *)*(s32 **)(arg0 + 0x1480) = -1;
    *(s32 *)*(s32 **)(arg0 + 0x14B0) = -1;
    *(s32 *)*(s32 **)(arg0 + 0x14E0) = -1;
}


s32 func_8001AB48(s32 unused, u8 *ctx, u8 *p, s32 a3, s32 n) {
    u8 pad[8];
    s32 i;
    s32 v;

    if (bcmp(p, D_8002AB7C, 3) != 0) {
        return 0;
    }
    if (n > 0) {
        i = 0;
        do {
            if (*(s32 *)(p + 0xC) == 0) {
                return 0;
            }
            p += *(s32 *)(p + 0xC);
            i++;
        } while (i < n);
    }
    v = *(u8 *)(p + 3);
    *(s32 *)(ctx + 4) = 1;
    *(s32 *)(ctx + 0) = 0;
    *(u8 *)(ctx + 0x19) = 0;
    *(s32 *)(ctx + 0xC) = a3;
    *(u8 **)(ctx + 0x10) = p + 0x10;
    *(u8 *)(ctx + 0x18) = v;
    *(s32 *)(ctx + 8) = *(s32 *)(p + 8);
    *(s32 *)(ctx + 0x14) = a3 + *(s32 *)(p + 8);
    return 1;
}


s32 func_8001AC1C(s32 arg0, u8 *ctx, s32 size) {
    s32 n;
    s32 m;

    switch (*(u8 *)(ctx + 0x18)) {
    case 0:
        n = *(s32 *)(ctx + 8);
        if (n < size) {
            size = n;
        }
        memcpy(*(u8 **)(ctx + 0xC), *(u8 **)(ctx + 0x10), size);
        m = *(s32 *)(ctx + 8) - size;
        *(u8 **)(ctx + 0xC) += size;
        *(u8 **)(ctx + 0x10) += size;
        *(s32 *)(ctx + 8) = m;
        return m == 0;
    case 1:
        return func_8001ACF8(arg0, ctx, size);
    case 2:
        return func_8001B1F8(arg0, ctx, size);
    }
}
