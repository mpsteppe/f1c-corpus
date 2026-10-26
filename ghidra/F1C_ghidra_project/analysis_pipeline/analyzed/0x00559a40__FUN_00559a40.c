// Function: FUN_00559a40 @ 00559a40
// Size (bytes): 39


undefined4 * __fastcall FUN_00559a40(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 3;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  return param_1;
}


