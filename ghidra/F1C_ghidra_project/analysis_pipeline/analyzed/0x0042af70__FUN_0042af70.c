// Function: FUN_0042af70 @ 0042af70
// Size (bytes): 364


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0042af70(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = FUN_004f1c20();
  if (cVar3 != '\0') {
    return 0;
  }
  if ((float)param_1[0x1143] <= (float)param_2[0x1131]) {
    iVar1 = param_2[0x1131];
  }
  else {
    iVar1 = param_1[0x1143];
  }
  param_1[0x1143] = iVar1;
  if (DAT_007c56a4 == 7) {
    iVar1 = *param_2;
    if (*(int *)(iVar1 + 0x403c) <= param_1[0x100f]) {
      if ((int *)param_1[0x117e] != param_2) {
        return 0;
      }
      iVar2 = *param_1;
      iVar4 = 0;
      if ((*(int *)(iVar1 + 0x48a8) < *(int *)(iVar2 + 0x48a8)) && (3 < param_1[0x100f])) {
        iVar4 = param_3;
      }
      if ((((*(int *)(iVar2 + 0xcd4) == 0) || (*(char *)(iVar2 + 0xd14) != '\0')) &&
          ((*(int *)(iVar2 + 0xd18) == 0 || (*(char *)(iVar2 + 0xd58) != '\0')))) ||
         ((((*(int *)(iVar1 + 0xcd4) != 0 && (*(char *)(iVar1 + 0xd14) == '\0')) ||
           (*(int *)(iVar1 + 0xd18) == 0)) || (*(char *)(iVar1 + 0xd58) != '\0'))))
      goto LAB_0042b08b;
    }
  }
  else if (DAT_007c56a4 == 5) {
    cVar3 = FUN_0042ae60();
    if (cVar3 != '\0') {
      return 0;
    }
    cVar3 = FUN_0042ae60();
    if (cVar3 == '\0') {
      return 0;
    }
  }
  else if ((float)param_1[0x1027] <= (float)param_2[0x1027]) {
    return 0;
  }
  iVar4 = param_3;
LAB_0042b08b:
  if (((iVar4 != 0) && (param_1[0xf5b] != 2)) &&
     ((float)param_1[0xe61] < _DAT_0059e600 == ((float)param_1[0xe61] == _DAT_0059e600))) {
    param_1[0x117f] = (int)param_2;
    if (param_3 == 2) {
      param_1[0x1108] = 0x40400000;
      return iVar4;
    }
    param_1[0x1108] = -0x3fc00000;
  }
  return iVar4;
}


