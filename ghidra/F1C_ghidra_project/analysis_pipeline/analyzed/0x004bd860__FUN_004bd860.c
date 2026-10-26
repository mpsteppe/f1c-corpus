// Function: FUN_004bd860 @ 004bd860
// Size (bytes): 96


void __thiscall FUN_004bd860(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (param_1[1] == *param_1) {
    iVar1 = *param_1 + 8;
    *param_1 = iVar1;
    pvVar2 = operator_new(iVar1 * 4);
    iVar1 = 0;
    if (0 < param_1[1]) {
      do {
        *(undefined4 *)((int)pvVar2 + iVar1 * 4) = *(undefined4 *)(param_1[2] + iVar1 * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[1]);
    }
    if (param_1[2] != 0) {
      FUN_00587bcf(param_1[2]);
    }
    param_1[2] = (int)pvVar2;
  }
  *(undefined4 *)(param_1[2] + param_1[1] * 4) = param_2;
  param_1[1] = param_1[1] + 1;
  return;
}


