int __cdecl wctomb(char *MbCh, wchar_t WCh)
{
  int v2; // ebx
  int WCha; // [esp+18h] [ebp+Ch]

  InterlockedIncrement(&dword_80151C);
  v2 = 0;
  if ( dword_801518 )
  {
    InterlockedDecrement(&dword_80151C);
    _lock(19);
    v2 = 1;
  }
  WCha = _wctomb_lk(MbCh, WCh);
  if ( v2 )
    _unlock(19);
  else
    InterlockedDecrement(&dword_80151C);
  return WCha;
}
