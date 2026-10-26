// Function: FUN_005630d0 @ 005630d0
// Strings:  [\status\]


undefined4 __fastcall FUN_005630d0(int param_1,ushort param_2,int param_3,short param_4)

{
  DWORD DVar1;
  sockaddr local_10;
  
  local_10.sa_family = 2;
  local_10.sa_data[2] = -1;
  local_10.sa_data[3] = -1;
  local_10.sa_data[4] = -1;
  local_10.sa_data[5] = -1;
  for (; (int)(uint)param_2 <= param_3; param_2 = param_2 + param_4) {
    local_10.sa_data._0_2_ = htons(param_2);
    sendto(*(SOCKET *)(param_1 + 0x88),s__status__005e4f50,8,0,&local_10,0x10);
  }
  FUN_00562fe0();
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 0x8c) = DVar1;
  return 0;
}


