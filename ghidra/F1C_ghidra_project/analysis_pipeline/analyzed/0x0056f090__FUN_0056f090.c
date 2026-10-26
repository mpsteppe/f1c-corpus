// Function: FUN_0056f090 @ 0056f090
// Size (bytes): 99


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0056f090(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  float10 fVar2;
  double local_10;
  
  local_10 = _DAT_0059e420;
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      fVar2 = (float10)FUN_00569de0(param_2,param_3);
      if (fVar2 < (float10)local_10) {
        local_10 = (double)fVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return (float10)local_10;
}


