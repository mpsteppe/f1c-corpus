char __thiscall sub_586500(int this)
{
  HANDLE v2; // eax
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+4h] [ebp-Ch] BYREF

  if ( *(_BYTE *)(this + 12) && CloseHandle(*(HANDLE *)(this + 4)) )
    *(_DWORD *)(this + 4) = 0;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v2 = CreateMutexA(&MutexAttributes, 0, 0);
  *(_DWORD *)(this + 4) = v2;
  if ( v2 )
    *(_BYTE *)(this + 12) = 1;
  return *(_BYTE *)(this + 12);
}
