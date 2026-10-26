// f1c  0x005862c0  size=92
char __thiscall sub_5862C0(int this)
{
  HANDLE v2; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_BYTE *)(this + 88) && CloseHandle(*(HANDLE *)(this + 80)) )
    *(_DWORD *)(this + 80) = 0;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *(_DWORD *)(this + 80) = v2;
  if ( v2 )
    *(_BYTE *)(this + 88) = 1;
  return *(_BYTE *)(this + 88);
}
