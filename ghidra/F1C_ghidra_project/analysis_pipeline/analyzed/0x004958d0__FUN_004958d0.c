// Function: FUN_004958d0 @ 004958d0
// Size (bytes): 79


int FUN_004958d0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    for (iVar1 = FUN_00498e30(); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x48)) {
      iVar2 = FUN_00495920(iVar1);
      iVar4 = iVar4 + iVar2;
    }
    uVar3 = FUN_00498f60();
    iVar1 = FUN_00495930(uVar3);
    return iVar1 + iVar4;
  }
  return -1;
}


