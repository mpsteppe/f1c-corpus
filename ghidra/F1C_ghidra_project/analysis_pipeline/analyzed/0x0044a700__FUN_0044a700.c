// Function: FUN_0044a700 @ 0044a700
// Size (bytes): 373


undefined4 __thiscall FUN_0044a700(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte local_5;
  int local_4;
  
  iVar4 = param_2;
  iVar2 = FUN_00566c00(param_1,4);
  if (iVar2 != 4) {
    return 0xffffffff;
  }
  iVar2 = FUN_00566c00(param_1 + 4,4);
  if (iVar2 != 4) {
    return 0xffffffff;
  }
  iVar2 = FUN_00566c00(&param_2,1);
  if (iVar2 != 1) {
    return 0xffffffff;
  }
  sVar1 = (short)(char)param_2;
  *(short *)(param_1 + 8) = sVar1;
  if ((-3 < sVar1) && (sVar1 < 2)) {
    iVar2 = 0;
    if (sVar1 < 0) {
      if (sVar1 == -1) {
        iVar5 = 1;
      }
      else {
        iVar5 = 2;
        if (sVar1 != -2) {
          iVar5 = param_2;
        }
      }
      *(int *)(param_1 + 0xc) = *(int *)(iVar4 + 0x1c) * 0x5c + *(int *)(iVar4 + 0x24);
      *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + iVar5;
      if (0 < iVar5) {
        local_4 = 0;
        do {
          iVar3 = FUN_00449f60(iVar4);
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          iVar2 = iVar2 + 1;
          local_4 = local_4 + 0x5c;
        } while (iVar2 < iVar5);
      }
    }
    else {
      iVar2 = FUN_00566c00(&local_5,1);
      if (iVar2 != 1) {
        return 0xffffffff;
      }
      *(ushort *)(param_1 + 10) = (ushort)local_5;
      *(int *)(param_1 + 0xc) = *(int *)(iVar4 + 0x28) * 0x10 + *(int *)(iVar4 + 0x30);
      *(int *)(iVar4 + 0x28) = *(int *)(iVar4 + 0x28) + 2;
      iVar2 = FUN_0044a700(iVar4);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      iVar4 = FUN_0044a700(iVar4);
      if (iVar4 != 0) {
        return 0xffffffff;
      }
    }
    return 0;
  }
  return 0xffffffff;
}


