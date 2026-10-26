_DWORD *__thiscall sub_4B0F90(int this, int a2, int a3, int a4, int a5, char *String2, char a7, char a8, _DWORD *a9)
{
  _DWORD *result; // eax
  int v11; // esi
  _DWORD *v12; // eax
  int v13; // ecx
  _DWORD *v14; // edx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  _DWORD *v18; // edx
  _DWORD *i; // ecx
  int j; // ecx
  CHAR Text[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( !String2 )
    return 0;
  v11 = sub_4AD970(*(_DWORD **)(this + 4), String2, 0, 0, 1);
  if ( v11 )
  {
    v12 = operator new(0x28u);
    if ( v12 )
      result = sub_4B0A90(v12);
    else
      result = 0;
    result[1] = a5;
    result[3] = a3;
    *result = a4;
    result[2] = a2;
    result[8] = 0;
    result[7] = v11;
    if ( a7 )
    {
      result[2] = 0;
      *result = 0;
      v13 = *(_DWORD *)(v11 + 24);
      result[1] = *(_DWORD *)(v11 + 20);
      result[3] = v13;
    }
    if ( a9 && (v14 = *(_DWORD **)(this + 8)) != 0 )
    {
      while ( v14 != a9 )
      {
        v14 = (_DWORD *)v14[8];
        if ( !v14 )
          goto LABEL_16;
      }
      v17 = a9[5];
      ++a9[4];
      result[5] = v17;
      v18 = a9;
      if ( a9[9] )
      {
        for ( i = (_DWORD *)a9[9]; i; i = (_DWORD *)i[9] )
          v18 = i;
        v18[9] = result;
      }
      else
      {
        a9[9] = result;
      }
    }
    else
    {
LABEL_16:
      v15 = *(_DWORD *)(this + 8);
      if ( v15 )
      {
        for ( j = *(_DWORD *)(v15 + 32); j; j = *(_DWORD *)(j + 32) )
          v15 = j;
        *(_DWORD *)(v15 + 32) = result;
        ++*(_DWORD *)(this + 12);
      }
      else
      {
        v16 = *(_DWORD *)(this + 12) + 1;
        *(_DWORD *)(this + 8) = result;
        *(_DWORD *)(this + 12) = v16;
      }
    }
  }
  else
  {
    if ( a8 )
    {
      sprintf(Text, "Could not load \"%s\"", String2);
      MessageBoxA(0, Text, aOptionsFrameAd, 0);
    }
    return 0;
  }
  return result;
}
