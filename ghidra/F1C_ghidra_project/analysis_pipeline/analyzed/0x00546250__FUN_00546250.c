// Function: FUN_00546250 @ 00546250
// Size (bytes): 217


undefined4 * __fastcall FUN_00546250(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0053c2a0();
  param_1[0x27] = 0x48900002;
  param_1[0x28] = 0xffffffff;
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  puVar2 = param_1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00547140(2,0xffffff);
  FUN_00547140(1,0xffffff);
  FUN_00547140(3,0);
  FUN_00547140(4,0);
  FUN_005471d0(2,0);
  FUN_005471d0(1,0);
  FUN_005471d0(3,0);
  FUN_005471d0(4,0);
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2d] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0x2f] = 0;
  param_1[0x2b] = 0x10002;
  param_1[0x2c] = 0x3f800000;
  return param_1;
}


