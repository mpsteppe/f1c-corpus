// Function: FUN_0045be00 @ 0045be00
// Size (bytes): 61


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0045be00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0045bb00();
  if (iVar1 < param_1) {
    return (float10)param_1 * (float10)_DAT_0059f078;
  }
  iVar1 = FUN_0045bb00();
  return (float10)iVar1 * (float10)_DAT_0059f078;
}


