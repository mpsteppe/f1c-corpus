// Function: FUN_0053bce0 @ 0053bce0
// Size (bytes): 255


void FUN_0053bce0(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x24) * *(float *)(param_2 + 0x48) *
          DAT_0059fec8;
  fVar2 = *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x24) * *(float *)(param_2 + 0x44) *
          DAT_0059fec8;
  fVar3 = DAT_0059e440 * DAT_0059e440 * DAT_0059e440;
  *param_3 = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x24) * *(float *)(param_2 + 0x4c) *
             DAT_0059fec8;
  param_3[1] = fVar1;
  param_3[2] = fVar2;
  param_3[3] = fVar3;
  return;
}


