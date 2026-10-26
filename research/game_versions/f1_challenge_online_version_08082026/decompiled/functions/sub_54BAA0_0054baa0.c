_DWORD *__thiscall sub_54BAA0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  _DWORD *result; // eax
  int v4; // ecx
  _DWORD *i; // ecx

  v2 = a2[18];
  if ( v2 )
    *(_DWORD *)(v2 + 76) = a2[19];
  result = (_DWORD *)a2[19];
  if ( result )
    result[18] = a2[18];
  if ( (_DWORD *)this[17] == a2 )
  {
    result = (_DWORD *)a2[19];
    this[17] = result;
    if ( result )
      result[18] = 0;
  }
  if ( dword_8B8F28 )
  {
    v4 = *(_DWORD *)(dword_8B8F28 + 264);
    result = 0;
    if ( v4 )
    {
      result = *(_DWORD **)(dword_8B8F28 + 264);
      for ( i = *(_DWORD **)(v4 + 76); i; i = (_DWORD *)i[19] )
        result = i;
      result[19] = a2;
    }
    else
    {
      *(_DWORD *)(dword_8B8F28 + 264) = a2;
    }
    a2[18] = result;
    a2[19] = 0;
  }
  if ( a2[140] )
  {
    result = (_DWORD *)a2[16];
    if ( result )
    {
      if ( result[140] )
        result = (_DWORD *)sub_560F40(a2[140]);
    }
  }
  a2[16] = 0;
  return result;
}
