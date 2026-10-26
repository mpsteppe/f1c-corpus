// Function: FUN_004f2430 @ 004f2430
// Size (bytes): 188


undefined4 * __fastcall FUN_004f2430(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_0040e6a0();
  FUN_0040e6a0();
  iVar3 = 4;
  do {
    FUN_0040e6a0();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 8;
  do {
    FUN_0040e6a0();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  puVar2 = param_1 + 0x46;
  puVar1 = param_1 + 0x50;
  iVar3 = 8;
  do {
    puVar2[-8] = 0;
    *puVar2 = 0;
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return param_1;
}


