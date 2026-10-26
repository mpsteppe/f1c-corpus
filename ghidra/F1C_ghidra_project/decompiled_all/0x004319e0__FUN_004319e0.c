// Function: FUN_004319e0 @ 004319e0
// Strings:  [%.3f %s, %.2f %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004319e0(int param_1,int param_2,undefined4 param_3)

{
  double dVar1;
  
  dVar1 = (double)(*(float *)(param_1 + 0x1cd8 + param_2 * 4) * (float)_DAT_0059ea20);
  if (*(int *)(param_1 + 4) == 1) {
    FUN_0058815f(param_3,s___2f__s_005c3820,dVar1,param_1 + 0x18);
    return;
  }
  FUN_0058815f(param_3,s___3f__s_005c3780,dVar1 * _DAT_0059ea18,param_1 + 0x18);
  return;
}


