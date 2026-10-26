// Function: FUN_00401c90 @ 00401c90
// Size (bytes): 1416


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00401c90(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  int local_8;
  int local_4;
  
  FUN_00401910(param_2);
  iVar8 = 0;
  FUN_00401340(0);
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      iVar7 = *(int *)(param_1 + 0x134);
      fVar10 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar7 + 0x74 + iVar8),iVar7 + iVar8 + 0x78,
                                     *(undefined4 *)(iVar7 + 0x70 + iVar8),0x41800000);
      *(float *)(iVar7 + iVar8 + 0x88) = (float)fVar10;
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 0x13c;
    } while (iVar9 < *(int *)(param_1 + 0x130));
  }
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    local_4 = 0;
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x134) + 0x10c + local_4);
      iVar8 = *(int *)(param_1 + 0x134) + local_4;
      while ((iVar7 = iVar9, iVar7 != 0 && (*(int *)(iVar7 + 0x110) == iVar8))) {
        fVar10 = (float10)FUN_004e9100(*(undefined4 *)(iVar8 + 0x88),*(undefined4 *)(iVar7 + 0x74),
                                       iVar7 + 0x78,*(undefined4 *)(iVar7 + 0x70));
        if (*(float *)(iVar8 + 0x88) < DAT_0059e440 != (*(float *)(iVar8 + 0x88) == DAT_0059e440))
        break;
        fVar11 = (float10)*(float *)(iVar8 + 0x94) - (float10)*(float *)(iVar7 + 0x94);
        fVar12 = (float10)*(float *)(iVar8 + 0x98) - (float10)*(float *)(iVar7 + 0x98);
        fVar13 = (float10)*(float *)(iVar8 + 0x9c) - (float10)*(float *)(iVar7 + 0x9c);
        fVar11 = SQRT(fVar11 * fVar11 + fVar12 * fVar12 + fVar13 * fVar13);
        fVar10 = (fVar11 / (float10)*(float *)(iVar8 + 0x88)) * fVar10 * (float10)_DAT_0059e450 +
                 (float10)*(float *)(iVar8 + 0x88);
        if (fVar10 < (float10)DAT_0059e440 != (fVar10 == (float10)DAT_0059e440)) break;
        fVar12 = (float10)FUN_004e9100((float)fVar10,*(undefined4 *)(iVar7 + 0x74),iVar7 + 0x78,
                                       *(undefined4 *)(iVar7 + 0x70));
        fVar10 = ((float10)(float)fVar11 / (float10)(float)fVar10) * fVar12 +
                 (float10)*(float *)(iVar8 + 0x88);
        if ((float10)*(float *)(iVar7 + 0x88) < fVar10) break;
        if (fVar10 < (float10)DAT_0059e440) {
          fVar10 = (float10)DAT_0059e440;
        }
        *(float *)(iVar7 + 0x88) = (float)fVar10;
        iVar8 = iVar7;
        iVar9 = *(int *)(iVar7 + 0x10c);
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 0x13c;
    } while (local_8 < *(int *)(param_1 + 0x130));
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    iVar9 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x134) + iVar9 + 0x8c) =
           *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x88 + iVar9);
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x13c;
    } while (iVar8 < *(int *)(param_1 + 0x130));
  }
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    local_4 = 0;
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x134) + 0x110 + local_4);
      iVar8 = *(int *)(param_1 + 0x134) + local_4;
      while ((iVar7 = iVar9, iVar7 != 0 && (*(int *)(iVar7 + 0x10c) == iVar8))) {
        fVar10 = (float10)FUN_004e9300(*(undefined4 *)(iVar8 + 0x8c),*(undefined4 *)(iVar8 + 0x74),
                                       iVar8 + 0x78,*(undefined4 *)(iVar8 + 0x70));
        if (*(float *)(iVar8 + 0x8c) < DAT_0059e440 != (*(float *)(iVar8 + 0x8c) == DAT_0059e440))
        break;
        fVar11 = (float10)*(float *)(iVar7 + 0x94) - (float10)*(float *)(iVar8 + 0x94);
        fVar12 = (float10)*(float *)(iVar7 + 0x98) - (float10)*(float *)(iVar8 + 0x98);
        fVar13 = (float10)*(float *)(iVar7 + 0x9c) - (float10)*(float *)(iVar8 + 0x9c);
        fVar11 = SQRT(fVar11 * fVar11 + fVar12 * fVar12 + fVar13 * fVar13);
        fVar10 = (fVar11 / (float10)*(float *)(iVar8 + 0x8c)) * fVar10 * (float10)_DAT_0059e450 +
                 (float10)*(float *)(iVar8 + 0x8c);
        if (fVar10 < (float10)DAT_0059e440 != (fVar10 == (float10)DAT_0059e440)) break;
        fVar12 = (float10)FUN_004e9300((float)fVar10,*(undefined4 *)(iVar8 + 0x74),iVar8 + 0x78,
                                       *(undefined4 *)(iVar8 + 0x70));
        fVar10 = ((float10)(float)fVar11 / (float10)(float)fVar10) * fVar12 +
                 (float10)*(float *)(iVar8 + 0x8c);
        if ((float10)*(float *)(iVar7 + 0x8c) <= fVar10) break;
        if (fVar10 < (float10)DAT_0059e440) {
          fVar10 = (float10)DAT_0059e440;
        }
        *(float *)(iVar7 + 0x8c) = (float)fVar10;
        iVar8 = iVar7;
        iVar9 = *(int *)(iVar7 + 0x110);
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 0x13c;
    } while (local_8 < *(int *)(param_1 + 0x130));
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    iVar9 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x90 + iVar9) = 0xbf800000;
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x13c;
    } while (iVar8 < *(int *)(param_1 + 0x130));
  }
  iVar8 = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    iVar9 = 0;
    do {
      for (iVar7 = *(int *)(param_1 + 0x134) + iVar9;
          ((iVar7 != 0 && (iVar2 = *(int *)(iVar7 + 0x10c), iVar2 != 0)) &&
          (*(float *)(iVar7 + 0x90) < DAT_0059e440)); iVar7 = *(int *)(iVar7 + 0x110)) {
        if (*(float *)(iVar2 + 0x48) <= *(float *)(iVar7 + 0x48)) {
          if (*(float *)(iVar2 + 0x90) < DAT_0059e440) break;
          fVar1 = *(float *)(iVar2 + 0x90);
          *(float *)(iVar7 + 0x90) = fVar1;
          fVar3 = (*(float *)(iVar2 + 0x8c) + *(float *)(iVar7 + 0x8c)) * _DAT_0059e450;
          if (DAT_0059e440 < fVar3) {
            fVar6 = *(float *)(iVar7 + 0x94) - *(float *)(iVar2 + 0x94);
            fVar5 = *(float *)(iVar7 + 0x98) - *(float *)(iVar2 + 0x98);
            fVar4 = *(float *)(iVar7 + 0x9c) - *(float *)(iVar2 + 0x9c);
            *(float *)(iVar7 + 0x90) =
                 SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4) / fVar3 + fVar1;
          }
          if ((*(int *)(iVar7 + 300) == 0) &&
             (*(float *)(param_1 + 0x148) < *(float *)(iVar7 + 0x90))) {
            *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(iVar7 + 0x90);
          }
        }
        else {
          fVar1 = (*(float *)(iVar2 + 0x8c) + *(float *)(iVar7 + 0x8c)) * _DAT_0059e450;
          if (fVar1 <= DAT_0059e440) {
            *(undefined4 *)(iVar7 + 0x90) = 0;
          }
          else {
            *(float *)(iVar7 + 0x90) = *(float *)(iVar7 + 0x48) / fVar1;
          }
        }
      }
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x13c;
    } while (iVar8 < *(int *)(param_1 + 0x130));
  }
  iVar8 = 0;
  fVar1 = _DAT_0059e43c - (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004fb260(fVar1);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x130));
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004faf60();
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x130));
  }
  return;
}


