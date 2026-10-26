int __thiscall sub_468BF0(_DWORD *this)
{
  const char *v1; // edi
  const char *v2; // eax
  char *v3; // eax
  int result; // eax
  int v5; // edi
  char v6; // bl
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  double v10; // st7
  int v11; // edx
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  _WORD v15[16]; // [esp+20h] [ebp-180h] BYREF
  _WORD v16[16]; // [esp+40h] [ebp-160h] BYREF
  _WORD v17[31]; // [esp+60h] [ebp-140h] BYREF
  __int16 v18; // [esp+9Eh] [ebp-102h]
  _WORD v19[128]; // [esp+A0h] [ebp-100h] BYREF

  v19[0] = *(_WORD *)String1;
  memset(&v19[1], 0, 254);
  v17[0] = word_5C694C;
  memset(&v17[1], 0, 0x3Cu);
  v18 = 0;
  v15[0] = word_5C694C;
  memset(&v15[1], 0, 30);
  v16[0] = word_5C694C;
  memset(&v16[1], 0, 30);
  v1 = (const char *)this[95];
  if ( !v1 )
    v1 = byte_5EA438;
  v2 = (const char *)dword_7CE668;
  if ( !dword_7CE668 )
    v2 = byte_5EA438;
  if ( strcmp(v2, v1) )
  {
    v3 = (char *)dword_7CE668;
    if ( !dword_7CE668 )
      v3 = byte_5EA438;
    StringCopyWithBufferRealloc(v3);
  }
  result = dword_7D2DC0;
  dword_7D2DC8 = dword_7D2DC0;
  if ( dword_7D2DC0 )
    v5 = *(_DWORD *)dword_7D2DC0;
  else
    v5 = 0;
  v6 = 1;
  while ( v5 || v6 )
  {
    v6 = 0;
    if ( v5 )
    {
      v7 = *(char **)v5;
      if ( !*(_DWORD *)v5 )
        v7 = byte_5EA438;
      if ( SeasonRacesSectionFinder(v7) )
      {
        v8 = StringKeyedLinkedListSearch(aGrandprixname);
        if ( v8 )
        {
          strcpy((char *)v17, (const char *)DataEntryAccessor(v8));
        }
        else
        {
          v9 = *(char **)v5;
          if ( !*(_DWORD *)v5 )
            v9 = byte_5EA438;
          sub_587DD0(v17, v9, 63);
          HIBYTE(v18) = 0;
        }
      }
      StringFormatWithBufferOverflowCheck(v16, "%d", *(_DWORD *)(v5 + 16));
      v10 = *(float *)(v5 + 20);
      v11 = CRTFtol(v10) / 60;
      if ( v11 > 0 )
        v10 = v10 - (double)(60 * v11);
      StringFormatWithBufferOverflowCheck(v15, "%i:%06.3f", v11, v10);
    }
    v12 = (const char *)UIListIndexedAccessor(10);
    StringFormatWithBufferOverflowCheck(v19, "%s%s%s", v12, (const char *)&word_5C692C, (const char *)v17);
    UIMenuItemCreator(v19, 0, 0, 0, 0);
    v13 = (const char *)UIListIndexedAccessor(11);
    StringFormatWithBufferOverflowCheck(v19, "%s%s%s", v13, (const char *)&word_5C692C, (const char *)v16);
    UIMenuItemCreator(v19, 0, 0, 0, 0);
    v14 = (const char *)UIListIndexedAccessor(12);
    StringFormatWithBufferOverflowCheck(v19, "%s%s%s", v14, (const char *)&word_5C692C, (const char *)v15);
    UIMenuItemCreator(v19, 0, 0, 0, 0);
    StringFormatWithBufferOverflowCheck(v19, byte_5EA438);
    UIMenuItemCreator(v19, 0, 0, 0, 0);
    if ( dword_7D2DC8 && (dword_7D2DC8 = *(_DWORD *)(dword_7D2DC8 + 4)) != 0 )
    {
      result = *(_DWORD *)dword_7D2DC8;
      v5 = *(_DWORD *)dword_7D2DC8;
    }
    else
    {
      result = 0;
      v5 = 0;
    }
  }
  return result;
}
