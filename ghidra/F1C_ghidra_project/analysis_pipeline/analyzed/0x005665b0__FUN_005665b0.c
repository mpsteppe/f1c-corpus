// Function: FUN_005665b0 @ 005665b0
// Size (bytes): 157


void __thiscall FUN_005665b0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  
  if (param_2 != (char *)0x0) {
    if ((char *)*param_1 == (char *)0x0) {
      FUN_00566650(param_2);
      return;
    }
    uVar3 = 0xffffffff;
    pcVar5 = (char *)*param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar5 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar7 = ~uVar3 + (~uVar4 - 2);
    if ((int)param_1[1] < iVar7) {
      pcVar2 = operator_new(iVar7 + 1);
      pcVar5 = (char *)*param_1;
      pcVar6 = pcVar2;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00587bcf(*param_1);
      *param_1 = pcVar2;
      param_1[1] = iVar7;
    }
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar5;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar7 = -1;
    pcVar6 = (char *)*param_1;
    do {
      pcVar2 = pcVar6;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar2 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar2;
    } while (cVar1 != '\0');
    pcVar5 = pcVar5 + -uVar3;
    pcVar6 = pcVar2 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  return;
}


