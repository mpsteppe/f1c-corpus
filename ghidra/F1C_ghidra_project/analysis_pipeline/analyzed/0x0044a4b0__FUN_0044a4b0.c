// Function: FUN_0044a4b0 @ 0044a4b0
// Size (bytes): 587


int __thiscall FUN_0044a4b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28;
  int local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar2 = param_3;
  FUN_00566bd0(param_1,4);
  FUN_00566bd0(param_1 + 4,4);
  iVar1 = param_2;
  iVar4 = 0;
  iVar3 = param_2;
  if (param_2 != 0) {
    do {
      iVar3 = *(int *)(iVar3 + 0x1c);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
    if (2 < iVar4) {
      if (iVar4 < 0x65) {
        iVar3 = ((iVar4 < 0xb) - 1 & 0xfffffff7) + 0xf;
      }
      else {
        iVar3 = 3;
      }
      iVar3 = (int)(0xe / (longlong)iVar3);
      param_3 = 1;
      if (0 < iVar3) {
        param_3 = iVar3;
      }
      local_24 = -1;
      local_20 = 3.4028235e+38;
      for (iVar4 = iVar4 % param_3; iVar4 < 0xe; iVar4 = iVar4 + param_3) {
        FUN_0044a450(iVar4,&local_28,&param_2);
        FUN_0044a2d0(iVar1,*(undefined4 *)(iVar2 + 0x34),local_28,param_2,0);
        if (local_4 < local_20) {
          local_20 = local_4;
          local_24 = iVar4;
        }
      }
      FUN_0044a450(local_24,&local_28,&param_2);
      FUN_0044a2d0(iVar1,*(undefined4 *)(iVar2 + 0x34),local_28,param_2,1);
      if (local_24 < 8) {
        *(undefined2 *)(param_1 + 8) = 0;
        *(short *)(param_1 + 10) = (short)local_24;
      }
      else {
        *(undefined2 *)(param_1 + 8) = 1;
        *(short *)(param_1 + 10) = 0xe - (short)local_24;
      }
      local_2a = *(undefined1 *)(param_1 + 8);
      FUN_00566bd0(&local_2a,1);
      local_29 = *(undefined1 *)(param_1 + 10);
      FUN_00566bd0(&local_29,1);
      *(int *)(param_1 + 0xc) = *(int *)(iVar2 + 0x28) * 0x10 + *(int *)(iVar2 + 0x30);
      *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x28) + 2;
      **(undefined4 **)(param_1 + 0xc) = local_18;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = local_14;
      iVar3 = FUN_0044a4b0(local_1c,iVar2);
      if (iVar3 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = local_c;
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14) = local_8;
        iVar3 = FUN_0044a4b0(local_10,iVar2);
        return -(uint)(iVar3 != 0);
      }
      return -1;
    }
    if (iVar4 == 1) {
      *(undefined2 *)(param_1 + 8) = 0xffff;
    }
    else if (iVar4 == 2) {
      *(undefined2 *)(param_1 + 8) = 0xfffe;
    }
  }
  param_3 = CONCAT31(param_3._1_3_,*(undefined1 *)(param_1 + 8));
  FUN_00566bd0(&param_3,1);
  *(undefined2 *)(param_1 + 10) = 0xffff;
  *(int *)(param_1 + 0xc) = *(int *)(iVar2 + 0x1c) * 0x5c + *(int *)(iVar2 + 0x24);
  *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + iVar4;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    FUN_00449ed0(iVar1,iVar2);
  }
  return 0;
}


