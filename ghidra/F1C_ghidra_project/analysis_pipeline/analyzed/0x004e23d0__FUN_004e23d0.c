// Function: FUN_004e23d0 @ 004e23d0
// Size (bytes): 199


void __thiscall FUN_004e23d0(int param_1,float *param_2,undefined4 *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  
  *(undefined4 *)(param_1 + 0x14) = *param_3;
  *(undefined4 *)(param_1 + 0x18) = param_3[1];
  *(undefined4 *)(param_1 + 0x1c) = param_3[2];
  pfVar4 = (float *)(param_1 + 0x20);
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *param_4;
    param_4 = param_4 + 1;
    pfVar4 = pfVar4 + 1;
  }
  *(float *)(param_1 + 0x54) = *param_2;
  *(float *)(param_1 + 0x58) = param_2[1];
  *(float *)(param_1 + 0x5c) = param_2[2];
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *(float *)(param_1 + 8) =
       *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x20) +
       *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x4c) +
       *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x50) + *param_2;
  *(float *)(param_1 + 0xc) =
       *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x48) +
       *(float *)(param_1 + 0x30) * *(float *)(param_1 + 0x4c) +
       *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x50) + fVar1;
  *(float *)(param_1 + 0x10) =
       *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x48) +
       *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x4c) +
       *(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x50) + fVar2;
  return;
}


