// Function: FUN_00418970 @ 00418970
// Size (bytes): 60


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00418970(int param_1,float param_2)

{
  if (((*(int **)(param_1 + 0xaf4) != (int *)0x0) && (DAT_0059e440 <= param_2)) &&
     (param_2 < _DAT_0059e43c != (param_2 == _DAT_0059e43c))) {
                    /* WARNING: Could not recover jumptable at 0x004189a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0xaf4) + 0x1c))();
    return;
  }
  return;
}


