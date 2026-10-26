// Function: FUN_0045fc50 @ 0045fc50
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, %s %s, %s %s, *** Unsetting Slot (index %d), *** UNLOADING Slot (index %d) @ et=%8.4f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045fc50(int param_1)

{
  byte bVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined *puVar18;
  int iVar19;
  char *pcVar20;
  bool bVar21;
  int local_184;
  int local_180;
  int local_17c;
  char local_170 [104];
  undefined1 auStack_108 [260];
  
  if (*(char *)(param_1 + 0x374) == '\0') {
    pcVar17 = local_170;
    for (iVar13 = 0x1a; iVar13 != 0; iVar13 = iVar13 + -1) {
      pcVar17[0] = '\0';
      pcVar17[1] = '\0';
      pcVar17[2] = '\0';
      pcVar17[3] = '\0';
      pcVar17 = pcVar17 + 4;
    }
    bVar4 = false;
    bVar5 = false;
    bVar6 = false;
    local_17c = 0;
    local_180 = 0;
    if (0 < *(int *)(param_1 + 0x3e14)) {
      pcVar17 = (char *)(param_1 + 0x3d0);
      do {
        cVar9 = FUN_00461530();
        if (cVar9 != '\0') {
          iVar13 = -1;
          local_17c = local_17c + 1;
          pcVar20 = pcVar17;
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            cVar9 = *pcVar20;
            pcVar20 = pcVar20 + 1;
          } while (cVar9 != '\0');
          if (iVar13 != -2) {
            iVar15 = (int)pcVar17[0x40];
            iVar19 = iVar15 * 0x48c0;
            iVar13 = (&DAT_005ecdcc)[iVar15 * 0x1230];
            bVar3 = false;
            uVar10 = FUN_004c69e0();
            iVar11 = FUN_00588410(uVar10);
            if (((iVar11 != 0) || (iVar13 == 0)) || ((&DAT_005ef9a0)[iVar15 * 0x1230] == -1)) {
              FUN_004c7b20();
              FUN_00566650();
              uVar10 = FUN_004c69e0();
              iVar11 = FUN_00588410(uVar10);
              if ((iVar11 == 0) || (iVar13 == 0)) {
                FUN_0045c030();
                thunk_FUN_00500170();
                FUN_0045c850();
                iVar13 = FUN_00462330();
                if (iVar15 == iVar13) {
                  if ((*(int *)(&DAT_005f073c + iVar19) == 0) ||
                     ((&DAT_005ef9a0)[iVar15 * 0x1230] == -1)) {
                    FUN_004ef5a0(0,0);
                  }
                  FUN_0042bc40();
                }
                else {
                  FUN_004ef5a0(2,0);
                }
                FUN_004bc2f0();
                FUN_004bc320();
                if ((DAT_007c569c != 5) &&
                   (cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0xfae),
                   cVar9 != '\0')) {
                  FUN_004d7aa0(&DAT_008ad25c,s_____LOADING_Slot__index__d____s__005c5f2c,iVar15,
                               pcVar17,_DAT_008afea0);
                }
                DAT_005c329c = DAT_005c329c + 1;
                FUN_0042bc80();
                FUN_004c6c40();
                FUN_004c6d90();
                FUN_004d1030();
                if ((&DAT_005ef9a0)[iVar15 * 0x1230] == 0) {
                  if ((DAT_007c569c != 5) &&
                     (cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0xfc6),
                     cVar9 != '\0')) {
                    FUN_004d7aa0(&DAT_008ad25c);
                  }
                  iVar13 = 0;
                  bVar4 = true;
                  if (0 < DAT_005c329c) {
                    do {
                      FUN_004e0ed0();
                      iVar13 = iVar13 + 1;
                    } while (iVar13 < DAT_005c329c);
                  }
                  FUN_0042bbd0();
                  FUN_0040d100();
                  FUN_0049ca00();
                  FUN_00433870();
                }
                else {
                  bVar3 = true;
                  bVar5 = true;
                  FUN_00465430((&DAT_005f0f6c)[iVar15 * 0x1230],(int)pcVar17[0x41]);
                }
              }
            }
            _strncpy((char *)(iVar19 + 0x5f0d38),pcVar17 + -0x18,0x17);
            pbVar16 = (byte *)(pcVar17 + -0x38);
            (&DAT_005f0d4f)[iVar19] = 0;
            pbVar12 = &DAT_005f0cf8 + iVar19;
            do {
              bVar1 = *pbVar12;
              bVar21 = bVar1 < *pbVar16;
              if (bVar1 != *pbVar16) {
LAB_0045ff68:
                iVar13 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                goto LAB_0045ff6d;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar12[1];
              bVar21 = bVar1 < pbVar16[1];
              if (bVar1 != pbVar16[1]) goto LAB_0045ff68;
              pbVar12 = pbVar12 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar1 != 0);
            iVar13 = 0;
LAB_0045ff6d:
            if (iVar13 != 0) {
              FUN_004c6980();
            }
            if (bVar3) {
              iVar13 = FUN_00423a00(s_has_entered_the_game__005c5ef0,&DAT_005ec4cc);
              if (iVar13 != 0) {
                iVar13 = 0;
                do {
                  pcVar20 = s_has_entered_the_game__005c5ef0 + iVar13;
                  (&DAT_005ec4cc)[iVar13] = *pcVar20;
                  iVar13 = iVar13 + 1;
                } while (*pcVar20 != '\0');
              }
              FUN_0058815f(auStack_108,s__s__s_005c5d30,&DAT_005f0cf8 + iVar19);
              FUN_0045bd10(auStack_108,3,0x1020304);
            }
            local_170[iVar15] = '\x01';
          }
        }
        local_180 = local_180 + 1;
        pcVar17 = pcVar17 + 0x8c;
      } while (local_180 < *(int *)(param_1 + 0x3e14));
    }
    local_184 = 0;
    local_180 = 0;
    puVar18 = &DAT_005ec6d8;
    do {
      if ((local_170[local_180] == '\0') && (*(int *)(puVar18 + 13000) != -1)) {
        iVar13 = FUN_00423a00(s_left_the_game__005c5ee0,&DAT_005ec4cc);
        if (iVar13 != 0) {
          iVar13 = 0;
          do {
            pcVar17 = s_left_the_game__005c5ee0 + iVar13;
            (&DAT_005ec4cc)[iVar13] = *pcVar17;
            iVar13 = iVar13 + 1;
          } while (*pcVar17 != '\0');
        }
        FUN_0058815f(auStack_108,s__s__s_005c5d30,puVar18 + 0x4620);
        FUN_0045bd10(auStack_108,3,0x1020304);
        if ((DAT_007c569c != 5) &&
           (cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x100f),
           cVar9 != '\0')) {
          FUN_004d7aa0(&DAT_008ad25c,s_____UNLOADING_Slot__index__d____e_005c5eb4,
                       *(undefined4 *)(puVar18 + 0x4894),_DAT_008afea0);
        }
        bVar6 = true;
        if ((*(int *)(param_1 + 0x3fc4) == 2) || (*(int *)(param_1 + 0x3fc4) == 1)) {
          pcVar17 = puVar18 + 0x4714;
          uVar14 = 0xffffffff;
          pcVar20 = pcVar17;
          do {
            if (uVar14 == 0) break;
            uVar14 = uVar14 - 1;
            cVar9 = *pcVar20;
            pcVar20 = pcVar20 + 1;
          } while (cVar9 != '\0');
          for (pcVar20 = pcVar17 + (~uVar14 - 1); (pcVar17 < pcVar20 && (*pcVar20 != '\\'));
              pcVar20 = pcVar20 + -1) {
          }
          piVar2 = *(int **)(param_1 + 0x3fc8);
          *(int **)(param_1 + 0x3fd0) = piVar2;
          if ((piVar2 != (int *)0x0) && (iVar13 = *piVar2, iVar13 != 0)) {
            while (iVar11 = FUN_00588410(iVar13), iVar11 != 0) {
              if (*(int *)(param_1 + 0x3fd0) != 0) {
                *(undefined4 *)(param_1 + 0x3fd0) = *(undefined4 *)(*(int *)(param_1 + 0x3fd0) + 4);
              }
              if ((*(int **)(param_1 + 0x3fd0) == (int *)0x0) ||
                 (iVar13 = **(int **)(param_1 + 0x3fd0), iVar13 == 0)) goto LAB_004601f8;
            }
            if (iVar13 != 0) {
              piVar8 = *(int **)(param_1 + 0x3fc8);
              piVar2 = (int *)0x0;
              goto joined_r0x00460192;
            }
          }
        }
LAB_004601f8:
        FUN_004c6e80();
        FUN_004ef5a0(0xffffffff,0);
        local_184 = local_184 + 1;
        if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) == local_180) {
          if ((&DAT_005ef9a0)[*(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894) * 0x1230] == -1) {
            iVar13 = 0;
            if (0 < DAT_005c329c) {
              do {
                if (*(int *)((&DAT_007c54f0)[iVar13] + 13000) != -1) {
                  DAT_007c54e0 = (&DAT_007c54f0)[iVar13];
                  DAT_007c54dc = iVar13;
                  break;
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 < DAT_005c329c);
            }
          }
          else {
            FUN_0042bbd0();
          }
        }
        if ((DAT_007c569c != 5) &&
           (cVar9 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1044),
           cVar9 != '\0')) {
          FUN_004d7aa0(&DAT_008ad25c);
        }
      }
      local_180 = local_180 + 1;
      puVar18 = puVar18 + 0x48c0;
    } while ((int)puVar18 < 0x7c54d8);
    if (0 < local_184) {
      FUN_00460cb0();
      DAT_005c329c = DAT_005c329c - local_184;
      FUN_0042bc80();
    }
    if (*(int *)(param_1 + 0x3fc4) != 1) {
      if (bVar4) {
        FUN_004c8de0(0,0x3f800000);
      }
      if (bVar5) {
        FUN_004c8de0(1,0x3f800000);
      }
      if (bVar6) {
        FUN_004c8de0(2,0x3f800000);
      }
    }
    if (local_17c != DAT_005c329c) {
      DAT_005c329c = local_17c;
      FUN_0042bc80();
    }
  }
  return;
joined_r0x00460192:
  piVar7 = piVar8;
  if (piVar7 == (int *)0x0) goto LAB_004601f8;
  if (*piVar7 == iVar13) {
    if (piVar7 == *(int **)(param_1 + 0x3fd0)) {
      *(int *)(param_1 + 0x3fd0) = piVar7[1];
    }
    if (piVar2 == (int *)0x0) {
      *(int *)(param_1 + 0x3fc8) = piVar7[1];
    }
    else {
      piVar2[1] = piVar7[1];
    }
    if (*(int **)(param_1 + 0x3fcc) == piVar7) {
      *(int **)(param_1 + 0x3fcc) = piVar2;
    }
    *(int *)(param_1 + 0x3fd4) = *(int *)(param_1 + 0x3fd4) + -1;
    if ((char)piVar7[2] != '\0') {
      FUN_00587bcf();
    }
    FUN_00587bcf();
    goto LAB_004601f8;
  }
  piVar8 = (int *)piVar7[1];
  piVar2 = piVar7;
  goto joined_r0x00460192;
}


