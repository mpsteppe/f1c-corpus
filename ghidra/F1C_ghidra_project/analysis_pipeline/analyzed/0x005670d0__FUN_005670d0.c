// Function: FUN_005670d0 @ 005670d0
// Size (bytes): 79


void __thiscall FUN_005670d0(float *param_1,float param_2,float param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar1 = (float10)fsin((float10)param_2);
  param_1[5] = 0.0;
  fVar2 = (float10)fcos((float10)param_2);
  fVar3 = (float10)fsin((float10)param_3);
  fVar4 = (float10)fcos((float10)param_3);
  *param_1 = (float)(fVar4 * fVar2);
  param_1[1] = (float)-(fVar3 * fVar2);
  param_1[2] = (float)fVar1;
  param_1[3] = (float)fVar3;
  param_1[4] = (float)fVar4;
  param_1[6] = (float)-(fVar4 * fVar1);
  param_1[7] = (float)(fVar3 * fVar1);
  param_1[8] = (float)fVar2;
  return;
}


