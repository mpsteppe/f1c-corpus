// Function: FUN_004cdb20 @ 004cdb20
// Size (bytes): 3461


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cdb20(int param_1)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  float10 fVar15;
  float10 fVar16;
  float fVar17;
  int in_stack_ffffff60;
  float *local_94;
  float *local_90;
  float local_8c;
  undefined4 **local_88;
  int local_70;
  int local_6c;
  float local_68;
  float *local_64;
  float local_60;
  float *local_5c;
  float *local_58;
  float local_54;
  float local_50;
  float *local_4c;
  float local_48;
  float local_44;
  float *local_40;
  float local_3c;
  float local_38;
  float local_34;
  float *local_30;
  float *local_2c;
  float local_18;
  float local_14;
  float *local_10;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    if (DAT_008ab6e4 == 2) {
      fVar16 = (float10)FUN_004b9ce0();
    }
    else {
      fVar16 = (float10)_DAT_008afea0;
    }
    fVar17 = (float)fVar16;
    local_6c = 0;
    if (0 < *(int *)(param_1 + 100)) {
      do {
        pfVar8 = *(float **)(*(int *)(param_1 + 0x68) + local_6c * 4);
        if ((pfVar8[3] < fVar17) || (fVar17 < pfVar8[2])) {
          local_8c = 7.050132e-39;
          local_88 = (undefined4 **)pfVar8;
          FUN_004cb5a0();
          local_6c = local_6c + -1;
        }
        else {
          fVar4 = fVar17 - pfVar8[2];
          local_54 = fVar4 * pfVar8[0xe] + pfVar8[0xb];
          local_50 = fVar4 * pfVar8[0xf] + pfVar8[0xc];
          local_4c = (float *)(fVar4 * pfVar8[0x10] + pfVar8[0xd]);
          fVar5 = fVar4 * pfVar8[0x1a];
          fVar1 = pfVar8[0x11];
          local_14 = fVar5 * *(float *)(param_1 + 0x1c);
          local_10 = (float *)(fVar5 * *(float *)(param_1 + 0x20));
          local_3c = fVar5 * *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0xc);
          local_38 = local_14 + *(float *)(param_1 + 0x10);
          local_34 = (float)local_10 + *(float *)(param_1 + 0x14);
          local_48 = local_54;
          local_44 = local_50;
          local_40 = local_4c;
          if (-1 < (int)fVar1) {
            if (DAT_007cf9ec == '\0') {
              if ((ABS((float)(&DAT_005ece1c)[(int)fVar1 * 0x1230] - local_54) < _DAT_005d3490) &&
                 (ABS((float)(&DAT_005ece24)[(int)fVar1 * 0x1230] - (float)local_4c) < _DAT_005d3490
                 )) {
                local_88 = (undefined4 **)&stack0xffffffdc;
                local_8c = local_38 * _DAT_0059e450;
                local_90 = pfVar8 + 0x15;
                local_94 = &local_48;
                FUN_004cbdd0();
              }
            }
            else {
              local_90 = (float *)((float)local_4c + local_54);
              local_88 = (undefined4 **)&local_68;
              local_8c = (float)_DAT_005d3494;
              local_94 = (float *)0x4cc309;
              iVar14 = FUN_004c9c70();
              iVar9 = 0;
              if (0 < (int)local_68) {
                do {
                  iVar3 = *(int *)(iVar14 + iVar9 * 4);
                  local_30 = *(float **)(iVar3 + 0x738);
                  local_2c = *(float **)(iVar3 + 0x73c);
                  if (((ABS((float)local_30 - local_48) < _DAT_005d3490) &&
                      (ABS(*(float *)(iVar3 + 0x740) - (float)local_40) < _DAT_005d3490)) &&
                     (pfVar8[0x11] != *(float *)(iVar3 + 4))) {
                    local_88 = &local_30;
                    local_8c = local_38 * _DAT_0059e450;
                    local_90 = pfVar8 + 0x15;
                    local_94 = &local_48;
                    FUN_004cbdd0();
                  }
                  iVar9 = iVar9 + 1;
                } while (iVar9 < (int)local_68);
              }
            }
          }
          local_88 = (undefined4 **)local_40;
          local_94 = (float *)*pfVar8;
          local_8c = local_44;
          local_90 = (float *)local_48;
          FUN_00558c60();
          local_88 = (undefined4 **)local_34;
          local_94 = (float *)*pfVar8;
          local_8c = local_38;
          local_90 = (float *)local_3c;
          FUN_00558cb0();
          if (fVar4 <= pfVar8[6]) {
            if (fVar4 <= pfVar8[5]) {
              pfVar13 = (float *)(int)ROUND(fVar4 * pfVar8[8] * pfVar8[10]);
              local_58 = pfVar13;
            }
            else {
              local_60 = pfVar8[10];
              pfVar13 = (float *)(int)ROUND(local_60);
              local_5c = pfVar13;
            }
          }
          else {
            pfVar13 = (float *)(int)ROUND((_DAT_0059e43c - (fVar4 - pfVar8[6]) * pfVar8[9]) *
                                          pfVar8[10]);
            local_64 = pfVar13;
          }
          local_8c = *pfVar8;
          local_88 = (undefined4 **)((int)pfVar13 * 0x1000000 + 0xffffff);
          local_90 = (float *)0x4cc4dc;
          FUN_00558cf0();
        }
        local_6c = local_6c + 1;
      } while (local_6c < *(int *)(param_1 + 100));
    }
    return;
  case 5:
    if (DAT_008ab6e4 == 2) {
      fVar16 = (float10)FUN_004b9ce0();
    }
    else {
      fVar16 = (float10)_DAT_008afea0;
    }
    fVar17 = (float)fVar16;
    local_70 = 0;
    if (0 < *(int *)(param_1 + 100)) {
      do {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x68) + local_70 * 4);
        if (((float)puVar2[3] < fVar17) || (fVar17 < (float)puVar2[2])) {
          FUN_004cb5a0(puVar2);
          local_70 = local_70 + -1;
        }
        else {
          fVar4 = fVar17 - (float)puVar2[2];
          local_94 = (float *)(fVar4 * (float)puVar2[0xe] + (float)puVar2[0xb]);
          local_90 = (float *)(fVar4 * (float)puVar2[0xf] + (float)puVar2[0xc]);
          local_8c = fVar4 * (float)puVar2[0x10] + (float)puVar2[0xd];
          local_58 = local_94;
          local_54 = (float)local_90;
          local_50 = local_8c;
          fVar16 = (float10)FUN_005881f0();
          fVar1 = (float)puVar2[0x1a];
          local_14 = fVar1 * *(float *)(param_1 + 0x28);
          local_10 = (float *)(fVar1 * *(float *)(param_1 + 0x2c));
          local_64 = (float *)(fVar1 * *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x18));
          local_48 = local_14 + *(float *)(param_1 + 0x1c);
          local_44 = (float)local_10 + *(float *)(param_1 + 0x20);
          fVar1 = *(float *)(param_1 + 0xc);
          fVar15 = (float10)(float)local_64;
          local_60 = (float)((float10)local_48 * fVar16);
          local_5c = (float *)(float)((float10)local_44 * fVar16);
          fVar5 = local_60 + *(float *)(param_1 + 0x10);
          fVar6 = (float)local_5c + *(float *)(param_1 + 0x14);
          fVar7 = fVar5 * _DAT_0059e450;
          local_90 = (float *)(local_54 + fVar7);
          local_4c = local_64;
          if (DAT_007cfa28 == 1) {
            local_2c = *(float **)((&DAT_007c54f0)[DAT_007c54dc] + 0x744);
            if ((ABS((float)local_2c - (float)local_94) < _DAT_005d3490) &&
               (ABS(*(float *)((&DAT_007c54f0)[DAT_007c54dc] + 0x74c) - local_8c) < _DAT_005d3490))
            {
              FUN_004cbdd0(&local_94,puVar2 + 0x15,fVar7,&local_2c);
            }
          }
          else if ((1 < (int)DAT_007cfa28) && ((int)DAT_007cfa28 < 4)) {
            if (DAT_007c54e0 == 0) {
              iVar14 = 0x68;
            }
            else {
              iVar14 = *(int *)(DAT_007c54e0 + 0x4894);
            }
            local_6c = 0x68;
            if ((DAT_007cfa28 & 1) == 0) {
              local_6c = iVar14;
            }
            local_88 = (undefined4 **)
                       FUN_004c9c70(local_8c + (float)local_94,_DAT_005d3494,&local_68);
            iVar14 = 0;
            if (0 < (int)local_68) {
              do {
                iVar9 = *(int *)((int)local_88 + iVar14 * 4);
                local_3c = *(float *)(iVar9 + 0x738);
                local_38 = *(float *)(iVar9 + 0x73c);
                local_34 = *(float *)(iVar9 + 0x740);
                if (((ABS(local_3c - (float)local_94) < _DAT_005d3490) &&
                    (ABS(local_34 - local_8c) < _DAT_005d3490)) && (local_6c != *(int *)(iVar9 + 4))
                   ) {
                  FUN_004cbdd0(&local_94,puVar2 + 0x15,fVar7,&local_3c);
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 < (int)local_68);
            }
          }
          FUN_00558c60(*puVar2,local_94,local_90,local_8c);
          FUN_00558cb0(*puVar2,(float)(fVar15 * fVar16 + (float10)fVar1),fVar5,fVar6);
          if (fVar4 <= (float)puVar2[6]) {
            if (fVar4 <= (float)puVar2[5]) {
              local_88 = (undefined4 **)(fVar4 * (float)puVar2[8] * (float)puVar2[10]);
              pfVar8 = (float *)(int)ROUND((float)local_88);
              local_30 = pfVar8;
            }
            else {
              pfVar8 = (float *)(int)ROUND((float)puVar2[10]);
              local_40 = pfVar8;
            }
          }
          else {
            local_88 = (undefined4 **)
                       ((_DAT_0059e43c - (fVar4 - (float)puVar2[6]) * (float)puVar2[9]) *
                       (float)puVar2[10]);
            pfVar8 = (float *)(int)ROUND((float)local_88);
          }
          FUN_00558cf0(*puVar2,(int)pfVar8 * 0x1000000 + 0xffffff);
        }
        local_70 = local_70 + 1;
      } while (local_70 < *(int *)(param_1 + 100));
    }
    return;
  case 6:
  case 7:
    if (DAT_008ab6e4 == 2) {
      local_10 = (float *)0x4cdae8;
      fVar16 = (float10)FUN_004b9ce0();
      iVar14 = 0;
      if (0 < *(int *)(param_1 + 100)) {
        do {
          local_10 = *(float **)(*(int *)(param_1 + 0x68) + iVar14 * 4);
          if ((float)fVar16 < *(float *)((int)local_10 + 8)) {
            local_14 = 7.058084e-39;
            FUN_004cb5a0();
            iVar14 = iVar14 + -1;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < *(int *)(param_1 + 100));
      }
    }
    return;
  case 8:
    if (DAT_008ab6e4 == 2) {
      fVar16 = (float10)FUN_004b9ce0();
    }
    else {
      fVar16 = (float10)_DAT_008afea0;
    }
    local_10 = (float *)(float)fVar16;
    local_18 = 0.0;
    if (0 < *(int *)(param_1 + 100)) {
      do {
        pfVar8 = *(float **)(*(int *)(param_1 + 0x68) + (int)local_18 * 4);
        pfVar13 = (float *)0x0;
        local_14 = ((float)local_10 - pfVar8[2]) * *(float *)(param_1 + 0x40);
        if (local_14 < pfVar8[0x19]) {
          pfVar13 = (float *)((int)ROUND((pfVar8[0x19] - local_14) * _DAT_005acec4) * 0x1000000 +
                             0xffffff);
        }
        pfVar11 = (float *)0x0;
        if (local_14 < pfVar8[0x18]) {
          pfVar11 = (float *)((int)ROUND((pfVar8[0x18] - local_14) * _DAT_005acec4) * 0x1000000 +
                             0xffffff);
        }
        if (((pfVar8[3] < (float)local_10) || ((float)local_10 < pfVar8[2])) ||
           ((pfVar13 == (float *)0x0 && (pfVar11 == (float *)0x0)))) {
          local_30 = (float *)0x4cdaaa;
          local_2c = pfVar8;
          FUN_004cb5a0();
          local_18 = (float)((int)local_18 + -1);
        }
        else {
          local_34 = *pfVar8;
          local_30 = (float *)0x0;
          local_38 = 7.057867e-39;
          local_2c = pfVar13;
          FUN_00558dc0();
          local_34 = *pfVar8;
          local_30 = (float *)0x1;
          local_38 = 7.057886e-39;
          local_2c = pfVar11;
          FUN_00558dc0();
          local_34 = *pfVar8;
          local_30 = (float *)0x2;
          local_38 = 7.057906e-39;
          local_2c = pfVar11;
          FUN_00558dc0();
          local_34 = *pfVar8;
          local_30 = (float *)0x3;
          local_38 = 7.057926e-39;
          local_2c = pfVar13;
          FUN_00558dc0();
        }
        local_18 = (float)((int)local_18 + 1);
      } while ((int)local_18 < *(int *)(param_1 + 100));
    }
    return;
  default:
    return;
  case 0xc:
    break;
  case 0xd:
    FUN_004ccb30();
    return;
  }
  iVar14 = param_1;
  iVar9 = FUN_0040c870();
  local_90 = *(float **)(iVar9 + 0x24);
  local_8c = *(float *)(iVar9 + 0x28);
  local_88 = *(undefined4 ***)(iVar9 + 0x2c);
  if (DAT_008ab6e4 == 2) {
    iVar9 = FUN_004b9e30();
    if (iVar9 == 5) {
      fVar17 = 0.0;
      goto LAB_004cd28d;
    }
    fVar16 = (float10)FUN_004b9cf0();
  }
  else {
    fVar16 = (float10)_DAT_008afe98;
  }
  fVar17 = (float)fVar16;
LAB_004cd28d:
  if (DAT_008ab6e4 == 2) {
    fVar16 = (float10)FUN_004b9ce0();
  }
  else {
    fVar16 = (float10)_DAT_008afea0;
  }
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x68) + iVar9 * 4);
      if ((*(float *)(iVar3 + 0xc) < (float)fVar16) || ((float)fVar16 < *(float *)(iVar3 + 8))) {
        FUN_004cb5a0(iVar3);
        iVar9 = iVar9 + -1;
      }
      else {
        pfVar8 = (float *)(iVar3 + 0x2c);
        *pfVar8 = fVar17 * *(float *)(iVar3 + 0x38) + *pfVar8;
        *(float *)(iVar3 + 0x30) = fVar17 * *(float *)(iVar3 + 0x3c) + *(float *)(iVar3 + 0x30);
        *(float *)(iVar3 + 0x34) = fVar17 * *(float *)(iVar3 + 0x40) + *(float *)(iVar3 + 0x34);
        *(float *)(iVar3 + 0x3c) = *(float *)(iVar3 + 0x3c) - ABS(fVar17) * _DAT_005aceb8;
        fVar1 = *pfVar8 * *(float *)(iVar3 + 0x54) +
                *(float *)(iVar3 + 0x30) * *(float *)(iVar3 + 0x58) +
                *(float *)(iVar3 + 0x34) * *(float *)(iVar3 + 0x5c);
        if (fVar1 < *(float *)(iVar3 + 100)) {
          fVar1 = *(float *)(iVar3 + 100) - fVar1;
          local_44 = fVar1 * *(float *)(iVar3 + 0x58);
          local_40 = (float *)(fVar1 * *(float *)(iVar3 + 0x5c));
          *pfVar8 = fVar1 * *(float *)(iVar3 + 0x54) + *pfVar8;
          *(float *)(iVar3 + 0x30) = local_44 + *(float *)(iVar3 + 0x30);
          *(float *)(iVar3 + 0x34) = (float)local_40 + *(float *)(iVar3 + 0x34);
          fVar1 = *(float *)(iVar3 + 0x38) * *(float *)(iVar3 + 0x54) +
                  *(float *)(iVar3 + 0x3c) * *(float *)(iVar3 + 0x58) +
                  *(float *)(iVar3 + 0x40) * *(float *)(iVar3 + 0x5c);
          fVar1 = fVar1 + fVar1;
          local_2c = (float *)(fVar1 * *(float *)(iVar3 + 0x58));
          *(float *)(iVar3 + 0x38) = *(float *)(iVar3 + 0x38) - fVar1 * *(float *)(iVar3 + 0x54);
          *(float *)(iVar3 + 0x3c) = *(float *)(iVar3 + 0x3c) - (float)local_2c;
          *(float *)(iVar3 + 0x40) = *(float *)(iVar3 + 0x40) - fVar1 * *(float *)(iVar3 + 0x5c);
          fVar1 = *(float *)(iVar3 + 0x38);
          if (fVar17 < DAT_0059e440) {
            *(float *)(iVar3 + 0x38) = fVar1 + fVar1;
            *(float *)(iVar3 + 0x3c) = *(float *)(iVar3 + 0x3c) + *(float *)(iVar3 + 0x3c);
            *(float *)(iVar3 + 0x40) = *(float *)(iVar3 + 0x40) + *(float *)(iVar3 + 0x40);
          }
          else {
            *(float *)(iVar3 + 0x38) = fVar1 * _DAT_0059e450;
            *(float *)(iVar3 + 0x3c) = *(float *)(iVar3 + 0x3c) * _DAT_0059e450;
            *(float *)(iVar3 + 0x40) = *(float *)(iVar3 + 0x40) * _DAT_0059e450;
          }
        }
        if ((DAT_007cfa4c & 3) != 0) {
          fVar1 = *(float *)(iVar3 + 0x38) * _DAT_0059ed18;
          fVar4 = *(float *)(iVar3 + 0x3c) * _DAT_0059ed18;
          local_94 = (float *)(*(float *)(iVar3 + 0x40) * _DAT_0059ed18);
          if (DAT_007cfa4c == 1) {
            if (DAT_007c54e0 != 0) {
              local_60 = *(float *)(DAT_007c54e0 + 0x744);
              local_5c = *(float **)(DAT_007c54e0 + 0x748);
              local_58 = *(float **)(DAT_007c54e0 + 0x74c);
              if ((ABS(local_60 - *pfVar8) < _DAT_0059e46c) &&
                 (ABS((float)local_58 - *(float *)(iVar3 + 0x34)) < _DAT_0059e46c)) {
                local_18 = fVar1 + *pfVar8;
                local_68 = fVar4 + *(float *)(iVar3 + 0x30);
                local_64 = (float *)((float)local_94 + *(float *)(iVar3 + 0x34));
                local_14 = local_68;
                local_10 = local_64;
                FUN_004cbf50(&local_18,pfVar8,DAT_007c54e0 + 0x6f0);
              }
            }
          }
          else {
            param_1 = iVar14;
            iVar10 = FUN_004c9c70(*pfVar8 + *(float *)(iVar3 + 0x34),0x40b504f3,&stack0xffffff60);
            iVar12 = 0;
            iVar14 = param_1;
            if (0 < in_stack_ffffff60) {
              do {
                iVar14 = *(int *)(iVar10 + iVar12 * 4);
                local_54 = *(float *)(iVar14 + 0x738);
                local_50 = *(float *)(iVar14 + 0x73c);
                local_4c = *(float **)(iVar14 + 0x740);
                if (((ABS(local_54 - *pfVar8) < _DAT_0059e46c) &&
                    (ABS((float)local_4c - *(float *)(iVar3 + 0x34)) < _DAT_0059e46c)) &&
                   (((DAT_007cfa4c & 1) != 0 || (*(int *)(iVar14 + 4) != DAT_007c54dc)))) {
                  local_3c = fVar1 + *pfVar8;
                  local_38 = fVar4 + *(float *)(iVar3 + 0x30);
                  local_34 = (float)local_94 + *(float *)(iVar3 + 0x34);
                  FUN_004cbf50(&local_3c,pfVar8,iVar14 + 0x6e4);
                }
                iVar12 = iVar12 + 1;
                iVar14 = param_1;
              } while (iVar12 < in_stack_ffffff60);
            }
          }
        }
        FUN_004cc500(iVar3,&stack0xffffffdc);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(param_1 + 100));
  }
  return;
}


