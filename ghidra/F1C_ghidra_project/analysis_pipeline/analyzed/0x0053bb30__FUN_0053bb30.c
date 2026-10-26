// Function: FUN_0053bb30 @ 0053bb30
// Size (bytes): 432


void FUN_0053bb30(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x14) * *(float *)(param_3 + 0x5c);
  fVar2 = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0x14) * *(float *)(param_3 + 0x58);
  fVar3 = *(float *)(param_2 + 8) * *(float *)(param_2 + 0x14) * *(float *)(param_3 + 0x54);
  fVar4 = DAT_0059e440 * DAT_0059e440;
  if (param_1 != 0) {
    fVar1 = *(float *)(param_1 + 0x184) + fVar1;
    fVar2 = *(float *)(param_1 + 0x180) + fVar2;
    fVar3 = *(float *)(param_1 + 0x17c) + fVar3;
    fVar4 = DAT_0059e440 + fVar4;
  }
  fVar2 = (fVar2 + *(float *)(param_3 + 0x78)) * DAT_0059fec8;
  fVar3 = (fVar3 + *(float *)(param_3 + 0x74)) * DAT_0059fec8;
  fVar4 = (fVar4 + DAT_0059e440) * DAT_0059e440;
  *param_4 = (fVar1 + *(float *)(param_3 + 0x7c)) * DAT_0059fec8;
  param_4[1] = fVar2;
  param_4[2] = fVar3;
  param_4[3] = fVar4;
  return;
}


