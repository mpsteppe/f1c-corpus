// Function: FUN_004e2070 @ 004e2070
// Size (bytes): 185


void __thiscall FUN_004e2070(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float local_24 [9];
  
  fVar1 = *(float *)(param_1 + 0x8f4) + *(float *)(param_1 + 0x900);
  fVar3 = *(float *)(param_1 + 0x8f8) + *(float *)(param_1 + 0x904);
  fVar2 = *(float *)(param_1 + 0x8fc) + *(float *)(param_1 + 0x908);
  *param_2 = fVar1 * *(float *)(param_1 + 0x20) +
             fVar3 * *(float *)(param_1 + 0x24) + fVar2 * *(float *)(param_1 + 0x28);
  param_2[1] = fVar1 * *(float *)(param_1 + 0x2c) +
               fVar3 * *(float *)(param_1 + 0x30) + fVar2 * *(float *)(param_1 + 0x34);
  param_2[2] = fVar1 * *(float *)(param_1 + 0x38) +
               fVar3 * *(float *)(param_1 + 0x3c) + fVar2 * *(float *)(param_1 + 0x40);
  *param_2 = *(float *)(param_1 + 8) + *param_2;
  param_2[1] = *(float *)(param_1 + 0xc) + param_2[1];
  param_2[2] = *(float *)(param_1 + 0x10) + param_2[2];
  pfVar5 = (float *)(param_1 + 0x20);
  pfVar6 = local_24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  FUN_00567120(param_1 + 0x90c,param_3);
  return;
}


