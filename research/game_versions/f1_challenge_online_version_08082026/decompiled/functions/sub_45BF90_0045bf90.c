HANDLE sub_45BF90()
{
  HANDLE result; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+0h] [ebp-Ch] BYREF

  dword_7CD264 = 0;
  byte_7CD26C = 0;
  dword_7CD268 = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  result = CreateMutexA(&MutexAttributes, 0, 0);
  dword_7CD264 = (int)result;
  if ( result )
    byte_7CD26C = 1;
  return result;
}
