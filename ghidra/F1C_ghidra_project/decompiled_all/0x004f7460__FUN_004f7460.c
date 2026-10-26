// Function: FUN_004f7460 @ 004f7460
// Strings:  [VS_INSIDE_, VS_OUTSIDE_, OtherAmbient, OtherShape, OtherRange, ShiftAmbient, ShiftShape, ShiftRange]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f7460(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 local_398;
  undefined1 local_394 [64];
  float local_354;
  float local_350;
  float local_34c;
  float local_348;
  float local_344;
  float local_340 [2];
  undefined4 local_338;
  int local_334 [103];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  char local_180 [10];
  undefined1 local_176;
  undefined1 local_175 [373];
  
  FUN_005668b0();
  pcVar4 = local_180;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = pcVar4 + 4;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  local_340[0] = 0.0;
  local_34c = 0.0;
  local_344 = 0.0;
  local_354 = 0.0;
  local_348 = 0.0;
  local_350 = 0.0;
  FUN_00566b20(param_1,1);
  uVar1 = 1;
  if (local_334[0] != 0) {
    local_338 = 0;
    iVar2 = FUN_00566cc0(local_180,0x180);
    while (iVar2 != 0) {
      iVar2 = FUN_005651b0();
      if (iVar2 == 0) {
        iVar2 = _strncmp(local_180,s_VS_INSIDE__005d6770,10);
        if (iVar2 == 0) {
          puVar3 = &local_176;
        }
        else {
          iVar2 = _strncmp(local_180,s_VS_OUTSIDE__005d677c,0xb);
          if (iVar2 != 0) {
            iVar2 = FUN_00565760(s_EngineRPMSound_005d6cf0,&local_398,0,0,0);
            if (iVar2 == 0) {
              iVar2 = FUN_00565760(s_EngineRPMSoundInside_005d6cd8,&local_398,0,0,0);
              if (iVar2 == 0) {
                iVar2 = FUN_00565760(s_EngineRPMSoundOutside_005d6cc0,&local_398,0,0,0);
                if (iVar2 == 0) {
                  FUN_00565870(s_playerEngineVolumeMinimum_005d6ca4,local_340,0,0,0,0,0,0,0);
                  FUN_00565870(s_playerEngineVolumeThrottleFracti_005d6c80,&local_34c,0,0,0,0,0,0,0)
                  ;
                  FUN_00565870(s_playerEngineVolumeRevFraction_005d6c60,&local_344,0,0,0,0,0,0,0);
                  FUN_00565870(s_non_playerEngineVolumeMinimum_005d6c40,&local_354,0,0,0,0,0,0,0);
                  FUN_00565870(s_non_playerEngineVolumeThrottleFr_005d6c18,&local_348,0,0,0,0,0,0,0)
                  ;
                  FUN_00565870(s_non_playerEngineVolumeRevFractio_005d6bf4,&local_350,0,0,0,0,0,0,0)
                  ;
                  FUN_00565870(s_EngineRange_005d6be8,&DAT_005d67b0,0,0,0,0,0,0,0);
                  FUN_00565870(s_EngineShape_005d6bdc,&DAT_005d67b4,0,0,0,0,0,0,0);
                  FUN_00565870(s_EngineAmbient_005d6bcc,&DAT_005d67b8,0,0,0,0,0,0,0);
                  FUN_00565870(s_ShiftRange_005d6bc0,&DAT_005d67bc,0,0,0,0,0,0,0);
                  FUN_00565870(s_ShiftShape_005d6bb4,&DAT_005d67c0,0,0,0,0,0,0,0);
                  FUN_00565870(s_ShiftAmbient_005d6ba4,&DAT_005d67c4,0,0,0,0,0,0,0);
                  FUN_00565870(s_OtherRange_005d6b98,&DAT_005d67c8,0,0,0,0,0,0,0);
                  FUN_00565870(s_OtherShape_005d6b8c,&DAT_005d67cc,0,0,0,0,0,0,0);
                  FUN_00565870(s_OtherAmbient_005d6b7c,&DAT_005d67d0,0,0,0,0,0,0,0);
                }
                else {
                  FUN_004f6bf0(local_334,local_398);
                }
              }
              else {
                FUN_004f6bf0(local_334,local_398);
              }
            }
            else {
              uVar1 = FUN_00566e20();
              FUN_004f6bf0(local_334,local_398);
              FUN_00566db0(uVar1);
              FUN_004f6bf0(local_334,local_398);
            }
            goto LAB_004f7f6b;
          }
          puVar3 = local_175;
        }
        iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_1__s_005d6d00 + 3,local_394);
        if ((((((((iVar2 == 1) ||
                 (iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_2__s_005d6b6c + 3,local_394), iVar2 == 1))
                || (iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_3__s_005d6b5c + 3,local_394), iVar2 == 1
                   )) || ((iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_4__s_005d6b4c + 3,local_394),
                          iVar2 == 1 ||
                          (iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_5__s_005d6b3c + 3,local_394),
                          iVar2 == 1)))) ||
              ((iVar2 = FUN_005887ed(puVar3,s_VS_WIND_NOISE__s_005d6b28 + 3,local_394), iVar2 == 1
               || ((iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_DRY__s_005d6b14 + 3,local_394),
                   iVar2 == 1 ||
                   (iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_WET__s_005d6b00 + 3,local_394),
                   iVar2 == 1)))))) ||
             (iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_GRASS__s_005d6ae8 + 3,local_394),
             iVar2 == 1)) ||
            ((((iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_DIRT__s_005d6ad0 + 3,local_394),
               iVar2 == 1 ||
               (iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_GRAVEL__s_005d6ab8 + 3,local_394),
               iVar2 == 1)) ||
              (iVar2 = FUN_005887ed(puVar3,s_VS_ROADNOISE_RUMBLESTRIP__s_005d6a9c + 3,local_394),
              iVar2 == 1)) ||
             (((iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_UP_1__s_005d6a88 + 3,local_394), iVar2 == 1
               || (iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_UP_2__s_005d6a74 + 3,local_394),
                  iVar2 == 1)) ||
              ((iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_UP_3__s_005d6a60 + 3,local_394), iVar2 == 1
               || ((iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_DOWN_1__s_005d6a4c + 3,local_394),
                   iVar2 == 1 ||
                   (iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_DOWN_2__s_005d6a38 + 3,local_394),
                   iVar2 == 1)))))))))) ||
           ((((iVar2 = FUN_005887ed(puVar3,s_VS_SHIFT_DOWN_3__s_005d6a24 + 3,local_394), iVar2 == 1
              || (((iVar2 = FUN_005887ed(puVar3,s_VS_BACKFIRE_1__s_005d6a10 + 3,local_394),
                   iVar2 == 1 ||
                   (iVar2 = FUN_005887ed(puVar3,s_VS_BACKFIRE_2__s_005d69fc + 3,local_394),
                   iVar2 == 1)) ||
                  (iVar2 = FUN_005887ed(puVar3,s_VS_BACKFIRE_3__s_005d69e8 + 3,local_394),
                  iVar2 == 1)))) ||
             (((iVar2 = FUN_005887ed(puVar3,s_VS_SKID_DRY__s_005d69d8 + 3,local_394), iVar2 == 1 ||
               (iVar2 = FUN_005887ed(puVar3,s_VS_SKID_WET__s_005d69c8 + 3,local_394), iVar2 == 1))
              || (((iVar2 = FUN_005887ed(puVar3,s_VS_SKID_GRASS__s_005d69b4 + 3,local_394),
                   iVar2 == 1 ||
                   ((iVar2 = FUN_005887ed(puVar3,s_VS_SKID_DIRT__s_005d69a4 + 3,local_394),
                    iVar2 == 1 ||
                    (iVar2 = FUN_005887ed(puVar3,s_VS_SKID_GRAVEL__s_005d6990 + 3,local_394),
                    iVar2 == 1)))) ||
                  (iVar2 = FUN_005887ed(puVar3,s_VS_SCRAPING__s_005d6980 + 3,local_394), iVar2 == 1)
                  ))))) ||
            (((((((iVar2 = FUN_005887ed(puVar3,s_VS_HIT_WALL_1__s_005d696c + 3,local_394),
                  iVar2 == 1 ||
                  (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_WALL_2__s_005d6958 + 3,local_394),
                  iVar2 == 1)) ||
                 (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_WALL_3__s_005d6944 + 3,local_394), iVar2 == 1
                 )) || ((iVar2 = FUN_005887ed(puVar3,s_VS_HIT_WALL_4__s_005d6930 + 3,local_394),
                        iVar2 == 1 ||
                        (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_WALL_5__s_005d691c + 3,local_394),
                        iVar2 == 1)))) ||
               (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_OTHERCAR_1__s_005d6904 + 3,local_394),
               iVar2 == 1)) ||
              (((((iVar2 = FUN_005887ed(puVar3,s_VS_HIT_OTHERCAR_2__s_005d68ec + 3,local_394),
                  iVar2 == 1 ||
                  (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_OTHERCAR_3__s_005d68d4 + 3,local_394),
                  iVar2 == 1)) ||
                 ((iVar2 = FUN_005887ed(puVar3,s_VS_HIT_OTHERCAR_4__s_005d68bc + 3,local_394),
                  iVar2 == 1 ||
                  (((iVar2 = FUN_005887ed(puVar3,s_VS_HIT_OTHERCAR_5__s_005d68a4 + 3,local_394),
                    iVar2 == 1 ||
                    (iVar2 = FUN_005887ed(puVar3,s_VS_HIT_CONE__s_005d6894 + 3,local_394),
                    iVar2 == 1)) ||
                   (iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_STARTING__s_005d687c + 3,local_394),
                   iVar2 == 1)))))) ||
                ((iVar2 = FUN_005887ed(puVar3,s_VS_ENGINE_STARTER__s_005d6864 + 3,local_394),
                 iVar2 == 1 ||
                 (iVar2 = FUN_005887ed(puVar3,s_VS_SPEED_LIMITER_TOGGLE__s_005d6848 + 3,local_394),
                 iVar2 == 1)))) ||
               (iVar2 = FUN_005887ed(puVar3,s_VS_LAUNCH_CONTROL_TOGGLE__s_005d682c + 3,local_394),
               iVar2 == 1)))) ||
             (((iVar2 = FUN_005887ed(puVar3,s_VS_ON_FIRE__s_005d681c + 3,local_394), iVar2 == 1 ||
               (iVar2 = FUN_005887ed(puVar3,s_VS_HORN__s_005d6810 + 3,local_394), iVar2 == 1)) ||
              (iVar2 = FUN_005887ed(puVar3,s_VS_TRACTION_CONTROL__s_005d67f8 + 3,local_394),
              iVar2 == 1)))))))) {
          FUN_00566650(local_394);
        }
      }
LAB_004f7f6b:
      iVar2 = FUN_00566cc0(local_180,0x180);
    }
    FUN_00566b90();
    uVar1 = local_338;
  }
  if (ABS((local_344 + local_34c + local_340[0]) - _DAT_0059e43c) < _DAT_005ad260) {
    _DAT_005d67a4 = local_340[0];
    _DAT_005d67a8 = local_34c;
    _DAT_005d67ac = local_344;
  }
  if (ABS((local_350 + local_348 + local_354) - _DAT_0059e43c) < _DAT_005ad260) {
    _DAT_005d6798 = local_354;
    _DAT_005d679c = local_348;
    _DAT_005d67a0 = local_350;
  }
  FUN_005668d0();
  return uVar1;
}


