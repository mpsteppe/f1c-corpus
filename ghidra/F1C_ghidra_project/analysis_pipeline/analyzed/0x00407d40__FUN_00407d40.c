// Function: FUN_00407d40 @ 00407d40
// Size (bytes): 144


void __thiscall FUN_00407d40(int param_1,undefined4 *param_2,float *param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  *(undefined4 *)(param_1 + 0x58) = *param_2;
  *(undefined4 *)(param_1 + 0x5c) = param_2[1];
  *(undefined4 *)(param_1 + 0x60) = param_2[2];
  *(float *)(param_1 + 100) = *param_3;
  *(float *)(param_1 + 0x68) = param_3[1];
  *(float *)(param_1 + 0x6c) = param_3[2];
  fVar4 = (float10)fsin((float10)param_3[1]);
  fVar5 = (float10)fsin((float10)*param_3);
  fVar6 = (float10)fcos((float10)param_3[1]);
  fVar1 = (float10)DAT_0059e440;
  fVar2 = (float10)DAT_0059e440;
  fVar3 = (float10)DAT_0059e440;
  *(float *)(param_1 + 0x78) = (float)(fVar4 - (float10)(float)(-fVar5 * fVar1));
  *(float *)(param_1 + 0x70) = (float)(-fVar5 * fVar1) - (float)-fVar6;
  *(float *)(param_1 + 0x74) = (float)((float10)(float)-fVar6 * fVar2 - fVar4 * fVar3);
  return;
}


