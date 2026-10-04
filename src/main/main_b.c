#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"

void func_800111B8(u8 arg0) {
    if (D_8002B62C != 0) {
        return;
    }
    if (D_8002B600 != 0) {
        D_8002B600 = 0;
        D_8002B628 = 3;
        func_8002549C(0);
        func_800255EC(9, 0);
        return;
    }
    if (arg0 == 5) {
        if (D_8002B601 != 0) {
            func_800112B4();
            return;
        }
    }
    if (arg0 == 1) {
        if (D_8002B604 != 0 && (*(u32 *)0x1F801098 & 0x1000000) != 0) {
            D_8002B605 = 1;
            return;
        }
        func_800112F8(D_8002B5D0, 1);
    } else {
        func_800112F8(D_8002B5D0, 0);
    }
}


void func_800112B4(void) {
    D_8002B62C = 1;
    D_8002B62F = 1;
    func_8002549C(0);
    func_800254B4(9, 0, 0);
}

void func_800112F8(s32 unused, s32 a)
{
  struct 
  {
    s32 words[2];
  } header;
  s32 error;
  s32 x;
  s32 size;
  s32 count;
  s32 i;
  s32 cmd;
  s32 sectorCount;
  s32 next;
  s32 check;
  void *dest;
  void *sectorDest;
  s32 *p;
  u16 n;
  D_8002B605 = 0;
  if (a)
  {
    x = CdGetSector(&header, 3);
    error = 1;
    if (x)
    {
      check = CdPosToInt(&header) ^ D_8002B624;
 do { D_8002B624++; } while (0);
      error = check != 0;
    }
    if (D_8002B602 && (!error))
    {
      if (!CdGetSector(D_8002B5E0, 8))
      {
        error = 1;
      }
      sectorDest = D_8002B5E4;
      sectorCount = 0x1F8;
    }
    else
    {
      sectorDest = D_8002B5DC;
      sectorCount = 0x200;
    }
    if (!CdGetSector(sectorDest, sectorCount))
    {
      error = 1;
    }
  }
  else
  {
    error = 1;
  }
  if (error && D_8002B601)
  {
    func_800112B4();
    return;
  }
  if (D_8002B602)
  {
    D_8002B5E0 += 0x20;
    D_8002B5E4 += 0x7E0;
  }
  D_8002B5DC += 0x800;
  D_8002B5D8 -= 0x800;
  if ((!D_8002B601) && (((D_8002B5F8 -= 0x800) <= 0) || ((*((u16 *) (D_8002B5E0 - 0x1C))) == ((D_8002B5F4 >> 11) - 1))))
  {
    n = D_8002B5FE + 1;
    D_8002B5FE = n;
    if (((s16) n) >= ((s16) D_8002B5FC))
    {
      D_8002B5FE = 0;
      D_8002B5DC = D_8002B5E8;
    }
    p = (s32 *) D_8002B5DC;
    size = (D_8002B5F4 >> 11) << 5;
    count = size >> 4;
    D_8002B5E0 = (u8 *) p;
    for (i = 0; i < count; i++)
    {
      *(p++) = 0;
      *(p++) = 0;
      *(p++) = 0;
      *(p++) = 0;
    }

    D_8002B5E4 = D_8002B5DC + size;
    D_8002B5F8 = D_8002B5F4;
  }
  if (D_8002B5D8 <= 0)
  {
    D_8002B628 = 3;
    func_8002549C(0);
    cmd = 9;
    dest = 0;
  }
  else
    if (error && (!D_8002B601))
  {
    D_8002B628 = 6;
    next = D_8002B624 - -1;
    D_8002B624 = next;
    func_800258E0(next, (void *)&D_8002B60C);
    cmd = 2;
    dest = (void *)&D_8002B60C;
  }
  else
  {
    return;
  }
  func_800255EC(cmd, dest);
}



u8 *func_80011604(u8 *arg0) {
    Obj *p;
    Obj *q;

    D_8002B5EC = 0;
    D_8002B5D8 = 0;
    D_8002B5F0 = 0;
    D_8002B5D4 = 0;
    D_8002B600 = 0;
    D_8002B5D0 = arg0;
    D_8002B628 = 0;
    D_8002B62A = 0;
    D_8002B62B = 0;
    D_8002B62C = 0;
    D_8002B62F = 0;
    p = __builtin_new(8);
    p->unk4 = &D_8002A890;
    D_8002B61C = p;
    q = __builtin_new(8);
    q->unk4 = &D_8002A870;
    D_8002B620 = q;
    while (func_800251F0() == 0) {
    }
    func_800116DC(arg0);
    func_80011D38(arg0);
    return arg0;
}

void func_800116DC(u8 *arg0) {
    u8 a;
    func_80025444(0, 0); func_800253C4(0); D_8002B604 = 0;
    VSync(4); D_8002B62D = 0; a = 0xA0;
    do {} while (func_800254B4(14, &a, 0) == 0);
    VSync(4); func_80025484(func_80010C34);
}


s32 func_8001175C(s32 arg0, s32 arg1) {
    u8 *p;
    u16 h;

    if (D_8002B5EC != 0) {
        return 0;
    }
    D_8002B628 = 1;
    D_8002B62A = 1;
    p = (u8 *) ((arg1 * 4) + arg0);
    D_8002B5E8 = 0;
    D_8002B60C = *(Pos *) (p + 4);
    D_8002B60C.d = 0;
    if (func_80025444(1, 0) == 2) {
        func_800255EC(2, &D_8002B60C);
    }
    h = *(u16 *) (p + 6);
    D_8002B600 = 0;
    D_8002B5D8 = (*(u8 *) (arg0 + arg1 + 0x5004) | (h & 0xFF00)) << 11;
    return 1;
}


s32 func_8001184C(void) {
    s32 v1;

    v1 = *(s16 *)&D_8002B5FE - 1;
    if (v1 < 0) {
        v1 += (s16) D_8002B5FC;
    }
    return v1;
}


void func_80011884(s32 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 t;

    D_8002B5F4 = arg3;
    D_8002B5F8 = arg3;
    t = arg1 + ((arg3 >> 11) << 5);
    D_8002B605 = 0;
    D_8002B602 = arg2;
    D_8002B5FE = 0;
    D_8002B5E0 = arg1;
    D_8002B5E4 = t;
    D_8002B603 = 0x1B;
    D_8002B601 = 0;
    D_8002B5FC = arg4;
    func_8001194C(arg0, arg1, arg5);
}


void func_8001190C(void) {
    D_8002B603 = 6;
    D_8002B602 = 0;
    D_8002B601 = 1;
    func_8001194C();
}


s32 func_8001194C(s32 arg0, s32 arg1, s32 arg2) {
    if (D_8002B5EC != 0) {
        return 0;
    }
    D_8002B5E8 = arg1;
    D_8002B600 = 0;
    D_8002B5C4 = 0;
    D_8002B5EC = 1;
    D_8002B5DC = arg1;
    if (arg2 > 0) {
        D_8002B5D8 = arg2;
    }
    D_8002B633 = 0;
    D_8002B630 = 0;
    D_8002B610 = D_8002B5D8;
    if (D_8002B62A != 0) {
        if (D_8002B62B == 2) {
            D_8002B62B = 0;
        }
        return 1;
    }
    D_8002B624 = CdPosToInt(&D_8002B60C);
    D_8002B628 = 4;
    func_8002549C((s32) func_800111B8);
    if (func_80025444(1, 0) == 2) {
        func_800255EC(D_8002B603, 0);
    }
    func_800142D4(D_8002B5CC, D_8002B620, 0);
    do {
        D_8002B614 = 0;
        D_8002B618 = 0;
    } while (0);
    return 1;
}

s32 func_80011A90(Pos *a, s32 b, s32 c) {
    Pos pos;
    if (D_8002B5EC != 0) return 0;
    D_8002B5E8 = 0; D_8002B600 = 0;
    pos = a[c + 1]; pos.d = 0;
    func_800258E0(CdPosToInt(&pos) + b, &pos);
    D_8002B60C = pos;
    if (D_8002B62A != 0) { D_8002B62B = 1; return 1; }
    D_8002B62A = 1; D_8002B62B = 2; D_8002B628 = 2;
    if (func_80025444(1, 0) == 2) func_800255EC(2, &D_8002B60C);
    return 1;
}

void func_80011B9C(s32 unused, s32 a, s32 b) { D_8002B5D4 = a; D_8002B608 = b; }


void func_80011BB4(void) {
    D_8002B5D4 = 0;
}

#ifdef NON_MATCHING
s32 func_80011BC4(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3)
{
  s32 new_var;
  do
  {
    new_var = func_8001175C(arg0, arg2);
 do { } while (0);
    while ((new_var ^ 1) != 0)
    {
    }

  }
  while ((((s32 (*)(u8 *, u8 *, s32))func_8001190C)(arg0, arg1, arg3) ^ 1) != 0);
  while (D_8002B5EC != 0)
  {
  }

  return 1;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80011BC4);
#endif


void func_80011C50(void) {
    if (D_8002B600 == 0 && D_8002B5EC != 0) {
        D_8002B5E8 = 0;
        D_8002B600 = 1;
    }
}


s32 func_80011C90(s32 a0) {
    return D_8002B5EC != 0;
}

s32 func_80011CA0(s32 arg0, s32 arg1) {
    return (*(u8 *)(arg0 + arg1 + 0x5004) | (*(u16 *)(arg0 + arg1 * 4 + 6) & 0xFF00)) << 11;
}


s32 func_80011CC4(void) {
    s32 v1 = 0;
    if (D_8002B5EC != 0) {
        v1 = D_8002B5C4;
    }
    return v1;
}


u8 func_80011CE8(void) {
    return D_8002B630;
}


u8 func_80011CF8(void) {
    return D_8002B62D;
}


s32 func_80011D08(void) {
    s32 v1 = 0;
    if (D_8002B5EC != 0) {
        v1 = D_8002B5D8;
    }
    return v1;
}

void func_80011D2C(s32 unused, u8 *obj) {
    *(volatile s32 *)(obj + 0x6404) = 0;
}

#ifdef NON_MATCHING
void func_80011D38(u8 *obj) {
    extern s32 D_8002A8B0;
    u8 buf[8];
    u8 *heap;
    u8 *dst;
    u8 *src;
    s32 i;
    s32 n;
    u32 key;

    *(s32 *)(obj + 0x6404) = 1;
    *(s32 *)(obj + 0x4) = 0x400;
    *(s32 *)(buf + 4) = (s32)&D_8002A8B0;
    func_80011B9C(obj, buf, obj);
    func_8001175C(obj, 0);
    heap = __builtin_vec_new(0x6800);
    ((void (*)(u8 *, u8 *, s32))func_8001190C)(obj, heap, 0x6800);
    do {
    } while (*(volatile s32 *)(obj + 0x6404) != 0);
    i = 0;
    n = 0x1900;
    src = heap;
    dst = obj + 4;
    do {
        *(s32 *)dst = *(s32 *)src;
        src += 4;
        i++;
        dst += 4;
    } while (i < n);
    __builtin_delete(heap);
    ((void (*)(u8 *))func_80011BB4)(obj);
    key = 0x64283921;
    for (i = 0; i < 0x1400; i++) {
        *(u32 *)(obj + 4 + i * 4) ^= key;
        key ^= key << 1;
        *(u8 *)(obj + 0x5004 + i) ^= key;
        key = ~key ^ 0x64283921;
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_b", func_80011D38);
#endif


s32 func_80011E50(u8 *arg0, s32 arg1) {
    if (*(s32 *)(arg0 + 4) != 0x19563824) {
        return 2;
    }
    return func_80011CA0((s32)arg0, arg1 + 1) != 0;
}


void func_80011E90(s32 a0) {
    u8 pad;
    u8 buf[8];

    while (func_80011C90(a0) != 0) {
    }
    while (D_8002B62C != 0) {
    }
    func_80025484(0);
    pad = 0;
    for (;;) {
        if (func_80025718(0xE, &pad, buf) == 0) {
            continue;
        }
        if ((buf[0] & 0x11) != 0) {
            continue;
        }
        if (func_80025718(8, NULL, buf) == 0) {
            continue;
        }
        if ((buf[0] & 0x11) != 0) {
            continue;
        }
        break;
    }
}


void func_80011F3C(void) {
    u8 pad;

    for (;;) {
        if (func_80025718(1, 0, &pad) == 0) continue;
        if (!(pad & 0x10)) break;
    }
    do {
        func_80025718(1, 0, &pad);
    } while (!(pad & 0x10));
    for (;;) {
        if (func_80025718(1, 0, &pad) == 0) continue;
        if (!(pad & 0x10)) break;
    }
}


s32 func_80011FCC(u8 *arg0) {
    s32 sp18;
    u8 buf[8];
    s32 r;
    s32 i;
    s32 j;
    s32 one;

    i = 0;
    for (;;) {
        VSync(0);
        i++;
        if (i >= 0x709) return 2;
        if (func_80025718(1, 0, &buf[0]) == 0) continue;
        if (!(buf[0] & 2)) continue;
        if (func_80025718(0x13, 0, &buf[0]) == 0) continue;
        if (buf[0] & 0x11) continue;

        sp18 = 0x400;
        j = 0x1E;
        func_800254B4(0x1B, (u8 *)&sp18, 0);
        one = 1;
        for (;;) {
            r = func_80025464(0, &buf[0]);
            j--;
            if (r == one || j <= 0) break;
            func_800254B4(0x1B, (u8 *)&sp18, 0);
        }
        if (r != 1) {
            if (buf[0] & 0x10) return 2;
            if ((buf[0] & 1) && (buf[1] & 0x40)) return 0;
            return ((buf[0] & 2) == 0) * 2;
        }
        while (func_80025718(9, 0, &buf[0]) == 0) {
        }
        VSync(8);
        if (func_80025338(0) == 0) {
            return 2;
        }
        func_800116DC(arg0);
        func_80011D38(arg0);
        return 1;
    }
    return 2;
}


void func_80012164(s32 unused, s8 arg1) {
    D_8002B604 = arg1;
}


u8 func_80012174(void) {
    return D_8002B605;
}

typedef struct { u8 pad[0x44]; s32 items[16]; } Object;
Object *func_80012184(Object *p) {
    s32 i;
    for (i = 15; i >= 0; i--) p->items[i] = 0;
    return p;
}

s32 func_800121A8(s32 *arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (arg0[i + 0x11] == 0 || arg0[i + 0x11] == arg2) {
            arg0[i + 1] = arg1;
            arg0[i + 0x11] = arg2;
            return 1;
        }
    }
    return 0;
}

void func_800121F0(s32 *p, s32 val) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (p[i + 0x11] == val) {
            p[i + 0x11] = 0;
        }
    }
}

s32 func_80012220(s32 *p, s32 val) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (p[i + 0x11] == val) {
            return p[i + 1];
        }
    }
    return 0;
}

u8 *func_8001225C(u8 *p) {
    return p;
}

void func_80012264(void) {
}


s32 func_8001226C(u8 *unused, u8 *p, s32 n) {
    u8 pad[8];
    s32 i;

    i = 0;
    if (n > 0) {
        do {
            if (*(s32 *)(p + 0xC) == 0) {
                return 0;
            }
            p += *(s32 *)(p + 0xC);
            i++;
        } while (i < n);
    }
    return (s32)__builtin_vec_new(*(s32 *)(p + 8));
}


s32 func_800122C0(u8 *a0, u8 *p, u8 *a2, s32 n) {
    u8 pad[8];
    s32 i;

    if (bcmp(p, D_8002A8D0, 3) != 0) {
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
    switch (*(u8 *)(p + 3)) {
    case 0:
        memcpy(a2, p + 0x10, *(s32 *)(p + 8));
        return 1;
    case 1:
        return func_800123CC(a0, p + 0x10, a2);
    case 2:
        return func_80012874(a0, p + 0x10, a2, *(s32 *)(p + 8));
    }
}
