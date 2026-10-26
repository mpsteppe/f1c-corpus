_DWORD *__thiscall sub_5EA670(_DWORD *this)
{
  _DWORD *v1; // edx
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  v1 = (_DWORD *)this[98];
  result = 0;
  if ( v1[156] )
  {
    v4 = (_DWORD *)v1[156];
    if ( !v4 )
      return v1;
    do
    {
      result = v4;
      v4 = (_DWORD *)v4[156];
    }
    while ( v4 );
  }
  else if ( (int)v1[160] > 0 )
  {
    v3 = (_DWORD *)v1[157];
    if ( v3 )
    {
      if ( *v3 )
        return v1;
    }
  }
  return result;
}
