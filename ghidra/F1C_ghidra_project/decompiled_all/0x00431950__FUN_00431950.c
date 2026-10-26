// Function: FUN_00431950 @ 00431950
// Strings:  [%d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00431950(int param_1,float param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int local_4;
  
  param_2 = param_2 - (float)_DAT_0059eac8;
  if (*(int *)(param_1 + 4) == 1) {
    puVar1 = &DAT_005c3738;
    param_2 = (param_2 - (float)_DAT_0059eac0) * (float)_DAT_0059eab8 - (float)_DAT_0059eab0;
  }
  else {
    puVar1 = &DAT_005c3734;
  }
  local_4 = (int)ROUND(param_2);
  FUN_0058815f(param_3,s__d__s_005c3778,local_4,puVar1);
  return;
}


