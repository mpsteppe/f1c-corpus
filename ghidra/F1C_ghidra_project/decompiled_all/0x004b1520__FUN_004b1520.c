// Function: FUN_004b1520 @ 004b1520
// Strings:  [Game Filter]


void __thiscall FUN_004b1520(int param_1,int param_2,char *param_3,uint param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar2 = *(char **)(param_2 * 0x1c + 0x28c4 + param_1);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  _strncpy(param_3,pcVar2,param_4 - 1);
  param_3[param_4 - 1] = '\0';
  pcVar2 = (char *)FUN_005681f0(s_Game_Filter_005c7130);
  if (pcVar2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar6 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar6 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 + (~uVar4 - 1) < param_4) {
      iVar5 = -1;
      pcVar6 = param_3;
      do {
        pcVar7 = pcVar6;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar3 = 0xffffffff;
      *(undefined2 *)(pcVar7 + -1) = DAT_005c32d8;
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
  }
  return;
}


