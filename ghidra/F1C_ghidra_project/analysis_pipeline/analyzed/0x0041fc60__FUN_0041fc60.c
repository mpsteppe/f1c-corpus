// Function: FUN_0041fc60 @ 0041fc60
// Size (bytes): 335


undefined4 FUN_0041fc60(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 local_50 [80];
  
  uVar6 = 0x50;
  puVar5 = local_50;
  FUN_004c2850(puVar5,0x50);
  FUN_004c1390();
  FUN_004c0a20(puVar5,uVar6);
  iVar1 = FUN_00566810();
  if (iVar1 != 0) {
    iVar4 = 0;
    FUN_004c2850();
    iVar1 = FUN_004c11d0();
    if (0 < iVar1) {
      iVar1 = 0xd8;
      do {
        FUN_004c2850();
        iVar2 = FUN_004c1390();
        if (*(int *)(iVar1 + iVar2) == 10) {
          return 1;
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + 4;
        FUN_004c2850();
        iVar2 = FUN_004c11d0();
      } while (iVar4 < iVar2);
    }
  }
  iVar4 = 0;
  FUN_004c2850();
  iVar1 = FUN_004c1370();
  if (0 < iVar1) {
    do {
      uVar6 = 0x50;
      puVar5 = local_50;
      iVar1 = iVar4;
      FUN_004c2850(iVar4,puVar5,0x50);
      FUN_004c13a0(iVar1);
      FUN_004c0a20(puVar5,uVar6);
      iVar1 = FUN_00566810();
      if (iVar1 != 0) {
        iVar2 = 0;
        FUN_004c2850();
        iVar1 = FUN_004c11d0();
        if (0 < iVar1) {
          iVar1 = 0xd8;
          do {
            iVar3 = iVar4;
            FUN_004c2850(iVar4);
            iVar3 = FUN_004c13a0(iVar3);
            if (*(int *)(iVar1 + iVar3) == 10) {
              return 1;
            }
            iVar2 = iVar2 + 1;
            iVar1 = iVar1 + 4;
            FUN_004c2850();
            iVar3 = FUN_004c11d0();
          } while (iVar2 < iVar3);
        }
      }
      iVar4 = iVar4 + 1;
      FUN_004c2850();
      iVar1 = FUN_004c1370();
    } while (iVar4 < iVar1);
  }
  return 0;
}


