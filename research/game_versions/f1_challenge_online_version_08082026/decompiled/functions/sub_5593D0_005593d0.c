void __thiscall sub_5593D0(_DWORD *this)
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

  v2 = (_DWORD *)*this;
  if ( *this )
  {
    for ( i = (_DWORD *)v2[7]; i; i = (_DWORD *)v2[7] )
    {
      v4 = v2;
      v5 = v2 == 0;
      v2 = i;
      if ( !v5 )
      {
        j_nullsub_3(v4);
        sub_587BCF(v4);
      }
    }
    j_nullsub_3(v2);
    sub_587BCF(v2);
    *this = 0;
  }
  v6 = (_DWORD *)this[1];
  if ( v6 )
  {
    for ( j = (_DWORD *)v6[7]; j; j = (_DWORD *)v6[7] )
    {
      v8 = v6;
      v5 = v6 == 0;
      v6 = j;
      if ( !v5 )
      {
        j_nullsub_3(v8);
        sub_587BCF(v8);
      }
    }
    j_nullsub_3(v6);
    sub_587BCF(v6);
    this[1] = 0;
  }
  v9 = (_DWORD *)this[2];
  if ( v9 )
  {
    for ( k = (_DWORD *)v9[7]; k; k = (_DWORD *)v9[7] )
    {
      v11 = v9;
      v5 = v9 == 0;
      v9 = k;
      if ( !v5 )
      {
        j_nullsub_3(v11);
        sub_587BCF(v11);
      }
    }
    j_nullsub_3(v9);
    sub_587BCF(v9);
    this[2] = 0;
  }
}
