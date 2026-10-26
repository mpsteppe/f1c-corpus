void *__thiscall sub_40D290(int this)
{
  void *result; // eax
  int v3; // esi
  const char *v4; // eax
  int v5; // esi
  int v6; // edi
  const CHAR *v7; // eax

  result = *(void **)(this + 80);
  v3 = -1;
  if ( result )
  {
    result = (void *)WaitForSingleObject(result, *(_DWORD *)(this + 84));
    if ( !result || result == (void *)128 )
    {
      result = *(void **)(this + 80);
      v3 = *(_DWORD *)(this + 76);
      if ( result )
        result = (void *)ReleaseMutex(*(HANDLE *)(this + 80));
    }
  }
  if ( v3 == 1 )
  {
    sub_40B640();
    v4 = *(const char **)(this + 36);
    if ( !v4 )
      v4 = WindowName;
    if ( !strcmp(v4, WindowName) && *(_DWORD *)(this + 44) == -1 )
    {
      sub_615860(WindowName);
      *(_DWORD *)(this + 24) = -1;
      *(_DWORD *)(this + 28) = -1;
      *(_BYTE *)(this + 32) = 0;
      return (void *)sub_40AD80();
    }
    else
    {
      v5 = this + 24;
      v6 = 2;
      do
      {
        v7 = *(const CHAR **)(v5 + 12);
        if ( !v7 )
          v7 = WindowName;
        sub_615860(v7);
        *(_DWORD *)v5 = *(_DWORD *)(v5 + 20);
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 24);
        *(_BYTE *)(v5 + 8) = *(_BYTE *)(v5 + 28);
        v5 += 20;
        --v6;
      }
      while ( v6 );
      sub_615860(WindowName);
      *(_DWORD *)(this + 64) = -1;
      *(_DWORD *)(this + 68) = -1;
      *(_BYTE *)(this + 72) = 0;
      return (void *)sub_40C810();
    }
  }
  return result;
}
