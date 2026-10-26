// Function: FUN_004141a0 @ 004141a0
// Size (bytes): 55


int FUN_004141a0(int param_1)

{
  int iVar1;
  
  iVar1 = -1;
  if ((-1 < param_1) && (param_1 < 2)) {
    if (param_1 == 0) {
      iVar1 = 1;
    }
    else if (param_1 == 1) {
      return DAT_005bf8d4;
    }
    iVar1 = (&DAT_005bf8c8)[iVar1];
  }
  return iVar1;
}


