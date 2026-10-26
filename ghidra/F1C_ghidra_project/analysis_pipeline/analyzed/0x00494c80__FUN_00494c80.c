// Function: FUN_00494c80 @ 00494c80
// Size (bytes): 348


uint __fastcall FUN_00494c80(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  ushort uVar11;
  float *local_18;
  int local_14;
  int local_10;
  float local_8;
  float local_4;
  
  local_8 = (float)(*(int *)(param_1 + 0x1c) + -1);
  local_4 = (float)(*(int *)(param_1 + 0x20) + -1);
  local_10 = 0;
  do {
    if (local_10 == 0) {
      pfVar7 = param_2;
      pfVar8 = param_2 + 3;
    }
    else {
      pfVar7 = param_2 + 3;
      pfVar8 = param_2;
    }
    local_14 = 0;
    do {
      local_18 = pfVar8 + 1;
      if (local_14 == 0) {
        pfVar10 = &local_8;
        pfVar5 = pfVar7;
        pfVar6 = local_18;
        pfVar9 = pfVar7 + 1;
        local_18 = pfVar8;
      }
      else {
        pfVar5 = pfVar7 + 1;
        pfVar10 = &local_4;
        pfVar6 = pfVar8;
        pfVar9 = pfVar7;
      }
      if (DAT_0059e440 <= *pfVar5) {
        if (*pfVar10 < *pfVar5) {
          fVar1 = *pfVar10 - *pfVar5;
          fVar2 = *local_18 - *pfVar5;
          uVar11 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe;
          if (fVar2 >= fVar1) goto LAB_00494dc4;
          fVar3 = *pfVar6 - *pfVar9;
          *pfVar5 = *pfVar10;
          goto LAB_00494d63;
        }
      }
      else {
        fVar1 = -*pfVar5;
        fVar2 = *local_18 - *pfVar5;
        uVar11 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                 (ushort)(fVar2 == fVar1) << 0xe;
        if (fVar2 < fVar1) {
LAB_00494dc4:
          return (uint)uVar11;
        }
        fVar3 = *pfVar6 - *pfVar9;
        *pfVar5 = 0.0;
LAB_00494d63:
        *pfVar9 = (fVar3 / fVar2) * fVar1 + *pfVar9;
      }
      local_14 = local_14 + 1;
    } while (local_14 < 2);
    local_10 = local_10 + 1;
    if (1 < local_10) {
      fVar1 = *param_2 - param_2[3];
      uVar4 = (uint)(ushort)((ushort)(fVar1 < DAT_0059e440) << 8 |
                             (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                            (ushort)(fVar1 == DAT_0059e440) << 0xe);
      if (fVar1 == DAT_0059e440) {
        fVar1 = param_2[1] - param_2[4];
        uVar4 = (uint)(ushort)((ushort)(fVar1 < DAT_0059e440) << 8 |
                               (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                              (ushort)(fVar1 == DAT_0059e440) << 0xe);
        if (fVar1 == DAT_0059e440) {
          return uVar4;
        }
      }
      return CONCAT31((int3)(uVar4 >> 8),1);
    }
  } while( true );
}


