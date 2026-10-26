// Function: FUN_004b02b0 @ 004b02b0
// Size (bytes): 214


undefined4 __thiscall FUN_004b02b0(int param_1,char *param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    FUN_004b0220(param_2,param_3);
    pcVar5 = *(char **)(param_1 + 0x1f9c);
    if (pcVar5 == (char *)0x0) {
      pcVar5 = &DAT_005ea438;
    }
    uVar2 = 0xffffffff;
    pcVar7 = pcVar5;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar3 = 0xffffffff;
    pcVar7 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (~uVar2 + (~uVar3 - 2) < param_3) {
      uVar2 = 0xffffffff;
      do {
        pcVar7 = pcVar5;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar7 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar7;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      pcVar5 = param_2;
      do {
        pcVar6 = pcVar5;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
      } while (cVar1 != '\0');
      pcVar5 = pcVar7 + -uVar2;
      pcVar7 = pcVar6 + -1;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar7 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      }
      uVar2 = 0xffffffff;
      pcVar5 = param_2;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      for (pcVar5 = param_2 + (~uVar2 - 1); param_2 < pcVar5; pcVar5 = pcVar5 + -1) {
        if (*pcVar5 == '.') {
          *pcVar5 = '\0';
          break;
        }
      }
      uVar2 = 0xffffffff;
      pcVar5 = param_2;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (~uVar2 + 4 < param_3) {
        iVar4 = -1;
        do {
          pcVar5 = param_2;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar5 = param_2 + 1;
          cVar1 = *param_2;
          param_2 = pcVar5;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar5 + -1) = DAT_005d1fe8;
        pcVar5[3] = DAT_005d1fec;
        return 0;
      }
    }
  }
  *param_2 = '\0';
  return 0xffffffff;
}


