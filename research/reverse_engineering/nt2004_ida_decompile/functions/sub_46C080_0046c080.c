HANDLE __thiscall sub_46C080(int this)
{
  DWORD v2; // eax
  _DWORD *v3; // eax
  char v4; // bl
  DWORD v5; // eax
  _DWORD *v6; // esi
  HANDLE result; // eax

  if ( hMutex && ((v2 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v2 == 128) )
    v3 = &unk_764EDC;
  else
    v3 = 0;
  *v3 = 0;
  if ( hMutex )
    ReleaseMutex(hMutex);
  *(_DWORD *)(this + 404) = CreateThread(0, 0, StartAddress, 0, 0, (LPDWORD)(this + 408));
  do
  {
    Sleep(1u);
    v4 = 0;
    if ( hMutex && ((v5 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v5 == 128) )
      v6 = &unk_764EDC;
    else
      v6 = 0;
    if ( *v6 == 1 )
    {
      v4 = 1;
      sub_46A4A0((CHAR ****)this, 3);
      sub_46A4A0((CHAR ****)this, 4);
      sub_46A4A0((CHAR ****)this, 5);
      *v6 = 2;
    }
    result = hMutex;
    if ( hMutex )
      result = (HANDLE)ReleaseMutex(hMutex);
  }
  while ( !v4 );
  return result;
}
