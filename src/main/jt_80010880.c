#define INCLUDE_ASM_USE_MACRO_INC 1
#include "common.h"
#include "main.h"


void func_80010880(void) {
    u8 sp10[8];
    u8 sp18[2];
    u8 sp20[8];
    u16 n;

    if (--D_8002B62E == 0) {
        D_8002B62E = 8;
        switch (D_8002B62C) {
        case 2:
            func_80025444(0, sp10);
            func_800255EC(1, 0);
            break;
        case 3:
            D_8002B62F = 0;
            D_8002B632 = 0;
            sp20[0] = 0;
            D_8002B633++;
            if (D_8002B633 >= 5) {
                if (func_80025338(0) == 0) {
                    break;
                }
                D_8002B62C = 7;
                D_8002B633 = 0;
                break;
            }
            func_80025444(0, sp10);
            if (func_800254B4(0xE, sp20, 0) != 0) {
                D_8002B62C = 4;
                D_8002B62E = 0xB4;
            }
            break;
        case 4:
            if (func_80025718(1, 0, sp10) != 0) {
                if (sp10[0] & 2) {
                    D_8002B62C = 5;
                    D_8002B632 = 0;
                    break;
                }
                D_8002B633 = 0;
                break;
            }
            D_8002B632++;
            if (D_8002B632 >= 0x1F) {
                D_8002B62C = 2;
            }
            break;
        case 5:
            if (func_80025718(0x13, 0, sp10) != 0) {
                D_8002B62C = 6;
                break;
            }
            D_8002B632++;
            if (D_8002B632 >= 0x1F) {
                D_8002B62C = 2;
            }
            break;
        case 6:
            sp18[0] = 1;
            sp18[1] = 1;
            if (func_800254B4(0xD, sp18, 0) != 0) {
                D_8002B62C = 7;
                break;
            }
            D_8002B62C = 3;
            break;
        case 7:
            sp20[0] = 0xA0;
            func_80025444(0, sp10);
            if (func_800254B4(0xE, sp20, 0) != 0) {
                D_8002B62C = 8;
                break;
            }
            D_8002B62C = 3;
            break;
        case 8:
            D_8002B633 = 0;
            D_8002B630 = 0;
            D_8002B5C4 = 0;
            D_8002B62D = 0;
            D_8002B62C = 1;
            func_80014348(D_8002B5CC, D_8002B61C);
            func_80025484(func_80010C34);
            n = D_8002B628;
            if (n != 4) {
                if (n != 5) {
                    goto done628;
                }
                D_8002B5D8 = D_8002B610;
                D_8002B5DC = D_8002B5E8;
            }
            D_8002B628 = 1;
        done628:
            sp10[0] = 0;
            func_80010C34(5, sp10);
            break;
        }
    }
}


void func_80010B84(void) {
    if (D_8002B614 == D_8002B5D8 && D_8002B62C == 0) {
        D_8002B618++;
        D_8002B5C4++;
        if (D_8002B618 > 600 && D_8002B601 != 0) {
            func_800112B4();
        }
    } else {
        D_8002B618 = 0;
        D_8002B614 = D_8002B5D8;
    }
}




typedef void (*ObjFn)(s32, s32);

void func_80010C34(s32 arg0, u8 *arg1) {
    s32 st;
    s32 arg;
    u8 *vt;

    st = arg0;
    if ((u8)D_8002B62C >= 3) {
        return;
    }
    if (D_8002B62C != 0) {
        if (*arg1 & 0x10) {
            if (D_8002B62C == 1) {
                func_800142D4(D_8002B5CC, D_8002B61C, 0);
                D_8002B62C = 2;
                D_8002B62E = 4;
                D_8002B62D = 1;
            }
            return;
        }
        if (D_8002B62C == 2) {
            D_8002B62E = 0x3C;
            D_8002B62C = 3;
            return;
        }
        if (D_8002B62F != 0) {
            func_8002549C(0);
            func_80014348(D_8002B5CC, D_8002B620);
            D_8002B62F = 0;
            D_8002B630++;
            if (D_8002B630 >= 6) {
                func_800142D4(D_8002B5CC, D_8002B61C, 0);
                D_8002B62C = 3;
                D_8002B62E = 4;
                return;
            }
            D_8002B628 = 1;
            D_8002B5D8 = D_8002B610;
            D_8002B5DC = D_8002B5E8;
            st = 5;
        }
    }
    if (D_8002B62C == 2) {
        return;
    }
    if ((st & 0xFF) != 5) {
        goto after;
    }
    if (D_8002B62C == 0) {
        D_8002B62C = 1;
        func_800255EC(1, 0);
        return;
    }
    D_8002B62C = 0;
    switch (D_8002B628) {
    case 1:
    case 2:
    case 6:
        if (D_8002B600 == 0) {
            func_800255EC(2, (void *)&D_8002B60C);
            return;
        }
        D_8002B628 = 0;
        D_8002B5EC = 0;
        return;
    case 3:
        func_800255EC(9, 0);
        return;
    case 4:
        if (D_8002B600 != 0) {
            D_8002B628 = 0;
            func_8002549C(0);
            D_8002B5EC = 0;
            func_80014348(D_8002B5CC, D_8002B620);
            if (D_8002B5D4 != 0) {
                arg = D_8002B608;
                vt = *(u8 **)(D_8002B5D4 + 4);
                D_8002B5C8 = 1;
                (*(ObjFn *)(vt + 0x1C))((s32)D_8002B5D4 + *(s16 *)(vt + 0x18), arg);
                D_8002B5C8 = 0;
            }
            return;
        }
        func_800255EC(D_8002B603, 0);
        return;
    default:
        break;
    }
after:
    if (D_8002B62C == 1) {
        D_8002B62C = 0;
    }
    if ((st & 0xFF) != 2) {
        return;
    }
    switch (D_8002B628) {
    case 1:
        if (D_8002B600 != 0) {
            D_8002B628 = 0;
            D_8002B62B = 0;
            D_8002B5EC = 0;
            return;
        }
        if (D_8002B62B == 1) {
            func_800255EC(2, (void *)&D_8002B60C);
            D_8002B62A = 1;
            D_8002B628 = 1;
            D_8002B62B = 2;
            return;
        }
        if (D_8002B62B == 2) {
            func_800255EC(0x15, 0);
            D_8002B62A = 1;
            D_8002B628 = 2;
            D_8002B62B = 0;
            return;
        }
    case 2:
        D_8002B62A = 0;
        if (D_8002B600 != 0) {
            D_8002B628 = 0;
            D_8002B5EC = 0;
            return;
        }
        if (D_8002B5E8 != 0) {
            D_8002B628 = 4;
            D_8002B624 = CdPosToInt((void *)&D_8002B60C);
            func_8002549C(func_800111B8);
            func_800255EC(D_8002B603, 0);
            func_800142D4(D_8002B5CC, D_8002B620, 0);
            D_8002B614 = 0;
            D_8002B618 = 0;
        } else {
            D_8002B628 = 0;
        }
        return;
    case 3:
        D_8002B628 = 0;
        D_8002B5EC = 0;
        func_80014348(D_8002B5CC, D_8002B620);
        if (D_8002B5D4 != 0) {
            arg = D_8002B608;
            vt = *(u8 **)(D_8002B5D4 + 4);
            D_8002B5C8 = 1;
            (*(ObjFn *)(vt + 0x1C))((s32)D_8002B5D4 + *(s16 *)(vt + 0x18), arg);
            D_8002B5C8 = 0;
        }
        return;
    case 4:
        if (D_8002B600 != 0) {
            D_8002B600 = 0;
            D_8002B628 = 3;
            func_8002549C(0);
            func_800255EC(9, 0);
            return;
        }
        D_8002B628 = 5;
        return;
    case 6:
        D_8002B628 = 4;
        D_8002B624 = CdPosToInt((void *)&D_8002B60C);
        func_800255EC(D_8002B603, 0);
        return;
    default:
        break;
    }
}
