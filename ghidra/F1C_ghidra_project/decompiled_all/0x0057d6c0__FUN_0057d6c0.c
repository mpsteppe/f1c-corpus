// Function: FUN_0057d6c0 @ 0057d6c0
// Strings:  [WSAETIMEDOUT, WSAEAFNOSUPPORT, WSAEADDRNOTAVAIL, WSAECONNRESET, WSAECONNABORTED, WSAESHUTDOWN, WSAENOTSOCK, WSAENETDOWN]


undefined1 __thiscall FUN_0057d6c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  u_short uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  u_short local_628;
  u_short uStack_626;
  undefined4 local_618;
  sockaddr local_614;
  ushort local_604;
  ushort uStack_602;
  
  FUN_0057d5d0(param_2,&local_604);
  local_628 = (u_short)*param_3;
  uStack_626 = (u_short)((uint)*param_3 >> 0x10);
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  uVar5 = htons(uStack_626);
  local_614.sa_data[0] = (char)uVar5;
  local_614.sa_data[1] = (char)(uVar5 >> 8);
  local_614.sa_family = local_628;
  local_614.sa_data._2_4_ = uVar1;
  local_614.sa_data._6_4_ = uVar2;
  local_614.sa_data._10_4_ = uVar3;
  iVar6 = sendto(*(SOCKET *)(param_1 + 0x93c),(char *)&local_604,local_604 + 4 + (uint)uStack_602,0,
                 &local_614,0x10);
  if (iVar6 != -1) {
    return 1;
  }
  iVar6 = WSAGetLastError();
  switch(iVar6) {
  case 0x2736:
    pcVar8 = s_WSAENOTSOCK_005e62b0;
    break;
  default:
    return 0;
  case 0x273f:
    pcVar8 = s_WSAEAFNOSUPPORT_005e625c;
    break;
  case 0x2741:
    pcVar8 = s_WSAEADDRNOTAVAIL_005e626c;
    break;
  case 0x2742:
    pcVar8 = s_WSAENETDOWN_005e62bc;
    break;
  case 0x2745:
    pcVar8 = s_WSAECONNABORTED_005e6290;
    break;
  case 0x2746:
    pcVar8 = s_WSAECONNRESET_005e6280;
    break;
  case 0x2747:
    cVar4 = FUN_0057ee80(param_3,&local_618,1);
    if (cVar4 == '\0') {
      return 0;
    }
    piVar7 = (int *)FUN_00585cc0();
    (**(code **)(*piVar7 + 0x38))(local_618);
    FUN_004b0170();
    return 0;
  case 0x274a:
    pcVar8 = s_WSAESHUTDOWN_005e62a0;
    break;
  case 0x274c:
    pcVar8 = s_WSAETIMEDOUT_005e624c;
  }
  FUN_0057dff0(*param_3,param_3[1],param_3[2],param_3[3],pcVar8);
  return 0;
}


