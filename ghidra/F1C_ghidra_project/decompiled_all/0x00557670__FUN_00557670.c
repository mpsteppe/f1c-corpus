// Function: FUN_00557670 @ 00557670
// Strings:  [Some MTS init error, PTEMP]


undefined4 __thiscall FUN_00557670(int param_1,char *param_2)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  short *psVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((param_2[0x20] & 8U) != 0) {
    pvVar4 = operator_new(0x23c);
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0054a600();
    }
    iVar6 = FUN_0054a730(s_PTEMP_005dc19c,param_2 + 0x38);
    if (iVar6 != 0) {
      if (iVar5 != 0) {
        FUN_0054a710();
        FUN_00587bcf(iVar5);
      }
      FUN_0053c590(0xffffffff,s_Some_MTS_init_error_005dc188);
      return 0xffffffff;
    }
    iVar6 = FUN_0054c230(0);
    if (-1 < (char)((uint)*(undefined4 *)(iVar6 + 0x14) >> 8)) {
      FUN_0054a770();
      if (iVar5 != 0) {
        FUN_0054a710();
        FUN_00587bcf(iVar5);
      }
      FUN_0053c590(0xffffffff,s_7Particle_must_be_a_trilist_005dc16b + 1);
      return 0xffffffff;
    }
    FUN_0054c6c0(0);
    iVar7 = FUN_00545f40();
    if ((iVar7 != 0) && (iVar7 = FUN_005487a0(), iVar7 != 0)) {
      FUN_0054a770();
      if (iVar5 != 0) {
        FUN_0054a710();
        FUN_00587bcf(iVar5);
      }
      return 0xffffffff;
    }
    pcVar8 = param_2;
    do {
      cVar2 = *pcVar8;
      pcVar8[param_1 - (int)param_2] = cVar2;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    iVar7 = *(int *)(param_2 + 0x24);
    *(int *)(param_1 + 0x2c) = iVar7;
    piVar9 = operator_new(iVar7 * 0x80 + 4);
    if (piVar9 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      piVar18 = piVar9 + 1;
      *piVar9 = iVar7;
      if (-1 < iVar7 + -1) {
        do {
          FUN_005573a0();
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    *(int **)(param_1 + 0x34) = piVar18;
    iVar7 = *(int *)(iVar6 + 0x118);
    *(int *)(param_1 + 0x4c) = iVar7;
    piVar9 = operator_new(iVar7 * 0x40 + 4);
    if (piVar9 == (int *)0x0) {
      piVar18 = (int *)0x0;
    }
    else {
      piVar18 = piVar9 + 1;
      *piVar9 = iVar7;
      if (-1 < iVar7 + -1) {
        do {
          FUN_0053c2a0();
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    *(int **)(param_1 + 0x50) = piVar18;
    for (iVar7 = (*(uint *)(param_1 + 0x4c) & 0x3ffffff) << 4; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar18 = 0;
      piVar18 = piVar18 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)piVar18 = 0;
      piVar18 = (int *)((int)piVar18 + 1);
    }
    if ((param_2[0x20] & 0x10U) != 0) {
      *(undefined4 *)(param_1 + 0x20) = 0x10;
    }
    if ((param_2[0x20] & 0x20U) != 0) {
      *(undefined4 *)(param_1 + 0x20) = 0x20;
    }
    pvVar4 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x40) = pvVar4;
    pvVar4 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x3c) = pvVar4;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 8;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      iVar7 = 0;
      do {
        puVar1 = (uint *)(*(int *)(param_1 + 0x50) + iVar7);
        *puVar1 = *puVar1 & 0xffffffef;
        *(undefined4 *)(*(int *)(param_1 + 0x50) + 4 + iVar7) =
             *(undefined4 *)(*(int *)(iVar6 + 0x11c) + 4 + iVar7);
        FUN_005473c0();
        *(int *)(*(int *)(param_1 + 0x50) + 8 + iVar7) =
             *(int *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7) * *(int *)(param_1 + 0x2c);
        *(int *)(*(int *)(param_1 + 0x50) + 0x10 + iVar7) =
             *(int *)(*(int *)(iVar6 + 0x11c) + 0x10 + iVar7) * *(int *)(param_1 + 0x2c);
        iVar12 = *(int *)(param_1 + 0x50) + iVar7;
        *(int *)(param_1 + 0x24) =
             *(int *)(param_1 + 0x24) + *(int *)(*(int *)(param_1 + 0x50) + 8 + iVar7);
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + *(int *)(iVar12 + 0x10);
        if (param_2[0x20] < '\0') {
          iVar12 = *(int *)(iVar12 + 8);
        }
        else {
          iVar12 = *(int *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7);
        }
        pvVar4 = operator_new(iVar12 * 0x24);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc + iVar7) = pvVar4;
        pvVar4 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 0x10 + iVar7) << 1);
        *(void **)(*(int *)(param_1 + 0x50) + 0x14 + iVar7) = pvVar4;
        if (param_2[0x20] < '\0') {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
          local_18 = 0;
          if (0 < *(int *)(param_1 + 0x2c)) {
            do {
              iVar12 = *(int *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7);
              iVar17 = *(int *)(iVar6 + 0x11c) + iVar7;
              puVar13 = (undefined4 *)
                        (*(int *)(*(int *)(param_1 + 0x50) + 0xc + iVar7) + iVar12 * local_18 * 0x24
                        );
              local_1c = 0;
              if (0 < iVar12) {
                local_14 = 0;
                do {
                  puVar10 = (undefined4 *)(*(int *)(iVar17 + 0xc) + local_14);
                  *puVar13 = *puVar10;
                  puVar13[1] = puVar10[1];
                  puVar13[2] = puVar10[2];
                  puVar13[6] = *(uint *)(*(int *)(*(int *)(iVar6 + 0x11c) + 0xc + iVar7) + 0x18 +
                                        local_14) | 0xff000000;
                  puVar13 = puVar13 + 9;
                  local_1c = local_1c + 1;
                  local_14 = local_14 + 0x30;
                } while (local_1c < *(int *)(iVar17 + 8));
              }
              local_18 = local_18 + 1;
            } while (local_18 < *(int *)(param_1 + 0x2c));
          }
        }
        else {
          puVar13 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xc + iVar7);
          iVar12 = *(int *)(iVar6 + 0x11c) + iVar7;
          local_1c = 0;
          if (0 < *(int *)(iVar12 + 8)) {
            iVar17 = 0;
            do {
              iVar11 = *(int *)(iVar12 + 0xc) + iVar17;
              *puVar13 = *(undefined4 *)(*(int *)(iVar12 + 0xc) + iVar17);
              puVar13[1] = *(undefined4 *)(iVar11 + 4);
              puVar13[2] = *(undefined4 *)(iVar11 + 8);
              puVar13[6] = *(uint *)(*(int *)(*(int *)(iVar6 + 0x11c) + 0xc + iVar7) + 0x18 + iVar17
                                    ) | 0xff000000;
              puVar13 = puVar13 + 9;
              local_1c = local_1c + 1;
              iVar12 = *(int *)(iVar6 + 0x11c) + iVar7;
              iVar17 = iVar17 + 0x30;
            } while (local_1c < *(int *)(iVar12 + 8));
          }
        }
        if (param_2[0x20] < '\0') {
          *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38 + iVar7) = 0x20;
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38 + iVar7) = 0x22;
        }
        iVar12 = FUN_00540940(*(int *)(param_1 + 0x50) + iVar7);
        if (iVar12 != 0) {
          return 0xffffffff;
        }
        if (-1 < param_2[0x20]) {
          *(undefined4 *)(*(int *)(param_1 + 0x50) + 8 + iVar7) =
               *(undefined4 *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7);
          *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10 + iVar7) =
               *(undefined4 *)(*(int *)(iVar6 + 0x11c) + 0x10 + iVar7);
        }
        FUN_00540d40(*(int *)(param_1 + 0x50) + iVar7,0xc);
        local_1c = 0;
        if (0 < *(int *)(param_1 + 0x2c)) {
          local_18 = 0;
          do {
            *(int *)(local_18 + 4 + *(int *)(param_1 + 0x34)) = local_1c;
            iVar12 = *(int *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7);
            if (0 < iVar12) {
              puVar13 = (undefined4 *)
                        (iVar12 * local_1c * 0x40 +
                         *(int *)(*(int *)(param_1 + 0x50) + 0x20 + iVar7) + 0x24);
              iVar17 = 0;
              do {
                puVar13[-1] = *(undefined4 *)
                               (*(int *)(*(int *)(iVar6 + 0x11c) + 0xc + iVar7) + 0x20 + iVar17);
                *puVar13 = *(undefined4 *)
                            (*(int *)(*(int *)(iVar6 + 0x11c) + 0xc + iVar7) + 0x24 + iVar17);
                puVar13 = puVar13 + 0x10;
                iVar17 = iVar17 + 0x30;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            local_1c = local_1c + 1;
            local_18 = local_18 + 0x80;
          } while (local_1c < *(int *)(param_1 + 0x2c));
        }
        uVar3 = *(undefined4 *)(*(int *)(iVar6 + 0x11c) + 8 + iVar7);
        iVar12 = *(int *)(*(int *)(iVar6 + 0x11c) + 0x10 + iVar7);
        local_1c = 0;
        if (0 < *(int *)(param_1 + 0x2c)) {
          local_18 = 0;
          do {
            psVar14 = (short *)(*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar7) + local_18);
            iVar17 = 0;
            if (0 < iVar12) {
              do {
                *psVar14 = *(short *)(*(int *)(*(int *)(iVar6 + 0x11c) + 0x14 + iVar7) + iVar17 * 2)
                           + (short)local_1c * (short)uVar3;
                psVar14 = psVar14 + 1;
                iVar17 = iVar17 + 1;
              } while (iVar17 < iVar12);
            }
            local_18 = local_18 + iVar12 * 2;
            local_1c = local_1c + 1;
          } while (local_1c < *(int *)(param_1 + 0x2c));
        }
        puVar13 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0x28 + iVar7);
        iVar12 = *(int *)(param_1 + 0x50) + iVar7;
        if (puVar13 != (undefined4 *)0x0) {
          uVar15 = *(int *)(iVar12 + 0x10) * *(int *)(param_1 + 0x2c);
          puVar10 = *(undefined4 **)(iVar12 + 0x14);
          for (uVar16 = (uVar15 & 0x7fffffff) >> 1; uVar16 != 0; uVar16 = uVar16 - 1) {
            *puVar13 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar13 = puVar13 + 1;
          }
          for (uVar15 = uVar15 * 2 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
        }
        FUN_00540da0(*(int *)(param_1 + 0x50) + iVar7,0xc);
        local_10 = local_10 + 1;
        iVar7 = iVar7 + 0x40;
      } while (local_10 < *(int *)(param_1 + 0x4c));
    }
    iVar7 = 0;
    if (0 < *(int *)(iVar6 + 0x118)) {
      iVar12 = 0;
      do {
        FUN_00540cb0(*(int *)(iVar6 + 0x11c) + iVar12);
        iVar7 = iVar7 + 1;
        iVar12 = iVar12 + 0x40;
      } while (iVar7 < *(int *)(iVar6 + 0x118));
    }
    FUN_00587bcf(iVar6);
    if (iVar5 != 0) {
      FUN_0054a710();
      FUN_00587bcf(iVar5);
    }
    pvVar4 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x44) = pvVar4;
    pvVar4 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x48) = pvVar4;
  }
  return 0;
}


