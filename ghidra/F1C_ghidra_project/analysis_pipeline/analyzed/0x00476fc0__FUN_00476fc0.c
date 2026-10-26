// Function: FUN_00476fc0 @ 00476fc0
// Size (bytes): 185


void __thiscall FUN_00476fc0(int param_1,int param_2,char *param_3,uint param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar2 = (char *)(&DAT_007d0d5c)[param_2 * 7];
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  _strncpy(param_3,pcVar2,param_4 - 1);
  param_3[param_4 - 1] = '\0';
  pcVar2 = *(char **)(param_1 + 0x188);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  uVar3 = 0xffffffff;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffff;
  pcVar2 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (~uVar3 + (~uVar4 - 1) < param_4) {
    iVar5 = -1;
    pcVar2 = param_3;
    do {
      pcVar6 = pcVar2;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    *(undefined2 *)(pcVar6 + -1) = DAT_005c32d8;
    pcVar2 = *(char **)(param_1 + 0x188);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = &DAT_005ea438;
    }
    uVar3 = 0xffffffff;
    do {
      pcVar6 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar5 = -1;
    do {
      pcVar2 = param_3;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar2 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar2;
    } while (cVar1 != '\0');
    pcVar6 = pcVar6 + -uVar3;
    pcVar2 = pcVar2 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return;
}


