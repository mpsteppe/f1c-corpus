// Function: FUN_0042dd80 @ 0042dd80
// Size (bytes): 76


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0042dd80(int param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 8))) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + param_2 * 8);
    if ((0 < iVar1) && (0 < *(int *)(param_1 + 0x10))) {
      return (float10)(*(int *)(*(int *)(param_1 + 0xc) + param_2 * 8 + 4) *
                      *(int *)(param_1 + 0x14)) / (float10)(*(int *)(param_1 + 0x10) * iVar1);
    }
  }
  return (float10)_DAT_0059e430;
}


