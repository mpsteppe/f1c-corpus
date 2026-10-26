// Function: FUN_004e9bd0 @ 004e9bd0
// Size (bytes): 193


void __fastcall FUN_004e9bd0(int param_1)

{
  *(float *)(param_1 + 0x3b60) =
       *(float *)(param_1 + 0x3b54) * *(float *)(param_1 + 0x34b0) +
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3b58) +
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3b5c);
  *(float *)(param_1 + 0x3b64) =
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3b54) +
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3b58) +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3b5c);
  *(float *)(param_1 + 0x3b68) =
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3b54) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3b58) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3b5c);
  *(float *)(param_1 + 0x3b60) = *(float *)(param_1 + 0x34d4) + *(float *)(param_1 + 0x3b60);
  *(float *)(param_1 + 0x3b64) = *(float *)(param_1 + 0x34d8) + *(float *)(param_1 + 0x3b64);
  *(float *)(param_1 + 0x3b68) = *(float *)(param_1 + 0x34dc) + *(float *)(param_1 + 0x3b68);
  return;
}


