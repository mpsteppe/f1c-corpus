char *__thiscall sub_44E520(_DWORD *this, int a2)
{
  _DWORD *v2; // ebp
  const char *v3; // edx
  const char *v4; // esi
  CHAR *v5; // eax
  const char *v6; // edx
  const char *v7; // ecx
  char *v8; // ecx
  __time32_t v9; // eax
  char *v10; // ecx
  __time32_t v11; // esi
  const char *v12; // ecx
  char *v13; // eax
  char *v14; // ecx
  int v15; // edx
  char v16; // al
  char *v17; // eax
  CHAR *v18; // eax
  unsigned int v19; // kr0C_4
  CHAR *i; // eax
  size_t v21; // esi
  unsigned int v22; // kr10_4
  signed int v23; // ecx
  char *v24; // eax
  char *result; // eax
  char *v26; // [esp+Ch] [ebp-62Ch]
  int v28[5]; // [esp+24h] [ebp-614h] BYREF
  char Str[256]; // [esp+38h] [ebp-600h] BYREF
  char FileName[256]; // [esp+138h] [ebp-500h] BYREF
  char Destination[1024]; // [esp+238h] [ebp-400h] BYREF

  v2 = this;
  if ( dword_7E8E58 )
    sub_590140(2, 0);
  sub_44E8B0(v2);
  sub_44E870();
  v3 = dword_766578;
  if ( !dword_766578 )
    v3 = &byte_629120;
  v4 = &v3[strlen(v3)];
  if ( v4 > v3 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= v3 )
        goto LABEL_10;
    }
    ++v4;
  }
LABEL_10:
  v26 = (char *)operator new(0x100u);
  *v26 = 0;
  v5 = dword_62A0C8;
  if ( !dword_62A0C8 )
    v5 = &byte_629120;
  sub_578600(v5);
  sub_578560(aHat);
  sub_578560(v4);
  v6 = v26;
  if ( !v26 )
    v6 = &byte_629120;
  v7 = &v6[strlen(v6)];
  if ( v7 > v6 )
  {
    while ( *v7 != 46 )
    {
      if ( --v7 <= v6 )
        goto LABEL_19;
    }
    *v7 = 0;
  }
LABEL_19:
  sub_578560(aHat_0);
  if ( byte_7682DC )
    goto LABEL_36;
  v8 = v26;
  if ( !v26 )
    v8 = &byte_629120;
  v9 = sub_44BE60(v8);
  v10 = dword_766578;
  v11 = v9;
  if ( !dword_766578 )
    v10 = &byte_629120;
  if ( sub_44BE60(v10) >= v9 )
    goto LABEL_36;
  v12 = dword_766578;
  if ( !dword_766578 )
    v12 = &byte_629120;
  strcpy(Str, v12);
  _strupr(Str);
  v13 = strstr(Str, aScn_0);
  if ( !v13 )
    goto LABEL_36;
  v14 = aMas;
  v15 = v13 - aMas;
  do
  {
    v16 = *v14;
    v14[v15] = *v14;
    ++v14;
  }
  while ( v16 );
  if ( sub_44BE60(Str) >= v11 )
    goto LABEL_36;
  sub_4F6A10(FileName, 256);
  if ( sub_44BE60(FileName) >= v11 )
    goto LABEL_36;
  v17 = v26;
  if ( !v26 )
    v17 = &byte_629120;
  if ( sub_44E2B0(v2, v17) )
  {
    sub_44E8B0(v2);
LABEL_36:
    v18 = v26;
    if ( !v26 )
      v18 = &byte_629120;
    sub_578600(v18);
    v19 = strlen(&byte_629120) + 1;
    if ( (int)(v19 - 1) > 0 )
    {
      for ( i = &byte_629120 + v19 - 2; i >= &byte_629120; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v21 = 0;
    v22 = strlen(&byte_629120) + 1;
    v23 = v22 - 1;
    if ( (int)(v22 - 1) > 0 )
    {
      do
      {
        if ( v21 >= 0x400 )
          break;
        if ( Destination[v21 + &byte_629120 - Destination] == 92 )
        {
          strncpy(Destination, &byte_629120, v21);
          Destination[v21] = 0;
          _mkdir(Destination);
          v23 = v22 - 1;
        }
        ++v21;
      }
      while ( (int)v21 < v23 );
      v2 = this;
    }
    _mkdir(&byte_629120);
    sub_44B6F0(v28);
    sub_44DFA0(v2, a2, (char **)v28);
    sub_44DD50((int)v2, v28);
    v24 = v26;
    if ( !v26 )
      v24 = &byte_629120;
    sub_44E090(v2, v24, v28);
    sub_44B780(v28);
  }
  sub_44DE80((int)v2);
  if ( dword_7E8E58 )
    sub_590140(1, 0);
  result = v26;
  if ( v26 )
    return (char *)sub_5BE8AE(v26);
  return result;
}
