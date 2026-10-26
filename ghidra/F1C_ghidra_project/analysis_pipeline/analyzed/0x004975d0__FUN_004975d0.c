// Function: FUN_004975d0 @ 004975d0
// Size (bytes): 121


int __thiscall FUN_004975d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  *(int *)(param_2 + 0x40) = param_1;
  *(undefined4 *)(param_2 + 0x98) = 0;
  *(undefined4 *)(param_2 + 0x9c) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 0;
  if (param_3 != 0) {
    FUN_0049ad50(param_3);
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x8c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x8c)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x8c) = param_2;
    return param_2;
  }
  *(int *)(param_1 + 0x1c) = param_2;
  return param_2;
}


