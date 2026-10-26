// Function: FUN_004fe2b0 @ 004fe2b0
// Strings:  [Medium]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004fe2b0(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_00588410(param_1,&PTR_DAT_005d6fd4);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad330;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6fcc);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad32c;
  }
  iVar1 = FUN_00588410(param_1,s_Medium_005c6eb8);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e8ec;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6fc4);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad328;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6fbc);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e8f4;
  }
  fVar2 = (float10)FUN_0058850f(param_1);
  return fVar2;
}


