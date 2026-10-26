void __thiscall sub_575F10(_BYTE *this)
{
  HANDLE v2; // eax
  HANDLE v3; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+Ch] [ebp-Ch] BYREF

  this[8] = 0;
  *((_DWORD *)this + 3) = 0;
  this[20] = 0;
  *((_DWORD *)this + 4) = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *((_DWORD *)this + 3) = v2;
  if ( v2 )
    this[20] = 1;
  this[24] = 0;
  *((_DWORD *)this + 7) = 0;
  this[36] = 0;
  *((_DWORD *)this + 8) = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v3 = CreateMutexA(&MutexAttributes, 0, 0);
  *((_DWORD *)this + 7) = v3;
  if ( v3 )
    this[36] = 1;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
}
