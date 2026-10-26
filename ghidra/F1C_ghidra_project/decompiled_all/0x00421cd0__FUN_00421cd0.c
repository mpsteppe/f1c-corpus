// Function: FUN_00421cd0 @ 00421cd0
// Strings:  [Config.ini, Config.ini, Config.ini, VERSION, [VERSION], IPADDRESS, VCRFILE, VCRCYCLE]


/* WARNING: Removing unreachable block (ram,0x00422605) */
/* WARNING: Removing unreachable block (ram,0x00422619) */

uint FUN_00421cd0(void)

{
  char cVar1;
  BOOL BVar2;
  undefined4 uVar3;
  undefined3 uVar4;
  undefined3 extraout_var;
  int extraout_ECX;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  bool bVar11;
  float10 fVar12;
  char cStack00000007;
  
  FUN_005881c0();
  puVar9 = (undefined4 *)&stack0x000003a4;
  for (iVar5 = 0x60; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  cStack00000007 = '\0';
  FUN_004230c0();
  iVar5 = 0xb;
  bVar11 = true;
  pcVar7 = &stack0x0000000c;
  pcVar10 = s_Windows_XP_005c2d9c;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar11 = *pcVar7 == *pcVar10;
    pcVar7 = pcVar7 + 1;
    pcVar10 = pcVar10 + 1;
  } while (bVar11);
  if (bVar11) {
LAB_00421d66:
    cVar1 = FUN_00423250();
    if (cVar1 == '\0') {
      cStack00000007 = '\x01';
      BVar2 = SHGetSpecialFolderPathA((HWND)0x0,&stack0x0000000c,5,1);
      if (-1 < BVar2) {
        FUN_0058815f();
        iVar5 = FUN_0058ba75();
        if (iVar5 == -1) {
          uVar6 = 0xffffffff;
          uVar8 = 0;
          pcVar7 = &stack0x0000010c;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          if (0 < (int)(~uVar6 - 1)) {
            do {
              if (0x3ff < uVar8) break;
              if ((&stack0x0000010c)[uVar8] == '\\') {
                _strncpy(&stack0x00000524,&stack0x0000010c,uVar8);
                (&stack0x00000524)[uVar8] = 0;
                FUN_00589671();
              }
              uVar8 = uVar8 + 1;
            } while ((int)uVar8 < (int)(~uVar6 - 1));
          }
          FUN_00589671();
          FUN_00566650();
          FUN_0058815f();
          FUN_00566650();
          CopyFileA(s_Config_ini_005c2aa0,&stack0x0000010c,1);
        }
        else {
          FUN_00566650();
          FUN_0058815f();
          FUN_00566650();
        }
      }
    }
  }
  else {
    iVar5 = 0xb;
    bVar11 = true;
    pcVar7 = &stack0x0000000c;
    pcVar10 = s_Windows_NT_005c2d90;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar7 == *pcVar10;
      pcVar7 = pcVar7 + 1;
      pcVar10 = pcVar10 + 1;
    } while (bVar11);
    if (bVar11) goto LAB_00421d66;
    iVar5 = 0xd;
    bVar11 = true;
    pcVar7 = &stack0x0000000c;
    pcVar10 = s_Windows_2000_005c2d80;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar7 == *pcVar10;
      pcVar7 = pcVar7 + 1;
      pcVar10 = pcVar10 + 1;
    } while (bVar11);
    if (bVar11) goto LAB_00421d66;
  }
  iVar5 = FUN_00587db0();
  if (iVar5 == 0) {
    cVar1 = FUN_00422be0();
    if (cVar1 == '\0') {
      uVar6 = FUN_004d7a50();
      if ((char)uVar6 != '\0') {
        uVar6 = FUN_004d7aa0();
        return uVar6 & 0xffffff00;
      }
    }
    else {
      iVar5 = FUN_00587db0();
      if (iVar5 != 0) goto LAB_00421fa6;
      uVar6 = FUN_004d7a50();
      if ((char)uVar6 != '\0') {
        uVar6 = FUN_004d7aa0();
      }
    }
    return uVar6 & 0xffffff00;
  }
LAB_00421fa6:
  iVar5 = FUN_00587ca0();
  do {
    if (iVar5 == 0) {
      uVar3 = FUN_00587d02();
      uVar4 = (undefined3)((uint)uVar3 >> 8);
      if (cStack00000007 != '\0') {
        FUN_00422be0();
        uVar4 = extraout_var;
      }
      return CONCAT31(uVar4,1);
    }
    iVar5 = FUN_005651b0();
    if (iVar5 == 0) {
      iVar5 = FUN_00587c20();
      if (iVar5 == 0) {
        iVar5 = FUN_00587c20();
        if (iVar5 == 0) {
          iVar5 = FUN_00587c20();
          if (iVar5 == 0) {
            iVar5 = FUN_00587c20();
            if (iVar5 != 0) {
              iVar5 = FUN_00587ca0();
              while (iVar5 != 0) {
                iVar5 = FUN_005651b0();
                if (iVar5 == 0) {
                  iVar5 = FUN_00565520();
                  if (iVar5 != 0) {
                    fVar12 = (float10)FUN_0058850f();
                    *(float *)(extraout_ECX + 0xe8) = (float)fVar12;
                  }
                }
                else if (iVar5 == 1) break;
                iVar5 = FUN_00587ca0();
              }
            }
          }
          else {
            iVar5 = FUN_00587ca0();
            while (iVar5 != 0) {
              iVar5 = FUN_005651b0();
              if (iVar5 == 0) {
                iVar5 = FUN_005654a0();
                if (iVar5 == 0) {
                  iVar5 = FUN_00565760();
                  if (iVar5 == 0) {
                    iVar5 = FUN_00565760();
                    if (iVar5 == 0) {
                      iVar5 = FUN_005654a0();
                      if (iVar5 == 0) {
                        iVar5 = FUN_005654a0();
                        if (iVar5 != 0) {
                          FUN_00404ef0();
                        }
                      }
                      else {
                        FUN_00404e60();
                      }
                    }
                    else {
                      FUN_00404d50();
                    }
                  }
                  else {
                    FUN_00404d30();
                  }
                }
                else {
                  FUN_00404cc0();
                  FUN_00404d40();
                }
              }
              else if (iVar5 == 1) break;
              iVar5 = FUN_00587ca0();
            }
          }
        }
        else {
          iVar5 = FUN_00587ca0();
          while (iVar5 != 0) {
            iVar5 = FUN_005651b0();
            if (iVar5 == 0) {
              iVar5 = FUN_005654a0();
              if (iVar5 == 0) {
                iVar5 = FUN_005654a0();
                if (iVar5 != 0) {
                  FUN_00421ad0();
                }
              }
              else {
                FUN_00421ab0();
              }
            }
            else if (iVar5 == 1) break;
            iVar5 = FUN_00587ca0();
          }
        }
      }
      else {
        iVar5 = FUN_00587ca0();
        while (iVar5 != 0) {
          iVar5 = FUN_005651b0();
          if (iVar5 == 0) {
            iVar5 = FUN_005654a0();
            if (iVar5 == 0) {
              iVar5 = FUN_005654a0();
              if (iVar5 == 0) {
                iVar5 = FUN_005654a0();
                if (iVar5 == 0) {
                  iVar5 = FUN_005654a0();
                  if (iVar5 == 0) {
                    iVar5 = FUN_005654a0();
                    if (iVar5 == 0) {
                      iVar5 = FUN_005654a0();
                      if (iVar5 == 0) {
                        iVar5 = FUN_005654a0();
                        if (iVar5 == 0) {
                          iVar5 = FUN_005654a0();
                          if (iVar5 == 0) {
                            iVar5 = FUN_005654a0();
                            if (iVar5 == 0) {
                              iVar5 = FUN_005654a0();
                              if (iVar5 == 0) {
                                iVar5 = FUN_005654a0();
                                if (iVar5 == 0) {
                                  iVar5 = FUN_005654a0();
                                  if (iVar5 == 0) {
                                    iVar5 = FUN_005654a0();
                                    if (iVar5 == 0) {
                                      iVar5 = FUN_005654a0();
                                      if (iVar5 == 0) {
                                        iVar5 = FUN_005654a0();
                                        if (iVar5 == 0) {
                                          iVar5 = FUN_005654a0();
                                          if (iVar5 == 0) {
                                            iVar5 = FUN_00565760();
                                            if (iVar5 == 0) {
                                              iVar5 = FUN_00565760();
                                              if (iVar5 == 0) {
                                                iVar5 = FUN_00565760();
                                                if (iVar5 == 0) {
                                                  iVar5 = FUN_00565760();
                                                  if (iVar5 == 0) {
                                                    iVar5 = FUN_00565760();
                                                    if (iVar5 == 0) {
                                                      iVar5 = FUN_00565760();
                                                      if (iVar5 == 0) {
                                                        iVar5 = FUN_00565520();
                                                        if (iVar5 == 0) {
                                                          iVar5 = FUN_00565760();
                                                          if (iVar5 == 0) {
                                                            iVar5 = FUN_00565760();
                                                            if (iVar5 == 0) {
                                                              iVar5 = FUN_00565760();
                                                              if (iVar5 == 0) {
                                                                iVar5 = FUN_00565760();
                                                                if (iVar5 == 0) {
                                                                  iVar5 = FUN_00565760();
                                                                  if (iVar5 == 0) {
                                                                    iVar5 = FUN_00565760();
                                                                    if (iVar5 == 0) {
                                                                      iVar5 = FUN_00565760();
                                                                      if (iVar5 == 0) {
                                                                        iVar5 = FUN_00565760();
                                                                        if (iVar5 != 0) {
                                                                          *(undefined4 *)
                                                                           (extraout_ECX + 0xe4) = 0
                                                                          ;
                                                                        }
                                                                      }
                                                                      else {
                                                                        *(undefined1 *)
                                                                         (extraout_ECX + 0xd6) = 0;
                                                                      }
                                                                    }
                                                                    else {
                                                                      *(undefined4 *)
                                                                       (extraout_ECX + 0xe0) = 0;
                                                                    }
                                                                  }
                                                                  else {
                                                                    *(undefined1 *)
                                                                     (extraout_ECX + 0xd5) = 0;
                                                                  }
                                                                }
                                                                else {
                                                                  *(undefined1 *)
                                                                   (extraout_ECX + 0xd4) = 0;
                                                                }
                                                              }
                                                              else {
                                                                *(undefined4 *)(extraout_ECX + 0xc0)
                                                                     = 0;
                                                              }
                                                            }
                                                            else {
                                                              *(undefined4 *)(extraout_ECX + 0xbc) =
                                                                   0;
                                                            }
                                                          }
                                                          else {
                                                            *(undefined4 *)(extraout_ECX + 0xb8) = 0
                                                            ;
                                                          }
                                                        }
                                                        else {
                                                          FUN_00566650();
                                                        }
                                                      }
                                                      else {
                                                        *(undefined4 *)(extraout_ECX + 0xdc) = 0;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(extraout_ECX + 0xd8) = 0;
                                                    }
                                                  }
                                                  else {
                                                    *(undefined4 *)(extraout_ECX + 0xd0) = 0;
                                                  }
                                                }
                                                else {
                                                  *(undefined4 *)(extraout_ECX + 0xcc) = 0;
                                                }
                                              }
                                              else {
                                                *(undefined4 *)(extraout_ECX + 200) = 0;
                                              }
                                            }
                                            else {
                                              *(undefined4 *)(extraout_ECX + 0xc4) = 0;
                                            }
                                          }
                                          else {
                                            FUN_00421af0();
                                          }
                                        }
                                        else {
                                          if (cStack00000007 != '\0') {
                                            FUN_0058815f();
                                            iVar5 = FUN_0058ba75();
                                            if (iVar5 == -1) {
                                              uVar6 = 0xffffffff;
                                              uVar8 = 0;
                                              pcVar7 = &stack0x0000010c;
                                              do {
                                                if (uVar6 == 0) break;
                                                uVar6 = uVar6 - 1;
                                                cVar1 = *pcVar7;
                                                pcVar7 = pcVar7 + 1;
                                              } while (cVar1 != '\0');
                                              if (0 < (int)(~uVar6 - 1)) {
                                                do {
                                                  if (0x3ff < uVar8) break;
                                                  if ((&stack0x0000010c)[uVar8] == '\\') {
                                                    _strncpy(&stack0x00000d24,&stack0x0000010c,uVar8
                                                            );
                                                    (&stack0x00000d24)[uVar8] = 0;
                                                    FUN_00589671();
                                                  }
                                                  uVar8 = uVar8 + 1;
                                                } while ((int)uVar8 < (int)(~uVar6 - 1));
                                              }
                                              FUN_00589671();
                                              FUN_00421b10();
                                              FUN_0058815f();
                                            }
                                          }
                                          FUN_00421a70();
                                        }
                                      }
                                      else {
                                        if (cStack00000007 != '\0') {
                                          FUN_0058815f();
                                          iVar5 = FUN_0058ba75();
                                          if (iVar5 == -1) {
                                            uVar6 = 0xffffffff;
                                            uVar8 = 0;
                                            pcVar7 = &stack0x0000010c;
                                            do {
                                              if (uVar6 == 0) break;
                                              uVar6 = uVar6 - 1;
                                              cVar1 = *pcVar7;
                                              pcVar7 = pcVar7 + 1;
                                            } while (cVar1 != '\0');
                                            if (0 < (int)(~uVar6 - 1)) {
                                              do {
                                                if (0x3ff < uVar8) break;
                                                if ((&stack0x0000010c)[uVar8] == '\\') {
                                                  _strncpy(&stack0x00000924,&stack0x0000010c,uVar8);
                                                  (&stack0x00000924)[uVar8] = 0;
                                                  FUN_00589671();
                                                }
                                                uVar8 = uVar8 + 1;
                                              } while ((int)uVar8 < (int)(~uVar6 - 1));
                                            }
                                            FUN_00589671();
                                            FUN_00421b10();
                                            FUN_0058815f();
                                          }
                                        }
                                        FUN_00421a50();
                                      }
                                    }
                                    else {
                                      if (cStack00000007 != '\0') {
                                        FUN_0058815f();
                                        iVar5 = FUN_0058ba75();
                                        if (iVar5 == -1) {
                                          uVar6 = 0xffffffff;
                                          uVar8 = 0;
                                          pcVar7 = &stack0x0000010c;
                                          do {
                                            if (uVar6 == 0) break;
                                            uVar6 = uVar6 - 1;
                                            cVar1 = *pcVar7;
                                            pcVar7 = pcVar7 + 1;
                                          } while (cVar1 != '\0');
                                          if (0 < (int)(~uVar6 - 1)) {
                                            do {
                                              if (0x3ff < uVar8) break;
                                              if ((&stack0x0000010c)[uVar8] == '\\') {
                                                _strncpy(&stack0x00000524,&stack0x0000010c,uVar8);
                                                (&stack0x00000524)[uVar8] = 0;
                                                FUN_00589671();
                                              }
                                              uVar8 = uVar8 + 1;
                                            } while ((int)uVar8 < (int)(~uVar6 - 1));
                                          }
                                          FUN_00589671();
                                          FUN_00421b10();
                                          FUN_0058815f();
                                        }
                                      }
                                      FUN_004219b0();
                                    }
                                  }
                                  else {
                                    FUN_00421a90();
                                  }
                                }
                                else {
                                  FUN_00421a30();
                                }
                              }
                              else {
                                FUN_00421a10();
                              }
                            }
                            else {
                              FUN_004219f0();
                            }
                          }
                          else {
                            FUN_004219d0();
                          }
                        }
                        else {
                          FUN_00421990();
                        }
                      }
                      else {
                        FUN_00421970();
                      }
                    }
                    else {
                      FUN_00421950();
                    }
                  }
                  else {
                    FUN_00421930();
                  }
                }
                else {
                  FUN_00421910();
                }
              }
              else {
                FUN_004218f0();
              }
            }
            else {
              FUN_004218d0();
            }
          }
          else if (iVar5 == 1) break;
          iVar5 = FUN_00587ca0();
        }
      }
    }
    iVar5 = FUN_00587ca0();
  } while( true );
}


