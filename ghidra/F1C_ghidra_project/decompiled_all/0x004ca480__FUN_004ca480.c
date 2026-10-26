// Function: FUN_004ca480 @ 004ca480
// Strings:  [COLOR, DESTBLEND, ALPHAFADE, SINGLESIDED, DEFORMABLE, BILLBOARDS, STAMPS, MTSFILE]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ca480(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  uint *puVar4;
  char cVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  bool bVar12;
  char local_100 [256];
  
  local_100[0] = '\0';
  FUN_004ca430();
  iVar6 = FUN_00565520(s_REACTION_005d36d8,local_100,0);
  if (iVar6 != 0) {
    iVar6 = 5;
    bVar12 = true;
    pcVar11 = local_100;
    pcVar9 = &DAT_005d36d0;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar12 = *pcVar11 == *pcVar9;
      pcVar11 = pcVar11 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar12);
    if (bVar12) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else {
      iVar6 = 0xb;
      bVar12 = true;
      pcVar11 = local_100;
      pcVar9 = s_WHITESMOKE_005d36c4;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar12 = *pcVar11 == *pcVar9;
        pcVar11 = pcVar11 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar12);
      if (bVar12) {
        *(undefined4 *)(param_1 + 4) = 1;
      }
      else {
        iVar6 = 10;
        bVar12 = true;
        pcVar11 = local_100;
        pcVar9 = s_BLUESMOKE_005d36b8;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar12 = *pcVar11 == *pcVar9;
          pcVar11 = pcVar11 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar12);
        if (bVar12) {
          *(undefined4 *)(param_1 + 4) = 2;
        }
        else {
          iVar6 = 0xb;
          bVar12 = true;
          pcVar11 = local_100;
          pcVar9 = s_BLACKSMOKE_005d36ac;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar11 == *pcVar9;
            pcVar11 = pcVar11 + 1;
            pcVar9 = pcVar9 + 1;
          } while (bVar12);
          if (bVar12) {
            *(undefined4 *)(param_1 + 4) = 3;
          }
          else {
            iVar6 = 7;
            bVar12 = true;
            pcVar11 = local_100;
            pcVar9 = s_FLAMES_005d36a4;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar12 = *pcVar11 == *pcVar9;
              pcVar11 = pcVar11 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar12);
            if (bVar12) {
              *(undefined4 *)(param_1 + 4) = 4;
            }
            else {
              iVar6 = 5;
              bVar12 = true;
              pcVar11 = local_100;
              pcVar9 = &DAT_005d369c;
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar12 = *pcVar11 == *pcVar9;
                pcVar11 = pcVar11 + 1;
                pcVar9 = pcVar9 + 1;
              } while (bVar12);
              if (bVar12) {
                *(undefined4 *)(param_1 + 4) = 6;
              }
              else {
                iVar6 = 9;
                bVar12 = true;
                pcVar11 = local_100;
                pcVar9 = s_SOFTSKID_005d3690;
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar12 = *pcVar11 == *pcVar9;
                  pcVar11 = pcVar11 + 1;
                  pcVar9 = pcVar9 + 1;
                } while (bVar12);
                if (bVar12) {
                  *(undefined4 *)(param_1 + 4) = 7;
                }
                else {
                  iVar6 = 6;
                  bVar12 = true;
                  pcVar11 = local_100;
                  pcVar9 = s_SPRAY_005d3688;
                  do {
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    bVar12 = *pcVar11 == *pcVar9;
                    pcVar11 = pcVar11 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar12);
                  if (bVar12) {
                    *(undefined4 *)(param_1 + 4) = 5;
                  }
                  else {
                    iVar6 = 8;
                    bVar12 = true;
                    pcVar11 = local_100;
                    pcVar9 = s_WETSKID_005d3680;
                    do {
                      if (iVar6 == 0) break;
                      iVar6 = iVar6 + -1;
                      bVar12 = *pcVar11 == *pcVar9;
                      pcVar11 = pcVar11 + 1;
                      pcVar9 = pcVar9 + 1;
                    } while (bVar12);
                    if (bVar12) {
                      *(undefined4 *)(param_1 + 4) = 8;
                    }
                    else {
                      iVar6 = 7;
                      bVar12 = true;
                      pcVar11 = local_100;
                      pcVar9 = s_GROOVE_005d3678;
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        bVar12 = *pcVar11 == *pcVar9;
                        pcVar11 = pcVar11 + 1;
                        pcVar9 = pcVar9 + 1;
                      } while (bVar12);
                      if (bVar12) {
                        *(undefined4 *)(param_1 + 4) = 9;
                      }
                      else {
                        iVar6 = 10;
                        bVar12 = true;
                        pcVar11 = local_100;
                        pcVar9 = s_WETGROOVE_005d366c;
                        do {
                          if (iVar6 == 0) break;
                          iVar6 = iVar6 + -1;
                          bVar12 = *pcVar11 == *pcVar9;
                          pcVar11 = pcVar11 + 1;
                          pcVar9 = pcVar9 + 1;
                        } while (bVar12);
                        if (bVar12) {
                          *(undefined4 *)(param_1 + 4) = 10;
                        }
                        else {
                          iVar6 = 9;
                          bVar12 = true;
                          pcVar11 = local_100;
                          pcVar9 = s_PARTICLE_005d3660;
                          do {
                            if (iVar6 == 0) break;
                            iVar6 = iVar6 + -1;
                            bVar12 = *pcVar11 == *pcVar9;
                            pcVar11 = pcVar11 + 1;
                            pcVar9 = pcVar9 + 1;
                          } while (bVar12);
                          if (bVar12) {
                            *(undefined4 *)(param_1 + 4) = 0xb;
                          }
                          else {
                            iVar6 = 6;
                            bVar12 = true;
                            pcVar11 = local_100;
                            pcVar9 = s_SPARK_005d3658;
                            do {
                              if (iVar6 == 0) break;
                              iVar6 = iVar6 + -1;
                              bVar12 = *pcVar11 == *pcVar9;
                              pcVar11 = pcVar11 + 1;
                              pcVar9 = pcVar9 + 1;
                            } while (bVar12);
                            if (bVar12) {
                              *(undefined4 *)(param_1 + 4) = 0xc;
                            }
                            else {
                              iVar6 = 5;
                              bVar12 = true;
                              pcVar11 = local_100;
                              pcVar9 = &DAT_005d3650;
                              do {
                                if (iVar6 == 0) break;
                                iVar6 = iVar6 + -1;
                                bVar12 = *pcVar11 == *pcVar9;
                                pcVar11 = pcVar11 + 1;
                                pcVar9 = pcVar9 + 1;
                              } while (bVar12);
                              if (bVar12) {
                                *(undefined4 *)(param_1 + 4) = 0xd;
                              }
                              else {
                                cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,
                                                     0x267);
                                if (cVar5 != '\0') {
                                  FUN_004d7aa0(&DAT_008ad25c,s_Unrecognized_reaction___s__005d3608,
                                               local_100);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  FUN_00565870(s_SCALE_005d3600,param_1 + 0xc,param_1 + 0x10,param_1 + 0x14,0,0,0,0,0);
  FUN_00565870(s_GROWTH_005d35f8,param_1 + 0x18,param_1 + 0x1c,param_1 + 0x20,0,0,0,0,0);
  FUN_00565870(s_GROWTHVEL_005d35ec,param_1 + 0x24,param_1 + 0x28,param_1 + 0x2c,0,0,0,0,0);
  FUN_00565870(s_DURATION_005d35e0,param_1 + 0x30,0,0,0,0,0,0,0);
  pfVar1 = (float *)(param_1 + 0x3c);
  pfVar2 = (float *)(param_1 + 0x38);
  pfVar3 = (float *)(param_1 + 0x34);
  iVar6 = FUN_00565870(s_ASDENVELOPE_005d35d4,pfVar3,pfVar2,pfVar1,0,0,0,0,0);
  if (iVar6 != 0) {
    if ((*(int *)(param_1 + 4) == 5) && (iVar6 = FUN_004f9230(), iVar6 < 0x18)) {
      *pfVar3 = *pfVar3 * _DAT_0059e8b4;
      *pfVar2 = *pfVar2 * _DAT_0059e8b4;
      *pfVar1 = *pfVar1 * _DAT_0059e8b4;
    }
    *(float *)(param_1 + 0x30) = *pfVar3 + *pfVar2 + *pfVar1;
  }
  FUN_00565870(s_POWER_005d35cc,param_1 + 0x44,0,0,0,0,0,0,0);
  pfVar1 = (float *)(param_1 + 0x48);
  iVar6 = FUN_00565870(s_RAMPSPEED_005d35c0,pfVar1,0,0,0,0,0,0,0);
  if (iVar6 != 0) {
    if (_DAT_0059e43c <= *pfVar1) {
      if (_DAT_0059eae0 < *pfVar1) {
        *pfVar1 = 3.4028235e+38;
      }
    }
    else {
      *pfVar1 = 1.0;
    }
  }
  FUN_00565870(s_OFFSETVEL_005d35b4,param_1 + 0x4c,0,0,0,0,0,0,0);
  iVar6 = FUN_00565520(&DAT_005c67a8,local_100,0);
  if (iVar6 != 0) {
    iVar6 = 0xd;
    bVar12 = true;
    pcVar11 = local_100;
    pcVar9 = s_NUMWAYPOINTS_005d35a4;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar12 = *pcVar11 == *pcVar9;
      pcVar11 = pcVar11 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar12);
    uVar8 = DAT_005ea3f0;
    if (!bVar12) {
      uVar8 = FUN_00587ece(local_100);
    }
    *(undefined4 *)(param_1 + 0x58) = uVar8;
  }
  iVar6 = *(int *)(param_1 + 0x50);
  if (iVar6 != 0) {
    FUN_004b0170();
    FUN_00587bcf(iVar6);
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    pvVar7 = operator_new(0xb0);
    if (pvVar7 == (void *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = FUN_00557350();
    }
    *(undefined4 *)(param_1 + 0x50) = uVar8;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x70) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x38) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x50) + 0x90) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x58) = 0x4030;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x5c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x60) = 0x80ffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20) = 0x211;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 100) = 0x40002;
  iVar6 = FUN_00565520(&DAT_005d35a0,local_100,0);
  if (iVar6 != 0) {
    pcVar11 = local_100;
    pcVar9 = (char *)(*(int *)(param_1 + 0x50) + 0x70);
    do {
      cVar5 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar9 = cVar5;
      pcVar9 = pcVar9 + 1;
    } while (cVar5 != '\0');
    iVar6 = FUN_00587c20(*(int *)(param_1 + 0x50) + 0x70,&DAT_005beb48);
    if (iVar6 == 0) {
      iVar6 = -1;
      pcVar11 = (char *)(*(int *)(param_1 + 0x50) + 0x70);
      do {
        pcVar9 = pcVar11;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar11 + 1;
        cVar5 = *pcVar11;
        pcVar11 = pcVar9;
      } while (cVar5 != '\0');
      *(undefined4 *)(pcVar9 + -1) = DAT_005cc79c;
      pcVar9[3] = DAT_005cc7a0;
    }
  }
  iVar6 = FUN_00565520(&DAT_005d359c,local_100,0);
  if (iVar6 != 0) {
    pcVar11 = local_100;
    pcVar9 = (char *)(*(int *)(param_1 + 0x50) + 0x38);
    do {
      cVar5 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar9 = cVar5;
      pcVar9 = pcVar9 + 1;
    } while (cVar5 != '\0');
    iVar6 = FUN_00587c20(*(int *)(param_1 + 0x50) + 0x38,&DAT_005beb48);
    if (iVar6 == 0) {
      iVar6 = -1;
      pcVar11 = (char *)(*(int *)(param_1 + 0x50) + 0x38);
      do {
        pcVar9 = pcVar11;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar11 + 1;
        cVar5 = *pcVar11;
        pcVar11 = pcVar9;
      } while (cVar5 != '\0');
      *(undefined4 *)(pcVar9 + -1) = DAT_005cd5ec;
      pcVar9[3] = DAT_005cd5f0;
    }
  }
  iVar6 = FUN_00565520(&DAT_005d3594,local_100,0);
  if (iVar6 != 0) {
    pcVar11 = local_100;
    pcVar9 = (char *)(*(int *)(param_1 + 0x50) + 0x90);
    do {
      cVar5 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar9 = cVar5;
      pcVar9 = pcVar9 + 1;
    } while (cVar5 != '\0');
    iVar6 = FUN_00587c20(*(int *)(param_1 + 0x50) + 0x90,&DAT_005beb48);
    if (iVar6 == 0) {
      iVar6 = -1;
      pcVar11 = (char *)(*(int *)(param_1 + 0x50) + 0x90);
      do {
        pcVar9 = pcVar11;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar11 + 1;
        cVar5 = *pcVar11;
        pcVar11 = pcVar9;
      } while (cVar5 != '\0');
      *(undefined4 *)(pcVar9 + -1) = DAT_005cc79c;
      pcVar9[3] = DAT_005cc7a0;
    }
  }
  iVar6 = FUN_00565520(s_VERTEX_005d358c,local_100,0);
  if (iVar6 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x58) = 0;
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 4;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 8;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 0x10;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 0x20;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 0x40;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 0x80;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x58);
      *puVar4 = *puVar4 | 0x4000;
    }
  }
  iVar6 = FUN_00565520(s_PIXEL_005d3528,local_100,0);
  if (iVar6 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x5c) = 0;
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x5c);
      *puVar4 = *puVar4 | 1;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x5c);
      *puVar4 = *puVar4 | 0x80;
    }
  }
  iVar6 = FUN_00565520(s_CHROMA_005d3504,local_100,0);
  if (iVar6 != 0) {
    uVar8 = FUN_004cad30();
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x68) = uVar8;
  }
  iVar6 = FUN_00565520(s_COLOR_005c57f4,local_100,0);
  if (iVar6 != 0) {
    uVar8 = FUN_004cad30();
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x60) = uVar8;
  }
  iVar6 = FUN_00565520(s_PARTICLE_005d3660,local_100,0);
  if (iVar6 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20) = 0;
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 1;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 2;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 4;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 8;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 0x10;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 0x20;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 0x80;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 0x200;
    }
    iVar6 = FUN_00566810();
    if (iVar6 != 0) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 0x20);
      *puVar4 = *puVar4 | 0x800;
    }
  }
  iVar6 = FUN_00565520(s_DESTBLEND_005d34a4,local_100,0);
  if (iVar6 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x50) + 0x66) = 0;
    iVar6 = FUN_004cada0();
    *(uint *)(*(int *)(param_1 + 0x50) + 100) =
         *(uint *)(*(int *)(param_1 + 0x50) + 100) | iVar6 << 0x10;
  }
  iVar6 = FUN_00565520(s_ASRCBLEND_005d3496 + 2,local_100,0);
  if (iVar6 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x50) + 100) = 0;
    uVar10 = FUN_004cada0();
    puVar4 = (uint *)(*(int *)(param_1 + 0x50) + 100);
    *puVar4 = *puVar4 | uVar10;
  }
  return;
}


