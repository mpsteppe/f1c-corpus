int __stdcall sub_4E9060(const char *a1)
{
  const char *v1; // ecx
  const char *v2; // eax
  char *v3; // edx
  char v4; // cl
  char *v5; // eax
  int v6; // ebx
  int i; // esi
  const char *v8; // edx
  const char *v9; // ecx
  const char *v10; // eax
  char *v11; // edx
  char v12; // cl
  char *v13; // eax
  char String2[77]; // [esp+Ch] [ebp-A0h] BYREF
  __int16 v16; // [esp+59h] [ebp-53h]
  char v17; // [esp+5Bh] [ebp-51h]
  char String1[77]; // [esp+5Ch] [ebp-50h] BYREF
  __int16 v19; // [esp+A9h] [ebp-3h]
  char v20; // [esp+ABh] [ebp-1h]

  String1[0] = byte_629120;
  memset(&String1[1], 0, 0x4Cu);
  v19 = 0;
  v20 = 0;
  v1 = &a1[strlen(a1)];
  if ( v1 > a1 )
  {
    while ( *v1 != 92 )
    {
      if ( --v1 <= a1 )
        goto LABEL_6;
    }
    ++v1;
  }
LABEL_6:
  v2 = v1;
  v3 = (char *)(String1 - v1);
  do
  {
    v4 = *v2;
    v2[(_DWORD)v3] = *v2;
    ++v2;
  }
  while ( v4 );
  v5 = &String1[strlen(String1)];
  if ( v5 > String1 )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= String1 )
        goto LABEL_13;
    }
    *v5 = 0;
  }
LABEL_13:
  v6 = 0;
  if ( dword_7D6B50 <= 0 )
    return -1;
  for ( i = 0; ; i += 400 )
  {
    String2[0] = byte_629120;
    v8 = (const char *)(i + dword_7D6B58 + 4);
    memset(&String2[1], 0, 0x4Cu);
    v16 = 0;
    v17 = 0;
    v9 = &v8[strlen(v8)];
    if ( v9 > v8 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v8 )
          goto LABEL_20;
      }
      ++v9;
    }
LABEL_20:
    v10 = v9;
    v11 = (char *)(String2 - v9);
    do
    {
      v12 = *v10;
      v10[(_DWORD)v11] = *v10;
      ++v10;
    }
    while ( v12 );
    v13 = &String2[strlen(String2)];
    if ( v13 > String2 )
    {
      while ( *v13 != 46 )
      {
        if ( --v13 <= String2 )
          goto LABEL_27;
      }
      *v13 = 0;
    }
LABEL_27:
    if ( strlen(String2) && !_strnicmp(String1, String2, strlen(String2)) )
      break;
    if ( ++v6 >= dword_7D6B50 )
      return -1;
  }
  return v6;
}
