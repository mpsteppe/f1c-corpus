// Function: FUN_004d5f70 @ 004d5f70
// Strings:  [D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, First data point must be zero in tire slip curve "%s", Need at least %d data points found for tire slip curve "%s", Tire slip curve step must be positive for curve "%s", Skipping unexpected data point "%s" in tire slip curve "%s"]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d5f70(undefined4 *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  bool bVar8;
  char cVar9;
  int iVar10;
  double *pdVar11;
  double *pdVar12;
  int iVar13;
  void *pvVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined1 *puVar19;
  undefined4 *puVar20;
  double *local_47c;
  undefined8 local_470;
  double local_468;
  double local_460;
  undefined4 local_458;
  undefined4 uStack_454;
  double local_450;
  double local_448;
  undefined8 local_440;
  undefined4 local_438;
  undefined4 local_434;
  double local_430;
  double local_428;
  double local_420;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  double local_408;
  double local_400;
  double local_3f8;
  undefined8 local_3f0;
  undefined4 local_3e8;
  undefined4 local_3e4;
  double local_3e0;
  double local_3d8;
  double local_3d0;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b8;
  undefined4 uStack_3b4;
  int local_3b0 [100];
  undefined4 local_220;
  undefined1 local_21c;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208 [96];
  undefined1 local_88 [132];
  
  iVar18 = 0;
  puVar20 = local_208;
  for (iVar16 = 0x60; iVar16 != 0; iVar16 = iVar16 + -1) {
    *puVar20 = 0;
    puVar20 = puVar20 + 1;
  }
  bVar8 = false;
  local_458 = 0x47ae147b;
  uStack_454 = 0x3f847ae1;
  iVar15 = 0;
  iVar16 = 0;
  local_47c = (double *)0x0;
  local_220 = 0;
  local_20c = 0;
  local_214 = 0;
  local_210 = 0;
  local_21c = 1;
  iVar10 = FUN_00566cc0(local_208,0x180);
  while (((iVar10 != 0 && (iVar10 = FUN_005651b0(), iVar10 != 1)) && (iVar10 != 4))) {
    if (iVar10 == 0) {
      if (bVar8) {
        iVar10 = FUN_005897ca(local_208,&DAT_005d46fc);
        if (iVar10 != 0) {
          iVar13 = iVar18 * 8;
          iVar17 = iVar18;
          iVar18 = iVar15;
          do {
            iVar15 = FUN_005887ed(iVar10,&PTR_DAT_005d46f8,&local_468);
            if (iVar15 == 1) {
              iVar15 = iVar17;
              pdVar11 = local_47c;
              if (iVar16 <= iVar17) {
                iVar16 = iVar16 + 0x80;
                pdVar11 = operator_new(iVar16 * 8);
                if (0 < iVar13) {
                  pdVar12 = pdVar11;
                  do {
                    *(undefined4 *)pdVar12 =
                         *(undefined4 *)(((int)local_47c - (int)pdVar11) + (int)pdVar12);
                    *(undefined4 *)((int)pdVar12 + 4) =
                         *(undefined4 *)(((int)local_47c - (int)pdVar11) + 4 + (int)pdVar12);
                    pdVar12 = pdVar12 + 1;
                    iVar17 = iVar17 + -1;
                    iVar15 = iVar18;
                  } while (iVar17 != 0);
                }
                if (local_47c != (double *)0x0) {
                  FUN_00587bcf(local_47c);
                }
              }
              local_47c = pdVar11;
              iVar18 = iVar15 + 1;
              *(double *)(iVar13 + (int)local_47c) = local_468;
              iVar13 = iVar13 + 8;
            }
            else {
              cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x11f);
              if (cVar9 != '\0') {
                puVar19 = (undefined1 *)*param_1;
                if (puVar19 == (undefined1 *)0x0) {
                  puVar19 = &DAT_005ea438;
                }
                FUN_004d7aa0(&DAT_008ad25c,s_Skipping_unexpected_data_point___005d46bc,iVar10,
                             puVar19);
              }
            }
            iVar10 = FUN_005897ca(0,&DAT_005d46fc);
            iVar17 = iVar18;
            iVar15 = iVar18;
          } while (iVar10 != 0);
        }
      }
      else {
        iVar10 = FUN_005654a0(&DAT_005d4710,local_88);
        if (iVar10 != 0) {
          FUN_00566650(local_88);
        }
        FUN_00565aa0(&DAT_005d4708,&local_458,0,0,0);
        iVar10 = FUN_00587c20(local_208,s_DATA__005d4700);
        if (iVar10 != 0) {
          bVar8 = true;
        }
      }
    }
    iVar10 = FUN_00566cc0(local_208,0x180);
  }
  if ((double)CONCAT44(uStack_454,local_458) < _DAT_0059e430 ==
      ((double)CONCAT44(uStack_454,local_458) == _DAT_0059e430)) {
    if (iVar18 < 3) {
      cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x136);
      if (cVar9 != '\0') {
        puVar19 = (undefined1 *)*param_1;
        if (puVar19 == (undefined1 *)0x0) {
          puVar19 = &DAT_005ea438;
        }
        FUN_004d7aa0(&DAT_008ad25c,s_Need_at_least__d_data_points_fou_005d4648,3,puVar19);
        return;
      }
    }
    else {
      if (*local_47c == _DAT_0059e430) {
        param_1[4] = iVar18;
        pvVar14 = operator_new(iVar18 << 5);
        param_1[5] = pvVar14;
        if ((int)param_1[4] < 4) {
          dVar2 = local_47c[1] - *local_47c;
        }
        else {
          dVar2 = (((local_47c[2] - *local_47c) + (local_47c[2] - *local_47c)) -
                  (local_47c[3] - local_47c[1])) * _DAT_0059e880;
        }
        iVar18 = 0;
        pdVar11 = &local_450;
        do {
          local_3b0[iVar18] = (int)pdVar11;
          iVar18 = iVar18 + 1;
          pdVar11 = pdVar11 + 5;
        } while (iVar18 < 4);
        iVar16 = 0;
        iVar18 = 0;
        do {
          dVar1 = _DAT_0059e430;
          if (iVar18 < param_1[4] + -2) {
            local_470 = (local_47c[iVar18 + 2] - local_47c[iVar18]) * _DAT_0059e880;
          }
          else {
            if (param_1[4] + -1 <= iVar18) {
              iVar16 = param_1[5];
              iVar15 = iVar18 * 0x20;
              *(undefined4 *)(iVar15 + iVar16) = 0;
              *(undefined4 *)(iVar15 + 4 + iVar16) = 0;
              iVar16 = param_1[5];
              *(undefined4 *)(iVar15 + 8 + iVar16) = 0;
              *(undefined4 *)(iVar15 + 0xc + iVar16) = 0;
              iVar16 = param_1[5];
              *(undefined4 *)(iVar15 + 0x10 + iVar16) = 0;
              *(undefined4 *)(iVar15 + 0x14 + iVar16) = 0;
              iVar16 = param_1[5];
              *(undefined4 *)(iVar15 + 0x18 + iVar16) = *(undefined4 *)(local_47c + iVar18);
              *(undefined4 *)(iVar15 + 0x1c + iVar16) =
                   *(undefined4 *)((int)local_47c + iVar18 * 8 + 4);
              iVar18 = param_1[4];
              iVar16 = 0;
              param_1[2] = 0;
              param_1[3] = 0;
              if (0 < iVar18) {
                pdVar11 = (double *)param_1[5];
                do {
                  dVar3 = (double)iVar16;
                  dVar2 = (double)iVar16;
                  dVar3 = ((dVar3 * *pdVar11 + pdVar11[1]) * dVar3 + pdVar11[2]) * dVar3 +
                          pdVar11[3];
                  if (dVar1 < dVar3) {
                    *(double *)(param_1 + 2) = dVar2;
                    dVar1 = dVar3;
                  }
                  dVar3 = *pdVar11 * _DAT_0059e7e0;
                  if (dVar3 != _DAT_0059e430) {
                    dVar4 = pdVar11[1] + pdVar11[1];
                    dVar7 = dVar4 * dVar4 - pdVar11[2] * dVar3 * _DAT_0059e7d8;
                    if (_DAT_0059e430 <= dVar7) {
                      dVar7 = SQRT(dVar7);
                      dVar3 = _DAT_0059ec10 / dVar3;
                      dVar5 = (dVar7 + dVar4) * dVar3;
                      if (((dVar2 < dVar5) && (dVar5 < (double)(iVar16 + 1))) &&
                         (dVar6 = ((dVar5 * *pdVar11 + pdVar11[1]) * dVar5 + pdVar11[2]) * dVar5 +
                                  pdVar11[3], dVar1 < dVar6)) {
                        *(double *)(param_1 + 2) = dVar5;
                        dVar1 = dVar6;
                      }
                      dVar3 = (dVar4 - dVar7) * dVar3;
                      if (((dVar2 < dVar3) && (dVar3 < (double)(iVar16 + 1))) &&
                         (dVar2 = ((dVar3 * *pdVar11 + pdVar11[1]) * dVar3 + pdVar11[2]) * dVar3 +
                                  pdVar11[3], dVar1 < dVar2)) {
                        *(double *)(param_1 + 2) = dVar3;
                        dVar1 = dVar2;
                      }
                    }
                  }
                  iVar16 = iVar16 + 1;
                  dVar2 = (double)iVar16;
                  local_468 = (double)iVar16;
                  local_460 = ((dVar2 * *pdVar11 + pdVar11[1]) * dVar2 + pdVar11[2]) * dVar2 +
                              pdVar11[3];
                  if (dVar1 < local_460) {
                    *(double *)(param_1 + 2) = local_468;
                    dVar1 = local_460;
                  }
                  pdVar11 = pdVar11 + 4;
                } while (iVar16 < iVar18);
              }
              iVar16 = 0;
              dVar1 = _DAT_0059e420 / dVar1;
              if (0 < iVar18) {
                iVar18 = 0;
                do {
                  iVar16 = iVar16 + 1;
                  *(double *)(param_1[5] + iVar18) = dVar1 * *(double *)(param_1[5] + iVar18);
                  pdVar11 = (double *)(param_1[5] + 8 + iVar18);
                  *pdVar11 = dVar1 * *pdVar11;
                  pdVar11 = (double *)(param_1[5] + 0x10 + iVar18);
                  *pdVar11 = dVar1 * *pdVar11;
                  pdVar11 = (double *)(param_1[5] + 0x18 + iVar18);
                  iVar18 = iVar18 + 0x20;
                  *pdVar11 = dVar1 * *pdVar11;
                } while (iVar16 < (int)param_1[4]);
              }
              FUN_00587bcf(local_47c);
              return;
            }
            local_470 = 0.0;
          }
          dVar3 = (double)iVar18;
          dVar1 = local_47c[iVar18];
          local_448 = dVar3 * dVar3;
          iVar15 = iVar18 + 1;
          local_450 = dVar3 * local_448;
          local_438 = 0;
          local_434 = 0x3ff00000;
          local_418 = 0;
          local_414 = 0x3ff00000;
          local_410 = 0;
          local_40c = 0;
          local_428 = local_448 * _DAT_0059e7e0;
          local_420 = dVar3 + dVar3;
          dVar4 = (double)iVar15;
          local_460 = local_47c[iVar18 + 1];
          local_3f8 = dVar4 * dVar4;
          local_3b8 = (undefined4)local_470;
          local_400 = dVar4 * local_3f8;
          uStack_3b4 = local_470._4_4_;
          local_3e8 = 0;
          local_3e4 = 0x3ff00000;
          local_3c8 = 0;
          local_3c4 = 0x3ff00000;
          local_3c0 = 0;
          local_3d8 = local_3f8 * _DAT_0059e7e0;
          local_3bc = 0;
          local_3d0 = dVar4 + dVar4;
          local_430 = dVar1;
          local_408 = dVar2;
          local_3e0 = local_460;
          local_440 = dVar3;
          local_3f0 = dVar4;
          iVar10 = FUN_005677b0();
          iVar18 = iVar15;
          dVar2 = local_470;
          if (iVar10 == 0) {
            *(double *)(iVar16 + param_1[5]) = local_430;
            iVar16 = iVar16 + 0x20;
            *(double *)(param_1[5] + -0x18 + iVar16) = local_408;
            *(double *)(param_1[5] + -0x10 + iVar16) = local_3e0;
            *(ulonglong *)(param_1[5] + -8 + iVar16) = CONCAT44(uStack_3b4,local_3b8);
          }
          else {
            iVar15 = param_1[5];
            *(undefined4 *)(iVar16 + iVar15) = 0;
            *(undefined4 *)(iVar16 + 4 + iVar15) = 0;
            iVar15 = param_1[5];
            *(undefined4 *)(iVar15 + 8 + iVar16) = 0;
            *(undefined4 *)(iVar15 + 0xc + iVar16) = 0;
            *(double *)(param_1[5] + 0x10 + iVar16) = (local_460 - dVar1) / (dVar4 - dVar3);
            pdVar11 = (double *)(param_1[5] + 0x10 + iVar16);
            iVar15 = param_1[5] + iVar16;
            iVar16 = iVar16 + 0x20;
            *(double *)(iVar15 + 0x18) = dVar1 - dVar3 * *pdVar11;
          }
        } while( true );
      }
      cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x13e);
      if (cVar9 != '\0') {
        puVar19 = (undefined1 *)*param_1;
        if (puVar19 == (undefined1 *)0x0) {
          puVar19 = &DAT_005ea438;
        }
        FUN_004d7aa0(&DAT_008ad25c,s_First_data_point_must_be_zero_in_005d4610,puVar19);
        return;
      }
    }
  }
  else {
    cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x12d);
    if (cVar9 != '\0') {
      puVar19 = (undefined1 *)*param_1;
      if (puVar19 == (undefined1 *)0x0) {
        puVar19 = &DAT_005ea438;
      }
      FUN_004d7aa0(&DAT_008ad25c,s_Tire_slip_curve_step_must_be_pos_005d4684,puVar19);
      return;
    }
  }
  return;
}


