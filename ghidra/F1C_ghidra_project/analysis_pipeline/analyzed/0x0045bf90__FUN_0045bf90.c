// Function: FUN_0045bf90 @ 0045bf90
// Size (bytes): 89


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045bf90(void)

{
  _SECURITY_ATTRIBUTES local_c;
  
  DAT_007cd264 = (HANDLE)0x0;
  DAT_007cd26c = 0;
  _DAT_007cd268 = 0xffffffff;
  local_c.nLength = 0xc;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  DAT_007cd264 = CreateMutexA(&local_c,0,(LPCSTR)0x0);
  if (DAT_007cd264 != (HANDLE)0x0) {
    DAT_007cd26c = 1;
  }
  return;
}


