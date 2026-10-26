HANDLE __thiscall sub_4887A0(DWORD *this)
{
  DWORD v2; // eax
  _DWORD *v3; // eax
  char v4; // bl
  DWORD v5; // eax
  _DWORD *v6; // edi
  HANDLE result; // eax

  if ( hMutex && ((v2 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v2 == 128) )
    v3 = &unk_759EA8;
  else
    v3 = 0;
  *v3 = 0;
  if ( hMutex )
    ReleaseMutex(hMutex);
  this[213] = (DWORD)CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_487D50, 0, 0, this + 214);
  do
  {
    Sleep(1u);
    v4 = 0;
    if ( hMutex && ((v5 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v5 == 128) )
      v6 = &unk_759EA8;
    else
      v6 = 0;
    if ( *v6 == 1 )
    {
      v4 = 1;
      sub_4804E0();
      sub_4804E0();
      sub_4804E0();
      sub_4804E0();
      *v6 = 2;
    }
    result = hMutex;
    if ( hMutex )
      result = (HANDLE)ReleaseMutex(hMutex);
  }
  while ( !v4 );
  return result;
}
