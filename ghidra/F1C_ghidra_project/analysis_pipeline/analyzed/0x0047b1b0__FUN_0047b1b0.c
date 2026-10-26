// Function: FUN_0047b1b0 @ 0047b1b0
// Size (bytes): 40


void __fastcall FUN_0047b1b0(int *param_1)

{
  param_1[0x41] = 0;
  (**(code **)(*param_1 + 0x40))(0);
  (**(code **)(*param_1 + 0x2c))(1);
                    /* WARNING: Could not recover jumptable at 0x0047b1d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x9c))();
  return;
}


