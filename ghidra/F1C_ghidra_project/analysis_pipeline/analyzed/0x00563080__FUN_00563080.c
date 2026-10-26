// Function: FUN_00563080 @ 00563080
// Size (bytes): 70


bool __fastcall FUN_00563080(int param_1)

{
  SOCKET s;
  int iVar1;
  char local_4 [4];
  
  local_4[0] = '\x01';
  local_4[1] = '\0';
  local_4[2] = '\0';
  local_4[3] = '\0';
  s = socket(2,2,0x11);
  *(SOCKET *)(param_1 + 0x88) = s;
  if (s == 0xffffffff) {
    return true;
  }
  iVar1 = setsockopt(s,0xffff,0x20,local_4,4);
  return iVar1 != 0;
}


