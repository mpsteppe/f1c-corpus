// Function: FUN_004f4270 @ 004f4270
// Strings:  [*.hdv file references unknown tire compound "%s", Normal, D:\dev\F1_1999_2002\Source\vehload.cpp, D:\dev\F1_1999_2002\Source\vehload.cpp, Gear6Setting, Gear5Setting, Gear4Setting, Gear3Setting]


/* WARNING: Removing unreachable block (ram,0x004f6415) */
/* WARNING: Removing unreachable block (ram,0x004f641d) */
/* WARNING: Removing unreachable block (ram,0x004f6423) */
/* WARNING: Removing unreachable block (ram,0x004f6430) */
/* WARNING: Removing unreachable block (ram,0x004f6445) */
/* WARNING: Removing unreachable block (ram,0x004f6449) */
/* WARNING: Removing unreachable block (ram,0x004f6459) */
/* WARNING: Removing unreachable block (ram,0x004f6470) */
/* WARNING: Removing unreachable block (ram,0x004f6497) */
/* WARNING: Removing unreachable block (ram,0x004f64b3) */
/* WARNING: Removing unreachable block (ram,0x004f64a6) */
/* WARNING: Removing unreachable block (ram,0x004f648e) */
/* WARNING: Removing unreachable block (ram,0x004f64e9) */
/* WARNING: Removing unreachable block (ram,0x004f64ed) */
/* WARNING: Removing unreachable block (ram,0x004f64f2) */
/* WARNING: Removing unreachable block (ram,0x004f64f4) */
/* WARNING: Removing unreachable block (ram,0x004f651c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004f4270(int param_1,char *param_2,int param_3,uint param_4)

{
  double dVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  undefined1 *local_590;
  undefined4 local_58c;
  undefined1 local_584 [4];
  int local_580;
  int local_57c;
  int local_574;
  int aiStack_570 [2];
  uint local_568;
  undefined4 local_564;
  undefined1 local_560 [384];
  undefined4 local_3e0;
  undefined1 local_3dc;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c8 [96];
  undefined1 local_248;
  undefined4 local_247;
  char acStack_20a [258];
  undefined1 local_108 [260];
  
  puVar6 = local_3c8;
  for (iVar10 = 0x60; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_3e0 = 0;
  local_3cc = 0;
  local_3d4 = 0;
  local_3d0 = 0;
  local_3dc = 1;
  local_590 = (undefined1 *)0x0;
  local_58c = 0xffffffff;
  iVar10 = FUN_00534b00();
  if (iVar10 == 0) {
LAB_004f4727:
    if (local_590 != (undefined1 *)0x0) {
      FUN_00587bcf(local_590);
    }
    return 0xffffffff;
  }
  local_568 = param_4 & 1;
  if (local_568 != 0) {
    iVar4 = FUN_005351d0(0x180);
    while (iVar4 != 0) {
      iVar4 = FUN_005651b0();
      if ((((((iVar4 == 0) && (iVar4 = FUN_00589db0(local_3c8,0x3d), iVar4 != 0)) &&
            (iVar5 = FUN_00587c20(local_3c8,s_SETTING__005d6764), iVar5 != iVar4 + -7)) &&
           ((puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_NOTES__005d675c), puVar6 != local_3c8
            && (puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_DOWNFORCE__005d6750),
               puVar6 != local_3c8)))) &&
          ((puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_BALANCE__005d6744), puVar6 != local_3c8
           && ((puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_RIDE__005d673c), puVar6 != local_3c8
               && (puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_GEARING__005d6730),
                  puVar6 != local_3c8)))))) &&
         ((puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_CUSTOM__005d6728), puVar6 != local_3c8 &&
          (puVar6 = (undefined4 *)FUN_00587c20(local_3c8,s_SYMMETRIC__005d671c), puVar6 != local_3c8
          )))) {
        if ((DAT_007c569c != 5) &&
           (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x2da), cVar3 != '\0'
           )) {
          FUN_004d7aa0(&DAT_008ad25c,s__s_is_an_illegal__SVM_file_005d6654,param_2);
        }
        FUN_005355a0();
        goto LAB_004f4727;
      }
      iVar4 = FUN_005351d0(0x180);
    }
    FUN_00535390(0);
  }
  FUN_00566650(&DAT_005ea438);
  *(undefined1 *)(param_3 + 0x19a4) = 1;
  *(undefined1 *)(param_3 + 0x19a5) = 1;
  iVar4 = FUN_005351d0(0x180);
joined_r0x004f44ab:
  if (iVar4 == 0) {
    FUN_0042e530(0xffffffff,0xffffffff);
    FUN_005355a0();
    if (local_590 != (undefined1 *)0x0) {
      FUN_00587bcf(local_590);
    }
    return 0;
  }
  iVar4 = FUN_005651b0();
  if (iVar4 == 0) {
    iVar4 = FUN_00587c20(local_3c8,s__GENERAL__005d6710);
    if (iVar4 == 0) {
      iVar4 = FUN_00587c20(local_3c8,s__FRONTWING__005d6464);
      if (iVar4 == 0) {
        iVar4 = FUN_00587c20(local_3c8,s__LEFTFENDER__005d63b0);
        if (iVar4 == 0) {
          iVar4 = FUN_00587c20(local_3c8,s__RIGHTFENDER__005d63a0);
          if (iVar4 == 0) {
            iVar4 = FUN_00587c20(local_3c8,s__REARWING__005d6394);
            if (iVar4 == 0) {
              iVar4 = FUN_00587c20(local_3c8,s__BODYAERO__005d6300);
              if (iVar4 == 0) {
                iVar4 = FUN_00587c20(local_3c8,s__DIFFUSER__005d61d4);
                if (iVar4 == 0) {
                  iVar4 = FUN_00587c20(local_3c8,s__SUSPENSION__005d617c);
                  if (iVar4 == 0) {
                    iVar4 = FUN_00587c20(local_3c8,s__CONTROLS__005d5b14);
                    if (iVar4 == 0) {
                      iVar4 = FUN_00587c20(local_3c8,s__ENGINE__005d59ec);
                      if (iVar4 == 0) {
                        iVar4 = FUN_00587c20(local_3c8,s__DRIVELINE__005d59c4);
                        if (iVar4 == 0) {
                          iVar4 = FUN_00587c20(local_3c8,s__FRONTLEFT__005d5790);
                          if (iVar4 == 0) {
                            iVar4 = FUN_00587c20(local_3c8,s__FRONTRIGHT__005d5780);
                            if (iVar4 == 0) {
                              iVar4 = FUN_00587c20(local_3c8,s__REARLEFT__005d5774);
                              if (iVar4 == 0) {
                                iVar4 = FUN_00587c20(local_3c8,s__REARRIGHT__005d5768);
                                if (iVar4 == 0) {
                                  iVar4 = FUN_00587c20(local_3c8,s__BASIC__005d5760);
                                  if (iVar4 != 0) {
                                    iVar4 = FUN_005351d0(0x180);
                                    while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                                      if (iVar4 == 0) {
                                        FUN_004317f0(local_560,0,s_Downforce_005d5754);
                                        FUN_004317f0(local_560,1,s_Balance_005d574c);
                                        FUN_004317f0(local_560,2,&DAT_005d5744);
                                        FUN_004317f0(local_560,3,s_Gearing_005d573c);
                                        iVar4 = FUN_00565760(s_Custom_005c670c,aiStack_570,0,0,0);
                                        if (iVar4 != 0) {
                                          *(bool *)(param_3 + 0x19a4) = aiStack_570[0] != 0;
                                        }
                                      }
                                      iVar4 = FUN_005351d0(0x180);
                                    }
                                  }
                                }
                                else {
                                  FUN_004f2c60(3,iVar10,local_560,param_3);
                                }
                              }
                              else {
                                FUN_004f2c60(2,iVar10,local_560,param_3);
                              }
                            }
                            else {
                              FUN_004f2c60(1,iVar10,local_560,param_3);
                            }
                          }
                          else {
                            FUN_004f2c60(0,iVar10,local_560,param_3);
                          }
                        }
                        else {
                          iVar4 = FUN_005351d0(0x180);
                          if (iVar4 != 0) {
                            while( true ) {
                              iVar4 = FUN_005651b0();
                              if (iVar4 == 1) goto LAB_004f63a3;
                              if (iVar4 == 0) break;
                              iVar4 = FUN_005351d0(0x180);
                              if (iVar4 == 0) goto LAB_004f63a3;
                            }
                            FUN_00565aa0(s_ClutchInertia_005d59b4,param_1 + 0x1374,0,0,0);
                            FUN_00565aa0(s_ClutchTorque_005d59a4,param_1 + 0x137c,0,0,0);
                            FUN_00565aa0(s_ClutchWear_005d5998,param_1 + 0x1384,0,0,0);
                            FUN_00565aa0(s_ClutchFriction_005d5988,param_1 + 0x138c,0,0,0);
                            FUN_00565aa0(s_BaulkTorque_005d597c,param_1 + 0x1394,0,0,0);
                            FUN_005655f0(s_AllowManualOverride_005d5968,param_1 + 0x139c,0,0,0);
                            FUN_005655f0(s_SemiAutomatic_005d5958,param_1 + 0x139d,0,0,0);
                            FUN_00565aa0(s_UpshiftDelay_005d5948,param_1 + 0x13a0,0,0,0);
                            FUN_00565aa0(s_UpshiftClutchTime_005d5934,param_1 + 0x13a8,0,0,0);
                            FUN_00565aa0(s_DownshiftDelay_005d5924,param_1 + 0x13b0,0,0,0);
                            FUN_00565aa0(s_DownshiftClutchTime_005d5910,param_1 + 0x13b8,0,0,0);
                            FUN_00565aa0(s_DiffPumpTorque_005d5900,param_1 + 0x13c8,0,0,0);
                            iVar10 = FUN_005654a0(s_WheelDrive_005d58f4,local_108);
                            if (iVar10 != 0) {
                              iVar10 = FUN_00588410(local_108,&DAT_005d58ef);
                              if (iVar10 == 0) {
                                *(undefined4 *)(param_1 + 0x13c0) = 0;
                              }
                              else {
                                iVar10 = FUN_00588410(local_108,&DAT_005d58ea);
                                if (iVar10 == 0) {
                                  *(undefined4 *)(param_1 + 0x13c0) = 1;
                                }
                                else {
                                  iVar10 = FUN_00588410(local_108,s_FRONT_005d58e4);
                                  if (iVar10 == 0) {
                                    *(undefined4 *)(param_1 + 0x13c0) = 2;
                                  }
                                }
                              }
                            }
                            iVar10 = FUN_005654a0(s_GearFile_005d58b6,local_108);
                            if (iVar10 == 0) goto LAB_004f60f0;
                            iVar10 = 2 - (int)param_2;
                            do {
                              cVar3 = *param_2;
                              param_2[(int)(acStack_20a + iVar10)] = cVar3;
                              param_2 = param_2 + 1;
                            } while (cVar3 != '\0');
                            uVar11 = 0xffffffff;
                            pcVar8 = acStack_20a + 2;
                            do {
                              if (uVar11 == 0) break;
                              uVar11 = uVar11 - 1;
                              cVar3 = *pcVar8;
                              pcVar8 = pcVar8 + 1;
                            } while (cVar3 != '\0');
                            if ((0 < (int)(~uVar11 - 1)) &&
                               (pcVar8 = acStack_20a + ~uVar11, acStack_20a + 2 <= pcVar8)) {
                              do {
                                if (*pcVar8 == '\\') break;
                                *pcVar8 = '\0';
                                pcVar8 = pcVar8 + -1;
                              } while (acStack_20a + 2 <= pcVar8);
                            }
                            iVar10 = FUN_004c40d0(local_108,&DAT_005d2ea4,acStack_20a + 2,&local_590
                                                 );
                            if (iVar10 == 0) {
                              if ((param_4 & 2) == 0) {
                                puVar7 = local_590;
                                if (local_590 == (undefined1 *)0x0) {
                                  puVar7 = &DAT_005ea438;
                                }
                                FUN_0042ecc0(puVar7);
                              }
                              puVar7 = local_590;
                              if (local_590 == (undefined1 *)0x0) {
                                puVar7 = &DAT_005ea438;
                              }
                              FUN_00566650(puVar7);
                            }
LAB_004f60f0:
                            FUN_00565760(s_ForwardGears_005d58a9,param_1 + 0x13c4,0,0,0);
                            FUN_00565760(s_Gear1Setting_005d589c,local_584,0,0,0);
                            FUN_00565760(s_Gear2Setting_005d588f,local_584,0,0,0);
                            FUN_00565760(s_Gear3Setting_005d5882,local_584,0,0,0);
                            FUN_00565760(s_Gear4Setting_005d5875,local_584,0,0,0);
                            FUN_00565760(s_Gear5Setting_005d5868,local_584,0,0,0);
                            FUN_00565760(s_Gear6Setting_005d585b,local_584,0,0,0);
                            uVar9 = FUN_0059d822();
                            return uVar9;
                          }
LAB_004f63a3:
                          iVar4 = 0x2c;
                          if (0x2c < *(int *)(param_1 + 0x13c4) + 0x2c) {
                            puVar7 = (undefined1 *)(param_3 + 0x16cc);
                            do {
                              *puVar7 = 1;
                              iVar4 = iVar4 + 1;
                              puVar7 = puVar7 + 0x40;
                            } while (iVar4 < *(int *)(param_1 + 0x13c4) + 0x2c);
                            if (0x32 < iVar4) goto LAB_004f66cd;
                          }
                          puVar7 = (undefined1 *)(iVar4 * 0x40 + 0xbcc + param_3);
                          iVar4 = 0x33 - iVar4;
                          do {
                            *puVar7 = 0;
                            puVar7 = puVar7 + 0x40;
                            iVar4 = iVar4 + -1;
                          } while (iVar4 != 0);
                        }
                      }
                      else {
                        local_248 = DAT_005ea438;
                        puVar6 = &local_247;
                        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
                          *puVar6 = 0;
                          puVar6 = puVar6 + 1;
                        }
                        *(undefined2 *)puVar6 = 0;
                        *(undefined1 *)((int)puVar6 + 2) = 0;
                        bVar2 = false;
                        iVar4 = FUN_004c58a0(&local_248,0x20,s_RestrictorPlate_005d59dc,0);
                        if ((iVar4 == 0) &&
                           (((iVar4 = FUN_00588410(&local_248,&DAT_005d59d4), iVar4 == 0 ||
                             (iVar4 = FUN_00588410(&local_248,&PTR_DAT_005d59d0), iVar4 == 0)) ||
                            (iVar4 = FUN_00587ece(&local_248), iVar4 == 1)))) {
                          bVar2 = true;
                        }
                        iVar4 = FUN_005351d0(0x180);
                        while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                          if (iVar4 == 0) {
                            if (local_568 == 0) {
                              iVar4 = FUN_005654a0(s_RestrictorPlate_005d59dc,local_108);
                              local_57c = iVar4;
                              local_580 = FUN_005654a0(s_Normal_005c6e74,local_108);
                              if (local_580 != iVar4) {
                                pcVar8 = param_2;
                                do {
                                  cVar3 = *pcVar8;
                                  pcVar8[(int)(acStack_20a + (2 - (int)param_2))] = cVar3;
                                  pcVar8 = pcVar8 + 1;
                                } while (cVar3 != '\0');
                                uVar11 = 0xffffffff;
                                pcVar8 = acStack_20a + 2;
                                do {
                                  if (uVar11 == 0) break;
                                  uVar11 = uVar11 - 1;
                                  cVar3 = *pcVar8;
                                  pcVar8 = pcVar8 + 1;
                                } while (cVar3 != '\0');
                                if ((0 < (int)(~uVar11 - 1)) &&
                                   (pcVar8 = acStack_20a + ~uVar11, acStack_20a + 2 <= pcVar8)) {
                                  do {
                                    if (*pcVar8 == '\\') break;
                                    *pcVar8 = '\0';
                                    pcVar8 = pcVar8 + -1;
                                  } while (acStack_20a + 2 <= pcVar8);
                                }
                                iVar5 = FUN_004c40d0(local_108,&DAT_005d2ea4,acStack_20a + 2,
                                                     &local_590);
                                iVar4 = local_57c;
                                if (iVar5 == 0) {
                                  if ((((local_57c != 0) && (bVar2)) ||
                                      ((local_580 != 0 && (!bVar2)))) && ((param_4 & 2) == 0)) {
                                    puVar7 = local_590;
                                    if (local_590 == (undefined1 *)0x0) {
                                      puVar7 = &DAT_005ea438;
                                    }
                                    FUN_004f3c80(puVar7,param_3);
                                  }
                                  puVar7 = local_590;
                                  if (iVar4 == 0) {
                                    if (local_590 == (undefined1 *)0x0) {
                                      puVar7 = &DAT_005ea438;
                                    }
                                  }
                                  else if (local_590 == (undefined1 *)0x0) {
                                    puVar7 = &DAT_005ea438;
                                  }
                                  FUN_00566650(puVar7);
                                }
                              }
                            }
                            FUN_004f3c10(local_560,param_3);
                          }
                          iVar4 = FUN_005351d0(0x180);
                        }
                        dVar1 = *(double *)(param_1 + 0x67c) * *(double *)(param_1 + 0x674) *
                                (double)_DAT_005ea40c * (double)DAT_007d0b64;
                        if (dVar1 <= _DAT_0059e430) {
                          *(undefined4 *)(param_3 + 0x1994) = 0;
                          *(undefined4 *)(param_3 + 0x1998) = 0;
                        }
                        else {
                          *(double *)(param_3 + 0x1994) = _DAT_0059e420 / dVar1;
                        }
                      }
                    }
                    else {
                      iVar4 = FUN_005351d0(0x180);
                      while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                        if (iVar4 == 0) {
                          FUN_00565aa0(s_AutoUpshiftGripThresh_005d5afc,param_1 + 0x620,0,0,0);
                          FUN_00565aa0(s_AutoDownshiftGripThresh_005d5ae4,param_1 + 0x628,0,0,0);
                          FUN_00565aa0(s_TractionControlGrip_005d5ad0,param_1 + 0x630,
                                       param_1 + 0x638,0,0);
                          FUN_00565aa0(s_TractionControlLevel_005d5ab8,param_1 + 0x640,
                                       param_1 + 0x648,0,0);
                          FUN_005655f0(s_ABS4Wheel_005d5aac,param_1 + 0x650,0,0,0);
                          FUN_00565aa0(s_ABSGrip_005d5aa4,param_1 + 0x654,param_1 + 0x65c,0,0);
                          FUN_00565aa0(s_ABSLevel_005d5a98,param_1 + 0x664,param_1 + 0x66c,0,0);
                          FUN_0042e1f0(local_560,s_SteerLockRange_005d5a74,
                                       s_SteerLockSetting_005d5a84,0xa2529d39,0x3f91df46);
                          FUN_0042e1f0(local_560,s_RearBrakeRange_005d5a50,
                                       s_RearBrakeSetting_005d5a60,0,0x3ff00000);
                          FUN_0042e1f0(local_560,s_BrakePressureRange_005d5a24,
                                       s_BrakePressureSetting_005d5a38,0,0x3ff00000);
                          FUN_0042e1f0(local_560,s_HandbrakePressRange_005d59f8,
                                       s_HandbrakePressSetting_005d5a0c,0,0x3ff00000);
                        }
                        iVar4 = FUN_005351d0(0x180);
                      }
                    }
                  }
                  else {
                    iVar4 = FUN_005351d0(0x180);
                    while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                      if (iVar4 == 0) {
                        iVar4 = FUN_005654a0(s_PhysicalModelFile_005d6168,local_108);
                        if (iVar4 != 0) {
                          pcVar8 = param_2;
                          do {
                            cVar3 = *pcVar8;
                            pcVar8[(int)(acStack_20a + (2 - (int)param_2))] = cVar3;
                            pcVar8 = pcVar8 + 1;
                          } while (cVar3 != '\0');
                          uVar11 = 0xffffffff;
                          pcVar8 = acStack_20a + 2;
                          do {
                            if (uVar11 == 0) break;
                            uVar11 = uVar11 - 1;
                            cVar3 = *pcVar8;
                            pcVar8 = pcVar8 + 1;
                          } while (cVar3 != '\0');
                          if ((0 < (int)(~uVar11 - 1)) &&
                             (pcVar8 = acStack_20a + ~uVar11, acStack_20a + 2 <= pcVar8)) {
                            do {
                              if (*pcVar8 == '\\') break;
                              *pcVar8 = '\0';
                              pcVar8 = pcVar8 + -1;
                            } while (acStack_20a + 2 <= pcVar8);
                          }
                          FUN_004c40d0(local_108,&DAT_005d6164,acStack_20a + 2,param_1 + 0x2c);
                        }
                        iVar4 = FUN_005655f0(s_ApplySlowToFastDampers_005d614c,
                                             (undefined1 *)(param_1 + 0x548),0,0,0);
                        if (iVar4 != 0) {
                          *(undefined1 *)(param_3 + 0x1988) = *(undefined1 *)(param_1 + 0x548);
                        }
                        FUN_005655f0(s_AdjustSuspRates_005d613c,param_1 + 0x549,0,0,0);
                        FUN_005655f0(s_AlignWheels_005d6130,param_1 + 0x54a,0,0,0);
                        FUN_00565aa0(s_FrontWheelTrack_005d6120,param_1 + 0x54c,0,0,0);
                        FUN_00565aa0(s_RearWheelTrack_005d6110,param_1 + 0x554,0,0,0);
                        FUN_00565aa0(s_LeftWheelBase_005d6100,param_1 + 0x55c,0,0,0);
                        FUN_00565aa0(s_RightWheelBase_005d60f0,param_1 + 0x564,0,0,0);
                        iVar4 = FUN_005655f0(s_SpringBasedAntiSway_005d60dc,
                                             (undefined1 *)(param_1 + 0x56c),0,0,0);
                        if (iVar4 != 0) {
                          *(undefined1 *)(param_3 + 0x1989) = *(undefined1 *)(param_1 + 0x56c);
                        }
                        FUN_00565aa0(s_FrontAntiSwayBase_005d60c8,param_1 + 0x570,0,0,0);
                        FUN_00565aa0(s_FrontAntiSwayRate_005d60b4,param_1 + 0x578,param_1 + 0x580,0,
                                     0);
                        FUN_00565aa0(s_RearAntiSwayBase_005d60a0,param_1 + 0x588,0,0,0);
                        FUN_00565aa0(s_RearAntiSwayRate_005d608c,param_1 + 0x590,param_1 + 0x598,0,0
                                    );
                        FUN_00565aa0(s_Front3rdBumpTravel_005d6078,param_1 + 0x5a0,0,0,0);
                        FUN_00565aa0(s_Front3rdReboundTravel_005d6060,param_1 + 0x5a8,0,0,0);
                        FUN_00565aa0(s_Front3rdBumpStopSpring_005d6048,param_1 + 0x5b0,0,0,0);
                        FUN_00565aa0(s_Front3rdBumpStopRisingSpring_005d6028,param_1 + 0x5b8,0,0,0);
                        FUN_00565aa0(s_Front3rdBumpStopDamper_005d6010,param_1 + 0x5c0,0,0,0);
                        FUN_00565aa0(s_Front3rdBumpStopRisingDamper_005d5ff0,param_1 + 0x5c8,0,0,0);
                        FUN_00565aa0(s_Front3rdBumpStage2_005d5fdc,param_1 + 0x5d0,0,0,0);
                        FUN_00565aa0(s_Front3rdReboundStage2_005d5fc4,param_1 + 0x5d8,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpTravel_005d5fb0,param_1 + 0x5e0,0,0,0);
                        FUN_00565aa0(s_Rear3rdReboundTravel_005d5f98,param_1 + 0x5e8,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpStopSpring_005d5f80,param_1 + 0x5f0,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpStopRisingSpring_005d5f64,param_1 + 0x5f8,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpStopDamper_005d5f4c,param_1 + 0x600,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpStopRisingDamper_005d5f30,param_1 + 0x608,0,0,0);
                        FUN_00565aa0(s_Rear3rdBumpStage2_005d5f1c,param_1 + 0x610,0,0,0);
                        FUN_00565aa0(s_Rear3rdReboundStage2_005d5f04,param_1 + 0x618,0,0,0);
                        FUN_0042e1f0(local_560,s_FrontAntiSwayRange_005d5ed8,
                                     s_FrontAntiSwaySetting_005d5eec,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_RearAntiSwayRange_005d5eb0,
                                     s_RearAntiSwaySetting_005d5ec4,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_FrontToeInRange_005d5e8c,
                                     s_FrontToeInSetting_005d5e9c,0xa2529d39,0x3f91df46);
                        FUN_0042e1f0(local_560,s_RearToeInRange_005d5e68,s_RearToeInSetting_005d5e78
                                     ,0xa2529d39,0x3f91df46);
                        FUN_0042e1f0(local_560,s_LeftFenderFlareRange_005d5e38,
                                     s_LeftFenderFlareSetting_005d5e50,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_RightFenderFlareRange_005d5e08,
                                     s_RightFenderFlareSetting_005d5e20,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_LeftCasterRange_005d5de4,
                                     s_LeftCasterSetting_005d5df4,0xa2529d39,0x3f91df46);
                        FUN_0042e1f0(local_560,s_RightCasterRange_005d5dbc,
                                     s_RightCasterSetting_005d5dd0,0xa2529d39,0x3f91df46);
                        FUN_0042e1f0(local_560,s_LeftTrackBarRange_005d5d94,
                                     s_LeftTrackBarSetting_005d5da8,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_RightTrackBarRange_005d5d68,
                                     s_RightTrackBarSetting_005d5d7c,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdPackerRange_005d5d3c,
                                     s_Front3rdPackerSetting_005d5d50,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdSpringRange_005d5d10,
                                     s_Front3rdSpringSetting_005d5d24,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdSlowBumpRange_005d5ce0,
                                     s_Front3rdSlowBumpSetting_005d5cf8,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdFastBumpRange_005d5cb0,
                                     s_Front3rdFastBumpSetting_005d5cc8,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdSlowReboundRange_005d5c78,
                                     s_Front3rdSlowReboundSetting_005d5c94,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Front3rdFastReboundRange_005d5c40,
                                     s_Front3rdFastReboundSetting_005d5c5c,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdPackerRange_005d5c14,
                                     s_Rear3rdPackerSetting_005d5c28,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdSpringRange_005d5be8,
                                     s_Rear3rdSpringSetting_005d5bfc,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdSlowBumpRange_005d5bb8,
                                     s_Rear3rdSlowBumpSetting_005d5bd0,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdFastBumpRange_005d5b88,
                                     s_Rear3rdFastBumpSetting_005d5ba0,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdSlowReboundRange_005d5b54,
                                     s_Rear3rdSlowReboundSetting_005d5b6c,0,0x3ff00000);
                        FUN_0042e1f0(local_560,s_Rear3rdFastReboundRange_005d5b20,
                                     s_Rear3rdFastReboundSetting_005d5b38,0,0x3ff00000);
                      }
                      iVar4 = FUN_005351d0(0x180);
                    }
                  }
                }
                else {
                  iVar4 = FUN_005351d0(0x180);
                  while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                    if (iVar4 == 0) {
                      iVar4 = FUN_00565aa0(s_DiffuserBase_005d61c4,param_1 + 0x4d8,param_1 + 0x4e0,
                                           param_1 + 0x4e8,0);
                      if (iVar4 != 0) {
                        *(undefined1 *)(param_1 + 0x4d4) = 1;
                      }
                      FUN_00565aa0(s_DiffuserFrontHeight_005d61b0,param_1 + 0x4f0,0,0,0);
                      FUN_00565aa0(s_DiffuserSideways_005d619c,param_1 + 0x4f8,0,0,0);
                      FUN_00565aa0(s_DiffuserCenter_005d618c,param_1 + 0x500,param_1 + 0x508,
                                   param_1 + 0x510,0);
                    }
                    iVar4 = FUN_005351d0(0x180);
                  }
                }
              }
              else {
                iVar4 = FUN_005351d0(0x180);
                while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                  if (iVar4 == 0) {
                    FUN_00565aa0(s_BodyDragBase_005d62f0,param_1 + 0x3f4,0,0,0);
                    FUN_00565aa0(s_BodyDragHeightAvg_005d62dc,param_1 + 0x3fc,0,0,0);
                    FUN_00565aa0(s_BodyDragHeightDiff_005d62c8,param_1 + 0x404,0,0,0);
                    FUN_00565aa0(s_BodyMaxHeight_005d62b8,param_1 + 0x40c,0,0,0);
                    FUN_004f3240(local_560,0,s_BodyLeft_005d62ac);
                    FUN_004f3240(local_560,1,s_BodyRight_005d62a0);
                    FUN_004f3240(local_560,2,s_BodyUp_005d6298);
                    FUN_004f3240(local_560,3,s_BodyDown_005d628c);
                    FUN_004f3240(local_560,4,s_BodyAft_005d6284);
                    FUN_004f3240(local_560,5,s_BodyFore_005d6278);
                    FUN_004f3490(local_560,s_BodyRot_005d6270);
                    FUN_00565aa0(s_BodyCenter_005d6264,param_1 + 0x414,param_1 + 0x41c,
                                 param_1 + 0x424,0);
                    FUN_00565aa0(s_RadiatorDrag_005d6254,param_1 + 0x518,0,0,0);
                    FUN_00565aa0(s_RadiatorLift_005d6244,param_1 + 0x520,0,0,0);
                    FUN_0042e1f0(local_560,s_RadiatorRange_005d6224,s_RadiatorSetting_005d6234,0,
                                 0x3ff00000);
                    FUN_00565aa0(s_BrakeDuctDrag_005d6214,param_1 + 0x528,0,0,0);
                    FUN_00565aa0(s_BrakeDuctLift_005d6204,param_1 + 0x530,0,0,0);
                    FUN_0042e1f0(local_560,s_BrakeDuctRange_005d61e0,s_BrakeDuctSetting_005d61f0,0,
                                 0x3ff00000);
                  }
                  iVar4 = FUN_005351d0(0x180);
                }
              }
            }
            else {
              iVar4 = FUN_005351d0(0x180);
              while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
                if (iVar4 == 0) {
                  iVar4 = FUN_00565aa0(s_RWDragParams_005d6384,param_1 + 0x2fc,param_1 + 0x304,
                                       param_1 + 0x30c,0);
                  if (iVar4 != 0) {
                    *(undefined1 *)(param_1 + 0x2f8) = 1;
                  }
                  FUN_00565aa0(s_RWLiftParams_005d6374,param_1 + 0x314,param_1 + 0x31c,
                               param_1 + 0x324,0);
                  FUN_00565aa0(s_RWLiftSideways_005d6364,param_1 + 0x32c,0,0,0);
                  FUN_004f3240(local_560,0,s_RWLeft_005d635c);
                  FUN_004f3240(local_560,1,s_RWRight_005d6354);
                  FUN_004f3240(local_560,2,&DAT_005d634c);
                  FUN_004f3240(local_560,3,s_RWDown_005d6344);
                  FUN_004f3240(local_560,4,s_RWAft_005d633c);
                  FUN_004f3240(local_560,5,s_RWFore_005d6334);
                  FUN_004f3490(local_560,s_RWRot_005d632c);
                  FUN_00565aa0(s_RWCenter_005d6320,param_1 + 0x3dc,param_1 + 0x3e4,param_1 + 0x3ec,0
                              );
                  FUN_0042e1f0(local_560,s_RWRange_005d630c,s_RWSetting_005d6314,0,0x3ff00000);
                }
                iVar4 = FUN_005351d0(0x180);
              }
            }
          }
          else {
            FUN_004f3090(10,iVar10,local_560,param_3);
          }
        }
        else {
          FUN_004f3090(9,iVar10,local_560,param_3);
        }
      }
      else {
        iVar4 = FUN_005351d0(0x180);
        while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
          if (iVar4 == 0) {
            iVar4 = FUN_00565aa0(s_FWDragParams_005d6454,param_1 + 0x1f8,param_1 + 0x200,
                                 param_1 + 0x208,0);
            if (iVar4 != 0) {
              *(undefined1 *)(param_1 + 0x1ec) = 1;
            }
            FUN_00565aa0(s_FWLiftParams_005d6444,param_1 + 0x210,param_1 + 0x218,param_1 + 0x220,0);
            FUN_00565aa0(s_FWMaxHeight_005d6438,param_1 + 0x1f0,0,0,0);
            FUN_00565aa0(s_FWLiftHeight_005d6428,param_1 + 0x228,0,0,0);
            FUN_00565aa0(s_FWLiftSideways_005d6418,param_1 + 0x230,0,0,0);
            FUN_004f3240(local_560,0,s_FWLeft_005d6410);
            FUN_004f3240(local_560,1,s_FWRight_005d6408);
            FUN_004f3240(local_560,2,&DAT_005d6400);
            FUN_004f3240(local_560,3,s_FWDown_005d63f8);
            FUN_004f3240(local_560,4,s_FWAft_005d63f0);
            FUN_004f3240(local_560,5,s_FWFore_005d63e8);
            FUN_004f3490(local_560,s_FWRot_005d63e0);
            FUN_00565aa0(s_FWCenter_005d63d4,param_1 + 0x2e0,param_1 + 0x2e8,param_1 + 0x2f0,0);
            FUN_0042e1f0(local_560,s_FWRange_005d63c0,s_FWSetting_005d63c8,0,0x3ff00000);
          }
          iVar4 = FUN_005351d0(0x180);
        }
      }
    }
    else {
      iVar4 = FUN_005351d0(0x180);
      while ((iVar4 != 0 && (iVar4 = FUN_005651b0(), iVar4 != 1))) {
        if (iVar4 == 0) {
          iVar4 = FUN_00565760(s_Rules_005d6708,&local_564,0,0,0);
          if (iVar4 != 0) {
            *(undefined4 *)(param_1 + 0x34) = local_564;
            *(undefined4 *)(param_3 + 0x1990) = local_564;
          }
          iVar4 = FUN_00565760(s_GarageDisplayFlags_005d66f4,(undefined4 *)(param_1 + 0x38),0,0,0);
          if (iVar4 != 0) {
            *(undefined4 *)(param_3 + 0x198c) = *(undefined4 *)(param_1 + 0x38);
          }
          FUN_00565760(s_FeelerFlags_005d66e8,param_1 + 0x3c,0,0,0);
          FUN_00565aa0(&DAT_005d66e0,param_1 + 0x40,0,0,0);
          FUN_00565aa0(s_Inertia_005d66d8,param_1 + 0x48,param_1 + 0x50,param_1 + 0x58,0);
          FUN_00565aa0(s_CGHeight_005d66cc,param_1 + 0x60,0,0,0);
          iVar4 = FUN_00565aa0(s_WedgePushrod_005d66bc,(undefined8 *)(param_1 + 0x68),0,0,0);
          if (iVar4 != 0) {
            *(undefined8 *)(param_3 + 0x199c) = *(undefined8 *)(param_1 + 0x68);
          }
          FUN_00565aa0(s_GraphicalOffset_005d66ac,param_1 + 0x70,param_1 + 0x78,param_1 + 0x80,0);
          FUN_00565aa0(s_FLUndertray_005d66a0,param_1 + 0x1448,param_1 + 0x1450,param_1 + 0x1458,0);
          FUN_00565aa0(s_FRUndertray_005d6694,param_1 + 0x1550,param_1 + 0x1558,param_1 + 0x1560,0);
          FUN_00565aa0(s_RLUndertray_005d6688,param_1 + 0x1658,param_1 + 0x1660,param_1 + 0x1668,0);
          FUN_00565aa0(s_RRUndertray_005d667c,param_1 + 0x1760,param_1 + 0x1768,param_1 + 6000,0);
          iVar4 = FUN_005654a0(s_TireBrand_005d6670,param_1 + 0x88);
          if (iVar4 != 0) {
            pcVar8 = (char *)(param_1 + 0x88);
            uVar11 = 0xffffffff;
            pcVar12 = pcVar8;
            do {
              if (uVar11 == 0) break;
              uVar11 = uVar11 - 1;
              cVar3 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar3 != '\0');
            for (pcVar12 = pcVar8 + (~uVar11 - 1); pcVar8 < pcVar12; pcVar12 = pcVar12 + -1) {
              if (*pcVar12 == '.') {
                *pcVar12 = '\0';
                break;
              }
            }
            FUN_0042ed50(param_1 + 0x88);
            iVar4 = FUN_004d7880(param_1 + 0x88);
            if (iVar4 == 0) {
              if ((DAT_007c569c != 5) &&
                 (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x334),
                 cVar3 != '\0')) {
                FUN_004d7aa0(&DAT_008ad25c,s___hdv_file_references_unknown_ti_005c42f4,
                             param_1 + 0x88);
              }
            }
            else {
              *(undefined4 *)(param_3 + 0xbc0) = *(undefined4 *)(iVar4 + 0x10);
              puVar7 = *(undefined1 **)(iVar4 + 0x18);
              if (puVar7 == (undefined1 *)0x0) {
                puVar7 = &DAT_005ea438;
              }
              FUN_00566650(puVar7);
              *(int *)(param_1 + 8) = *(int *)(iVar4 + 0x20) + 0x20040229;
            }
          }
          FUN_00565aa0(s_FuelTankPos_005d6648,param_1 + 200,param_1 + 0xd0,param_1 + 0xd8,0);
          FUN_00565aa0(s_FuelTankMotion_005d6638,param_1 + 0xe0,param_1 + 0xe8,0,0);
          FUN_00565760(s_AIMinPassesPerTick_005d6624,param_1 + 0xf0,0,0,0);
          FUN_00565aa0(s_AIRotationThreshold_005d6610,param_1 + 0xf4,0,0,0);
          FUN_00565aa0(s_AIEvenSuspension_005d65fc,param_1 + 0xfc,0,0,0);
          FUN_00565aa0(s_AISpringRate_005d65ec,param_1 + 0x104,0,0,0);
          FUN_00565aa0(s_AIDamperSlow_005d65dc,param_1 + 0x10c,0,0,0);
          FUN_00565aa0(s_AIDamperFast_005d65cc,param_1 + 0x114,0,0,0);
          FUN_00565aa0(s_AIDownforceZArm_005d65bc,param_1 + 0x11c,0,0,0);
          FUN_00565aa0(s_AIDownforceBias_005d65ac,param_1 + 0x124,0,0,0);
          FUN_00565aa0(s_AITorqueStab_005d659c,param_1 + 300,param_1 + 0x134,param_1 + 0x13c,0);
          iVar4 = FUN_005654a0(s_Notes_005d6594,local_108);
          if (iVar4 != 0) {
            FUN_005665b0(local_108);
          }
          iVar4 = FUN_00565760(s_Symmetric_005d6588,&local_574,0,0,0);
          if (iVar4 != 0) {
            *(bool *)(param_3 + 0x19a5) = local_574 != 0;
          }
          iVar4 = FUN_005654a0(s_DamageFile_005d657c,local_108);
          if (iVar4 != 0) {
            pcVar8 = param_2;
            do {
              cVar3 = *pcVar8;
              pcVar8[(int)(acStack_20a + (2 - (int)param_2))] = cVar3;
              pcVar8 = pcVar8 + 1;
            } while (cVar3 != '\0');
            uVar11 = 0xffffffff;
            pcVar8 = acStack_20a + 2;
            do {
              if (uVar11 == 0) break;
              uVar11 = uVar11 - 1;
              cVar3 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar3 != '\0');
            if ((0 < (int)(~uVar11 - 1)) &&
               (pcVar8 = acStack_20a + ~uVar11, acStack_20a + 2 <= pcVar8)) {
              do {
                if (*pcVar8 == '\\') break;
                *pcVar8 = '\0';
                pcVar8 = pcVar8 + -1;
              } while (acStack_20a + 2 <= pcVar8);
            }
            iVar4 = FUN_004c40d0(local_108,&DAT_005d2ea4,acStack_20a + 2,&local_590);
            if (iVar4 == 0) {
              if ((param_4 & 2) == 0) {
                puVar7 = local_590;
                if (local_590 == (undefined1 *)0x0) {
                  puVar7 = &DAT_005ea438;
                }
                FUN_004f24f0(puVar7);
              }
              puVar7 = local_590;
              if (local_590 == (undefined1 *)0x0) {
                puVar7 = &DAT_005ea438;
              }
              FUN_00566650(puVar7);
            }
          }
          FUN_0042e1f0(local_560,s_CGRightRange_005d655c,s_CGRightSetting_005d656c,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_CGRearRange_005d6540,s_CGRearSetting_005d654c,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_WedgeRange_005d6524,s_WedgeSetting_005d6530,0,0x3ff00000);
          FUN_0042e1f0(local_560,0,s_TireCompoundSetting_005d6510,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_FuelRange_005d64f8,s_FuelSetting_005d6504,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_NumPitstopsRange_005d64d0,s_NumPitstopsSetting_005d64e4,0,
                       0x3ff00000);
          FUN_0042e1f0(local_560,s_Pitstop1Range_005d64b0,s_Pitstop1Setting_005d64c0,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_Pitstop2Range_005d6490,s_Pitstop2Setting_005d64a0,0,0x3ff00000);
          FUN_0042e1f0(local_560,s_Pitstop3Range_005d6470,s_Pitstop3Setting_005d6480,0,0x3ff00000);
        }
        iVar4 = FUN_005351d0(0x180);
      }
    }
  }
LAB_004f66cd:
  iVar4 = FUN_005351d0(0x180);
  goto joined_r0x004f44ab;
}


