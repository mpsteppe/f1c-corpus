// Function: FUN_00567d00 @ 00567d00
// Size (bytes): 170


int FUN_00567d00(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  if (param_1 == (char *)0x0) {
    return -1;
  }
  uVar4 = 0xffffffff;
  iVar6 = 0;
  pcVar7 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  if (0 < iVar5) {
    iVar6 = FUN_00589a35((int)*param_1);
    iVar2 = FUN_00589a35((int)param_1[iVar5 / 6]);
    iVar5 = FUN_00589a35((int)param_1[iVar5 / 2]);
    iVar3 = FUN_00589a35((int)param_1[~uVar4 - 2]);
    iVar6 = (iVar3 * 0x2771 + iVar5 * 0x3b1 + iVar6 + iVar2 * 10 + iVar2) % 9;
  }
  return iVar6;
}


