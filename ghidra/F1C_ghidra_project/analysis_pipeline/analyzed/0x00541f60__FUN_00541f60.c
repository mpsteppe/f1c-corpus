// Function: FUN_00541f60 @ 00541f60
// Size (bytes): 235


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00541f60(int param_1,float param_2,float param_3,float param_4)

{
  float10 fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  
  param_2 = *(float *)(param_1 + 0x24) - param_2;
  param_3 = *(float *)(param_1 + 0x28) - param_3;
  param_4 = *(float *)(param_1 + 0x2c) - param_4;
  fVar2 = SQRT(param_2 * param_2 + param_3 * param_3 + param_4 * param_4);
  if (fVar2 != (float)_DAT_0059e430) {
    fVar2 = _DAT_0059e43c / fVar2;
    fVar3 = (float10)FUN_00588570();
    fVar4 = (float10)fpatan((float10)fVar2 * (float10)param_4,(float10)fVar2 * (float10)param_2);
    fVar1 = (float10)_DAT_0059f1f4;
    *(float *)(param_1 + 0x30) = -(float)-fVar3;
    *(float *)(param_1 + 0x34) = -(float)(fVar4 + fVar1);
    FUN_00541cd0(*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x3c),
                 *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x40),
                 *(float *)(param_1 + 0x2c) - *(float *)(param_1 + 0x44),(float)-fVar3,
                 (float)(fVar4 + fVar1),-*(float *)(param_1 + 0x38));
    return;
  }
  return;
}


