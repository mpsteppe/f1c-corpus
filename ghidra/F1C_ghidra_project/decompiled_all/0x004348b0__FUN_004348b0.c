// Function: FUN_004348b0 @ 004348b0
// Strings:  [GRIDWALK_CAM]


undefined4 __fastcall FUN_004348b0(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00434d40();
  }
  pvVar1 = operator_new(0xd0);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004583b0();
  }
  *(int *)(param_1 + 0xc) = iVar2;
  if (iVar2 != 0) {
    iVar2 = FUN_004349a0();
    if (iVar2 == 0) {
      FUN_00566650(s_GRIDWALK_CAM_005c4088);
      iVar2 = *(int *)(param_1 + 0xc);
      *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(iVar2 + 0x3c) = 0x427a0000;
      FUN_004582c0(0);
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa8) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa4) = 0x40000000;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x48) = 0x3fa00000;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      FUN_00456150(&local_c);
      (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))();
      FUN_00434d60(0);
      return 0;
    }
  }
  return 1;
}


