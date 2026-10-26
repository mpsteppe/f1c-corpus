double __cdecl strtod(const char *String, char **EndPtr)
{
  const char *i; // esi
  double *v4; // eax
  int v5; // edx
  double result; // st7
  double v7; // st7
  int *v8; // eax
  _BYTE v9[24]; // [esp+8h] [ebp-20h] BYREF
  double v10; // [esp+20h] [ebp-8h]

  for ( i = String;
        (int)SrcSizeInBytes <= 1
      ? *((_BYTE *)off_625680 + 2 * *(unsigned __int8 *)i) & 8
      : _isctype(*(unsigned __int8 *)i, 8);
        ++i )
  {
    ;
  }
  strlen(i);
  v4 = (double *)_fltin2(v9, i);
  if ( EndPtr )
    *EndPtr = (char *)&i[*((_DWORD *)v4 + 1)];
  v5 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0x240) == 0 )
  {
    if ( (v5 & 0x81) != 0 )
    {
      v7 = dbl_628630;
      if ( *i == 45 )
        v7 = -dbl_628630;
    }
    else
    {
      if ( (v5 & 0x100) == 0 )
        return v4[2];
      v7 = 0.0;
    }
    v10 = v7;
    v8 = _errno();
    result = v10;
    *v8 = 34;
    return result;
  }
  result = 0.0;
  if ( EndPtr )
    *EndPtr = (char *)String;
  return result;
}
