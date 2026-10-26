// Function: FUN_004ca2d0 @ 004ca2d0
// Size (bytes): 260


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ca2d0(int param_1,float param_2,float *param_3,float param_4)

{
  undefined4 *puVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  
  fVar3 = *(float *)(param_1 + 4) - *param_3;
  fVar5 = *(float *)(param_1 + 8) - param_3[1];
  fVar4 = *(float *)(param_1 + 0xc) - param_3[2];
  param_4 = param_4 + *(float *)(param_1 + 0x10);
  if (fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4 <= param_4 * param_4) {
    fVar11 = (float10)param_2 + (float10)*(float *)(param_1 + 0x14);
    iVar9 = 0;
    *(float *)(param_1 + 0x14) = (float)fVar11;
    fVar12 = ((float10)_DAT_008afee4 * (float10)_DAT_005ace98 + (float10)*(float *)(param_1 + 0x18))
             * (float10)*(float *)(param_1 + 0x1c);
    fVar11 = fVar11 * (float10)*(float *)(param_1 + 0x20);
    fVar13 = (float10)fsin(fVar11);
    fVar11 = (float10)fcos(fVar11);
    fVar3 = *(float *)(param_1 + 0x2c);
    fVar4 = *(float *)(param_1 + 0x24);
    fVar5 = *(float *)(param_1 + 0x30);
    fVar6 = *(float *)(param_1 + 0x28);
    if (0 < *(int *)(param_1 + 0x34)) {
      iVar10 = 0;
      do {
        iVar7 = *(int *)(param_1 + 0x38);
        pfVar2 = (float *)(iVar7 + 0x10 + iVar10);
        puVar1 = (undefined4 *)(iVar7 + iVar10);
        piVar8 = (int *)(iVar7 + iVar10);
        iVar9 = iVar9 + 1;
        iVar10 = iVar10 + 0x14;
        *(float *)*puVar1 =
             (float)(((float10)(float)fVar13 * (float10)fVar4 + fVar11 * (float10)fVar3) * fVar12) *
             *pfVar2 + (float)piVar8[1];
        *(float *)(*piVar8 + 4) = (float)piVar8[4] * DAT_0059e440 + (float)piVar8[2];
        *(float *)(*piVar8 + 8) =
             (float)(((float10)(float)fVar13 * (float10)fVar6 + fVar11 * (float10)fVar5) * fVar12) *
             (float)piVar8[4] + (float)piVar8[3];
      } while (iVar9 < *(int *)(param_1 + 0x34));
    }
    iVar9 = FUN_0054c230(0);
    if (iVar9 != 0) {
      *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) & 0xfeffffdf;
    }
  }
  return;
}


