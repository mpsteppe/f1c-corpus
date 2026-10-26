// Function: FUN_0047f300 @ 0047f300
// Size (bytes): 100


void FUN_0047f300(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  
  iVar3 = DAT_008ac488;
  iVar7 = 0;
  if (0 < DAT_008ac488) {
    iVar8 = 0;
    do {
      pcVar1 = (char *)(iVar8 + 4 + DAT_008ac490);
      uVar6 = 0xffffffff;
      pcVar9 = pcVar1;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      if (0 < (int)(~uVar6 - 1)) {
        puVar4 = DAT_007ce5d0;
        if (DAT_007ce5d0 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        iVar5 = FUN_00596c80(pcVar1,puVar4,~uVar6 - 1);
        if (iVar5 == 0) {
          return;
        }
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x18c;
    } while (iVar7 < iVar3);
  }
  FUN_004c54f0(0);
  return;
}


