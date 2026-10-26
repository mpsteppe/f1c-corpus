// Function: FUN_0054fe10 @ 0054fe10
// Size (bytes): 54


undefined4 * __fastcall FUN_0054fe10(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0053c2a0();
  puVar2 = param_1;
  for (iVar1 = 0x10; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
  }
  *param_1 = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x13] = 1;
  param_1[0x14] = 1;
  return param_1;
}


