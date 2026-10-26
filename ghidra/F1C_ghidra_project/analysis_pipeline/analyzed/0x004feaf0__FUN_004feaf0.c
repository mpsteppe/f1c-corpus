// Function: FUN_004feaf0 @ 004feaf0
// Size (bytes): 1231


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004feaf0(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int local_b58;
  float local_b54;
  float local_b50;
  float local_b4c;
  float local_b48;
  float afStack_b40 [720];
  
  if (param_1[0xf] != 0.0) {
    FUN_004fde00(*(undefined4 *)((int)param_1[0xf] + 8));
    param_1[0xe] = param_1[0xf];
    param_1[1] = 0.0;
    uVar2 = DAT_005c329c;
    uVar13 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    bVar5 = false;
    fVar1 = *(float *)(&DAT_008ab274 + uVar13 * 4) * _DAT_0059e4e0 + _DAT_005acd94;
    local_b50 = 0.0;
    do {
      fVar4 = param_1[9] - fVar1;
      afStack_b40[(int)local_b50] = fVar4;
      if (DAT_0059e440 < fVar4) {
        bVar5 = true;
      }
      FUN_004fdeb0(*param_1 * _DAT_0059e5fc,
                   ((float)(int)local_b50 * _DAT_0059e5fc + _DAT_0059e5fc) * *param_1,uVar2);
      local_b50 = (float)((int)local_b50 + 1);
    } while ((int)local_b50 < 0x2d0);
    if (bVar5) {
      local_b4c = 0.0;
      uVar13 = DAT_008aae70;
      do {
        local_b50 = 0.0;
        local_b48 = 3.4028235e+38;
        local_b58 = 0;
        do {
          if (DAT_0059e440 < afStack_b40[local_b58]) {
            fVar1 = ABS(local_b4c - (float)local_b58 * _DAT_0059e5fc);
            if ((fVar1 == DAT_0059e440) ||
               ((fVar4 = afStack_b40[local_b58] / fVar1, fVar6 = DAT_0059e440, DAT_0059e440 <= fVar4
                && (fVar6 = fVar4, _DAT_005acd3c < fVar4)))) {
              fVar6 = _DAT_005acd3c;
            }
            if (local_b50 < fVar6) {
              local_b50 = fVar6;
            }
            if (fVar1 < local_b48) {
              local_b48 = fVar1;
            }
          }
          local_b58 = local_b58 + 1;
        } while (local_b58 < 0x2d0);
        DAT_008aae70 = uVar13;
        if ((DAT_0059e440 < local_b50) && (local_b48 < _DAT_0059e80c)) {
          local_b48 = local_b48 * _DAT_0059ef64;
          DAT_008aae70 = uVar13 + 1;
          if (*(float *)(&DAT_008aae74 + (uVar13 & 0xff) * 4) <
              _DAT_005ad144 - local_b48 * _DAT_0059e454) {
            uVar14 = DAT_008aae70 & 0xff;
            DAT_008aae70 = uVar13 + 2;
            local_b54 = ((local_b50 * _DAT_0059e470 * _DAT_0059e7f8 + _DAT_0059e8cc) -
                        local_b48 * _DAT_0059e8b4) -
                        *(float *)(&DAT_008aae74 + uVar14 * 4) * _DAT_0059e458;
            if (DAT_0059e440 < local_b54) {
              if (_DAT_0059e43c < local_b54) {
                local_b54 = 1.0;
              }
              uVar14 = DAT_008aae70 & 0xff;
              DAT_008aae70 = uVar13 + 3;
              fVar1 = local_b48 * _DAT_0059e450;
              if (*(float *)(&DAT_008aae74 + uVar14 * 4) < _DAT_007cf8cc - fVar1) {
                pfVar7 = operator_new(0xc);
                *pfVar7 = local_b4c;
                pfVar7[1] = 1.4013e-45;
                pfVar7[2] = local_b54;
                puVar8 = operator_new(0xc);
                if (puVar8 == (undefined4 *)0x0) {
                  puVar8 = (undefined4 *)0x0;
                }
                else {
                  *puVar8 = pfVar7;
                  puVar8[1] = 0;
                  *(undefined1 *)(puVar8 + 2) = 1;
                }
                if (param_1[0x15] == 0.0) {
                  param_1[0x15] = (float)puVar8;
                  param_1[0x17] = (float)puVar8;
                }
                else {
                  *(undefined4 **)((int)param_1[0x16] + 4) = puVar8;
                }
                param_1[0x16] = (float)puVar8;
                param_1[0x18] = (float)((int)param_1[0x18] + 1);
              }
              uVar13 = DAT_008aae70 & 0xff;
              DAT_008aae70 = DAT_008aae70 + 1;
              if (*(float *)(&DAT_008aae74 + uVar13 * 4) < _DAT_007cf8f0 - fVar1) {
                pfVar7 = operator_new(0xc);
                fVar1 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
                DAT_008aae70 = DAT_008aae70 + 1;
                fVar4 = local_b48 + _DAT_0059e43c;
                pfVar7[1] = 0.0;
                pfVar7[2] = local_b54;
                *pfVar7 = local_b48 * _DAT_0059e940 + fVar4 * fVar1 + local_b4c;
                puVar8 = operator_new(0xc);
                if (puVar8 == (undefined4 *)0x0) {
                  puVar8 = (undefined4 *)0x0;
                }
                else {
                  *puVar8 = pfVar7;
                  puVar8[1] = 0;
                  *(undefined1 *)(puVar8 + 2) = 1;
                }
                if (param_1[0x15] == 0.0) {
                  param_1[0x15] = (float)puVar8;
                  param_1[0x17] = (float)puVar8;
                }
                else {
                  *(undefined4 **)((int)param_1[0x16] + 4) = puVar8;
                }
                param_1[0x16] = (float)puVar8;
                param_1[0x18] = (float)((int)param_1[0x18] + 1);
              }
            }
          }
        }
        uVar13 = DAT_008aae70 + 1;
        local_b4c = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4) +
                    *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4) + _DAT_0059e800 +
                    local_b4c;
      } while (local_b4c < _DAT_005acb3c);
      puVar8 = (undefined4 *)param_1[0x15];
      iVar9 = 0;
      puVar11 = puVar8;
      DAT_008aae70 = uVar13;
      if (puVar8 != (undefined4 *)0x0) {
        do {
          puVar11 = (undefined4 *)puVar11[1];
          iVar9 = iVar9 + 1;
        } while (puVar11 != (undefined4 *)0x0);
        if (1 < iVar9) {
          iVar9 = iVar9 / 2 + -1;
          puVar11 = puVar8;
          if (0 < iVar9) {
            do {
              iVar9 = iVar9 + -1;
              puVar11 = (undefined4 *)puVar11[1];
            } while (iVar9 != 0);
          }
          uVar2 = puVar11[1];
          puVar11[1] = 0;
          puVar10 = (undefined4 *)FUN_004ff2b0(puVar8);
          puVar11 = (undefined4 *)FUN_004ff2b0(uVar2);
          puVar8 = puVar11;
          if ((puVar10 != (undefined4 *)0x0) && (puVar8 = puVar10, puVar11 != (undefined4 *)0x0)) {
            if (*(float *)*puVar11 <= *(float *)*puVar10) {
              puVar3 = (undefined4 *)puVar11[1];
              puVar15 = puVar10;
              puVar10 = puVar11;
            }
            else {
              puVar3 = puVar11;
              puVar15 = (undefined4 *)puVar10[1];
              puVar11 = puVar10;
            }
            while (puVar8 = puVar10, puVar15 != (undefined4 *)0x0) {
              if (puVar3 == (undefined4 *)0x0) {
                if (puVar15 == (undefined4 *)0x0) goto LAB_004fef8d;
                puVar11[1] = puVar15;
                goto LAB_004fef96;
              }
              if (*(float *)*puVar3 <= *(float *)*puVar15) {
                puVar8 = (undefined4 *)puVar3[1];
                puVar12 = puVar3;
              }
              else {
                puVar12 = puVar15;
                puVar8 = puVar3;
                puVar15 = (undefined4 *)puVar15[1];
              }
              puVar11[1] = puVar12;
              puVar3 = puVar8;
              puVar11 = puVar12;
            }
            if (puVar3 == (undefined4 *)0x0) {
LAB_004fef8d:
              puVar11[1] = 0;
            }
            else {
              puVar11[1] = puVar3;
            }
          }
        }
      }
LAB_004fef96:
      param_1[0x15] = (float)puVar8;
      puVar11 = puVar8;
      if (puVar8 != (undefined4 *)0x0) {
        puVar10 = (undefined4 *)puVar8[1];
        while (puVar3 = puVar10, puVar3 != (undefined4 *)0x0) {
          puVar11 = puVar3;
          puVar10 = (undefined4 *)puVar3[1];
        }
      }
      param_1[0x16] = (float)puVar11;
      param_1[0x17] = (float)puVar8;
    }
  }
  return;
}


