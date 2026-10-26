// Function: FUN_00405e60 @ 00405e60
// Size (bytes): 275


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00405e60(int *param_1,float param_2,int param_3,float *param_4,int *param_5,float *param_6,
            float *param_7)

{
  int *piVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  bVar2 = param_2 < _DAT_0059e4d8;
  param_1[0x12] = param_3;
  piVar1 = (int *)param_1[0x15];
  param_1[10] = (int)*param_4;
  param_1[0xb] = (int)param_4[1];
  param_1[0xc] = (int)param_4[2];
  param_1[0xd] = *param_5;
  param_1[0xe] = param_5[1];
  param_1[0xf] = param_5[2];
  if (bVar2) {
    param_2 = 0.0;
  }
  iVar4 = (**(code **)(*piVar1 + 0x58))();
  if (iVar4 == 1) {
    fVar5 = (float10)(**(code **)(*(int *)param_1[0x15] + 0x30))();
    fVar5 = fVar5 * (float10)param_2;
    if ((float10)_DAT_0059e43c < fVar5) {
      fVar5 = (float10)_DAT_0059e43c;
    }
  }
  else {
    fVar5 = (float10)DAT_0059e440;
  }
  param_1[0x10] = (int)(float)fVar5;
  if (fVar5 == (float10)DAT_0059e440) {
    (**(code **)(*param_1 + 8))();
    return 1;
  }
  if ((*(byte *)(param_1 + 6) & 8) == 0) {
    *param_7 = *param_4 - (float)piVar1[0x16];
    param_7[1] = param_4[1] - (float)piVar1[0x17];
    fVar3 = param_4[2] - (float)piVar1[0x18];
    param_7[2] = fVar3;
    *param_6 = SQRT(fVar3 * fVar3 + param_7[1] * param_7[1] + *param_7 * *param_7);
    return 0;
  }
  *param_6 = 0.0;
  return 0;
}


