char __thiscall sub_5865C0(int this)
{
  HANDLE v2; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_BYTE *)(this + 36) && CloseHandle(*(HANDLE *)(this + 28)) )
    *(_DWORD *)(this + 28) = 0;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *(_DWORD *)(this + 28) = v2;
  if ( v2 )
    *(_BYTE *)(this + 36) = 1;
  return *(_BYTE *)(this + 36);
}

