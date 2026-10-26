// Function: FUN_00562d90 @ 00562d90
// Strings:  [master.openspy.net, master.openspy.net]


undefined4 __fastcall FUN_00562d90(int param_1)

{
  hostent *phVar1;
  SOCKET s;
  int iVar2;
  sockaddr local_10;
  
  local_10.sa_family = 2;
  local_10.sa_data._0_2_ = htons(0x70e4);
  local_10.sa_data._2_4_ = inet_addr(s_master_openspy_net_005e4ef8);
  if (local_10.sa_data._2_4_ == 0xffffffff) {
    phVar1 = gethostbyname(s_master_openspy_net_005e4ef8);
    if (phVar1 == (hostent *)0x0) {
      return 2;
    }
    local_10.sa_data._2_4_ = *(undefined4 *)*phVar1->h_addr_list;
  }
  s = socket(2,1,6);
  *(SOCKET *)(param_1 + 0x88) = s;
  if (s == 0xffffffff) {
    return 1;
  }
  iVar2 = connect(s,&local_10,0x10);
  if (iVar2 != 0) {
    closesocket(*(SOCKET *)(param_1 + 0x88));
    return 3;
  }
  return 0;
}


