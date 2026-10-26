// Function: FUN_00490160 @ 00490160
// Size (bytes): 43


void __thiscall FUN_00490160(int *param_1,char param_2)

{
  if (param_2 == '\0') {
    param_1[0x38] = 1;
  }
  else {
    param_1[0x38] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00490188. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2c))();
  return;
}


