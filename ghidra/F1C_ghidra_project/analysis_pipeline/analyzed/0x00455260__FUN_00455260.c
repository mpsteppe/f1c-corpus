// Function: FUN_00455260 @ 00455260
// Size (bytes): 43


undefined4 FUN_00455260(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = FUN_00455200();
    return uVar1;
  }
  if (*param_1 != 1) {
    return 0;
  }
  uVar1 = FUN_00455240();
  return uVar1;
}


