// Function: FUN_004ce110 @ 004ce110
// Size (bytes): 613


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ce110(int param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  float *pfVar11;
  float *pfVar12;
  int local_48;
  float local_1c [4];
  float local_c;
  float local_8;
  int local_4;
  
  pfVar11 = param_4;
  iVar7 = param_2;
  cVar8 = FUN_004b9fb0();
  if (cVar8 != '\0') {
    pfVar12 = (float *)(param_2 + 0x48);
    local_1c[0] = *param_3;
    fVar2 = *param_3 - *pfVar12;
    local_1c[1] = param_3[1];
    local_1c[2] = param_3[2];
    fVar3 = param_3[1] - *(float *)(param_2 + 0x4c);
    fVar4 = param_3[2] - *(float *)(param_2 + 0x50);
    fVar5 = fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4;
    if (_DAT_005acec8 < fVar5) {
      pfVar1 = param_4 + 1;
      param_2 = 0xffffff;
      param_4 = (float *)0xffffff;
      local_48 = 0xffffff;
      local_4 = 0xffffff;
      fVar6 = (_DAT_0059e43c / SQRT(fVar5)) * *(float *)(iVar7 + 0x18);
      local_1c[3] = (fVar4 * *pfVar1 - fVar3 * pfVar11[2]) * fVar6;
      local_c = (fVar2 * pfVar11[2] - fVar4 * *pfVar11) * fVar6;
      local_8 = (fVar3 * *pfVar11 - fVar2 * pfVar11[1]) * fVar6;
      if ((fVar5 < _DAT_0059e920) && (param_3 = (float *)0x0, 0 < *(int *)(param_1 + 0x3c))) {
        piVar10 = (int *)(param_1 + 0x40);
        do {
          iVar9 = *(int *)(*piVar10 + 4);
          if (iVar9 == 6) {
            iVar9 = *(int *)(iVar7 + 100);
            local_4 = (int)ROUND(*(float *)(iVar7 + 0x1c) * _DAT_005acec4) * 0x1000000 + 0xffffff;
            param_2 = local_4;
LAB_004ce308:
            *(int *)(iVar7 + 0x60) = iVar9;
joined_r0x004ce2d3:
            if ((iVar9 != 0xffffff) || (local_4 != 0xffffff)) {
              FUN_004cd6c0(pfVar12,local_1c);
            }
          }
          else {
            if (iVar9 == 7) {
              iVar9 = *(int *)(iVar7 + 0x68);
              local_4 = (int)ROUND(*(float *)(iVar7 + 0x20) * _DAT_005acec4) * 0x1000000 + 0xffffff;
              *(int *)(iVar7 + 0x60) = iVar9;
              param_4 = (float *)local_4;
              goto joined_r0x004ce2d3;
            }
            if (iVar9 == 8) {
              iVar9 = *(int *)(iVar7 + 0x6c);
              local_4 = (int)ROUND(*(float *)(iVar7 + 0x24) * _DAT_005acebc) * 0x1000000 + 0xffffff;
              local_48 = local_4;
              goto LAB_004ce308;
            }
          }
          param_3 = (float *)((int)param_3 + 1);
          piVar10 = piVar10 + 1;
        } while ((int)param_3 < *(int *)(param_1 + 0x3c));
      }
      pfVar11 = local_1c;
      for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
        *pfVar12 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        pfVar12 = pfVar12 + 1;
      }
      *(int *)(iVar7 + 100) = param_2;
      *(float **)(iVar7 + 0x68) = param_4;
      *(int *)(iVar7 + 0x6c) = local_48;
      return;
    }
  }
  return;
}


