// Function: FUN_0042f1e0 @ 0042f1e0
// Strings:  [%.1f %s, %d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f1e0(int param_1,double *param_2)

{
  double dVar1;
  
  dVar1 = (double)*(int *)((int)param_2 + 0x14) * param_2[1] + *param_2;
  if (*(int *)(param_1 + 4) == 0) {
    FUN_0058815f((int)param_2 + 0x1e,s__d__s_005c3778,(int)ROUND(dVar1),param_1 + 0x48);
    return;
  }
  FUN_0058815f((int)param_2 + 0x1e,s___1f__s_005c36f4,dVar1 * _DAT_0059ea10,param_1 + 0x48);
  return;
}


