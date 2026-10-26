// Function: FUN_004fcaa0 @ 004fcaa0
// Strings:  [%sweather.txt]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fcaa0(int param_1)

{
  float *pfVar1;
  float fVar2;
  undefined1 *puVar3;
  int local_10c;
  int local_108;
  int local_104;
  undefined1 local_100 [256];
  
  FUN_004fd840();
  if (DAT_007cf080 == 0) {
    FUN_004fd8b0(0,0x48d2f000);
    puVar3 = DAT_005ec438;
    if (DAT_005ec438 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,s__sweather_txt_005d6f68,puVar3);
    FUN_004fe820(local_100);
  }
  *(undefined4 *)(param_1 + 0xa4) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x18) = 0xbf800000;
  *(undefined4 *)(param_1 + 0xc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  FUN_005439f0(&local_104,&local_10c,&local_108);
  *(float *)(param_1 + 0xb4) = (float)local_104 * _DAT_0059e460;
  *(float *)(param_1 + 0xb8) = (float)local_10c * _DAT_0059e460;
  *(float *)(param_1 + 0xbc) = (float)local_108 * _DAT_0059e460;
  FUN_00543a30(param_1 + 0xd8,param_1 + 0xdc);
  pfVar1 = (float *)(param_1 + 0xe0);
  FUN_00543a60(pfVar1);
  FUN_004fefc0(0x3e000000);
  fVar2 = _DAT_0059e444 - *pfVar1;
  *(undefined4 *)(param_1 + 0xc0) = 0x3f400000;
  *(undefined4 *)(param_1 + 0xc4) = 0x3f400000;
  *(undefined4 *)(param_1 + 200) = 0x3f400000;
  *(float *)(param_1 + 0xec) = fVar2 * *(float *)(param_1 + 0xa8) + *pfVar1;
  *(undefined4 *)(param_1 + 0xcc) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xd4) = 0x3f000000;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0x43160000;
  *(undefined4 *)(param_1 + 0xf8) = 0x3c23d70a;
  *(undefined4 *)(param_1 + 0xe4) = 0x432f0000;
  *(undefined4 *)(param_1 + 0xe8) = 0x4428c000;
  FUN_004ff040(0x3f000000,0);
  FUN_004fba10();
  *(undefined1 *)(param_1 + 0x1c4) = 0;
  return;
}


