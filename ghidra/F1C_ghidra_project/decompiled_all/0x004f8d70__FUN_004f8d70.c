// Function: FUN_004f8d70 @ 004f8d70
// Strings:  [FTFRAMERATE.BMP, FONT.MAS]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004f8d70(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0x461c3c00;
  param_1[5] = 0;
  pvVar1 = operator_new(0x4c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00556220();
  }
  param_1[6] = uVar2;
  FUN_00556260(1);
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_4 = (float)DAT_008b8dd4 * _DAT_005acf38;
  local_8 = (float)DAT_008b8dd8;
  param_1[7] = 900;
  param_1[8] = 2;
  param_1[9] = 0x280;
  local_8 = local_8 * _DAT_005ad26c;
  param_1[10] = 0x14;
  puVar3 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_0053c800(puVar3);
  local_c = 0;
  iVar4 = FUN_0053cbc0(&local_c,s_FONT_MAS_005d6d94);
  if (iVar4 == 0) {
    iVar4 = FUN_0053cfe0(0,s_FTFRAMERATE_BMP_005d6d84,0x20000);
    if (iVar4 == 0) {
      FUN_0053d260(s__FTFRAMERATE_005d6d77 + 1,0xffffff,0,0x40,0,2);
      FUN_0053d2b0(s__FTFRAMERATE_005d6d77 + 1,local_4,local_8);
      *param_1 = 2;
    }
    FUN_0053ce40(local_c);
  }
  return 0;
}


