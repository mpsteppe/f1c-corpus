// Function: FUN_0048ebd0 @ 0048ebd0
// Size (bytes): 465


undefined4 __fastcall FUN_0048ebd0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00487060(0);
  param_1[0x44] = iVar1;
  iVar1 = FUN_00487060(1);
  param_1[0x45] = iVar1;
  iVar1 = FUN_00487060(2);
  param_1[0x46] = iVar1;
  iVar1 = FUN_00487060(3);
  param_1[0x47] = iVar1;
  iVar1 = FUN_00487060(4);
  param_1[0x48] = iVar1;
  iVar1 = FUN_00487060(5);
  param_1[0x49] = iVar1;
  iVar1 = FUN_00487060(6);
  param_1[0x4a] = iVar1;
  iVar1 = FUN_00487060(7);
  param_1[0x4b] = iVar1;
  iVar1 = FUN_004870e0(0);
  param_1[0x4c] = iVar1;
  iVar1 = FUN_004870e0(1);
  param_1[0x4d] = iVar1;
  iVar1 = FUN_004870e0(2);
  param_1[0x4e] = iVar1;
  iVar1 = FUN_004870e0(3);
  param_1[0x4f] = iVar1;
  iVar1 = FUN_004870e0(4);
  param_1[0x50] = iVar1;
  iVar1 = FUN_004870e0(5);
  param_1[0x51] = iVar1;
  iVar1 = FUN_004870e0(6);
  param_1[0x52] = iVar1;
  iVar1 = FUN_004870e0(7);
  param_1[0x53] = iVar1;
  if (param_1[0x50] < 0) {
    param_1[0x50] = param_1[1];
  }
  if (param_1[0x48] < 0) {
    param_1[0x48] = param_1[3];
  }
  if (param_1[0x51] < 0) {
    param_1[0x51] = param_1[2];
  }
  if (param_1[0x49] < 0) {
    param_1[0x49] = param_1[4];
  }
  param_1[0x5d] = 0;
  (**(code **)(*param_1 + 0x40))(param_1[0x41]);
  iVar1 = FUN_00486460(6);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    param_1[0x39] = *(int *)(*(int *)(iVar1 + 0x20) + 0xc);
  }
  iVar1 = FUN_00486460(7);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    param_1[0x3a] = *(int *)(*(int *)(iVar1 + 0x20) + 0xc);
  }
  iVar1 = FUN_00486460(5);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    param_1[0x3b] = *(int *)(*(int *)(iVar1 + 0x20) + 0xc);
  }
  FUN_0048f9f0();
  FUN_00566650(&DAT_005ea438);
  param_1[0x5a] = 0;
  return 0;
}


