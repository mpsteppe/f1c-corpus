int __thiscall sub_40C3B0(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  const char *v5; // esi
  char *v6; // eax
  char v7; // cl
  int v8; // ecx
  char *i; // eax
  const char *v10; // ecx
  const char *v11; // eax
  char *v12; // edx
  char v13; // cl
  char *v14; // eax
  char v16[64]; // [esp+4h] [ebp-240h] BYREF
  char v17[512]; // [esp+44h] [ebp-200h] BYREF

  if ( !this[8] )
  {
    v2 = (_DWORD *)sub_587C03(24);
    if ( v2 )
      v3 = sub_40B560(v2);
    else
      v3 = 0;
    this[8] = v3;
  }
  v4 = dword_8AC490 + 396 * dword_8AC48C;
  if ( v4 )
  {
    v5 = (const char *)(v4 + 4);
    v6 = (char *)(v4 + 4);
    do
    {
      v7 = *v6;
      v6[v17 - v5] = *v6;
      ++v6;
    }
    while ( v7 );
    v8 = strlen(v17);
    if ( v8 > 0 )
    {
      for ( i = &v16[v8 + 63]; i >= v17; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v10 = &v5[strlen(v5)];
    if ( v10 > v5 )
    {
      while ( *v10 != 92 )
      {
        if ( --v10 <= v5 )
          goto LABEL_18;
      }
      ++v10;
    }
LABEL_18:
    v11 = v10;
    v12 = (char *)(v16 - v10);
    do
    {
      v13 = *v11;
      v11[(_DWORD)v12] = *v11;
      ++v11;
    }
    while ( v13 );
    v14 = &v16[strlen(v16)];
    if ( v14 > v16 )
    {
      while ( *v14 != 46 )
      {
        if ( --v14 <= v16 )
          goto LABEL_25;
      }
      *v14 = 0;
    }
LABEL_25:
    strcat(v16, aCam);
    strcat(v17, v16);
    (*(void (__thiscall **)(_DWORD, char *))(*(_DWORD *)this[8] + 4))(this[8], v17);
  }
  return 0;
}
