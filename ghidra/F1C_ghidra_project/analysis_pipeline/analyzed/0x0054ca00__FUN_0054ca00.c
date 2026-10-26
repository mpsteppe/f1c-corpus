// Function: FUN_0054ca00 @ 0054ca00
// Size (bytes): 1546


undefined4 __fastcall FUN_0054ca00(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  float *pfVar13;
  int iVar14;
  int local_1c;
  int local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  local_8 = 0x12;
  if ((*(uint *)(param_1 + 0x14) & 0x8000000) == 0) {
    if ((*(byte *)(*(int *)(param_1 + 0x138) + 0x3c) & 0x10) != 0) {
      local_8 = 0x22;
    }
    iVar11 = 0;
    local_4 = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x38 + iVar11) = local_8;
        iVar4 = FUN_00540940(*(int *)(param_1 + 0x11c) + iVar11);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        FUN_0054e0e0(*(int *)(param_1 + 0x11c) + iVar11,0xc);
        puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x11c) + 0x20 + iVar11);
        if (puVar12 != (undefined4 *)0x0) {
          iVar4 = *(int *)(*(int *)(param_1 + 0x11c) + iVar11 + 4);
          FUN_005472d0(2,&local_10);
          local_10 = local_10 << 0x18;
          if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
            puVar6 = *(undefined4 **)(*(int *)(param_1 + 0x11c) + 0xc + iVar11);
            iVar7 = 0;
            if (0 < *(int *)(*(int *)(param_1 + 0x11c) + iVar11 + 8)) {
              do {
                *puVar12 = *puVar6;
                puVar12[1] = puVar6[1];
                puVar12[2] = puVar6[2];
                puVar12[3] = puVar6[3];
                puVar12[4] = puVar6[4];
                puVar12[5] = puVar6[5];
                puVar6[6] = puVar6[6] | local_10;
                puVar12[6] = puVar6[6];
                puVar12[7] = 0;
                puVar6 = puVar6 + 0xc;
                puVar12 = puVar12 + 0x10;
                iVar7 = iVar7 + 1;
              } while (iVar7 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
            }
            local_c = -1;
            local_1c = 0;
            if (0 < *(int *)(iVar4 + 0xa4)) {
              pfVar13 = (float *)(*(int *)(iVar4 + 0xa8) + 0x70);
              do {
                iVar7 = 0;
                if (0 < local_1c) {
                  pfVar8 = (float *)(*(int *)(iVar4 + 0xa8) + 0x74);
                  do {
                    if ((((*pfVar13 == pfVar8[-1]) && (pfVar13[1] == *pfVar8)) &&
                        (pfVar13[2] == pfVar8[1])) && (pfVar13[3] == pfVar8[2])) {
                      FUN_0054fc70(iVar7);
                      break;
                    }
                    iVar7 = iVar7 + 1;
                    pfVar8 = pfVar8 + 0x25;
                  } while (iVar7 < local_1c);
                }
                if (iVar7 == local_1c) {
                  iVar14 = local_c + 1;
                  local_c = iVar14;
                  FUN_0054fc70(iVar14);
                  iVar2 = *(int *)(*(int *)(param_1 + 0x11c) + 0xc + iVar11);
                  iVar7 = *(int *)(param_1 + 0x11c) + iVar11;
                  iVar3 = *(int *)(iVar7 + 0x20);
                  switch(iVar14) {
                  case 0:
                    iVar14 = 0;
                    if (0 < *(int *)(iVar7 + 8)) {
                      pfVar8 = (float *)(iVar2 + 0x20);
                      pfVar9 = (float *)(iVar3 + 0x24);
                      do {
                        iVar14 = iVar14 + 1;
                        *pfVar8 = pfVar8[2] * pfVar13[2] + *pfVar13;
                        pfVar8[1] = pfVar8[3] * pfVar13[3] + pfVar13[1];
                        pfVar9[-1] = *pfVar8;
                        *pfVar9 = pfVar8[1];
                        pfVar8 = pfVar8 + 0xc;
                        pfVar9 = pfVar9 + 0x10;
                      } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                    }
                    break;
                  case 1:
                    iVar14 = 0;
                    if (0 < *(int *)(iVar7 + 8)) {
                      pfVar8 = (float *)(iVar2 + 0x2c);
                      pfVar9 = (float *)(iVar3 + 0x2c);
                      do {
                        iVar14 = iVar14 + 1;
                        pfVar9[-1] = pfVar8[-1] * pfVar13[2] + *pfVar13;
                        *pfVar9 = pfVar13[3] * *pfVar8 + pfVar13[1];
                        pfVar8 = pfVar8 + 0xc;
                        pfVar9 = pfVar9 + 0x10;
                      } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                    }
                    break;
                  case 2:
                    iVar14 = 0;
                    if (0 < *(int *)(iVar7 + 8)) {
                      pfVar8 = (float *)(iVar2 + 0x2c);
                      pfVar9 = (float *)(iVar3 + 0x34);
                      do {
                        iVar14 = iVar14 + 1;
                        pfVar9[-1] = pfVar8[-1] * pfVar13[2] + *pfVar13;
                        *pfVar9 = *pfVar8 * pfVar13[3] + pfVar13[1];
                        pfVar8 = pfVar8 + 0xc;
                        pfVar9 = pfVar9 + 0x10;
                      } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                    }
                    break;
                  case 3:
                    iVar14 = 0;
                    if (0 < *(int *)(iVar7 + 8)) {
                      pfVar8 = (float *)(iVar2 + 0x2c);
                      pfVar9 = (float *)(iVar3 + 0x3c);
                      do {
                        iVar14 = iVar14 + 1;
                        pfVar9[-1] = pfVar8[-1] * pfVar13[2] + *pfVar13;
                        *pfVar9 = pfVar13[3] * *pfVar8 + pfVar13[1];
                        pfVar8 = pfVar8 + 0xc;
                        pfVar9 = pfVar9 + 0x10;
                      } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                    }
                  }
                }
                pfVar13 = pfVar13 + 0x25;
                local_1c = local_1c + 1;
              } while (local_1c < *(int *)(iVar4 + 0xa4));
            }
          }
          else {
            iVar7 = 0;
            if (0 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11)) {
              puVar12 = puVar12 + 7;
              puVar5 = (uint *)(*(int *)(*(int *)(param_1 + 0x11c) + 0xc + iVar11) + 0x28);
              do {
                uVar1 = *puVar5;
                *puVar5 = uVar1 | local_10;
                puVar12[-1] = uVar1 | local_10;
                *puVar12 = 0;
                puVar5 = puVar5 + 0x10;
                puVar12 = puVar12 + 0x10;
                iVar7 = iVar7 + 1;
              } while (iVar7 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
            }
            local_c = *(int *)(iVar4 + 0xa8);
            local_14 = 0;
            local_1c = 0;
            if (0 < *(int *)(iVar4 + 0xa4)) {
              pfVar13 = (float *)(local_c + 0x78);
              do {
                iVar7 = 0;
                if (0 < local_1c) {
                  pfVar8 = (float *)(*(int *)(iVar4 + 0xa8) + 0x78);
                  do {
                    if (((pfVar13[-2] != pfVar8[-2]) || (pfVar13[-1] != pfVar8[-1])) ||
                       ((*pfVar13 != *pfVar8 || (*pfVar13 != *pfVar8)))) {
                      local_14 = local_14 + 1;
                      FUN_0054fc70(local_14);
                      break;
                    }
                    iVar7 = iVar7 + 1;
                    pfVar8 = pfVar8 + 0x25;
                  } while (iVar7 < local_1c);
                }
                iVar2 = *(int *)(*(int *)(param_1 + 0x11c) + 0x20 + iVar11);
                iVar7 = *(int *)(param_1 + 0x11c) + iVar11;
                iVar3 = *(int *)(iVar7 + 0xc);
                switch(local_14) {
                case 0:
                  iVar14 = 0;
                  if (0 < *(int *)(iVar7 + 8)) {
                    pfVar8 = (float *)(iVar3 + 0x30);
                    pfVar9 = (float *)(iVar2 + 0x24);
                    do {
                      iVar14 = iVar14 + 1;
                      *pfVar8 = pfVar8[2] * *pfVar13 + pfVar13[-2];
                      pfVar8[1] = pfVar13[1] * pfVar8[3] + pfVar13[-1];
                      pfVar9[-1] = *pfVar8;
                      *pfVar9 = pfVar8[1];
                      pfVar8 = pfVar8 + 0x10;
                      pfVar9 = pfVar9 + 0x10;
                    } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                  }
                  break;
                case 1:
                  iVar14 = 0;
                  if (0 < *(int *)(iVar7 + 8)) {
                    pfVar8 = (float *)(iVar3 + 0x3c);
                    pfVar9 = (float *)(iVar2 + 0x2c);
                    do {
                      iVar14 = iVar14 + 1;
                      pfVar9[-1] = pfVar8[-1] * *pfVar13 + pfVar13[-2];
                      *pfVar9 = pfVar13[1] * *pfVar8 + pfVar13[-1];
                      pfVar8 = pfVar8 + 0x10;
                      pfVar9 = pfVar9 + 0x10;
                    } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                  }
                  break;
                case 2:
                  iVar14 = 0;
                  if (0 < *(int *)(iVar7 + 8)) {
                    pfVar8 = (float *)(iVar3 + 0x3c);
                    pfVar9 = (float *)(iVar2 + 0x34);
                    do {
                      iVar14 = iVar14 + 1;
                      pfVar9[-1] = pfVar8[-1] * *pfVar13 + pfVar13[-2];
                      *pfVar9 = pfVar13[1] * *pfVar8 + pfVar13[-1];
                      pfVar8 = pfVar8 + 0x10;
                      pfVar9 = pfVar9 + 0x10;
                    } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                  }
                  break;
                case 3:
                  iVar14 = 0;
                  if (0 < *(int *)(iVar7 + 8)) {
                    pfVar8 = (float *)(iVar3 + 0x3c);
                    pfVar9 = (float *)(iVar2 + 0x3c);
                    do {
                      iVar14 = iVar14 + 1;
                      pfVar9[-1] = pfVar8[-1] * *pfVar13 + pfVar13[-2];
                      *pfVar9 = pfVar13[1] * *pfVar8 + pfVar13[-1];
                      pfVar8 = pfVar8 + 0x10;
                      pfVar9 = pfVar9 + 0x10;
                    } while (iVar14 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar11));
                  }
                }
                local_c = local_c + 0x94;
                pfVar13 = pfVar13 + 0x25;
                local_1c = local_1c + 1;
              } while (local_1c < *(int *)(iVar4 + 0xa4));
            }
          }
        }
        puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x11c) + 0x28 + iVar11);
        iVar4 = *(int *)(param_1 + 0x11c) + iVar11;
        if (puVar12 != (undefined4 *)0x0) {
          uVar1 = *(uint *)(iVar4 + 0x10);
          puVar6 = *(undefined4 **)(iVar4 + 0x14);
          for (uVar10 = (uVar1 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar12 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar4 = (uVar1 & 1) << 1; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
        }
        FUN_0055d720(*(undefined4 *)(DAT_008b8f28 + 0xf8),0);
        FUN_0054e0f0(*(int *)(param_1 + 0x11c) + iVar11,0xc);
        *(uint *)(*(int *)(param_1 + 0x11c) + 0x38 + iVar11) =
             *(uint *)(*(int *)(param_1 + 0x11c) + 0x38 + iVar11) | 0x200;
        local_4 = local_4 + 1;
        iVar11 = iVar11 + 0x40;
      } while (local_4 < *(int *)(param_1 + 0x118));
    }
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x9000020;
  }
  return 0;
}


