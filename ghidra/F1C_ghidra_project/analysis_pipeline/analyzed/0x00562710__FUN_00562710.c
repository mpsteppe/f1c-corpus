// Function: FUN_00562710 @ 00562710
// Size (bytes): 284


void FUN_00562710(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  for (uVar3 = ~uVar3 + (~uVar4 - 2); 0x545 < uVar3; uVar3 = ~uVar3 + (~uVar4 - 2)) {
    uVar4 = 0;
    uVar3 = 0xffffffff;
    pcVar2 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 < 0x547) {
      FUN_00562610(param_1);
      iVar5 = (int)param_1 - (int)param_2;
      do {
        cVar1 = *param_2;
        param_2[iVar5] = cVar1;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      return;
    }
    iVar5 = 0;
    pcVar2 = param_2;
    pcVar6 = param_2;
    do {
      if (*pcVar2 == '\\') {
        uVar3 = uVar4 & 0x80000001;
        bVar7 = uVar3 == 0;
        if ((int)uVar3 < 0) {
          bVar7 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (bVar7) {
          pcVar6 = pcVar2;
        }
        uVar4 = uVar4 + 1;
      }
      pcVar2 = pcVar2 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x546);
    if (pcVar6 == param_2) {
      return;
    }
    *pcVar6 = '\0';
    FUN_00562710(param_1,param_2);
    uVar3 = 0xffffffff;
    *pcVar6 = '\\';
    pcVar2 = pcVar6;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    param_2 = pcVar6;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar2 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar5 = -1;
  do {
    pcVar6 = param_1;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar6 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar6;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + -uVar3;
  pcVar6 = pcVar6 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return;
}


