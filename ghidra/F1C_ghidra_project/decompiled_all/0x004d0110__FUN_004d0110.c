// Function: FUN_004d0110 @ 004d0110
// Strings:  [%s%s%s, %s%s%s, %s.BMP, CMAPS.MAS, CDB.MAS, Unable to setup scene after initializing grid character %d: %s, WCFLAG, WCFLAG.BMP]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d0110(int *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  char *pcVar12;
  undefined2 uVar13;
  int iVar14;
  float10 fVar15;
  float local_360;
  float local_35c;
  float local_358;
  int *local_354;
  int local_350;
  int local_34c;
  undefined4 local_348;
  undefined1 *local_344;
  undefined4 local_340;
  undefined4 local_33c;
  float local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  float local_324;
  float local_320;
  float local_31c;
  float local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  float local_304;
  undefined4 local_300;
  float local_2fc;
  undefined4 local_2f8;
  float local_2f4;
  float local_2f0;
  double local_2e8;
  double local_2e0;
  double local_2d8;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  double local_2c0;
  undefined4 local_2b8;
  char local_2b4 [31];
  undefined1 local_295;
  char local_294 [20];
  float local_280;
  undefined1 local_278 [36];
  undefined1 local_254 [11];
  char local_249 [257];
  undefined1 local_148 [32];
  undefined1 local_128 [32];
  undefined1 local_108 [260];
  
  iVar14 = DAT_005c329c;
  iVar7 = DAT_005c329c * 0x84;
  *param_1 = DAT_005c329c;
  local_354 = param_1;
  piVar4 = operator_new(iVar7 + 4);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = iVar14;
    piVar4 = piVar4 + 1;
    if (-1 < iVar14 + -1) {
      do {
        FUN_004d0b00();
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
    }
  }
  param_1[1] = (int)piVar4;
  iVar14 = 0;
  if (0 < *param_1) {
    iVar7 = 0;
    do {
      uVar13 = 1;
      if (((*(int *)((&DAT_007c54f0)[iVar14] + 0x4058) + -1) % 3 == 0) || (iVar14 == DAT_007c54e4))
      {
        uVar13 = 0;
      }
      *(undefined2 *)(iVar7 + 4 + param_1[1]) = uVar13;
      iVar14 = iVar14 + 1;
      iVar7 = iVar7 + 0x84;
    } while (iVar14 < *param_1);
  }
  local_328 = 0;
  pcVar8 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  pcVar12 = local_249;
  do {
    pcVar12 = pcVar12 + 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    *pcVar12 = cVar3;
  } while (cVar3 != '\0');
  uVar9 = 0xffffffff;
  pcVar8 = local_249;
  do {
    pcVar8 = pcVar8 + 1;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
  } while (*pcVar8 != '\0');
  pcVar8 = local_249 + ~uVar9;
  if (local_249 + 1 < pcVar8) {
    do {
      if (*pcVar8 == '.') {
        *pcVar8 = '\0';
        break;
      }
      pcVar8 = pcVar8 + -1;
    } while (local_249 + 1 < pcVar8);
  }
  iVar14 = -1;
  pcVar8 = local_249 + 1;
  do {
    pcVar12 = pcVar8;
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    pcVar12 = pcVar8 + 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar12;
  } while (cVar3 != '\0');
  *(undefined4 *)(pcVar12 + -1) = DAT_005c448c;
  pcVar12[3] = DAT_005c4490;
  iVar14 = FUN_0053cbc0(&local_328,local_249 + 1);
  if (((iVar14 != 0) && (DAT_007c569c != 5)) &&
     (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0xcd), cVar3 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_load__s_005d3b58,local_249 + 1);
  }
  local_330 = 0;
  pcVar8 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  pcVar12 = local_249;
  do {
    pcVar12 = pcVar12 + 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    *pcVar12 = cVar3;
  } while (cVar3 != '\0');
  uVar9 = 0xffffffff;
  pcVar8 = local_249;
  do {
    pcVar8 = pcVar8 + 1;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
  } while (*pcVar8 != '\0');
  pcVar8 = local_249 + ~uVar9;
  if (local_249 + 1 < pcVar8) {
    do {
      if (*pcVar8 == '.') {
        *pcVar8 = '\0';
        break;
      }
      pcVar8 = pcVar8 + -1;
    } while (local_249 + 1 < pcVar8);
  }
  iVar14 = -1;
  pcVar8 = local_249 + 1;
  do {
    pcVar12 = pcVar8;
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    pcVar12 = pcVar8 + 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar12;
  } while (cVar3 != '\0');
  *(undefined4 *)(pcVar12 + -1) = s_MAP_MAS_005d3b50._0_4_;
  *(undefined4 *)(pcVar12 + 3) = s_MAP_MAS_005d3b50._4_4_;
  iVar14 = FUN_0053cbc0(&local_330,local_249 + 1);
  if (((iVar14 != 0) && (DAT_007c569c != 5)) &&
     (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0xd4), cVar3 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_load__s_005d3b58,local_249 + 1);
  }
  local_348 = 0;
  puVar10 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar10 = &DAT_005ea438;
  }
  puVar5 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_0058815f(local_249 + 1,s__s_s_s_005c6784,puVar5,puVar10,s_CDB_MAS_005cd5c4);
  iVar14 = FUN_0053cbc0(&local_348,local_249 + 1);
  if (iVar14 == 0) {
    local_32c = 0;
    puVar10 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar10 = &DAT_005ea438;
    }
    puVar5 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_0058815f(local_249 + 1,s__s_s_s_005c6784,puVar5,puVar10,s_CMAPS_MAS_005cceb0);
    iVar14 = FUN_0053cbc0(&local_32c,local_249 + 1);
    if (iVar14 == 0) {
      local_350 = 0;
      if (0 < *param_1) {
        local_34c = 0;
        do {
          iVar7 = local_350;
          iVar14 = (&DAT_007c54f0)[local_350];
          piVar4 = (int *)(local_354[1] + local_34c);
          local_278[0] = 0;
          FUN_0058815f(local_278,s_GridModel_02d_005d3b0c,local_350);
          iVar6 = _rand();
          if (iVar6 % 3 == 0) {
            pcVar8 = s_GRIDGIRLA_MTS_005d3afc;
          }
          else {
            pcVar8 = s_GRIDGIRLB_MTS_005d3aec;
            if (iVar6 % 3 != 1) {
              pcVar8 = s_GRIDGIRLC_MTS_005d3adc;
            }
          }
          FUN_004a21d0(local_278,pcVar8,0,0);
          FUN_004d10e0(iVar14,&local_360,&local_33c);
          FUN_00566e40();
          uVar11 = DAT_008aae70 & 0xff;
          uVar9 = DAT_008aae70 + 1;
          DAT_008aae70 = DAT_008aae70 + 2;
          fVar2 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) * _DAT_0059e7f8;
          fVar1 = *(float *)(&DAT_008ab274 + uVar11 * 4) * _DAT_0059e7f8 - _DAT_0059f124;
          local_2f4 = local_320 * DAT_0059e440 + local_31c * fVar1 + fVar2 * local_324;
          local_2f0 = local_314 * DAT_0059e440 + local_318 * fVar2 + local_310 * fVar1;
          local_360 = local_2f4 + local_360;
          local_35c = local_2f0 + local_35c;
          local_358 = local_308 * DAT_0059e440 + local_30c * fVar2 + local_304 * fVar1 + local_358;
          if (piVar4[0x1a] != 0) {
            FUN_004dd550(local_254);
            local_2e8 = (double)local_360;
            local_2e0 = (double)local_35c;
            local_2d8 = (double)local_358;
            local_2d0 = 0;
            local_2cc = 0x40200000;
            local_2c8 = 0x40000000;
            local_2c4 = 0x479e17b8;
            local_2b8 = 0;
            iVar6 = FUN_0044c4c0(&local_2e8);
            if (iVar6 != 0) {
              local_35c = (float)local_2c0 - local_280;
            }
          }
          uVar9 = DAT_008aae70 & 0xff;
          DAT_008aae70 = DAT_008aae70 + 1;
          local_2fc = *(float *)(&DAT_008ab274 + uVar9 * 4) * _DAT_0059e84c;
          local_300 = 0;
          local_2f8 = 0;
          FUN_00567120(&local_300,&local_33c);
          local_33c = 0;
          local_334 = 0;
          fVar15 = (float10)fpatan((float10)local_304 * (float10)DAT_0059e440 +
                                   (float10)local_308 * (float10)DAT_0059e440 + (float10)local_30c,
                                   (float10)local_31c * (float10)DAT_0059e440 +
                                   (float10)local_320 * (float10)DAT_0059e440 + (float10)local_324);
          local_338 = (float)-fVar15;
          local_35c = local_35c - _DAT_005acee0;
          FUN_004a2800(&local_360,&local_33c);
          local_344 = (undefined1 *)0x0;
          local_35c = local_35c - _DAT_005acedc;
          local_340 = 0xffffffff;
          uVar9 = _rand();
          pcVar8 = s_GIRLA_005d3ad4;
          if ((uVar9 & 1) == 0) {
            pcVar8 = &DAT_005d3acc;
          }
          pcVar12 = local_294;
          do {
            cVar3 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            *pcVar12 = cVar3;
            pcVar12 = pcVar12 + 1;
          } while (cVar3 != '\0');
          FUN_00566650(&DAT_005ea438);
          FUN_00566650(local_294);
          FUN_005665b0(&DAT_005cd49c);
          puVar10 = local_344;
          if (local_344 == (undefined1 *)0x0) {
            puVar10 = &DAT_005ea438;
          }
          FUN_004a22d0(local_294,puVar10,0,0);
          if (0 < piVar4[0x1d]) {
            iVar7 = piVar4[0x1e];
            uVar9 = DAT_008aae70 & 0xff;
            DAT_008aae70 = DAT_008aae70 + 1;
            FUN_004a1fd0(0,(*(float *)(&DAT_008ab274 + uVar9 * 4) * _DAT_0059e7e8 + _DAT_0059e43c) *
                           *(float *)(iVar7 + 0x10));
            piVar4[0x1f] = *(int *)(iVar7 + 4);
            uVar9 = DAT_008aae70 & 0xff;
            DAT_008aae70 = DAT_008aae70 + 1;
            piVar4[0x20] = (int)(*(float *)(&DAT_008aae74 + uVar9 * 4) * (float)piVar4[0x1f]);
            iVar7 = local_350;
          }
          FUN_0058815f(local_128,s_GridSign_02d_005d3abc,iVar7);
          *piVar4 = 0;
          if ((piVar4[0x1a] != 0) &&
             (FUN_005450e0(piVar4,local_128,s_GGIRLSIGN_MTS_005d3aac,0x10), *piVar4 != 0)) {
            iVar6 = FUN_0054c230(0);
            FUN_0054b4d0(local_360,local_35c + _DAT_0059e7e8,local_358,local_33c,local_338,local_334
                        );
            FUN_00545250(*piVar4);
            if (iVar6 != 0) {
              FUN_00545930(iVar6,0);
            }
            FUN_0058815f(local_148,s__s_BMP_005ccea8,iVar14 + 0x4708);
            FUN_004dc770(local_148,s_WCNUMBER_BMP_005d3a9c,0,1,0);
            _strncpy(local_2b4,(char *)(iVar14 + 0x4660),0x1f);
            local_295 = 0;
            FUN_00589901(local_2b4);
            uVar9 = 0xffffffff;
            pcVar8 = local_2b4;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar3 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar3 != '\0');
            if (~uVar9 - 1 < 0x1b) {
              iVar14 = -1;
              pcVar8 = local_2b4;
              do {
                pcVar12 = pcVar8;
                if (iVar14 == 0) break;
                iVar14 = iVar14 + -1;
                pcVar12 = pcVar8 + 1;
                cVar3 = *pcVar8;
                pcVar8 = pcVar12;
              } while (cVar3 != '\0');
              *(undefined4 *)(pcVar12 + -1) = DAT_005cc79c;
              pcVar12[3] = DAT_005cc7a0;
            }
            FUN_004dc770(local_2b4,s_WCFLAG_BMP_005d3a84,0,1,0);
          }
          iVar14 = FUN_00543fa0();
          if (((iVar14 != 0) && (FUN_0053c5b0(0,local_108), DAT_007c569c != 5)) &&
             (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x170),
             cVar3 != '\0')) {
            FUN_004d7aa0(&DAT_008ad25c,s_Unable_to_setup_scene_after_init_005d3a3c,iVar7,local_108);
          }
          if (local_344 != (undefined1 *)0x0) {
            FUN_00587bcf(local_344);
          }
          local_350 = iVar7 + 1;
          local_34c = local_34c + 0x84;
        } while (local_350 < *local_354);
      }
      FUN_0053ce40(local_328);
      FUN_0053ce40(local_330);
      FUN_0053ce40(local_348);
      FUN_0053ce40(local_32c);
      piVar4 = local_354;
      iVar14 = 0;
      if (0 < *local_354) {
        do {
          FUN_004a27d0();
          iVar14 = iVar14 + 1;
        } while (iVar14 < *piVar4);
      }
    }
    else {
      FUN_0053ce40(local_348);
      if ((DAT_007c569c != 5) &&
         (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0xe4), cVar3 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_load_CMAPS_MAS_005d3b1c);
        return;
      }
    }
  }
  else if ((DAT_007c569c != 5) &&
          (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0xdb), cVar3 != '\0'))
  {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_load_CDB_MAS_005d3b38);
    return;
  }
  return;
}


