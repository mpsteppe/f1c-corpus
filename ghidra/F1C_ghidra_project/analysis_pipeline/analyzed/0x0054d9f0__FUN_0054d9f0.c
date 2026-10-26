// Function: FUN_0054d9f0 @ 0054d9f0
// Size (bytes): 1675


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054d9f0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_2c;
  int local_28;
  int iStack_24;
  float fStack_20;
  int local_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  if (iVar1 != 0) {
    while (iVar1 != 0) {
      iVar10 = 0;
      if ((*(uint *)(iVar1 + 4) & 0x18000) != 0) {
        uVar2 = *(uint *)(param_1 + 0x14);
        local_34 = 1e+12;
        local_3c = 1e+12;
        local_44 = 1e+12;
        local_38 = -1e+12;
        local_40 = -1e+12;
        local_48 = -1e+12;
        if ((uVar2 & 0x800000) == 0) {
          iVar8 = *(int *)(iVar1 + 0x18) + 4;
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0x118)) {
            do {
              FUN_0054e0e0(*(int *)(param_1 + 0x11c) + iVar10,4);
              iVar3 = *(int *)(param_1 + 0x11c);
              iVar9 = *(int *)(iVar3 + 0xc + iVar10);
              pfVar11 = *(float **)(iVar3 + 0x20 + iVar10);
              local_2c = 0;
              if (0 < *(int *)(iVar3 + iVar10 + 8)) {
                do {
                  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar9,&local_c,iVar8);
                  if (local_44 <= local_c) {
                    if (local_48 < local_c) {
                      local_48 = local_c;
                    }
                  }
                  else {
                    local_44 = local_c;
                  }
                  if (local_3c <= fStack_8) {
                    if (local_40 < fStack_8) {
                      local_40 = fStack_8;
                    }
                  }
                  else {
                    local_3c = fStack_8;
                  }
                  if (local_34 <= fStack_4) {
                    if (local_38 < fStack_4) {
                      local_38 = fStack_4;
                    }
                  }
                  else {
                    local_34 = fStack_4;
                  }
                  pfVar11[2] = fStack_4;
                  *pfVar11 = local_c;
                  pfVar11[1] = fStack_8;
                  (**(code **)*DAT_008b8f24)(DAT_008b8f24,iVar9 + 0xc,pfVar11 + 3,iVar8);
                  pfVar11[8] = *(float *)(iVar9 + 0x20);
                  pfVar11[9] = *(float *)(iVar9 + 0x24);
                  iVar9 = iVar9 + 0x30;
                  pfVar11 = pfVar11 + 0x10;
                  local_2c = local_2c + 1;
                } while (local_2c < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar10));
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x11c) + iVar10);
              if ((uVar2 & 2) == 0) {
                if ((uVar2 & 1) == 0) {
                  FUN_0055d900(0);
                }
                else {
                  FUN_0055da50(0);
                }
              }
              else {
                FUN_0055e320(0);
              }
              if ((*(uint *)(param_1 + 0x14) & 0x400000) != 0) {
                FUN_0055eb30();
              }
              FUN_0054e0f0(*(int *)(param_1 + 0x11c) + iVar10,4);
              local_28 = local_28 + 1;
              iVar10 = iVar10 + 0x40;
            } while (local_28 < *(int *)(param_1 + 0x118));
          }
        }
        else {
          if ((uVar2 & 0x80010000) != 0) {
            if ((uVar2 & 0x10000) == 0) {
              if ((int)uVar2 < 0) {
                iVar10 = *(int *)(param_1 + 0x144);
                fVar5 = *(float *)(iVar10 + 8) - *(float *)(DAT_008b8f28 + 0xf0);
                goto LAB_0054dc76;
              }
            }
            else {
              iVar10 = *(int *)(param_1 + 0x144);
              fVar5 = *(float *)(DAT_008b8f28 + 0xf0) + *(float *)(iVar10 + 8);
LAB_0054dc76:
              *(float *)(iVar10 + 8) = fVar5;
            }
            piVar4 = *(int **)(param_1 + 0x144);
            if ((float)piVar4[2] <= (float)piVar4[1]) {
              if ((float)piVar4[2] < DAT_0059e440) goto LAB_0054dcbe;
            }
            else if (*piVar4 == 1) {
LAB_0054dcbe:
              piVar4[2] = 0;
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0x7ffeffff;
            }
            else {
              piVar4[2] = piVar4[1];
              if (*piVar4 != 2) {
                *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffeffff | 0x80000000;
              }
            }
            fStack_20 = *(float *)(*(int *)(param_1 + 0x144) + 8) /
                        *(float *)(*(int *)(param_1 + 0x144) + 4);
          }
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0x118)) {
            iStack_24 = 0;
            do {
              FUN_0054e0e0(*(int *)(param_1 + 0x11c) + iStack_24,4);
              iVar10 = *(int *)(param_1 + 0x11c);
              iVar8 = *(int *)(iVar10 + 0xc + iStack_24);
              pfVar11 = *(float **)(iVar10 + 0x20 + iStack_24);
              local_2c = 0;
              if (0 < *(int *)(iVar10 + iStack_24 + 8)) {
                local_1c = 0;
                do {
                  iVar10 = (*(uint *)(iVar8 + 0x18) & 0xff) * 0x88;
                  (**(code **)(*DAT_008b8f24 + 4))
                            (DAT_008b8f24,iVar8,&fStack_18,*(int *)(iVar1 + 0x18) + 4 + iVar10);
                  if ((*(uint *)(param_1 + 0x14) & 0x80010000) != 0) {
                    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + 0xc) + 0x11c) +
                                     0xc + iStack_24);
                    iVar9 = iVar3 + local_1c;
                    fStack_18 = (*(float *)(iVar3 + local_1c) - fStack_18) * fStack_20 + fStack_18;
                    fStack_14 = (*(float *)(iVar9 + 4) - fStack_14) * fStack_20 + fStack_14;
                    fStack_10 = (*(float *)(iVar9 + 8) - fStack_10) * fStack_20 + fStack_10;
                  }
                  if (local_44 <= fStack_18) {
                    if (local_48 < fStack_18) {
                      local_48 = fStack_18;
                    }
                  }
                  else {
                    local_44 = fStack_18;
                  }
                  if (local_3c <= fStack_14) {
                    if (local_40 < fStack_14) {
                      local_40 = fStack_14;
                    }
                  }
                  else {
                    local_3c = fStack_14;
                  }
                  if (local_34 <= fStack_10) {
                    if (local_38 < fStack_10) {
                      local_38 = fStack_10;
                    }
                  }
                  else {
                    local_34 = fStack_10;
                  }
                  *pfVar11 = fStack_18;
                  pfVar11[1] = fStack_14;
                  pfVar11[2] = fStack_10;
                  (**(code **)*DAT_008b8f24)
                            (DAT_008b8f24,iVar8 + 0x1c,pfVar11 + 3,
                             *(int *)(iVar1 + 0x18) + 4 + iVar10);
                  pfVar11[8] = *(float *)(iVar8 + 0x30);
                  pfVar11[9] = *(float *)(iVar8 + 0x34);
                  local_1c = local_1c + 0x30;
                  iVar8 = iVar8 + 0x40;
                  pfVar11 = pfVar11 + 0x10;
                  local_2c = local_2c + 1;
                } while (local_2c < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iStack_24));
              }
              uVar2 = *(uint *)(*(int *)(param_1 + 0x11c) + iStack_24);
              if ((uVar2 & 2) == 0) {
                if ((uVar2 & 1) == 0) {
                  FUN_0055d900(0);
                }
                else {
                  FUN_0055da50(0);
                }
              }
              else {
                FUN_0055e320(0);
              }
              if ((*(uint *)(param_1 + 0x14) & 0x400000) != 0) {
                FUN_0055eb30();
              }
              FUN_0054e0f0(*(int *)(param_1 + 0x11c) + iStack_24,4);
              local_28 = local_28 + 1;
              iStack_24 = iStack_24 + 0x40;
            } while (local_28 < *(int *)(param_1 + 0x118));
          }
        }
        *(float *)(param_1 + 0x1c) = local_48;
        fVar5 = (local_48 + local_44) * _DAT_0059e450;
        *(float *)(param_1 + 0x20) = local_3c;
        *(float *)(param_1 + 0xdc) = fVar5;
        *(float *)(param_1 + 0x24) = local_34;
        *(float *)(param_1 + 0x28) = local_48;
        *(float *)(param_1 + 0x2c) = local_3c;
        fVar5 = (local_40 + local_3c) * _DAT_0059e450;
        *(float *)(param_1 + 0x30) = local_38;
        *(float *)(param_1 + 0xe0) = fVar5;
        *(float *)(param_1 + 0x34) = local_44;
        *(float *)(param_1 + 0x38) = local_3c;
        *(float *)(param_1 + 0x3c) = local_38;
        fVar5 = (local_38 + local_34) * _DAT_0059e450;
        *(float *)(param_1 + 0x40) = local_44;
        *(float *)(param_1 + 0xe4) = fVar5;
        *(float *)(param_1 + 0x44) = local_3c;
        *(float *)(param_1 + 0x48) = local_34;
        *(float *)(param_1 + 0x4c) = local_48;
        fVar5 = (local_48 - local_44) * _DAT_0059e450;
        *(float *)(param_1 + 0x50) = local_40;
        *(float *)(param_1 + 0x54) = local_34;
        fVar7 = (local_40 - local_3c) * _DAT_0059e450;
        *(float *)(param_1 + 0x58) = local_48;
        *(float *)(param_1 + 0x5c) = local_40;
        fVar6 = (local_38 - local_34) * _DAT_0059e450;
        *(float *)(param_1 + 0x60) = local_38;
        *(float *)(param_1 + 100) = local_44;
        *(float *)(param_1 + 0x68) = local_40;
        *(float *)(param_1 + 0x6c) = local_38;
        *(float *)(param_1 + 0x70) = local_44;
        *(float *)(param_1 + 0x74) = local_40;
        *(float *)(param_1 + 0x78) = local_34;
        *(float *)(param_1 + 0x18) = SQRT(fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6);
      }
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffeffff;
      iVar1 = *(int *)(iVar1 + 0x24);
    }
  }
  return;
}


