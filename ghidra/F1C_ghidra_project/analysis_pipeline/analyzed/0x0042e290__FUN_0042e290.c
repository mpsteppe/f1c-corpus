// Function: FUN_0042e290 @ 0042e290
// Size (bytes): 140


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042e290(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((double)CONCAT44(param_3,param_2) < _DAT_0059e880) {
    *(int *)(param_1 + 0x14) =
         (int)ROUND(((double)CONCAT44(param_3,param_2) + (double)CONCAT44(param_3,param_2)) *
                    (double)*(int *)(param_1 + 0x18));
  }
  else {
    *(int *)(param_1 + 0x14) =
         *(int *)(param_1 + 0x18) +
         (int)ROUND((((double)CONCAT44(param_3,param_2) + (double)CONCAT44(param_3,param_2)) -
                    _DAT_0059e420) *
                    (double)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x18)) + -1));
  }
  iVar1 = *(int *)(param_1 + 0x10) + -1;
  if (*(int *)(param_1 + 0x14) < 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    return;
  }
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return;
}


