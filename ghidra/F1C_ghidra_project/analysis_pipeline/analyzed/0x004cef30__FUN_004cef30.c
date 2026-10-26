// Function: FUN_004cef30 @ 004cef30
// Size (bytes): 106


void FUN_004cef30(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_40 [64];
  
  iVar1 = FUN_00545f40();
  if ((iVar1 != 0) && (iVar3 = 0, 0 < *(int *)(iVar1 + 0x10))) {
    do {
      FUN_00548850(iVar3);
      FUN_00547370(local_40);
      uVar2 = FUN_004ce860(local_40);
      uVar2 = FUN_004ce8d0(uVar2);
      FUN_00547280(uVar2,0x1000);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x10));
  }
  return;
}


