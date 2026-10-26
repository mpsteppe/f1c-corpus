// Function: FUN_00563ab0 @ 00563ab0
// Strings:  [\final\]


undefined4 __fastcall FUN_00563ab0(int param_1)

{
  u_short uVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  char *cp;
  ulong uVar6;
  SOCKET *pSVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_704;
  int local_700;
  int local_6fc;
  timeval local_6f8;
  sockaddr local_6f0;
  fd_set local_6e0;
  char local_5dc [1500];
  
  iVar9 = 0;
  iVar2 = *(int *)(param_1 + 0x6c);
  iVar10 = 0;
  uVar8 = 0;
  local_6fc = 0;
  local_6f8.tv_sec = 0;
  local_6f8.tv_usec = 0;
  local_700 = 0x10;
  local_6e0.fd_count = 0;
  if (0 < iVar2) {
    pSVar7 = *(SOCKET **)(param_1 + 8);
    do {
      if ((pSVar7[1] != 0) && (iVar10 = iVar10 + 1, uVar8 < 0x40)) {
        local_6e0.fd_array[uVar8] = *pSVar7;
        uVar8 = local_6e0.fd_count + 1;
        local_6e0.fd_count = uVar8;
      }
      pSVar7 = pSVar7 + 7;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    local_6fc = iVar10;
    if ((((0 < iVar10) &&
         (iVar2 = select(0x40,&local_6e0,(fd_set *)0x0,(fd_set *)0x0,&local_6f8), iVar2 != -1)) &&
        (iVar2 != 0)) && (local_704 = 0, 0 < *(int *)(param_1 + 0x6c))) {
      do {
        if ((*(int *)(*(int *)(param_1 + 8) + 4 + iVar9) != 0) &&
           (iVar2 = __WSAFDIsSet(*(SOCKET *)(*(int *)(param_1 + 8) + iVar9),&local_6e0), iVar2 != 0)
           ) {
          local_700 = 0x10;
          iVar10 = recvfrom(*(SOCKET *)(*(int *)(param_1 + 8) + iVar9),local_5dc,0x5db,0,&local_6f0,
                            &local_700);
          iVar2 = *(int *)(param_1 + 8) + iVar9;
          if ((local_6f0.sa_data._2_4_ == *(int *)(*(int *)(param_1 + 8) + 0x10 + iVar9)) &&
             (local_6f0.sa_data._0_2_ == *(short *)(iVar2 + 0xe))) {
            if (iVar10 == -1) {
              *(undefined4 *)(iVar2 + 4) = 0;
            }
            else {
              local_5dc[iVar10] = '\0';
              iVar10 = FUN_00587c20(local_5dc,s__final__005e4eac);
              iVar2 = *(int *)(*(int *)(param_1 + 8) + 4 + iVar9);
              if (*(short *)(iVar2 + 6) == 9999) {
                DVar3 = GetTickCount();
                *(short *)(iVar2 + 6) = (short)DVar3 - *(short *)(*(int *)(param_1 + 8) + 8 + iVar9)
                ;
              }
              FUN_00564390();
              if (iVar10 != 0) {
                iVar10 = FUN_00563e70();
                (**(code **)(param_1 + 0x78))
                          (param_1,2,*(undefined4 *)(param_1 + 0x7c),iVar2,
                           (*(int *)(param_1 + 0x70) * 100) / iVar10);
                *(undefined4 *)(*(int *)(param_1 + 8) + 4 + iVar9) = 0;
              }
            }
          }
        }
        local_704 = local_704 + 1;
        iVar9 = iVar9 + 0x1c;
      } while (local_704 < *(int *)(param_1 + 0x6c));
    }
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    iVar9 = 0;
    do {
      if (*(int *)(iVar9 + 4 + *(int *)(param_1 + 8)) != 0) {
        iVar10 = iVar9 + *(int *)(param_1 + 8);
        DVar3 = GetTickCount();
        if (3000 < DVar3 - *(int *)(iVar10 + 8)) {
          *(undefined4 *)(iVar10 + 4) = 0;
        }
      }
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + 0x1c;
    } while (iVar2 < *(int *)(param_1 + 0x6c));
  }
  if ((*(int *)(param_1 + 0x74) == 0) &&
     ((iVar2 = FUN_00563e70(), *(int *)(param_1 + 0x70) < iVar2 || (local_6fc != 0)))) {
    iVar2 = 0;
    if (*(int *)(param_1 + 0x6c) < 1) {
      return 0;
    }
    iVar9 = 0;
    do {
      iVar10 = *(int *)(param_1 + 0x70);
      iVar4 = FUN_00563e70();
      if (iVar4 <= iVar10) {
        return 0;
      }
      if (*(int *)(iVar9 + 4 + *(int *)(param_1 + 8)) == 0) {
        piVar5 = (int *)FUN_005648b0();
        iVar10 = *piVar5;
        *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
        *(int *)(iVar9 + 4 + *(int *)(param_1 + 8)) = iVar10;
        *(undefined2 *)(iVar9 + 0xc + *(int *)(param_1 + 8)) = 2;
        cp = (char *)FUN_00564490();
        uVar6 = inet_addr(cp);
        *(ulong *)(iVar9 + 0x10 + *(int *)(param_1 + 8)) = uVar6;
        uVar1 = FUN_005644a0();
        uVar1 = htons(uVar1);
        *(u_short *)(iVar9 + 0xe + *(int *)(param_1 + 8)) = uVar1;
        iVar10 = *(int *)(iVar10 + 8);
        pSVar7 = (SOCKET *)(*(int *)(param_1 + 8) + iVar9);
        sendto(*pSVar7,(&PTR_s__basic__005e4f38)[iVar10],*(int *)(&DAT_005b89a0 + iVar10 * 4),0,
               (sockaddr *)(pSVar7 + 3),0x10);
        DVar3 = GetTickCount();
        *(DWORD *)(iVar9 + 8 + *(int *)(param_1 + 8)) = DVar3;
      }
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + 0x1c;
    } while (iVar2 < *(int *)(param_1 + 0x6c));
    return 0;
  }
  FUN_00563dc0();
  FUN_00562fe0();
  return 0;
}


