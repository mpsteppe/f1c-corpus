int __thiscall sub_585550(int this)
{
  int i; // esi
  int result; // eax
  void *v4; // eax
  DWORD v5; // eax
  _BYTE *v6; // eax
  void *v7; // esi

  for ( i = 0; i < 10; ++i )
  {
    if ( (unsigned __int8)ThreadResumeWithMutexWait(this) )
      break;
    Sleep(0xFAu);
  }
  result = *(_DWORD *)(this + 4);
  if ( result )
  {
    v4 = *(void **)(this + 16);
    if ( v4 && ((v5 = WaitForSingleObject(v4, *(_DWORD *)(this + 20))) == 0 || v5 == 128) )
      v6 = (_BYTE *)(this + 12);
    else
      v6 = 0;
    *v6 = 1;
    v7 = *(void **)(this + 16);
    if ( v7 )
      ReleaseMutex(v7);
    WaitForSingleObject(*(HANDLE *)(this + 4), 0xFFFFFFFF);
    result = CloseHandle(*(HANDLE *)(this + 4));
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 8) = 0;
  }
  return result;
}
