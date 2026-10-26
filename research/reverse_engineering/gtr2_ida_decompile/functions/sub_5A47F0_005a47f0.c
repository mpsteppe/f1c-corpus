int __thiscall sub_5A47F0(int this)
{
  int i; // esi
  int result; // eax
  void *v4; // eax
  DWORD v5; // eax
  _BYTE *v6; // eax
  void *v7; // esi

  for ( i = 0; i < 10; ++i )
  {
    if ( sub_5A4030(this) )
      break;
    Sleep(0xFAu);
  }
  result = *(_DWORD *)(this + 8);
  if ( result )
  {
    v4 = *(void **)(this + 20);
    if ( v4 && ((v5 = WaitForSingleObject(v4, *(_DWORD *)(this + 24))) == 0 || v5 == 128) )
      v6 = (_BYTE *)(this + 16);
    else
      v6 = 0;
    *v6 = 1;
    v7 = *(void **)(this + 20);
    if ( v7 )
      ReleaseMutex(v7);
    WaitForSingleObject(*(HANDLE *)(this + 8), 0xFFFFFFFF);
    result = CloseHandle(*(HANDLE *)(this + 8));
    *(_DWORD *)(this + 8) = 0;
    *(_DWORD *)(this + 12) = 0;
  }
  return result;
}
