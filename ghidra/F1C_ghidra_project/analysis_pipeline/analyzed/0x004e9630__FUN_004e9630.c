// Function: FUN_004e9630 @ 004e9630
// Size (bytes): 140


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004e9630(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  
  pfVar1 = (float *)(param_1 + 0x34d4);
  fVar2 = *(float *)(param_1 + 0x3aa0) - *pfVar1;
  fVar4 = *(float *)(param_1 + 0x3aa4) - *(float *)(param_1 + 0x34d8);
  fVar3 = *(float *)(param_1 + 0x3aa8) - *(float *)(param_1 + 0x34dc);
  if ((_DAT_0059e9e0 < fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) ||
     (*(int *)(param_1 + 0x3a9c) == 0)) {
    uVar5 = FUN_00403640(pfVar1,*(undefined4 *)(param_1 + 0x3a9c));
    *(undefined4 *)(param_1 + 0x3a9c) = uVar5;
    *(float *)(param_1 + 0x3aa0) = *pfVar1;
    *(undefined4 *)(param_1 + 0x3aa4) = *(undefined4 *)(param_1 + 0x34d8);
    *(undefined4 *)(param_1 + 0x3aa8) = *(undefined4 *)(param_1 + 0x34dc);
  }
  return *(undefined4 *)(param_1 + 0x3a9c);
}


