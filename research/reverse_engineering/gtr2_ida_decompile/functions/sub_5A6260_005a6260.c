HANDLE __thiscall sub_5A6260(char *lpParameter)
{
  int i; // ebx
  char *v3; // edi
  HANDLE result; // eax
  void *v5; // eax
  DWORD v6; // eax
  _BYTE *v7; // eax
  void *v8; // esi
  void *v9; // eax
  DWORD v10; // eax
  _BYTE *v11; // eax
  void *v12; // esi

  for ( i = 0; i < 1; ++i )
  {
    v3 = &lpParameter[40 * i];
    result = (HANDLE)*((_DWORD *)v3 + 2);
    if ( !result && !i && StartAddress )
    {
      v5 = (void *)*((_DWORD *)v3 + 5);
      if ( v5 && ((v6 = WaitForSingleObject(v5, *((_DWORD *)v3 + 6))) == 0 || v6 == 128) )
        v7 = v3 + 16;
      else
        v7 = 0;
      *v7 = 0;
      v8 = (void *)*((_DWORD *)v3 + 5);
      if ( v8 )
        ReleaseMutex(v8);
      v9 = (void *)*((_DWORD *)v3 + 9);
      if ( v9 && ((v10 = WaitForSingleObject(v9, *((_DWORD *)v3 + 10))) == 0 || v10 == 128) )
        v11 = v3 + 32;
      else
        v11 = 0;
      *v11 = 1;
      v12 = (void *)*((_DWORD *)v3 + 9);
      if ( v12 )
        ReleaseMutex(v12);
      result = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, lpParameter, 4u, (LPDWORD)v3 + 3);
      *((_DWORD *)v3 + 2) = result;
      if ( result )
        result = (HANDLE)SetThreadPriority(result, 1);
    }
  }
  return result;
}
