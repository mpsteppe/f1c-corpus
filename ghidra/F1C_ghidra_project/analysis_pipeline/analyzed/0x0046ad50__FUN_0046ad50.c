// Function: FUN_0046ad50 @ 0046ad50
// Size (bytes): 261


void FUN_0046ad50(int param_1,char *param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  pcVar2 = (char *)FUN_00455560(param_1);
  pcVar3 = (char *)FUN_00455260(&DAT_007d1b08 + param_1 * 7);
  if ((pcVar2 != (char *)0x0) && (param_2 != (char *)0x0)) {
    iVar4 = FUN_00423a00(pcVar2,&DAT_005ec4cc);
    if (iVar4 != 0) {
      iVar4 = (int)&DAT_005ec4cc - (int)pcVar2;
      do {
        cVar1 = *pcVar2;
        pcVar2[iVar4] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    pcVar2 = &DAT_005ec4cc;
    do {
      cVar1 = *pcVar2;
      (param_2 + -0x5ec4cc)[(int)pcVar2] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_004894d0(param_2);
    if (pcVar3 == (char *)0x0) {
      pcVar2 = &DAT_005ea438;
    }
    else {
      iVar4 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
      if (iVar4 != 0) {
        iVar4 = (int)&DAT_005ec4cc - (int)pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3[iVar4] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      pcVar2 = &DAT_005ec4cc;
    }
    uVar5 = 0xffffffff;
    do {
      pcVar3 = pcVar2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar3 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar3;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    pcVar2 = param_2;
    do {
      pcVar7 = pcVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    pcVar2 = pcVar3 + -uVar5;
    pcVar3 = pcVar7 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar3 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    if (param_3 != '\0') {
      FUN_00489600(param_2,0,0,0,0);
    }
  }
  return;
}


