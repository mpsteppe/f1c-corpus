int __thiscall sub_5A78B0(_DWORD *this)
{
  _DWORD *v2; // esi
  _DWORD *i; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // esi
  _DWORD *j; // eax
  int v8; // eax
  int v9; // eax
  _DWORD *v10; // esi
  _DWORD *k; // eax
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // esi
  _DWORD *m; // eax
  int v16; // eax
  int v17; // eax

  if ( this[1296] )
  {
    v2 = (_DWORD *)this[1133];
    if ( v2 )
    {
      for ( i = (_DWORD *)v2[7]; i; i = (_DWORD *)v2[7] )
      {
        v2 = i;
        v4 = *(_DWORD *)(i[6] + 32);
        if ( v4 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
        if ( v2[6] )
          sub_5BE8AE();
      }
      v5 = v2[8];
      if ( v5 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(v2[8]);
      sub_5BE8AE();
      this[1133] = 0;
    }
    v6 = (_DWORD *)this[1135];
    if ( v6 )
    {
      for ( j = (_DWORD *)v6[7]; j; j = (_DWORD *)v6[7] )
      {
        v6 = j;
        v8 = *(_DWORD *)(j[6] + 32);
        if ( v8 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
        if ( v6[6] )
          sub_5BE8AE();
      }
      v9 = v6[8];
      if ( v9 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(v6[8]);
      sub_5BE8AE();
      this[1135] = 0;
    }
    v10 = (_DWORD *)this[1137];
    if ( v10 )
    {
      for ( k = (_DWORD *)v10[5]; k; k = (_DWORD *)v10[5] )
      {
        v10 = k;
        v12 = *(_DWORD *)(k[4] + 24);
        if ( v12 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v12 + 8))(v12);
        if ( v10[4] )
          sub_5BE8AE();
      }
      v13 = v10[6];
      if ( v13 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 8))(v10[6]);
      sub_5BE8AE();
      this[1137] = 0;
    }
    v14 = (_DWORD *)this[1139];
    if ( v14 )
    {
      for ( m = (_DWORD *)v14[5]; m; m = (_DWORD *)v14[5] )
      {
        v14 = m;
        v16 = *(_DWORD *)(m[4] + 24);
        if ( v16 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
        if ( v14[4] )
          sub_5BE8AE();
      }
      v17 = v14[6];
      if ( v17 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v17 + 8))(v14[6]);
      sub_5BE8AE();
      this[1139] = 0;
    }
  }
  return 0;
}
