#ifndef OVL_4911_H
#define OVL_4911_H

#include "main.h"

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    void (*unkC)(u8 *);
    s16 unk10;
    u8 pad12[2];
    void (*unk14)(u8 *, s32);
} Ovl4911Vtbl;

typedef struct {
    u8 pad0[4];
    Ovl4911Vtbl *unk4;
} Ovl4911Obj;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} SndChan;

typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} Entry;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Out;

typedef struct {
    s16 unk0;
    s16 unk2;
} Hdr;

typedef struct {
    u8 pad[0x64A9];
    u8 unk64A9;
    u8 pad2[0x64C0 - 0x64AA];
    void *unk64C0;
} Ctx64A9;

extern u8 D_8002F8D8;
extern u8 D_80033AA0;
extern s32 *D_80036810;
extern u8 *D_800370AC;
extern s16 *func_80031448(s32 arg0, s32 arg1);
extern u16 D_800370A2;
extern SndChan D_80033AB8;
extern SndChan D_80033AD0;
extern s32 D_800370B0;
extern u8 *D_80036804;
extern u8 *D_80036814;
extern u8 *D_8003682C;
extern u8 *D_80036830;
extern u8 *D_80036838;
extern u8 *D_80036844;
extern u8 *D_80036850[];
extern s32 D_80036C4C;
extern u8 *D_80036C54[];
extern s32 D_80037050;
extern u8 *D_80037058[];
extern s32 D_80037094;
extern u8 *D_80036834;
extern s32 D_800370CC;
extern s32 D_800370D0;
extern s32 D_800370D4;
extern s32 D_800370D8;
extern s32 D_800370DC;
extern s32 D_800370E0;
extern s32 func_800307C8(s32, s32, s32, s32);
extern s16 *D_8003684C[];
extern s16 *D_80036C50[];
extern s16 *D_80037054[];

extern s32 D_80036808;
extern s32 D_8003681C;
extern s32 D_80036828;
extern s32 D_8003683C;
extern s32 D_80036840;
extern u8 D_800366A0[];
extern u8 D_800366B6;
extern u8 D_800366B7;
extern u8 D_800366B8;
extern u8 D_800366B9;
extern u8 D_800366BA;
extern u8 D_800366BB;
extern u16 D_8003709C;
extern u16 D_8003709E;
extern s32 D_80037098;
extern s32 *D_800370C4;
extern u8 *D_800370B8;

extern void func_8002F8A4(u8 *, s32);
extern void func_8002F8F4(void);
extern void func_8002FB60(u8 *, s32);
extern s32 *func_8002FCF8(s32 *);
extern void func_8002FD44(void);
extern void func_8002FF84(void);
extern void func_80031160(s32, Out *);
extern s32 *func_80031378(s32);
extern void func_8003326C(void);

extern u8 *func_800100C4(void);
extern void func_80012EC8(void *, s32, s32, s32, s32);
extern void func_80012E90_ovl(void *, s32, s32, s32, s32) __asm__("func_80012E90");
extern void ClearImage(void *, s32, s32, s32);
extern void DrawSync(s32);
extern void PutDispEnv(void *);
extern void PutDrawEnv(void *);

#endif
