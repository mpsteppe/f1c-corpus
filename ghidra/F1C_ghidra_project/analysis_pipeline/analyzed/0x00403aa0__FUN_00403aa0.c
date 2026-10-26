// Function: FUN_00403aa0 @ 00403aa0
// Size (bytes): 548


int FUN_00403aa0(float *param_1,int param_2,float param_3,char param_4)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = (int)param_3;
  if (param_2 == 0) {
    iVar7 = FUN_004038e0(param_1,param_3);
    return iVar7;
  }
  if ((((float)*(int *)(param_2 + 300) != param_3) &&
      (iVar1 = *(int *)(param_2 + 0x114), iVar1 != 0)) && ((float)*(int *)(iVar1 + 300) == param_3))
  {
    param_2 = iVar1;
  }
  iVar1 = *(int *)(param_2 + 0x10c);
  fVar3 = *param_1 - *(float *)(param_2 + 0x94);
  fVar5 = param_1[1] - *(float *)(param_2 + 0x98);
  fVar4 = param_1[2] - *(float *)(param_2 + 0x9c);
  param_3 = fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4;
  iVar9 = param_2;
  if ((iVar1 != 0) &&
     (fVar3 = *param_1 - *(float *)(iVar1 + 0x94), fVar5 = param_1[1] - *(float *)(iVar1 + 0x98),
     fVar4 = param_1[2] - *(float *)(iVar1 + 0x9c),
     fVar3 = fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4, fVar3 < param_3)) {
    do {
      fVar4 = fVar3;
      iVar8 = iVar1;
      if (iVar7 != *(int *)(iVar8 + 300)) break;
      iVar1 = *(int *)(iVar8 + 0x10c);
      if (iVar1 == 0) goto LAB_00403cad;
      fVar6 = *param_1 - *(float *)(iVar1 + 0x94);
      fVar5 = param_1[1] - *(float *)(iVar1 + 0x98);
      fVar3 = param_1[2] - *(float *)(iVar1 + 0x9c);
      fVar3 = fVar6 * fVar6 + fVar5 * fVar5 + fVar3 * fVar3;
      iVar9 = iVar8;
      param_3 = fVar4;
    } while (fVar3 < fVar4);
  }
  iVar1 = *(int *)(param_2 + 0x110);
  if ((iVar1 != 0) &&
     (fVar3 = *param_1 - *(float *)(iVar1 + 0x94), fVar5 = param_1[1] - *(float *)(iVar1 + 0x98),
     fVar4 = param_1[2] - *(float *)(iVar1 + 0x9c),
     fVar3 = fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4, fVar3 < param_3)) {
    do {
      iVar9 = iVar1;
      iVar1 = *(int *)(iVar9 + 0x110);
      if (iVar1 == 0) goto LAB_00403cad;
      fVar6 = *param_1 - *(float *)(iVar1 + 0x94);
      fVar5 = param_1[1] - *(float *)(iVar1 + 0x98);
      fVar4 = param_1[2] - *(float *)(iVar1 + 0x9c);
      fVar4 = fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4;
      bVar2 = fVar4 < fVar3;
      fVar3 = fVar4;
    } while (bVar2);
  }
  if (param_4 != '\0') {
    if (iVar9 == 0) goto LAB_00403cad;
    if (*(float *)(iVar9 + 0xa4) * (*(float *)(iVar9 + 0x94) - *param_1) +
        *(float *)(iVar9 + 0xac) * (*(float *)(iVar9 + 0x9c) - param_1[2]) < DAT_0059e440) {
      iVar9 = *(int *)(iVar9 + 0x110);
    }
  }
  if (iVar9 != 0) {
    return iVar9;
  }
LAB_00403cad:
  iVar7 = FUN_004038e0(param_1,iVar7);
  return iVar7;
}


