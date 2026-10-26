// Function: FUN_004bfcd0 @ 004bfcd0
// Size (bytes): 97


int __thiscall FUN_004bfcd0(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (param_2 < (int)param_1[3]) {
    if (param_2 < 0) {
      param_1[2] = 0;
    }
    else {
      param_1[2] = *param_1;
      while ((0 < param_2 && (param_1[2] != 0))) {
        param_2 = param_2 + -1;
        param_1[2] = *(undefined4 *)(param_1[2] + 4);
      }
    }
    if ((undefined4 *)param_1[2] == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)param_1[2];
    }
    if (*piVar2 < DAT_008ac390) {
      iVar1 = *piVar2 * 0x424 + DAT_008ac394;
    }
  }
  return iVar1;
}


