// Function: FUN_00463160 @ 00463160
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp]


void __thiscall FUN_00463160(int *param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  char local_40 [63];
  undefined1 local_1;
  
  if ((DAT_007c569c != 5) &&
     (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b25), cVar2 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_NetComm_checking_command_line____005c64e4,param_2);
  }
  iVar3 = FUN_00566810();
  if (iVar3 != 0) {
    uVar9 = 0xffffffff;
    pcVar5 = s__password___005c64d8;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    _strncpy(local_40,(char *)((~uVar9 - 1) + iVar3),0xf);
    local_40[0xf] = 0;
    puVar4 = (undefined1 *)FUN_00587c20(local_40,&DAT_005c64d4);
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 0;
    }
    FUN_00463710(local_40);
    if ((DAT_007c569c != 5) &&
       (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b3a), cVar2 != '\0'))
    {
      FUN_004d7aa0(&DAT_008ad25c,s_Setting_Game_Password_to____s__005c64b4,local_40);
    }
  }
  iVar3 = FUN_00566810();
  if (iVar3 == 0) {
    iVar3 = FUN_00566810();
    if (iVar3 == 0) {
      iVar3 = FUN_00566810();
      if (iVar3 != 0) {
        uVar9 = 0xffffffff;
        pcVar5 = s__connect_005c644c;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        pcVar5 = (char *)(iVar3 + (~uVar9 - 1));
        cVar2 = *(char *)(iVar3 + (~uVar9 - 1));
        while (cVar2 == ' ') {
          pcVar6 = pcVar5 + 1;
          pcVar5 = pcVar5 + 1;
          cVar2 = *pcVar6;
        }
        iVar3 = *param_1;
        _strncpy((char *)(iVar3 + 200),pcVar5,0x4f);
        *(undefined1 *)(iVar3 + 0x117) = 0;
        puVar4 = (undefined1 *)(*param_1 + 200);
        cVar2 = *(char *)(*param_1 + 200);
        while (cVar2 != '\0') {
          if (cVar2 == ' ') {
            *puVar4 = 0;
            break;
          }
          pcVar5 = puVar4 + 1;
          puVar4 = puVar4 + 1;
          cVar2 = *pcVar5;
        }
        iVar3 = FUN_00587c20(*param_1 + 200,&DAT_005c3f6c);
        if (iVar3 == 0) {
          if ((DAT_007c569c != 5) &&
             (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b8e),
             cVar2 != '\0')) {
            FUN_004d7aa0(&DAT_008ad25c,s_No_port_specified_for_autojoin__w_005c638c);
          }
        }
        else {
          *(undefined1 *)(*param_1 + 0xc6) = 1;
          if ((DAT_007c569c != 5) &&
             (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b7b),
             cVar2 != '\0')) {
            FUN_004d7aa0(&DAT_008ad25c,s_NetComm_activated_autojoin_mode_005c642c);
          }
          iVar10 = FUN_00587ece(iVar3 + 1);
          if (iVar10 == 0) {
            local_40[0] = '\0';
            FUN_0058815f(local_40,&DAT_005c3280,DAT_007d1004);
            pcVar5 = local_40;
            do {
              cVar2 = *pcVar5;
              pcVar5[(iVar3 + 1) - (int)local_40] = cVar2;
              pcVar5 = pcVar5 + 1;
            } while (cVar2 != '\0');
            if (DAT_007c569c != 5) {
              cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b88);
              if (cVar2 != '\0') {
                FUN_004d7aa0(&DAT_008ad25c,s_____Autojoin_address_specified_p_005c63e8,DAT_007d1004)
                ;
              }
              if ((DAT_007c569c != 5) &&
                 (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b89),
                 cVar2 != '\0')) {
                FUN_004d7aa0(&DAT_008ad25c,s_____New_address_string_____s__005c63c8,*param_1 + 200);
              }
            }
          }
        }
      }
    }
    else {
      *(undefined1 *)(*param_1 + 0xc5) = 1;
      if ((DAT_007c569c != 5) &&
         (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b4d), cVar2 != '\0')
         ) {
        FUN_004d7aa0(&DAT_008ad25c,s_NetComm_activated_autohost_mode_005c6480);
      }
      iVar3 = FUN_00566810();
      if (iVar3 != 0) {
        uVar9 = 0xffffffff;
        pcVar5 = s__gamename___005c6474;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        local_40[0] = '\0';
        _strncpy(local_40,(char *)((~uVar9 - 1) + iVar3),0x3f);
        local_1 = 0;
        pcVar5 = (char *)FUN_005897ca(local_40,&DAT_005c64d4);
        if (pcVar5 != (char *)0x0) {
          iVar3 = -1;
          pcVar6 = pcVar5;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar2 != '\0');
          if (iVar3 != -2) {
            pcVar6 = (char *)(*param_1 + 0x16c);
            do {
              cVar2 = *pcVar5;
              pcVar5 = pcVar5 + 1;
              *pcVar6 = cVar2;
              pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
          }
        }
        if ((DAT_007c569c != 5) &&
           (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1b5f),
           cVar2 != '\0')) {
          FUN_004d7aa0(&DAT_008ad25c,s_Setting_Game_Name_to____s__005c6458,*param_1 + 0x16c);
        }
      }
    }
  }
  iVar3 = FUN_00566810();
  if (iVar3 != 0) {
    uVar9 = 0xffffffff;
    pcVar5 = &DAT_005c6384;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pcVar5 = (char *)(iVar3 + (~uVar9 - 1));
    local_40[0] = '\0';
    cVar2 = *pcVar5;
    while (cVar2 == ' ') {
      pcVar6 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar6;
    }
    if ((*pcVar5 == '\0') || (*pcVar5 != '\"')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
      pcVar5 = pcVar5 + 1;
    }
    cVar2 = *pcVar5;
    for (iVar3 = 0; (cVar2 != '\0' && (iVar3 < 0x1e)); iVar3 = iVar3 + 1) {
      if (bVar1) {
        bVar11 = cVar2 == '\"';
      }
      else {
        bVar11 = cVar2 == ' ';
      }
      if (bVar11) break;
      local_40[iVar3] = cVar2;
      cVar2 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    }
    iVar10 = -1;
    local_40[iVar3] = '\0';
    pcVar5 = local_40;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    if (iVar10 != -2) {
      pcVar5 = local_40;
      pcVar6 = (char *)(*param_1 + 0x11c);
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar2;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      if ((DAT_007c569c != 5) &&
         (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1bc2), cVar2 != '\0')
         ) {
        FUN_004d7aa0(&DAT_008ad25c,s_NetComm_set_network_name_to___s__005c6360,local_40);
      }
    }
  }
  iVar3 = FUN_00566810();
  if (iVar3 != 0) {
    uVar9 = 0xffffffff;
    pcVar5 = s__maxplayers_005c6350;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    iVar10 = iVar3 + (~uVar9 - 1);
    cVar2 = *(char *)(iVar3 + (~uVar9 - 1));
    while (cVar2 == ' ') {
      pcVar5 = (char *)(iVar10 + 1);
      iVar10 = iVar10 + 1;
      cVar2 = *pcVar5;
    }
    uVar7 = FUN_00587ece(iVar10);
    *(undefined4 *)(*param_1 + 0x1ac) = uVar7;
    iVar3 = *(int *)(*param_1 + 0x1ac);
    puVar8 = (undefined4 *)(*param_1 + 0x1ac);
    if (iVar3 < 2) {
      *puVar8 = 2;
      return;
    }
    if (0x68 < iVar3) {
      *puVar8 = 0x68;
    }
  }
  return;
}


