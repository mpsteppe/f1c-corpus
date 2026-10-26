// Function: FUN_004530a0 @ 004530a0
// Size (bytes): 83


void FUN_004530a0(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    FUN_004527e0(param_1[1],param_2);
  }
  else if (*param_1 == 1) {
    iVar1 = FUN_00452b10(param_1[1],param_2 == 2);
    if (iVar1 != 0) {
      FUN_00452810(param_1[1]);
      return;
    }
  }
  return;
}


