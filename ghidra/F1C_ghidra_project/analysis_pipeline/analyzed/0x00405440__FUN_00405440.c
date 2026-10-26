// Function: FUN_00405440 @ 00405440
// Size (bytes): 82


void __fastcall FUN_00405440(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0xffffffff;
  FUN_00566650(&DAT_005ea438);
  param_1[3] = 0;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  FUN_0052d990();
  param_1[0xe] = 0;
  puVar2 = param_1 + 0x11;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x1c) = 0;
  return;
}


