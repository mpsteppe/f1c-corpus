// Function: FUN_00561e30 @ 00561e30
// Size (bytes): 149


void __fastcall FUN_00561e30(SOCKET *param_1)

{
  int iVar1;
  int local_120;
  timeval local_11c;
  sockaddr local_114;
  fd_set local_104;
  
  local_120 = 0x10;
  local_11c.tv_sec = 0;
  local_11c.tv_usec = 0;
  if (param_1[0x39] != 0) {
    local_104.fd_array[0] = *param_1;
    local_104.fd_count = 1;
    while( true ) {
      iVar1 = select(0x40,&local_104,(fd_set *)0x0,(fd_set *)0x0,&local_11c);
      if ((iVar1 == -1) || (iVar1 == 0)) break;
      iVar1 = recvfrom(*param_1,&DAT_008cef80,0xff,0,&local_114,&local_120);
      if (iVar1 != -1) {
        (&DAT_008cef80)[iVar1] = 0;
        FUN_005622c0(iVar1,&local_114);
      }
    }
  }
  return;
}


