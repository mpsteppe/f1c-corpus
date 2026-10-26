// f1c  0x005968f6  size=312
int __cdecl sub_5968F6(int a1, LCID Locale, LCTYPE LCType, _DWORD *a4)
{
  CHAR *v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // esi
  CHAR *v8; // eax
  _BYTE *v9; // eax
  WCHAR *v11; // esi
  unsigned __int8 v12; // bl
  int v13; // eax
  CHAR LCData[128]; // [esp+Ch] [ebp-80h] BYREF
  int v15; // [esp+94h] [ebp+8h]

  if ( a1 == 1 )
  {
    v4 = LCData;
    v15 = 0;
    v5 = sub_597E4F(Locale, LCType, LCData, 128, 0);
    if ( !v5 )
    {
      if ( GetLastError() != 122 )
        return -1;
      v6 = sub_597E4F(Locale, LCType, 0, 0, 0);
      v7 = v6;
      if ( !v6 )
        return -1;
      v8 = (CHAR *)sub_58A935(v6);
      v4 = v8;
      if ( !v8 )
        return -1;
      v15 = 1;
      v5 = sub_597E4F(Locale, LCType, v8, v7, 0);
      if ( !v5 )
        goto LABEL_9;
    }
    v9 = (_BYTE *)sub_58A935(v5);
    *a4 = v9;
    if ( !v9 )
    {
      if ( !v15 )
        return -1;
LABEL_9:
      sub_58AA6F(v4);
      return -1;
    }
    sub_587DD0(v9, v4, v5);
    if ( v15 )
      sub_58AA6F(v4);
  }
  else
  {
    if ( a1 )
      return -1;
    v11 = &::LCData;
    if ( !sub_597D3C(Locale, LCType, &::LCData, 4, 0) )
      return -1;
    *(_BYTE *)a4 = 0;
    do
    {
      v12 = *(_BYTE *)v11;
      if ( cbMultiByte <= 1 )
        v13 = off_5E69C8[0][v12] & 4;
      else
        v13 = sub_58C674(v12, 4);
      if ( !v13 )
        break;
      ++v11;
      *(_BYTE *)a4 = v12 + 10 * *(_BYTE *)a4 - 48;
    }
    while ( (int)v11 < (int)word_8D41CC );
  }
  return 0;
}
