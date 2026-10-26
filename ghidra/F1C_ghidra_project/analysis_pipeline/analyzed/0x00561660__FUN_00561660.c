// Function: FUN_00561660 @ 00561660
// Size (bytes): 725


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00561660(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float *pfVar15;
  float *pfVar16;
  int iVar17;
  float10 fVar18;
  int local_30;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)(param_1 + 0x18);
  pfVar1 = (float *)(iVar3 + 0xe8);
  fVar12 = *(float *)(iVar3 + 0x18) * _DAT_0059e5fc;
  for (iVar4 = *(int *)(param_2 + 0x204); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
    if ((*(uint *)(iVar4 + 0x14) & 0x4000) != 0) {
      iVar17 = *(int *)(param_1 + 0xc);
      fVar5 = *(float *)(iVar17 + 0xc);
      fVar6 = *(float *)(iVar17 + 0x14);
      fVar13 = _DAT_0059e43c / (float)*(int *)(iVar17 + 0x54);
      fVar14 = _DAT_0059e43c / (float)*(int *)(iVar17 + 0x58);
      fVar2 = *(float *)(iVar17 + 0x10);
      fVar7 = *(float *)(iVar17 + 0x18);
      fVar8 = *(float *)(iVar4 + 0xe4) - *(float *)(iVar3 + 0xf0);
      fVar11 = *(float *)(iVar4 + 0xe0) - *(float *)(iVar3 + 0xec);
      fVar10 = *(float *)(iVar4 + 0xdc) - *pfVar1;
      fVar9 = fVar12 + *(float *)(iVar4 + 0x18);
      if (fVar8 * fVar8 + fVar11 * fVar11 + fVar10 * fVar10 <= fVar9 * fVar9) {
        param_2 = *(int *)(iVar4 + 0x124);
        local_30 = 0;
        if (0 < *(int *)(iVar4 + 0x120)) {
          pfVar15 = (float *)(param_2 + 0x14);
          do {
            fVar8 = pfVar15[1] - *(float *)(iVar3 + 0xf0);
            fVar10 = *pfVar15 - *(float *)(iVar3 + 0xec);
            fVar9 = fVar12 + pfVar15[2];
            if ((pfVar15[-1] - *pfVar1) * (pfVar15[-1] - *pfVar1) + fVar10 * fVar10 + fVar8 * fVar8
                <= fVar9 * fVar9) {
              fVar8 = pfVar15[-3];
              pfVar16 = (float *)((int)pfVar15[-2] * 0x10 + *(int *)(iVar4 + 300));
              fVar18 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(pfVar1,pfVar16);
              if ((((float10)pfVar15[3] < fVar18) &&
                  (iVar17 = *(int *)(param_1 + 0xc),
                  DAT_0059e440 <
                  (pfVar15[-1] - *(float *)(iVar17 + 0x24)) * *pfVar16 +
                  (*pfVar15 - *(float *)(iVar17 + 0x28)) * pfVar16[1] +
                  (pfVar15[1] - *(float *)(iVar17 + 0x2c)) * pfVar16[2])) &&
                 (*(int *)(param_1 + 4) < 0x7fd)) {
                iVar17 = **(int **)(param_1 + 0x20);
                if (iVar17 < 0x3ff) {
                  *(int *)((*(int **)(param_1 + 0x20))[1] + iVar17 * 4) = param_2;
                  **(int **)(param_1 + 0x20) = **(int **)(param_1 + 0x20) + 1;
                  iVar17 = 0;
                  do {
                    pfVar16 = (float *)((uint)*(ushort *)(param_2 + iVar17 * 2) * 0x30 +
                                       *(int *)((int)fVar8 + 0xc));
                    **(float **)(param_1 + 8) = pfVar16[3] * _DAT_0059e448 + *pfVar16;
                    *(float *)(*(int *)(param_1 + 8) + 4) = pfVar16[4] * _DAT_0059e448 + pfVar16[1];
                    *(float *)(*(int *)(param_1 + 8) + 8) = pfVar16[5] * _DAT_0059e448 + pfVar16[2];
                    *(float *)(*(int *)(param_1 + 8) + 0xc) = pfVar16[6];
                    (**(code **)(*DAT_008b8f24 + 4))
                              (DAT_008b8f24,pfVar16,&fStack_c,*(int *)(param_1 + 0xc) + 0x15c);
                    fVar9 = _DAT_0059e43c / fStack_4;
                    *(float *)(*(int *)(param_1 + 8) + 0x10) =
                         (fStack_c * fVar9 * fVar5 + fVar6) * fVar13;
                    *(float *)(*(int *)(param_1 + 8) + 0x14) =
                         (fStack_8 * fVar9 * -fVar2 + fVar7) * fVar14;
                    iVar17 = iVar17 + 1;
                    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x18;
                  } while (iVar17 < 3);
                  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 3;
                }
              }
            }
            param_2 = param_2 + 0x24;
            pfVar15 = pfVar15 + 9;
            local_30 = local_30 + 1;
          } while (local_30 < *(int *)(iVar4 + 0x120));
        }
      }
    }
  }
  return;
}


