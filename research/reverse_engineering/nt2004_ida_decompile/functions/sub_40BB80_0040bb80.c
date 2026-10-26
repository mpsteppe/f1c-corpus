char *__stdcall sub_40BB80(char *a1, int a2)
{
  char *v2; // ebp
  char *result; // eax
  const char *v4; // esi
  char *v5; // eax
  char v6; // cl
  int v7; // ecx
  char *i; // eax
  const char *v9; // ecx
  const char *v10; // eax
  char *v11; // edx
  char v12; // cl
  char *v13; // eax
  char v14; // cl
  int v15; // ecx
  char *j; // eax
  int v17; // ecx
  char *k; // eax
  char *v19; // edx
  char v20; // cl
  char *v21; // edi
  char v22; // cl
  unsigned int v23; // [esp+10h] [ebp-244h]
  char v24[61]; // [esp+14h] [ebp-240h] BYREF
  __int16 v25; // [esp+51h] [ebp-203h]
  char v26; // [esp+53h] [ebp-201h] BYREF
  char FileName[509]; // [esp+54h] [ebp-200h] BYREF
  __int16 v28; // [esp+251h] [ebp-3h]
  char v29; // [esp+253h] [ebp-1h]

  v24[0] = byte_629120;
  memset(&v24[1], 0, 0x3Cu);
  v25 = 0;
  v26 = 0;
  FileName[0] = byte_629120;
  memset(&FileName[1], 0, 0x1FCu);
  v28 = 0;
  v29 = 0;
  v2 = strcpy(a1, &byte_629120);
  result = (char *)(dword_7D6B58 + 400 * dword_7D6B54);
  if ( result )
  {
    v4 = result + 4;
    v5 = result + 4;
    do
    {
      v6 = *v5;
      v5[FileName - v4] = *v5;
      ++v5;
    }
    while ( v6 );
    v7 = strlen(FileName);
    if ( v7 > 0 )
    {
      for ( i = &FileName[v7 - 1]; i >= FileName; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v9 = &v4[strlen(v4)];
    if ( v9 > v4 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= v4 )
          goto LABEL_13;
      }
      ++v9;
    }
LABEL_13:
    v10 = v9;
    v11 = (char *)(v24 - v9);
    do
    {
      v12 = *v10;
      v10[(_DWORD)v11] = *v10;
      ++v10;
    }
    while ( v12 );
    v13 = &v24[strlen(v24)];
    if ( v13 > v24 )
    {
      while ( *v13 != 46 )
      {
        if ( --v13 <= v24 )
          goto LABEL_20;
      }
      *v13 = 0;
    }
LABEL_20:
    v23 = strlen(aCam) + 1;
    qmemcpy(&v24[strlen(v24)], aCam, v23);
    v23 = strlen(v24) + 1;
    qmemcpy(&FileName[strlen(FileName)], v24, v23);
    if ( _access(FileName, 0) == -1 )
    {
      v15 = strlen(FileName);
      if ( v15 > 0 )
      {
        for ( j = &FileName[v15 - 1]; j >= FileName; *j-- = 0 )
        {
          if ( *j == 92 )
            break;
        }
      }
      if ( *((_BYTE *)&v25 + strlen(FileName) + 2) == 92 )
        FileName[strlen(FileName) - 1] = 0;
      v17 = strlen(FileName);
      if ( v17 > 0 )
      {
        for ( k = &FileName[v17 - 1]; k >= FileName; *k-- = 0 )
        {
          if ( *k == 92 )
            break;
        }
      }
      if ( *((_BYTE *)&v25 + strlen(FileName) + 2) == 92 )
        FileName[strlen(FileName) - 1] = 0;
      result = &FileName[strlen(FileName)];
      if ( result > FileName )
      {
        while ( *result != 92 )
        {
          if ( --result <= FileName )
            goto LABEL_41;
        }
        ++result;
      }
LABEL_41:
      if ( result )
      {
        v19 = (char *)(v24 - result);
        do
        {
          v20 = *result;
          result[(_DWORD)v19] = *result;
          ++result;
        }
        while ( v20 );
        *(_WORD *)&FileName[strlen(FileName)] = *(_WORD *)word_5FB9F4;
        strcat(FileName, v24);
        v21 = &FileName[strlen(FileName) + 1];
        v22 = byte_5FB9F0;
        *(_DWORD *)--v21 = dword_5FB9EC;
        v21[4] = v22;
        strcpy(v2, FileName);
      }
    }
    else
    {
      result = FileName;
      do
      {
        v14 = *result;
        result[v2 - FileName] = *result;
        ++result;
      }
      while ( v14 );
    }
  }
  return result;
}
