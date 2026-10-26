// Function: FUN_0041f070 @ 0041f070
// Size (bytes): 132


uint __fastcall FUN_0041f070(int param_1)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  if (param_1 == 0) {
    return in_EAX & 0xffffff00;
  }
  iVar2 = 0;
  FUN_004c2850();
  iVar1 = FUN_004c1370();
  if (0 < iVar1) {
    do {
      iVar1 = iVar2;
      FUN_004c2850(iVar2);
      iVar1 = FUN_004c13a0(iVar1);
      if (param_1 != iVar1) {
        iVar1 = iVar2;
        FUN_004c2850(iVar2);
        iVar1 = FUN_004c13a0(iVar1);
        if (iVar3 < *(int *)(iVar1 + 0x198)) {
          iVar3 = *(int *)(iVar1 + 0x198);
        }
      }
      iVar2 = iVar2 + 1;
      FUN_004c2850();
      iVar1 = FUN_004c1370();
    } while (iVar2 < iVar1);
  }
  iVar3 = *(int *)(param_1 + 0x198) - iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),9 < iVar3);
}


