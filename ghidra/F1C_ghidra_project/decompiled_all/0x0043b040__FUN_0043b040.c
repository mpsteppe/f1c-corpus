// Function: FUN_0043b040 @ 0043b040
// Strings:  [fr_steering, fl_steering, fl_steering, D:\dev\F1_1999_2002\Source\hdvehicle.cpp, Sorry, only support independent 5-link front suspensions right now]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043b040(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  int iVar11;
  char cVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  double *pdVar18;
  int *piVar19;
  undefined4 *puVar20;
  double *pdVar21;
  undefined4 *puVar22;
  float10 fVar23;
  int local_2d4;
  int local_2d0;
  int local_2cc;
  char *local_2c8;
  int local_2c0;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  double local_2a8;
  double local_2a0;
  double local_298;
  undefined4 local_290 [7];
  double local_274;
  double local_250;
  double local_238;
  double local_230;
  undefined4 local_228 [7];
  double local_20c;
  double local_1e8;
  double local_1d0;
  double local_1c8;
  double local_1b0;
  double local_198;
  undefined4 local_190 [3];
  double local_184 [34];
  undefined4 local_70 [27];
  
  local_2b8 = 0;
  do {
    iVar15 = *(int *)(local_2b8 * 0x464 + 0x3ec + param_1);
    iVar17 = 0;
    if (local_2b8 == 0) {
      local_2c8 = s_fl_steering_005c41c8;
      local_2b4 = 0xb;
    }
    else {
      local_2c8 = s_fr_steering_005c41bc;
      local_2b4 = 0xc;
    }
    local_2c0 = 0;
    local_2cc = 0;
    if (*(int *)(param_1 + 0x15c4) < 1) {
LAB_0043b1ec:
      if ((DAT_007c569c != 5) &&
         (cVar12 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_hdveh_005c421c,0xaf7), cVar12 != '\0'
         )) {
        FUN_004d7aa0(&DAT_008ad25c,s_Sorry__only_support_independent_5_005c4270);
      }
    }
    else {
      local_2d4 = 0;
      puVar14 = local_190;
      do {
        piVar19 = (int *)(*(int *)(param_1 + 0x15c8) + local_2d4);
        puVar16 = puVar14;
        if ((((piVar19[1] == iVar15) && (piVar19[3] == *(int *)(param_1 + 0x15f0))) ||
            ((piVar19[3] == iVar15 && (piVar19[1] == *(int *)(param_1 + 0x15f0))))) &&
           ((*piVar19 == 0 || (iVar13 = FUN_00588410(*piVar19,local_2c8), iVar13 != 0)))) {
          iVar13 = piVar19[2];
          puVar16 = puVar14 + 0x12;
          iVar11 = piVar19[1];
          puVar14[1] = iVar11;
          puVar14[2] = iVar13;
          *puVar14 = piVar19;
          iVar17 = iVar17 + 2;
          FUN_0043aee0(iVar11 + 4,iVar13,puVar14 + 3);
          iVar13 = piVar19[3];
          pdVar18 = (double *)piVar19[4];
          dVar1 = *(double *)(iVar13 + 0x2c);
          dVar2 = pdVar18[2];
          puVar14[9] = piVar19;
          dVar3 = *(double *)(iVar13 + 0x24);
          puVar14[10] = iVar13;
          dVar4 = pdVar18[1];
          puVar14[0xb] = pdVar18;
          dVar5 = *(double *)(iVar13 + 0x44);
          dVar6 = pdVar18[2];
          dVar7 = *(double *)(iVar13 + 0x3c);
          dVar8 = pdVar18[1];
          dVar9 = *(double *)(iVar13 + 0x34);
          dVar10 = *pdVar18;
          local_198 = *(double *)(iVar13 + 0x4c) * *pdVar18 +
                      *(double *)(iVar13 + 0x54) * pdVar18[1] +
                      *(double *)(iVar13 + 0x5c) * pdVar18[2];
          *(double *)(puVar14 + 0xc) =
               *(double *)(iVar13 + 0x1c) * *pdVar18 + dVar3 * dVar4 + dVar1 * dVar2 +
               *(double *)(iVar13 + 4);
          *(double *)(puVar14 + 0xe) =
               dVar9 * dVar10 + dVar7 * dVar8 + dVar5 * dVar6 + *(double *)(iVar13 + 0xc);
          *(double *)(puVar14 + 0x10) = local_198 + *(double *)(iVar13 + 0x14);
        }
        local_2cc = local_2cc + 1;
        local_2d4 = local_2d4 + 0x48;
        puVar14 = puVar16;
      } while (local_2cc < *(int *)(param_1 + 0x15c4));
      local_2c0 = iVar17;
      if (iVar17 != 8) goto LAB_0043b1ec;
    }
    puVar14 = local_190 + local_2c0 * 9;
    local_2cc = 0;
    do {
      puVar16 = local_228;
      if (local_2cc != 0) {
        puVar16 = local_290;
      }
      puVar16[0x12] = 0xffffffff;
      puVar16[0x13] = 0x7fefffff;
      local_2d0 = 0;
      if (0 < local_2c0) {
        local_2c8 = (char *)0x0;
        do {
          local_2d4 = 0;
          if (0 < (int)local_2c8) {
            pdVar18 = local_184 + 2;
            do {
              dVar1 = *(double *)((int)local_184 + (int)local_2c8) - pdVar18[-2];
              dVar3 = *(double *)((int)local_184 + (int)local_2c8 + 8) - pdVar18[-1];
              dVar2 = *(double *)((int)local_184 + (int)local_2c8 + 0x10) - *pdVar18;
              dVar1 = SQRT(dVar1 * dVar1 + dVar3 * dVar3 + dVar2 * dVar2);
              if (dVar1 < *(double *)(puVar16 + 0x12)) {
                *(double *)(puVar16 + 0x12) = dVar1;
                puVar20 = (undefined4 *)((int)local_190 + (int)local_2c8);
                puVar22 = puVar16;
                for (iVar15 = 9; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *puVar22 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar22 = puVar22 + 1;
                }
                puVar20 = (undefined4 *)((int)pdVar18 + -0x1c);
                puVar22 = puVar16 + 9;
                for (iVar15 = 9; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *puVar22 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar22 = puVar22 + 1;
                }
                local_2b0 = local_2d0;
                local_1b0 = *(double *)(puVar16 + 7) + *(double *)(puVar16 + 0x10);
                local_2ac = local_2d4;
                local_2a8 = (*(double *)(puVar16 + 3) + *(double *)(puVar16 + 0xc)) * _DAT_0059e880;
                local_2a0 = (*(double *)(puVar16 + 5) + *(double *)(puVar16 + 0xe)) * _DAT_0059e880;
                local_298 = (*(double *)(puVar16 + 7) + *(double *)(puVar16 + 0x10)) * _DAT_0059e880
                ;
                pdVar21 = &local_2a8;
                puVar20 = puVar16 + 0x14;
                for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *puVar20 = *(undefined4 *)pdVar21;
                  pdVar21 = (double *)((int)pdVar21 + 4);
                  puVar20 = puVar20 + 1;
                }
              }
              local_2d4 = local_2d4 + 1;
              pdVar18 = (double *)((int)pdVar18 + 0x24);
            } while (local_2d4 < local_2d0);
          }
          local_2d0 = local_2d0 + 1;
          local_2c8 = (char *)((int)local_2c8 + 0x24);
        } while (local_2d0 < local_2c0);
      }
      puVar16 = puVar14 + -9;
      puVar20 = local_190 + local_2b0 * 9;
      for (iVar15 = 9; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar20 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar20 = puVar20 + 1;
      }
      puVar14 = puVar14 + -0x12;
      puVar16 = puVar14;
      puVar20 = local_190 + local_2ac * 9;
      for (iVar15 = 9; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar20 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar20 = puVar20 + 1;
      }
      local_2c0 = local_2c0 + -2;
      local_2cc = local_2cc + 1;
    } while (local_2cc < 2);
    if (local_1d0 < local_238) {
      puVar14 = local_228;
      puVar16 = local_70;
      for (iVar15 = 0x1a; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      puVar14 = local_290;
      puVar16 = local_228;
      for (iVar15 = 0x1a; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      puVar14 = local_70;
      puVar16 = local_290;
      for (iVar15 = 0x1a; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    pdVar18 = (double *)(local_2b4 * 0x40 + 0xbb0 + param_2);
    iVar15 = 0;
    fVar23 = (float10)fptan((float10)*(int *)(local_2b4 * 0x40 + 0xbc4 + param_2) *
                            (float10)pdVar18[1] + (float10)*pdVar18);
    fVar23 = (((float10)local_1d0 - (float10)local_238) * fVar23 -
             ((float10)local_1c8 - (float10)local_230)) * (float10)_DAT_0059e880;
    local_20c = (double)((float10)local_20c + fVar23);
    local_1e8 = (double)((float10)local_1e8 + fVar23);
    local_274 = (double)((float10)local_274 - fVar23);
    local_250 = (double)((float10)local_250 - fVar23);
    do {
      puVar14 = local_228;
      if (iVar15 != 0) {
        puVar14 = local_290;
      }
      iVar17 = 2;
      puVar14 = puVar14 + 2;
      do {
        iVar13 = puVar14[-1];
        dVar1 = *(double *)(puVar14 + 1) - *(double *)(iVar13 + 4);
        pdVar18 = (double *)*puVar14;
        dVar3 = *(double *)(puVar14 + 3) - *(double *)(iVar13 + 0xc);
        iVar17 = iVar17 + -1;
        dVar2 = *(double *)(puVar14 + 5) - *(double *)(iVar13 + 0x14);
        *pdVar18 = dVar1 * *(double *)(iVar13 + 0x1c) +
                   dVar3 * *(double *)(iVar13 + 0x34) + dVar2 * *(double *)(iVar13 + 0x4c);
        pdVar18[1] = dVar1 * *(double *)(iVar13 + 0x24) +
                     dVar3 * *(double *)(iVar13 + 0x3c) + dVar2 * *(double *)(iVar13 + 0x54);
        pdVar18[2] = dVar1 * *(double *)(iVar13 + 0x2c) +
                     dVar3 * *(double *)(iVar13 + 0x44) + dVar2 * *(double *)(iVar13 + 0x5c);
        pdVar18[3] = *(double *)(iVar13 + 0x1c) * *pdVar18 +
                     *(double *)(iVar13 + 0x24) * pdVar18[1] +
                     *(double *)(iVar13 + 0x2c) * pdVar18[2];
        pdVar18[4] = *(double *)(iVar13 + 0x3c) * pdVar18[1] +
                     *(double *)(iVar13 + 0x44) * pdVar18[2] + *(double *)(iVar13 + 0x34) * *pdVar18
        ;
        pdVar18[5] = *(double *)(iVar13 + 0x54) * pdVar18[1] +
                     *(double *)(iVar13 + 0x5c) * pdVar18[2] + *(double *)(iVar13 + 0x4c) * *pdVar18
        ;
        puVar14 = puVar14 + 9;
      } while (iVar17 != 0);
      iVar15 = iVar15 + 1;
    } while (iVar15 < 2);
    local_2b8 = local_2b8 + 1;
    if (1 < local_2b8) {
      return;
    }
  } while( true );
}


