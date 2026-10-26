// Function: FUN_00550760 @ 00550760
// Size (bytes): 64


undefined4 * __fastcall FUN_00550760(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0053c2a0();
  *(undefined1 *)(param_1 + 0x11) = 0;
  *param_1 = 0xffffffff;
  puVar2 = param_1 + 1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[6] = 0x3f800000;
  param_1[0xb] = 0x3f800000;
  param_1[0x10] = 0x3f800000;
  param_1[1] = 0x3f800000;
  param_1[0x21] = 0;
  return param_1;
}


