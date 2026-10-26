HANDLE sub_45D330()
{
  HANDLE result; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+0h] [ebp-Ch] BYREF

  dword_764D78 = 0;
  byte_764D80 = 0;
  dword_764D7C = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  result = CreateMutexA(&MutexAttributes, 0, 0);
  dword_764D78 = result;
  if ( result )
    byte_764D80 = 1;
  return result;
}
