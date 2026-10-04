#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"

#ifdef NON_MATCHING
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
s32 func_80012874(u8 *unused, u8 *src, u8 *dst, s32 size) {
    u8 *end;
    s32 bits;
    s32 nbits;
    s32 i;
    s32 cmd;
    s32 word;
    s32 len;

    bits = 0;
    nbits = 1;
    end = dst + size;
    while (dst < end) {
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
        word = src[0] | ((src[1] & 0xF) << 8);
        cmd = src[1] >> 4;
        len = cmd + 3;
        if (len < 0x12) {
            if (word >= 0x10) {
                switch (cmd) {
                case 0:
                    *(U3 *)dst = *(U3 *)(dst - word);
                    dst += 3;
                    break;
                case 1:
                    *(U4 *)dst = *(U4 *)(dst - word);
                    dst += 4;
                    break;
                case 2:
                    *(U5 *)dst = *(U5 *)(dst - word);
                    dst += 5;
                    break;
                case 3:
                    *(U6 *)dst = *(U6 *)(dst - word);
                    dst += 6;
                    break;
                case 4:
                    *(U7 *)dst = *(U7 *)(dst - word);
                    dst += 7;
                    break;
                case 5:
                    *(U8 *)dst = *(U8 *)(dst - word);
                    dst += 8;
                    break;
                case 6:
                    *(U9 *)dst = *(U9 *)(dst - word);
                    dst += 9;
                    break;
                case 7:
                    *(U10 *)dst = *(U10 *)(dst - word);
                    dst += 10;
                    break;
                case 8:
                    *(U11 *)dst = *(U11 *)(dst - word);
                    dst += 11;
                    break;
                case 9:
                    *(U12 *)dst = *(U12 *)(dst - word);
                    dst += 12;
                    break;
                case 10:
                    *(U13 *)dst = *(U13 *)(dst - word);
                    dst += 13;
                    break;
                case 11:
                    *(U14 *)dst = *(U14 *)(dst - word);
                    dst += 14;
                    break;
                case 12:
                    *(U15 *)dst = *(U15 *)(dst - word);
                    dst += 15;
                    break;
                case 13:
                    *(U16 *)dst = *(U16 *)(dst - word);
                    dst += 16;
                    break;
                case 14:
                    *(U17 *)dst = *(U17 *)(dst - word);
                    dst += 17;
                    break;
                }
            } else {
                for (i = 0; i < len; i++) {
                    *dst = *(dst - word);
                    dst++;
                }
            }
        } else {
            s32 count;
            s32 val;
            u16 v16;

            val = word & 0xFF;
            if (word < 0x100) {
                val = src[2];
                src++;
                count = word + 0x13;
            } else {
                count = (word >> 8) + 3;
            }
            v16 = val | (val << 8);
            if (((u32)dst & 1) != 0) {
                *dst++ = val;
                if ((count & 1) != 0) {
                    for (i = 1; i < count; i += 2) {
                        *(u16 *)dst = v16;
                        dst += 2;
                    }
                } else {
                    for (i = 1; i < count - 1; i += 2) {
                        *(u16 *)dst = v16;
                        dst += 2;
                    }
                    if (i < count) {
                        *dst++ = val;
                    }
                }
            } else {
                for (i = 0; i < count - 1; i += 2) {
                    *(u16 *)dst = v16;
                    dst += 2;
                }
                if (i < count) {
                    *dst++ = val;
                }
            }
        }
        src += 2;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_c", func_80012874);
#endif


void func_80012DA8(void) {
    ClearOTag(&D_8002B634, 1);
}


s32 func_80012DD0(u32 *arg0, s32 arg1) {
    u32 tmp[2];
    u32 *p;
    u32 addr;
    s32 count;
    s32 i;
    s32 n;

    count = arg1 - 1;
    n = count >> 2;
    p = arg0;
    addr = ((u32)(p + 1)) & 0xFFFFFF;
    i = 0;
    if (n > 0) {
        do {
            *p++ = addr;
            addr += 4;
            *p++ = addr;
            addr += 4;
            *p++ = addr;
            addr += 4;
            *p++ = addr;
            addr += 4;
            i++;
        } while (i < n);
    }
    if (count & 3) {
        i = 0;
        for (;;) {
            s32 r = count % 4;

            if (i >= r) {
                break;
            }
            i++;
            *p++ = addr;
            addr += 4;
        }
    }
    *p = D_8002B634;
    return 0;
}

DISPENV *func_80012E90(DISPENV *env, s16 x, s16 y, s16 w, s32 h) {
    env->disp.x = x;
    env->disp.y = y;
    env->disp.w = w;
    env->disp.h = h;
    env->screen.x = 0;
    env->screen.y = 0;
    env->screen.w = 0x100;
    env->screen.h = 0xF0;
    env->unk10 = 0;
    return env;
}

typedef struct Unk12EC8 {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 x2;
    s16 y2;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    u8 unk17;
    s32 unk18;
} Unk12EC8;

Unk12EC8 *func_80012EC8(Unk12EC8 *p, s32 a1, s32 a2, s32 a3, s32 a5) {
    p->x = a1;
    p->y = a2;
    p->w = a3;
    p->x2 = a1;
    p->y2 = a2;
    p->unkC = 0;
    p->unkE = 0;
    p->unk10 = 0;
    p->unk12 = 0;
    p->unk14 = 0xA;
    p->unk16 = 1;
    p->unk18 = 0;
    p->h = a5;
    p->unk17 = a5 != 0x1E0;
    return p;
}

s32 func_80012F1C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s16 rect[4];
    s32 w = f;
    rect[0] = d; rect[1] = e;
    if (b == 0) w >>= 2;
    if (b == 1) w >>= 1;
    rect[3] = g; rect[2] = w;
    LoadImage(rect, a);
    return ((b & 3) << 7) | ((c & 3) << 5) | ((e & 0x100) >> 4) | ((d & 0x3FF) >> 6) | ((e & 0x200) * 4);
}


s32 func_80012FDC(s32 a0, s32 a1, s32 a2) {
    s16 rect[4];

    rect[2] = 0x100;
    rect[0] = a1;
    rect[1] = a2;
    rect[3] = 1;
    LoadImage(rect, a0);
    return (a2 << 6) | (a1 >> 4);
}


s32 func_80013040(void *arg0, s32 arg1, s32 arg2) {
    RECT r;

    r.w = 0x10;
    r.x = arg1;
    r.y = arg2;
    r.h = 1;
    LoadImage(&r, arg0);
    return (arg2 << 6) | (arg1 >> 4);
}


void func_800130A4(Chunk *arg0, s32 arg1) {
    Chunk *sent;

    sent = (Chunk *)&D_8002B638;
    sent->size = 4;
    D_8002B648 = sent;
    D_8002B64C = 0;
    D_8002B650 = 0;
    D_8002B63D = 1;
    D_8002B644 = arg0;
    D_8002B640 = arg0;
    arg0->used = 0;
    arg0->size = arg1;
    arg0->next = D_8002B648;
    arg0->prev = D_8002B648;
}


void *func_80013104(s32 arg0) {
    Chunk *p;
    Chunk *q;
    s32 size;

    if (D_8002B650 != 0) {
        return func_80013204(arg0);
    }
    size = (arg0 + 0x13) & -4;
    p = D_8002B648->prev;
    while (p != D_8002B648) {
        if (p->used == 0 && p->size >= size) {
            if (p->size - size < 0x15) {
                goto found;
            }
            q = (Chunk *)((u8 *)p + size);
            q->size = p->size - size;
            q->used = 0;
            p->prev->next = q;
            q->prev = p->prev;
            p->prev = q;
            q->next = p;
            p->size = size;
        found:
            p->used = 1;
            return (u8 *)p + 0x10;
        }
        p = p->prev;
    }
    if (D_8002B64C != NULL) {
        return D_8002B64C(arg0);
    }
    return NULL;
}


void *func_80013204(s32 arg0) {
    Chunk *p;
    Chunk *q;
    s32 size;

    size = (arg0 + 0x13) & -4;
    p = D_8002B648->next;
    while (p != D_8002B648) {
        if (p->used == 0 && p->size >= size) {
            if (p->size - size < 0x15) {
                p->used = 1;
                return (u8 *)p + 0x10;
            }
            goto split;
        }
        p = p->next;
    }
    if (D_8002B64C != NULL) {
        goto callback;
    }
    return NULL;
split:
    q = (Chunk *)((u8 *)p + p->size - size);
    q->size = size;
    q->used = 1;
    p->prev->next = q;
    q->prev = p->prev;
    p->prev = q;
    q->next = p;
    p->size -= size;
    p->used = 0;
    return (u8 *)q + 0x10;
callback:
    return D_8002B64C(arg0);
}


void func_80013304(void) {
    Chunk *p;

    p = D_8002B648->next;
    while (p != D_8002B648) {
        if (p->used != 0) {
            func_8001336C((u8 *)p + 0x10);
            return;
        }
        p = p->next;
    }
}

void func_8001336C(u8 *arg0) {
    Chunk *m;

    m = (Chunk *)(arg0 - 0x10);
    if (m->used == 0) {
        return;
    }
    if (m->next->used != 0) {
        goto skip;
    }
    m->prev->next = m->next;
    m->next->prev = m->prev;
    m->next->size = m->next->size + m->size;
    m = m->next;
skip:
    if (m->prev->used == 0) {
        m->prev->prev->next = m;
        m->size = m->size + m->prev->size;
        m->prev = m->prev->prev;
    }
    m->used = 0;
}

#ifdef NON_MATCHING
typedef struct Chunk_13428 {
    s32 size;
    u8 pad4;
    u8 used;
    u8 pad6[2];
    struct Chunk_13428 *prev;
    struct Chunk_13428 *next;
} Chunk_13428;
/* Reallocates the chunk that owns arg0 to arg1 bytes.  When the size
 * change is small and the previous chunk is in use, the chunk is left
 * alone; otherwise it is split and/or coalesced with a free neighbour.
 * The chunk header is volatile so its fields are reloaded after every
 * store, as in the original. */
void *func_80013428(u8 *arg0, s32 arg1) {
    volatile Chunk_13428 *m;
    Chunk_13428 *p;
    s32 size;
    s32 old;

    m = (Chunk_13428 *)(arg0 - 0x10);
    old = m->size;
    size = (arg1 + 0x13) & -4;
    if (old == size) {
        goto done;
    }
    if (size >= old) {
        goto alloc;
    }
    if (m->prev->used == 0) {
        ;
    } else if (old - size < 0x14) {
        goto done;
    }
    p = (Chunk_13428 *)((u8 *)m + size);
    if (m->prev->used != 0) {
        p->size = m->size - size;
        p->next = m;
        p->used = 0;
        p->prev = m->prev;
        m->prev->next = p;
    } else {
        p->next = m;
        p->used = 0;
        p->prev = m->prev->prev;
        p->size = m->prev->size + m->size - size;
        m->prev->prev->next = p;
    }
    m->prev = p;
    m->size = size;
done:
    return arg0;
alloc:
    func_8001336C(arg0);
    return func_80013104(arg1);
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_c", func_80013428);
#endif

typedef struct Node {
    s32 unk0;
    u8 pad4[1];
    u8 unk5;
    u8 pad6[2];
    struct Node *unk8;
} Node;


s32 func_80013540(s32 *arg0, s32 *arg1) {
    Node *p;
    s32 max;

    *arg1 = 0;
    *arg0 = 0;
    p = ((Node *)D_8002B648)->unk8;
    max = 0;
    while (p != (Node *)D_8002B648) {
        if (p->unk5 != 0) {
            *arg1 += p->unk0;
        } else {
            *arg0 += p->unk0;
            if (max < p->unk0) {
                max = p->unk0;
            }
        }
        p = p->unk8;
    }
    max -= 0x10;
    if (max < 0) {
        max = 0;
    }
    return max;
}

void func_800135E8(void) {
}


void func_800135F0(void *(*arg0)(s32)) {
    D_8002B64C = arg0;
}


void func_80013600(u8 arg0) {
    D_8002B650 = arg0;
}

void func_80013610(void) {
}

void func_80013618(void) {
}

Pair *func_80013620(Pair *arg0, Pair *arg1) {
    volatile s32 old;

    old = arg0->b;
    *arg0 = *arg1;
    arg0->b = old;
    return arg0;
}


Pair *func_80013658(Pair *arg0, Pair *arg1) {
    *arg0 = *arg1;
    arg0->b = (s32)&D_8002A954;
    return arg0;
}


Pair *func_8001367C(Pair *arg0) {
    arg0->b = (s32)&D_8002A954;
    return arg0;
}

#ifdef NON_MATCHING
typedef struct {
    u8 pad[4];
    u8 *unk4;
} Ent_13690;
typedef struct {
    u8 pad[0x18];
    s16 unk18;
    u8 pad1A[2];
    void (*unk1C)(u8 *, s32);
} Tbl;
void func_80013690(void) {
    extern s32 PadGetState(s32);
    extern s32 PadInfoAct(s32, s32, s32);
    extern s32 PadInfoComb(s32, s32, s32);
    extern void PadSetAct(s32, u8 *, s32);
    extern s32 PadSetActAlign(s32, u8 *);
    extern s32 func_80013DD0(s32, s32, s32 *, s32 *, s32 *, s32 *);
    extern u8 D_8002B654[];
    extern u8 D_8002B6C9[];
    extern u8 D_8002B6CA[];
    extern u8 D_8002B6CB[];
    s32 i;
    s32 j;
    s32 port;
    s32 state;
    s32 comb;
    s32 k;
    s32 off;
    s32 off4;
    s32 off22;
    u8 n;
    s32 one;
    u8 act;
    u8 flag;
    u8 mode;
    s32 hid;
    u8 *b0p;
    u8 *b4p;
    u8 *c0p;
    u8 *b8p;
    u8 *bcp;
    u8 *p710;
    u8 *p6a8;
    u8 *p70c;
    u16 *p698;
    u16 *p69c;
    u16 *a0p;
    u16 *a1p;
    struct {
        s32 x;
        s32 y;
        s32 w;
        s32 z;
        u8 *volatile saved_p710;
    } frame;
#define x frame.x
#define y frame.y
#define w frame.w
#define z frame.z
#define saved_p710 frame.saved_p710

    D_8002B5C8 = 1;
    for (i = 0; i < D_8002B65C; i++) {
        Ent_13690 *ent;
        Tbl *tbl;

        ent = (Ent_13690 *)D_8002B660[i];
        tbl = (Tbl *)ent->unk4;
        tbl->unk1C((u8 *)ent + tbl->unk18, D_8002B678[i]);
    }
    D_8002B5C8 = 0;
    n = D_8002B6AD + 1;
    D_8002B6AD = n;
    if (n >= 0x32) {
        D_8002B6AD = 0;
        D_8002B690++;
    }
    j = 0;
    one = 1;
    b0p = D_8002B6B0;
    c0p = D_8002B6C0;
    b4p = D_8002B6B4;
    bcp = D_8002B6BC;
    b8p = D_8002B6B8;
    k = 0;
top:
    if (j >= 2) {
        goto out;
    }
    port = j << 4;
    if (*b0p == 0) {
        goto next;
    }
    state = PadGetState(port);
    if (state == one) {
        *b0p = one;
    }
    if (*b0p != one) {
        goto next;
    }
    PadSetAct(port, D_8002B6C4 + k, 2);
    if (state == 2) {
        *b0p = 2;
    }
    if (state != 6) {
        goto next;
    }
    *b4p = PadInfoAct(port, -1, 0);
    if (*b4p >= 3) {
        *b4p = 2;
    }
    i = 0;
    if (i < *b4p) {
        u8 *p8 = b8p;
        u8 *pc = bcp;
        do {
            if (PadInfoAct(port, i, 1) == one) {
                *p8 = PadInfoAct(port, i, 2);
                *pc = PadInfoAct(port, i, 3);
            } else {
                *p8 = 0;
            }
            p8++;
            pc++;
            i++;
        } while (i < *b4p);
    }
    comb = PadInfoComb(port, 0, -1);
    if (comb >= 3) {
        comb = 2;
    }
    *c0p = 0;
    for (i = 0; i < comb; i++) {
        *c0p |= one << PadInfoComb(port, 0, i);
    }
    if (PadSetActAlign(port, D_8002B654) != 0) {
        *b0p = 2;
    }
    func_80013D24(D_8002B5CC, 0, 0, 0, 0, 0, 0x20);
    func_80013D78(D_8002B5CC, 0, 0x50, 0x50, 0x50, 0x50);
    func_80013DBC(D_8002B5CC, 0, 1);
next:
    b0p++;
    bcp += 2;
    c0p++;
    b8p += 2;
    b4p++;
    k += 2;
    j++;
    goto top;
out:
    flag = D_8002B6AB;
    port = 0;
    p698 = D_8002B698;
    p69c = (u16 *)&D_8002B69C;
    off = 0;
    p6a8 = D_8002B6A8;
    p70c = D_8002B70C;
    off4 = 0;
    off22 = 0;
    p710 = D_8002B710;
top2:
    if (port >= 2) {
        goto out2;
    }
    if (flag == 0) {
        goto out2;
    }
    if (!(flag & 1)) goto invalid;
    {
        if (D_8002B6B0[port] >= 2 && D_8002B6C8[off22] == 0) {
            hid = D_8002B6C9[off22] >> 4;
            if (hid == 4 || hid == 7) goto valid;
        }
    }
invalid:
    *p698 = 0;
    *p70c = 0;
    goto next2;
valid:
    {
                *p69c = *p698;
                *p698 = ~((D_8002B6CA[off22] << 8) | D_8002B6CB[off22]);
                if (hid == 7) {
                    *p70c = 1;
                    {
                        s32 copy;
                        u8 *source = D_8002B6C8 + off22;
                        u8 *dest = p710;
                        for (copy = 0; copy < 4; copy++) {
                            *dest++ = source[copy + 4];
                        }
                    }
                    mode = D_8002B72C[port];
                    if (mode != 0) {
                        if (mode == 2) {
                            *p698 &= 0xFFF;
                        }
                        saved_p710 = p710;
                        hid = func_80013DD0(D_8002B5CC, port, &x, &y, &w, &z);
                        p710 = saved_p710;
                        if (hid != 0) {
                            if (-(D_8002B726[off4] >> 1) >= w) {
                                *p698 |= 0x8000;
                            }
                            if (w >= (D_8002B726[off4] >> 1)) {
                                *p698 |= 0x2000;
                            }
                            if (-(D_8002B727[off4] >> 1) >= z) {
                                *p698 |= 0x1000;
                            }
                            if (z >= (D_8002B727[off4] >> 1)) {
                                *p698 |= 0x4000;
                            }
                        }
                    } else {
                        *p70c = 0;
                    }
                } else {
                    *p70c = 0;
                }
                if (*p69c == *p698 && *p69c != 0) {
                    act = *p6a8;
                    if (act < D_8002B6AA) {
                        *p6a8 = act + 1;
                    }
                } else {
                    *p6a8 = 0;
                }
                a0p = (u16 *)((u8 *)D_8002B6A0 + off);
                a1p = (u16 *)((u8 *)D_8002B6A4 + off);
                *a0p |= *p698;
                *a1p |= *p698 & ~*p69c;
                goto next2;
    }
next2:
    p698++;
    p69c++;
    off += 2;
    p6a8++;
    p70c++;
    off4 += 4;
    off22 += 0x22;
    p710 += 4;
    port++;
    flag >>= 1;
    goto top2;
out2:
    ;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_c", func_80013690);
#endif

void func_80013D1C(void) {
}


void func_80013D24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx;

    idx = arg1 * 4;
    D_8002B718[idx] = arg2;
    D_8002B719[idx] = arg3;
    D_8002B71A[idx] = arg4;
    D_8002B71B[idx] = arg5;
    D_8002B720[arg1] = arg6;
}


void func_80013D78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx;

    idx = arg1 * 4;
    D_8002B724[idx] = arg2;
    D_8002B725[idx] = arg3;
    D_8002B726[idx] = arg4;
    D_8002B727[idx] = arg5;
}


void func_80013DBC(s32 arg0, s32 arg1, s32 arg2) {
    D_8002B72C[arg1] = arg2;
}

s32 func_80013DD0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 i;
    s32 off;
    s32 val;
    s32 adiff;
    s32 lim;
    s32 pv;
    s32 *dst;
    u8 *maxp;
    s8 *prev;
    u8 *cur;
    s32 thresh;

    i = 0;
    if (D_8002B70C[arg1] == 0) {
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
        *arg5 = 0;
        return 0;
    }
    thresh = D_8002B720[arg1];
    off = arg1 * 4;
    maxp = D_8002B724 + off;
    prev = (s8 *)D_8002B718 + off;
    cur = D_8002B710 + off;
top:
    if (i >= 4) {
        goto out;
    }
    switch (i) {
    case 0:
        dst = arg2;
        break;
    case 1:
        dst = arg3;
        break;
    case 2:
        dst = arg4;
        break;
    case 3:
        dst = arg5;
        break;
    }
    pv = *prev + 0x80;
    val = *cur - pv;
    adiff = __builtin_abs(val);
    if (adiff < thresh) {
        val = 0;
    } else if (val > 0) {
        val -= thresh;
    } else {
        val += thresh;
    }
    lim = *maxp;
    if (lim < val) {
        val = lim;
    }
    if (val < -lim) {
        val = -lim;
    }
    *dst = val;
    maxp++;
    prev++;
    cur++;
    i++;
    goto top;
out:
    return 1;
}

void func_80013F2C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 n;
    u8 t0;
    u8 t1;
    u8 *p4;
    u8 *pc;
    u8 *pb;
    u8 t;

    if (*(u8 *)(arg0 + arg1 + 8) != 0) {
        if (func_800140A8(arg0, arg1) != 0) {
            n = D_8002B6B4[arg1];
            if (n <= 0) {
                return;
            }
            i = 0;
            t1 = arg3 != 0;
            t0 = arg2 != 0;
            p4 = D_8002B6C4 + arg1 * 2;
            pc = D_8002B6BC + arg1 * 2;
            pb = D_8002B6B8 + arg1 * 2;
        top:
            if ((D_8002B6C0[arg1] >> i) & 1) {
                t = *pb;
                if (t == 1) {
                    if (*pc == 0) {
                        *p4 = t1;
                    } else {
                        *p4 = arg3;
                    }
                } else if (t == 2) {
                    if (*pc == 0) {
                        *p4 = t0;
                    } else {
                        *p4 = arg2;
                    }
                }
            }
            p4++;
            pc++;
            pb++;
            i++;
            if (i < D_8002B6B4[arg1]) {
                goto top;
            }
        } else {
            D_8002B6C4[arg1 * 2] = 0x40;
            D_8002B6C4[arg1 * 2 + 1] = (arg2 | arg3) != 0;
        }
    }
}

void func_8001409C(u8 *arg0, s32 arg1, u8 arg2) {
    *(u8 *)(arg0 + arg1 + 8) = arg2;
}


s32 func_800140A8(s32 arg0, s32 arg1) {
    return PadInfoMode(arg1 << 4, 2, 0) != 0;
}

s32 func_800140D0(s32 a) {
    s16 *p, *q, *r;
    s32 i;
    i = 0; r = &D_8002B6A4; q = &D_8002B69C; p = &D_8002B6A0;
    D_8002B694 = 0; D_8002B65C = 0; D_8002B6AC = 0; D_8002B5CC = a;
    do { *p = 0; *q = 0; *r = 0; r++; q++; i++; p++; } while (i < 2);
    return a;
}


void func_80014138(s32 *arg0) {
    s32 i;
    s8 *p;

    SetGraphDebug(0);
    func_80012DA8();
    ResetCallback();
    i = 1;
    p = &D_8002B6B1;
    do {
        *p = 0;
        i -= 1;
        p -= 1;
    } while (i >= 0);
    arg0[1] = VSyncCallback(func_80013690);
}


void func_800141A4(u8 *arg0) {
    s32 i;
    s32 j;
    s32 off;
    s32 one;
    u8 *p4;
    u8 *pc;
    u8 *pb;

    i = 0;
    one = 1;
    off = 0;
    p4 = D_8002B6C4;
    pc = D_8002B6BC;
    pb = D_8002B6B8;
    while (1) {
        if (i >= 2) {
            break;
        }
        *(u8 *)(arg0 + i + 8) = one;
        D_8002B72C[i] = one;
        D_8002B6B0[i] = one;
        D_8002B6B4[i] = 0;
        D_8002B6C0[i] = 0;
        for (j = 0; j < 2; j++) {
            pb[j] = 0;
            pc[j] = 0;
            p4[j] = 0;
        }
        memset(D_8002B6C8 + off, 0, 0x22);
        off += 0x22;
        p4 += 2;
        pc += 2;
        pb += 2;
        i += 1;
    }
    PadInitDirect(D_8002B6C8, D_8002B6C8 + 0x22);
    PadStartCom();
}


s32 func_800142D4(s32 unused, s32 arg0, s32 arg1) {
    s32 idx;
    u8 *p;

    if (D_8002B65C >= 6) {
        return 0;
    }
    idx = D_8002B65C;
    D_8002B678[idx] = arg1;
    D_8002B660[idx] = (void *)arg0;
    p = *(u8 **)(arg0 + 4);
    D_8002B65C = idx + 1;
    ((void (*)(s32)) *(u32 *)(p + 0x14))(arg0 + *(s16 *)(p + 0x10));
    return 1;
}

#ifdef NON_MATCHING
void func_80014348(s32 unused, void *arg0) {
    s32 i = 0;
    s32 j;
    s32 *p = D_8002B660;

    while (1) {
        if (i >= D_8002B65C) {
            break;
        }
        if (*p == (s32)arg0) {
            if (i < D_8002B65C - 1) {
                for (j = i; j < D_8002B65C - 1; j++) {
                    D_8002B678[j] = D_8002B678[j + 1];
                    D_8002B660[j] = D_8002B660[j + 1];
                }
            }
            D_8002B65C -= 1;
        }
        p += 1;
        i += 1;
    }
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_c", func_80014348);
#endif


void func_8001440C(s32 *arg0) {
    s32 cb;

    cb = arg0[1];
    D_8002B65C = 0;
    VSyncCallback(cb);
    arg0[1] = 0;
    PadStopCom();
}


void func_8001444C(s32 unused, s8 arg1) {
    D_8002B6AB = arg1;
}


void func_8001445C(s32 a0, u8 a1) {
    D_8002B6AA = a1;
}


u16 func_8001446C(s32 unused, s32 idx) {
    return D_8002B698[idx];
}


u16 func_80014484(s32 a0, s32 a1) {
    return D_8002B6A0[a1];
}


u16 func_8001449C(s32 a0, s32 a1) {
    return D_8002B6A4[a1];
}


u16 func_800144B4(s32 arg0, s32 arg1) {
    if (D_8002B6A8[arg1] >= D_8002B6AA) {
        return D_8002B698[arg1];
    }
    return D_8002B6A4[arg1];
}


void func_80014500(s32 a0, s32 a1) {
    D_8002B6A0[a1] = 0;
    D_8002B6A4[a1] = 0;
}


void func_80014524(s32 a0, s8 a1) {
    D_8002B6AC = a1;
}


void func_80014534(void) {
    D_8002B6AD = 0;
    D_8002B690 = 0;
}


s32 func_8001454C(void) {
    return D_8002B690;
}


void func_8001455C(s32 a0, s32 a1) {
    D_8002B690 = a1;
    D_8002B6AD = 0;
}


void func_80014574(s32 arg0, s32 arg1) {
    D_8002B694 = arg1;
}

void func_80014584(void) {
}

Pair *func_8001458C(Pair *dst, Pair *src) {
    volatile s32 save;

    save = dst->b;
    *dst = *src;
    dst->b = save;
    return dst;
}


typedef struct {
    s32 a;
    void *b;
} PairPtr;

PairPtr *func_800145C4(PairPtr *dst, PairPtr *src) {
    *dst = *src;
    dst->b = &D_8002A974;
    return dst;
}


PairPtr *func_800145E8(PairPtr *dst) {
    dst->b = &D_8002A974;
    return dst;
}

void func_800145FC(void) {
}

u8 *func_80014604(u8 *arg0) {
    *(s16 *)(arg0 + 0x3240) = 0;
    *(s32 *)(arg0 + 0x323C) = 0;
    *(s16 *)(arg0 + 0x3242) = 0;
    *(s32 *)(arg0 + 0x1574) = 0;
    *(s32 *)(arg0 + 0x1578) = 0;
    return arg0;
}

void func_80014620(u8 *arg0, u8 *arg1) {
    *(u8 **)(arg0 + 0x38) = arg1 + 4;
    *(u8 **)(arg0 + 0x3C) = arg1 + *(s32 *)arg1;
}


void func_8001463C(void) {
    func_80015398(D_8002B750);
}


void func_80014664(u8 *arg0) {
    s32 i;
    u8 *p;
    u8 *st;

    st = SpuStInit(0);
    *(u8 **)(arg0 + 0x10E4) = st;
    *(s32 *)st = 0x100;
    *(s32 *)(arg0 + 0x325C) = 0;
    *(s32 *)(arg0 + 0x3260) = 0;
    *(s16 *)(arg0 + 0x3264) = 0;
    *(s16 *)(arg0 + 0x3266) = 0;
    p = (u8 *)0x70000;
    i = 0;
    do {
        *(u8 **)(*(u8 **)(arg0 + 0x10E4) + (i << 4) + 0x10) = p;
        i++;
        p += 0x100;
    } while (i < 0x18);
    SpuStSetPreparationFinishedCallback(func_80014704);
    SpuStSetTransferFinishedCallback(func_80014760);
    SpuStSetStreamFinishedCallback(func_8001478C);
}

typedef struct {
    u8 pad[0x10DD];
    u8 unk10DD;
    u8 unk10DE;
} SndA;


void func_80014704(s32 arg0) {
    ((SndA *)D_8002B750)->unk10DD = 1;
    ((SndA *)D_8002B750)->unk10DE = 0;
    func_8001483C((SndObj *)D_8002B750, arg0);
    SpuStTransfer(5, arg0);
}


void func_80014760(s32 arg0) {
    func_8001483C((SndObj *)D_8002B750, arg0);
}

typedef struct {
    u8 pad[0xBBE];
    u8 unkBBE;
    u8 pad2[0x3266 - 0xBBF];
    s16 unk3266;
} SndB;


void func_8001478C(u32 arg0) {
    u32 notv;
    s32 i;
    s32 off;

    SpuSetKey(0, arg0);
    notv = ~arg0;
    if ((notv & SpuStGetVoiceStatus()) == 0) {
        ((SndB *)D_8002B750)->unk3266 = 1;
    }
    i = 0;
    if (arg0 != 0) {
        off = 0;
        do {
            if (arg0 & 1) {
                func_8001A144(D_8002B750, i);
                *(u8 *)((u8 *)D_8002B750 + off + 0xBBE) = 0;
            }
            off += 0x38;
            arg0 >>= 1;
            i++;
        } while (arg0 != 0);
    }
}

typedef struct {
    u8 pad[8];
    u8 unk8;
    u8 pad9[3];
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Ent;

typedef struct {
    u8 pad[0xBA4];
    s32 unkBA4;
    s32 unkBA8;
} Ch;

void func_8001483C(SndObj *arg0, u32 arg1) {
    s32 i;
    s32 off;
    s32 off2;

    arg0->unk10E0 = 0;
    i = 0;
    if (arg1 != 0) {
        do {
            off = i * 16;
            if (arg1 & 1) {
                ((Ent *)(arg0->unk10E4 + off))->unk14 += 0x80;
                ((Ch *)((u8 *)arg0 + i * 0x38))->unkBA8 += 0x80;
                if (((Ch *)((u8 *)arg0 + i * 0x38))->unkBA4 - 0x80 < ((Ch *)((u8 *)arg0 + i * 0x38))->unkBA8) {
                    ((Ent *)(arg0->unk10E4 + off))->unk8 = 2;
                    ((Ent *)(arg0->unk10E4 + off))->unkC = ((Ch *)((u8 *)arg0 + i * 0x38))->unkBA4 - ((Ch *)((u8 *)arg0 + i * 0x38))->unkBA8;
                }
            }
            i++;
            arg1 >>= 1;
        } while (arg1 != 0);
    }
    i = 0;
    if (arg0->unk3264 == 0 && arg0->unk3260 != 0) {
        do {
            off2 = i * 16;
            if (arg0->unk3260 & 1) {
                ((Ent *)(arg0->unk10E4 + off2))->unk8 = 2;
                ((Ent *)(arg0->unk10E4 + off2))->unkC = 0x80;
            }
            i++;
        } while ((arg0->unk3260 >>= 1) != 0);
    }
}

typedef struct {
    u8 pad[0x10DD];
    u8 unk10DD;
    u8 unk10DE;
    u8 unk10DF;
    s32 unk10E0;
    u8 *unk10E4;
    u8 pad2[0x325C - 0x10E8];
    u32 unk325C;
    u8 pad3[0x3264 - 0x3260];
    u16 unk3264;
    s16 unk3266;
} Snd;


void func_80014948(void *arg0_)
{
    Snd *arg0 = arg0_;
  s16 t2;
  s16 t3;
  s32 i;
  s32 t;
  u32 c;
  u32 mask;
  int new_var;
  arg0->unk10E0 = arg0->unk10E0 + 1;
  if ((arg0->unk10DD != 0) && (arg0->unk10E0 >= 0x191))
  {
    func_80014664((u8 *) arg0);
    arg0->unk3266 = 1;
    SpuSetTransferCallback(&func_80018EF0);
  }
  t2 = arg0->unk3266;
  if (t2 != 0)
  {
    t3 = t2 - 1;
    arg0->unk3266 = t3;
    if ((t3 << 16) == 0)
    {
      arg0->unk10DD = 0;
      arg0->unk10DF = 0;
    }
  }
  c = arg0->unk3264 - 1;
  if ((c & 0xFFFF) < 0x62)
  {
    arg0->unk3264 = c;
  }
  mask = arg0->unk325C;
  i = 0;
  if (mask != 0)
  {
    do
    {
      new_var = arg0->unk325C & 1;
      t = i * 16;
      if (new_var)
      {
        *((s32 *) ((arg0->unk10E4 + t) + 0x14)) = *((s32 *) ((((u8 *) arg0) + (i * 0x38)) + 0xBA0));
        *((u8 *) ((arg0->unk10E4 + t) + 8)) = 6;
        *((s32 *) ((((u8 *) arg0) + (i * 0x38)) + 0xBA8)) = 0;
      }
      i++;
    }
    while ((arg0->unk325C >>= 1) != 0);
    SpuStTransfer(4, mask);
    arg0->unk3264 = 1;
  }
}


void func_80014A6C(u8 *arg0) {
    s32 ev;
    Obj *p;

    D_8002B748 = 0;
    D_8002B750 = arg0;
    EnterCriticalSection();
    SpuInitMalloc(4, arg0 + 0x154C);
    SpuInit();
    func_80014664(arg0);
    SpuSetMute(1);
    SpuSetTransferMode(0);
    func_80014CA4(arg0);
    SpuSetPitchLFOVoice(0, 0xFFFFFF);
    SpuSetNoiseVoice(0, 0xFFFFFF);
    SpuSetNoiseClock(0);
    func_8001510C(arg0);
    ResetRCnt(0xF2000002);
    ev = OpenEvent(0xF2000002, 2, 0x1000, &func_8001463C);
    *(s32 *)(arg0 + 0x20) = ev;
    EnableEvent(ev);
    func_80015294(arg0);
    StartRCnt(0xF2000002);
    SpuSetMute(0);
    SpuSetTransferCallback(&func_80018EF0);
    ExitCriticalSection();
    p = __builtin_new(8);
    p->unk4 = &D_8002AA04;
    *(Obj **)(arg0 + 0x10D8) = p;
}


void func_80014B8C(u8 *arg0) {
    s32 i;

    for (i = 1; i < 9; i++) {
        func_8001A174(arg0, i);
    }
    do {
    } while (func_80018F70(arg0) != 0);
    EnterCriticalSection();
    *(s32 *)(arg0 + 0x3254) = 0;
    arg0[0x5E] = 0;
    arg0[0x66] = 0;
    arg0[0x6E] = 0;
    *(s32 *)(arg0 + 0x40) &= ~1;
    func_800183E0(arg0, -1);
    SpuSetKey(0, 0xFFFFFF);
    StopRCnt(0xF2000002);
    CloseEvent(*(s32 *)(arg0 + 0x20));
    DisableEvent(*(s32 *)(arg0 + 0x20));
    SpuSetMute(1);
    SpuSetReverb(0);
    SpuSetReverbVoice(0, 0xFFFFFF);
    *(s32 *)(arg0 + 0x10DC) = 0;
    SpuSetTransferCallback(0);
    SpuQuit();
    SpuStQuit();
    SpuInit();
    SpuQuit();
    ExitCriticalSection();
}

#ifdef NON_MATCHING
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    u8 pad10[0x30];
} VoiceAttr;
void func_80014CA4(u8 *arg0) {
    VoiceAttr va;
    s32 i;
    u8 *p;
    s32 tmp;

    memset(arg0 + 0x20, 0, 0x78);
    memset(arg0 + 0x98, 0, 0xB00);
    memset(arg0 + 0xB98, 0, 0x540);
    memset(arg0 + 4, 0, 0x1C);
    memset(arg0 + 0x112C, 0, 0x1A0);
    *(u8 *)(arg0 + 0x53) = 0x50;
    *(u8 *)(arg0 + 0x5B) = 0x50;
    *(u8 *)(arg0 + 0x62) = 0x7F;
    *(u8 *)(arg0 + 0x6A) = 0x7F;
    *(u8 *)(arg0 + 0x72) = 0x7F;
    *(s16 *)(arg0 + 0x78) = 0x3FFF;
    *(s16 *)(arg0 + 0x7A) = 0x3FFF;
    *(s16 *)(arg0 + 0x50) = 0x7F7F;
    *(u16 *)(arg0 + 0x4C) = 0x9371;
    *(s16 *)(arg0 + 0x4E) = 0x5713;
    *(u8 **)(arg0 + 0x48) = arg0 + 0x1530;
    *(u8 **)(arg0 + 0x44) = arg0 + 0x1531;
    *(u8 **)(arg0 + 0x12D0) = arg0 + 0x1580;
    *(u8 **)(arg0 + 0x1300) = arg0 + 0x1744;
    *(u8 **)(arg0 + 0x1330) = arg0 + 0x1908;
    *(u8 **)(arg0 + 0x1360) = arg0 + 0x1ACC;
    *(u8 **)(arg0 + 0x1390) = arg0 + 0x1C90;
    *(u8 **)(arg0 + 0x13C0) = arg0 + 0x1CE8;
    *(u8 **)(arg0 + 0x13F0) = arg0 + 0x1D40;
    *(u8 **)(arg0 + 0x1420) = arg0 + 0x2444;
    *(u8 **)(arg0 + 0x1450) = arg0 + 0x27C8;
    *(u8 **)(arg0 + 0x1480) = arg0 + 0x2804;
    *(u8 **)(arg0 + 0x14B0) = arg0 + 0x2840;
    *(u8 **)(arg0 + 0x14E0) = arg0 + 0x287C;
    *(s32 *)(arg0 + 0x13C8) = 0x40000;
    *(s32 *)(arg0 + 0x13F8) = 0x1010;
    *(u8 *)(arg0 + 0x52) = 0;
    *(s32 *)(arg0 + 0x12D8) = 0x48000;
    *(s32 *)(arg0 + 0x1308) = 0x52000;
    *(s32 *)(arg0 + 0x1338) = 0x5C000;
    *(s32 *)(arg0 + 0x1368) = 0x66000;
    *(s32 *)(arg0 + 0x1398) = 0x38000;
    *(s32 *)(arg0 + 0x1428) = 0x18000;
    *(s32 *)(arg0 + 0x1458) = 0x70000;
    *(u8 **)(arg0 + 0x12DC) = arg0 + 0x28B8;
    *(u8 **)(arg0 + 0x130C) = arg0 + 0x2998;
    *(u8 **)(arg0 + 0x133C) = arg0 + 0x2A78;
    *(u8 **)(arg0 + 0x136C) = arg0 + 0x2B58;
    *(u8 **)(arg0 + 0x139C) = arg0 + 0x2C38;
    *(u8 **)(arg0 + 0x13CC) = arg0 + 0x2C70;
    *(u8 **)(arg0 + 0x145C) = arg0 + 0x2CA8;
    *(u8 **)(arg0 + 0x148C) = arg0 + 0x2CC4;
    *(u8 **)(arg0 + 0x14BC) = arg0 + 0x2CE0;
    *(u8 **)(arg0 + 0x14EC) = arg0 + 0x2CFC;
    *(u8 **)(arg0 + 0x12E4) = arg0 + 0x28D8;
    *(u8 **)(arg0 + 0x1314) = arg0 + 0x29B8;
    *(u8 **)(arg0 + 0x1344) = arg0 + 0x2A98;
    *(u8 **)(arg0 + 0x1374) = arg0 + 0x2B78;
    *(u8 **)(arg0 + 0x13A4) = arg0 + 0x2C40;
    *(u8 **)(arg0 + 0x13D4) = arg0 + 0x2C78;
    *(u8 **)(arg0 + 0x1464) = arg0 + 0x2CAC;
    *(u8 **)(arg0 + 0x1494) = arg0 + 0x2CC8;
    *(u8 **)(arg0 + 0x14C4) = arg0 + 0x2CE4;
    *(u8 **)(arg0 + 0x14F4) = arg0 + 0x2D00;
    *(u8 **)(arg0 + 0x12EC) = arg0 + 0x2D18;
    *(u8 **)(arg0 + 0x131C) = arg0 + 0x2DF8;
    *(u8 **)(arg0 + 0x134C) = arg0 + 0x2ED8;
    *(u8 **)(arg0 + 0x137C) = arg0 + 0x2FB8;
    *(u8 **)(arg0 + 0x13AC) = arg0 + 0x3098;
    *(u8 **)(arg0 + 0x13DC) = arg0 + 0x30D0;
    *(u8 **)(arg0 + 0x146C) = arg0 + 0x3108;
    *(u8 **)(arg0 + 0x149C) = arg0 + 0x3140;
    *(u8 **)(arg0 + 0x14CC) = arg0 + 0x3178;
    *(u8 **)(arg0 + 0x14FC) = arg0 + 0x31B0;
    *(s32 *)(arg0 + 0x1488) = 0x70100;
    *(s32 *)(arg0 + 0x14B8) = 0x70200;
    *(s32 *)(arg0 + 0x14E8) = 0x70300;
    *(u8 **)(arg0 + 0x12F4) = arg0 + 0x2D38;
    *(u8 **)(arg0 + 0x1324) = arg0 + 0x2E18;
    *(u8 **)(arg0 + 0x1354) = arg0 + 0x2EF8;
    *(u8 **)(arg0 + 0x1384) = arg0 + 0x2FD8;
    *(u8 **)(arg0 + 0x13B4) = arg0 + 0x30A0;
    *(u8 **)(arg0 + 0x13E4) = arg0 + 0x30D8;
    *(u8 **)(arg0 + 0x1474) = arg0 + 0x3110;
    *(u8 **)(arg0 + 0x14A4) = arg0 + 0x3148;
    *(u8 **)(arg0 + 0x14D4) = arg0 + 0x3180;
    *(u8 **)(arg0 + 0x1504) = arg0 + 0x31B8;
    *(u8 **)(arg0 + 0x12F8) = arg0 + 0x31E8;
    *(u8 **)(arg0 + 0x1328) = arg0 + 0x31FC;
    *(u8 **)(arg0 + 0x1358) = arg0 + 0x3210;
    *(u8 **)(arg0 + 0x1388) = arg0 + 0x3224;
    i = 0;
    do {
        *(s32 *)(arg0 + i * 0x30 + 0x12CC) = *(s32 *)(arg0 + i * 0x30 + 0x12D0);
        *(s32 *)(arg0 + i * 0x30 + 0x12D4) = *(s32 *)(arg0 + i * 0x30 + 0x12D8);
        **(s32 **)(arg0 + i * 0x30 + 0x12D0) = -1;
        if ((u32)(i - 6) >= 2) {
            tmp = *(s32 *)(arg0 + i * 0x30 + 0x12DC);
            memset((void *)tmp, 0, *(s32 *)(arg0 + i * 0x30 + 0x12E4) - tmp);
            *(s32 *)(arg0 + i * 0x30 + 0x12E0) = *(s32 *)(arg0 + i * 0x30 + 0x12E4);
            *(s32 *)(arg0 + i * 0x30 + 0x12E8) = *(s32 *)(arg0 + i * 0x30 + 0x12EC);
            *(s32 *)(arg0 + i * 0x30 + 0x12F0) = *(s32 *)(arg0 + i * 0x30 + 0x12F4);
        }
        i++;
    } while (i != 0xC);
    i = 0;
    do {
        func_80018FA0(arg0, i);
        i++;
    } while (i != 6);
    *(s32 *)(arg0 + 0x10E8) = 0;
    i = 0;
    do {
        *(u8 *)(arg0 + i + 0x1531) = i;
        i++;
    } while (i < 0x18 - *(s32 *)(arg0 + 0x10E8));
    *(u8 **)(arg0 + 0x48) = arg0 + 0x1530;
    *(s32 *)(arg0 + 0x10EC) = 0;
    *(u8 **)(arg0 + 0x44) = arg0 + 0x1531;
    p = arg0 + 0x23;
    i = 0x23;
    do {
        *(u8 *)(p + 0x150C) = 0x60;
        i--;
        p--;
    } while (i >= 0);
    i = 0x18;
    do {
        *(s32 *)(arg0 + i * 0x58 + 0x98) = 0x800;
        i++;
    } while (i < 0x20);
    i = 0x1F;
    do {
        *(u8 *)(arg0 + i * 0x58 + 0xDA) = 0x7F;
        i--;
    } while (i >= 0);
    va.unk0 = 0xFFFFFF;
    va.unk4 = 0xC;
    va.unkC = 0;
    va.unkE = 0;
    SpuSetVoiceAttr(&va);
    *(s32 *)(arg0 + 0x10DC) = 0;
}
#else
INCLUDE_ASM("asm/main/nonmatchings/main_c", func_80014CA4);
#endif


void func_8001510C(u8 *arg0) {
    *(s32 *)(arg0 + 0x10F4) = 5;
    *(s32 *)(arg0 + 0x10FC) = 0;
    *(s32 *)(arg0 + 0x1100) = 0;
    func_8001514C();
    func_800151D4(arg0);
}


void func_8001514C(u8 *arg0) {
    ReverbParam sp10;

    SpuGetReverbModeParam(&sp10);
    if (sp10.unk4 != *(s32 *)(arg0 + 0x10F4)) {
        SpuSetReverb(0);
        SpuSetReverbVoice(0, 0xFFFFFF);
        SpuClearReverbWorkArea(*(s32 *)(arg0 + 0x10F4));
        *(s32 *)(arg0 + 0x10F0) = 0x19;
        if (SpuSetReverbModeParam((ReverbParam *)(arg0 + 0x10F0)) != -1) {
            SpuSetReverb(1);
        }
    }
}


void func_800151D4(u8 *arg0) {
    u16 v1;
    u16 a1;

    v1 = *(u16 *)(arg0 + 0x78);
    if (*(u8 *)(arg0 + 0x7C) != 0) {
        v1 = -v1;
    }
    a1 = *(u16 *)(arg0 + 0x7A);
    *(u16 *)(arg0 + 0x10F8) = v1;
    if (*(u8 *)(arg0 + 0x7D) != 0) {
        a1 = -a1;
    }
    *(u16 *)(arg0 + 0x10FA) = a1;
    *(s32 *)(arg0 + 0x10F0) = 6;
    SpuSetReverbDepth(arg0 + 0x10F0);
}


void func_8001522C(u8 *arg0) {
    *(u16 *)(arg0 + 0x1108) = 0x3FFF;
    *(u16 *)(arg0 + 0x110A) = 0x3FFF;
    *(u16 *)(arg0 + 0x1110) = 0x3FFF;
    *(u16 *)(arg0 + 0x1112) = 0x3FFF;
    *(u16 *)(arg0 + 0x1114) = 0x7FFF;
    *(u16 *)(arg0 + 0x1116) = 0x7FFF;
    *(s32 *)(arg0 + 0x1104) = 0;
    *(u16 *)(arg0 + 0x110C) = 0;
    *(u16 *)(arg0 + 0x110E) = 0;
    *(s32 *)(arg0 + 0x1118) = 0;
    *(s32 *)(arg0 + 0x111C) = 1;
    *(u16 *)(arg0 + 0x1120) = 0;
    *(u16 *)(arg0 + 0x1122) = 0;
    *(s32 *)(arg0 + 0x1124) = 0;
    *(s32 *)(arg0 + 0x1128) = 0;
    SpuSetCommonAttr(arg0 + 0x1104);
}
