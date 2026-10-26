// Function: FUN_00423db0 @ 00423db0
// Size (bytes): 197


void __thiscall
FUN_00423db0(int *param_1,float param_2,undefined4 param_3,float param_4,float param_5,
            undefined4 param_6,float param_7)

{
  float fVar1;
  float fVar2;
  
  param_5 = *(float *)(*param_1 + 0x34e0) - param_5;
  param_7 = *(float *)(*param_1 + 0x34e8) - param_7;
  fVar2 = param_2 * param_5 + param_4 * param_7;
  fVar1 = param_2 * fVar2 * param_2 * fVar2 + param_4 * fVar2 * param_4 * fVar2;
  if (fVar2 <= DAT_0059e440) {
    fVar1 = -SQRT(fVar1);
  }
  else {
    fVar1 = SQRT(fVar1);
  }
  param_1[3] = (int)fVar1;
  fVar2 = param_2 * param_7 - param_4 * param_5;
  fVar1 = -param_4 * fVar2 * -param_4 * fVar2 + param_2 * fVar2 * param_2 * fVar2;
  if (DAT_0059e440 < fVar2) {
    param_1[1] = (int)-SQRT(fVar1);
    return;
  }
  param_1[1] = (int)SQRT(fVar1);
  return;
}


