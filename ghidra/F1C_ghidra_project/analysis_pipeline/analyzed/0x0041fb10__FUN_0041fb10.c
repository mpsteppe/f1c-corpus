// Function: FUN_0041fb10 @ 0041fb10
// Size (bytes): 327


undefined4 FUN_0041fb10(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 local_50 [80];
  
  bVar1 = false;
  bVar2 = false;
  iVar3 = FUN_004c2990();
  uVar7 = 0x50;
  puVar6 = local_50;
  FUN_004c2850(puVar6,0x50);
  FUN_004c1390();
  FUN_004c0a20(puVar6,uVar7);
  iVar4 = FUN_00566810();
  if (iVar4 != 0) {
    FUN_004c2850();
    iVar4 = FUN_004c1390();
    if (*(int *)(iVar4 + 0xd4 + iVar3 * 4) == 10) {
      bVar1 = true;
    }
    else {
      FUN_004c2850();
      iVar4 = FUN_004c1390();
      if (*(int *)(iVar4 + 0xd4 + iVar3 * 4) == 6) {
        bVar2 = true;
      }
    }
  }
  iVar5 = 0;
  FUN_004c2850();
  iVar4 = FUN_004c1370();
  if (0 < iVar4) {
    do {
      uVar7 = 0x50;
      puVar6 = local_50;
      iVar4 = iVar5;
      FUN_004c2850(iVar5,puVar6,0x50);
      FUN_004c13a0(iVar4);
      FUN_004c0a20(puVar6,uVar7);
      iVar4 = FUN_00566810();
      if (iVar4 != 0) {
        iVar4 = iVar5;
        FUN_004c2850(iVar5);
        iVar4 = FUN_004c13a0(iVar4);
        if (*(int *)(iVar4 + 0xd4 + iVar3 * 4) == 10) {
          bVar1 = true;
        }
        iVar4 = iVar5;
        FUN_004c2850(iVar5);
        iVar4 = FUN_004c13a0(iVar4);
        if (*(int *)(iVar4 + 0xd4 + iVar3 * 4) == 6) {
          bVar2 = true;
        }
      }
      iVar5 = iVar5 + 1;
      FUN_004c2850();
      iVar4 = FUN_004c1370();
    } while (iVar5 < iVar4);
  }
  if (bVar1) {
    if (bVar2) {
      return 1;
    }
  }
  return 0;
}


