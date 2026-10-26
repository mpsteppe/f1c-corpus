// Function: FUN_004fbd70 @ 004fbd70
// Size (bytes): 1024


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fbd70(int *param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_28;
  float local_24;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1[0x11] == DAT_007c56a4) {
    param_1[0x11] = -1;
    FUN_004fc550(0);
  }
  FUN_0040c910();
  FUN_00542460(&local_c,&local_8,&local_4);
  if (*param_1 != 0) {
    FUN_0054b3b0((float)param_1[1] - local_c * _DAT_007cf950,param_1[2],
                 (float)param_1[3] - local_4 * _DAT_007cf950);
  }
  pfVar8 = (float *)(param_1 + 6);
  iVar9 = 3;
  do {
    if (pfVar8[-2] != 0.0) {
      FUN_0054b3b0(pfVar8[-1],*pfVar8 - local_8,pfVar8[1]);
    }
    pfVar8 = pfVar8 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  bVar1 = _DAT_008afec8 != (float)param_1[0x2e];
  if (bVar1) {
    param_1[0x2e] = (int)_DAT_008afec8;
  }
  local_28 = 0;
  if (0 < param_1[0x12]) {
    do {
      if ((param_1[0x1c] != 0) &&
         (((float)param_1[0x1d] != DAT_0059e440 || ((float)param_1[0x1e] != DAT_0059e440)))) {
        FUN_0054bf60(param_1[0x1c],0,(float)_DAT_008afe98 * (float)param_1[0x1d],
                     (float)_DAT_008afe98 * (float)param_1[0x1e]);
      }
      iVar9 = FUN_0054c230(0);
      if ((bVar1) && (iVar9 != 0)) {
        iVar5 = __ftol();
        uVar6 = iVar5 << 0x18;
        FUN_0054c030(uVar6 != 0,uVar6 != 0,1,0);
        iVar5 = FUN_0054e100();
        iVar10 = 0;
        if (0 < iVar5) {
          do {
            iVar7 = FUN_0054e120(iVar10);
            *(undefined1 *)(iVar7 + 0x1b) = 0;
            iVar10 = iVar10 + 1;
            *(uint *)(iVar7 + 0x18) = *(uint *)(iVar7 + 0x18) | uVar6;
          } while (iVar10 < iVar5);
        }
        FUN_0054b3f0(0,0,0);
        *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) & 0xefffffff;
      }
      local_28 = local_28 + 1;
    } while (local_28 < param_1[0x12]);
  }
  local_28 = 0;
  if (0 < param_1[0x1f]) {
    do {
      if ((param_1[0x29] != 0) &&
         (((float)param_1[0x2a] != DAT_0059e440 || ((float)param_1[0x2b] != DAT_0059e440)))) {
        FUN_0054bf60(param_1[0x29],0,(float)_DAT_008afe98 * (float)param_1[0x2a],
                     (float)_DAT_008afe98 * (float)param_1[0x2b]);
      }
      if ((float)param_1[0x2c] < (float)param_1[0x2d]) {
        fVar2 = _DAT_0059e43c / ((float)param_1[0x2d] - (float)param_1[0x2c]);
        iVar9 = FUN_0054c230(0);
        if ((bVar1) && (iVar9 != 0)) {
          if (DAT_007cf938 == '\0') {
            local_24 = _DAT_008afec8;
            fVar3 = _DAT_008afec8;
          }
          else {
            local_24 = (_DAT_008afec8 + _DAT_008afec8) - _DAT_0059e43c;
            fVar3 = _DAT_008afec8 + _DAT_008afec8;
          }
          if ((fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440)) ||
             (local_24 < DAT_0059e440 == (local_24 == DAT_0059e440))) {
            uVar12 = 1;
            uVar11 = 1;
          }
          else {
            uVar12 = 0;
            uVar11 = 0;
          }
          FUN_0054c030(uVar11,uVar12,1,0);
          iVar5 = FUN_0054e100();
          iVar10 = 0;
          if (0 < iVar5) {
            do {
              pfVar8 = (float *)FUN_0054e120(iVar10);
              fVar4 = (*pfVar8 - (float)param_1[0x2c]) * fVar2 * (fVar3 - local_24) + local_24;
              if (fVar4 <= _DAT_0059e43c) {
                if (DAT_0059e440 <= fVar4) {
                  iVar7 = __ftol();
                }
                else {
                  iVar7 = 0;
                }
              }
              else {
                iVar7 = 0xfe;
              }
              *(undefined1 *)((int)pfVar8 + 0x1b) = 0;
              iVar10 = iVar10 + 1;
              pfVar8[6] = (float)((uint)pfVar8[6] | iVar7 << 0x18);
            } while (iVar10 < iVar5);
          }
          FUN_0054b3f0(0,0,0);
          *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) & 0xefffffff;
        }
      }
      local_28 = local_28 + 1;
    } while (local_28 < param_1[0x1f]);
  }
  return;
}


