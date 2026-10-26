// Function: FUN_00466160 @ 00466160
// Size (bytes): 69


undefined4 __fastcall FUN_00466160(int param_1)

{
  float10 fVar1;
  
  FUN_0048e6a0();
  *(float *)(param_1 + 0x11c) =
       SQRT(*(float *)(param_1 + 0xf8) * *(float *)(param_1 + 0xf8) -
            *(float *)(param_1 + 0x118) * *(float *)(param_1 + 0x118));
  fVar1 = (float10)FUN_00588570();
  *(float *)(param_1 + 0x120) = (float)fVar1;
  return 0;
}


