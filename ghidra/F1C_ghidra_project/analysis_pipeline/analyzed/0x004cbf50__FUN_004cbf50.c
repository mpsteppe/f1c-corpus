// Function: FUN_004cbf50 @ 004cbf50
// Size (bytes): 639


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cbf50(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar1 = *(float *)(param_3 + 0x78);
  fVar2 = *(float *)(param_3 + 0x84);
  fVar3 = *param_1 - *(float *)(param_3 + 8);
  fVar7 = param_1[1] - *(float *)(param_3 + 0xc);
  fVar6 = param_1[2] - *(float *)(param_3 + 0x10);
  fVar5 = fVar3 * *(float *)(param_3 + 0x20) +
          fVar7 * *(float *)(param_3 + 0x2c) + fVar6 * *(float *)(param_3 + 0x38);
  fVar4 = fVar3 * *(float *)(param_3 + 0x24) +
          fVar7 * *(float *)(param_3 + 0x30) + fVar6 * *(float *)(param_3 + 0x3c);
  fVar3 = fVar3 * *(float *)(param_3 + 0x28) +
          fVar7 * *(float *)(param_3 + 0x34) + fVar6 * *(float *)(param_3 + 0x40);
  fVar6 = *param_2 - *(float *)(param_3 + 8);
  fVar10 = param_2[1] - *(float *)(param_3 + 0xc);
  fVar9 = param_2[2] - *(float *)(param_3 + 0x10);
  fVar8 = fVar6 * *(float *)(param_3 + 0x20) +
          fVar10 * *(float *)(param_3 + 0x2c) + fVar9 * *(float *)(param_3 + 0x38);
  fVar7 = fVar6 * *(float *)(param_3 + 0x24) +
          fVar10 * *(float *)(param_3 + 0x30) + fVar9 * *(float *)(param_3 + 0x3c);
  fVar6 = fVar6 * *(float *)(param_3 + 0x28) +
          fVar10 * *(float *)(param_3 + 0x34) + fVar9 * *(float *)(param_3 + 0x40);
  if ((((fVar5 < fVar2) && (fVar1 < fVar8)) || ((fVar1 < fVar5 && (fVar8 < fVar2)))) &&
     ((((fVar3 < *(float *)(param_3 + 0x8c) && (*(float *)(param_3 + 0x80) < fVar6)) ||
       ((*(float *)(param_3 + 0x80) < fVar3 && (fVar6 < *(float *)(param_3 + 0x8c))))) &&
      (((fVar4 < *(float *)(param_3 + 0x88) && (*(float *)(param_3 + 0x7c) < fVar7)) ||
       ((*(float *)(param_3 + 0x7c) < fVar4 && (fVar7 < *(float *)(param_3 + 0x88))))))))) {
    if ((fVar1 + fVar2) * _DAT_0059e450 <= (fVar8 + fVar5) * _DAT_0059e450) {
      fVar1 = fVar2;
      if (fVar5 <= fVar8) {
        fVar1 = (fVar8 - fVar5) + fVar2;
      }
    }
    else if (fVar8 < fVar5) {
      fVar1 = fVar1 - (fVar5 - fVar8);
    }
    *param_2 = fVar1 * *(float *)(param_3 + 0x20) +
               fVar6 * *(float *)(param_3 + 0x28) + fVar7 * *(float *)(param_3 + 0x24);
    param_2[1] = fVar1 * *(float *)(param_3 + 0x2c) +
                 fVar6 * *(float *)(param_3 + 0x34) + fVar7 * *(float *)(param_3 + 0x30);
    param_2[2] = fVar1 * *(float *)(param_3 + 0x38) +
                 fVar6 * *(float *)(param_3 + 0x40) + fVar7 * *(float *)(param_3 + 0x3c);
    *param_2 = *param_2 + *(float *)(param_3 + 8);
    param_2[1] = *(float *)(param_3 + 0xc) + param_2[1];
    param_2[2] = *(float *)(param_3 + 0x10) + param_2[2];
  }
  return;
}


