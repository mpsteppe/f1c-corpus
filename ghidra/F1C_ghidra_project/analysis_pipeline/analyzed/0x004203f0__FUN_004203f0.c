// Function: FUN_004203f0 @ 004203f0
// Size (bytes): 150


void FUN_004203f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_0041e920();
  if (iVar2 != 0) {
    iVar3 = FUN_0041e920();
    iVar1 = *(int *)(iVar2 + 0x198);
    iVar2 = *(int *)(iVar3 + 0x198);
    FUN_004c2850();
    iVar3 = FUN_004c11d0();
    FUN_004c2850();
    iVar4 = FUN_004c1190();
    iVar2 = iVar2 + (iVar4 - iVar3) * 10;
    if ((iVar1 <= iVar2) &&
       ((((iVar2 < iVar1 + 1 || (iVar2 < iVar1 + 2)) || (iVar2 < iVar1 + 3)) ||
        ((iVar2 < iVar1 + 4 || (iVar2 < iVar1 + 6)))))) {
      FUN_004144d0();
    }
  }
  return;
}


