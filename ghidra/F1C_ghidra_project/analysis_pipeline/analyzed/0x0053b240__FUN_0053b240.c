// Function: FUN_0053b240 @ 0053b240
// Size (bytes): 239


void __fastcall FUN_0053b240(int param_1)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar3 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x10) = (float)fVar3;
  fVar4 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x14) = (float)fVar4;
  fVar5 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x18) = (float)fVar5;
  fVar6 = (float10)fsin((float10)(float)fVar3);
  *(undefined4 *)(param_1 + 0x34) = 0;
  fVar3 = (float10)fcos((float10)(float)fVar3);
  fVar1 = (float)fVar3;
  fVar3 = (float10)fsin((float10)(float)fVar4);
  fVar4 = (float10)fcos((float10)(float)fVar4);
  fVar2 = (float)fVar4;
  fVar4 = (float10)fsin(fVar5);
  fVar5 = (float10)fcos(fVar5);
  *(float *)(param_1 + 0x28) =
       (float)(fVar3 * fVar6 * fVar4 + (float10)(float)(fVar5 * (float10)fVar2));
  *(float *)(param_1 + 0x2c) = (float)(fVar4 * (float10)fVar1);
  *(float *)(param_1 + 0x30) =
       (float)((float10)(float)(fVar4 * (float10)fVar2) * fVar6 - fVar5 * fVar3);
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(float *)(param_1 + 0x38) =
       (float)(fVar3 * fVar6 * fVar5 - (float10)(float)(fVar4 * (float10)fVar2));
  *(float *)(param_1 + 0x3c) = (float)(fVar5 * (float10)fVar1);
  *(float *)(param_1 + 0x40) =
       (float)(fVar4 * fVar3 + (float10)(float)(fVar5 * (float10)fVar2) * fVar6);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(float *)(param_1 + 0x48) = (float)(fVar3 * (float10)fVar1);
  *(float *)(param_1 + 0x4c) = (float)-fVar6;
  *(float *)(param_1 + 0x50) = fVar2 * fVar1;
  return;
}


