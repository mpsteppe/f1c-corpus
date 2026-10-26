// Function: FUN_0048b560 @ 0048b560
// Size (bytes): 148


undefined4 __thiscall FUN_0048b560(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_00589c49(param_2);
  if (iVar2 != 0) {
    if (*(int *)(param_1 + 0x2e8) != 1) {
      if (*(int *)(param_1 + 0x2e8) != 2) {
        return 1;
      }
      iVar2 = FUN_00589b9e(param_2);
      if ((((iVar2 == 0) && (iVar2 = FUN_00589b70(param_2), iVar2 == 0)) && (param_2 != '.')) &&
         (param_2 != ':')) {
        return 0;
      }
      return 1;
    }
    if (((param_2 != '\\') && (param_2 != '/')) && ((param_2 != ':' && (param_2 != '.')))) {
      if (param_2 == ' ') {
        iVar2 = -1;
        pcVar3 = *(char **)(param_1 + 0x2f0);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (iVar2 == -2) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}


