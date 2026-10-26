// Function: FUN_0042dd00 @ 0042dd00
// Size (bytes): 114


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0042dd00(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((((-1 < param_2) && (param_2 < *param_1)) && (-1 < param_3)) && (param_3 < param_1[2])) {
    iVar1 = *(int *)(param_1[1] + param_2 * 8);
    if (0 < iVar1) {
      iVar2 = *(int *)(param_1[3] + param_3 * 8);
      if ((0 < iVar2) && (0 < param_1[4])) {
        return (float10)(*(int *)(param_1[3] + param_3 * 8 + 4) *
                         *(int *)(param_1[1] + param_2 * 8 + 4) * param_1[5]) /
               (float10)(param_1[4] * iVar2 * iVar1);
      }
    }
  }
  return (float10)_DAT_0059e430;
}


