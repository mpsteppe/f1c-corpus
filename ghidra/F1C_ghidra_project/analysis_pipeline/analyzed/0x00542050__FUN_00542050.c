// Function: FUN_00542050 @ 00542050
// Size (bytes): 422


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00542050(int param_1,float param_2,float param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  *(float *)(param_1 + 0x6c) = param_2;
  if (param_4 == 0) {
    fVar3 = ((float10)DAT_008b8dd8 / (float10)DAT_008b8dd4) * (float10)_DAT_005b897c *
            (float10)param_2 * (float10)_DAT_005b8978;
  }
  else {
    fVar3 = (float10)param_3;
  }
  *(float *)(param_1 + 0x70) = (float)fVar3;
  fVar1 = (float)((float10)param_2 * (float10)_DAT_0059e450);
  fVar4 = (float10)fptan((float10)param_2 * (float10)_DAT_0059e450);
  *(float *)(param_1 + 0x1c) = (float)fVar4;
  fVar2 = (float)(fVar3 * (float10)_DAT_0059e450);
  fVar3 = (float10)fptan(fVar3 * (float10)_DAT_0059e450);
  *(float *)(param_1 + 0x20) = (float)fVar3;
  fVar5 = (float10)fsin((float10)fVar1);
  fVar6 = (float10)fcos((float10)fVar1);
  fVar7 = (float10)fsin((float10)fVar2);
  fVar8 = (float10)fcos((float10)fVar2);
  *(float *)(param_1 + 0xc) = ((float)*(int *)(param_1 + 0x54) * _DAT_0059e450) / (float)fVar4;
  *(float *)(param_1 + 0x10) = ((float)*(int *)(param_1 + 0x58) * _DAT_0059e450) / (float)fVar3;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0xbf800000;
  *(float *)(param_1 + 0xf8) = -*(float *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 4);
  *(float *)(param_1 + 0x9c) = (float)-fVar6;
  *(float *)(param_1 + 0xa4) = (float)fVar5;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(float *)(param_1 + 0xac) = (float)fVar6;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(float *)(param_1 + 0xb4) = (float)fVar5;
  *(float *)(param_1 + 0xc0) = (float)fVar8;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(float *)(param_1 + 0xc4) = (float)fVar7;
  *(undefined4 *)(param_1 + 200) = 0;
  *(float *)(param_1 + 0xd0) = -(float)fVar8;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(float *)(param_1 + 0xd4) = (float)fVar7;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  fVar3 = (float10)fptan((float10)*(float *)(param_1 + 0x6c) * (float10)_DAT_0059e450);
  fVar3 = fVar3 * (float10)*(float *)(param_1 + 8);
  fVar4 = (float10)fptan((float10)*(float *)(param_1 + 0x70) * (float10)_DAT_0059e450);
  fVar4 = fVar4 * (float10)*(float *)(param_1 + 8);
  *(float *)(param_1 + 0x78) = (float)SQRT(fVar3 * fVar3 + fVar4 * fVar4);
  if ((*(byte *)(param_1 + 0x80) & 0x10) != 0) {
    *(float *)(param_1 + 0xc) = -*(float *)(param_1 + 0xc);
  }
  return;
}


