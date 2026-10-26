// Function: FUN_00403cd0 @ 00403cd0
// Size (bytes): 664


void __thiscall FUN_00403cd0(int param_1,int param_2,float *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float fVar9;
  float *pfVar10;
  int iVar11;
  
  pfVar8 = *(float **)(param_1 + 0x150);
  pfVar10 = pfVar8 + param_2 * 7;
  if (((((*pfVar10 != DAT_0059e440) || (pfVar10[1] != DAT_0059e440)) || (pfVar10[2] != DAT_0059e440)
       ) || ((pfVar10[3] != DAT_0059e440 || (pfVar10[4] != DAT_0059e440)))) ||
     (pfVar10[5] != DAT_0059e440)) {
    *param_3 = *pfVar10;
    param_3[1] = pfVar10[1];
    param_3[2] = pfVar10[2];
    puVar1 = (undefined4 *)(param_2 * 0x1c + 0xc + *(int *)(param_1 + 0x150));
    *param_4 = *puVar1;
    param_4[1] = puVar1[1];
    param_4[2] = puVar1[2];
    return;
  }
  iVar11 = param_2 + -2;
  if (-1 < iVar11) {
    pfVar10 = pfVar8 + iVar11 * 7;
    do {
      if (((*pfVar10 != DAT_0059e440) || (pfVar10[1] != DAT_0059e440)) ||
         ((pfVar10[2] != DAT_0059e440 ||
          (((pfVar10[3] != DAT_0059e440 || (pfVar10[4] != DAT_0059e440)) ||
           (pfVar10[5] != DAT_0059e440)))))) break;
      iVar11 = iVar11 + -2;
      pfVar10 = pfVar10 + -0xe;
    } while (-1 < iVar11);
  }
  if ((1 < iVar11) &&
     ((((pfVar10 = pfVar8 + (iVar11 + -2) * 7, pfVar8[(iVar11 + -2) * 7] != DAT_0059e440 ||
        (pfVar10[1] != DAT_0059e440)) ||
       ((pfVar10[2] != DAT_0059e440 ||
        ((pfVar10[3] != DAT_0059e440 || (pfVar10[4] != DAT_0059e440)))))) ||
      (pfVar10[5] != DAT_0059e440)))) {
    fVar9 = (float)((param_2 - iVar11) / 2);
    fVar2 = pfVar8[iVar11 * 7 + 1];
    fVar3 = pfVar10[1];
    fVar4 = pfVar8[iVar11 * 7 + 2];
    fVar5 = pfVar10[2];
    fVar6 = pfVar8[iVar11 * 7 + 1];
    fVar7 = pfVar8[iVar11 * 7 + 2];
    *param_3 = (pfVar8[iVar11 * 7] - *pfVar10) * fVar9 + pfVar8[iVar11 * 7];
    param_3[1] = (fVar2 - fVar3) * fVar9 + fVar6;
    param_3[2] = (fVar4 - fVar5) * fVar9 + fVar7;
    puVar1 = (undefined4 *)(iVar11 * 0x1c + 0xc + *(int *)(param_1 + 0x150));
    *param_4 = *puVar1;
    param_4[1] = puVar1[1];
    param_4[2] = puVar1[2];
    return;
  }
  *param_3 = *pfVar8;
  param_3[1] = pfVar8[1];
  param_3[2] = pfVar8[2];
  iVar11 = *(int *)(param_1 + 0x150);
  *param_4 = *(undefined4 *)(iVar11 + 0xc);
  param_4[1] = *(undefined4 *)(iVar11 + 0x10);
  param_4[2] = *(undefined4 *)(iVar11 + 0x14);
  return;
}


