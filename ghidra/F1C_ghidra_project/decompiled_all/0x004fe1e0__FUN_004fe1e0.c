// Function: FUN_004fe1e0 @ 004fe1e0
// Strings:  [Monsoon, Soaked]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004fe1e0(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_00588410(param_1,&PTR_DAT_005c6e98);
  if (iVar1 == 0) {
    return (float10)DAT_0059e440;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6fb4);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e7f8;
  }
  iVar1 = FUN_00588410(param_1,&PTR_DAT_005c7234);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e450;
  }
  iVar1 = FUN_00588410(param_1,s_Soaked_005d6fac);
  if (iVar1 != 0) {
    iVar1 = FUN_00588410(param_1,s_Monsoon_005c6e7c);
    if (iVar1 != 0) {
      fVar2 = (float10)FUN_0058850f(param_1);
      fVar2 = fVar2 * (float10)_DAT_0059e444;
      if (fVar2 < (float10)DAT_0059e440) {
        return (float10)DAT_0059e440;
      }
      if (fVar2 <= (float10)_DAT_0059e43c) {
        return fVar2;
      }
    }
    return (float10)_DAT_0059e43c;
  }
  return (float10)_DAT_0059e7fc;
}


