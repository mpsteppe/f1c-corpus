// Function: FUN_004fe0d0 @ 004fe0d0
// Strings:  [Monsoon, Overcast, Drizzle, Clear]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004fe0d0(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_00588410(param_1,&DAT_005d6fa4);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad324;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6f9c);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e8b4;
  }
  iVar1 = FUN_00588410(param_1,s_Clear_005d6f94);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e4e8;
  }
  iVar1 = FUN_00588410(param_1,s_Overcast_005c6e8c);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e8f8;
  }
  iVar1 = FUN_00588410(param_1,s_Drizzle_005d6f8c);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad320;
  }
  iVar1 = FUN_00588410(param_1,&DAT_005d6f84);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e908;
  }
  iVar1 = FUN_00588410(param_1,s_Monsoon_005c6e7c);
  if (iVar1 == 0) {
    return (float10)_DAT_005ad31c;
  }
  fVar2 = (float10)FUN_0058850f(param_1);
  fVar2 = fVar2 * (float10)_DAT_0059e444;
  if (fVar2 < (float10)DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  if ((float10)_DAT_0059e43c < fVar2) {
    fVar2 = (float10)_DAT_0059e43c;
  }
  return fVar2;
}


