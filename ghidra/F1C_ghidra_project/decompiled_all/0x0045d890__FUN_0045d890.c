// Function: FUN_0045d890 @ 0045d890
// Strings:  [terrain.ini, D:\dev\F1_1999_2002\Source\NetComm.cpp, %s "%s" %s, mismatch, mismatch, %s %s, was removed from the game, was removed from the game]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0045d890(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  char cVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  size_t _Count;
  char *pcVar17;
  char *pcVar18;
  int iVar19;
  undefined4 uVar20;
  undefined1 local_295;
  char *local_294;
  undefined4 local_290;
  char local_28c [79];
  undefined1 local_23d;
  char local_23c [4];
  undefined1 local_238 [136];
  undefined1 local_1b0;
  undefined4 local_1af;
  char local_1a8 [424];
  
  uVar15 = *param_2;
  bVar6 = false;
  local_295 = 1;
  if ((uVar15 & 0xe0000000) == 0x80000000) {
    switch(uVar15 >> 0x12 & 0x3f) {
    case 0:
    case 1:
      break;
    case 2:
      if (*(int *)(param_1 + 0x3fc4) == 3) {
        puVar14 = param_2 + 2;
        puVar8 = (uint *)(param_1 + 0x3fd8);
        for (iVar19 = 0x68; iVar19 != 0; iVar19 = iVar19 + -1) {
          *puVar8 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar8 = puVar8 + 1;
        }
        *(short *)puVar8 = (short)*puVar14;
        FUN_00460710();
        *(undefined4 *)(param_1 + 0x10) = 0x3fc00000;
        *(undefined1 *)(param_1 + 0x14) = 1;
        iVar19 = FUN_00423a00(s_Next_session_005c5dac,&DAT_005ec4cc);
        if (iVar19 != 0) {
          iVar19 = 0;
          do {
            pcVar18 = s_Next_session_005c5dac + iVar19;
            (&DAT_005ec4cc)[iVar19] = *pcVar18;
            iVar19 = iVar19 + 1;
          } while (*pcVar18 != '\0');
        }
        cVar7 = FUN_004a0e70(&DAT_005ec4cc);
        if (cVar7 == '\0') {
          FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
          *(undefined4 *)(param_1 + 0x380) = DAT_0059f0b0;
          return 1;
        }
        Sleep(1000);
        *(undefined4 *)(param_1 + 0x380) = DAT_0059f0b0;
        return 1;
      }
      break;
    case 3:
      uVar15 = param_2[0x6b];
      FUN_004b33b0(4,4,0x1a4,0xff,(float)_DAT_008afea0,1);
      cVar7 = FUN_0045e5f0(uVar15);
      if (cVar7 == '\0') {
        uVar10 = FUN_0045e5b0();
        FUN_0045e5d0(uVar10,uVar15);
        param_2[2] = uVar10;
        puVar14 = param_2 + 3;
        for (iVar19 = 0x68; iVar19 != 0; iVar19 = iVar19 + -1) {
          *puVar14 = 0xbf800000;
          puVar14 = puVar14 + 1;
        }
        iVar19 = 0;
        if (0 < DAT_005c329c) {
          do {
            iVar2 = (&DAT_007c54f0)[iVar19];
            if (iVar2 != 0) {
              param_2[*(int *)(iVar2 + 0x4894) + 3] = *(uint *)(iVar2 + 0x409c);
            }
            iVar19 = iVar19 + 1;
          } while (iVar19 < DAT_005c329c);
        }
      }
      else {
        param_2[2] = 0xffffffff;
        puVar14 = param_2 + 3;
        for (iVar19 = 0x68; iVar19 != 0; iVar19 = iVar19 + -1) {
          *puVar14 = 0xbf800000;
          puVar14 = puVar14 + 1;
        }
      }
      FUN_00462250(param_2,2,uVar15,0xffffffff);
      FUN_004b33b0(4,0x23,2,0xff,(float)_DAT_008afea0,1);
      *(undefined1 *)(param_2 + 2) = *(undefined1 *)(param_1 + 0x1b754);
      *(undefined1 *)((int)param_2 + 9) = *(undefined1 *)(param_1 + 0x1b755);
      FUN_00462250(param_2,2,uVar15,0xffffffff);
      DAT_008aff00 = 1;
      return 1;
    case 4:
      if ((DAT_007c569c != 5) &&
         (cVar7 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x99d), cVar7 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s_Received_server_verify__setting_s_005c5d78);
      }
      puVar14 = param_2 + 3;
      puVar8 = &DAT_005f0774;
      do {
        puVar9 = puVar8 + 0x1230;
        *puVar8 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar8 = puVar9;
      } while ((int)puVar9 < 0x7c9574);
      FUN_00460520(param_2[2]);
      return 1;
    case 5:
      if (*(char *)(param_1 + 0x20) == '\0') {
        *(undefined4 *)(param_1 + 0x1c) = DAT_0059f0ac;
        *(undefined1 *)(param_1 + 0x20) = 1;
      }
      iVar19 = FUN_00423a00(s_Next_Track_005c5d6c,&DAT_005ec4cc);
      if (iVar19 != 0) {
        iVar19 = 0;
        do {
          pcVar18 = s_Next_Track_005c5d6c + iVar19;
          (&DAT_005ec4cc)[iVar19] = *pcVar18;
          iVar19 = iVar19 + 1;
        } while (*pcVar18 != '\0');
      }
      cVar7 = FUN_004a0e70(&DAT_005ec4cc);
      if (cVar7 == '\0') {
        FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
        return 1;
      }
      Sleep(1000);
      return 1;
    case 6:
      uVar15 = uVar15 >> 8 & 0x3ff;
      if (uVar15 == 0) {
        return 1;
      }
      *(undefined1 *)(uVar15 + 8 + (int)param_2) = 0;
      local_1b0 = DAT_005ea438;
      puVar13 = &local_1af;
      for (iVar19 = 0x3f; iVar19 != 0; iVar19 = iVar19 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      *(undefined2 *)puVar13 = 0;
      *(undefined1 *)((int)puVar13 + 2) = 0;
      FUN_00461470();
      FUN_00462460(*param_2 & 0xff,local_23c,&local_294);
      if (*(int *)(param_1 + 0x3fc4) != 1) {
        FUN_0045bc50(local_238,param_2 + 2,&local_1b0,0x100);
        if ((DAT_007ce254 == '\0') && (DAT_007d1044 != '\0')) {
          FUN_0045bd10(&local_1b0,3,0x1020304);
        }
        puVar13 = operator_new(8);
        if (puVar13 == (undefined4 *)0x0) {
          puVar13 = (undefined4 *)0x0;
        }
        else {
          *puVar13 = 0;
          puVar13[1] = 0xffffffff;
        }
        FUN_00566650(&local_1b0);
        FUN_00434030(puVar13,0);
        FUN_0045ebd0();
      }
      bVar6 = true;
      FUN_004b0170();
      goto LAB_0045e47d;
    default:
      goto switchD_0045d8d8_caseD_7;
    case 0x20:
      if ((*(int *)(param_1 + 0x3fc4) != 2) && (*(int *)(param_1 + 0x3fc4) != 1)) {
        uVar15 = param_2[2];
        uVar10 = FUN_00462300();
        if (uVar10 == uVar15) {
          iVar19 = FUN_00423a00(s_You_have_been_booted_005c5d54,&DAT_005ec4cc);
          if (iVar19 != 0) {
            iVar19 = 0;
            do {
              pcVar18 = s_You_have_been_booted_005c5d54 + iVar19;
              (&DAT_005ec4cc)[iVar19] = *pcVar18;
              iVar19 = iVar19 + 1;
            } while (*pcVar18 != '\0');
          }
          puVar13 = operator_new(8);
          if (puVar13 == (undefined4 *)0x0) {
            puVar13 = (undefined4 *)0x0;
          }
          else {
            *puVar13 = 0;
            puVar13[1] = 0xffffffff;
          }
          FUN_00566650(&DAT_005ec4cc);
          FUN_00434030(puVar13,0);
          FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
          FUN_0057a660();
          cVar7 = FUN_004a0e70(&DAT_005ec4cc);
          if (cVar7 != '\0') {
            Sleep(1000);
            return 1;
          }
        }
        else {
          pcVar17 = (char *)FUN_0045eb50(uVar15);
          iVar19 = -1;
          pcVar18 = pcVar17;
          do {
            if (iVar19 == 0) break;
            iVar19 = iVar19 + -1;
            cVar7 = *pcVar18;
            pcVar18 = pcVar18 + 1;
          } while (cVar7 != '\0');
          if (iVar19 != -2) {
            iVar19 = FUN_00423a00(s_was_removed_from_the_game_005c5d38,&DAT_005ec4cc);
            if (iVar19 != 0) {
              iVar19 = 0;
              do {
                pcVar18 = s_was_removed_from_the_game_005c5d38 + iVar19;
                (&DAT_005ec4cc)[iVar19] = *pcVar18;
                iVar19 = iVar19 + 1;
              } while (*pcVar18 != '\0');
            }
            FUN_0058815f(local_28c,s__s__s_005c5d30,pcVar17,&DAT_005ec4cc);
            FUN_0045bd10(local_28c,3,0x1020304);
            return 1;
          }
        }
      }
      break;
    case 0x23:
      *(char *)(param_1 + 0x1b768) = (char)param_2[2];
      *(undefined1 *)(param_1 + 0x1b769) = *(undefined1 *)((int)param_2 + 9);
      FUN_004607a0();
      return 1;
    case 0x24:
      iVar19 = (uVar15 & 0xff) * 0x48c0;
      pcVar18 = (char *)0x0;
      local_294 = (char *)0x0;
      if ((iVar19 != -0x5ec6d8) && (iVar19 = FUN_004c40b0(&DAT_005f0dec + iVar19), iVar19 != 0)) {
        pcVar17 = *(char **)(iVar19 + 8);
        if (pcVar17 == (char *)0x0) {
          pcVar17 = &DAT_005ea438;
        }
        uVar15 = 0xffffffff;
        pcVar18 = pcVar17;
        do {
          if (uVar15 == 0) break;
          uVar15 = uVar15 - 1;
          cVar7 = *pcVar18;
          pcVar18 = pcVar18 + 1;
        } while (cVar7 != '\0');
        for (pcVar18 = pcVar17 + (~uVar15 - 1); local_294 = pcVar18, pcVar17 < pcVar18;
            pcVar18 = pcVar18 + -1) {
          if (*pcVar18 == '\\') {
            pcVar18 = pcVar18 + 1;
            local_294 = pcVar18;
            break;
          }
        }
      }
      cVar7 = FUN_00460a10(param_2,pcVar18);
      if (cVar7 == '\0') {
        local_290 = 0;
        do {
          switch(local_290) {
          case 0:
            cVar7 = *(char *)(param_1 + 0x1b76a);
            iVar19 = 0;
            do {
              cVar1 = (&DAT_005c5d2c)[iVar19];
              local_28c[iVar19] = cVar1;
              iVar19 = iVar19 + 1;
            } while (cVar1 != '\0');
            break;
          case 1:
            cVar7 = *(char *)(param_1 + 0x1b76b);
            if (local_294 == (char *)0x0) {
              local_28c[0] = '\0';
            }
            else {
              pcVar18 = local_294;
              do {
                cVar1 = *pcVar18;
                pcVar18[(int)(local_28c + -(int)local_294)] = cVar1;
                pcVar18 = pcVar18 + 1;
              } while (cVar1 != '\0');
            }
            break;
          case 2:
            cVar7 = *(char *)(param_1 + 0x1b76c);
            iVar19 = 0;
            do {
              cVar1 = s_terrain_ini_005c5b88[iVar19];
              local_28c[iVar19] = cVar1;
              iVar19 = iVar19 + 1;
            } while (cVar1 != '\0');
            break;
          case 3:
            cVar7 = *(char *)(param_1 + 0x1b76d);
            pcVar18 = DAT_007ce5d0;
            if (DAT_007ce5d0 == (char *)0x0) {
              pcVar18 = &DAT_005ea438;
            }
            uVar15 = 0xffffffff;
            pcVar17 = pcVar18;
            do {
              if (uVar15 == 0) break;
              uVar15 = uVar15 - 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar17 + 1;
            } while (cVar1 != '\0');
            for (pcVar17 = pcVar18 + (~uVar15 - 1); pcVar18 < pcVar17; pcVar17 = pcVar17 + -1) {
              if (*pcVar17 == '\\') {
                pcVar17 = pcVar17 + 1;
                break;
              }
            }
            _strncpy(local_28c,pcVar17,0x4f);
            uVar15 = 0xffffffff;
            local_23d = 0;
            pcVar18 = local_28c;
            do {
              if (uVar15 == 0) break;
              uVar15 = uVar15 - 1;
              cVar1 = *pcVar18;
              pcVar18 = pcVar18 + 1;
            } while (cVar1 != '\0');
            pcVar18 = local_28c + (~uVar15 - 1);
            if (local_28c < pcVar18) {
              do {
                if (*pcVar18 == '.') {
                  *pcVar18 = '\0';
                  break;
                }
                pcVar18 = pcVar18 + -1;
              } while (local_28c < pcVar18);
            }
            iVar19 = -1;
            pcVar18 = local_28c;
            do {
              pcVar17 = pcVar18;
              if (iVar19 == 0) break;
              iVar19 = iVar19 + -1;
              pcVar17 = pcVar18 + 1;
              cVar1 = *pcVar18;
              pcVar18 = pcVar17;
            } while (cVar1 != '\0');
            *(undefined4 *)(pcVar17 + -1) = DAT_005c5d24;
            pcVar17[3] = DAT_005c5d28;
            break;
          case 4:
            cVar7 = *(char *)(param_1 + 0x1b76e);
            puVar16 = DAT_007d0434;
            if (DAT_007d0434 == (undefined1 *)0x0) {
              puVar16 = &DAT_005ea438;
            }
            puVar11 = DAT_005ec3d8;
            if (DAT_005ec3d8 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            FUN_0058969d(local_28c,0x50,&DAT_005be860,puVar11,puVar16);
            local_23d = 0;
            break;
          default:
            goto switchD_0045deef_default;
          }
          if (cVar7 == '\0') {
            uVar20 = FUN_0045eb50(param_2[0x6b]);
            iVar19 = FUN_00423a00(s_mismatch_005c5d18,&DAT_005ec4cc);
            if (iVar19 != 0) {
              iVar19 = 0;
              do {
                pcVar18 = s_mismatch_005c5d18 + iVar19;
                (&DAT_005ec4cc)[iVar19] = *pcVar18;
                iVar19 = iVar19 + 1;
              } while (*pcVar18 != '\0');
            }
            FUN_0058815f(local_23c,s__s___s___s_005c5d0c,uVar20,local_28c,&DAT_005ec4cc);
            puVar13 = operator_new(8);
            if (puVar13 == (undefined4 *)0x0) {
              puVar13 = (undefined4 *)0x0;
            }
            else {
              *puVar13 = 0;
              puVar13[1] = 0xffffffff;
            }
            FUN_00566650(local_23c);
            if (puVar13 != (undefined4 *)0x0) {
              puVar12 = operator_new(0xc);
              if (puVar12 == (undefined4 *)0x0) {
                puVar12 = (undefined4 *)0x0;
              }
              else {
                *puVar12 = puVar13;
                puVar12[1] = 0;
                *(undefined1 *)(puVar12 + 2) = 0;
              }
              if (*(int *)(param_1 + 0x1b770) == 0) {
                *(undefined4 **)(param_1 + 0x1b770) = puVar12;
                *(undefined4 **)(param_1 + 0x1b778) = puVar12;
              }
              else {
                *(undefined4 **)(*(int *)(param_1 + 0x1b774) + 4) = puVar12;
              }
              *(undefined4 **)(param_1 + 0x1b774) = puVar12;
              *(int *)(param_1 + 0x1b77c) = *(int *)(param_1 + 0x1b77c) + 1;
            }
            FUN_0045bd10(local_23c,3,0x1020304);
            uVar15 = 0xffffffff;
            pcVar18 = local_23c;
            do {
              if (uVar15 == 0) break;
              uVar15 = uVar15 - 1;
              cVar7 = *pcVar18;
              pcVar18 = pcVar18 + 1;
            } while (cVar7 != '\0');
            _Count = ~uVar15 - 1;
            if ((int)_Count < 0) {
              _Count = 0;
            }
            else if (0x9f < (int)_Count) {
              _Count = 0x9f;
            }
            FUN_004b33b0(4,6,_Count,0,(float)_DAT_008afea0,1);
            _strncpy(local_1a8,local_23c,_Count);
            local_1a8[_Count] = '\0';
            FUN_00462250(&local_1b0,0,0xffffffff,0xffffffff);
          }
switchD_0045deef_default:
          local_290 = local_290 + 1;
          if (4 < local_290) {
            return 1;
          }
        } while( true );
      }
      break;
    case 0x27:
      if (DAT_007d10d4 != '\0') {
        piVar3 = *(int **)(param_1 + 0x3fc8);
        *(int **)(param_1 + 0x3fd0) = piVar3;
        if ((piVar3 != (int *)0x0) && (iVar19 = *piVar3, iVar19 != 0)) {
          do {
            iVar19 = FUN_00588410(iVar19,param_2 + 2);
            if (iVar19 == 0) {
              uVar20 = 0x29;
              goto LAB_0045e2ca;
            }
            if (*(int *)(param_1 + 0x3fd0) != 0) {
              *(undefined4 *)(param_1 + 0x3fd0) = *(undefined4 *)(*(int *)(param_1 + 0x3fd0) + 4);
            }
          } while ((*(int **)(param_1 + 0x3fd0) != (int *)0x0) &&
                  (iVar19 = **(int **)(param_1 + 0x3fd0), iVar19 != 0));
        }
      }
      pcVar18 = operator_new(0x80);
      _strncpy(pcVar18,(char *)(param_2 + 2),0x7f);
      pcVar18[0x7f] = '\0';
      puVar13 = operator_new(0xc);
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)0x0;
      }
      else {
        *puVar13 = pcVar18;
        puVar13[1] = 0;
        *(undefined1 *)(puVar13 + 2) = 1;
      }
      if (*(int *)(param_1 + 0x3fc8) == 0) {
        *(undefined4 **)(param_1 + 0x3fc8) = puVar13;
        *(undefined4 **)(param_1 + 0x3fd0) = puVar13;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0x3fcc) + 4) = puVar13;
      }
      *(undefined4 **)(param_1 + 0x3fcc) = puVar13;
      *(int *)(param_1 + 0x3fd4) = *(int *)(param_1 + 0x3fd4) + 1;
      uVar20 = 0x28;
LAB_0045e2ca:
      FUN_004b33b0(4,uVar20,0,0xff,(float)_DAT_008afea0,1);
      FUN_00462250(&local_1b0,2,param_2[0x6b],0xffffffff);
      return 1;
    case 0x28:
      *(undefined4 *)(param_1 + 0x378) = 2;
      return 1;
    case 0x29:
      *(undefined4 *)(param_1 + 0x378) = 3;
      return 1;
    case 0x2a:
      iVar19 = 0;
      if (0 < *(int *)(param_1 + 0x3e14)) {
        pcVar18 = (char *)(param_1 + 0x410);
        do {
          cVar7 = FUN_00461530(1);
          if ((cVar7 != '\0') && (cVar7 = FUN_0045ca20((int)*pcVar18,&local_294,1), cVar7 != '\0'))
          {
            local_290 = (int)(short)param_2[2];
            if ((*(float *)(param_1 + 0x390) <
                 ABS((float)local_290 * _DAT_0059f094 - (float)local_294)) ||
               (((float)local_290 * _DAT_0059f094 < DAT_0059e440 ||
                ((float)local_294 < DAT_0059e440)))) {
              *(undefined1 *)(param_1 + 0x14) = 1;
              fVar4 = *(float *)(param_1 + 0x390) + _DAT_0059e87c;
              *(undefined4 *)(param_1 + 0x10) = 0x3f800000;
              *(float *)(param_1 + 0x390) = fVar4;
            }
            else {
              fVar4 = *(float *)(param_1 + 0x390) * _DAT_0059e448;
              fVar5 = _DAT_0059f108;
              if ((_DAT_0059f108 <= fVar4) && (fVar5 = fVar4, _DAT_0059e444 < fVar4)) {
                fVar5 = _DAT_0059e444;
              }
              fVar5 = *(float *)(param_1 + 0x390) - fVar5;
              *(float *)(param_1 + 0x390) = fVar5;
              if (fVar5 < DAT_0059f0b8) {
                *(float *)(param_1 + 0x390) = DAT_0059f0b8;
              }
            }
          }
          iVar19 = iVar19 + 1;
          pcVar18 = pcVar18 + 0x8c;
        } while (iVar19 < *(int *)(param_1 + 0x3e14));
        return 1;
      }
    }
  }
  else {
switchD_0045d8d8_caseD_7:
LAB_0045e47d:
    local_295 = 0;
    if (*(char *)(param_1 + 0x20) == '\0') {
      if ((*param_2 & 0x8000000) != 0) {
        bVar6 = true;
      }
      if (((*(byte *)((int)param_2 + 3) & 7) == DAT_007c56a4) || (bVar6)) {
        if (DAT_007d2e50 < 0x3ff) {
          DAT_007d2e50 = DAT_007d2e50 + 1;
          DAT_0083ee54 = DAT_0083ee54 + 0x1b0;
        }
        FUN_004b3a90(param_2);
        local_295 = 1;
      }
    }
  }
  return local_295;
}


