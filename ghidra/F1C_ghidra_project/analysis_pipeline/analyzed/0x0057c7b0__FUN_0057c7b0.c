// Function: FUN_0057c7b0 @ 0057c7b0
// Size (bytes): 175


uint FUN_0057c7b0(SOCKET param_1,short param_2)

{
  undefined4 uVar1;
  u_short uVar2;
  int iVar3;
  ushort hostshort;
  int iVar4;
  sockaddr local_20;
  sockaddr local_10;
  
  iVar4 = 0;
  htonl(0);
  htons(0);
  do {
    uVar1._0_1_ = '\0';
    uVar1._1_1_ = '\0';
    uVar1._2_1_ = '\0';
    uVar1._3_1_ = '\0';
    hostshort = param_2 + (short)iVar4;
    local_10._0_4_ = CONCAT22(hostshort,2);
    uVar2 = htons(hostshort);
    local_10.sa_data[1] = (char)(uVar2 >> 8);
    local_10.sa_data[0] = (char)uVar2;
    local_20.sa_family = local_10.sa_family;
    local_20.sa_data[0] = (char)uVar2;
    local_20.sa_data[1] = local_10.sa_data[1];
    local_20.sa_data._2_4_ = uVar1;
    iVar3 = bind(param_1,&local_20,0x10);
    if (iVar3 == 0) {
      return (uint)hostshort;
    }
    iVar3 = WSAGetLastError();
  } while ((iVar3 != 0x2726) && (iVar4 = iVar4 + 1, iVar4 < 100));
  return 0xffffffff;
}


