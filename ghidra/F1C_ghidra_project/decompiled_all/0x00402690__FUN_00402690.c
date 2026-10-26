// Function: FUN_00402690 @ 00402690
// Strings:  [wp_ptrs, wp_bitfields, wp_dwidth, wp_width, wp_perp, wp_score, wp_groove_lat, wp_galpha]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00402690(int param_1,int param_2)

{
  int *piVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_364;
  float local_360;
  int local_35c;
  int local_358;
  float local_354;
  undefined4 local_350;
  float local_34c;
  float local_348;
  undefined1 local_344 [4];
  float local_340;
  float local_33c;
  int *local_338;
  int local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined1 local_324 [4];
  int local_320;
  int local_31c;
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  puVar3 = local_180;
  for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  local_334 = 0;
  local_320 = 0;
  FUN_004034d0();
  FUN_00403350();
  *(undefined1 *)(param_1 + 300) = 0;
  piVar5 = local_338;
  if (param_2 != 0) {
LAB_00402700:
    do {
      iVar6 = FUN_00587ca0(local_180,0x180,param_2);
      if (iVar6 == 0) break;
      iVar6 = FUN_00587c20(local_180,s__Features__005be684);
      if (iVar6 != 0) {
        iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        while ((iVar6 != 0 && (iVar6 = FUN_005651b0(), iVar6 != 1))) {
          if (iVar6 == 0) {
            FUN_00565760(s_pitlanes_005be678,param_1 + 0x15c,0,0,0);
            piVar1 = (int *)(param_1 + 0x160);
            FUN_00565760(s_startinggrid_005be668,piVar1,0,0,0);
            if (*piVar1 < 0x68) {
              *piVar1 = 0x68;
            }
            piVar1 = (int *)(param_1 + 0x164);
            FUN_00565760(s_pitspots_005be65c,piVar1,0,0,0);
            if (*piVar1 < 0x34) {
              *piVar1 = 0x34;
            }
            piVar1 = (int *)(param_1 + 0x168);
            FUN_00565760(s_garagespots_005be650,piVar1,0,0,0);
            if (*piVar1 < 3) {
              *piVar1 = 3;
            }
          }
          iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        }
        FUN_00403350();
      }
      iVar6 = FUN_00587c20(local_180,s__GRID__005be648);
      if (iVar6 != 0) {
        local_35c = -1;
        iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        while ((iVar6 != 0 && (iVar6 = FUN_005651b0(), iVar6 != 1))) {
          if ((iVar6 == 0) &&
             (iVar6 = FUN_00565760(s_GridIndex_005be63c,&local_35c,0,0,0), iVar6 == 0)) {
            iVar6 = FUN_00565870(&PTR_DAT_005be638,&local_330,&local_32c,&local_328,0,0,0,0,0);
            if (iVar6 == 0) {
              iVar6 = FUN_00565870(&PTR_DAT_005be634,&local_330,&local_32c,&local_328,0,0,0,0,0);
              if (((iVar6 != 0) && (-1 < local_35c)) && (local_35c < 0x68)) {
                puVar3 = (undefined4 *)(*(int *)(param_1 + 0x150) + 0xc + local_35c * 0x1c);
                goto LAB_00402933;
              }
            }
            else if ((-1 < local_35c) && (local_35c < 0x68)) {
              puVar3 = (undefined4 *)(local_35c * 0x1c + *(int *)(param_1 + 0x150));
LAB_00402933:
              *puVar3 = local_330;
              puVar3[1] = local_32c;
              puVar3[2] = local_328;
            }
          }
          iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        }
      }
      iVar6 = FUN_00587c20(local_180,s__PITS__005be62c);
      if (iVar6 != 0) {
        local_35c = -1;
        iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        while ((iVar6 != 0 && (iVar6 = FUN_005651b0(), iVar6 != 1))) {
          if ((iVar6 == 0) &&
             (iVar6 = FUN_00565760(s_TeamIndex_005be620,&local_35c,0,0,0), iVar6 == 0)) {
            iVar6 = FUN_00565870(s_PitPos_005be618,&local_350,&local_34c,&local_348,0,0,0,0,0);
            if (iVar6 == 0) {
              iVar6 = FUN_00565870(s_PitOri_005be610,&local_350,&local_34c,&local_348,0,0,0,0,0);
              if (iVar6 == 0) {
                iVar6 = FUN_00565870(s_GarPos_005be608,local_324,&local_350,&local_34c,&local_348,0,
                                     0,0,0);
                if (iVar6 == 0) {
                  iVar6 = FUN_00565870(s_GarOri_005be600,local_324,&local_350,&local_34c,&local_348,
                                       0,0,0,0);
                  if (iVar6 == 0) goto LAB_00402b5b;
                  iVar6 = __ftol();
                  puVar3 = (undefined4 *)
                           ((*(int *)(param_1 + 0x164) * iVar6 + local_35c) * 0x1c + 0xc +
                           *(int *)(param_1 + 0x158));
                  fVar8 = extraout_ST0_00;
                  fVar7 = extraout_ST1_00;
                }
                else {
                  iVar6 = __ftol();
                  puVar3 = (undefined4 *)
                           ((*(int *)(param_1 + 0x164) * iVar6 + local_35c) * 0x1c +
                           *(int *)(param_1 + 0x158));
                  fVar8 = extraout_ST0;
                  fVar7 = extraout_ST1;
                }
              }
              else {
                if ((local_35c < 0) || (0x33 < local_35c)) goto LAB_00402b5b;
                fVar7 = (float10)local_348;
                fVar8 = (float10)local_34c;
                puVar3 = (undefined4 *)(local_35c * 0x1c + 0xc + *(int *)(param_1 + 0x154));
              }
            }
            else {
              if ((local_35c < 0) || (0x33 < local_35c)) goto LAB_00402b5b;
              fVar7 = (float10)local_348;
              fVar8 = (float10)local_34c;
              puVar3 = (undefined4 *)(local_35c * 0x1c + *(int *)(param_1 + 0x154));
            }
            *puVar3 = local_350;
            puVar3[1] = (float)fVar8;
            puVar3[2] = (float)fVar7;
          }
LAB_00402b5b:
          iVar6 = FUN_00587ca0(local_180,0x180,param_2);
        }
      }
      iVar6 = FUN_005651b0();
      if (iVar6 == 0) {
        iVar4 = FUN_00565760(s_number_waypoints_005be5ec,&local_358,0,0,0);
        iVar6 = local_358;
        if (iVar4 == 0) {
          iVar6 = FUN_00565760(s_LeftHandedPits_005be5dc,&local_358,0,0,0);
          if (iVar6 == 0) {
            pfVar2 = (float *)(param_1 + 0x11c);
            iVar6 = FUN_00565870(s_WorstAdjust_005be5d0,pfVar2,0,0,0,0,0,0,0);
            if (iVar6 == 0) {
              iVar6 = FUN_00565870(s_MidAdjust_005be5c4,param_1 + 0x120,0,0,0,0,0,0,0);
              if (iVar6 == 0) {
                pfVar2 = (float *)(param_1 + 0x124);
                iVar6 = FUN_00565870(s_BestAdjust_005be5b8,pfVar2,0,0,0,0,0,0,0);
                if (iVar6 == 0) {
                  iVar6 = FUN_00565870(s_RaceQualRatio_005be5a8,param_1 + 0x128,0,0,0,0,0,0,0);
                  if (((((iVar6 == 0) &&
                        (iVar6 = FUN_00565870(s_lap_length_005be59c,param_1 + 0x13c,0,0,0,0,0,0,0),
                        iVar6 == 0)) &&
                       (iVar6 = FUN_00565870(s_sector_1_length_005be58c,param_1 + 0x140,0,0,0,0,0,0,
                                             0), iVar6 == 0)) &&
                      ((iVar6 = FUN_00565870(s_sector_2_length_005be57c,param_1 + 0x144,0,0,0,0,0,0,
                                             0), iVar6 == 0 &&
                       (iVar6 = FUN_00565870(s_FuelUse_005be574,param_1 + 0x14c,0,0,0,0,0,0,0),
                       iVar6 == 0)))) &&
                     ((iVar6 = FUN_00565870(s_GrooveWidth_005be568,param_1,0,0,0,0,0,0,0),
                      iVar6 == 0 &&
                      (iVar6 = FUN_00565870(s_GrooveWidthWet_005be558,param_1 + 4,0,0,0,0,0,0,0),
                      iVar6 == 0)))) {
                    iVar6 = FUN_00565870(s_IntermediateFogLevel_005be540,&local_364,0,0,0,0,0,0,0);
                    if (iVar6 == 0) {
                      iVar6 = FUN_00565870(s_IntermediateFogPlanes_005be528,&local_364,&local_360,0,
                                           0,0,0,0,0);
                      if (iVar6 == 0) {
                        iVar6 = FUN_00565870(s_RainyFogPlanes_005be518,&local_364,&local_360,0,0,0,0
                                             ,0,0);
                        if (iVar6 == 0) {
                          iVar6 = FUN_00565870(s_IntermediateFogColor_005be500,&local_364,&local_360
                                               ,&local_354,0,0,0,0,0);
                          if (iVar6 == 0) {
                            iVar6 = FUN_00565870(s_RainyFogColor_005be4f0,&local_364,&local_360,
                                                 &local_354,0,0,0,0,0);
                            if (iVar6 == 0) {
                              iVar6 = FUN_00565870(s_FogDensity_005be4e4,&local_364,&local_360,0,0,0
                                                   ,0,0,0);
                              if (iVar6 == 0) {
                                iVar6 = FUN_00565870(s_RainyDarkness_005be4d4,&local_364,&local_360,
                                                     0,0,0,0,0,0);
                                if (iVar6 != 0) {
                                  FUN_004ff040(local_364,local_360);
                                }
                              }
                              else {
                                _DAT_008affac = local_364;
                                _DAT_008affb8 = local_360;
                              }
                            }
                            else {
                              _DAT_008aff8c = local_364 * _DAT_0059e460;
                              _DAT_008aff90 = local_360 * _DAT_0059e460;
                              _DAT_008aff94 = local_354 * _DAT_0059e460;
                            }
                          }
                          else {
                            _DAT_008aff80 = local_364 * _DAT_0059e460;
                            _DAT_008aff84 = local_360 * _DAT_0059e460;
                            _DAT_008aff88 = local_354 * _DAT_0059e460;
                          }
                        }
                        else {
                          _DAT_008affb0 = local_364;
                          _DAT_008affb4 = local_360;
                        }
                      }
                      else {
                        _DAT_008affa4 = local_364;
                        _DAT_008affa8 = local_360;
                      }
                    }
                    else {
                      FUN_004fefc0(local_364);
                    }
                  }
                }
                else if (_DAT_0059e464 < *pfVar2) {
                  *pfVar2 = 1.3;
                }
              }
            }
            else if (*pfVar2 < _DAT_0059e450) {
              *pfVar2 = 0.5;
            }
          }
          else {
            *(bool *)(param_1 + 300) = local_358 != 0;
          }
        }
        else {
          local_320 = local_358;
          piVar5 = operator_new(local_358 * 0x13c + 4);
          if (piVar5 == (int *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            *piVar5 = iVar6;
            piVar5 = piVar5 + 1;
            if (-1 < iVar6 + -1) {
              do {
                FUN_004fad80();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          *(int **)(param_1 + 0x134) = piVar5;
          if (piVar5 != (int *)0x0) {
            *(int *)(param_1 + 0x130) = local_358;
          }
          local_334 = 0;
        }
        FUN_00565760(s_wp_branchID_005be4c8,piVar5 + 0x4b,0,0,0);
        FUN_00565870(s_wp_path_005be4c0,piVar5 + 6,piVar5 + 7,0,0,0,0,0,0);
        iVar6 = FUN_00565870(s_wp_event_005be4b4,piVar5 + 0x21,&local_340,&local_33c,0,0,0,0,0);
        if (iVar6 != 0) {
          local_31c = (int)ROUND(local_340);
          piVar5[0x4d] = local_31c;
          local_338 = (int *)(int)ROUND(local_33c);
          piVar5[0x4e] = (int)local_338;
        }
        FUN_00565760(s_wp_wpse_005be4ac,piVar5 + 0x4d,piVar5 + 0x4e,0,0);
        iVar6 = FUN_00565870(s_wp_pos_005be4a4,piVar5,piVar5 + 1,piVar5 + 2,0,0,0,0,0);
        if (iVar6 != 0) {
          piVar5[0x25] = *piVar5;
          piVar5[0x26] = piVar5[1];
          piVar5[0x27] = piVar5[2];
        }
        FUN_00565870(s_wp_galpha_005be498,piVar5 + 0x46,0,0,0,0,0,0,0);
        FUN_00565870(s_wp_groove_lat_005be488,piVar5 + 0x47,0,0,0,0,0,0,0);
        iVar6 = FUN_00565870(s_wp_score_005be47c,local_344,piVar5 + 0x12,0,0,0,0,0,0);
        if (iVar6 != 0) {
          iVar6 = __ftol();
          piVar5[0x11] = iVar6;
        }
        FUN_00565870(s_wp_perp_005be474,piVar5 + 8,piVar5 + 9,piVar5 + 10,0,0,0,0,0);
        FUN_00565870(s_wp_width_005be468,piVar5 + 0xb,piVar5 + 0xc,piVar5 + 0xd,piVar5 + 0xe,0,0,0,0
                    );
        FUN_00565870(s_wp_dwidth_005be45c,piVar5 + 0x16,piVar5 + 0x17,piVar5 + 0x18,piVar5 + 0x19,0,
                     0,0,0);
        FUN_00565760(s_wp_bitfields_005be44c,piVar5 + 0x4c,0,0,0);
        iVar6 = FUN_00565760(s_wp_ptrs_005be444,piVar5 + 0x48,piVar5 + 0x49,piVar5 + 0x4a,0);
        if (iVar6 != 0) {
          if (*(int *)(param_1 + 0x130) <= local_334) {
            return;
          }
          local_334 = local_334 + 1;
          piVar5 = (int *)(local_334 * 0x13c + *(int *)(param_1 + 0x134));
        }
        goto LAB_00402700;
      }
    } while (iVar6 != 4);
    if (local_320 != 0) goto LAB_00403318;
  }
  iVar6 = 2;
  *(undefined4 *)(param_1 + 0x130) = 2;
  puVar3 = operator_new(0x27c);
  if (puVar3 == (undefined4 *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *puVar3 = 2;
    local_338 = puVar3 + 1;
    do {
      FUN_004fad80();
      iVar6 = iVar6 + -1;
      piVar5 = local_338;
    } while (iVar6 != 0);
  }
  *(int **)(param_1 + 0x134) = piVar5;
  piVar5[0x49] = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x120) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x128) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x1d8) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x260) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x25c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x264) = 0xffffffff;
LAB_00403318:
  FUN_00403540();
  iVar6 = local_334;
  if (0 < local_334) {
    do {
      FUN_004faec0();
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return;
}


