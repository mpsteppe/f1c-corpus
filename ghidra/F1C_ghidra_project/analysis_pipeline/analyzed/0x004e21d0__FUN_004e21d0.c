// Function: FUN_004e21d0 @ 004e21d0
// Size (bytes): 89


void FUN_004e21d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = __ftol();
  iVar2 = FUN_0054e100();
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0054e120(iVar4);
      iVar4 = iVar4 + 1;
      *(int *)(iVar3 + 0x18) = iVar1 * 0x1000000 + 0xffffff;
    } while (iVar4 < iVar2);
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10000000;
  return;
}


