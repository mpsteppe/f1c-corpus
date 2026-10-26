// Function: FUN_004f17d0 @ 004f17d0
// Size (bytes): 138


void __thiscall FUN_004f17d0(int param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  
  pfVar2 = (float *)(param_1 + 0x34b0);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = *param_2;
    param_2 = param_2 + 1;
    pfVar2 = pfVar2 + 1;
  }
  pfVar2 = (float *)(param_1 + 0x3534);
  *pfVar2 = *param_3;
  *(float *)(param_1 + 0x3538) = param_3[1];
  *(float *)(param_1 + 0x353c) = param_3[2];
  *(float *)(param_1 + 0x3540) =
       *pfVar2 * *(float *)(param_1 + 0x34b0) +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x353c);
  *(float *)(param_1 + 0x3544) =
       *(float *)(param_1 + 0x34b4) * *pfVar2 +
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x353c);
  *(float *)(param_1 + 0x3548) =
       *(float *)(param_1 + 0x34b8) * *pfVar2 +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x353c);
  return;
}


