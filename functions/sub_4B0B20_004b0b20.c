_BYTE *__thiscall sub_4B0B20(char *this, _BYTE *a2, int a3)
{
  int v4; // eax
  _BYTE *result; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  char *v9; // esi
  char v10[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = NullTerminatedStringLengthAt0x11c(dword_7CD25C);
  if ( v4 )
  {
    result = (_BYTE *)sub_587DD0(a2, v4, a3 - 1);
    a2[a3 - 1] = 0;
  }
  else
  {
    *a2 = 0;
    v6 = ShortComputation_0b10(this);
    v7 = (char *)(v10 - v6);
    do
    {
      v8 = *v6;
      v6[(_DWORD)v7] = *v6;
      ++v6;
    }
    while ( v8 );
    v9 = &v10[strlen(v10)];
    if ( v9 > v10 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v10 )
          goto LABEL_10;
      }
      ++v9;
    }
LABEL_10:
    result = (_BYTE *)sub_566810(v9, aPlr);
    if ( result )
      *result = 0;
    if ( v9 )
    {
      result = (_BYTE *)sub_587DD0(a2, v9, a3 - 1);
      a2[a3 - 1] = 0;
    }
  }
  return result;
}
