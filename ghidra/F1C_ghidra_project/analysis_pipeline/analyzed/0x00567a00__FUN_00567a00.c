// Function: FUN_00567a00 @ 00567a00
// Size (bytes): 37


undefined4 * __fastcall FUN_00567a00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  puVar2 = param_1;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0xd] = 0;
  return param_1;
}


