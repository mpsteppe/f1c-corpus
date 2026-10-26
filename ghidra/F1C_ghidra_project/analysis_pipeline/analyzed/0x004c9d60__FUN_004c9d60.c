// Function: FUN_004c9d60 @ 004c9d60
// Size (bytes): 585


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c9d60(int param_1,float param_2,float param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  uint uVar4;
  
  uVar4 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(param_1 + 0x10) =
       (*(float *)(&DAT_008ab274 + uVar4 * 4) * _DAT_0059e7e8 + _DAT_0059e43c) * param_2;
  uVar4 = DAT_008aae70 + 2;
  param_3 = (*(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7e8 + _DAT_0059e43c)
            * param_3;
  fVar3 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e7e8 + _DAT_0059e43c;
  DAT_008aae70 = DAT_008aae70 + 3;
  param_5 = (*(float *)(&DAT_008ab274 + (uVar4 & 0xff) * 4) * _DAT_0059e7e8 + _DAT_0059e43c) *
            param_5;
  *(float *)(param_1 + 0x14) = param_3;
  fVar3 = param_3 + fVar3 * param_4;
  *(float *)(param_1 + 0x18) = fVar3;
  *(float *)(param_1 + 0x1c) = fVar3 + param_5;
  if (param_3 == DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    *(float *)(param_1 + 0x20) = _DAT_0059e43c / param_3;
  }
  if (param_5 == DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    *(float *)(param_1 + 0x24) = _DAT_0059e43c / param_5;
  }
  uVar4 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar3 = *(float *)(&DAT_008ab274 + uVar4 * 4) * _DAT_0059e86c + _DAT_005ace90;
  *(float *)(param_1 + 0x28) = fVar3;
  *(int *)(param_1 + 0x60) = (int)ROUND(fVar3) * 0x1000000 + 0xffffff;
  uVar4 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(param_1 + 0x68) = *(float *)(&DAT_008ab274 + uVar4 * 4) * _DAT_0059e7e8 + _DAT_0059e43c
  ;
  uVar1 = *(undefined4 *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4);
  uVar2 = *(undefined4 *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4);
  uVar4 = DAT_008aae70 + 2;
  DAT_008aae70 = DAT_008aae70 + 3;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(&DAT_008ab274 + (uVar4 & 0xff) * 4);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  if (*(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50) +
      *(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x4c) +
      *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x48) == DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    fVar3 = _DAT_0059e43c /
            SQRT(*(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x50) +
                 *(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x4c) +
                 *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x48));
    *(float *)(param_1 + 0x48) = fVar3 * *(float *)(param_1 + 0x48);
    *(float *)(param_1 + 0x4c) = fVar3 * *(float *)(param_1 + 0x4c);
    *(float *)(param_1 + 0x50) = fVar3 * *(float *)(param_1 + 0x50);
  }
  uVar4 = _rand();
  uVar4 = uVar4 & 0x8000000f;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
  }
  *(uint *)(param_1 + 0x54) = uVar4;
  return;
}


