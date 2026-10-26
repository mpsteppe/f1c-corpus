// Function: FUN_00498eb0 @ 00498eb0
// Size (bytes): 141


int __thiscall FUN_00498eb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  iVar1 = *(int *)(param_2 + 0x90);
  *(int *)(param_2 + 0x98) = param_1;
  *(undefined4 *)(param_2 + 0x9c) = 0;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x8c)) {
    *(int *)(iVar1 + 0x98) = param_1;
    *(undefined4 *)(iVar1 + 0x9c) = 0;
  }
  FUN_004869e0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4));
  iVar1 = *(int *)(param_1 + 0x4c);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x8c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x8c)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x8c) = param_2;
    return param_2;
  }
  *(int *)(param_1 + 0x4c) = param_2;
  return param_2;
}


