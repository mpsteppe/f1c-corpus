// Function: FUN_004109d0 @ 004109d0
// Size (bytes): 244


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004109d0(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  
  if (DAT_008ab6e4 == 2) {
    iVar2 = 0;
    if (0 < DAT_005c329c) {
      do {
        FUN_004f0430(param_2);
        FUN_004ef180();
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_005c329c);
      return;
    }
  }
  else {
    iVar2 = 0;
    if (0 < *param_1) {
      do {
        FUN_0040f300(param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *param_1);
    }
    if ((DAT_008ab6e4 != 1) || (param_2 <= (float)param_1[0x1b] + _DAT_0059e43c)) {
      if (0 < *param_1) {
        iVar2 = 0;
        do {
          iVar1 = *(int *)(param_1[2] + iVar2 * 4);
          if ((*(int *)(iVar1 + 0x1c) != 6) && (*(char *)(iVar1 + 10) != '\0')) {
            FUN_0040f600();
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *param_1);
      }
    }
    else {
      iVar2 = 0;
      param_1[0x1b] = (int)param_2;
      if (0 < *param_1) {
        do {
          if (*(int *)(*(int *)(param_1[2] + iVar2 * 4) + 0x1c) != 6) {
            FUN_0040f600();
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *param_1);
        return;
      }
    }
  }
  return;
}


