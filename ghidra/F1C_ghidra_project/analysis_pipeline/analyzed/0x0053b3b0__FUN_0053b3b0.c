// Function: FUN_0053b3b0 @ 0053b3b0
// Size (bytes): 43


void __fastcall FUN_0053b3b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[10] = 0x3f800000;
  param_1[0xf] = 0x3f800000;
  param_1[0x14] = 0x3f800000;
  param_1[0x19] = 0x3f800000;
  *param_1 = 1;
  return;
}


