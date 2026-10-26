// Function: FUN_00498f40 @ 00498f40
// Size (bytes): 24


void __thiscall FUN_00498f40(int *param_1,int param_2)

{
  if (param_2 != 0) {
    param_1[0x14] = param_2;
  }
                    /* WARNING: Could not recover jumptable at 0x00498f55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2c))();
  return;
}


