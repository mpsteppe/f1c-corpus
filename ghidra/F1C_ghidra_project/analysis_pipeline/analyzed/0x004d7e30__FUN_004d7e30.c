// Function: FUN_004d7e30 @ 004d7e30
// Size (bytes): 12


void __fastcall FUN_004d7e30(int *param_1)

{
  param_1[3] = 0;
                    /* WARNING: Could not recover jumptable at 0x004d7e39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


