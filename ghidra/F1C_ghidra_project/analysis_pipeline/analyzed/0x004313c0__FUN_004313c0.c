// Function: FUN_004313c0 @ 004313c0
// Size (bytes): 1060


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004313c0(int param_1)

{
  double dVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  float10 fVar12;
  float10 fVar13;
  double local_390;
  double *local_384;
  double local_380;
  double adStack_378 [44];
  double local_218 [11];
  double adStack_1c0 [44];
  double local_60 [11];
  
  dVar1 = (double)((*(float *)(param_1 + 0x1cac) - (float)_DAT_0059e880) * (float)_DAT_0059e880 +
                  *(float *)(param_1 + 0x1ca8));
  FUN_0042e290(dVar1);
  FUN_0042e290(dVar1);
  FUN_0042e290(dVar1);
  FUN_0042e290((double)(((float)_DAT_0059e880 - *(float *)(param_1 + 0x1cac)) * (float)_DAT_0059e880
                       + *(float *)(param_1 + 0x1ca8)));
  FUN_0042e290((double)*(float *)(param_1 + 0x1cac));
  FUN_0042e290((double)((((float)_DAT_0059e420 - *(float *)(param_1 + 0x1cac)) +
                        *(float *)(param_1 + 0x1cb0)) * (float)_DAT_0059e880));
  FUN_0042e290((double)((*(float *)(param_1 + 0x1cb0) + *(float *)(param_1 + 0x1cac)) *
                       (float)_DAT_0059e880));
  iVar6 = 4;
  do {
    FUN_0042e290((double)*(float *)(param_1 + 0x1cb0));
    FUN_0042e290((double)*(float *)(param_1 + 0x1cb0));
    FUN_0042e290((double)*(float *)(param_1 + 0x1cb0));
    FUN_0042e290((double)*(float *)(param_1 + 0x1cb0));
    FUN_0042e290((double)*(float *)(param_1 + 0x1cb0));
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 0x2c;
  *(undefined4 *)(param_1 + 0x1644) = *(undefined4 *)(param_1 + 0x1648);
  local_384 = (double *)0x2c;
  iVar10 = 0x2c;
  puVar7 = (undefined4 *)(param_1 + 0x16c4);
  do {
    *puVar7 = puVar7[1];
    fVar12 = (float10)FUN_0042ed00();
    adStack_1c0[iVar10] = (double)fVar12;
    if (*(char *)(puVar7 + 2) != '\0') {
      iVar6 = iVar10;
      local_384 = (double *)iVar10;
    }
    iVar10 = iVar10 + 1;
    puVar7 = puVar7 + 0x10;
  } while (iVar10 < 0x33);
  *(undefined4 *)(param_1 + 0x1644) = 0;
  *(undefined4 *)(param_1 + 0x16c4) = 0;
  fVar12 = (float10)FUN_0042ed00();
  *(int *)(param_1 + 0x1644) = *(int *)(param_1 + 0x1640) + -1;
  *(int *)(iVar6 * 0x40 + 0xbc4 + param_1) = *(int *)((iVar6 + 0x2f) * 0x40 + param_1) + -1;
  if (*(float *)(param_1 + 0x1cb4) < (float)_DAT_0059e880) {
    fVar13 = (float10)*(float *)(param_1 + 0x1cb4) + (float10)*(float *)(param_1 + 0x1cb4);
    fVar13 = ((float10)_DAT_0059e420 - fVar13) * (fVar12 / (float10)local_60[0]) + fVar13;
  }
  else {
    fVar2 = (*(float *)(param_1 + 0x1cb4) + *(float *)(param_1 + 0x1cb4)) - (float)_DAT_0059e420;
    fVar12 = (float10)FUN_0042ed00();
    fVar13 = ((float10)_DAT_0059e420 - (float10)fVar2) +
             (fVar12 / (float10)adStack_1c0[iVar6]) * (float10)fVar2;
  }
  iVar10 = 0;
  iVar6 = 0;
  do {
    iVar3 = iVar6 + 8;
    *(double *)((int)local_218 + iVar6) =
         (double)(fVar13 * (float10)*(double *)((int)local_60 + iVar6));
    iVar6 = iVar3;
  } while (iVar3 < 0x31);
  iVar6 = *(int *)(param_1 + 0x1648);
  local_390 = 1.7976931348623157e+308;
  if (0 < *(int *)(param_1 + 0x1640)) {
    uVar9 = -iVar6;
    do {
      local_380 = 0.0;
      *(int *)(param_1 + 0x1644) = iVar10;
      fVar12 = (float10)FUN_0042ed00();
      if (fVar12 < (float10)local_218[0]) {
        local_380 = (double)((float10)local_218[0] - fVar12);
      }
      fVar12 = (float10)FUN_0042ed00();
      if (((float10)adStack_378[(int)local_384] < fVar12) &&
         ((float10)local_380 < fVar12 - (float10)adStack_378[(int)local_384])) {
        local_380 = (double)(fVar12 - (float10)adStack_378[(int)local_384]);
      }
      if (local_380 == local_390) {
        uVar4 = iVar6 - *(int *)(param_1 + 0x1648);
        uVar5 = (int)uVar4 >> 0x1f;
        if ((int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)) <
            (int)((uVar4 ^ uVar5) - uVar5)) {
LAB_00431720:
          local_390 = local_380;
          iVar6 = iVar10;
        }
      }
      else if (local_380 < local_390) goto LAB_00431720;
      iVar10 = iVar10 + 1;
      uVar9 = uVar9 + 1;
    } while (iVar10 < *(int *)(param_1 + 0x1640));
  }
  local_384 = local_218;
  *(int *)(param_1 + 0x1644) = iVar6;
  iVar6 = 0x2c;
  piVar11 = (int *)(param_1 + 0x16c0);
  do {
    iVar10 = 0;
    iVar8 = 0;
    local_390 = 1.7976931348623157e+308;
    iVar3 = 0;
    if (0 < *piVar11) {
      do {
        iVar10 = iVar3;
        piVar11[1] = iVar8;
        fVar12 = (float10)FUN_0042ed00();
        if (ABS(fVar12 - (float10)*local_384) < (float10)local_390) {
          local_390 = (double)ABS(fVar12 - (float10)*local_384);
          iVar10 = iVar8;
        }
        iVar8 = iVar8 + 1;
        iVar3 = iVar10;
      } while (iVar8 < *piVar11);
    }
    piVar11[1] = iVar10;
    if ((0x2c < iVar6) && (iVar10 <= piVar11[-0xf])) {
      iVar10 = piVar11[-0xf] + 1;
      if (iVar10 < *piVar11) {
        piVar11[1] = iVar10;
      }
      else {
        piVar11[1] = *piVar11 + -1;
      }
    }
    iVar6 = iVar6 + 1;
    local_384 = local_384 + 1;
    piVar11 = piVar11 + 0x10;
  } while (iVar6 < 0x33);
  return;
}


