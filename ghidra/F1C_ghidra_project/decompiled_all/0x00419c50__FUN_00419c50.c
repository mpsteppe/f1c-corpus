// Function: FUN_00419c50 @ 00419c50
// Strings:  [Indianapolis, Suzuka, Sepang, Nurburgring, Monza, Spa_Francorchamps, Hungaroring, Hockenheim]


void FUN_00419c50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    FUN_004144d0();
    if ((*(int *)(param_1 + 0x4064) == 1) && (*(int *)(param_1 + 0x4070) == 0)) {
      iVar1 = *(int *)(param_1 + 0x4060);
      if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)) {
        if (iVar1 == 1) {
          uVar5 = 0xa7;
          if (((1 < DAT_007d0410) && (DAT_007d0410 < 6)) &&
             (DAT_008ac48c * 0x18c + DAT_008ac490 != 0)) {
            iVar1 = FUN_00566810();
            if (iVar1 == 0) {
              iVar1 = FUN_00566810();
              if (iVar1 == 0) {
                iVar1 = FUN_00566810();
                if (iVar1 == 0) {
                  iVar1 = FUN_00566810();
                  if (iVar1 == 0) {
                    iVar1 = FUN_00566810();
                    if (iVar1 == 0) {
                      iVar1 = FUN_00566810();
                      if (iVar1 == 0) {
                        iVar1 = FUN_00566810();
                        if (iVar1 == 0) {
                          iVar1 = FUN_00566810();
                          if (iVar1 == 0) {
                            iVar1 = FUN_00566810();
                            if (iVar1 == 0) {
                              iVar1 = FUN_00566810();
                              if (iVar1 == 0) {
                                iVar1 = FUN_00566810();
                                if (iVar1 == 0) {
                                  iVar1 = FUN_00566810();
                                  if (iVar1 == 0) {
                                    iVar1 = FUN_00566810();
                                    if (iVar1 == 0) {
                                      iVar1 = FUN_00566810();
                                      if (iVar1 == 0) {
                                        iVar1 = FUN_00566810();
                                        if (iVar1 == 0) {
                                          iVar1 = FUN_00566810();
                                          if (iVar1 == 0) {
                                            iVar1 = FUN_00566810();
                                            if (iVar1 != 0) {
                                              uVar5 = 0xb1;
                                            }
                                          }
                                          else {
                                            uVar5 = 0xac;
                                          }
                                        }
                                        else {
                                          uVar5 = 0xad;
                                        }
                                      }
                                      else {
                                        uVar5 = 0xa0;
                                      }
                                    }
                                    else {
                                      uVar5 = 0xab;
                                    }
                                  }
                                  else {
                                    uVar5 = 0xa3;
                                  }
                                }
                                else {
                                  uVar5 = 0xaa;
                                }
                              }
                              else {
                                uVar5 = 0xa8;
                              }
                            }
                            else {
                              uVar5 = 0xa2;
                            }
                          }
                          else {
                            uVar5 = 0xa9;
                          }
                        }
                        else {
                          uVar5 = 0xa6;
                        }
                      }
                      else {
                        uVar5 = 0xa5;
                      }
                    }
                    else {
                      uVar5 = 0xb0;
                    }
                  }
                  else {
                    uVar5 = 0xae;
                  }
                }
                else {
                  uVar5 = 0xaf;
                }
              }
              else {
                uVar5 = 0xa4;
              }
            }
            else {
              uVar5 = 0xa1;
            }
          }
        }
        else {
          uVar5 = 0x9e;
          if ((DAT_007d0410 == 4) && (6 < iVar1)) {
            uVar5 = 0x9d;
          }
        }
        FUN_004144f0(uVar5,*(undefined4 *)(param_1 + 0x4060),0xffffffff,0xffffffff,0xffffffff,
                     0xc0000000,0xc0000000);
        FUN_00418560(local_20);
        if (DAT_007d0410 == 4) {
          iVar1 = FUN_004c2850();
          if (iVar1 != 0) {
            FUN_004c2850();
            iVar1 = FUN_004c11d0();
            FUN_004c2850();
            iVar2 = FUN_004c1190();
            iVar1 = (iVar2 - iVar1) + -1;
            if (1 < iVar1) {
              iVar2 = 0;
              iVar4 = 0;
              if (DAT_005c329c != 1 && -1 < DAT_005c329c + -1) {
                do {
                  iVar3 = iVar4;
                  FUN_004c2850(iVar4);
                  iVar3 = FUN_004c13a0(iVar3);
                  if (iVar3 != 0) {
                    iVar3 = iVar4;
                    FUN_004c2850(iVar4);
                    iVar3 = FUN_004c13a0(iVar3);
                    if (*(char *)(iVar3 + 0x1b0) != '\0') {
                      iVar3 = iVar4;
                      FUN_004c2850(iVar4);
                      iVar3 = FUN_004c13a0(iVar3);
                      if (iVar2 < *(int *)(iVar3 + 0x198)) {
                        iVar2 = iVar4;
                        FUN_004c2850(iVar4);
                        iVar2 = FUN_004c13a0(iVar2);
                        iVar2 = *(int *)(iVar2 + 0x198);
                      }
                    }
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 < DAT_005c329c + -1);
              }
              FUN_004c2850();
              iVar4 = FUN_004c1390();
              if (iVar4 != 0) {
                FUN_004c2850();
                iVar4 = FUN_004c1390();
                if (iVar2 + iVar1 * 10 < *(int *)(iVar4 + 0x198)) {
                  FUN_004144f0(0x9f,iVar1,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
                  FUN_00418560(local_20);
                  return;
                }
              }
            }
          }
        }
      }
      else {
        if (iVar1 == 1) {
          FUN_004144f0(0x105,*(undefined4 *)(param_1 + 0x489c),0xffffffff,0xffffffff,0xffffffff,
                       0xc0000000,0xc0000000);
          FUN_00418560(local_20);
          return;
        }
        if (iVar1 < 6) {
          FUN_004144f0(0x104,*(undefined4 *)(param_1 + 0x489c),iVar1,0xffffffff,0xffffffff,
                       0xc0000000,0xc0000000);
          FUN_00418560(local_20);
        }
      }
    }
  }
  return;
}


