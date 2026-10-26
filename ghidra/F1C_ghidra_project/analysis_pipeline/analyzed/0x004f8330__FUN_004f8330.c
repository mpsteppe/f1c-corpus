// Function: FUN_004f8330 @ 004f8330
// Size (bytes): 55


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f8330(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0x84);
  if (DAT_0059e440 < fVar1) {
    *(float *)(param_1 + 0x88) = _DAT_0059e43c / fVar1;
    return;
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}


