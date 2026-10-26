int __thiscall ResultsPageBuilder(int *this)
{
  int *v2; // ecx
  int v3; // eax
  int v4; // edi
  char *v5; // ecx
  char *v6; // eax
  char *v7; // eax
  _DWORD *v8; // esi
  char *v9; // eax
  _DWORD *v10; // eax
  double v11; // st7
  int v12; // kr00_4
  int v13; // edx
  int v14; // eax
  char *v15; // eax
  char *v16; // eax
  char v18; // [esp+18h] [ebp-188h] BYREF
  __int16 v19; // [esp+19h] [ebp-187h]
  char v20; // [esp+1Bh] [ebp-185h]
  int v21; // [esp+1Ch] [ebp-184h]
  _WORD v22[16]; // [esp+20h] [ebp-180h] BYREF
  _WORD v23[16]; // [esp+40h] [ebp-160h] BYREF
  _WORD v24[31]; // [esp+60h] [ebp-140h] BYREF
  __int16 v25; // [esp+9Eh] [ebp-102h]
  _BYTE v26[256]; // [esp+A0h] [ebp-100h] BYREF

  v19 = 0;
  v20 = 0;
  v18 = byte_5EA438[0];
  v24[0] = word_5C694C;
  memset(&v24[1], 0, 0x3Cu);
  v25 = 0;
  v23[0] = word_5C694C;
  memset(&v23[1], 0, 30);
  v22[0] = word_5C694C;
  memset(&v22[1], 0, 30);
  StateCleanupNotification(this);
  v2 = (int *)dword_7D2DC0;
  dword_7D2DC8 = dword_7D2DC0;
  if ( dword_7D2DC0 )
    v3 = *(_DWORD *)dword_7D2DC0;
  else
    v3 = 0;
  v4 = v3;
  if ( v3 )
  {
    do
    {
      if ( v4 )
      {
        v5 = (char *)dword_7CE5EC;
        if ( !dword_7CE5EC )
          v5 = byte_5EA438;
        v6 = *(char **)v4;
        if ( !*(_DWORD *)v4 )
          v6 = byte_5EA438;
        if ( !sub_588410(v6, v5) )
        {
          v7 = *(char **)v4;
          if ( !*(_DWORD *)v4 )
            v7 = byte_5EA438;
          v8 = (_DWORD *)SeasonRacesSectionFinder((int)v7);
          if ( v8 )
          {
            v9 = *(char **)v4;
            if ( !*(_DWORD *)v4 )
              v9 = byte_5EA438;
            sub_587DD0(v24, v9, 0x3Fu);
            HIBYTE(v25) = 0;
            v10 = StringKeyedLinkedListSearch(v8, (int)aTrackname);
            if ( v10 )
              strcpy((char *)v24, DataEntryAccessor(v10));
          }
          StringFormatWithBufferOverflowCheck(v22, (int)"%d", *(_DWORD *)(v4 + 16));
          v11 = *(float *)(v4 + 20);
          v12 = CRTFtol(v11);
          v13 = v12 / 60;
          if ( v12 / 60 > 0 )
          {
            v21 = 60 * v13;
            v11 = v11 - (double)(60 * v13);
          }
          StringFormatWithBufferOverflowCheck(v23, (int)"%i:%06.3f", v12 / 60, v11);
        }
        v2 = (int *)dword_7D2DC8;
      }
      if ( v2 && (v2 = (int *)v2[1], (dword_7D2DC8 = (int)v2) != 0) )
        v14 = *v2;
      else
        v14 = 0;
      v4 = v14;
    }
    while ( v14 );
  }
  StrlenOverwrite(&v18);
  StringFormatWithBufferOverflowCheck(v26, (int)byte_5EA438);
  UIMenuItemCreator(this, (int)v26, 0, 0, 0, 0);
  v15 = UIListIndexedAccessor(this, 1);
  StringFormatWithBufferOverflowCheck(v26, (int)"%s%s%s", v15, &v18, (const char *)v22);
  UIMenuItemCreator(this, (int)v26, 0, 0, 0, 0);
  v16 = UIListIndexedAccessor(this, 2);
  StringFormatWithBufferOverflowCheck(v26, (int)"%s%s%s", v16, &v18, (const char *)v23);
  return UIMenuItemCreator(this, (int)v26, 0, 0, 0, 0);
}

