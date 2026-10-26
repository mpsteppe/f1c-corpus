// Function: FUN_00502ee5 @ 00502ee5
// Size (bytes): 76


undefined4 * __thiscall FUN_00502ee5(undefined4 *param_1,byte param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 & 2) == 0) {
    FUN_00587bcf(*param_1);
    puVar1 = param_1;
    if ((param_2 & 1) != 0) {
      FUN_00587bcf(param_1);
    }
  }
  else {
    puVar1 = param_1 + -1;
    FUN_0058a5f7(param_1,0xc,*puVar1,&LAB_00502c1f);
    if ((param_2 & 1) != 0) {
      FUN_00587bcf(puVar1);
    }
  }
  return puVar1;
}


