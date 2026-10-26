// Function: FUN_004e2c70 @ 004e2c70
// Size (bytes): 44


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e2c70(int param_1)

{
  float10 fVar1;
  
  if (DAT_008ab6e4 == 2) {
    fVar1 = (float10)FUN_004b9ce0();
    *(float *)(param_1 + 0x984) = (float)fVar1;
    return;
  }
  *(float *)(param_1 + 0x984) = (float)_DAT_008afea0;
  return;
}


