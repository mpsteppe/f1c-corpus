// Function: FUN_00541db0 @ 00541db0
// Size (bytes): 422


void __fastcall FUN_00541db0(int param_1)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar3 = (float10)FUN_0058957a();
  fVar1 = (float)fVar3;
  fVar3 = (float10)FUN_0058957a();
  fVar2 = (float)fVar3;
  fVar3 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x38) = (float)fVar3;
  fVar4 = (float10)fsin((float10)fVar1);
  *(float *)(param_1 + 0x30) = fVar1;
  *(float *)(param_1 + 0x34) = fVar2;
  *(undefined4 *)(param_1 + 0x168) = 0;
  fVar5 = (float10)fcos((float10)fVar1);
  fVar6 = (float10)fsin((float10)fVar2);
  fVar7 = (float10)fcos((float10)fVar2);
  fVar1 = (float)fVar7;
  fVar7 = (float10)fsin(fVar3);
  fVar3 = (float10)fcos(fVar3);
  fVar2 = (float)((float10)(float)fVar3 * fVar6);
  *(float *)(param_1 + 0x15c) =
       (float)((float10)(float)(fVar3 * (float10)fVar1) - fVar7 * fVar6 * fVar4);
  *(float *)(param_1 + 0x164) = (float)-(fVar6 * fVar5);
  *(float *)(param_1 + 0x160) =
       (float)((float10)fVar2 * fVar4 + (float10)(float)((float10)fVar1 * fVar7));
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(float *)(param_1 + 0x16c) = (float)-(fVar7 * fVar5);
  *(float *)(param_1 + 0x174) = (float)fVar4;
  *(float *)(param_1 + 0x170) = (float)((float10)(float)fVar3 * fVar5);
  *(undefined4 *)(param_1 + 0x188) = 0;
  fVar8 = (float10)(float)((float10)fVar1 * fVar7) * fVar4 + (float10)fVar2;
  *(float *)(param_1 + 0x17c) = (float)fVar8;
  *(float *)(param_1 + 0x184) = (float)((float10)fVar1 * fVar5);
  *(float *)(param_1 + 0x180) =
       (float)((float10)(float)(fVar7 * fVar6) - (float10)(float)(fVar3 * (float10)fVar1) * fVar4);
  *(float *)(param_1 + 0x18c) =
       *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x16c) +
       (float)fVar8 * *(float *)(param_1 + 0x2c) +
       *(float *)(param_1 + 0x15c) * *(float *)(param_1 + 0x24);
  *(float *)(param_1 + 400) =
       *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x160) +
       *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x170) +
       *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x180);
  *(undefined4 *)(param_1 + 0x198) = 0x3f800000;
  *(float *)(param_1 + 0x194) =
       *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x164) +
       *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x184) +
       *(float *)(param_1 + 0x174) * *(float *)(param_1 + 0x28);
  return;
}


