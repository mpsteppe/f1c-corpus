int __stdcall sub_6029C0(int *a1, char a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  unsigned int v6; // edi
  int v7; // eax
  int v8; // esi
  unsigned int v9; // edi
  _DWORD v11[8]; // [esp+28h] [ebp-20h] BYREF

  memset(v11, 0, sizeof(v11));
  if ( (a2 & 1) != 0 )
  {
    v2 = sub_5E7120(a1, 1);
    if ( (*(_BYTE *)a1 & 1) != 0 )
    {
      if ( v2 )
        (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v2 + 48))(v2, v11);
    }
  }
  if ( (a2 & 2) != 0 )
  {
    v3 = sub_5E7120(a1, 2);
    if ( (*(_BYTE *)a1 & 2) != 0 )
    {
      if ( v3 )
        (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v3 + 48))(v3, v11);
    }
  }
  if ( (a2 & 4) != 0 )
  {
    v4 = sub_5E7150(a1, 4);
    v5 = v4;
    if ( (*(_BYTE *)a1 & 4) != 0 )
    {
      if ( v4 )
      {
        v6 = 0;
        if ( (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 52))(v4) )
        {
          do
            (*(void (__stdcall **)(int, unsigned int, _DWORD *))(*(_DWORD *)v5 + 68))(v5, v6++, v11);
          while ( v6 < (*(int (__stdcall **)(int))(*(_DWORD *)v5 + 52))(v5) );
        }
      }
    }
  }
  if ( (a2 & 8) != 0 )
  {
    v7 = sub_5E7150(a1, 8);
    v8 = v7;
    if ( (*(_BYTE *)a1 & 8) != 0 )
    {
      if ( v7 )
      {
        v9 = 0;
        if ( (*(int (__stdcall **)(int))(*(_DWORD *)v7 + 52))(v7) )
        {
          do
            (*(void (__stdcall **)(int, unsigned int, _DWORD *))(*(_DWORD *)v8 + 68))(v8, v9++, v11);
          while ( v9 < (*(int (__stdcall **)(int))(*(_DWORD *)v8 + 52))(v8) );
        }
      }
    }
  }
  return 0;
}
