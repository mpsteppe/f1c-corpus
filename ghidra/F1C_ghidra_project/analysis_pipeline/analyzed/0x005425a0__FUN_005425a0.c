// Function: FUN_005425a0 @ 005425a0
// Size (bytes): 171


void __thiscall FUN_005425a0(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_c [12];
  
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,param_2,local_c,param_1 + 0x15c);
  iVar1 = __ftol();
  *param_3 = iVar1;
  iVar1 = __ftol();
  param_3[1] = iVar1;
  iVar1 = *param_3;
  if (*param_3 <= *(int *)(param_1 + 0x68)) {
    iVar1 = *(int *)(param_1 + 0x68);
  }
  *param_3 = iVar1;
  iVar2 = *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x68);
  if (iVar2 <= iVar1) {
    iVar1 = iVar2;
  }
  *param_3 = iVar1;
  iVar1 = param_3[1];
  if (param_3[1] <= *(int *)(param_1 + 100)) {
    iVar1 = *(int *)(param_1 + 100);
  }
  param_3[1] = iVar1;
  iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 100);
  if (iVar1 < iVar2) {
    param_3[1] = iVar1;
    return;
  }
  param_3[1] = iVar2;
  return;
}


