char __thiscall sub_46B5F0(_DWORD *this, int a2, const char *a3, char *a4)
{
  int v4; // esi
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  const char *v9; // ebx
  char v10; // cl
  int v11; // edx
  const char *v12; // ebp
  const char *v13; // edi
  unsigned int v16[2]; // [esp+18h] [ebp-128h] BYREF
  _BYTE v17[48]; // [esp+20h] [ebp-120h] BYREF
  _BYTE v18[48]; // [esp+50h] [ebp-F0h] BYREF
  _BYTE v19[48]; // [esp+80h] [ebp-C0h] BYREF
  _BYTE v20[48]; // [esp+B0h] [ebp-90h] BYREF
  char v21[48]; // [esp+E0h] [ebp-60h] BYREF
  _BYTE v22[48]; // [esp+110h] [ebp-30h] BYREF

  if ( a4 )
    *a4 = 0;
  v4 = dword_7C54F0[a2];
  StringFormatWithBufferOverflowCheck(v17, "%d", *(_DWORD *)(v4 + 16480));
  sub_587DD0(v18, v4 + 17952, 47);
  v18[47] = 0;
  sub_587DD0(v19, v4 + 18104, 47);
  v19[47] = 0;
  if ( dword_7C56A4 == 5 || dword_7C56A4 == 7 )
  {
    v5 = dword_8ACF8C;
    v6 = *(_DWORD *)(v4 + 16444);
    if ( dword_8ACF8C == 0x7FFFFFFF )
      StringFormatWithBufferOverflowCheck(v16, asc_5C6A78);
    else
      StringFormatWithBufferOverflowCheck(v16, "%d", dword_8ACF8C);
    if ( v6 >= 0 )
    {
      if ( v6 > v5 && !dword_7CE814 )
        v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    StringFormatWithBufferOverflowCheck(v20, "%d/%s", v6, (const char *)v16);
  }
  else
  {
    StringFormatWithBufferOverflowCheck(v20, "%d", *(int *)(v4 + 16444) < 0 ? 0 : *(_DWORD *)(v4 + 16444));
  }
  v7 = sub_42BDD0(a2, v21) - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        strcpy(a4, aFtim14greyoutl);
    }
    else
    {
      strcpy(a4, aFtim14greenout);
    }
  }
  else
  {
    strcpy(a4, aFtim14redoutli);
  }
  sub_46B830(a2, v22, 47);
  v9 = a3;
  *a3 = 0;
  v10 = 1;
  v11 = 0;
  v12 = v17;
  do
  {
    if ( this[95] != 1 || v11 >= 0 && (v11 <= 1 || v11 == 4) )
    {
      if ( !v10 )
        *(_WORD *)&v9[strlen(v9)] = word_5C692C;
      v16[0] = strlen(v12) + 1;
      v13 = &v9[strlen(v9) + 1];
      v9 = a3;
      qmemcpy((void *)(v13 - 1), v12, v16[0]);
      v10 = 0;
    }
    ++v11;
    v12 += 48;
  }
  while ( v11 < 6 );
  return 1;
}
