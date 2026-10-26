// Function: FUN_0041ff10 @ 0041ff10
// Size (bytes): 234


undefined4 FUN_0041ff10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 local_50 [80];
  
  iVar1 = FUN_004c2990();
  uVar5 = 0x50;
  puVar4 = local_50;
  FUN_004c2850(puVar4,0x50);
  FUN_004c1390();
  FUN_004c0a20(puVar4,uVar5);
  iVar2 = FUN_00566810();
  if (iVar2 != 0) {
    FUN_004c2850();
    iVar2 = FUN_004c1390();
    if (*(int *)(iVar2 + 0xd4 + iVar1 * 4) == 10) {
      return 1;
    }
  }
  iVar3 = 0;
  FUN_004c2850();
  iVar2 = FUN_004c1370();
  if (0 < iVar2) {
    do {
      uVar5 = 0x50;
      puVar4 = local_50;
      iVar2 = iVar3;
      FUN_004c2850(iVar3,puVar4,0x50);
      FUN_004c13a0(iVar2);
      FUN_004c0a20(puVar4,uVar5);
      iVar2 = FUN_00566810();
      if (iVar2 != 0) {
        iVar2 = iVar3;
        FUN_004c2850(iVar3);
        iVar2 = FUN_004c13a0(iVar2);
        if (*(int *)(iVar2 + 0xd4 + iVar1 * 4) == 10) {
          return 1;
        }
      }
      iVar3 = iVar3 + 1;
      FUN_004c2850();
      iVar2 = FUN_004c1370();
    } while (iVar3 < iVar2);
  }
  return 0;
}


