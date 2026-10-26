char __thiscall sub_582720(int this)
{
  HANDLE v2; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_BYTE *)(this + 40) && CloseHandle(*(HANDLE *)(this + 32)) )
    *(_DWORD *)(this + 32) = 0;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *(_DWORD *)(this + 32) = v2;
  if ( v2 )
    *(_BYTE *)(this + 40) = 1;
  return *(_BYTE *)(this + 40);
}
