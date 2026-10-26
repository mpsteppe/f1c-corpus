// Function: FUN_0057bf00 @ 0057bf00
// Strings:  [ (%s), TCPDeny, TCPDeny, TCPDeny, TCPDeny, TCPInfo, TCPInfo, TCPInfo]


undefined4 __thiscall FUN_0057bf00(int *param_1,char *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  char acVar3 [4];
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  int iVar11;
  u_long uVar12;
  byte *pbVar13;
  SOCKET len;
  DWORD DVar14;
  undefined4 uVar15;
  sockaddr *psVar16;
  char *pcVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  size_t _Count;
  byte *pbVar22;
  char *pcVar23;
  char *pcVar24;
  bool bVar25;
  SOCKET local_198;
  int *local_194;
  int local_190;
  char local_18c [4];
  sockaddr local_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  sockaddr local_16c;
  sockaddr local_15c;
  uint local_14c [2];
  undefined4 local_144;
  undefined1 uStack_13c;
  undefined4 local_130;
  char local_12c [80];
  char local_dc [80];
  char local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c9b9;
  local_c = ExceptionList;
  if ((DAT_008d3c10 & 1) == 0) {
    DAT_008d3c10 = DAT_008d3c10 | 1;
    uVar18 = 0xffffffff;
    pcVar17 = PTR_DAT_005e537c;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      cVar10 = *pcVar17;
      pcVar17 = pcVar17 + 1;
    } while (cVar10 != '\0');
    DAT_008d3c14 = ~uVar18 - 1;
  }
  if ((param_3 <= (int)DAT_008d3c14) ||
     (ExceptionList = &local_c, iVar11 = _strncmp(param_2,PTR_DAT_005e537c,DAT_008d3c14),
     iVar11 != 0)) {
    ExceptionList = local_c;
    return 0;
  }
  _Count = param_3 - DAT_008d3c14;
  if (0x4e < (int)_Count) {
    _Count = 0x4f;
  }
  local_12c[0] = '\0';
  local_4 = 0;
  _strncpy(local_12c,param_2 + DAT_008d3c14,_Count);
  uVar18 = 0xffffffff;
  local_12c[_Count] = '\0';
  pcVar17 = PTR_DAT_005e5384;
  do {
    if (uVar18 == 0) break;
    uVar18 = uVar18 - 1;
    cVar10 = *pcVar17;
    pcVar17 = pcVar17 + 1;
  } while (cVar10 != '\0');
  iVar11 = _strncmp(local_12c,PTR_DAT_005e5384,~uVar18 - 1);
  if (iVar11 == 0) {
    iVar11 = FUN_00585d20();
    if (iVar11 != 4) {
      ExceptionList = local_c;
      return 1;
    }
    local_16c.sa_family = 2;
    uVar12 = htonl(0);
    local_16c.sa_data[2] = (char)uVar12;
    local_16c.sa_data[3] = (char)(uVar12 >> 8);
    local_16c.sa_data[4] = (char)(uVar12 >> 0x10);
    local_16c.sa_data[5] = (char)(uVar12 >> 0x18);
    local_16c.sa_data._0_2_ = htons(0);
    local_190 = 0x10;
    iVar11 = getsockname(param_1[0x24e],&local_16c,&local_190);
    local_16c.sa_data._0_2_ = ntohs(local_16c.sa_data._0_2_);
    if (iVar11 != 0) {
      ExceptionList = local_c;
      return 1;
    }
    uVar18 = 0xffffffff;
    pbVar22 = (byte *)(param_1 + 0x246);
    pcVar17 = PTR_DAT_005e5384;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      cVar10 = *pcVar17;
      pcVar17 = pcVar17 + 1;
    } while (cVar10 != '\0');
    pbVar13 = (byte *)(local_12c + (~uVar18 - 1));
    do {
      bVar1 = *pbVar13;
      bVar25 = bVar1 < *pbVar22;
      if (bVar1 != *pbVar22) {
LAB_0057c086:
        iVar11 = (1 - (uint)bVar25) - (uint)(bVar25 != 0);
        goto LAB_0057c08b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar13[1];
      bVar25 = bVar1 < pbVar22[1];
      if (bVar1 != pbVar22[1]) goto LAB_0057c086;
      pbVar13 = pbVar13 + 2;
      pbVar22 = pbVar22 + 2;
    } while (bVar1 != 0);
    iVar11 = 0;
LAB_0057c08b:
    if (iVar11 == 0) {
      cVar10 = FUN_00585220(0,0);
      if (cVar10 != '\0') {
        local_8c[0] = '\0';
        local_18c[0] = *(undefined1 *)((int)param_4 + 7);
        local_178 = CONCAT31(local_178._1_3_,*(undefined1 *)((int)param_4 + 6));
        local_174 = CONCAT31(local_174._1_3_,*(undefined1 *)((int)param_4 + 5));
        local_170 = CONCAT31(local_170._1_3_,*(undefined1 *)(param_4 + 1));
        len = FUN_0058815f(local_8c,s__s_s__d__d__d__d__d__d_005e540c,PTR_DAT_005e537c,
                           PTR_s_TCPInfo_005e5388,local_16c.sa_data._0_2_,
                           *(undefined1 *)(param_4 + 1),*(undefined1 *)((int)param_4 + 5),
                           *(undefined1 *)((int)param_4 + 6),*(undefined1 *)((int)param_4 + 7),
                           *(undefined2 *)((int)param_4 + 2));
        local_188.sa_family = (u_short)*param_4;
        local_188.sa_data._0_2_ = SUB42((uint)*param_4 >> 0x10,0);
        local_188.sa_data._2_2_ = SUB42(param_4[1],0);
        uVar4 = local_188.sa_data._2_2_;
        local_188.sa_data._4_2_ = SUB42((uint)param_4[1] >> 0x10,0);
        uVar5 = local_188.sa_data._4_2_;
        local_188.sa_data._6_4_ = param_4[2];
        uVar15 = param_4[3];
        local_15c.sa_data._0_2_ = htons(local_188.sa_data._0_2_);
        psVar16 = &local_15c;
        local_15c.sa_family = local_188.sa_family;
        local_15c.sa_data[6] = local_188.sa_data[6];
        local_15c.sa_data[7] = local_188.sa_data[7];
        local_15c.sa_data[8] = local_188.sa_data[8];
        local_15c.sa_data[9] = local_188.sa_data[9];
        local_15c.sa_data._2_2_ = uVar4;
        local_15c.sa_data._4_2_ = uVar5;
        local_15c.sa_data._10_4_ = uVar15;
        goto LAB_0057c272;
      }
      iVar11 = 4 - (uint)(*(char *)((int)param_1 + 0x5d) != '\0');
    }
    else {
      iVar11 = 2;
    }
    local_8c[0] = '\0';
    local_198 = FUN_0058815f(local_8c,s__s_s_d_005e5424,PTR_DAT_005e537c,PTR_DAT_005e538c,iVar11);
    if (iVar11 == 2) {
      iVar11 = FUN_0058815f(local_dc,s___s__005c721c,param_1 + 0x246);
      uVar18 = 0xffffffff;
      pcVar17 = local_dc;
      do {
        pcVar24 = pcVar17;
        if (uVar18 == 0) break;
        uVar18 = uVar18 - 1;
        pcVar24 = pcVar17 + 1;
        cVar10 = *pcVar17;
        pcVar17 = pcVar24;
      } while (cVar10 != '\0');
      uVar18 = ~uVar18;
      iVar19 = -1;
      pcVar17 = local_8c;
      do {
        pcVar23 = pcVar17;
        if (iVar19 == 0) break;
        iVar19 = iVar19 + -1;
        pcVar23 = pcVar17 + 1;
        cVar10 = *pcVar17;
        pcVar17 = pcVar23;
      } while (cVar10 != '\0');
      pcVar17 = pcVar24 + -uVar18;
      pcVar24 = pcVar23 + -1;
      for (uVar20 = uVar18 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        *(undefined4 *)pcVar24 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar24 = pcVar24 + 4;
      }
      local_198 = local_198 + iVar11;
      for (uVar18 = uVar18 & 3; uVar18 != 0; uVar18 = uVar18 - 1) {
        *pcVar24 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar24 = pcVar24 + 1;
      }
    }
    local_15c.sa_family = (u_short)*param_4;
    local_15c.sa_data._0_2_ = SUB42((uint)*param_4 >> 0x10,0);
    local_15c.sa_data._2_2_ = SUB42(param_4[1],0);
    uVar4 = local_15c.sa_data._2_2_;
    local_15c.sa_data._4_2_ = SUB42((uint)param_4[1] >> 0x10,0);
    uVar5 = local_15c.sa_data._4_2_;
    uVar15 = param_4[2];
    uVar2 = param_4[3];
    local_15c.sa_data._0_2_ = htons(local_15c.sa_data._0_2_);
    psVar16 = &local_188;
    len = local_198;
    local_188.sa_data._2_2_ = uVar4;
    local_188.sa_data._4_2_ = uVar5;
    local_188.sa_data._6_4_ = uVar15;
    local_188.sa_data._10_4_ = uVar2;
LAB_0057c272:
    local_188.sa_family = local_15c.sa_family;
    local_188.sa_data._0_2_ = local_15c.sa_data._0_2_;
    sendto(param_1[0x24f],local_8c,len,0,psVar16,0x10);
    ExceptionList = local_c;
    return 1;
  }
  uVar18 = 0xffffffff;
  pcVar17 = PTR_s_TCPInfo_005e5388;
  do {
    if (uVar18 == 0) break;
    uVar18 = uVar18 - 1;
    cVar10 = *pcVar17;
    pcVar17 = pcVar17 + 1;
  } while (cVar10 != '\0');
  iVar11 = _strncmp(local_12c,PTR_s_TCPInfo_005e5388,~uVar18 - 1);
  if (iVar11 == 0) {
    iVar11 = FUN_00585d20();
    if (iVar11 != 1) {
      ExceptionList = local_c;
      return 1;
    }
    htonl(0);
    htons(0);
    local_16c.sa_family = 2;
    uVar12 = htonl(0);
    local_16c.sa_data[2] = (char)uVar12;
    local_16c.sa_data[3] = (char)(uVar12 >> 8);
    local_16c.sa_data[4] = (char)(uVar12 >> 0x10);
    local_16c.sa_data[5] = (char)(uVar12 >> 0x18);
    local_16c.sa_data._0_2_ = htons(0);
    local_188.sa_family = (u_short)*param_4;
    local_188.sa_data._0_2_ = SUB42((uint)*param_4 >> 0x10,0);
    local_188.sa_data._2_2_ = SUB42(param_4[1],0);
    local_188.sa_data._4_2_ = SUB42((uint)param_4[1] >> 0x10,0);
    local_188.sa_data._6_4_ = param_4[2];
    local_188.sa_data._10_4_ = param_4[3];
    uVar18 = 0xffffffff;
    pcVar17 = PTR_s_TCPInfo_005e5388;
    do {
      if (uVar18 == 0) break;
      uVar18 = uVar18 - 1;
      cVar10 = *pcVar17;
      pcVar17 = pcVar17 + 1;
    } while (cVar10 != '\0');
    local_190 = 0;
    local_14c[0] = 0;
    local_170 = 0;
    local_174 = 0;
    local_178 = 0;
    local_18c[0] = '\0';
    local_18c[1] = '\0';
    local_18c[2] = '\0';
    local_18c[3] = '\0';
    FUN_005887ed(local_12c + (~uVar18 - 1),s__d__d__d__d__d__d_005e53f8,&local_190,local_14c,
                 &local_170,&local_174,&local_178,local_18c);
    acVar3 = local_18c;
    iVar11 = local_190;
    local_16c.sa_data[2] = (char)local_14c[0];
    local_16c.sa_data[3] = (char)local_170;
    local_16c.sa_data[4] = (char)local_174;
    local_16c.sa_data[5] = (char)local_178;
    local_16c.sa_data[0] = local_18c[0];
    local_16c.sa_data[1] = local_18c[1];
    local_188.sa_data[0] = (undefined1)local_190;
    local_188.sa_data[1] = local_190._1_1_;
    local_198 = 0xffffffff;
    local_194 = (int *)0x0;
    local_190 = iVar11;
    local_18c = acVar3;
    while( true ) {
      do {
        local_198 = FUN_0057bee0();
      } while (local_198 == 0xffffffff);
      FUN_0057c7b0(local_198,*(ushort *)(param_1 + 0x244) + 0x32 + (int)local_194);
      uVar8 = local_188.sa_data._10_4_;
      uVar15 = local_188.sa_data._6_4_;
      uVar6 = local_188.sa_data._4_2_;
      uVar4 = local_188.sa_data._2_2_;
      local_144 = CONCAT22(local_188.sa_data._0_2_,local_188.sa_family);
      local_15c.sa_data._0_2_ = htons(local_188.sa_data._0_2_);
      uVar9 = local_188.sa_data._10_4_;
      uVar2 = local_188.sa_data._6_4_;
      uVar7 = local_188.sa_data._4_2_;
      uVar5 = local_188.sa_data._2_2_;
      local_144 = CONCAT22(local_15c.sa_data._0_2_,(u_short)local_144);
      local_15c.sa_family = (u_short)local_144;
      local_188.sa_data[2] = (char)uVar4;
      local_188.sa_data[3] = SUB21(uVar4,1);
      local_15c.sa_data[2] = local_188.sa_data[2];
      local_15c.sa_data[3] = local_188.sa_data[3];
      local_188.sa_data[4] = (char)uVar6;
      local_188.sa_data[5] = SUB21(uVar6,1);
      local_15c.sa_data[4] = local_188.sa_data[4];
      local_15c.sa_data[5] = local_188.sa_data[5];
      local_188.sa_data[6] = (char)uVar15;
      local_188.sa_data[7] = SUB41(uVar15,1);
      local_188.sa_data[8] = SUB41(uVar15,2);
      local_188.sa_data[9] = SUB41(uVar15,3);
      local_15c.sa_data[6] = local_188.sa_data[6];
      local_15c.sa_data[7] = local_188.sa_data[7];
      local_15c.sa_data[8] = local_188.sa_data[8];
      local_15c.sa_data[9] = local_188.sa_data[9];
      local_188.sa_data[10] = (char)uVar8;
      local_188.sa_data[0xb] = SUB41(uVar8,1);
      local_188.sa_data[0xc] = SUB41(uVar8,2);
      local_188.sa_data[0xd] = SUB41(uVar8,3);
      local_15c.sa_data[10] = local_188.sa_data[10];
      local_15c.sa_data[0xb] = local_188.sa_data[0xb];
      local_15c.sa_data[0xc] = local_188.sa_data[0xc];
      local_15c.sa_data[0xd] = local_188.sa_data[0xd];
      local_188.sa_data._2_2_ = uVar5;
      local_188.sa_data._4_2_ = uVar7;
      local_188.sa_data._6_4_ = uVar2;
      local_188.sa_data._10_4_ = uVar9;
      iVar11 = connect(local_198,&local_15c,0x10);
      if (iVar11 == 0) break;
      iVar11 = WSAGetLastError();
      if ((iVar11 != 0x2740) || (local_194 = (int *)((int)local_194 + 1), 0x32 < (int)local_194)) {
        FUN_0057c8e0(&local_198,1);
        ExceptionList = local_c;
        return 1;
      }
      FUN_0057c8e0(&local_198,1);
      Sleep(10);
    }
    FUN_00585cd0(2);
    if (((HANDLE)param_1[0x2fb] == (HANDLE)0x0) ||
       ((DVar14 = WaitForSingleObject((HANDLE)param_1[0x2fb],param_1[0x2fc]),
        local_194 = param_1 + 0x2f3, DVar14 != 0 && (DVar14 != 0x80)))) {
      local_194 = (int *)0x0;
    }
    piVar21 = local_194;
    iVar11 = 0;
    FUN_004ba780();
    piVar21 = (int *)piVar21[6];
    if (piVar21 != (int *)0x0) {
      iVar11 = *piVar21;
      *(undefined1 *)(piVar21 + 2) = 0;
      cVar10 = FUN_005817a0(iVar11,1);
      if (cVar10 == '\0') {
        iVar11 = 0;
      }
    }
    if (iVar11 == 0) {
      local_130 = operator_new(4);
      local_4._0_1_ = 1;
      if (local_130 == (void *)0x0) {
        uVar15 = 0;
      }
      else {
        uVar15 = FUN_005830c0(0);
      }
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_00583530(uVar15,0);
      iVar11 = FUN_00582eb0();
    }
    if ((HANDLE)param_1[0x2fb] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x2fb]);
    }
    FUN_004979c0(local_198);
    local_14c[1] = 0x10;
    psVar16 = (sockaddr *)FUN_0057b6a0();
    getpeername(local_198,psVar16,(int *)(local_14c + 1));
    FUN_0057b680(param_4);
    if ((HANDLE)param_1[400] != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)param_1[400],param_1[0x191]);
    }
    FUN_005870e0();
    if ((HANDLE)param_1[400] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[400]);
    }
    uVar15 = (**(code **)(*param_1 + 0x58))();
    FUN_00586800(0,6,1,2,0xffffffff);
    FUN_00586a00(&local_16c,0x10);
    FUN_0057afa0(psVar16);
    FUN_00584c70(uVar15);
    uVar15 = (**(code **)(*param_1 + 0x58))();
    FUN_00586800(0,3,1,2,0xffffffff);
    pcVar17 = (char *)FUN_00585020();
    if (pcVar17 == (char *)0x0) {
      local_14c[0] = local_14c[0] & 0xffffff00;
    }
    else {
      _strncpy((char *)local_14c,pcVar17,0x10);
      uStack_13c = 0;
    }
    FUN_00586a00(local_14c,0x11);
    FUN_0057afa0(psVar16);
    FUN_00584c70(uVar15);
    FUN_0057dc10(iVar11);
    ExceptionList = local_c;
    return 1;
  }
  uVar18 = 0xffffffff;
  pcVar17 = PTR_DAT_005e538c;
  do {
    if (uVar18 == 0) break;
    uVar18 = uVar18 - 1;
    cVar10 = *pcVar17;
    pcVar17 = pcVar17 + 1;
  } while (cVar10 != '\0');
  iVar11 = _strncmp(local_12c,PTR_DAT_005e538c,~uVar18 - 1);
  if (iVar11 != 0) {
    ExceptionList = local_c;
    return 1;
  }
  iVar11 = FUN_00585d20();
  if (iVar11 != 1) {
    ExceptionList = local_c;
    return 1;
  }
  FUN_00585cd0(0);
  uVar18 = 0xffffffff;
  local_190 = 0;
  local_dc[0] = '\0';
  pcVar17 = PTR_DAT_005e538c;
  do {
    if (uVar18 == 0) break;
    uVar18 = uVar18 - 1;
    cVar10 = *pcVar17;
    pcVar17 = pcVar17 + 1;
  } while (cVar10 != '\0');
  FUN_005887ed(local_12c + (~uVar18 - 1),s__d_____005e53ec,&local_190,local_dc);
  piVar21 = param_1 + 0x171;
  if (((HANDLE)param_1[0x186] == (HANDLE)0x0) ||
     ((DVar14 = WaitForSingleObject((HANDLE)param_1[0x186],param_1[0x187]), DVar14 != 0 &&
      (DVar14 != 0x80)))) {
    piVar21 = (int *)0x0;
  }
  switch(local_190) {
  case 2:
    *piVar21 = 2;
    pcVar17 = local_dc;
    do {
      cVar10 = *pcVar17;
      pcVar17[(int)piVar21 + (4 - (int)local_dc)] = cVar10;
      pcVar17 = pcVar17 + 1;
    } while (cVar10 != '\0');
    goto LAB_0057c74e;
  case 3:
    *piVar21 = 3;
    break;
  case 4:
    *piVar21 = 4;
    break;
  case 5:
    *piVar21 = 5;
    break;
  default:
    *piVar21 = 1;
  }
  *(undefined1 *)(piVar21 + 1) = 0;
LAB_0057c74e:
  if ((HANDLE)param_1[0x186] != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)param_1[0x186]);
  }
  ExceptionList = local_c;
  return 1;
}


