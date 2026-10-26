int __cdecl sub_58FD90(_BYTE *a1, _WORD *a2, int a3)
{
  _BYTE *v3; // eax
  int v4; // edi

  if ( !dword_8D3FB8 )
  {
    if ( sub_5904C1() )
      dword_8D3FB8 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))GetLocaleInfoA;
    else
      dword_8D3FB8 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))sub_5904F7;
  }
  if ( !a1 )
    goto LABEL_20;
  dword_8D3FA8 = (int)a1;
  if ( *a1 )
    sub_58FF0D(&off_5E72D0, 64, &dword_8D3FA8);
  v3 = a1 + 64;
  dword_8D3FAC = (int)(a1 + 64);
  if ( a1 != (_BYTE *)-64 && *v3 )
  {
    sub_58FF0D(&off_5E7218, 22, &dword_8D3FAC);
    v3 = (_BYTE *)dword_8D3FAC;
  }
  dword_8D3FB0 = 0;
  if ( !dword_8D3FA8 || !*(_BYTE *)dword_8D3FA8 )
  {
    if ( v3 && *v3 )
    {
      sub_590303();
      goto LABEL_21;
    }
LABEL_20:
    sub_5903C0();
    goto LABEL_21;
  }
  if ( v3 && *v3 )
    sub_58FF65();
  else
    sub_5901F0();
LABEL_21:
  if ( dword_8D3FB0 )
  {
    v4 = sub_5903DA(a1 + 128);
    if ( v4 )
    {
      if ( IsValidCodePage((unsigned __int16)v4) && IsValidLocale(Locale, 1u) )
      {
        if ( a2 )
        {
          *a2 = Locale;
          a2[1] = dword_8D3FB4;
          a2[2] = v4;
        }
        if ( !a3 )
          return 1;
        if ( dword_8D3FB8(Locale, 4097, a3, 64) && dword_8D3FB8(dword_8D3FB4, 4098, a3 + 64, 64) )
        {
          sub_596BF3(v4, a3 + 128, 10);
          return 1;
        }
      }
    }
  }
  return 0;
}
