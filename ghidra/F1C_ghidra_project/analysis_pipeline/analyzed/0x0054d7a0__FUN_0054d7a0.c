// Function: FUN_0054d7a0 @ 0054d7a0
// Size (bytes): 368


undefined4 __thiscall FUN_0054d7a0(int param_1,int param_2,float *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  
  fVar3 = *(float *)(param_2 + 0x2c) + param_3[2];
  uVar1 = *(uint *)(param_1 + 0x14);
  fVar5 = *(float *)(param_2 + 0x28) + param_3[1];
  fVar4 = *(float *)(param_2 + 0x24) + *param_3;
  fVar3 = SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4);
  if ((uVar1 & 0x10) == 0) {
    if ((fVar3 < *(float *)(param_1 + 0xf8)) &&
       (fVar3 < *(float *)(param_1 + 0xf4) == (fVar3 == *(float *)(param_1 + 0xf4)))) {
      *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffffc | 4;
      return 0;
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0xfc);
    if (((iVar2 < 5) || (fVar3 - *(float *)(param_1 + 0x18) <= *(float *)(param_2 + 8))) &&
       ((param_4 != 0 ||
        ((fVar3 <= *(float *)(param_1 + 0xf8) * *(float *)(param_2 + 0x88) &&
         (*(float *)(param_1 + 0xf4) * *(float *)(param_2 + 0x88) < fVar3)))))) {
      iVar6 = 0;
      *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffff9 | 1;
      if (iVar2 < 1) {
        return 0;
      }
      pfVar7 = (float *)(param_2 + 0x104);
      while( true ) {
        fVar3 = ((-(pfVar7[-2] * *param_3) - pfVar7[-1] * param_3[1]) - *pfVar7 * param_3[2]) -
                pfVar7[1];
        if (*(float *)(param_1 + 0x18) < fVar3) {
          *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffff8 | 2;
          return 0;
        }
        if (-*(float *)(param_1 + 0x18) < fVar3) break;
        iVar6 = iVar6 + 1;
        pfVar7 = pfVar7 + 4;
        if (iVar2 <= iVar6) {
          return 0;
        }
      }
      *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffff8 | 4;
      return 0;
    }
  }
  *(uint *)(param_1 + 0x14) = uVar1 & 0xfffffffa | 2;
  return 0;
}


