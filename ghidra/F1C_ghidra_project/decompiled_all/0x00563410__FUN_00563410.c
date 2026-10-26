// Function: FUN_00563410 @ 00563410
// Strings:  [\final\, \final\]


undefined4 __fastcall FUN_00563410(undefined4 *param_1)

{
  char cVar1;
  u_short uVar2;
  undefined4 uVar3;
  int iVar4;
  DWORD DVar5;
  uint uVar6;
  char *pcVar7;
  int local_6fc;
  timeval local_6f8;
  sockaddr local_6f0;
  fd_set local_6e0;
  char local_5dc [1192];
  undefined4 uStack_134;
  timeval local_10c;
  fd_set local_104;
  
  if (param_1 != (undefined4 *)0x0) {
    switch(*param_1) {
    default:
      return 0;
    case 1:
      goto LAB_00563570;
    case 2:
      local_6f8.tv_sec = 0;
      local_6f8.tv_usec = 0;
      local_6fc = 0x10;
      while( true ) {
        local_6e0.fd_array[0] = param_1[0x22];
        local_6e0.fd_count = 1;
        iVar4 = select(0x40,&local_6e0,(fd_set *)0x0,(fd_set *)0x0,&local_6f8);
        if ((iVar4 == -1) || (iVar4 == 0)) break;
        iVar4 = recvfrom(param_1[0x22],local_5dc,0x5db,0,&local_6f0,&local_6fc);
        if (iVar4 != -1) {
          local_104.fd_array[0x3f]._3_1_ = 0;
          iVar4 = FUN_00587c20(local_5dc,s__final__005e4eac);
          if (iVar4 != 0) {
            uVar2 = ntohs(local_6f0.sa_data._0_2_);
            iVar4 = FUN_005631a0(uVar2);
            if (iVar4 == -1) {
              uVar3 = 5;
              uVar2 = ntohs(local_6f0.sa_data._0_2_);
              FUN_00563160(uVar2,uVar3);
            }
          }
        }
      }
      DVar5 = GetTickCount();
      if (3000 < DVar5 - param_1[0x23]) {
        closesocket(param_1[0x22]);
        param_1[0x22] = 0xffffffff;
        FUN_00562fe0();
      }
      return 0;
    case 3:
      uVar3 = FUN_00563ab0();
      return uVar3;
    }
  }
  return 5;
LAB_00563570:
  local_104.fd_array[0] = param_1[0x22];
  local_10c.tv_sec = 0;
  local_10c.tv_usec = 0;
  local_104.fd_count = 1;
  uStack_134 = 0x5635ab;
  iVar4 = select(0x40,&local_104,(fd_set *)0x0,(fd_set *)0x0,&local_10c);
  if (iVar4 < 1) {
    return 0;
  }
  iVar4 = recv(param_1[0x22],(char *)(&DAT_008cf288 + (int)DAT_008cfae0),0x7ff - (int)DAT_008cfae0,0
              );
  if ((iVar4 == -1) || (iVar4 == 0)) {
    closesocket(param_1[0x22]);
    param_1[0x22] = 0xffffffff;
    DAT_008cfae0 = (undefined1 *)0x0;
    FUN_00563df0();
    FUN_00562fe0();
    return 3;
  }
  if (param_1[0x157] != -1) {
    FUN_00565140();
  }
  DAT_008cfae0 = (undefined1 *)((int)DAT_008cfae0 + iVar4);
  pcVar7 = (char *)&DAT_008cf288;
  if (param_1[0x157] == -1) {
    if ((int)((int)(char)DAT_008cf288 ^ 0xecU) < (int)DAT_008cfae0) {
      DAT_008cf288 = DAT_008cf288 ^ 0xec;
      uVar6 = 0xffffffff;
      iVar4 = 0;
      pcVar7 = (char *)(param_1 + 0xb);
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (0 < (int)(~uVar6 - 1)) {
        do {
          (&DAT_008cf289)[iVar4] = (&DAT_008cf289)[iVar4] ^ *(byte *)((int)(param_1 + 0xb) + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(~uVar6 - 1));
      }
      FUN_00565080();
      pcVar7 = &DAT_008cf289 + (char)DAT_008cf288;
      FUN_00565140();
    }
    if (param_1[0x157] == -1) goto LAB_00563801;
  }
  if ((int)(pcVar7 + -0x8cf288) <= (int)DAT_008cfae0 + -6) {
    do {
      iVar4 = _strncmp(pcVar7,s__final__005e4eac,7);
      if ((iVar4 == 0) || (param_1[0x1d] != 0)) {
        closesocket(param_1[0x22]);
        param_1[0x22] = 0xffffffff;
        DAT_008cfae0 = (undefined1 *)0x0;
        if ((param_1[0x24] != 6) && (param_1[0x24] != 7)) {
          FUN_00562fe0();
          return 0;
        }
        FUN_00562fe0();
        return 0;
      }
      if ((int)DAT_008cfae0 < 6) break;
      if ((param_1[0x24] == 6) || (param_1[0x24] == 7)) {
        iVar4 = FUN_00563870();
        if (iVar4 < 0) {
          param_1[0x1d] = 1;
        }
        else {
          if (iVar4 == 0) break;
          pcVar7 = pcVar7 + iVar4;
        }
      }
      else {
        uVar2 = *(u_short *)(pcVar7 + 4);
        pcVar7 = pcVar7 + 6;
        ntohs(uVar2);
        iVar4 = FUN_005631d0();
        if (iVar4 == -1) {
          ntohs(uVar2);
          FUN_00563160();
        }
      }
    } while ((int)(pcVar7 + -0x8cf288) <= (int)DAT_008cfae0 + -6);
  }
LAB_00563801:
  DAT_008cfae0 = &DAT_008cf288 + ((int)DAT_008cfae0 - (int)pcVar7);
  FUN_0058b130();
  return 0;
}


