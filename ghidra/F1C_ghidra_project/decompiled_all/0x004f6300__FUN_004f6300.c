// Function: FUN_004f6300 @ 004f6300
// Strings:  [Custom, Gearing, Balance, Downforce, [BASIC], [REARRIGHT], [REARLEFT], [FRONTRIGHT]]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004f6300(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  float fVar1;
  double dVar2;
  float fVar3;
  bool bVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar15;
  int iStack00000028;
  int iStack00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000380;
  
  FUN_0042e1f0();
  FUN_0042e1f0();
  FUN_0042e1f0();
  FUN_0042e1f0();
  do {
    iVar9 = FUN_005351d0();
    if (iVar9 != 0) goto LAB_004f5e41;
    do {
      do {
        iVar9 = 0x2c;
        if (*(int *)(unaff_ESI + 0x13c4) + 0x2c < 0x2d) {
LAB_004f63d9:
          puVar12 = (undefined1 *)(iVar9 * 0x40 + 0xbcc + unaff_EBX);
          iVar9 = 0x33 - iVar9;
          do {
            *puVar12 = 0;
            puVar12 = puVar12 + 0x40;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        else {
          puVar12 = (undefined1 *)(unaff_EBX + 0x16cc);
          do {
            *puVar12 = 1;
            iVar9 = iVar9 + 1;
            puVar12 = puVar12 + 0x40;
          } while (iVar9 < *(int *)(unaff_ESI + 0x13c4) + 0x2c);
          if (iVar9 < 0x33) goto LAB_004f63d9;
        }
        iVar9 = *(int *)(unaff_ESI + 0x13c4);
        if (((1 < iVar9) && (1 < param_3)) && (iVar9 != param_3)) {
          iVar13 = 0;
          if (0 < param_3) {
            puVar14 = (undefined4 *)(unaff_EBX + 0x16c4);
            do {
              *(undefined4 *)(&stack0x00000380 + iVar13 * 4) = *puVar14;
              iVar13 = iVar13 + 1;
              puVar14 = puVar14 + 0x10;
            } while (iVar13 < param_3);
          }
          iStack00000028 = 0;
          if (0 < iVar9) {
            iStack00000030 = 0;
            piVar15 = (int *)(unaff_EBX + 0x16c4);
            do {
              fVar3 = (float)iStack00000030 / (float)(iVar9 + -1);
              iVar9 = in_stack_00000380;
              if (fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440)) {
                fVar1 = (float)(param_3 + -1);
                if (fVar1 < fVar3 == (fVar1 == fVar3)) {
                  __ftol();
                  iVar9 = __ftol();
                }
                else {
                  iVar9 = *(int *)(&stack0x0000037c + param_3 * 4);
                }
              }
              if ((-1 < iVar9) && (iVar9 < piVar15[-1])) {
                *piVar15 = iVar9;
              }
              iStack00000030 = iStack00000030 + param_3 + -1;
              iStack00000028 = iStack00000028 + 1;
              iVar9 = *(int *)(unaff_ESI + 0x13c4);
              piVar15 = piVar15 + 0x10;
            } while (iStack00000028 < iVar9);
          }
        }
LAB_004f66cd:
        while( true ) {
          do {
            iVar9 = FUN_005351d0();
            if (iVar9 == 0) {
              FUN_0042e530();
              FUN_005355a0();
              if (param_6 != 0) {
                FUN_00587bcf();
              }
              return 0;
            }
            iVar9 = FUN_005651b0();
          } while (iVar9 != 0);
          iVar9 = FUN_00587c20();
          if (iVar9 == 0) break;
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              iVar9 = FUN_00565760();
              if (iVar9 != 0) {
                *(undefined4 *)(unaff_ESI + 0x34) = in_stack_00000044;
                *(undefined4 *)(unaff_EBX + 0x1990) = in_stack_00000044;
              }
              iVar9 = FUN_00565760();
              if (iVar9 != 0) {
                *(undefined4 *)(unaff_EBX + 0x198c) = *(undefined4 *)(unaff_ESI + 0x38);
              }
              FUN_00565760();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              iVar9 = FUN_00565aa0();
              if (iVar9 != 0) {
                *(undefined8 *)(unaff_EBX + 0x199c) = *(undefined8 *)(unaff_ESI + 0x68);
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              iVar9 = FUN_005654a0();
              if (iVar9 != 0) {
                pcVar6 = (char *)(unaff_ESI + 0x88);
                uVar10 = 0xffffffff;
                pcVar11 = pcVar6;
                do {
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  cVar5 = *pcVar11;
                  pcVar11 = pcVar11 + 1;
                } while (cVar5 != '\0');
                for (pcVar11 = pcVar6 + (~uVar10 - 1); pcVar6 < pcVar11; pcVar11 = pcVar11 + -1) {
                  if (*pcVar11 == '.') {
                    *pcVar11 = '\0';
                    break;
                  }
                }
                FUN_0042ed50();
                iVar9 = FUN_004d7880();
                if (iVar9 == 0) {
                  if ((DAT_007c569c != 5) && (cVar5 = FUN_004d7a50(), cVar5 != '\0')) {
                    FUN_004d7aa0();
                  }
                }
                else {
                  *(undefined4 *)(unaff_EBX + 0xbc0) = *(undefined4 *)(iVar9 + 0x10);
                  FUN_00566650();
                  *(int *)(unaff_ESI + 8) = *(int *)(iVar9 + 0x20) + 0x20040229;
                }
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565760();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              iVar9 = FUN_005654a0();
              if (iVar9 != 0) {
                FUN_005665b0();
              }
              iVar9 = FUN_00565760();
              if (iVar9 != 0) {
                *(bool *)(unaff_EBX + 0x19a5) = in_stack_00000034 != 0;
              }
              iVar9 = FUN_005654a0();
              if (iVar9 != 0) {
                pcVar6 = *(char **)(unaff_EBP + 8);
                iVar9 = -(int)pcVar6;
                do {
                  cVar5 = *pcVar6;
                  pcVar6[(int)(&stack0x000003a0 + iVar9)] = cVar5;
                  pcVar6 = pcVar6 + 1;
                } while (cVar5 != '\0');
                uVar10 = 0xffffffff;
                pcVar6 = &stack0x000003a0;
                do {
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  cVar5 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar5 != '\0');
                if ((0 < (int)(~uVar10 - 1)) &&
                   (pcVar6 = &stack0x0000039e + ~uVar10, &stack0x000003a0 <= pcVar6)) {
                  do {
                    if (*pcVar6 == '\\') break;
                    *pcVar6 = '\0';
                    pcVar6 = pcVar6 + -1;
                  } while (&stack0x000003a0 <= pcVar6);
                }
                iVar9 = FUN_004c40d0();
                if (iVar9 == 0) {
                  if ((*(byte *)(unaff_EBP + 0x10) & 2) == 0) {
                    FUN_004f24f0();
                  }
                  FUN_00566650();
                }
              }
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              iVar9 = FUN_00565aa0();
              if (iVar9 != 0) {
                *(undefined1 *)(unaff_ESI + 0x1ec) = 1;
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3490();
              FUN_00565aa0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          FUN_004f3090();
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          FUN_004f3090();
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              iVar9 = FUN_00565aa0();
              if (iVar9 != 0) {
                *(undefined1 *)(unaff_ESI + 0x2f8) = 1;
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3490();
              FUN_00565aa0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3240();
              FUN_004f3490();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_0042e1f0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              iVar9 = FUN_00565aa0();
              if (iVar9 != 0) {
                *(undefined1 *)(unaff_ESI + 0x4d4) = 1;
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              iVar9 = FUN_005654a0();
              if (iVar9 != 0) {
                pcVar6 = *(char **)(unaff_EBP + 8);
                iVar9 = -(int)pcVar6;
                do {
                  cVar5 = *pcVar6;
                  pcVar6[(int)(&stack0x000003a0 + iVar9)] = cVar5;
                  pcVar6 = pcVar6 + 1;
                } while (cVar5 != '\0');
                uVar10 = 0xffffffff;
                pcVar6 = &stack0x000003a0;
                do {
                  if (uVar10 == 0) break;
                  uVar10 = uVar10 - 1;
                  cVar5 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar5 != '\0');
                if ((0 < (int)(~uVar10 - 1)) &&
                   (pcVar6 = &stack0x0000039e + ~uVar10, &stack0x000003a0 <= pcVar6)) {
                  do {
                    if (*pcVar6 == '\\') break;
                    *pcVar6 = '\0';
                    pcVar6 = pcVar6 + -1;
                  } while (&stack0x000003a0 <= pcVar6);
                }
                FUN_004c40d0();
              }
              iVar9 = FUN_005655f0();
              if (iVar9 != 0) {
                *(undefined1 *)(unaff_EBX + 0x1988) = *(undefined1 *)(unaff_ESI + 0x548);
              }
              FUN_005655f0();
              FUN_005655f0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              iVar9 = FUN_005655f0();
              if (iVar9 != 0) {
                *(undefined1 *)(unaff_EBX + 0x1989) = *(undefined1 *)(unaff_ESI + 0x56c);
              }
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_005655f0();
              FUN_00565aa0();
              FUN_00565aa0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
              FUN_0042e1f0();
            }
            iVar9 = FUN_005351d0();
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 != 0) {
          puVar14 = (undefined4 *)&stack0x00000361;
          for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          }
          *(undefined2 *)puVar14 = 0;
          *(undefined1 *)((int)puVar14 + 2) = 0;
          bVar4 = false;
          iVar9 = FUN_004c58a0();
          if ((iVar9 == 0) &&
             (((iVar9 = FUN_00588410(), iVar9 == 0 || (iVar9 = FUN_00588410(), iVar9 == 0)) ||
              (iVar9 = FUN_00587ece(), iVar9 == 1)))) {
            bVar4 = true;
          }
          iVar9 = FUN_005351d0();
          while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
            if (iVar9 == 0) {
              if (in_stack_00000040 == 0) {
                iVar9 = FUN_005654a0();
                iVar13 = FUN_005654a0();
                if (iVar13 != iVar9) {
                  pcVar6 = *(char **)(unaff_EBP + 8);
                  iVar7 = -(int)pcVar6;
                  do {
                    cVar5 = *pcVar6;
                    pcVar6[(int)(&stack0x000003a0 + iVar7)] = cVar5;
                    pcVar6 = pcVar6 + 1;
                  } while (cVar5 != '\0');
                  uVar10 = 0xffffffff;
                  pcVar6 = &stack0x000003a0;
                  do {
                    if (uVar10 == 0) break;
                    uVar10 = uVar10 - 1;
                    cVar5 = *pcVar6;
                    pcVar6 = pcVar6 + 1;
                  } while (cVar5 != '\0');
                  if ((0 < (int)(~uVar10 - 1)) &&
                     (pcVar6 = &stack0x0000039e + ~uVar10, &stack0x000003a0 <= pcVar6)) {
                    do {
                      if (*pcVar6 == '\\') break;
                      *pcVar6 = '\0';
                      pcVar6 = pcVar6 + -1;
                    } while (&stack0x000003a0 <= pcVar6);
                  }
                  iVar7 = FUN_004c40d0();
                  if (iVar7 == 0) {
                    if ((((iVar9 != 0) && (bVar4)) || ((iVar13 != 0 && (!bVar4)))) &&
                       ((*(byte *)(unaff_EBP + 0x10) & 2) == 0)) {
                      FUN_004f3c80();
                    }
                    FUN_00566650();
                  }
                }
              }
              FUN_004f3c10();
            }
            iVar9 = FUN_005351d0();
          }
          dVar2 = *(double *)(unaff_ESI + 0x67c) * *(double *)(unaff_ESI + 0x674) *
                  (double)_DAT_005ea40c * (double)DAT_007d0b64;
          if (dVar2 <= _DAT_0059e430) {
            *(undefined4 *)(unaff_EBX + 0x1994) = 0;
            *(undefined4 *)(unaff_EBX + 0x1998) = 0;
          }
          else {
            *(double *)(unaff_EBX + 0x1994) = _DAT_0059e420 / dVar2;
          }
          goto LAB_004f66cd;
        }
        iVar9 = FUN_00587c20();
        if (iVar9 == 0) {
          iVar9 = FUN_00587c20();
          if (iVar9 == 0) {
            iVar9 = FUN_00587c20();
            if (iVar9 == 0) {
              iVar9 = FUN_00587c20();
              if (iVar9 == 0) {
                iVar9 = FUN_00587c20();
                if (iVar9 == 0) {
                  iVar9 = FUN_00587c20();
                  if (iVar9 != 0) {
                    iVar9 = FUN_005351d0();
                    while ((iVar9 != 0 && (iVar9 = FUN_005651b0(), iVar9 != 1))) {
                      if (iVar9 == 0) {
                        FUN_004317f0();
                        FUN_004317f0();
                        FUN_004317f0();
                        FUN_004317f0();
                        iVar9 = FUN_00565760();
                        if (iVar9 != 0) {
                          *(bool *)(unaff_EBX + 0x19a4) = in_stack_00000038 != 0;
                        }
                      }
                      iVar9 = FUN_005351d0();
                    }
                  }
                }
                else {
                  FUN_004f2c60();
                }
              }
              else {
                FUN_004f2c60();
              }
            }
            else {
              FUN_004f2c60();
            }
          }
          else {
            FUN_004f2c60();
          }
          goto LAB_004f66cd;
        }
        param_3 = 0;
        iVar9 = FUN_005351d0();
      } while (iVar9 == 0);
LAB_004f5e41:
      iVar9 = FUN_005651b0();
    } while (iVar9 == 1);
  } while (iVar9 != 0);
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_005655f0();
  FUN_005655f0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  FUN_00565aa0();
  iVar9 = FUN_005654a0();
  if (iVar9 != 0) {
    iVar9 = FUN_00588410();
    if (iVar9 == 0) {
      *(undefined4 *)(unaff_ESI + 0x13c0) = 0;
    }
    else {
      iVar9 = FUN_00588410();
      if (iVar9 == 0) {
        *(undefined4 *)(unaff_ESI + 0x13c0) = 1;
      }
      else {
        iVar9 = FUN_00588410();
        if (iVar9 == 0) {
          *(undefined4 *)(unaff_ESI + 0x13c0) = 2;
        }
      }
    }
  }
  iVar9 = FUN_005654a0();
  if (iVar9 != 0) {
    pcVar6 = *(char **)(unaff_EBP + 8);
    iVar9 = -(int)pcVar6;
    do {
      cVar5 = *pcVar6;
      pcVar6[(int)(&stack0x000003a0 + iVar9)] = cVar5;
      pcVar6 = pcVar6 + 1;
    } while (cVar5 != '\0');
    uVar10 = 0xffffffff;
    pcVar6 = &stack0x000003a0;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar5 != '\0');
    if ((0 < (int)(~uVar10 - 1)) &&
       (pcVar6 = &stack0x0000039e + ~uVar10, &stack0x000003a0 <= pcVar6)) {
      do {
        if (*pcVar6 == '\\') break;
        *pcVar6 = '\0';
        pcVar6 = pcVar6 + -1;
      } while (&stack0x000003a0 <= pcVar6);
    }
    iVar9 = FUN_004c40d0();
    if (iVar9 == 0) {
      if ((*(byte *)(unaff_EBP + 0x10) & 2) == 0) {
        FUN_0042ecc0();
      }
      FUN_00566650();
    }
  }
  FUN_00565760();
  FUN_00565760();
  FUN_00565760();
  FUN_00565760();
  FUN_00565760();
  FUN_00565760();
  FUN_00565760();
  uVar8 = FUN_0059d822();
  return uVar8;
}


