// Function: FUN_0048e860 @ 0048e860
// Size (bytes): 34


void __fastcall FUN_0048e860(int *param_1)

{
  if (param_1[0x3a] == 0) {
    FUN_00496e40();
                    /* WARNING: Could not recover jumptable at 0x0048e87a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xa0))();
    return;
  }
  return;
}


