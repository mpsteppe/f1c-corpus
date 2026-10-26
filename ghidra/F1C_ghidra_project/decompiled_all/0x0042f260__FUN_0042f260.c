// Function: FUN_0042f260 @ 0042f260
// Strings:  [%.1f %s, %.3f %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f260(int param_1,double *param_2,double param_3)

{
  double dVar1;
  
  dVar1 = (double)*(int *)((int)param_2 + 0x14) * param_2[1] + *param_2;
  if (param_3 != _DAT_0059e430) {
    dVar1 = ((double)*(int *)(param_1 + 0xc84) * *(double *)(param_1 + 0xc78) +
            *(double *)(param_1 + 0xc70)) * *(double *)(param_1 + 0x199c) * param_3 + dVar1;
  }
  if (*(int *)(param_1 + 4) == 0) {
    FUN_0058815f((int)param_2 + 0x1e,s___1f__s_005c36f4,dVar1 * _DAT_0059ea20,param_1 + 0x18);
    return;
  }
  FUN_0058815f((int)param_2 + 0x1e,s___3f__s_005c3780,dVar1 * _DAT_0059ea20 * _DAT_0059ea18,
               param_1 + 0x18);
  return;
}


