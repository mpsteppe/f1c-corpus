double __cdecl strtod(const char *String, char **EndPtr)
{
  int v2; // eax
  const char *v3; // esi
  double *v4; // eax
  int v5; // edx
  double result; // st7
  double v7; // st7
  int *v8; // eax
  _BYTE v9[24]; // [esp+8h] [ebp-20h] BYREF
  double v10; // [esp+20h] [ebp-8h]

  v2 = *(unsigned __int8 *)String;
  v3 = String;
  while ( isspace(v2) )
    v2 = *(unsigned __int8 *)++v3;
  sub_6354D0(v3);
  v4 = (double *)_fltin2(v9, v3);
  if ( EndPtr )
    *EndPtr = (char *)&v3[*((_DWORD *)v4 + 1)];
  v5 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0x240) == 0 )
  {
    if ( (v5 & 0x81) != 0 )
    {
      v7 = dbl_9136A4;
      if ( *v3 == 45 )
        v7 = -dbl_9136A4;
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
