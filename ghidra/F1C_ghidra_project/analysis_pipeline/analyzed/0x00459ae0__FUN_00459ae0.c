// Function: FUN_00459ae0 @ 00459ae0
// Size (bytes): 3411


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00459ae0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  float *pfVar7;
  double *pdVar8;
  double *pdVar9;
  double *pdVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  int iStack_50c;
  int iStack_508;
  double local_4e8;
  double local_4e0;
  double local_4d8;
  int local_4d0;
  int iStack_4cc;
  float local_4c8;
  double *pdStack_4c4;
  double dStack_4c0;
  float fStack_4b8;
  float fStack_4b4;
  float fStack_4b0;
  double dStack_4ac;
  double dStack_4a4;
  double dStack_49c;
  float fStack_494;
  float fStack_490;
  float fStack_48c;
  double local_488;
  double local_480;
  double local_478;
  double local_470;
  double local_468;
  double local_460;
  double dStack_458;
  double dStack_450;
  double dStack_448;
  double local_440;
  double local_438;
  double local_430;
  double dStack_428;
  double dStack_420;
  double dStack_418;
  double dStack_410;
  double dStack_408;
  double dStack_400;
  double dStack_3f8;
  double dStack_3f0;
  double dStack_3e8;
  double dStack_3e0;
  double dStack_3d8;
  double dStack_3d0;
  double dStack_3c8;
  double dStack_3b8;
  double dStack_3b0;
  double dStack_3a8;
  double dStack_3a0;
  double dStack_398;
  float local_390;
  float local_38c;
  float local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  float fStack_364;
  float fStack_360;
  float fStack_35c;
  double dStack_358;
  double dStack_350;
  double dStack_348;
  double dStack_340;
  double dStack_330;
  double local_328;
  double local_320;
  double local_318;
  double dStack_310;
  double dStack_308;
  double dStack_300;
  double dStack_2f8;
  double dStack_2f0;
  double dStack_2e8;
  undefined1 auStack_2e0 [36];
  float fStack_2bc;
  float fStack_2b8;
  float fStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  float fStack_2a8;
  undefined1 auStack_2a0 [36];
  float fStack_27c;
  float fStack_278;
  float fStack_274;
  float fStack_270;
  float fStack_26c;
  float fStack_268;
  double dStack_250;
  double dStack_238;
  undefined4 auStack_230 [6];
  double dStack_218;
  double adStack_200 [6];
  double adStack_1d0 [57];
  
  local_4d0 = 0;
  do {
    param_1[0x82] = 0;
    param_1[0x83] = 0;
    param_1[0x84] = 0;
    param_1[0x85] = 0;
    param_1[0x86] = 0;
    param_1[0x87] = 0;
    param_1[0x88] = 0;
    param_1[0x89] = 0;
    param_1[0x8a] = 0;
    param_1[0x8b] = 0;
    param_1[0x8c] = 0;
    param_1[0x8d] = 0;
    param_1[0x83] = param_1[0x83];
    dVar1 = *(double *)(param_1 + 0x60) * _DAT_0059ed50;
    param_1[0x87] = param_1[0x87];
    param_1[0x82] = 0;
    param_1[0x86] = param_1[0x86];
    *(double *)(param_1 + 0x84) = dVar1 + *(double *)(param_1 + 0x84);
    local_470 = *(double *)(param_1 + 0x4e) * *(double *)(param_1 + 0x4e);
    local_468 = *(double *)(param_1 + 0x50) * *(double *)(param_1 + 0x50);
    dVar1 = *(double *)(param_1 + 0x52);
    dVar2 = *(double *)(param_1 + 0x52);
    local_460 = dVar1 * dVar2;
    pdVar5 = &local_470;
    pdVar9 = &local_4e8;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)pdVar9 = *(undefined4 *)pdVar5;
      pdVar5 = (double *)((int)pdVar5 + 4);
      pdVar9 = (double *)((int)pdVar9 + 4);
    }
    dVar1 = local_470 * local_470 + local_468 * local_468 + dVar1 * dVar2 * local_460;
    if (_DAT_0059f058 < dVar1) {
      dVar1 = _DAT_0059f050 / SQRT(dVar1);
      local_4e8 = local_470 * dVar1;
      local_4e0 = local_4e0 * dVar1;
      local_4d8 = dVar1 * local_4d8;
    }
    dVar1 = *(double *)(param_1 + 0x10);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x4e)) {
      dVar1 = -dVar1;
    }
    local_4e8 = dVar1 * local_4e8;
    dVar1 = *(double *)(param_1 + 0x10);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x50)) {
      dVar1 = -dVar1;
    }
    local_4e0 = dVar1 * local_4e0;
    dVar1 = *(double *)(param_1 + 0x10);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x52)) {
      dVar1 = -dVar1;
    }
    local_4d8 = dVar1 * local_4d8;
    *(double *)(param_1 + 0x82) = local_4e8 + *(double *)(param_1 + 0x82);
    *(double *)(param_1 + 0x84) = local_4e0 + *(double *)(param_1 + 0x84);
    *(double *)(param_1 + 0x86) = local_4d8 + *(double *)(param_1 + 0x86);
    dVar1 = *(double *)(param_1 + 0x54);
    dVar2 = *(double *)(param_1 + 0x54);
    local_488 = dVar1 * dVar2;
    local_480 = *(double *)(param_1 + 0x56) * *(double *)(param_1 + 0x56);
    local_478 = *(double *)(param_1 + 0x58) * *(double *)(param_1 + 0x58);
    pdVar5 = &local_488;
    pdVar9 = &local_4e8;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)pdVar9 = *(undefined4 *)pdVar5;
      pdVar5 = (double *)((int)pdVar5 + 4);
      pdVar9 = (double *)((int)pdVar9 + 4);
    }
    dVar1 = local_480 * local_480 + local_478 * local_478 + dVar1 * dVar2 * local_488;
    if (_DAT_0059f058 < dVar1) {
      dVar1 = _DAT_0059f050 / SQRT(dVar1);
      local_4e8 = local_488 * dVar1;
      local_4e0 = local_4e0 * dVar1;
      local_4d8 = dVar1 * local_4d8;
    }
    dVar1 = *(double *)(param_1 + 0x12);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x54)) {
      dVar1 = -dVar1;
    }
    local_4e8 = dVar1 * local_4e8;
    dVar1 = *(double *)(param_1 + 0x12);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x56)) {
      dVar1 = -dVar1;
    }
    local_4e0 = dVar1 * local_4e0;
    dVar1 = *(double *)(param_1 + 0x12);
    if (_DAT_0059e430 < *(double *)(param_1 + 0x58)) {
      dVar1 = -dVar1;
    }
    local_4d8 = dVar1 * local_4d8;
    *(double *)(param_1 + 0x88) = local_4e8 + *(double *)(param_1 + 0x88);
    *(double *)(param_1 + 0x8a) = local_4e0 + *(double *)(param_1 + 0x8a);
    *(double *)(param_1 + 0x8c) = local_4d8 + *(double *)(param_1 + 0x8c);
    if (local_4d0 == 1) {
      local_328 = (double)(float)param_1[0x30];
      local_320 = (double)(float)param_1[0x31];
      local_318 = (double)(float)param_1[0x32];
      FUN_004361d0(param_1 + 0x36,&local_328,&local_440);
      param_1[0x30] = (int)(float)*(double *)(param_1 + 0x36);
      param_1[0x31] = (int)(float)*(double *)(param_1 + 0x38);
      param_1[0x32] = (int)(float)*(double *)(param_1 + 0x3a);
      local_390 = (float)local_440;
      local_38c = (float)local_438;
      local_388 = (float)local_430;
      fVar12 = SQRT((float10)local_440 * (float10)local_440 +
                    (float10)local_438 * (float10)local_438 +
                    (float10)local_430 * (float10)local_430);
      if (fVar12 < (float10)(float)param_1[0x33]) {
        fVar12 = (float10)(float)param_1[0x33];
      }
      local_4c8 = (float)fVar12;
    }
    else {
      local_4c8 = (float)param_1[0x33];
      local_390 = 0.0;
      local_38c = 0.0;
      local_388 = 0.0;
    }
    local_37c = 0;
    local_380 = 0;
    local_384 = 0;
    FUN_0054fa00(&local_390,0);
    (**(code **)(*param_1 + 8))();
    fVar12 = (float10)FUN_00588570();
    if (ABS(*(double *)(param_1 + 0x46)) == _DAT_0059e420) {
      fVar13 = (float10)fpatan(-(float10)*(double *)(param_1 + 0x48),
                               (float10)*(double *)(param_1 + 0x3c));
      fVar14 = (float10)_DAT_0059e430;
    }
    else {
      fVar13 = (float10)fpatan((float10)*(double *)(param_1 + 0x40),
                               (float10)*(double *)(param_1 + 0x4c));
      fVar14 = (float10)fpatan((float10)*(double *)(param_1 + 0x42),
                               (float10)*(double *)(param_1 + 0x44));
    }
    fStack_4b8 = (float)*(double *)(param_1 + 0x36);
    fStack_4b4 = (float)*(double *)(param_1 + 0x38);
    fStack_4b0 = (float)*(double *)(param_1 + 0x3a);
    fStack_494 = (float)-fVar12;
    fStack_490 = (float)fVar13;
    fStack_48c = (float)fVar14;
    FUN_0054b4d0(fStack_4b8,fStack_4b4,fStack_4b0,fStack_494,fStack_490,fStack_48c);
    FUN_004be4e0(param_1[0x34],&fStack_4b8,local_4c8);
    iStack_50c = 0;
    iStack_4cc = 1;
    if (1 < param_1[0x14]) {
      pdStack_4c4 = adStack_200;
      pfVar7 = (float *)(param_1 + 0x19);
      do {
        iVar6 = iStack_4cc;
        iVar4 = FUN_0054fa90(iStack_4cc,auStack_2a0);
        pdVar5 = pdStack_4c4;
        if (iVar4 != 0) {
          dStack_310 = (double)pfVar7[-1];
          dStack_308 = (double)*pfVar7;
          pdStack_4c4 = pdStack_4c4 + 7;
          iStack_50c = iStack_50c + 1;
          dStack_300 = (double)pfVar7[1];
          dStack_408 = (double)fStack_270;
          dStack_400 = (double)fStack_26c;
          dStack_3f8 = (double)fStack_268;
          FUN_0043aee0(param_1 + 0x36,&dStack_310,&dStack_358);
          pdVar9 = pdVar5 + 1;
          dStack_250 = dStack_348 + dStack_3f8;
          dStack_218 = (dStack_358 + dStack_408) * _DAT_0059e880;
          dStack_2f8 = dStack_218 - *(double *)(param_1 + 0x36);
          dStack_2f0 = (dStack_350 + dStack_400) * _DAT_0059e880 - *(double *)(param_1 + 0x38);
          dStack_2e8 = (dStack_348 + dStack_3f8) * _DAT_0059e880 - *(double *)(param_1 + 0x3a);
          pdVar8 = &dStack_2f8;
          pdVar10 = pdVar9;
          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pdVar10 = *(undefined4 *)pdVar8;
            pdVar8 = (double *)((int)pdVar8 + 4);
            pdVar10 = (double *)((int)pdVar10 + 4);
          }
          dStack_4ac = (double)fStack_27c;
          dStack_4a4 = (double)fStack_278;
          dVar1 = (double)fStack_274;
          dStack_410 = (dStack_400 - dStack_350) * dStack_4a4 +
                       (dStack_3f8 - dStack_348) * dVar1 + (dStack_408 - dStack_358) * dStack_4ac;
          dStack_330 = pdVar5[2] * *(double *)(param_1 + 0x54) -
                       *(double *)(param_1 + 0x56) * *pdVar9;
          dStack_340 = (pdVar5[3] * *(double *)(param_1 + 0x56) -
                       pdVar5[2] * *(double *)(param_1 + 0x58)) + *(double *)(param_1 + 0x4e);
          dStack_450 = (*(double *)(param_1 + 0x58) * *pdVar9 -
                       pdVar5[3] * *(double *)(param_1 + 0x54)) + *(double *)(param_1 + 0x50);
          dStack_448 = dStack_330 + *(double *)(param_1 + 0x52);
          dVar2 = dStack_450 * dStack_4a4 + dStack_448 * dVar1 + dStack_340 * dStack_4ac;
          if (_DAT_0059e430 <= dStack_410) {
            dVar3 = dStack_410 * *(double *)(param_1 + 10) - dVar2 * *(double *)(param_1 + 0xc);
            *pdVar5 = dVar3;
            if (dVar3 < _DAT_0059e430) {
              *pdVar5 = dVar3 * _DAT_0059e880;
            }
          }
          else {
            *(undefined4 *)pdVar5 = 0;
            *(undefined4 *)((int)pdVar5 + 4) = 0;
          }
          if (_DAT_0059f048 < ABS(*pdVar5)) {
            dVar3 = _DAT_0059f040;
            if (_DAT_0059e430 < *pdVar5) {
              dVar3 = _DAT_0059f048;
            }
            *pdVar5 = dVar3;
          }
          dStack_238 = dVar2 * dVar1;
          dStack_458 = dStack_340 - dStack_4ac * dVar2;
          dStack_450 = dStack_450 - dVar2 * dStack_4a4;
          dStack_448 = dStack_448 - dVar2 * dVar1;
          pdVar9 = &dStack_458;
          pdVar8 = &dStack_428;
          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pdVar8 = *(undefined4 *)pdVar9;
            pdVar9 = (double *)((int)pdVar9 + 4);
            pdVar8 = (double *)((int)pdVar8 + 4);
          }
          dVar2 = dStack_450 * dStack_450 + dStack_448 * dStack_448 + dStack_458 * dStack_458;
          if (_DAT_0059e420 < dVar2) {
            dVar2 = _DAT_0059e420 / SQRT(dVar2);
            dStack_428 = dStack_458 * dVar2;
            dStack_420 = dStack_420 * dVar2;
            dStack_418 = dStack_418 * dVar2;
          }
          dVar2 = *(double *)(param_1 + 0xe) * *pdVar5;
          dStack_3a0 = dStack_420 * dVar2;
          dStack_398 = dStack_418 * dVar2;
          dStack_49c = *pdVar5;
          dStack_4ac = dStack_4ac * dStack_49c;
          dStack_4a4 = dStack_4a4 * dStack_49c;
          dStack_49c = dStack_49c * dVar1;
          dVar1 = dStack_4ac - dStack_428 * dVar2;
          dStack_3b8 = dStack_4a4 - dStack_420 * dVar2;
          dVar3 = dStack_49c - dStack_418 * dVar2;
          dVar2 = SQRT(dStack_3b8 * dStack_3b8 + dVar3 * dVar3 + dVar1 * dVar1);
          *pdVar5 = dVar2;
          if (dVar2 <= _DAT_0059e430) {
            *(undefined4 *)(pdVar5 + 4) = 0;
            *(undefined4 *)((int)pdVar5 + 0x24) = 0;
            *(undefined4 *)(pdVar5 + 5) = 0;
            *(undefined4 *)((int)pdVar5 + 0x2c) = 0;
            *(undefined4 *)(pdVar5 + 6) = 0;
            *(undefined4 *)((int)pdVar5 + 0x34) = 0;
          }
          else {
            dVar2 = _DAT_0059e420 / dVar2;
            dStack_3f0 = dVar1 * dVar2;
            dStack_3e8 = dStack_3b8 * dVar2;
            dStack_3e0 = dVar3 * dVar2;
            pdVar9 = &dStack_3f0;
            pdVar5 = pdVar5 + 4;
            for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined4 *)pdVar5 = *(undefined4 *)pdVar9;
              pdVar9 = (double *)((int)pdVar9 + 4);
              pdVar5 = (double *)((int)pdVar5 + 4);
            }
          }
          FUN_0054fae0();
          iVar6 = iStack_4cc;
        }
        iStack_4cc = iVar6 + 1;
        pfVar7 = pfVar7 + 3;
      } while (iStack_4cc < param_1[0x14]);
      if (0 < iStack_50c) {
        if (1 < iStack_50c) {
          dStack_4c0 = 0.0;
          dVar1 = _DAT_0059e430;
          if (0 < iStack_50c) {
            pdVar5 = adStack_200;
            iVar6 = iStack_50c;
            dVar2 = _DAT_0059e430;
            do {
              dVar3 = *pdVar5;
              if (dStack_4c0 < dVar3) {
                dStack_4c0 = dVar3;
              }
              pdVar5 = pdVar5 + 7;
              dVar2 = dVar3 + dVar2;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (_DAT_0059e430 < dVar2) {
              dVar1 = dStack_4c0 / dVar2;
            }
          }
          if (iStack_50c < 1) goto LAB_0045a63d;
          pdVar5 = adStack_200;
          iVar6 = iStack_50c;
          do {
            iVar6 = iVar6 + -1;
            *pdVar5 = dVar1 * *pdVar5;
            pdVar5 = pdVar5 + 7;
          } while (iVar6 != 0);
        }
        if (0 < iStack_50c) {
          pdVar5 = adStack_1d0;
          iStack_508 = iStack_50c;
          do {
            dVar1 = pdVar5[-6];
            dStack_3d8 = dVar1 * pdVar5[-2];
            dStack_3d0 = dVar1 * pdVar5[-1];
            dStack_3c8 = dVar1 * *pdVar5;
            pdVar9 = &dStack_3d8;
            puVar11 = auStack_230;
            for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar11 = *(undefined4 *)pdVar9;
              pdVar9 = (double *)((int)pdVar9 + 4);
              puVar11 = puVar11 + 1;
            }
            FUN_00569ad0(pdVar5 + -5,auStack_230);
            pdVar5 = pdVar5 + 7;
            iStack_508 = iStack_508 + -1;
          } while (iStack_508 != 0);
        }
      }
    }
LAB_0045a63d:
    iVar6 = local_4d0;
    if (local_4d0 == 0) {
      FUN_00569c10((double)CONCAT44(param_3,param_2) * _DAT_0059e880);
    }
    else {
      FUN_00569de0(param_2,param_3);
    }
    local_4d0 = iVar6 + 1;
    if (1 < local_4d0) {
      iVar6 = FUN_0054fa90(0,auStack_2e0);
      if (iVar6 != 0) {
        dStack_3d8 = (double)(float)param_1[0x15];
        dStack_3d0 = (double)(float)param_1[0x16];
        dStack_3c8 = (double)(float)param_1[0x17];
        dStack_4ac = (double)fStack_2b0;
        dStack_4a4 = (double)fStack_2ac;
        dStack_49c = (double)fStack_2a8;
        FUN_0043aee0(param_1 + 0x36,&dStack_3d8,&dStack_3f0);
        local_388 = (float)(((float10)dStack_4ac - (float10)dStack_3f0) * (float10)fStack_2bc +
                            ((float10)dStack_4a4 - (float10)dStack_3e8) * (float10)fStack_2b8 +
                            ((float10)dStack_49c - (float10)dStack_3e0) * (float10)fStack_2b4 +
                           (float10)_DAT_0059f038);
        fStack_364 = fStack_2bc;
        fStack_360 = fStack_2b8;
        fStack_35c = fStack_2b4;
        FUN_00459a40(&local_390,param_1 + 0x30);
        pdVar5 = (double *)(param_1 + 0x4e);
        dVar1 = (double)fStack_2bc * *pdVar5 +
                (double)fStack_2b8 * *(double *)(param_1 + 0x50) +
                (double)fStack_2b4 * *(double *)(param_1 + 0x52);
        dStack_3b8 = dVar1 * (double)fStack_2b8;
        dStack_3b0 = dVar1 * (double)fStack_2b4;
        dStack_3a8 = *pdVar5 - (double)fStack_2bc * dVar1;
        dStack_3a0 = *(double *)(param_1 + 0x50) - dStack_3b8;
        dStack_398 = *(double *)(param_1 + 0x52) - dStack_3b0;
        pdVar9 = &dStack_3a8;
        for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pdVar5 = *(undefined4 *)pdVar9;
          pdVar9 = (double *)((int)pdVar9 + 4);
          pdVar5 = (double *)((int)pdVar5 + 4);
        }
        FUN_0054fae0();
      }
      return;
    }
  } while( true );
}


