// Function: FUN_0047bb40 @ 0047bb40
// Size (bytes): 236


void __thiscall FUN_0047bb40(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar1 = iVar1 + param_1[0x46] / 2 + param_1[0x44];
  if (param_2 < iVar1) {
    FUN_0047bae0(-param_1[0x3c]);
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (param_2 < iVar1 + param_1[0x46] / 2 + param_1[0x44]) {
      return;
    }
  }
  else {
    if (param_2 <= iVar1) {
      return;
    }
    FUN_0047bae0(param_1[0x3c]);
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (iVar1 + param_1[0x46] / 2 + param_1[0x44] < param_2) {
      return;
    }
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar1 = (param_2 - param_1[0x46] / 2) - iVar1;
  param_1[0x44] = iVar1;
  if (-1 < iVar1) {
    if (param_1[0x45] < iVar1) {
      param_1[0x44] = param_1[0x45];
    }
    FUN_0047be00();
    return;
  }
  param_1[0x44] = 0;
  FUN_0047be00();
  return;
}


