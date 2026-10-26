// Function: FUN_004c6330 @ 004c6330
// Strings:  [Filter Properties]


int __thiscall FUN_004c6330(int param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  void *pvVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  byte *pbVar16;
  undefined4 *puVar17;
  bool bVar18;
  int local_3c0;
  int local_3bc [4];
  undefined4 local_3ac;
  undefined1 local_3a8;
  undefined4 local_3a4;
  undefined1 local_3a0;
  undefined4 local_39c;
  undefined1 local_398;
  undefined4 local_394;
  undefined1 local_390;
  undefined4 local_38f;
  int local_290 [50];
  int local_1c8 [50];
  char local_100 [255];
  undefined1 local_1;
  
  local_3bc[0] = 0;
  local_3bc[3] = param_1;
  FUN_004c62c0();
  if (param_2 != (byte *)0x0) {
    pbVar16 = &DAT_005ea438;
    pbVar6 = param_2;
    do {
      bVar1 = *pbVar6;
      bVar18 = bVar1 < *pbVar16;
      if (bVar1 != *pbVar16) {
LAB_004c6387:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_004c638c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar18 = bVar1 < pbVar16[1];
      if (bVar1 != pbVar16[1]) goto LAB_004c6387;
      pbVar6 = pbVar6 + 2;
      pbVar16 = pbVar16 + 2;
    } while (bVar1 != 0);
    iVar7 = 0;
LAB_004c638c:
    if ((iVar7 != 0) && ((iVar7 = 0, DAT_007d0398 == 0 || (DAT_007d0410 == 5)))) {
      FUN_00566650(param_2);
      local_3a8 = DAT_005d30d8;
      local_3ac = DAT_005d30d4;
      local_394 = DAT_005d30c0;
      local_3a4 = DAT_005d30cc;
      local_3a0 = DAT_005d30d0;
      local_3bc[0] = 0;
      local_3bc[2] = 0;
      local_3bc[1] = 0;
      local_39c = DAT_005d30c4;
      local_398 = DAT_005d30c8;
      local_3c0 = 0;
      _strncpy(local_100,(char *)param_2,0xff);
      piVar11 = local_1c8;
      for (iVar14 = 0x32; iVar14 != 0; iVar14 = iVar14 + -1) {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
      }
      piVar11 = local_290;
      for (iVar14 = 0x32; iVar14 != 0; iVar14 = iVar14 + -1) {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
      }
      local_1 = 0;
      iVar14 = FUN_005897ca(local_100,&local_3ac);
      while (iVar14 != 0) {
        iVar8 = FUN_00588410(iVar14,&local_3a4);
        if (iVar8 == 0) {
          local_3c0 = 0;
        }
        else {
          iVar8 = FUN_00588410(iVar14,&local_394);
          if (iVar8 == 0) {
            local_3c0 = 1;
          }
          else {
            iVar8 = FUN_00588410(iVar14,&local_39c);
            if (iVar8 == 0) {
              local_3c0 = 2;
            }
            else {
              if (local_3c0 == 0) {
LAB_004c64e1:
                piVar9 = local_3bc;
                piVar11 = local_290 + iVar7;
              }
              else if (local_3c0 == 1) {
                piVar9 = local_3bc + 2;
                piVar11 = local_1c8 + local_3bc[2];
              }
              else {
                if (local_3c0 != 2) goto LAB_004c64e1;
                piVar9 = local_3bc + 1;
                piVar11 = (int *)(&local_390 + local_3bc[1] * 4);
              }
              if (*piVar9 < 0x31) {
                *piVar9 = *piVar9 + 1;
                *piVar11 = iVar14;
                iVar7 = local_3bc[0];
              }
            }
          }
        }
        iVar14 = FUN_005897ca(0,&local_3ac);
      }
      FUN_004c5e50(local_290,iVar7);
      FUN_004c5fd0(local_1c8,local_3bc[2]);
      local_3bc[0] = FUN_004c6150(&local_390,local_3bc[1]);
      goto LAB_004c6640;
    }
  }
  FUN_00566650(&DAT_005ea438);
  iVar7 = 0;
  if (0 < DAT_008ac488) {
    local_3bc[1] = 0;
    do {
      if (local_3bc[1] + DAT_008ac490 != 0) {
        local_390 = DAT_005ea438;
        puVar15 = &local_38f;
        for (iVar14 = 0x3f; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar15 = 0;
          puVar15 = puVar15 + 1;
        }
        *(undefined2 *)puVar15 = 0;
        *(undefined1 *)((int)puVar15 + 2) = 0;
        FUN_004c58a0(&local_390,0x100,s_Filter_Properties_005d31ec,
                     local_3bc[1] + DAT_008ac490 + 0x104);
        pvVar10 = operator_new(0x10);
        if ((pvVar10 != (void *)0x0) && (iVar14 = FUN_004c5c80(iVar7,&local_390), iVar14 != 0)) {
          piVar11 = operator_new(0xc);
          if (piVar11 == (int *)0x0) {
            piVar11 = (int *)0x0;
          }
          else {
            *piVar11 = iVar14;
            piVar11[1] = 0;
            *(undefined1 *)(piVar11 + 2) = 1;
          }
          if (*(int *)(param_1 + 8) == 0) {
            *(int **)(param_1 + 8) = piVar11;
            *(int **)(param_1 + 0x10) = piVar11;
          }
          else {
            *(int **)(*(int *)(param_1 + 0xc) + 4) = piVar11;
          }
          *(int **)(param_1 + 0xc) = piVar11;
          local_3bc[0] = local_3bc[0] + 1;
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        }
      }
      iVar7 = iVar7 + 1;
      local_3bc[1] = local_3bc[1] + 0x18c;
    } while (iVar7 < DAT_008ac488);
  }
LAB_004c6640:
  puVar15 = *(undefined4 **)(param_1 + 8);
  iVar7 = 0;
  puVar13 = puVar15;
  if (puVar15 != (undefined4 *)0x0) {
    do {
      puVar13 = (undefined4 *)puVar13[1];
      iVar7 = iVar7 + 1;
    } while (puVar13 != (undefined4 *)0x0);
    if (1 < iVar7) {
      iVar7 = iVar7 / 2 + -1;
      puVar13 = puVar15;
      if (0 < iVar7) {
        do {
          iVar7 = iVar7 + -1;
          puVar13 = (undefined4 *)puVar13[1];
        } while (iVar7 != 0);
      }
      uVar2 = puVar13[1];
      puVar13[1] = 0;
      puVar12 = (undefined4 *)FUN_004c6810(puVar15);
      puVar13 = (undefined4 *)FUN_004c6810(uVar2);
      puVar15 = puVar13;
      if ((puVar12 != (undefined4 *)0x0) && (puVar15 = puVar12, puVar13 != (undefined4 *)0x0)) {
        cVar5 = FUN_004c5d30(*puVar13);
        param_1 = local_3bc[3];
        if (cVar5 == '\0') {
          puVar3 = (undefined4 *)puVar13[1];
          puVar4 = puVar13;
          puVar17 = puVar12;
        }
        else {
          puVar4 = puVar12;
          puVar3 = puVar13;
          puVar17 = (undefined4 *)puVar12[1];
          puVar13 = puVar12;
        }
        while (puVar15 = puVar13, puVar17 != (undefined4 *)0x0) {
          if (puVar3 == (undefined4 *)0x0) {
            if (puVar17 == (undefined4 *)0x0) goto LAB_004c6708;
            puVar4[1] = puVar17;
            goto LAB_004c6723;
          }
          local_3bc[3] = param_1;
          cVar5 = FUN_004c5d30(*puVar3);
          if (cVar5 == '\0') {
            puVar15 = (undefined4 *)puVar3[1];
            puVar12 = puVar3;
          }
          else {
            puVar12 = puVar17;
            puVar15 = puVar3;
            puVar17 = (undefined4 *)puVar17[1];
          }
          puVar4[1] = puVar12;
          puVar4 = puVar12;
          puVar3 = puVar15;
          param_1 = local_3bc[3];
        }
        if (puVar3 == (undefined4 *)0x0) {
LAB_004c6708:
          puVar4[1] = 0;
        }
        else {
          puVar4[1] = puVar3;
        }
      }
    }
  }
LAB_004c6723:
  *(undefined4 **)(param_1 + 8) = puVar15;
  puVar13 = puVar15;
  if (puVar15 != (undefined4 *)0x0) {
    puVar12 = (undefined4 *)puVar15[1];
    while (puVar3 = puVar12, puVar3 != (undefined4 *)0x0) {
      puVar13 = puVar3;
      puVar12 = (undefined4 *)puVar3[1];
    }
  }
  *(undefined4 **)(param_1 + 0xc) = puVar13;
  *(undefined4 **)(param_1 + 0x10) = puVar15;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return local_3bc[0];
}


