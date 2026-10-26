// Function: FUN_004bfd90 @ 004bfd90
// Size (bytes): 465


undefined4 FUN_004bfd90(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char local_100 [255];
  undefined1 local_1;
  
  if (DAT_005c329c < 1) goto LAB_004bfef2;
  FUN_004bf630();
  cVar1 = FUN_0042bc10();
  if (cVar1 == '\0') {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ea438)[iVar2];
      local_100[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    pcVar6 = DAT_007ce64c;
    if (DAT_007ce64c == (char *)0x0) {
      pcVar6 = &DAT_005ea438;
    }
    _strncpy(local_100,pcVar6,0xff);
    local_1 = 0;
  }
  if (DAT_007d0410 == 1) {
    if (DAT_007d00c8 == 0) {
      uVar3 = FUN_004b3c60();
      DAT_005c329c = uVar3 % 3 + 3;
      FUN_0042bc80();
      goto LAB_004bfe4f;
    }
    DAT_005c329c = 1;
    FUN_0042bc80();
  }
  else {
LAB_004bfe4f:
    cVar1 = FUN_0042bc10();
    iVar2 = DAT_005c329c;
    if (cVar1 != '\0') {
      iVar2 = DAT_005c329c + -1;
    }
    iVar4 = FUN_004bf790(iVar2,local_100,param_1);
    if (iVar4 == iVar2) {
      cVar1 = FUN_0042bc10();
      uVar3 = (uint)(cVar1 != '\0');
      iVar2 = uVar3 + iVar2;
      if ((int)uVar3 < iVar2) {
        iVar4 = 0;
        do {
          FUN_004ef5a0(1,0);
          uVar5 = FUN_004bfd40(iVar4);
          FUN_004c78f0(uVar5);
          FUN_004c6960(uVar3);
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 1;
        } while ((int)uVar3 < iVar2);
      }
    }
  }
  FUN_004bf640();
LAB_004bfef2:
  pcVar6 = DAT_007ce64c;
  if (DAT_007ce64c == (char *)0x0) {
    pcVar6 = &DAT_005ea438;
  }
  FUN_004c3f80(pcVar6);
  FUN_004c78f0(DAT_008ac38c);
  FUN_004c6960(0);
  cVar1 = FUN_0042bc10();
  if (cVar1 == '\0') {
    FUN_004ef5a0(1,0);
    return 0;
  }
  FUN_004ef5a0(0,0);
  return 0;
}


