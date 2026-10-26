// Function: FUN_004e58d0 @ 004e58d0
// Size (bytes): 516


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e58d0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *(float *)(param_1 + 0x3514) * (float)_DAT_0059ed50;
  fVar4 = *(float *)(param_1 + 0x34b0) * DAT_0059e440 +
          *(float *)(param_1 + 0x34c8) * DAT_0059e440 + fVar1 * *(float *)(param_1 + 0x34bc);
  fVar5 = *(float *)(param_1 + 0x34b4) * DAT_0059e440 +
          *(float *)(param_1 + 0x34cc) * DAT_0059e440 + fVar1 * *(float *)(param_1 + 0x34c0);
  fVar6 = *(float *)(param_1 + 0x34b8) * DAT_0059e440 +
          *(float *)(param_1 + 0x34d0) * DAT_0059e440 + fVar1 * *(float *)(param_1 + 0x34c4);
  fVar1 = *(float *)(param_1 + 0x34f8) -
          (*(float *)(param_1 + 0x3a58) * *(float *)(param_1 + 0x34b0) +
          *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3a5c) +
          *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3a60));
  fVar2 = *(float *)(param_1 + 0x34fc) -
          (*(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3a58) +
          *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3a5c) +
          *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3a60));
  fVar3 = *(float *)(param_1 + 0x3500) -
          (*(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3a58) +
          *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3a5c) +
          *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3a60));
  fVar3 = fVar3 * fVar3;
  fVar1 = fVar1 * fVar1 * *(float *)(param_1 + 0x3a64);
  if (DAT_0059e440 <= *(float *)(param_1 + 0x34f8)) {
    fVar4 = fVar4 - fVar1;
  }
  else {
    fVar4 = fVar1 + fVar4;
  }
  fVar1 = fVar2 * fVar2 * *(float *)(param_1 + 0x3a68);
  if (DAT_0059e440 <= *(float *)(param_1 + 0x34fc)) {
    fVar5 = fVar5 - fVar1;
  }
  else {
    fVar5 = fVar1 + fVar5;
  }
  fVar1 = fVar3 * *(float *)(param_1 + 0x3a6c);
  if (DAT_0059e440 <= *(float *)(param_1 + 0x3500)) {
    fVar6 = fVar6 - fVar1;
  }
  else {
    fVar6 = fVar1 + fVar6;
    fVar3 = fVar3 * *(float *)(param_1 + 0x3a70);
    fVar5 = fVar5 - fVar3;
    *(float *)(param_1 + 0x3558) =
         fVar3 * *(float *)(param_1 + 0x3a74) + *(float *)(param_1 + 0x3558);
  }
  *(float *)(param_1 + 0x354c) = fVar4 + *(float *)(param_1 + 0x354c);
  *(float *)(param_1 + 0x3550) = fVar5 + *(float *)(param_1 + 0x3550);
  *(float *)(param_1 + 0x3554) = fVar6 + *(float *)(param_1 + 0x3554);
  return;
}


