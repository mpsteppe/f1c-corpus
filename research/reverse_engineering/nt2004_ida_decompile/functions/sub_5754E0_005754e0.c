HANDLE __thiscall sub_5754E0(char *lpParameter)
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
    result = (HANDLE)*((_DWORD *)v3 + 1);
    if ( !result && !i && sub_573E00 )
    {
      v5 = (void *)*((_DWORD *)v3 + 4);
      if ( v5 && ((v6 = WaitForSingleObject(v5, *((_DWORD *)v3 + 5))) == 0 || v6 == 128) )
        v7 = v3 + 12;
      else
        v7 = 0;
      *v7 = 0;
      v8 = (void *)*((_DWORD *)v3 + 4);
      if ( v8 )
        ReleaseMutex(v8);
      v9 = (void *)*((_DWORD *)v3 + 8);
      if ( v9 && ((v10 = WaitForSingleObject(v9, *((_DWORD *)v3 + 9))) == 0 || v10 == 128) )
        v11 = v3 + 28;
      else
        v11 = 0;
      *v11 = 1;
      v12 = (void *)*((_DWORD *)v3 + 8);
      if ( v12 )
        ReleaseMutex(v12);
      result = CreateThread(0, 0, sub_573E00, lpParameter, 4u, (LPDWORD)v3 + 2);
      *((_DWORD *)v3 + 1) = result;
      if ( result )
        result = (HANDLE)SetThreadPriority(result, 1);
    }
  }
  return result;
}
