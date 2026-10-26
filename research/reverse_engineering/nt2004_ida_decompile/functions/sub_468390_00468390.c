HANDLE sub_468390()
{
  HANDLE result; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+0h] [ebp-Ch] BYREF

  hMutex = 0;
  byte_764EE8 = 0;
  dwMilliseconds = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  result = CreateMutexA(&MutexAttributes, 0, 0);
  hMutex = result;
  if ( result )
    byte_764EE8 = 1;
  return result;
}
