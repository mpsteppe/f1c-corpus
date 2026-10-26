// Function: FUN_004cf070 @ 004cf070
// Strings:  [WhH9], Could not open %s, CMAPS.MAS, D:\dev\F1_1999_2002\Source\specialfx.cpp, D:\dev\F1_1999_2002\Source\specialfx.cpp, REACTION, REACTION, REACTION]


void __fastcall FUN_004cf070(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  undefined1 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  float10 fVar14;
  undefined4 uVar15;
  int local_9f8;
  char *local_9f4;
  int local_9f0;
  int local_9ec;
  undefined4 local_9e8;
  float local_9e4;
  float local_9e0;
  float local_9dc;
  double local_9d8;
  double local_9d0;
  double local_9c8;
  undefined4 local_9c0;
  undefined4 local_9bc;
  undefined4 local_9b8;
  undefined4 local_9b4;
  undefined4 local_9a8;
  undefined1 local_9a4 [32];
  undefined1 local_984 [12];
  char local_978 [64];
  undefined1 local_938 [384];
  undefined4 local_7b8;
  undefined1 local_7b4;
  undefined4 local_7ac;
  undefined4 local_7a8;
  undefined4 local_7a4;
  char local_7a0 [384];
  undefined1 local_620 [32];
  undefined1 local_600 [256];
  undefined1 local_500 [256];
  undefined1 local_400 [256];
  char local_300 [256];
  undefined1 local_200 [256];
  char local_100 [256];
  
  pcVar2 = local_7a0;
  for (iVar11 = 0x60; iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  local_7b8 = 0;
  local_7a4 = 0;
  local_7ac = 0;
  local_7a8 = 0;
  local_7b4 = 1;
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_speci_005d3624,0xb5c);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_SpecialFX__Init___005d39b4);
  }
  pcVar2 = (char *)(DAT_008ac48c * 0x18c + 0x104 + DAT_008ac490);
  iVar11 = -(int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_300 + iVar11)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_004ceef0(local_400,0x100);
  FUN_00568a60(0xb5,param_1 + 0xe);
  iVar11 = FUN_00587db0(local_400,&DAT_005be690);
  if (iVar11 == 0) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,0xb70);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_open__s_005c6810,local_400);
      return;
    }
  }
  else {
    local_9ec = 0;
    param_1[2] = 0;
    local_9f0 = 0;
    iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
    if (iVar3 != 0) {
      local_9f4 = local_100;
      do {
        iVar3 = FUN_005651b0();
        if (iVar3 == 0) {
          iVar3 = FUN_00587c20(local_7a0,s__TRACKVARS__005d39a8);
          if (iVar3 != 0) {
            iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
            while (((iVar3 != 0 && (iVar3 = FUN_005651b0(), iVar3 != 1)) && (iVar3 != 4))) {
              iVar6 = local_9ec;
              if ((iVar3 == 0) &&
                 (puVar4 = (undefined1 *)FUN_00589db0(local_7a0,0x3d), puVar4 != (undefined1 *)0x0))
              {
                uVar12 = 0xffffffff;
                pcVar2 = local_7a0;
                do {
                  if (uVar12 == 0) break;
                  uVar12 = uVar12 - 1;
                  cVar1 = *pcVar2;
                  pcVar2 = pcVar2 + 1;
                } while (cVar1 != '\0');
                if (~uVar12 - 1 < 0x20) {
                  *puVar4 = 0;
                  pvVar5 = operator_new(0x28);
                  if (pvVar5 == (void *)0x0) {
                    iVar6 = 0;
                  }
                  else {
                    iVar6 = FUN_004c9d10();
                  }
                  pcVar2 = local_7a0;
                  do {
                    cVar1 = *pcVar2;
                    pcVar2[iVar6 - (int)local_7a0] = cVar1;
                    pcVar2 = pcVar2 + 1;
                  } while (cVar1 != '\0');
                  fVar14 = (float10)FUN_0058850f(puVar4 + 1);
                  *(float *)(iVar6 + 0x20) = (float)fVar14;
                  *(int *)(iVar6 + 0x24) = local_9ec;
                  iVar3 = FUN_004c58a0(local_620,0x20,iVar6,0);
                  if (iVar3 == 0) {
                    fVar14 = (float10)FUN_0058850f(local_620);
                    *(float *)(iVar6 + 0x20) = (float)fVar14;
                  }
                }
              }
              iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              local_9ec = iVar6;
            }
          }
          iVar3 = FUN_00587c20(local_7a0,s__FEEDBACK__005d399c);
          if (iVar3 == 0) {
            iVar3 = FUN_00587c20(local_7a0,s__LOOSE__005d3974);
            if (iVar3 != 0) {
              iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              while (((iVar3 != 0 && (iVar3 = FUN_005651b0(), iVar3 != 1)) && (iVar3 != 4))) {
                if ((iVar3 == 0) &&
                   (iVar3 = FUN_00565520(s_REACTION_005d36d8,local_600,0), iVar3 != 0)) {
                  local_9f0 = local_9f0 + 1;
                }
                iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              }
            }
          }
          else {
            cVar1 = '\x01';
            iVar3 = 0;
            iVar6 = FUN_00587ca0(local_7a0,0x180,iVar11);
            while (((iVar6 != 0 && (iVar6 = FUN_005651b0(), iVar6 != 1)) && (iVar6 != 4))) {
              if (iVar6 == 0) {
                iVar6 = FUN_00565520(s_INCLUDETRACKS_005d398c,local_600,0);
                if ((iVar6 != 0) && (iVar6 = FUN_00566810(), iVar6 == 0)) {
                  cVar1 = '\0';
                }
                iVar6 = FUN_00565520(s_EXCLUDETRACKS_005d397c,local_600,0);
                if ((iVar6 != 0) && (iVar6 = FUN_00566810(), iVar6 != 0)) {
                  cVar1 = '\0';
                }
                iVar6 = FUN_00565520(s_REACTION_005d36d8,local_600,0);
                if (iVar6 != 0) {
                  iVar3 = iVar3 + 1;
                }
              }
              iVar6 = FUN_00587ca0(local_7a0,0x180,iVar11);
            }
            *local_9f4 = cVar1;
            local_9f4 = local_9f4 + 1;
            if (cVar1 != '\0') {
              local_9f0 = local_9f0 + iVar3;
              param_1[2] = param_1[2] + 1;
            }
          }
        }
        iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
      } while (iVar3 != 0);
    }
    iVar3 = param_1[2];
    piVar7 = operator_new(iVar3 * 0x6c + 4);
    if (piVar7 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = piVar7 + 1;
      *piVar7 = iVar3;
      if (-1 < iVar3 + -1) {
        do {
          FUN_004cdb90();
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    param_1[3] = (int)piVar9;
    piVar7 = operator_new(local_9f0 * 0x6c + 4);
    if (piVar7 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = piVar7 + 1;
      *piVar7 = local_9f0;
      if (-1 < local_9f0 + -1) {
        do {
          FUN_004ca3e0();
          local_9f0 = local_9f0 + -1;
        } while (local_9f0 != 0);
      }
    }
    param_1[5] = (int)piVar9;
    param_1[4] = 0;
    puVar4 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    puVar8 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar8 = &DAT_005ea438;
    }
    FUN_0058815f(local_500,&DAT_005be860,puVar8,puVar4);
    FUN_0058815f(local_200,s_CMAPS_MAS_005cceb0);
    FUN_00587f64(iVar11,0,0);
    iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
    if (iVar3 != 0) {
      local_9f4 = local_100;
      local_9f8 = 0;
      do {
        iVar3 = FUN_005651b0();
        if (iVar3 == 0) {
          iVar3 = FUN_00587c20(local_7a0,s__FEEDBACK__005d399c);
          if (iVar3 == 0) {
            iVar3 = FUN_00587c20(local_7a0,s__LOOSE__005d3974);
            if (iVar3 != 0) {
              iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              while (((iVar3 != 0 && (iVar3 = FUN_005651b0(), iVar3 != 1)) && (iVar3 != 4))) {
                if (iVar3 == 0) {
                  iVar3 = FUN_00565520(s_REACTION_005d36d8,local_600,0);
                  if (iVar3 != 0) {
                    FUN_004ca480(local_938);
                    iVar3 = param_1[4];
                    iVar6 = 0;
                    if (0 < iVar3) {
                      do {
                        cVar1 = FUN_004caed0(iVar3 * 0x6c + param_1[5]);
                        if (cVar1 != '\0') break;
                        iVar3 = param_1[4];
                        iVar6 = iVar6 + 1;
                      } while (iVar6 < iVar3);
                    }
                    if (iVar6 == param_1[4]) {
                      param_1[4] = param_1[4] + 1;
                    }
                  }
                  FUN_00565520(s_SEARCHPATH_005d3968,local_500,0);
                  FUN_00565520(s_MASFILE_005d3960,local_200,0);
                }
                iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              }
            }
          }
          else {
            cVar1 = *local_9f4;
            local_9f4 = local_9f4 + 1;
            if (cVar1 == '\0') {
              iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              while ((iVar3 != 0 && (iVar3 = FUN_005651b0(), iVar3 != 1))) {
                iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              }
            }
            else {
              iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              while (((iVar3 != 0 && (iVar3 = FUN_005651b0(), iVar3 != 1)) && (iVar3 != 4))) {
                if (iVar3 == 0) {
                  iVar3 = FUN_00565520(s_REACTION_005d36d8,local_600,0);
                  if (iVar3 != 0) {
                    FUN_004ca480(local_938);
                    iVar3 = param_1[4];
                    iVar6 = 0;
                    if (0 < iVar3) {
                      do {
                        cVar1 = FUN_004caed0(iVar3 * 0x6c + param_1[5]);
                        if (cVar1 != '\0') break;
                        iVar3 = param_1[4];
                        iVar6 = iVar6 + 1;
                      } while (iVar6 < iVar3);
                    }
                    if (iVar6 == param_1[4]) {
                      param_1[4] = param_1[4] + 1;
                    }
                    iVar3 = param_1[3] + local_9f8;
                    *(int *)(iVar3 + 0x40 + *(int *)(param_1[3] + 0x3c + local_9f8) * 4) =
                         iVar6 * 0x6c + param_1[5];
                    piVar7 = (int *)(iVar3 + 0x3c);
                    *piVar7 = *piVar7 + 1;
                  }
                  FUN_004cdd80(local_938,local_9ec);
                }
                iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
              }
              local_9f8 = local_9f8 + 0x6c;
            }
          }
        }
        iVar3 = FUN_00587ca0(local_7a0,0x180,iVar11);
      } while (iVar3 != 0);
    }
    FUN_00587d02(iVar11);
    if (local_9ec != 0) {
      FUN_004c9d30();
      FUN_00587bcf(local_9ec);
    }
    iVar11 = 0;
    if (0 < param_1[4]) {
      iVar3 = 0;
      do {
        *(int *)(iVar3 + param_1[5]) = iVar11;
        iVar11 = iVar11 + 1;
        iVar3 = iVar3 + 0x6c;
      } while (iVar11 < param_1[4]);
    }
    FUN_0053c800(local_500);
    FUN_0053cbc0(&local_9e8,local_200);
    iVar11 = 0;
    do {
      iVar3 = 0;
      if (0 < param_1[4]) {
        iVar6 = 0;
        do {
          switch(*(undefined4 *)(iVar6 + param_1[5] + 4)) {
          case 4:
          case 0xb:
          case 0xc:
          case 0xd:
            bVar13 = iVar11 == 1;
            break;
          default:
            bVar13 = iVar11 == 2;
            break;
          case 6:
          case 7:
          case 8:
            bVar13 = iVar11 == 0;
            break;
          case 9:
          case 10:
            if (iVar11 == 0) {
              uVar15 = 0;
              goto LAB_004cf9b6;
            }
            goto LAB_004cf9bb;
          }
          if (bVar13) {
            uVar15 = 1;
LAB_004cf9b6:
            FUN_004cb120(uVar15);
          }
LAB_004cf9bb:
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + 0x6c;
        } while (iVar3 < param_1[4]);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
    FUN_0053c900(local_500);
    FUN_0053ce40(local_9e8);
    FUN_004cef30();
    iVar11 = param_1[4];
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    if (0 < iVar11) {
      iVar3 = param_1[5];
      do {
        iVar6 = *(int *)(iVar3 + 4);
        if (iVar6 == 0xc) {
          param_1[6] = iVar3;
        }
        else if (iVar6 == 0xd) {
          param_1[7] = iVar3;
        }
        else if (iVar6 == 1) {
          param_1[8] = iVar3;
        }
        else if (iVar6 == 3) {
          param_1[9] = iVar3;
        }
        else if (iVar6 == 4) {
          param_1[10] = iVar3;
        }
        iVar3 = iVar3 + 0x6c;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_0044c0e0(2);
    FUN_004024f0();
    FUN_00403cd0(0,&local_9e4,local_984);
    local_9d8 = (double)local_9e4;
    local_9d0 = (double)local_9e0;
    local_9c8 = (double)local_9dc;
    local_9c0 = 0;
    local_9bc = 0x40240000;
    local_9b8 = 0x40000000;
    local_9b4 = 0x479e17b8;
    local_9a8 = 0;
    iVar11 = FUN_0044c4c0(&local_9d8);
    if (iVar11 != 0) {
      iVar11 = *(int *)(iVar11 + 0x54);
      param_1[0xb] = iVar11;
      param_1[0xc] = (int)(*(float *)(iVar11 + 8) - *(float *)(iVar11 + 0xc) * DAT_0059e440);
      param_1[0xd] = (int)(*(float *)(iVar11 + 8) - *(float *)(iVar11 + 0xc));
    }
    iVar11 = FUN_004c58a0(local_9a4,0x20,s_AIDryGrip_005d3954,0);
    if (iVar11 == 0) {
      fVar14 = (float10)FUN_0058850f(local_9a4);
      param_1[0xc] = (int)(float)fVar14;
    }
    iVar11 = FUN_004c58a0(local_9a4,0x20,s_AIWetGrip_005d3948,0);
    if (iVar11 == 0) {
      fVar14 = (float10)FUN_0058850f(local_9a4);
      param_1[0xd] = (int)(float)fVar14;
    }
    *param_1 = 0;
    local_978[0] = '\0';
    iVar11 = FUN_005452f0();
    if (0 < iVar11) {
      iVar3 = 0;
      do {
        iVar6 = FUN_00545340(iVar3);
        if (((byte)*(undefined4 *)(iVar6 + 0x3c) & 0x10) == 0x10) {
          FUN_0054bda0(local_978);
          iVar6 = _strncmp(local_978,s_LPTREE_005d3940,6);
          if (iVar6 == 0) {
            *param_1 = *param_1 + 1;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar11);
    }
    iVar3 = *param_1;
    piVar7 = operator_new(iVar3 * 0x3c + 4);
    if (piVar7 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = piVar7 + 1;
      *piVar7 = iVar3;
      piVar7 = piVar9;
      if (-1 < iVar3 + -1) {
        do {
          piVar7[0xe] = 0;
          FUN_004ca280();
          iVar3 = iVar3 + -1;
          piVar7 = piVar7 + 0xf;
        } while (iVar3 != 0);
      }
    }
    iVar3 = 0;
    param_1[1] = (int)piVar9;
    if (0 < iVar11) {
      do {
        iVar6 = FUN_00545340(iVar3);
        if (((byte)*(undefined4 *)(iVar6 + 0x3c) & 0x10) == 0x10) {
          FUN_0054bda0(local_978);
          iVar10 = _strncmp(local_978,s_LPTREE_005d3940,6);
          if (iVar10 == 0) {
            FUN_004c9fb0(iVar6);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar11);
    }
  }
  return;
}


