// Function: FUN_00534ee0 @ 00534ee0
// Size (bytes): 174


int __fastcall FUN_00534ee0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x50) != 0) {
      FUN_0058aa6f(*(int *)(param_1 + 0x50));
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (*(char *)(param_1 + 0x5c) == 'w') {
        iVar3 = FUN_005361d0();
      }
      else if (*(char *)(param_1 + 0x5c) == 'r') {
        iVar3 = FUN_00535660();
      }
    }
    if (((*(int *)(param_1 + 0x40) != 0) &&
        (iVar1 = FUN_00587d02(*(int *)(param_1 + 0x40)), iVar1 != 0)) &&
       (piVar2 = (int *)FUN_0058afcf(), *piVar2 != 0x1d)) {
      iVar3 = -1;
    }
    if (*(int *)(param_1 + 0x38) < 0) {
      iVar3 = *(int *)(param_1 + 0x38);
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0058aa6f(*(int *)(param_1 + 0x44));
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      FUN_0058aa6f(*(int *)(param_1 + 0x48));
    }
    if (*(int *)(param_1 + 0x54) != 0) {
      FUN_0058aa6f(*(int *)(param_1 + 0x54));
    }
    FUN_0058aa6f(param_1);
    return iVar3;
  }
  return -2;
}


