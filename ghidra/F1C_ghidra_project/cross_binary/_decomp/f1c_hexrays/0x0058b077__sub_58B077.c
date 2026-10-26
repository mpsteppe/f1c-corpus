// f1c  0x0058b077  size=170
double __cdecl sub_58B077(_BYTE *a1, _DWORD *a2)
{
  _BYTE *i; // esi
  double *v4; // eax
  int v5; // edx
  double result; // st7
  double v7; // st7
  _DWORD *v8; // eax
  _BYTE v9[24]; // [esp+8h] [ebp-20h] BYREF
  double v10; // [esp+20h] [ebp-8h]

  for ( i = a1; cbMultiByte <= 1 ? off_5E69C8[0][(unsigned __int8)*i] & 8 : sub_58C674((unsigned __int8)*i, 8); ++i )
    ;
  sub_58E1B0(i);
  v4 = (double *)sub_58E12E(v9, i);
  if ( a2 )
    *a2 = &i[*((_DWORD *)v4 + 1)];
  v5 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0x240) == 0 )
  {
    if ( (v5 & 0x81) != 0 )
    {
      v7 = dbl_5E9990;
      if ( *i == 45 )
        v7 = -dbl_5E9990;
    }
    else
    {
      if ( (v5 & 0x100) == 0 )
        return v4[2];
      v7 = 0.0;
    }
    v10 = v7;
    v8 = (_DWORD *)sub_58AFCF();
    result = v10;
    *v8 = 34;
    return result;
  }
  result = 0.0;
  if ( a2 )
    *a2 = a1;
  return result;
}
