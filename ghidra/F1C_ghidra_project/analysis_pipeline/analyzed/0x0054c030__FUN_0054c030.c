// Function: FUN_0054c030 @ 0054c030
// Size (bytes): 124


void __thiscall FUN_0054c030(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  
  if (param_4 == 1) {
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0054c030(param_2,param_3,1,1);
    }
    if ((param_5 != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
      FUN_0054c030(param_2,param_3,1,1);
    }
  }
  if (param_2 == 1) {
    uVar1 = *(uint *)(param_1 + 0x3c) & 0xfffffffd;
  }
  else {
    if (param_2 != 0) goto LAB_0054c08a;
    uVar1 = *(uint *)(param_1 + 0x3c) | 6;
  }
  *(uint *)(param_1 + 0x3c) = uVar1;
LAB_0054c08a:
  if (param_3 == 1) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffffb;
    return;
  }
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 4;
  }
  return;
}


