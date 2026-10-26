// Function: FUN_0057b9a0 @ 0057b9a0
// Size (bytes): 77


bool __thiscall FUN_0057b9a0(sockaddr *param_1,SOCKET param_2)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0x10;
  iVar1 = getpeername(param_2,param_1,&local_4);
  iVar2 = getsockname(param_2,param_1 + 1,&local_4);
  if (iVar2 != 0) {
    return false;
  }
  return iVar1 == 0;
}


