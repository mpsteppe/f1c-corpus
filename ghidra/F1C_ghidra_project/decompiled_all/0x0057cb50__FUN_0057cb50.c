// Function: FUN_0057cb50 @ 0057cb50
// Strings:  [Timed Out, Aborted, Invalid, Shutdown, Not Supported, Not Socket, Network Reset, Not Connected]


undefined4 __thiscall FUN_0057cb50(int *param_1,SOCKET param_2,char param_3)

{
  ushort uVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  u_short uVar8;
  int iVar9;
  DWORD DVar10;
  u_long uVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  ushort *puVar15;
  int *piVar16;
  float10 fVar17;
  char local_76e;
  char local_76c;
  undefined1 local_76a;
  uint local_764;
  uint local_760;
  sockaddr local_758;
  int local_748;
  undefined4 local_744;
  u_long uStack_740;
  undefined4 uStack_73c;
  undefined4 uStack_738;
  undefined4 uStack_734;
  u_long uStack_730;
  undefined4 uStack_72c;
  undefined4 uStack_728;
  int local_724;
  timeval local_720;
  undefined1 local_718 [16];
  fd_set local_708;
  ushort local_604;
  ushort uStack_602;
  
  local_76a = 0;
  local_720.tv_sec = 0;
  local_720.tv_usec = 0;
  local_76e = '\0';
  local_708.fd_array[0] = param_2;
  local_708.fd_count = 1;
  local_76c = '\0';
  local_748 = 0;
  do {
    iVar9 = CONCAT31((int3)((uint)local_748 >> 8),local_76c);
    if (local_76c != '\0') break;
    bVar3 = false;
    bVar4 = false;
    bVar5 = false;
    local_760 = 0;
    iVar9 = select(0,&local_708,(fd_set *)0x0,(fd_set *)0x0,&local_720);
    if (iVar9 == -1) {
      WSAGetLastError();
      FUN_0057d400();
    }
    else if (iVar9 != 0) {
      bVar4 = true;
    }
    if (param_3 == '\0') {
      if (bVar4) {
LAB_0057ccca:
        bVar3 = false;
LAB_0057cccf:
        if (local_76c != '\0') goto LAB_0057d2c1;
        local_764 = 0;
        local_758.sa_family = 2;
        uVar11 = htonl(0);
        local_758.sa_data._2_2_ = SUB42(uVar11,0);
        local_758.sa_data._4_2_ = SUB42(uVar11 >> 0x10,0);
        local_758.sa_data._0_2_ = htons(0);
        pcVar12 = (char *)FUN_00563e70();
        iVar9 = FUN_0055bfc0();
        local_724 = 0x10;
        if (param_3 == '\0') {
          bVar6 = true;
          if (bVar4) {
            piVar16 = param_1 + 0x2ab;
            if (((HANDLE)param_1[0x2af] == (HANDLE)0x0) ||
               ((DVar10 = WaitForSingleObject((HANDLE)param_1[0x2af],param_1[0x2b0]), DVar10 != 0 &&
                (DVar10 != 0x80)))) {
              piVar16 = (int *)0x0;
            }
            piVar2 = (int *)*piVar16;
            piVar16[2] = (int)piVar2;
            if ((piVar2 != (int *)0x0) && (iVar13 = *piVar2, iVar13 != 0)) {
              while( true ) {
                if ((*(SOCKET *)(iVar13 + 0x20) != 0xffffffff) &&
                   (((param_2 != 0xffffffff && (*(SOCKET *)(iVar13 + 0x20) == param_2)) &&
                    (iVar13 = 0x1000 - (uint)*(ushort *)(iVar13 + 0x1038), iVar13 <= iVar9)))) {
                  iVar9 = iVar13;
                }
                if (piVar16[2] == 0) break;
                piVar2 = *(int **)(piVar16[2] + 4);
                piVar16[2] = (int)piVar2;
                if ((piVar2 == (int *)0x0) || (iVar13 = *piVar2, iVar13 == 0)) break;
              }
            }
            if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
              ReleaseMutex((HANDLE)param_1[0x2af]);
            }
            if (iVar9 < 1) goto LAB_0057ce92;
            bVar5 = true;
            local_760 = recv(param_2,pcVar12,iVar9,0);
            if (0 < (int)local_760) {
              bVar6 = false;
            }
LAB_0057ce9a:
            if (local_76e == '\0') {
              local_76e = FUN_0057b9a0(param_2);
            }
          }
          else {
LAB_0057ce92:
            if (bVar5) goto LAB_0057ce9a;
          }
          piVar16 = param_1 + 0x2ab;
          if (((HANDLE)param_1[0x2af] == (HANDLE)0x0) ||
             ((DVar10 = WaitForSingleObject((HANDLE)param_1[0x2af],param_1[0x2b0]), DVar10 != 0 &&
              (DVar10 != 0x80)))) {
            piVar16 = (int *)0x0;
          }
          piVar2 = (int *)*piVar16;
          piVar16[2] = (int)piVar2;
          if ((piVar2 != (int *)0x0) && (iVar9 = *piVar2, iVar9 != 0)) {
            while ((*(SOCKET *)(iVar9 + 0x20) == 0xffffffff ||
                   ((param_2 == 0xffffffff || (*(SOCKET *)(iVar9 + 0x20) != param_2))))) {
              if (piVar16[2] == 0) goto LAB_0057cfba;
              piVar2 = *(int **)(piVar16[2] + 4);
              piVar16[2] = (int)piVar2;
              if ((piVar2 == (int *)0x0) || (iVar9 = *piVar2, iVar9 == 0)) goto LAB_0057cfba;
            }
            if ((bVar5) && (0 < (int)local_760)) {
              FUN_0057b550(pcVar12,local_760);
              bVar6 = true;
            }
            uVar1 = *(ushort *)(iVar9 + 0x1038);
            if ((((3 < uVar1) && (cVar7 = FUN_0057b630(&local_604,4), cVar7 != '\0')) &&
                (uVar14 = uStack_602 + 4 + (uint)local_604, uVar14 <= uVar1)) &&
               (cVar7 = FUN_0057b5c0(pcVar12,uVar14), cVar7 != '\0')) {
              local_764 = uVar14;
            }
          }
LAB_0057cfba:
          if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
            ReleaseMutex((HANDLE)param_1[0x2af]);
          }
          if (bVar6) goto LAB_0057cfd4;
LAB_0057d193:
          bVar3 = true;
        }
        else {
          local_764 = recvfrom(param_2,pcVar12,iVar9,0,&local_758,&local_724);
          local_758.sa_data._0_2_ = ntohs(local_758.sa_data._0_2_);
          cVar7 = FUN_0057bf00(pcVar12,local_764,&local_758);
          local_760 = local_764;
          if ((cVar7 != '\0') || (bVar5 = true, (int)local_764 < 1)) goto LAB_0057d193;
          local_76e = FUN_0057b950(CONCAT22(local_758.sa_data._0_2_,local_758.sa_family),
                                   CONCAT22(local_758.sa_data._4_2_,local_758.sa_data._2_2_),
                                   local_758.sa_data._6_4_,local_758.sa_data._10_4_,param_2);
LAB_0057cfd4:
          if ((int)local_764 < 1) goto LAB_0057d193;
          if (local_764 < 0x605) {
            puVar15 = &local_604;
            for (uVar14 = local_764 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *(undefined4 *)puVar15 = *(undefined4 *)pcVar12;
              pcVar12 = pcVar12 + 4;
              puVar15 = puVar15 + 2;
            }
            for (uVar14 = local_764 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
              *(char *)puVar15 = *pcVar12;
              pcVar12 = pcVar12 + 1;
              puVar15 = (ushort *)((int)puVar15 + 1);
            }
            if (local_764 == uStack_602 + 4 + (uint)local_604) {
              local_76a = 1;
              fVar17 = (float10)FUN_00584f90();
              FUN_0057b9f0(&local_758);
              piVar16 = param_1 + 0x2ab;
              if (((HANDLE)param_1[0x2af] == (HANDLE)0x0) ||
                 ((DVar10 = WaitForSingleObject((HANDLE)param_1[0x2af],param_1[0x2b0]), DVar10 != 0
                  && (DVar10 != 0x80)))) {
                piVar16 = (int *)0x0;
              }
              piVar2 = (int *)*piVar16;
              piVar16[2] = (int)piVar2;
              if ((piVar2 != (int *)0x0) && (iVar9 = *piVar2, iVar9 != 0)) {
                while (((*(int *)(iVar9 + 4) !=
                         CONCAT22(local_758.sa_data._4_2_,local_758.sa_data._2_2_) ||
                        (*(u_short *)(iVar9 + 2) != local_758.sa_data._0_2_)) &&
                       ((*(int *)(iVar9 + 0x14) !=
                         CONCAT22(local_758.sa_data._4_2_,local_758.sa_data._2_2_) ||
                        (*(u_short *)(iVar9 + 0x12) != local_758.sa_data._0_2_))))) {
                  if (piVar16[2] == 0) goto LAB_0057d0ca;
                  piVar2 = *(int **)(piVar16[2] + 4);
                  piVar16[2] = (int)piVar2;
                  if ((piVar2 == (int *)0x0) || (iVar9 = *piVar2, iVar9 == 0)) goto LAB_0057d0ca;
                }
                *(float *)(iVar9 + 0x2c) = (float)fVar17;
              }
LAB_0057d0ca:
              if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
                ReleaseMutex((HANDLE)param_1[0x2af]);
              }
              local_764 = 0xffffffff;
              piVar16 = param_1 + 0x2b2;
              if (((HANDLE)param_1[0x2b6] == (HANDLE)0x0) ||
                 ((DVar10 = WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]), DVar10 != 0
                  && (DVar10 != 0x80)))) {
                piVar16 = (int *)0x0;
              }
              piVar2 = (int *)*piVar16;
              piVar16[2] = (int)piVar2;
              if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
                while (cVar7 = FUN_0057b840(&local_758), cVar7 == '\0') {
                  if (piVar16[2] == 0) goto LAB_0057d153;
                  piVar2 = *(int **)(piVar16[2] + 4);
                  piVar16[2] = (int)piVar2;
                  if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) goto LAB_0057d153;
                }
                local_764 = FUN_005871f0();
              }
LAB_0057d153:
              if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
                ReleaseMutex((HANDLE)param_1[0x2b6]);
              }
              iVar9 = (**(code **)(*param_1 + 0x58))();
              if (iVar9 != 0) {
                FUN_0057d660(&local_604,iVar9);
                *(uint *)(iVar9 + 4) = local_764;
                FUN_00585400(iVar9);
              }
            }
          }
        }
        if (!bVar5) goto switchD_0057d249_caseD_271f;
        if (local_760 != 0xffffffff) {
          if (local_760 == 0) {
            local_744 = CONCAT22(local_744._2_2_,2);
            uStack_740 = htonl(0);
            uVar8 = htons(0);
            local_744 = CONCAT22(uVar8,(undefined2)local_744);
            FUN_0057b9f0(&local_744);
            FUN_0057dff0(local_744,uStack_740,uStack_73c,uStack_738,s_Closed_Gracefully_005e54d0);
            local_76c = '\x01';
          }
          goto switchD_0057d249_caseD_271f;
        }
        iVar9 = WSAGetLastError();
        switch(iVar9) {
        case 0x271e:
          pcVar12 = s_Fault_005e5490;
          break;
        default:
          goto switchD_0057d249_caseD_271f;
        case 0x2726:
          pcVar12 = s_Invalid_005e5440;
          break;
        case 0x2736:
          pcVar12 = s_Not_Socket_005e5464;
          break;
        case 0x2738:
          goto switchD_0057d249_caseD_2738;
        case 0x273d:
          pcVar12 = s_Not_Supported_005e5454;
          break;
        case 0x2742:
          pcVar12 = s_Network_Down_005e5498;
          break;
        case 0x2744:
          pcVar12 = s_Network_Reset_005e5470;
          break;
        case 0x2745:
          pcVar12 = s_Aborted_005e5438;
          break;
        case 0x2746:
          if (param_3 == '\0') {
            pcVar12 = s_TCP_connection_reset_005e54b8;
            break;
          }
switchD_0057d249_caseD_271f:
          if (bVar3) goto LAB_0057d2c1;
          goto LAB_0057cccf;
        case 0x2749:
          pcVar12 = s_Not_Connected_005e5480;
          break;
        case 0x274a:
          pcVar12 = s_Shutdown_005e5448;
          break;
        case 0x274c:
          pcVar12 = s_Timed_Out_005e542c;
          break;
        case 0x276d:
          pcVar12 = s_Not_Initialised_005e54a8;
        }
        uStack_734 = CONCAT22(uStack_734._2_2_,2);
        uStack_730 = htonl(0);
        uVar8 = htons(0);
        uStack_734 = CONCAT22(uVar8,(undefined2)uStack_734);
        FUN_0057b9f0(&uStack_734);
        FUN_0057dff0(uStack_734,uStack_730,uStack_72c,uStack_728,pcVar12);
        local_76c = '\x01';
        goto LAB_0057d2c1;
      }
      if (local_76e == '\0') {
        local_76e = FUN_0057b9a0(param_2);
      }
      htonl(0);
      htons(0);
      FUN_0057b9f0(local_718);
      piVar16 = param_1 + 0x2ab;
      if (((HANDLE)param_1[0x2af] == (HANDLE)0x0) ||
         ((DVar10 = WaitForSingleObject((HANDLE)param_1[0x2af],param_1[0x2b0]), DVar10 != 0 &&
          (DVar10 != 0x80)))) {
        piVar16 = (int *)0x0;
      }
      piVar2 = (int *)*piVar16;
      piVar16[2] = (int)piVar2;
      if ((piVar2 != (int *)0x0) && (iVar9 = *piVar2, iVar9 != 0)) {
        while ((*(SOCKET *)(iVar9 + 0x20) == 0xffffffff ||
               ((param_2 == 0xffffffff || (*(SOCKET *)(iVar9 + 0x20) != param_2))))) {
          if (piVar16[2] == 0) goto LAB_0057ccb4;
          piVar2 = *(int **)(piVar16[2] + 4);
          piVar16[2] = (int)piVar2;
          if ((piVar2 == (int *)0x0) || (iVar9 = *piVar2, iVar9 == 0)) goto LAB_0057ccb4;
        }
        if (3 < *(ushort *)(iVar9 + 0x1038)) {
          bVar3 = true;
        }
      }
LAB_0057ccb4:
      if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
        ReleaseMutex((HANDLE)param_1[0x2af]);
      }
      if (bVar3) goto LAB_0057ccca;
    }
    else if (bVar4) goto LAB_0057ccca;
LAB_0057d2c1:
    iVar9 = local_748 + 1;
    local_748 = iVar9;
  } while (iVar9 < 1);
  return CONCAT31((int3)((uint)iVar9 >> 8),local_76a);
switchD_0057d249_caseD_2738:
  FUN_005875c0(0x200);
  goto LAB_0057ccca;
}


