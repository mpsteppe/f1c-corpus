_DWORD *__thiscall sub_499F70(int this, int a2, int a3, int a4, int a5, const char *a6, char a7, char a8, _DWORD *a9)
{
  _DWORD *result; // eax
  int v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  _DWORD *v17; // edx
  _DWORD *i; // ecx
  int j; // ecx
  CHAR Text[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( !a6 )
    return 0;
  v11 = sub_497AD0(*(_DWORD **)(this + 4), a6, 0);
  if ( v11 )
  {
    v12 = (_DWORD *)OperatorNewNhMallocWrapper(52);
    if ( v12 )
      result = sub_499B10(v12);
    else
      result = 0;
    result[1] = a5;
    result[3] = a3;
    *result = a4;
    result[2] = a2;
    result[9] = 0;
    result[8] = v11;
    if ( a7 )
    {
      result[2] = 0;
      *result = 0;
      result[1] = *(_DWORD *)(*(_DWORD *)(v11 + 12) + 28);
      result[3] = *(_DWORD *)(*(_DWORD *)(v11 + 12) + 32);
    }
    if ( a9 && (v13 = *(_DWORD **)(this + 8)) != 0 )
    {
      while ( v13 != a9 )
      {
        v13 = (_DWORD *)v13[9];
        if ( !v13 )
          goto LABEL_16;
      }
      v16 = a9[6];
      ++a9[4];
      result[6] = v16;
      v17 = a9;
      if ( a9[10] )
      {
        for ( i = (_DWORD *)a9[10]; i; i = (_DWORD *)i[10] )
          v17 = i;
        v17[10] = result;
      }
      else
      {
        a9[10] = result;
      }
    }
    else
    {
LABEL_16:
      v14 = *(_DWORD *)(this + 8);
      if ( v14 )
      {
        for ( j = *(_DWORD *)(v14 + 36); j; j = *(_DWORD *)(j + 36) )
          v14 = j;
        *(_DWORD *)(v14 + 36) = result;
        ++*(_DWORD *)(this + 12);
      }
      else
      {
        v15 = *(_DWORD *)(this + 12) + 1;
        *(_DWORD *)(this + 8) = result;
        *(_DWORD *)(this + 12) = v15;
      }
    }
  }
  else
  {
    if ( a8 )
    {
      StringFormatWithBufferOverflowCheck(Text, "Could not load \"%s\"", a6);
      MessageBoxA(0, Text, aOptionsFrameAd, 0);
    }
    return 0;
  }
  return result;
}

