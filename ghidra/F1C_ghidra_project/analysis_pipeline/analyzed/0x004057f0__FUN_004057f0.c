// Function: FUN_004057f0 @ 004057f0
// Size (bytes): 137


undefined4 * __thiscall
FUN_004057f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 *puVar1;
  
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  *param_1 = &PTR_FUN_0059e490;
  puVar1 = (undefined1 *)*param_2;
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566650(puVar1);
  param_1[3] = param_2[2];
  param_1[4] = param_2[3];
  param_1[6] = param_4;
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[5] = param_3;
  param_1[7] = 0x3c23d70a;
  param_1[8] = 0x3f79999a;
  param_1[9] = 0x3f000000;
  param_1[0x11] = 0x472c4400;
  param_1[0x15] = param_5;
  param_1[0x18] = 0xffffffff;
  return param_1;
}


