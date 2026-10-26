// Function: FUN_0047f370 @ 0047f370
// Size (bytes): 82


undefined4 * __fastcall FUN_0047f370(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00495190();
  param_1[0x864] = 0xffffffff;
  param_1[0x863] = 0;
  param_1[0x866] = 0xffffffff;
  param_1[0x865] = 0;
  param_1[0x868] = 0xffffffff;
  param_1[0x867] = 0;
  *param_1 = &PTR_FUN_005a6e70;
  puVar2 = param_1 + 0x647;
  for (iVar1 = 0x1fc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x843) = 0;
  return param_1;
}


