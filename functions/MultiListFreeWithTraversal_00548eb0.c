void __thiscall sub_548EB0(_DWORD *this)
{
  _DWORD *v2; // esi
  _DWORD *i; // eax
  void *v4; // edi
  bool v5; // zf
  _DWORD *v6; // esi
  _DWORD *j; // eax
  void *v8; // edi
  _DWORD *v9; // esi
  _DWORD *k; // eax
  void *v11; // edi
  _DWORD *v12; // esi
  _DWORD *m; // eax
  void *v14; // edi
  int v15; // esi
  int n; // eax
  int v17; // [esp-4h] [ebp-14h]

  v2 = (_DWORD *)this[58];
  if ( v2 )
  {
    for ( i = (_DWORD *)v2[5]; i; i = (_DWORD *)v2[5] )
    {
      v4 = v2;
      v5 = v2 == 0;
      v2 = i;
      if ( !v5 )
      {
        EmptyStub_0170();
        FreeWrapper_7bcf(v4);
      }
    }
    EmptyStub_0170();
    FreeWrapper_7bcf(v2);
    this[58] = 0;
  }
  v6 = (_DWORD *)this[60];
  if ( v6 )
  {
    for ( j = (_DWORD *)v6[13]; j; j = (_DWORD *)v6[13] )
    {
      v8 = v6;
      v5 = v6 == 0;
      v6 = j;
      if ( !v5 )
      {
        EmptyStub_0170();
        FreeWrapper_7bcf(v8);
      }
    }
    EmptyStub_0170();
    FreeWrapper_7bcf(v6);
    this[60] = 0;
  }
  v9 = (_DWORD *)this[62];
  if ( v9 )
  {
    for ( k = (_DWORD *)v9[5]; k; k = (_DWORD *)v9[5] )
    {
      v11 = v9;
      v5 = v9 == 0;
      v9 = k;
      if ( !v5 )
      {
        EmptyStub_0170();
        FreeWrapper_7bcf(v11);
      }
    }
    EmptyStub_0170();
    FreeWrapper_7bcf(v9);
    this[62] = 0;
  }
  v12 = (_DWORD *)this[63];
  if ( v12 )
  {
    for ( m = (_DWORD *)v12[5]; m; m = (_DWORD *)v12[5] )
    {
      v14 = v12;
      v5 = v12 == 0;
      v12 = m;
      if ( !v5 )
      {
        EmptyStub_0170();
        FreeWrapper_7bcf(v14);
      }
    }
    EmptyStub_0170();
    FreeWrapper_7bcf(v12);
    this[63] = 0;
  }
  v15 = this[59];
  if ( v15 )
  {
    for ( n = *(_DWORD *)(v15 + 76); n; n = *(_DWORD *)(v15 + 76) )
    {
      v17 = v15;
      v15 = n;
      sub_549110(v17);
    }
    sub_549110(v15);
    this[59] = 0;
  }
}
