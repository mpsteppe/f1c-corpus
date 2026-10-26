// Function: FUN_00457d00 @ 00457d00
// Size (bytes): 477


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00457d00(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int *piVar10;
  float *pfVar11;
  int iVar12;
  float local_10;
  
  if (param_2 < DAT_0059e440) {
    iVar12 = *param_1;
    param_1[4] = *(int *)(iVar12 + 0x1c);
    param_1[5] = *(int *)(iVar12 + 0x20);
    param_1[6] = *(int *)(iVar12 + 0x24);
    param_1[3] = 0;
    return;
  }
  if ((float)param_1[2] <= param_2) {
    piVar10 = (int *)((param_1[1] + -2) * 0x1c + *param_1);
    param_1[4] = *piVar10;
    param_1[5] = piVar10[1];
    param_1[6] = piVar10[2];
    param_1[3] = param_1[2];
    return;
  }
  iVar12 = 0;
  if (0 < param_1[1] + -3) {
    iVar5 = *param_1;
    pfVar11 = (float *)(iVar5 + 0x34);
    do {
      if ((pfVar11[-7] < param_2 != (pfVar11[-7] == param_2)) && (param_2 < *pfVar11)) {
        fVar1 = *(float *)(iVar12 * 0x1c + 0x18 + iVar5);
        local_10 = (param_2 - fVar1) / (*(float *)(iVar12 * 0x1c + 0x34 + iVar5) - fVar1);
        break;
      }
      iVar12 = iVar12 + 1;
      pfVar11 = pfVar11 + 7;
    } while (iVar12 < param_1[1] + -3);
  }
  iVar5 = *param_1;
  fVar1 = local_10 * local_10;
  fVar2 = local_10 * fVar1;
  fVar7 = (_DAT_0059e478 * fVar2 - fVar1 * _DAT_0059e7ec) + local_10 * DAT_0059e440 + _DAT_0059e800;
  pfVar11 = (float *)(iVar12 * 0x1c + iVar5);
  fVar8 = (fVar1 * _DAT_0059e46c - _DAT_0059e478 * fVar2) + local_10;
  fVar6 = (fVar2 - fVar1) + local_10 * DAT_0059e440;
  fVar9 = ((fVar1 + fVar1) - fVar2) - local_10;
  param_1[4] = (int)((*pfVar11 * fVar9 +
                     *(float *)((iVar12 + 1) * 0x1c + iVar5) * fVar7 +
                     *(float *)((iVar12 + 2) * 0x1c + iVar5) * fVar8 +
                     *(float *)((iVar12 + 3) * 0x1c + iVar5) * fVar6) * _DAT_0059e450);
  param_1[5] = (int)((pfVar11[8] * fVar7 +
                     pfVar11[0xf] * fVar8 + pfVar11[0x16] * fVar6 + pfVar11[1] * fVar9) *
                    _DAT_0059e450);
  fVar1 = pfVar11[2];
  fVar2 = pfVar11[0x17];
  fVar3 = pfVar11[0x10];
  fVar4 = pfVar11[9];
  param_1[3] = (int)param_2;
  param_1[6] = (int)((fVar4 * fVar7 + fVar3 * fVar8 + fVar2 * fVar6 + fVar1 * fVar9) * _DAT_0059e450
                    );
  return;
}


