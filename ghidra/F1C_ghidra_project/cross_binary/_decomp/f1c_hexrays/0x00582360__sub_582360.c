// f1c  0x00582360  size=92
char __thiscall sub_582360(int this)
{
  HANDLE v2; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_BYTE *)(this + 24) && CloseHandle(*(HANDLE *)(this + 16)) )
    *(_DWORD *)(this + 16) = 0;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *(_DWORD *)(this + 16) = v2;
  if ( v2 )
    *(_BYTE *)(this + 24) = 1;
  return *(_BYTE *)(this + 24);
}
