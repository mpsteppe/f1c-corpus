int __stdcall sub_4C51A0(int a1, int a2, const char *a3, int a4)
{
  const char *v4; // ecx
  const char *v5; // ecx
  int v6; // esi
  int v7; // edi
  _BYTE *v8; // edx
  char *v9; // eax
  int v10; // edx
  char v11; // cl
  int v12; // esi
  int result; // eax
  _BYTE v14[256]; // [esp+10h] [ebp-100h] BYREF

  v4 = &a3[strlen(a3)];
  if ( v4 > a3 )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= a3 )
        goto LABEL_6;
    }
    *v4 = 0;
  }
LABEL_6:
  v5 = &a3[strlen(a3)];
  if ( v5 > a3 )
  {
    while ( *v5 != 92 )
    {
      if ( --v5 <= a3 )
        goto LABEL_11;
    }
    ++v5;
  }
LABEL_11:
  StringFormatWithBufferOverflowCheck(v14, "%s", v5);
  v6 = 0;
  if ( dword_8AC488 > 0 )
  {
    v7 = a4 + 260;
    do
    {
      if ( !sub_588410(v14, v7) )
        break;
      ++v6;
      v7 += 396;
    }
    while ( v6 < dword_8AC488 );
  }
  if ( v6 == dword_8AC488 )
  {
    v8 = (_BYTE *)(396 * v6 + a4 + 260);
    *v8 = 0;
    v9 = v14;
    v10 = v8 - v14;
    do
    {
      v11 = *v9;
      v9[v10] = *v9;
      ++v9;
    }
    while ( v11 );
    ++dword_8AC488;
  }
  v12 = a4 + 396 * v6;
  strcpy((char *)(v12 + 4), a3);
  SeasonRacesSectionWriter(a3);
  result = SceneFilePathFormatter(a3, 115, 211);
  *(_DWORD *)(v12 + 392) = result;
  return result;
}
