// Function: FUN_0049f870 @ 0049f870
// Strings:  [FTFU30WH,  [%d ms], %d %s (%d)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049f870(int param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  char *pcVar12;
  int *piVar13;
  char *pcVar14;
  char *pcVar15;
  float10 fVar16;
  float local_d4;
  float local_d0;
  float local_cc;
  int *local_c8;
  int *local_c4;
  int *local_c0;
  int local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  int local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  char local_9c [16];
  int local_8c;
  float local_88;
  int local_84;
  char local_80 [128];
  
  if (DAT_007ce254 == '\0') {
    if (DAT_007cc49c != 0) {
      *(bool *)(param_1 + 8) = *(char *)(param_1 + 8) == '\0';
    }
    local_a8 = param_1;
    if ((*(char *)(param_1 + 8) != '\0') || (iVar4 = FUN_00461cd0(), iVar4 != 0)) {
      local_cc = 0.0;
      if (DAT_0059e440 < _DAT_005ea4e8) {
        local_d0 = DAT_005d6d64;
        fVar16 = (float10)FUN_00408490();
        local_cc = (float)(fVar16 * (float10)(int)local_d0);
      }
      local_d0 = DAT_005d6d64;
      fVar16 = (float10)FUN_0045be00(4);
      local_d4 = (float)(fVar16 * (float10)(int)local_d0);
      local_b8 = (float)__ftol();
      local_b4 = (float)__ftol();
      local_ac = __ftol();
      fVar11 = (float)(DAT_005d6d60 - local_ac);
      local_b0 = fVar11;
      iVar4 = FUN_0040cd60();
      if ((iVar4 < 5) || (local_cc = 350.0, 6 < iVar4)) {
        local_cc = 175.0;
      }
      local_d0 = (float)FUN_0040c910();
      local_c8 = (undefined4 *)0x0;
      local_c4 = (undefined4 *)0x0;
      local_c0 = (undefined4 *)0x0;
      local_bc = 0;
      piVar13 = &DAT_005ef9a0;
      do {
        if (((*piVar13 != -1) && (*piVar13 != 0)) && (((uint)piVar13[0x57d] >> 1 & 1) != 0)) {
          local_8c = piVar13[-0xae1];
          local_84 = piVar13[-0xadf];
          local_88 = (float)piVar13[-0xae0] + _DAT_0059f124;
          cVar3 = FUN_004dc960(local_9c,&local_d4,local_cc);
          if (cVar3 != '\0') {
            iVar4 = __ftol();
            iVar5 = __ftol();
            if (((local_ac < iVar4) && (iVar4 < (int)fVar11)) &&
               (((int)local_b8 < iVar5 && ((iVar5 < (int)local_b4 && (_DAT_0059e478 < local_d4))))))
            {
              puVar6 = operator_new(0x10);
              *puVar6 = piVar13 + -0xcb2;
              puVar6[1] = local_d4;
              puVar6[2] = iVar4;
              puVar6[3] = iVar5;
              puVar7 = operator_new(0xc);
              if (puVar7 == (undefined4 *)0x0) {
                puVar7 = (undefined4 *)0x0;
              }
              else {
                *puVar7 = puVar6;
                puVar7[1] = 0;
                *(undefined1 *)(puVar7 + 2) = 1;
              }
              piVar1 = puVar7;
              piVar2 = puVar7;
              if (local_c8 != (undefined4 *)0x0) {
                local_c4[1] = (int)puVar7;
                piVar1 = local_c8;
                piVar2 = local_c0;
              }
              local_c0 = piVar2;
              local_c8 = piVar1;
              local_bc = local_bc + 1;
              fVar11 = local_b0;
              local_c4 = puVar7;
            }
          }
        }
        piVar13 = piVar13 + 0x1230;
      } while ((int)piVar13 < 0x7c87a0);
      if (local_bc == 0) {
        FUN_0049af30();
        return;
      }
      local_c8 = (int *)FUN_0049feb0(local_c8);
      local_c4 = local_c8;
      if (local_c8 != (int *)0x0) {
        piVar13 = (int *)local_c8[1];
        local_c4 = local_c8;
        while (piVar1 = piVar13, piVar1 != (int *)0x0) {
          local_c4 = piVar1;
          piVar13 = (int *)piVar1[1];
        }
      }
      local_c0 = local_c8;
      iVar4 = FUN_0053d1f0(PTR_s_FTFU30WH_005ccc10);
      if (iVar4 == 0) {
        FUN_0049af30();
        return;
      }
      local_a4 = *(undefined4 *)(iVar4 + 0x60);
      local_a0 = *(undefined4 *)(iVar4 + 0x5c);
      local_b0 = (float)DAT_005d6d60 * (float)_DAT_005acb18;
      local_b4 = (float)(int)DAT_005d6d64 * _DAT_005a68e8;
      local_d0 = local_b8;
      local_d4 = 0.0;
      local_c0 = local_c8;
      if ((local_c8 != (int *)0x0) && (piVar13 = (int *)*local_c8, piVar13 != (int *)0x0)) {
        while (((int)local_d4 < 3 &&
               ((float)(int)local_d0 <= (float)(int)DAT_005d6d64 * _DAT_0059f0c0))) {
          if ((*(char *)(local_a8 + 8) != '\0') ||
             (cVar3 = FUN_004624e0(*(undefined4 *)(*piVar13 + 0x4894),0xbf800000), cVar3 != '\0')) {
            local_80[0] = '\0';
            local_b8 = (float)piVar13[1] / local_cc;
            fVar11 = _DAT_0059e970 - local_b8 * _DAT_0059f0c0;
            *(float *)(iVar4 + 0x5c) = local_b0 * fVar11;
            *(float *)(iVar4 + 0x60) = fVar11 * local_b4;
            if ((DAT_007c56a4 == 7) && (iVar5 = *piVar13, 0 < *(int *)(iVar5 + 0x403c))) {
              if (DAT_007d0398 == 0) goto LAB_0049fc94;
              FUN_0058815f(local_80,s__d__s___d__005ccfd8,*(undefined4 *)(iVar5 + 0x4710),
                           iVar5 + 0x46f8,*(undefined4 *)(iVar5 + 0x4060));
            }
            else {
              iVar5 = *piVar13;
LAB_0049fc94:
              FUN_0058815f(local_80,&DAT_005c2c18,iVar5 + 0x46f8);
            }
            iVar5 = FUN_00461cd0();
            if ((iVar5 != 0) && (*(int *)(*piVar13 + 13000) == 2)) {
              FUN_00462530(*(undefined4 *)(*piVar13 + 0x4894));
              uVar8 = __ftol();
              local_9c[0] = '\0';
              FUN_0058815f(local_9c,s___d_ms__005ccfcc,uVar8);
              uVar9 = 0xffffffff;
              pcVar12 = local_9c;
              do {
                pcVar15 = pcVar12;
                if (uVar9 == 0) break;
                uVar9 = uVar9 - 1;
                pcVar15 = pcVar12 + 1;
                cVar3 = *pcVar12;
                pcVar12 = pcVar15;
              } while (cVar3 != '\0');
              uVar9 = ~uVar9;
              iVar5 = -1;
              pcVar12 = local_80;
              do {
                pcVar14 = pcVar12;
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                pcVar14 = pcVar12 + 1;
                cVar3 = *pcVar12;
                pcVar12 = pcVar14;
              } while (cVar3 != '\0');
              pcVar12 = pcVar15 + -uVar9;
              pcVar15 = pcVar14 + -1;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined4 *)pcVar15 = *(undefined4 *)pcVar12;
                pcVar12 = pcVar12 + 4;
                pcVar15 = pcVar15 + 4;
              }
              for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *pcVar15 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                pcVar15 = pcVar15 + 1;
              }
            }
            FUN_0049b370(local_80,&local_d0,iVar4,local_b8,*(char *)(local_a8 + 8) == '\0');
            local_d4 = (float)((int)local_d4 + 1);
          }
          if (((local_c0 == (int *)0x0) || (local_c0 = (int *)local_c0[1], local_c0 == (int *)0x0))
             || (piVar13 = (int *)*local_c0, piVar13 == (int *)0x0)) break;
        }
      }
      *(undefined4 *)(iVar4 + 0x5c) = local_a0;
      *(undefined4 *)(iVar4 + 0x60) = local_a4;
      piVar13 = local_c8;
      while (piVar13 != (int *)0x0) {
        piVar1 = (int *)piVar13[1];
        if ((char)piVar13[2] != '\0') {
          FUN_00587bcf(*piVar13);
        }
        FUN_00587bcf(piVar13);
        piVar13 = piVar1;
      }
    }
  }
  return;
}


