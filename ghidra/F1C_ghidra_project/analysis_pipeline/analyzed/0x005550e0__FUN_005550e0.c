// Function: FUN_005550e0 @ 005550e0
// Size (bytes): 3422


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005550e0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puStack_84;
  uint *puStack_80;
  int iStack_7c;
  uint *puStack_74;
  int *piStack_70;
  float local_6c;
  int iStack_68;
  undefined4 local_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  undefined4 *puStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int local_8;
  undefined1 local_4 [4];
  
  param_1[0x4f3] = 0;
  FUN_00542520(&local_64,&local_6c);
  FUN_005424c0(&local_8,local_4);
  if (param_1[0x4f1] != 1) {
    param_1[0x4f1] = 1;
    uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x88,1);
    *param_1 = uVar3;
  }
  iVar4 = FUN_0055c9b0();
  if ((((iVar4 != 0) && (-1 < (char)((uint)*(undefined4 *)(param_2 + 0xec) >> 8))) &&
      (iVar4 = *(int *)(param_2 + 0x15c), iVar4 != 0)) && (0 < *(int *)(param_2 + 0x13c))) {
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
      if ((*(byte *)(iVar4 + 0x24) & 2) != 0) {
        FUN_00560fe0(0,0);
      }
    }
    FUN_00541b70(0xe);
  }
  FUN_00554b20(param_3,0);
  FUN_00554700(0);
  if ((*(uint *)(param_2 + 0xec) & 0x10000) != 0) {
    *(uint *)(param_2 + 0xec) = *(uint *)(param_2 + 0xec) & 0xfffeffff;
    FUN_00556040(param_2);
  }
  if (param_1[0x53c] != 0) {
    uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,1);
    *param_1 = uVar3;
  }
  iVar4 = __ftol();
  iVar5 = __ftol();
  iVar6 = __ftol();
  iVar4 = iVar6 + (iVar4 * -0x100 + iVar5) * -0x100 + 0xffffff;
  *(int *)(param_2 + 0x154) = iVar4;
  if (param_1[0x4f2] != iVar4) {
    param_1[0x4f2] = iVar4;
    uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x3c,iVar4);
    *param_1 = uVar3;
  }
  iStack_60 = 0;
  do {
    switch(iStack_60) {
    case 0:
      iStack_68 = *(int *)(param_2 + 0x1b4);
      puStack_80 = *(uint **)(param_2 + 0x1b8);
      uVar3 = 1;
      break;
    case 1:
      iStack_68 = *(int *)(param_2 + 0x1c4);
      puStack_80 = *(uint **)(param_2 + 0x1c8);
      goto LAB_00555303;
    case 2:
      if (0 < *(int *)(param_2 + 0x1c4) + *(int *)(param_2 + 0x1b4)) {
        FUN_00554b20(param_3,1);
      }
      iStack_68 = *(int *)(param_2 + 0x1bc);
      puStack_80 = *(uint **)(param_2 + 0x1c0);
      uVar3 = 1;
      break;
    case 3:
      iStack_68 = *(int *)(param_2 + 0x1cc);
      puStack_80 = *(uint **)(param_2 + 0x1d0);
LAB_00555303:
      uVar3 = 0;
      break;
    default:
      goto switchD_0055527d_default;
    }
    FUN_00554be0(uVar3);
switchD_0055527d_default:
    if (0 < iStack_68) {
      puStack_74 = puStack_80 + 0x82;
      iStack_50 = iStack_68;
      do {
        if (0 < (int)*puStack_74) {
          iVar4 = *(int *)(puStack_74[1] + 0xc);
          if (param_1[0x4f6] != 0) {
            uStack_38 = *(undefined4 *)(iVar4 + 0x58);
            uStack_3c = *(undefined4 *)(iVar4 + 0x54);
            uStack_34 = *(undefined4 *)(iVar4 + 0x5c);
            uStack_4c = *(undefined4 *)(iVar4 + 0x44);
            uStack_40 = *(undefined4 *)(iVar4 + 0x50);
            uStack_30 = *(undefined4 *)(iVar4 + 0x60);
            uStack_48 = *(undefined4 *)(iVar4 + 0x48);
            uStack_24 = *(undefined4 *)(iVar4 + 0x6c);
            uStack_44 = *(undefined4 *)(iVar4 + 0x4c);
            uStack_2c = *(undefined4 *)(iVar4 + 100);
            uStack_18 = *(undefined4 *)(iVar4 + 0x78);
            uStack_28 = *(undefined4 *)(iVar4 + 0x68);
            uStack_20 = *(undefined4 *)(iVar4 + 0x70);
            uStack_c = *(undefined4 *)(iVar4 + 0xb0);
            uStack_1c = *(undefined4 *)(iVar4 + 0x74);
            uStack_14 = *(undefined4 *)(iVar4 + 0x7c);
            uStack_10 = *(undefined4 *)(iVar4 + 0x80);
            uVar3 = (**(code **)(*(int *)param_1[0x440] + 0xa8))((int *)param_1[0x440],&uStack_4c);
            *param_1 = uVar3;
          }
          if ((*(uint *)(iVar4 + 0x9c) & 0x400) == 0) {
            FUN_00554790(*puStack_80,*(undefined4 *)(iVar4 + 0xac),
                         *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0x84));
            iVar5 = *(int *)(iVar4 + 0xa4);
            puStack_84 = (uint *)0x0;
            if (0 < iVar5) {
              do {
                iVar6 = 0;
                puVar8 = puStack_84;
                if ((int)puStack_84 < iVar5) {
                  puStack_84 = puStack_80 + (int)puStack_84 * 0x10 + 1;
                  do {
                    if ((int)param_1[0x4ec] <= iVar6) break;
                    uVar7 = FUN_005504d0(0,puVar8);
                    if (uVar7 == 0) {
                      FUN_00553fa0(iVar6);
                    }
                    else {
                      iVar5 = FUN_00554f80(param_2,uVar7);
                      if (iVar5 != 0) {
                        puStack_84[0xb] = uVar7;
                        FUN_005546a0(puStack_84,iVar6);
                      }
                    }
                    puStack_84 = puStack_84 + 0x10;
                    puVar8 = (uint *)((int)puVar8 + 1);
                    iVar6 = iVar6 + 1;
                  } while ((int)puVar8 < *(int *)(iVar4 + 0xa4));
                }
                puStack_84 = puVar8;
                FUN_00553fa0(iVar6);
                piStack_70 = (int *)puStack_74[1];
                iStack_7c = 0;
                if (0 < (int)*puStack_74) {
                  do {
                    iVar5 = piStack_70[1];
                    iVar6 = *piStack_70;
                    iVar9 = piStack_70[2];
                    if (*(int *)(iVar5 + 0xfc) < 5) {
                      FUN_005423c0(0x3f800000,0x461c4000);
                      FUN_00541b70(4);
                    }
                    if (iVar6 != param_1[0x4f3]) {
                      param_1[0x4f3] = iVar6;
                      FUN_0054b9e0();
                    }
                    bVar2 = (byte)*(undefined4 *)(iVar6 + 0x3c);
                    if (param_1[0x4f6] == 0) {
                      if ((bVar2 & 0x10) == 0x10) {
                        FUN_0055d720(param_3,1);
                      }
                    }
                    else if ((bVar2 & 0x10) == 0x10) {
                      FUN_00541810(*(undefined4 *)(iVar5 + 0x10c),*(undefined4 *)(iVar5 + 0x110));
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                                        ((int *)param_1[0x440],0x89,1);
                      *param_1 = uVar3;
                      piVar1 = (int *)param_1[0x440];
                      if ((*(uint *)(iVar5 + 0x14) & 0x400000) == 0) {
                        uVar3 = (**(code **)(*piVar1 + 200))(piVar1,0x8d,0);
                        *param_1 = uVar3;
                      }
                      else {
                        uVar3 = (**(code **)(*piVar1 + 200))(piVar1,0x8d,1);
                        *param_1 = uVar3;
                      }
                    }
                    else {
                      FUN_00541810(0,0);
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                                        ((int *)param_1[0x440],0x89,0);
                      *param_1 = uVar3;
                    }
                    FUN_00554700(*(undefined4 *)(iVar9 + 0x1c));
                    iVar6 = *(int *)param_1[0x440];
                    if ((*(uint *)(iVar5 + 0x14) & 0x800) == 0) {
                      uVar3 = (**(code **)(iVar6 + 0x154))
                                        ((int *)param_1[0x440],
                                         *(undefined4 *)(*(int *)(iVar9 + 0x24) + 0x18),
                                         *(undefined4 *)(iVar9 + 0x2c));
                      *param_1 = uVar3;
                      if ((char)((uint)*(undefined4 *)(iVar5 + 0x14) >> 8) < '\0') {
                        uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                          ((int *)param_1[0x440],4,0,*(undefined4 *)(iVar9 + 8),
                                           *(undefined4 *)(iVar9 + 0x30),*(int *)(iVar9 + 0x10) / 3)
                        ;
                      }
                      else {
                        uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                          ((int *)param_1[0x440],5,0,*(undefined4 *)(iVar9 + 8),
                                           *(undefined4 *)(iVar9 + 0x30),*(int *)(iVar9 + 0x10) + -2
                                          );
                      }
                    }
                    else {
                      uVar3 = (**(code **)(iVar6 + 0x154))();
                      *param_1 = uVar3;
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                                        ((int *)param_1[0x440],0x17,4);
                      *param_1 = uVar3;
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],8,2)
                      ;
                      *param_1 = uVar3;
                      if ((char)((uint)*(undefined4 *)(iVar5 + 0x14) >> 8) < '\0') {
                        uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                          ((int *)param_1[0x440],4,0,*(undefined4 *)(iVar9 + 8),
                                           *(undefined4 *)(iVar9 + 0x30),*(int *)(iVar9 + 0x10) / 3)
                        ;
                      }
                      else {
                        uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                          ((int *)param_1[0x440],5,0,*(undefined4 *)(iVar9 + 8),
                                           *(undefined4 *)(iVar9 + 0x30),*(int *)(iVar9 + 0x10) + -2
                                          );
                      }
                      *param_1 = uVar3;
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                                        ((int *)param_1[0x440],0x17,2);
                      *param_1 = uVar3;
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],8,3)
                      ;
                    }
                    *param_1 = uVar3;
                    if (*(int *)(iVar5 + 0xfc) < 5) {
                      FUN_005423c0(local_64,local_6c);
                      FUN_00541b70(4);
                    }
                    piStack_70 = piStack_70 + 4;
                    iStack_7c = iStack_7c + 1;
                  } while (iStack_7c < (int)*puStack_74);
                }
                if (param_1[0x4f4] == 0) goto LAB_00555b83;
                FUN_00554790(*puStack_80 | 0x800,0x10009,0);
                uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x17,4);
                *param_1 = uVar3;
                iVar5 = *(int *)(iVar4 + 0xa4);
              } while ((int)puStack_84 < iVar5);
            }
          }
          else {
            piStack_70 = (int *)puStack_74[1];
            iStack_7c = 0;
            if (0 < (int)*puStack_74) {
              do {
                iVar5 = piStack_70[1];
                iVar6 = piStack_70[2];
                iVar9 = *piStack_70;
                iStack_5c = iVar5;
                iStack_58 = iVar6;
                if (param_1[0x4f4] != 0) {
                  uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x17,2);
                  *param_1 = uVar3;
                }
                FUN_00554790(*puStack_80,*(undefined4 *)(iVar4 + 0xac),
                             *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0x84));
                if (iVar9 != param_1[0x4f3]) {
                  param_1[0x4f3] = iVar9;
                  FUN_0054b9e0();
                }
                bVar2 = (byte)*(undefined4 *)(iVar9 + 0x3c);
                if (param_1[0x4f6] == 0) {
                  if ((bVar2 & 0x10) == 0x10) {
                    FUN_0055d720(param_3,1);
                  }
                }
                else if ((bVar2 & 0x10) == 0x10) {
                  FUN_00541810(*(undefined4 *)(iVar5 + 0x10c),*(undefined4 *)(iVar5 + 0x110));
                  uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x89,1);
                  *param_1 = uVar3;
                  piVar1 = (int *)param_1[0x440];
                  if ((*(uint *)(iVar5 + 0x14) & 0x400000) == 0) {
                    uVar3 = (**(code **)(*piVar1 + 200))(piVar1,0x8d,0);
                    *param_1 = uVar3;
                  }
                  else {
                    uVar3 = (**(code **)(*piVar1 + 200))(piVar1,0x8d,1);
                    *param_1 = uVar3;
                  }
                }
                else {
                  FUN_00541810(0,0);
                  uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x89,0);
                  *param_1 = uVar3;
                }
                FUN_00554700(*(undefined4 *)(iVar6 + 0x1c));
                iVar5 = 0;
                iVar9 = 0;
                if (0 < *(int *)(iVar4 + 0xa4)) {
                  if (*(int *)(iVar4 + 0xa4) < 1) goto LAB_005559ec;
                  do {
                    iVar9 = 0;
                    puStack_54 = param_1 + 0x45e;
                    puStack_84 = puStack_80 + iVar5 * 0x10 + 1;
                    do {
                      if ((int)param_1[0x4ec] <= iVar9) break;
                      uVar7 = FUN_005504d0(*(undefined4 *)(iStack_58 + 0x34),iVar5);
                      iVar6 = FUN_00554f80(param_2,uVar7);
                      if (iVar6 != 0) {
                        puStack_84[0xb] = uVar7;
                        FUN_005546a0(puStack_84,iVar9);
                      }
                      puStack_84 = puStack_84 + 0x10;
                      iVar5 = iVar5 + 1;
                      puStack_54 = puStack_54 + 0x11;
                      iVar9 = iVar9 + 1;
                      iVar6 = iStack_58;
                    } while (iVar5 < *(int *)(iVar4 + 0xa4));
LAB_005559ec:
                    FUN_00553fa0(iVar9);
                    if (*(int *)(iStack_5c + 0xfc) < 5) {
                      FUN_005423c0(0x3f800000,0x461c4000);
                      FUN_00541b70(4);
                    }
                    uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x154))
                                      ((int *)param_1[0x440],
                                       *(undefined4 *)(*(int *)(iVar6 + 0x24) + 0x18),
                                       *(undefined4 *)(iVar6 + 0x2c));
                    *param_1 = uVar3;
                    if ((char)((uint)*(undefined4 *)(iStack_68 + 0x14) >> 8) < '\0') {
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                        ((int *)param_1[0x440],4,0,*(undefined4 *)(iVar6 + 8),
                                         *(undefined4 *)(iVar6 + 0x30),*(int *)(iVar6 + 0x10) / 3);
                    }
                    else {
                      uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                                        ((int *)param_1[0x440],5,0,*(undefined4 *)(iVar6 + 8),
                                         *(undefined4 *)(iVar6 + 0x30),*(int *)(iVar6 + 0x10) + -2);
                    }
                    *param_1 = uVar3;
                    if (*(int *)(iStack_5c + 0xfc) < 5) {
                      FUN_005423c0(local_64,local_6c);
                      FUN_00541b70(4);
                    }
                    if (param_1[0x4f4] == 0) break;
                    if (puStack_80[iVar5 * 0x10 + 9] == 4) {
                      uVar7 = *puStack_80;
                      uVar3 = 0x10009;
LAB_00555b12:
                      FUN_00554790(uVar7 | 0x800,uVar3,0);
                    }
                    else if (puStack_80[iVar5 * 0x10 + 9] == 2) {
                      uVar7 = *puStack_80;
                      uVar3 = 0x20002;
                      goto LAB_00555b12;
                    }
                    uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))
                                      ((int *)param_1[0x440],0x17,4);
                    *param_1 = uVar3;
                  } while (iVar5 < *(int *)(iVar4 + 0xa4));
                }
                piStack_70 = piStack_70 + 4;
                iStack_7c = iStack_7c + 1;
              } while (iStack_7c < (int)*puStack_74);
            }
          }
          if (param_1[0x4f4] != 0) {
            uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x17,2);
            *param_1 = uVar3;
          }
        }
LAB_00555b83:
        puStack_80 = puStack_80 + 0x84;
        puStack_74 = puStack_74 + 0x84;
        iStack_50 = iStack_50 + -1;
      } while (iStack_50 != 0);
    }
    iStack_60 = iStack_60 + 1;
    if (3 < iStack_60) {
      if (param_1[0x53c] != 0) {
        uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,0);
        *param_1 = uVar3;
      }
      if (((-1 < (char)((uint)*(undefined4 *)(param_2 + 0xec) >> 8)) &&
          (*(int *)(param_2 + 0x15c) != 0)) && (0 < *(int *)(param_2 + 0x13c))) {
        if ((param_1[0x4ea] & 0x100) == 0) {
          FUN_005423c0(local_64,local_6c * _DAT_0059e868 + local_6c);
        }
        else {
          uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x2f,1);
          *param_1 = uVar3;
        }
        uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x17,4);
        *param_1 = uVar3;
        FUN_00553fa0(1);
        FUN_00553fa0(2);
        FUN_00553fa0(3);
        for (iVar4 = *(int *)(param_2 + 0x15c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
          if ((*(byte *)(iVar4 + 0x24) & 2) != 0) {
            iVar5 = FUN_0055c9b0();
            if ((iVar5 == 0) && (FUN_00560fe0(0,0), (*(byte *)(iVar4 + 0x24) & 8) != 0)) {
              FUN_00541b70(0xe);
            }
            if ((*(uint *)(iVar4 + 0x24) & 8) != 0) {
              *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffff7;
              iVar5 = FUN_00554f80(param_2,*(undefined4 *)(iVar4 + 0x10));
              if (iVar5 != 0) {
                FUN_00553db0();
                uStack_2c = *(undefined4 *)(iVar4 + 0x10);
                uStack_38 = 0xc;
                uStack_34 = 2;
                uStack_24 = 1;
                uStack_20 = 1;
                FUN_005546a0(&iStack_58,0);
                FUN_00554790(0x900,0x40001,0);
                FUN_005613e0();
                uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x94))
                                  ((int *)param_1[0x440],0x100,param_1 + 0x503);
                *param_1 = uVar3;
                param_1[0x4f3] = 0;
                if (*(int *)(iVar4 + 4) != 0) {
                  FUN_00554700(param_1[0x453] + param_1[0x452] * 0x24);
                  uVar3 = (**(code **)(*(int *)param_1[0x440] + 0x118))
                                    ((int *)param_1[0x440],4,0,*(int *)(iVar4 + 4) / 3);
                  *param_1 = uVar3;
                  param_2 = local_8;
                }
              }
            }
          }
        }
        uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x17,2);
        *param_1 = uVar3;
        if ((param_1[0x4ea] & 0x100) == 0) {
          FUN_005423c0(local_64,local_6c);
        }
        else {
          uVar3 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x2f,0);
          *param_1 = uVar3;
        }
      }
      FUN_00541b70(0xe);
      return;
    }
  } while( true );
}


