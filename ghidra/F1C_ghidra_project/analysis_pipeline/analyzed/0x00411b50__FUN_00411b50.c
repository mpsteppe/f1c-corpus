// Function: FUN_00411b50 @ 00411b50
// Size (bytes): 151


undefined4 FUN_00411b50(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = -1;
  if (param_1 == 0x2693) {
    if (param_4 == 0x18d) {
      iVar2 = 0x2d;
    }
    else {
      if (param_4 != 0x1aa) {
        return 1;
      }
      iVar2 = 0x2e;
    }
    goto LAB_00411bc8;
  }
  if (param_1 == 0x2694) {
    if (param_4 == 1) {
      iVar2 = 0x2a;
    }
    else {
      if (param_4 != 2) {
        return 1;
      }
      iVar2 = 0x2b;
    }
    goto LAB_00411bc8;
  }
  if (param_2 == 0) {
    puVar1 = &DAT_005bee08;
LAB_00411bbd:
    iVar2 = *(int *)(puVar1 + param_1 * 4);
  }
  else if (param_2 == 1) {
    puVar1 = &DAT_005bf4c0;
    goto LAB_00411bbd;
  }
  if (param_1 < 0) {
    return 1;
  }
  if (iVar2 < 0) {
    return 1;
  }
LAB_00411bc8:
  FUN_00566650(&DAT_005ea438);
  *(int *)(param_3 + 8) = param_1;
  *(int *)(param_3 + 0xc) = iVar2;
  return 0;
}


