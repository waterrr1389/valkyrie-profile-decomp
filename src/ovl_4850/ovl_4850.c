#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "ovl_4850.h"

void func_8002F824(s32 arg0) {
    func_80039BF0();
    ((Ovl4850Obj *)D_8002F8F0)->unk4->unk14((s32)((Ovl4850Obj *)D_8002F8F0) + ((Ovl4850Obj *)D_8002F8F0)->unk4->unk10, arg0);
    ((Ovl4850Obj *)D_8002F8F0)->unk4->unkC((s32)((Ovl4850Obj *)D_8002F8F0) + ((Ovl4850Obj *)D_8002F8F0)->unk4->unk8);
}

void func_8002F8A4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 8) = arg1;
}

s32 func_8002F8AC(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}

u8 *func_8002F8B8(u8 *arg0) {
    *(u8 **)(arg0 + 4) = D_8002F8D8;
    D_8002F8F0 = (s32)arg0;
    return arg0;
}

/* Zero data blob that follows the function inside the overlay's code segment. */
u8 D_8002F8D8[12] __attribute__((section(".text"))) = { 0 };

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8002F8E4);

void func_8002F8F4(void) {
    D_8003BA34.unk0 = func_80014484(D_8003F23C, 0);
    D_8003BA4C.unk0 = func_80014484(D_8003F23C, 1);
    D_8003BA34.unk2 = func_8001449C(D_8003F23C, 0);
    D_8003BA4C.unk2 = func_8001449C(D_8003F23C, 1);
    D_8003BA34.unk4 = func_800144B4(D_8003F23C, 0);
    D_8003BA4C.unk4 = func_800144B4(D_8003F23C, 1);
    D_8003BA34.unk6 = func_80013DD0(D_8003F23C, 0, &D_8003BA34.unk8, &D_8003BA34.unkC, &D_8003BA34.unk10, &D_8003BA34.unk14);
    D_8003BA4C.unk6 = func_80013DD0(D_8003F23C, 1, &D_8003BA4C.unk8, &D_8003BA4C.unkC, &D_8003BA4C.unk10, &D_8003BA4C.unk14);
    func_80014500(D_8003F23C, 0);
    func_80014500(D_8003F23C, 1);
}

void func_8002FA34(void) {
    memset(&D_8003BA34, 0, 0x18);
    memset(&D_8003BA4C, 0, 0x18);
    func_8001444C(D_8003F23C, 3);
    func_8001445C(D_8003F23C, 0x14);
    func_80014500(D_8003F23C, 0);
    func_80013D24(D_8003F23C, 0, 0, 0, 0, 0, 0x20);
    func_80013D78(D_8003F23C, 0, 0x50, 0x50, 0x50, 0x50);
    func_80013DBC(D_8003F23C, 0, 1);
}

typedef struct {
    u8 pad0[4];
    s16 unk4;
    s16 unk6;
} Unk8002FB04;

void func_8002FB04(Unk8002FB04 *arg0) {
    s32 prod = arg0->unk4 * arg0->unk6;
    s32 q;

    if (prod < 0x100) {
        arg0->unk4 = prod;
    } else {
        arg0->unk4 = 0x100;
    }

    q = prod / 256;
    arg0->unk6 = q;
    if ((q << 16) <= 0) {
        arg0->unk6 = 1;
    }
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8002FB60);

void func_8002FCF8(void) {
    u8 *p;
    s32 i;

    p = D_8003F118;
    for (i = 0x7F; i >= 0; i--) {
        *(s32 *)p = 0;
        p += 0xEC;
    }
}

void func_8002FD1C(void) {
    u8 *p;
    s32 i;
    void (*f)(u8 *);

    p = D_8003F118;
    i = 0;
    do {
        f = *(void (**)(u8 *))p;
        if (f != NULL) {
            f(p);
        }
        i++;
        p += 0xEC;
    } while (i < 0x80);
}

u8 *func_8002FD78(void) {
    u8 *p;
    s32 i;

    p = D_8003F118;
    for (i = 0; i < 0x80; i++) {
        if (*(s32 *)p == 0) {
            memset(p, 0, 0xEC);
            return p;
        }
        p += 0xEC;
    }
    return NULL;
}

u8 *func_8002FDDC(s32 arg0) {
    u8 *p = D_8003F118;
    s32 i;
    u8 *ret;

    for (i = 0; i < 0x80; i++) {
        ret = p;
        if (*(s32 *)p == arg0) {
            return ret;
        }
        p += 0xEC;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8002FE14);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8003080C);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80030ECC);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80031990);

void func_80031B0C(s32 arg0) {
    s32 t;
    s32 q;
    s32 x;
    s32 y;
    u8 *p;
    u8 d8;
    p = &D_8003F1D8;
    d8 = *p;
    t = (arg0 - D_8003F164) << 8;
    q = t / 10;
    x = arg0 << 8;
    y = D_8003F164 << 8;
    D_8003F1B4 = x;
    *p = d8 | 2;
    D_8003F1C4 = q;
    D_8003F1A4 = y;
    D_8003F1D4 = q / 25;
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80031B98);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80031ED8);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80032030);

void func_80032C64(void) {
    s32 *temp_v0;
    temp_v0 = (s32 *)func_8002FDDC(func_80032030);
    if (temp_v0 != NULL) {
        u16 v = D_8003F236;
        *temp_v0 = 0;
        D_8003F236 = v & 0xFFFB;
    }
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80032CB0);

void func_80032FFC(Ovl4850T *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 d;

    d = arg3 - arg1;
    arg0->unk66 = arg5;
    arg0->unk6A = 0xF0 - arg5 - arg6;
    arg0->unk64 = (arg7 << 8) / d;
    arg0->unk68 = ((arg3 - arg7 - arg8) << 8) / d;
}

void func_80033054(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_80012EC8(D_8003F038, arg0, arg1, (arg2 - arg6) - arg7, (arg3 - arg4) - arg5);
    func_80012E90_ovl(D_8003F038 + 0xCC, arg0, arg1, arg2, arg3);
    func_80032FFC((Ovl4850T *)(D_8003F038 + 0x70), arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void func_80033140(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    func_80012E90_ovl((DISPENV *)D_8003F094, a0, a1, a2, a3);
    func_80012EC8(D_8003F094 + 0x14, a0, a1, a2 - a6 - a7, a3 - a4 - a5);
    func_80032FFC((Ovl4850T *)(D_8003F094 - 0x5C), a0, a1, a2, a3, a4, a5, a6, a7);
}

typedef struct {
    u32 a;
    u32 b;
} __attribute__((packed)) COPY8;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} COPY16;

void func_8003322C(void) {
    s16 r[4];
    s32 n;
    u8 *env;
    void **slot;
    void *pix;

    func_80033824();
    D_8003F12C = (Ovl4850Ctx *)func_80012220(D_8003F250, 3);
    SetGraphDebug(0);
    func_800394B4();
    n = 8;
    func_80033054(0, 0, 0x140, 0xF0, n, n, 0, 0);
    func_80033140(0, 0x100, 0x140, 0xF0, n, n, 0, 0);
    env = &D_8003F04E;
    env[0] = 1;
    D_8003F04F = 1;
    D_8003F050 = 1;
    D_8003F053 = 0;
    D_8003F052 = 0;
    D_8003F051 = 0;
    D_8003F0BE = 1;
    D_8003F0BF = 1;
    D_8003F0C0 = 1;
    D_8003F0C3 = 0;
    D_8003F0C2 = 0;
    D_8003F0C1 = 0;
    PutDispEnv(env + 0x46);
    PutDrawEnv(env - 0x16);
    D_8003F140 = 0;
    D_8003F13C = 0;
    D_8003F138 = 0;
    D_8003F144 = 0;
    D_8003F14C = 0;
    memset(&D_8003F1E0, 0, 0x40);
    D_8003F228 = 0xC0;
    D_8003F22C = 0xC0;
    D_8003F222 = 0;
    D_8003F224 = 0;
    D_8003F226 = 0;
    D_8003F22A = 0;
    D_8003F236 = 8;
    memset(&D_8003F198, 0, 0x44);
    memset(D_8003F150, 0xFF, 0x8000);
    D_8003F232 = 0;
    D_8003F230 = 0;
    D_8003F158 = D_8003F154;
    D_8003F134 = func_80012220(D_8003F250, 6) + 0x5EC;
    if (D_8003F12C->unk3C0 & 8) {
        *(COPY8 *)&D_8003F178 = *(COPY8 *)&D_8003F12C->unkE8;
        *(COPY16 *)&D_8003F168 = *(COPY16 *)&D_8003F12C->unkD8;
    } else {
        D_8003F178 = -0x258;
        D_8003F17A = 0;
        D_8003F17C = 0;
        D_8003F168 = 0x4000;
        D_8003F16C = 0x4000;
        D_8003F170 = 0x4000;
    }
    D_8003F160 = 0;
    D_8003F162 = 0;
    D_8003F164 = 0x478;
    func_8002FCF8();
    slot = (void **)func_8002FD78();
    pix = (void *)D_8003F15C;
    *slot = (void *)func_800339D4;
    r[0] = 0x300;
    r[1] = 0x1E0;
    r[2] = 0x100;
    r[3] = 0x20;
    StoreImage(r, pix);
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80033534);

void func_80033664(s32 *arg0, u8 *arg1) {
    switch (*arg0) {
    case 3: {
        u8 *p;

        p = (u8 *)func_8001226C(D_8003F244, arg1, 0);
        func_800122C0(D_8003F244, arg1, p, 0);
        func_8002FB60(p, 0);
        DrawSync(0);
        func_8001336C(p);
        break;
    }
    case 0x11: {
        u8 *p;

        p = (u8 *)func_8001226C(D_8003F244, arg1, 0);
        D_8003F140 = p;
        func_800122C0(D_8003F244, arg1, p, 0);
        func_80030ECC();
        break;
    }
    case 4: {
        u8 *p;

        p = (u8 *)func_8001226C(D_8003F244, arg1, 0);
        D_8003F144 = p;
        func_800122C0(D_8003F244, arg1, p, 0);
        p = (u8 *)func_8001226C(D_8003F244, arg1, 1);
        D_8003F148 = p;
        func_800122C0(D_8003F244, arg1, p, 1);
        D_8003F14C = D_8003F148 + *(s32 *)D_8003F148 + 8;
        break;
    }
    case 0xC: {
        u16 n;

        n = *(u16 *)(arg1 + 8) * *(u16 *)(arg1 + 0xA);
        *(u16 *)(arg1 + 0xA) = 1;
        *(u16 *)(arg1 + 8) = n;
        LoadImage(arg1 + 4, arg1 + 0xC);
        break;
    }
    }
    DrawSync(0);
}

#include "main.h"


void func_80033824(void) {
    D_8003F120 = func_80013104(0x1ADB0);
    D_8003F124 = D_8003F120 + 0xD6D8;
    D_8003F118 = func_80013104(0x7600);
    D_8003F190 = func_80013104(0x20000);
    D_8003F194 = D_8003F190 + 0x10000;
    D_8003F150 = func_80013104(0x8000);
    D_8003F154 = func_80013104(0xE000);
    D_8003F15C = func_80013104(0x4000);
}

void func_800338C0(void) {
    func_8001336C(D_8003F120);
    func_8001336C(D_8003F118);
    func_8001336C(D_8003F190);
    func_8001336C(D_8003F150);
    func_8001336C(D_8003F154);
    func_8001336C(D_8003F15C);
}

void func_80033938(void) {
    if (D_8003F140 != 0) {
        func_8001336C(D_8003F140);
    }
    if (D_8003F13C != 0) {
        func_8001336C(D_8003F13C);
    }
    if (D_8003F138 != 0) {
        func_8001336C(D_8003F138);
    }
    if (D_8003F144 != 0) {
        func_8001336C(D_8003F144);
    }
    if (D_8003F148 != 0) {
        func_8001336C(D_8003F148);
    }
}

void func_800339D4(u8 *arg0) {
    s32 v0;
    s32 r;
    RECT rect;

    switch (arg0[4]) {
    case 0:
        if ((func_80011C90(D_8003F240) ^ 1) != 0) {
            D_8003F12C->unk0 = 0;
            r = (s32)func_80013204(func_80011CA0(D_8003F240, D_8003F12C->unk312) - (D_8003F12C->unk394 << 11));
            D_8003F12C->unk0 = r;
            if (r != 0) {
                func_80011A90((Pos *)D_8003F240, D_8003F12C->unk394, D_8003F12C->unk312);
                v0 = func_80011CA0(D_8003F240, D_8003F12C->unk312);
                func_8001190C_ovl(D_8003F240, D_8003F12C->unk0, v0 - (D_8003F12C->unk394 << 11));
            }
            arg0[4] = 1;
        }
        break;
    case 1:
        if ((func_80011C90(D_8003F240) ^ 1) != 0) {
            D_8003F130 = 0;
            r = (s32)func_80013104(func_80011CA0(D_8003F240, 0x96F));
            D_8003F130 = r;
            if (r != 0) {
                func_8001175C(D_8003F240, 0x96F);
                func_8001190C_ovl(D_8003F240, D_8003F130, 0);
            }
            arg0[4] = 2;
        }
        break;
    case 2:
        if ((D_8003F236 & 1) != 0) {
            if ((func_80011C90(D_8003F240) ^ 1) != 0) {
                rect.x = 0x300;
                rect.y = 0x1E0;
                rect.w = 0x100;
                rect.h = 0x20;
                LoadImage(&rect, D_8003F15C);
                DrawSync(0);
                func_800338C0();
                func_80033938();
                if (D_8003F12C->unk0 == 0) {
                    D_8003F12C->unk0 = (s32)func_80013204(func_80011CA0(D_8003F240, D_8003F12C->unk312) - (D_8003F12C->unk394 << 11));
                    func_80011A90((Pos *)D_8003F240, D_8003F12C->unk394, D_8003F12C->unk312);
                    v0 = func_80011CA0(D_8003F240, D_8003F12C->unk312);
                    func_8001190C_ovl(D_8003F240, D_8003F12C->unk0, v0 - (D_8003F12C->unk394 << 11));
                    do {
                    } while (func_80011C90(D_8003F240) != 0);
                }
                if (D_8003F130 == 0) {
                    D_8003F130 = (s32)func_80013104(func_80011CA0(D_8003F240, 0x96F));
                    func_80011BC4(D_8003F240, D_8003F130, 0x96F, 0);
                }
                D_8003F12C->unkD0 = *(Ovl4850B8 *)&D_8003F160;
                D_8003F12C->unkE8 = *(Ovl4850B8 *)&D_8003F178;
                D_8003F12C->unkD8 = *(Ovl4850W4 *)&D_8003F168;
                D_8003F12C->unk3C0 |= 8;
                __builtin_delete((void *)func_800100DC());
                func_800105B0(D_8003F254, D_8003F130, 1);
            }
        }
        break;
    }
}

void func_80033DE0(void) {
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80033DE8);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8003503C);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800353E4);

void func_80035688(u16 *arg0, u16 *arg1) {
    u16 v;

    v = *arg0 + 0x10;
    *arg0 = v;
    if ((s16)v >= 0x100) {
        *arg0 = 0;
        v = *arg1 + 0x10;
        *arg1 = v;
        if ((s16)v >= 0x100) {
            *arg1 = 0;
            memset(D_8003F150, 0xFF, 0x8000);
        }
    }
}

s32 *func_80035704(s32 arg0) {
    s32 *p = D_8003F144;
    s32 span = (*p - 4) / 16;
    s32 step = (span << 3) + 4;

    for (;;) {
        p = (s32 *)((u8 *)p + step);
        for (;;) {
            if (arg0 == *p) {
                goto found;
            }
            if (*p < arg0) {
                if (arg0 < p[2]) {
                    return NULL;
                }
            } else if (p[-2] < arg0) {
                return NULL;
            }
            if (span >= 2) {
                span >>= 1;
            }
            if (*p < arg0) {
                step = span << 3;
                break;
            }
            p = (s32 *)((u8 *)p - (span << 3));
        }
    }
found:
    return (s32 *)((u8 *)D_8003F144 + D_8003F144[0] + p[1]);
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800357C0);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800359D8);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80035C20);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800360A8);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80036150);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800364A4);

void func_80036C7C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (*(s16 *)(arg0 + 0x10) != 0 && arg2 < 0x20) {
        arg4 += 2;
    }
    func_800359D8(arg1, arg3 + 4, arg4 - 7, arg0[1]);
    if (arg2 < 0x20) {
        if (*(s16 *)(arg0 + 0x10) != 0) {
            func_800359D8(5, arg3, arg4, arg0[1]);
            func_80035C20(arg0, arg3 - 4, arg4, arg2);
            return;
        }
    }
    func_800359D8(4, arg3, arg4, arg0[1]);
}

void func_80036D4C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (*(s16 *)(arg0 + 0x10) != 0 && arg1 < 0x20) {
        func_800359D8(7, arg2, arg3 + 2, arg0[1]);
        func_80035C20(arg0, arg2 - 2, arg3 - 4, arg1);
        return;
    }
    func_800359D8(6, arg2, arg3, arg0[1]);
}

void func_80036DEC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (*(s16 *)(arg0 + 0x10) != 0 && arg1 < 0x20) {
        func_800359D8(9, arg2, arg3 + 2, arg0[1]);
        func_80035C20(arg0, arg2, arg3 - 3, arg1);
    } else {
        func_800359D8(8, arg2, arg3, arg0[1]);
    }
}

void func_80036E8C(s16 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0[8] != 0 && arg2 < 0x20) {
        func_800359D8(arg1 + 4, arg3, arg4 + 2, *(u8 *)((u8 *)arg0 + 1));
        func_80035C20(arg0, arg3, arg4, arg2);
    } else {
        func_800359D8(arg1, arg3, arg4, *(u8 *)((u8 *)arg0 + 1));
    }
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80036F28);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80037264);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80037690);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800394B4);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_800395D0);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8003988C);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80039A50);

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80039AB4);

void func_80039B20(s32 arg0, s8 arg1, s32 arg2) {
    s32 x;
    u16 v;

    x = (s32)((u32)(arg2 & 0xFFFF) >> 8);
    x = x * D_8003F12C->unk3C3 >> 7;
    v = (arg2 & 0xFF) | (x << 8);
    func_80019B70(D_8003F24C, arg0, arg1, v);
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80039B84);

void func_80039BF0(void) {
    Obj *p;

    p = __builtin_new(0xC);
    p->unk4 = D_8002F8D8;
    D_8002F8F0 = (s32)p;
    p->unk4 = &D_8003B488;
}

void func_80039C2C(u8 *arg0, u8 *arg1) {
    func_8002F8A4(arg0, (s32)arg1);
    D_8003F23C = (s32)(arg1 + 4);
    D_8003F240 = (s32)(arg1 + 0x10);
    D_8003F24C = arg1 + 0x64A4;
    D_8003F244 = arg1 + 1;
    D_8003F254 = (s32)arg1;
    D_8003F248 = arg1 + 2;
    D_8003F250 = (s32 *)(arg1 + 0x6420);
}

void func_80039CA4(void) {
}

s32 func_80039CAC(s32 arg0) {
    arg0 &= 0xFFF;
    if (arg0 < 0x401) {
        return D_8003F258[arg0];
    }
    if (arg0 < 0x800) {
        return D_8003F258[0x800 - arg0];
    }
    if (arg0 < 0xC01) {
        return -D_8003E258[arg0];
    }
    return -D_8003F258[0x1000 - arg0];
}

s32 func_80039D40(s32 arg0) {
    arg0 &= 0xFFF;
    if (arg0 < 0x400) {
        return D_8003F258[0x400 - arg0];
    }
    if (arg0 < 0x800) {
        return -D_8003EA58[arg0];
    }
    if (arg0 < 0xC00) {
        return -D_8003F258[0xC00 - arg0];
    }
    return D_8003DA58[arg0];
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80039DD4);

u32 func_80039EB4(u32 n) {
    u32 x;
    u32 y;

    x = 1;
    if (n == 0) {
        return 0;
    }
    y = n;
    while (x < y) {
        x *= 2;
        y >>= 1;
    }
    do {
        y = x;
        x = (n / y + y) >> 1;
    } while (x < y);
    return y;
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_80039F14);

void func_8003A104(s32 arg0, s16 *arg1) {
    s16 a;
    s16 v;

    a = func_80039D40(arg0);
    v = func_80039CAC(arg0);
    arg1[6] = -v;
    arg1[0] = a;
    arg1[3] = 0;
    arg1[1] = 0;
    arg1[4] = 0x1000;
    arg1[7] = 0;
    arg1[2] = v;
    arg1[5] = 0;
    arg1[8] = a;
}

INCLUDE_ASM("asm/ovl_4850/nonmatchings/ovl_4850", func_8003A170);

s32 *func_8003A3EC(s32 *arg0) {
    arg0[0] = (s32)__builtin_vec_new(0xB18);
    *(s32 *)(func_800100C4() + 0x64C0) = arg0[0];
    *(u8 *)(func_800100C4() + 0x64A9) = 1;
    return arg0;
}
