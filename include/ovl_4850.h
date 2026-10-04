#ifndef OVL_4850_H
#define OVL_4850_H

#include "main.h"

typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[2];
    void (*unkC)(s32);
    s16 unk10;
    u8 pad12[2];
    void (*unk14)(s32, s32);
} Ovl4850Vtbl;

typedef struct {
    u8 pad0[4];
    Ovl4850Vtbl *unk4;
} Ovl4850Obj;

typedef struct {
    u8 b[8];
} Ovl4850B8;

typedef struct {
    s32 w[4];
} Ovl4850W4;

typedef struct {
    s32 unk0;
    u8 pad4[0xCC];
    Ovl4850B8 unkD0;
    Ovl4850W4 unkD8;
    Ovl4850B8 unkE8;
    u8 padF0[0x222];
    u16 unk312;
    u8 pad314[6];
    u16 unk31A;
    u16 unk31C;
    u16 unk31E;
    u16 unk320;
    u16 unk322;
    u16 unk324;
    u16 unk326;
    u8 pad328[0x6C];
    s16 unk394;
    u8 pad396[0x2A];
    u8 unk3C0;
    u8 pad3C1[2];
    u8 unk3C3;
} Ovl4850Ctx;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 pad7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} UnkBA34;

typedef struct {
    u8 pad[0x64];
    s16 unk64;
    s16 unk66;
    s16 unk68;
    s16 unk6A;
} Ovl4850T;

extern UnkBA34 D_8003BA34;
extern UnkBA34 D_8003BA4C;
extern s32 D_8003F23C;
extern u8 *D_8003F150;
extern s32 *D_8003F144;
extern u8 *D_8003F118;
extern void func_800359D8(s32, s32, s32, u8);
extern void func_80035C20(u8 *, s32, s32, s32);
extern u8 *func_800100C4(void);
extern u8 *D_8003F140;
extern u8 *D_8003F13C;
extern u8 *D_8003F138;
extern u8 *D_8003F148;
extern u8 *D_8003F120;
extern u8 *D_8003F154;
extern u8 *D_8003F15C;
extern u8 *D_8003F190;
extern u16 D_8003E258[];
extern u16 D_8003F258[];
extern u16 D_8003DA58[];
extern u16 D_8003EA58[];
extern u8 *D_8003F124;
extern u8 *D_8003F194;
extern s16 D_8003F164;
extern s32 D_8003F1A4;
extern s32 D_8003F1B4;
extern s32 D_8003F1C4;
extern s32 D_8003F1D4;
extern u8 D_8003F1D8;
extern u8 D_8002F8D8[];
extern void DrawSync(s32);
extern void func_8002FB60(u8 *, s32);
extern void func_80030ECC(void);
extern u8 *D_8003F244;
extern u8 *D_8003F14C;

extern u8 D_8003F038[];
extern u8 D_8003F094[];
extern Ovl4850Ctx *D_8003F12C;
extern s32 D_8003F130;
extern s32 D_8003F134;
extern u8 *D_8003F158;
extern u16 D_8003F234;
extern u16 D_8003F236;
extern s32 D_8003F240;
extern u8 *D_8003F248;
extern u8 *D_8003F24C;
extern s32 *D_8003F250;
extern s32 D_8003F254;
extern s16 D_8003F160;
extern s16 D_8003F162;
extern s32 D_8003F168;
extern s32 D_8003F16C;
extern s32 D_8003F170;
extern s32 D_8003F174;
extern s16 D_8003F178;
extern s16 D_8003F17A;
extern s16 D_8003F17C;
extern u8 D_8003F198;
extern u8 D_8003F1E0;
extern s16 D_8003F222;
extern s16 D_8003F224;
extern s16 D_8003F226;
extern s16 D_8003F228;
extern s16 D_8003F22A;
extern s16 D_8003F22C;
extern s16 D_8003F230;
extern s16 D_8003F232;
extern u8 D_8003F04E;
extern u8 D_8003F04F;
extern u8 D_8003F050;
extern u8 D_8003F051;
extern u8 D_8003F052;
extern u8 D_8003F053;
extern u8 D_8003F0BE;
extern u8 D_8003F0BF;
extern u8 D_8003F0C0;
extern u8 D_8003F0C1;
extern u8 D_8003F0C2;
extern u8 D_8003F0C3;
extern u8 D_8003B488;

extern void func_8002F8A4(u8 *, s32);
extern u8 *func_8002FDDC(s32);
extern u8 *func_8002FD78(void);
extern void func_8002FCF8(void);
extern void func_80032030(void);
extern void func_80032FFC(Ovl4850T *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80033054(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80033140(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80033824(void);
extern void func_800339D4(u8 *);
extern void func_800394B4(void);
extern void func_80039B20(s32, s8, s32);
extern void func_80039BF0(void);
extern void func_80039C2C(u8 *, u8 *);
extern s32 func_80039CAC(s32);
extern s32 func_80039D40(s32);
extern void func_8003A104(s32, s16 *);

extern void func_80012EC8(void *, s32, s32, s32, s32);
extern s32 func_80013DD0(s32, s32, s32 *, s32 *, s32 *, s32 *);
extern void func_80011BC4(s32, s32, s32, s32);
extern void func_800105B0(s32, s32, s32);
extern s32 func_80019B70(u8 *, s32, s8, u16);
extern void PutDispEnv(void *);
extern void PutDrawEnv(void *);
extern void StoreImage(void *, void *);
extern void func_8001190C_ovl(s32, s32, s32) __asm__("func_8001190C");
extern void func_80012E90_ovl(void *, s32, s32, s32, s32) __asm__("func_80012E90");

#endif
