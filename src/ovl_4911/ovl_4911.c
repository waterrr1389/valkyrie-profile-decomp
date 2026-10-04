#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "ovl_4911.h"

void func_8002F824(s32 arg0) {
    func_8003326C();
    ((Ovl4911Obj *)D_8002F8F0)->unk4->unk14((u8 *)((Ovl4911Obj *)D_8002F8F0) + ((Ovl4911Obj *)D_8002F8F0)->unk4->unk10, arg0);
    ((Ovl4911Obj *)D_8002F8F0)->unk4->unkC((u8 *)((Ovl4911Obj *)D_8002F8F0) + ((Ovl4911Obj *)D_8002F8F0)->unk4->unk8);
}

void func_8002F8A4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 8) = arg1;
}

s32 func_8002F8AC(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_8002F8B8);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_8002F8E4);

void func_8002F8F4(void) {
    D_80033AB8.unk0 = func_80014484(D_800370B0, 0);
    D_80033AD0.unk0 = func_80014484(D_800370B0, 1);
    D_80033AB8.unk2 = func_8001449C(D_800370B0, 0);
    D_80033AD0.unk2 = func_8001449C(D_800370B0, 1);
    D_80033AB8.unk4 = func_800144B4(D_800370B0, 0);
    D_80033AD0.unk4 = func_800144B4(D_800370B0, 1);
    D_80033AB8.unk6 = func_80013DD0(D_800370B0, 0, &D_80033AB8.unk8, &D_80033AB8.unkC,
                                     &D_80033AB8.unk10, &D_80033AB8.unk14);
    D_80033AD0.unk6 = func_80013DD0(D_800370B0, 1, &D_80033AD0.unk8, &D_80033AD0.unkC,
                                     &D_80033AD0.unk10, &D_80033AD0.unk14);
    func_80014500(D_800370B0, 0);
    func_80014500(D_800370B0, 1);
}

void func_8002FA34(void) {
    memset(&D_80033AB8, 0, 0x18);
    memset(&D_80033AD0, 0, 0x18);
    func_8001444C(D_800370B0, 3);
    func_8001445C(D_800370B0, 0x14);
    func_80014500(D_800370B0, 0);
    func_80013D24(D_800370B0, 0, 0, 0, 0, 0, 0x20);
    func_80013D78(D_800370B0, 0, 0x50, 0x50, 0x50, 0x50);
    func_80013DBC(D_800370B0, 0, 1);
}

void func_8002FB04(s16 *arg0) {
    s32 prod;

    prod = arg0[2] * arg0[3];
    if (prod < 0x100) {
        arg0[2] = prod;
    } else {
        arg0[2] = 0x100;
    }
    arg0[3] = prod / 256;
    if (arg0[3] <= 0) {
        arg0[3] = 1;
    }
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_8002FB60);

s32 *func_8002FCF8(s32 *arg0) {
    *arg0 = (s32)__builtin_vec_new(0xB18);
    ((Ctx64A9 *)func_800100C4())->unk64C0 = (void *)*arg0;
    ((Ctx64A9 *)func_800100C4())->unk64A9 = 1;
    return arg0;
}

void func_8002FD44(void) {
    u8 *p;
    s32 i;

    p = D_80036810;
    i = 0x8F;
    do {
        *(s32 *)p = 0;
        i--;
        p += 0xEC;
    } while (i >= 0);
}

void func_8002FD68(void) {
    u8 *p;
    s32 i;
    void (*f)(u8 *);

    p = D_80036810;
    i = 0;
    do {
        f = *(void (**)(u8 *))p;
        if (f != 0) {
            f(p);
        }
        i++;
        p += 0xEC;
    } while (i < 0x90);
}

u8 *func_8002FDC4(void) {
    u8 *p = D_80036810;
    s32 i = 0;

    while (i < 0x90) {
        if (*(s32 *)p == 0) {
            p[5] = 0;
            p[4] = 0;
            return p;
        }
        i++;
        p += 0xEC;
    }
    return 0;
}

s32 *func_8002FE10(s32 arg0) {
    s32 *p;
    s32 i;

    p = D_80036810;
    for (i = 0; i < 0x90; i++) {
        if (*p == arg0) {
            return p;
        }
        p = (s32 *)((u8 *)p + 0xEC);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_8002FE48);

void func_8002FF84(void) {
    s16 rect[4];
    u8 *p;
    u8 *buf;
    u32 *q;
    s32 i;
    s32 k;

    SetGraphDebug(0);
    rect[1] = 0;
    rect[0] = 0;
    rect[2] = 0x280;
    rect[3] = 0x1E0;
    ClearImage(rect, 0, 0, 0);
    DrawSync(0);
    D_80036804 = (u8 *)func_80013104(0x10000);
    D_80036808 = (s32)(D_80036804 + 0x8000);
    p = func_80013104(0x600);
    D_80036844 = p;
    memset(p, 0xFF, 0x600);
    D_800370AC = (u8 *)func_80012220(D_800370C4, 3);
    D_80036810 = (s32 *)func_80012220(D_800370C4, 4);
    D_80036828 = func_80012220(D_800370C4, 8);
    D_8003682C = (u8 *)func_80013104(0x4000);
    D_8003683C = func_80012220(D_800370C4, 6);
    D_80036840 = D_8003683C + 0x5EC;
    func_80012EC8(D_800366A0, 0, 0, 0x280, 0x1E0);
    func_80012E90_ovl(D_800366A0 + 0x5C, 0, 0, 0x280, 0x1E0);
    D_800366B6 = 1;
    D_800366B7 = 0;
    D_800366B8 = 1;
    D_800366BB = 0;
    D_800366BA = 0;
    D_800366B9 = 0;
    PutDispEnv(D_800366A0 + 0x5C);
    PutDrawEnv(D_800366A0);
    D_80036814 = 0;
    D_8003681C = 0;
    D_80036838 = 0;
    func_8002FD44();
    D_8003709C = 0x280;
    D_8003709E = 0;
    D_80036C4C = 1;
    D_80037050 = 1;
    D_80037094 = 1;
    D_80037098 = 0;
    k = -1;
    p = D_80036844;
    for (i = 0x7F; i >= 0; i--) {
        *(s16 *)p = k;
        p += 0xC;
    }
    buf = func_80013104(0x200);
    if (buf != NULL) {
        *(u32 *)buf = 0xFFFF0000;
        q = (u32 *)(buf + 4);
        for (i = 1; i < 0x80; i++) {
            *q++ = -1;
        }
        rect[0] = 0;
        rect[1] = 0x1FD;
        rect[2] = 0x100;
        rect[3] = 1;
        LoadImage(rect, buf);
        DrawSync(0);
        q = (u32 *)buf;
        for (i = 0x7F; i >= 0; i--) {
            *q++ = 0;
        }
        rect[1] = 0x1FB;
        LoadImage(rect, buf);
        DrawSync(0);
        func_8001336C(buf);
    }
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_80030250);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_80030424);

void func_8003066C(void) {
    s32 i;

    func_8001336C(D_80036804);
    func_8001336C(D_80036844);
    func_8001336C(D_80036814);
    func_8001336C(D_80036830);
    func_8001336C(D_8003682C);
    if (D_80036838 != NULL) {
        func_8001336C(D_80036838);
    }
    for (i = 1; i < D_80036C4C; i++) {
        func_8001336C(D_80036850[i - 1]);
    }
    for (i = 1; i < D_80037050; i++) {
        func_8001336C(D_80036C54[i - 1]);
    }
    for (i = 1; i < D_80037094; i++) {
        func_8001336C(D_80037058[i - 1]);
    }
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_800307C8);

s32 func_80030F44(u8 *arg0) {
    s32 s2;
    s32 s3;
    u8 *s0;
    s32 s1;
    s32 a0;
    u8 c;

    s2 = (s16)D_800370A2;
    s0 = arg0;
    s3 = 0;
    c = *s0;
    s1 = s2;
    while (c != 0) {
        a0 = c & 0xFF;
        s0++;
        if (a0 & 0x80) {
            a0 &= 0x7F;
            a0 |= *s0 << 7;
            s0++;
            if (a0 >= 0x4000) {
                if (a0 == 0x4000) goto end;
                if (a0 == 0x4005) goto end;
                if (a0 == 0x4002) {
                    s1 = *s0;
                    s0++;
                    if ((u32)s2 < (u32)s1) s2 = s1;
                    goto cont;
                }
                if (a0 == 0x4004) {
                    s0++;
                    goto cont;
                }
                if ((u32)(a0 - 0x4006) < 2) {
                    s0 += 2;
                }
                goto cont;
            }
        }
        s3 += *func_80031448(a0, s1);
    cont:
        c = *s0;
    }
end:
    return (((u32)(0x280 - s3) >> 1) & 0xFFFF) | ((s2 + 4) << 16);
}

s32 func_80031068(u8 *arg0, s32 arg1) {
    s32 total = 0;
    s32 code = (s16)D_800370A2;
    u8 c;
    s32 val;

    while ((c = *arg0) != 0) {
        val = c;
        arg0++;
        if (val & 0x80) {
            val &= 0x7F;
            val |= *arg0 << 7;
            arg0++;
            if (val >= 0x4000) {
                if (val == 0x4000) {
                    break;
                }
                if (val == 0x4005) {
                    break;
                }
                if (val == 0x4002) {
                    code = *arg0++;
                    continue;
                }
                if (val == 0x4004) {
                    arg0++;
                    continue;
                }
                if ((u32)(val - 0x4006) < 2) {
                    break;
                }
                continue;
            }
        }
        total += *func_80031448(val, code);
    }
    return arg1 - total;
}

void func_80031160(s32 arg0, Out *arg1) {
    Hdr *hdr;
    Entry *p;
    s32 i;
    s32 h;
    s32 x;
    s32 yv;
    s32 v;
    u16 t;
    s16 rect[4];

    hdr = (Hdr *)func_80031448(arg0, (s16)D_800370A2);
    i = 0;
    p = (Entry *)D_80036844;
    do {
        if (p->unk0 == arg0 && p->unk2 == (s16)D_800370A2) {
            arg1->unk0 = p->unk4;
            arg1->unk2 = p->unk6;
            arg1->unk4 = p->unk8;
            arg1->unk6 = p->unkA;
            goto end;
        }
        i++;
        p++;
    } while (i < 0x80);
    h = hdr->unk2;
    x = (s16)D_8003709E;
    yv = hdr->unk0;
    v = x + h;
    arg1->unk4 = yv;
    arg1->unk6 = h;
    if (v >= 0x201) {
        t = D_8003709C;
        D_8003709E = 0;
        t += 0x80;
        D_8003709C = t;
        if ((s16)t >= 0x380) {
            D_8003709C = 0x280;
        }
    } else if (x < 0x100 && v >= 0x100) {
        D_8003709E = 0x100;
    }
    arg1->unk0 = D_8003709C;
    arg1->unk2 = D_8003709E;
    rect[0] = D_8003709C;
    rect[1] = D_8003709E;
    rect[2] = yv / 4;
    rect[3] = h;
    LoadImage(rect, (u8 *)hdr + 4);
    D_8003709E += h;
    D_80037098++;
    if (D_80037098 >= 0x80) {
        D_80037098 = 0;
    }
    p = &((Entry *)D_80036844)[D_80037098];
    p->unk0 = arg0;
    p->unk2 = D_800370A2;
    p->unk4 = arg1->unk0;
    p->unk6 = arg1->unk2;
    p->unk8 = arg1->unk4;
    p->unkA = arg1->unk6;
end:
    ;
}

s32 *func_80031378(s32 arg0) {
    s32 *base = (s32 *)D_80036814;
    s32 span = (*base - 4) / 16;
    s32 *p = (s32 *)((u8 *)base + ((span << 3) + 4));

    for (;;) {
        s32 v = *p;

        if (arg0 == v) {
            goto found;
        }
        if (v < arg0) {
            if (arg0 < p[2]) {
                return (s32 *)((u8 *)base + *base);
            }
        } else if (p[-2] < arg0) {
            return (s32 *)((u8 *)base + *base);
        }
        if (span >= 2) {
            span >>= 1;
        }
        if (*p < arg0) {
            p = (s32 *)((u8 *)p + (span << 3));
        } else {
            p = (s32 *)((u8 *)p - (span << 3));
        }
    }
found:
    return (s32 *)((u8 *)D_80036814 + *(s32 *)D_80036814 + p[1]);
}

s16 *func_80031448(s32 arg0, s32 arg1) {
    s16 *p;

    switch (arg1) {
    case 0x14:
        p = D_80036C50[arg0];
        break;
    case 0x18:
        p = D_80037054[arg0];
        break;
    default:
        p = D_8003684C[arg0];
        break;
    }
    return p;
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_800314A4);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_80031508);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_80031574);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_800315D8);

void func_80031644(void) {
    s32 i;

    i = 0;
    do {
        s32 off = i * 8;
        s32 p = *(s32 *)(D_800370AC + off + 0x2C);

        if (p != 0) {
            func_8001336C((u8 *)p);
            *(s32 *)(D_800370AC + off + 0x2C) = 0;
        }
        i++;
    } while (i < 0xD);
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_800316BC);

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_8003173C);

void func_80032F40(void) {
    u8 *s1;
    u8 *s3;
    u8 *s0;
    s32 s2;
    s32 size;
    s32 r;

    s1 = D_80036814;
    s2 = 0;
    size = *(s32 *)s1;
    D_800370CC = 0xF0;
    s3 = s1 + size;
    s1 += 4;
    s0 = func_80013104((s3 - s1) + 8);
    D_80036830 = s0;
    if (s1 < s3) {
        do {
            *(s32 *)s0 = *(s32 *)s1;
            s0 += 4;
            *(s32 *)s0 = s2;
            s0 += 4;
            r = func_800307C8(0, *(s32 *)s1, 0, 1);
            s1 += 8;
            s2 += r;
            D_800370CC += r;
        } while (s1 < s3);
    }
    *(s32 *)s0 = -1;
    *(s32 *)(s0 + 4) = s2;
    D_800370D0 = 0x1E000;
    D_800370D8 = 0;
    D_800370DC = 0;
    D_800370E0 = 0x168;
    D_80036834 = D_80036830;
    D_800370D4 = (D_800370CC << 8) / 18000;
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_80033088);

typedef struct {
    s32 unk0;
    void *unk4;
} OvlObj;


void func_8003326C(void) {
    OvlObj *o = __builtin_new(0xC);

    o->unk4 = &D_8002F8D8;
    D_8002F8F0 = o;
    o->unk4 = &D_80033AA0;
}

INCLUDE_ASM("asm/ovl_4911/nonmatchings/ovl_4911", func_800332A8);

void SsUtVibrateOn(void) {
}

void SsUtVibrateOff(void) {
}
