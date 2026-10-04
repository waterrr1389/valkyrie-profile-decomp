#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"

void func_80010000(void) {
}

INCLUDE_ASM("asm/main/nonmatchings/main", func_80010008);


s32 func_800100DC(void) {
    return D_8002F8F0;
}

s32 func_800100EC(s8 *buf, s32 value, s32 width, s8 pad) {
    s8 tmp[20];
    s8 *p;
    s8 *q;
    s32 i;
    s32 n;
    s32 j;

    p = buf;
    if (value < 0) {
        *p++ = '-';
        value = -value;
    }
    if (width > 0) {
        p += width;
        *p = 0;
        i = 0;
        while (i < width) {
            *--p = value % 10 + '0';
            value /= 10;
            if (value == 0) {
                i++;
                break;
            }
            i++;
        }
        if (i < width) {
            for (;;) {
                *--p = pad;
                i++;
                if (i >= width) {
                    break;
                }
            }
        }
        return buf;
    }
    q = tmp + 12;
    n = 0;
    do {
        *--q = value % 10 + '0';
        value /= 10;
        n++;
    } while (value > 0);
    j = 0;
    if (n > 0) {
        do {
            *p++ = *q++;
            j++;
        } while (j < n);
    }
    *p = 0;
    return buf;
}


void func_80010224(void) {
    s32 *base;
    s32 *p;
    s32 *q;
    s32 i;

    i = 1;
    base = D_8002B4D8;
    p = base + 1;
    q = base + 0x20;
    do {
        *p = *p - *q;
        p++;
        q++;
        i++;
    } while (i < 0x19);

    i = 0x19;
    base = D_8002B4D8;
    p = base + 0x19;
    q = base + 1;
    do {
        *p = *p - *q;
        p++;
        q++;
        i++;
    } while (i < 0x38);
}

#ifdef NON_MATCHING
void func_8001029C(s32 a0) {
    extern s32 D_8002B5B4;
    s32 *p = &D_8002B5B4;
    s32 *q;
    s32 x, i, j, y;

    *p = a0;
    x = 1;
    i = 1;
    q = p - 0x37;
    j = 0x15;
    y = a0;
    while (1) {
        if (i >= 0x37) break;
        q[j % 55] = x;
        x = y - x;
        y = q[j % 55];
        j += 0x15;
        i++;
    }
    func_80010224();
    func_80010224();
    func_80010224();
    D_8002B4D4 = 0x37;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main", func_8001029C);
#endif


s32 func_8001034C(void) {
    s32 v;

    v = D_8002B4D4 + 1;
    D_8002B4D4 = v;
    if (v >= 0x38) {
        func_80010224();
        D_8002B4D4 = 1;
    }
    return D_8002B4D8[D_8002B4D4];
}


s32 func_800103B4(void) {
    return func_8001034C() & 0x7FFF;
}


u32 func_800103D4(s32 a, s32 b) {
    u32 r;
    u32 res;
    s32 d;

    if (b != a) {
        r = func_8001034C();
        d = b - a;
        res = d >= 0 ? r % d + a : r % (a - b) + a;
    } else {
        res = b;
    }
    return res;
}


s32 func_80010460(s32 a) {
    return func_800103D4(-a, a);
}

void func_80010484(s32 a) { func_800103D4((-a) << 12, a << 12); }


s32 func_800104B0(s32 a, s32 b) {
    return func_800103D4(a << 12, b << 12);
}


u32 func_800104D4(u32 a) {
    u32 r;

    if (a != 0) {
        r = func_8001034C() % a;
    } else {
        r = 0;
    }
    return r;
}


s32 func_80010528(void) {
    return (GetSr() ^ 1) & 1;
}

void func_8001054C(void) {
    s32 *buf;
    s32 *p;
    s32 i;

    buf = __builtin_vec_new(0x1000);
    if (buf != NULL) {
        p = buf;
        for (i = 0x3FD; i >= 0; i--) {
            *p++ = 0;
        }
        p[0] = 0x03E00008;
        p[1] = 0;
        ((void (*)(void))buf)();
        __builtin_delete(buf);
    }
}

void func_800105B0(s32 arg0, u8 *arg1, s32 arg2) {
    func_800122C0((u8 *)arg0 + 1, arg1, (u8 *)func_8002F824, 0);
    func_8001054C();
    __builtin_delete(arg1);
    if (arg2 != 0) {
        __asm__ volatile("lui $fp, 0x8020\n\tlui $sp, 0x8020");
    }
    func_8002F824(arg0);
}


s32 func_80010628(void) {
    func_80010000();
    func_80010650(0);
    return 0;
}

void func_80010650(s32 arg0) {
    extern s32 D_8002B5C0;
    extern void ResetGraph(s32);
    extern void InitCARD(s32);
    extern void StartCARD(void);
    extern void func_8001029C(s32);
    extern void ChangeClearPAD(s32);
    extern void _bu_init(void);
    extern void TestEvent(s32);
    extern void func_80080508(s32, s32);
    extern void func_800805B8(s32, s32);
    extern void func_800805F8(s32, s32);
    extern void func_80080668(s32, s32);
    extern void func_800806B8(s32, s32, s32);
    extern void func_80080738(s32, s32, s32);
    extern u32 strlen(const char *);
    extern void *memchr(const void *, s32, u32);
    extern s32 toupper(s32);
    extern s32 tolower(s32);
    extern s32 putchar(s32);
    extern void SetDrawMove(s32, s32, s32, s32);
    extern void PadSetMainMode(s32, s32, s32);
    extern void func_80080228(s32);
    u8 *p;
    u8 *q;
    u8 *r;
    s32 x;

    __asm__ volatile("lui $fp, 0x8020\n\tlui $sp, 0x8020");
    ResetCallback();
    func_800130A4(0x80090000, 0x16E000);
    p = __builtin_new(0x970C);
    func_800140D0((s32)(p + 4));
    q = p + 0x10;
    func_80011604(q);
    func_8001225C(p + 0x6418);
    func_80012184(p + 0x6420);
    r = p + 0x64A4;
    func_80014604(r);
    D_8002B5C0 = (s32)p;
    ResetGraph(0);
    func_80014138(D_8002B5C0 + 4);
    if (arg0 == 0) {
        InitCARD(0);
        StartCARD();
        func_8001029C(0x4E421714);
    }
    x = func_80013204(0x80000);
    func_8001175C((s32)q, 1);
    ((void (*)(u8 *, s32, s32))func_8001190C)(q, x, 0);
    func_80014A6C(r);
    if (arg0 == 0) {
        ChangeClearPAD(0);
        _bu_init();
    }
    while (func_80011C90(q) != 0) {
    }
    func_800105B0(D_8002B5C0, (u8 *)x, 1);
    TestEvent(0);
    func_80080508(0, 0);
    func_800805B8(0, 0);
    func_800805F8(0, 0);
    func_80080668(0, 0);
    func_800806B8(0, 0, 0);
    func_80080738(0, 0, 0);
    strlen(0);
    memcpy(0, 0, 0);
    memset(0, 0, 0);
    memchr(0, 0, 0);
    bcmp(0, 0, 0);
    toupper(0);
    tolower(0);
    putchar(0);
    SetDrawMove(0, 0, 0, 0);
    func_800251F0();
    PadSetMainMode(0, 1, 2);
    func_80080228(0);
}
