int __stdcall sub_4C5690(const char *a1)
{
  const char *v1; // ecx
  const char *v2; // eax
  char *v3; // edx
  char v4; // cl
  char *v5; // eax
  int result; // eax
  int v7; // ebx
  int i; // esi
  const char *v9; // edx
  const char *v10; // ecx
  const char *v11; // eax
  char *v12; // edx
  char v13; // cl
  char *v14; // eax
  char v15[77]; // [esp+Ch] [ebp-A0h] BYREF
  __int16 v16; // [esp+59h] [ebp-53h]
  char v17; // [esp+5Bh] [ebp-51h]
  char v18[77]; // [esp+5Ch] [ebp-50h] BYREF
  __int16 v19; // [esp+A9h] [ebp-3h]
  char v20; // [esp+ABh] [ebp-1h]

  v18[0] = byte_5EA438[0];
  memset(&v18[1], 0, 0x4Cu);
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
  v3 = (char *)(v18 - v1);
  do
  {
    v4 = *v2;
    v2[(_DWORD)v3] = *v2;
    ++v2;
  }
  while ( v4 );
  v5 = &v18[strlen(v18)];
  if ( v5 > v18 )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= v18 )
        goto LABEL_13;
    }
    *v5 = 0;
  }
LABEL_13:
  result = dword_8AC488;
  v7 = 0;
  if ( dword_8AC488 > 0 )
  {
    for ( i = 0; ; i += 396 )
    {
      v15[0] = byte_5EA438[0];
      v9 = (const char *)(i + dword_8AC490 + 4);
      memset(&v15[1], 0, 0x4Cu);
      v16 = 0;
      v17 = 0;
      v10 = &v9[strlen(v9)];
      if ( v10 > v9 )
      {
        while ( *v10 != 92 )
        {
          if ( --v10 <= v9 )
            goto LABEL_20;
        }
        ++v10;
      }
LABEL_20:
      v11 = v10;
      v12 = (char *)(v15 - v10);
      do
      {
        v13 = *v11;
        v11[(_DWORD)v12] = *v11;
        ++v11;
      }
      while ( v13 );
      v14 = &v15[strlen(v15)];
      if ( v14 > v15 )
      {
        while ( *v14 != 46 )
        {
          if ( --v14 <= v15 )
            goto LABEL_27;
        }
        *v14 = 0;
      }
LABEL_27:
      if ( strlen(v15) )
      {
        result = sub_596C80(v18, v15, strlen(v15));
        if ( !result )
          break;
      }
      result = dword_8AC488;
      if ( ++v7 >= dword_8AC488 )
        return result;
    }
    dword_8AC48C = v7;
  }
  return result;
}
