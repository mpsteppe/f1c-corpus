_DWORD *__thiscall sub_5B87A0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int i; // eax
  int v7; // ecx
  _DWORD *result; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // esi

  v2 = a2[13];
  v3 = 0;
  if ( v2 )
    *(_DWORD *)(v2 + 56) = a2[14];
  v4 = a2[14];
  if ( v4 )
    *(_DWORD *)(v4 + 52) = a2[13];
  v5 = this[12];
  if ( v5 )
  {
    v3 = this[12];
    for ( i = *(_DWORD *)(v5 + 56); i; i = *(_DWORD *)(i + 56) )
      v3 = i;
    *(_DWORD *)(v3 + 56) = a2;
  }
  else
  {
    this[12] = a2;
  }
  v7 = a2[10] | 4;
  a2[13] = v3;
  a2[14] = 0;
  a2[10] = v7;
  result = (_DWORD *)dword_7E8E5C;
  v9 = *(_DWORD **)(dword_7E8E5C + 360);
  if ( v9 )
  {
    result = (_DWORD *)v9[1];
    if ( result )
    {
      while ( (_DWORD *)*result != a2 )
      {
        v9 = result;
        result = (_DWORD *)result[1];
        if ( !result )
          return result;
      }
      v10 = (_DWORD *)v9[1];
      v9[1] = v10[1];
      if ( v10 )
      {
        nullsub_6(v10);
        sub_5BE8AE();
      }
      result = (_DWORD *)dword_7E8E5C;
      --*(_DWORD *)(dword_7E8E5C + 356);
    }
  }
  return result;
}
