// Function: FUN_0042f180 @ 0042f180
// Strings:  [%d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f180(int param_1,double *param_2)

{
  double local_8;
  
  local_8 = ((double)*(int *)((int)param_2 + 0x14) * param_2[1] + *param_2) * _DAT_0059ea08;
  if (*(int *)(param_1 + 4) == 1) {
    local_8 = local_8 * _DAT_0059ea00;
  }
  FUN_0058815f((int)param_2 + 0x1e,s__d__s_005c3778,(int)ROUND(local_8),param_1 + 0x38);
  return;
}


