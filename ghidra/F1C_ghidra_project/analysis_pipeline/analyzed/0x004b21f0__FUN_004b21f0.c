// Function: FUN_004b21f0 @ 004b21f0
// Size (bytes): 278


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b21f0(int *param_1,float *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*param_2 <= _DAT_005acc8c) {
    if (_DAT_005acc88 <= *param_2) {
      iVar3 = (int)ROUND(*param_2 * _DAT_005acc84);
    }
    else {
      iVar3 = -0x7fffffff;
    }
  }
  else {
    iVar3 = 0x7fffffff;
  }
  if (param_2[1] <= _DAT_005acc8c) {
    if (_DAT_005acc88 <= param_2[1]) {
      uVar2 = (uint)ROUND(param_2[1] * _DAT_005acc84);
    }
    else {
      uVar2 = 0x80000001;
    }
  }
  else {
    uVar2 = 0x7fffffff;
  }
  if (param_2[2] <= _DAT_005acc8c) {
    if (_DAT_005acc88 <= param_2[2]) {
      uVar1 = (uint)ROUND(param_2[2] * _DAT_005acc84);
    }
    else {
      uVar1 = 0x80000001;
    }
  }
  else {
    uVar1 = 0x7fffffff;
  }
  *param_1 = (iVar3 >> 8 & 0xffffffU) + (uVar2 & 0xffffff00) * 0x10000;
  param_1[1] = ((int)uVar2 >> 0x10 & 0xffffU) + (uVar1 & 0xffffff00) * 0x100;
  *(char *)(param_1 + 2) = (char)(uVar1 >> 0x18);
  return;
}


