// Function: FUN_004c3fe0 @ 004c3fe0
// Size (bytes): 150


void FUN_004c3fe0(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar7 = 0;
  if (0 < DAT_008ac390) {
    iVar8 = 0;
    do {
      pcVar6 = *(char **)(iVar8 + DAT_008ac394);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = &DAT_005ea438;
      }
      uVar4 = 0xffffffff;
      pcVar5 = pcVar6;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      for (pcVar5 = pcVar6 + (~uVar4 - 1); pcVar6 < pcVar5; pcVar5 = pcVar5 + -1) {
        if (*pcVar5 == '\\') {
          pcVar5 = pcVar5 + 1;
          break;
        }
      }
      iVar2 = FUN_00596c80(pcVar5,param_1,~uVar3 - 1);
      if (iVar2 == 0) {
        DAT_008ac38c = iVar7;
        return;
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x424;
    } while (iVar7 < DAT_008ac390);
  }
  DAT_008ac38c = 0;
  return;
}


