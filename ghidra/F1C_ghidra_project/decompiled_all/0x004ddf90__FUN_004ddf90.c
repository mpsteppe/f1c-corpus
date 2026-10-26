// Function: FUN_004ddf90 @ 004ddf90
// Strings:  [NOTSPIN, TEAMDIR, < does not have matching > in %s, Could not open %s, Could not open %s, DASHHIGH, DASHLOW, VEHDIR]


void __fastcall FUN_004ddf90(undefined4 param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 *puVar11;
  int iVar12;
  int local_630;
  int local_62c;
  undefined4 local_61c;
  char local_618 [640];
  undefined4 local_398;
  undefined1 local_394;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  char local_380 [384];
  undefined1 local_200 [512];
  
  pcVar10 = local_380;
  for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar10[0] = '\0';
    pcVar10[1] = '\0';
    pcVar10[2] = '\0';
    pcVar10[3] = '\0';
    pcVar10 = pcVar10 + 4;
  }
  puVar8 = (undefined4 *)(param_2 * 0x424 + DAT_008ac394);
  local_398 = 0;
  local_384 = 0;
  local_38c = 0;
  local_388 = 0;
  local_394 = 1;
  puVar11 = (undefined1 *)puVar8[8];
  if (puVar11 == (undefined1 *)0x0) {
    puVar11 = &DAT_005ea438;
  }
  iVar6 = FUN_00534b00();
  if (iVar6 == 0) {
    if ((DAT_007c569c != 5) &&
       (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x24b), cVar1 != '\0')) {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_open__s_005c6810,puVar11);
      return;
    }
  }
  else {
    iVar6 = FUN_00587db0(param_1,&DAT_005c680c);
    if (iVar6 == 0) {
      if ((DAT_007c569c != 5) &&
         (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x255), cVar1 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_open__s_005c6810,param_1);
      }
      FUN_005355a0();
      return;
    }
    if (param_4 == 0) {
      if (((&DAT_005ef9a0)[param_3 * 0x1230] == 0) || ((&DAT_005ef9a0)[param_3 * 0x1230] == 3)) {
        local_62c = 1;
        uVar3 = DAT_007cf7f4;
      }
      else {
        local_62c = 0;
        uVar3 = DAT_007cf818;
      }
      switch(uVar3) {
      case 0:
        local_630 = 1;
        break;
      case 1:
        local_630 = 2;
        break;
      case 2:
        local_630 = 3;
        break;
      case 3:
        local_630 = 4;
      }
    }
    else {
      iVar2 = FUN_00534b00();
      if (iVar2 != 0) {
        iVar2 = FUN_005351d0(0x180);
        while (iVar2 != 0) {
          iVar2 = FUN_005651b0();
          if (iVar2 != 3) {
            FUN_005887b1(iVar6,&DAT_005c4064,local_380);
          }
          iVar2 = FUN_005351d0(0x180);
        }
        FUN_005355a0();
      }
      local_630 = 0;
      local_62c = 0;
    }
    iVar2 = FUN_005351d0(0x180);
    while (iVar2 != 0) {
      iVar2 = FUN_005651b0();
      if (iVar2 != 3) {
        while (iVar2 = FUN_00587c20(local_380,&DAT_005c6808), iVar2 != 0) {
          iVar12 = 0;
          if (0 < iVar2 - (int)local_380) {
            do {
              FUN_00589898((int)local_380[iVar12],iVar6);
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar2 - (int)local_380);
          }
          pcVar10 = (char *)(iVar2 + 1);
          puVar4 = (undefined1 *)FUN_00587c20(local_380,&DAT_005c6804);
          local_61c = puVar4;
          if (((puVar4 == (undefined1 *)0x0) && (DAT_007c569c != 5)) &&
             (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x2b2),
             cVar1 != '\0')) {
            FUN_004d7aa0(&DAT_008ad25c,s_<_does_not_have_matching_>_in__s_005c67e0,puVar11);
          }
          *puVar4 = 0;
          iVar2 = FUN_00588410(pcVar10,&DAT_005c67dc);
          if (iVar2 == 0) {
            FUN_005887b1(iVar6,&DAT_005c67d4,param_3);
          }
          else {
            iVar2 = FUN_00588410(pcVar10,s_VEHDIR_005d4cd8);
            if (iVar2 == 0) {
              puVar4 = DAT_005ec428;
              if (DAT_005ec428 == (undefined1 *)0x0) {
                puVar4 = &DAT_005ea438;
              }
              puVar5 = DAT_005ec3d8;
              if (DAT_005ec3d8 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              FUN_0058815f(local_200,&DAT_005be860,puVar5,puVar4);
              FUN_005887b1(iVar6,&DAT_005c2c18,local_200);
            }
            else {
              iVar2 = FUN_00588410(pcVar10,s_TEAMDIR_005c67cc);
              if (iVar2 == 0) {
                pcVar10 = (char *)*puVar8;
                if (pcVar10 == (char *)0x0) {
                  pcVar10 = &DAT_005ea438;
                }
                pcVar9 = local_618;
                do {
                  cVar1 = *pcVar10;
                  pcVar10 = pcVar10 + 1;
                  *pcVar9 = cVar1;
                  pcVar9 = pcVar9 + 1;
                } while (cVar1 != '\0');
                uVar7 = 0xffffffff;
                pcVar10 = local_618;
                do {
                  if (uVar7 == 0) break;
                  uVar7 = uVar7 - 1;
                  cVar1 = *pcVar10;
                  pcVar10 = pcVar10 + 1;
                } while (cVar1 != '\0');
                if ((0 < (int)(~uVar7 - 1)) &&
                   (pcVar10 = local_618 + (~uVar7 - 2), local_618 <= pcVar10)) {
                  do {
                    if (*pcVar10 == '\\') break;
                    *pcVar10 = '\0';
                    pcVar10 = pcVar10 + -1;
                  } while (local_618 <= pcVar10);
                }
                FUN_005887b1(iVar6,&DAT_005c2c18,local_618);
              }
              else {
                iVar2 = FUN_00588410(pcVar10,s_NOTSPIN_005c67c4);
                if (iVar2 == 0) {
                  if (local_630 == 0) {
                    FUN_005887b1(iVar6,&DAT_005c30b8);
                  }
                }
                else {
                  iVar12 = FUN_00588410(pcVar10,&DAT_005c67bc);
                  iVar2 = local_630;
                  if (iVar12 == 0) goto LAB_004de3ca;
                  iVar2 = FUN_00588410(pcVar10,&PTR_LAB_005c67b8);
                  if (iVar2 == 0) {
                    if (local_630 != 1) {
                      FUN_005887b1(iVar6,&DAT_005c30b8);
                    }
                  }
                  else {
                    iVar2 = FUN_00588410(pcVar10,&DAT_005c67b4);
                    if (iVar2 == 0) {
                      if (local_630 != 2) {
                        FUN_005887b1(iVar6,&DAT_005c30b8);
                      }
                    }
                    else {
                      iVar2 = FUN_00588410(pcVar10,&DAT_005c67ac);
                      if (iVar2 == 0) {
                        if (local_630 != 3) {
                          FUN_005887b1(iVar6,&DAT_005c30b8);
                        }
                      }
                      else {
                        iVar2 = FUN_00588410(pcVar10,&DAT_005c67a8);
                        if (iVar2 == 0) {
                          if (local_630 != 4) {
                            FUN_005887b1(iVar6,&DAT_005c30b8);
                          }
                        }
                        else {
                          iVar12 = FUN_00588410(pcVar10,s_DASHLOW_005d4cd0);
                          iVar2 = local_62c;
                          if (iVar12 != 0) {
                            iVar2 = FUN_00588410(pcVar10,s_DASHHIGH_005d4cc4);
                            if (iVar2 != 0) {
                              uVar7 = 0xffffffff;
                              pcVar9 = pcVar10;
                              do {
                                if (uVar7 == 0) break;
                                uVar7 = uVar7 - 1;
                                cVar1 = *pcVar9;
                                pcVar9 = pcVar9 + 1;
                              } while (cVar1 != '\0');
                              iVar2 = 0;
                              if (0 < (int)(~uVar7 - 1)) {
                                do {
                                  FUN_00589898((int)*(char *)(pcVar10[iVar2] + -9 + (int)puVar8),
                                               iVar6);
                                  iVar2 = iVar2 + 1;
                                } while (iVar2 < (int)(~uVar7 - 1));
                              }
                              goto LAB_004de503;
                            }
                            iVar2 = local_62c + -1;
                          }
LAB_004de3ca:
                          if (iVar2 != 0) {
                            FUN_005887b1(iVar6,&DAT_005c30b8);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_004de503:
          pcVar10 = local_61c + 1;
          iVar2 = -(int)pcVar10;
          do {
            cVar1 = *pcVar10;
            pcVar10[(int)(local_380 + iVar2)] = cVar1;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
        }
        FUN_005887b1(iVar6,&DAT_005c4064,local_380);
      }
      iVar2 = FUN_005351d0(0x180);
    }
    FUN_005887b1(iVar6,&DAT_005c30b4);
    FUN_00587d02(iVar6);
    FUN_005355a0();
  }
  return;
}


