// Function: FUN_0041d630 @ 0041d630
// Strings:  [Indianapolis, Suzuka, Sepang, Nurburgring, Monza, Spa_Francorchamps, Hungaroring, Hockenheim]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d630(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int local_34;
  int local_30;
  float local_2c;
  int local_28;
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    FUN_004144d0();
    iVar5 = -1;
    local_2c = 1e+16;
    local_30 = -1;
    local_34 = 0;
    local_28 = -1;
    uVar6 = 0x1dd;
    if (DAT_008ac48c * 0x18c + DAT_008ac490 != 0) {
      iVar2 = FUN_00566810();
      if (iVar2 == 0) {
        iVar2 = FUN_00566810();
        if (iVar2 == 0) {
          iVar2 = FUN_00566810();
          if (iVar2 == 0) {
            iVar2 = FUN_00566810();
            if (iVar2 == 0) {
              iVar2 = FUN_00566810();
              if (iVar2 == 0) {
                iVar2 = FUN_00566810();
                if (iVar2 == 0) {
                  iVar2 = FUN_00566810();
                  if (iVar2 == 0) {
                    iVar2 = FUN_00566810();
                    if (iVar2 == 0) {
                      iVar2 = FUN_00566810();
                      if (iVar2 == 0) {
                        iVar2 = FUN_00566810();
                        if (iVar2 == 0) {
                          iVar2 = FUN_00566810();
                          if (iVar2 == 0) {
                            iVar2 = FUN_00566810();
                            if (iVar2 == 0) {
                              iVar2 = FUN_00566810();
                              if (iVar2 == 0) {
                                iVar2 = FUN_00566810();
                                if (iVar2 == 0) {
                                  iVar2 = FUN_00566810();
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_00566810();
                                    if (iVar2 == 0) {
                                      iVar2 = FUN_00566810();
                                      if (iVar2 != 0) {
                                        uVar6 = 0x1d9;
                                      }
                                    }
                                    else {
                                      uVar6 = 0x1d0;
                                    }
                                  }
                                  else {
                                    uVar6 = 0x1d2;
                                  }
                                }
                                else {
                                  uVar6 = 0x1c5;
                                }
                              }
                              else {
                                uVar6 = 0x1cf;
                              }
                            }
                            else {
                              uVar6 = 0x1c1;
                            }
                          }
                          else {
                            uVar6 = 0x1ce;
                          }
                        }
                        else {
                          uVar6 = 0x1ca;
                        }
                      }
                      else {
                        uVar6 = 0x1c0;
                      }
                    }
                    else {
                      uVar6 = 0x1c3;
                    }
                  }
                  else {
                    uVar6 = 0x1c9;
                  }
                }
                else {
                  uVar6 = 0x1c4;
                }
              }
              else {
                uVar6 = 0x1d8;
              }
            }
            else {
              uVar6 = 0x1d3;
            }
          }
          else {
            uVar6 = 0x1d7;
          }
        }
        else {
          uVar6 = 0x1c2;
        }
      }
      else {
        uVar6 = 0x1bf;
      }
    }
    FUN_004144f0(uVar6,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
    iVar2 = DAT_005c329c;
    iVar8 = 1;
    iVar4 = DAT_007c54e8;
    iVar3 = DAT_005c329c;
    if (0 < DAT_005c329c) {
      do {
        iVar7 = 0;
        if (0 < iVar3) {
          do {
            iVar1 = (&DAT_007c54f0)[iVar7];
            if (*(int *)(iVar1 + 0x4060) == iVar8) {
              if (*(int *)(iVar1 + 0x4064) == 2) {
                local_34 = local_34 + 1;
                iVar5 = local_30;
                local_28 = iVar7;
              }
              if ((((iVar4 != 0) && (iVar4 == iVar1)) || (iVar8 < 7)) &&
                 (*(int *)(iVar1 + 0x4064) != 2)) {
                iVar4 = (&DAT_007c54f0)[iVar7];
                if ((*(float *)(iVar4 + 0x409c) != _DAT_0059e670) &&
                   (*(float *)(iVar4 + 0x409c) < local_2c)) {
                  local_2c = *(float *)(iVar4 + 0x409c);
                  iVar5 = iVar7;
                  local_30 = iVar7;
                }
                uVar6 = 0x18d;
                if ((iVar3 == 0x16) && (*(int *)(iVar4 + 0x4060) == 0x16)) {
                  uVar6 = 0x1d1;
                }
                FUN_004144f0(uVar6,*(undefined4 *)(iVar4 + 0x489c),iVar8,0xffffffff,0xffffffff,
                             0xc0000000,0xc0000000);
                FUN_00418560(local_20);
                iVar4 = DAT_007c54e8;
                iVar3 = DAT_005c329c;
                if (((DAT_007c54e8 != 0) && (DAT_007c54e8 == (&DAT_007c54f0)[iVar7])) &&
                   (*(int *)((&DAT_007c54f0)[iVar7] + 0x4064) != 2)) {
                  if ((iVar8 == 1) && (DAT_007d2de8 == 0)) {
                    FUN_004144f0(0x1da,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,
                                 0xc0000000);
                    FUN_00418560(local_20);
                  }
                  iVar4 = *(int *)((&DAT_007c54f0)[iVar7] + 0x4058);
                  if (iVar4 < iVar8) {
                    iVar3 = 0x1cb;
                  }
                  else if (iVar8 < 7) {
                    iVar3 = ((iVar4 <= iVar8) - 1 & 0x40) + 0x18d;
                  }
                  else {
                    iVar3 = 0x1cc;
                  }
                  FUN_004144f0(iVar3,iVar4,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
                  FUN_00418560(local_20);
                  iVar4 = DAT_007c54e8;
                  iVar3 = DAT_005c329c;
                }
                break;
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar3);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 <= iVar2);
      if (-1 < iVar5) {
        if (local_34 < 2) {
          if (local_34 == 1) {
            if (local_28 < 0) {
              local_34 = *(int *)((&DAT_007c54f0)[iVar5] + 0x489c);
              uVar6 = 0xffffffff;
              uVar9 = 0x1c7;
            }
            else {
              uVar6 = *(undefined4 *)((&DAT_007c54f0)[iVar5] + 0x489c);
              local_34 = *(int *)((&DAT_007c54f0)[local_28] + 0x489c);
              uVar9 = 0x1c8;
            }
          }
          else {
            local_34 = *(int *)((&DAT_007c54f0)[iVar5] + 0x489c);
            uVar6 = 0xffffffff;
            uVar9 = 0x1dc;
          }
        }
        else {
          uVar6 = *(undefined4 *)((&DAT_007c54f0)[iVar5] + 0x489c);
          uVar9 = 0x1c6;
        }
        FUN_004144f0(uVar9,local_34,uVar6,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        FUN_00418560(local_20);
      }
    }
  }
  return;
}


