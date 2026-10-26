int __stdcall sub_4BF8E0(int a1, int a2)
{
  int v2; // ebx
  const char *v3; // ecx
  int v4; // ecx
  char *i; // eax
  int v6; // esi
  int v7; // eax
  CHAR *v8; // ebx
  char v11[512]; // [esp+14h] [ebp-1400h] BYREF
  char Buffer[509]; // [esp+214h] [ebp-1200h] BYREF
  __int16 v13; // [esp+411h] [ebp-1003h]
  char v14; // [esp+413h] [ebp-1001h]
  char v15[509]; // [esp+414h] [ebp-1000h] BYREF
  __int16 v16; // [esp+611h] [ebp-E03h]
  char v17; // [esp+613h] [ebp-E01h]
  char v18[509]; // [esp+614h] [ebp-E00h] BYREF
  __int16 v19; // [esp+811h] [ebp-C03h]
  char v20; // [esp+813h] [ebp-C01h]
  char Source[509]; // [esp+814h] [ebp-C00h] BYREF
  __int16 v22; // [esp+A11h] [ebp-A03h]
  char v23; // [esp+A13h] [ebp-A01h]
  char v24[509]; // [esp+A14h] [ebp-A00h] BYREF
  __int16 v25; // [esp+C11h] [ebp-803h]
  char v26; // [esp+C13h] [ebp-801h]
  char v27[509]; // [esp+C14h] [ebp-800h] BYREF
  __int16 v28; // [esp+E11h] [ebp-603h]
  char v29; // [esp+E13h] [ebp-601h]
  char v30[509]; // [esp+E14h] [ebp-600h] BYREF
  __int16 v31; // [esp+1011h] [ebp-403h]
  char v32; // [esp+1013h] [ebp-401h]
  char Destination[512]; // [esp+1014h] [ebp-400h] BYREF
  char v34[509]; // [esp+1214h] [ebp-200h] BYREF
  __int16 v35; // [esp+1411h] [ebp-3h]
  char v36; // [esp+1413h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v13 = 0;
  v14 = 0;
  v15[0] = byte_629120;
  memset(&v15[1], 0, 0x1FCu);
  v16 = 0;
  v17 = 0;
  Source[0] = byte_629120;
  memset(&Source[1], 0, 0x1FCu);
  v22 = 0;
  v23 = 0;
  v27[0] = byte_629120;
  memset(&v27[1], 0, 0x1FCu);
  v28 = 0;
  v29 = 0;
  v18[0] = byte_629120;
  memset(&v18[1], 0, 0x1FCu);
  v19 = 0;
  v20 = 0;
  v34[0] = byte_629120;
  memset(&v34[1], 0, 0x1FCu);
  v35 = 0;
  v36 = 0;
  v30[0] = byte_629120;
  memset(&v30[1], 0, 0x1FCu);
  v31 = 0;
  v32 = 0;
  v24[0] = byte_629120;
  memset(&v24[1], 0, 0x1FCu);
  v25 = 0;
  v26 = 0;
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 511);
  v11[0] = byte_629120;
  memset(&v11[1], 0, 511);
  sprintf(Buffer, "%s%.2d", aPbox, a1 + 1);
  sprintf(v15, "%s%.2d", aPlpop, a1 + 1);
  if ( a2 )
  {
    v2 = dword_7D6A5C + 1232 * *(_DWORD *)(a2 + 25252);
    if ( v2 )
    {
      sub_4E7140(*(_DWORD *)(a2 + 2040), Destination, 512);
      v3 = *(const char **)v2;
      if ( !*(_DWORD *)v2 )
        v3 = &byte_629120;
      strcpy(v11, v3);
      v4 = strlen(v11);
      if ( v4 > 0 )
      {
        for ( i = &v11[v4 - 1]; i >= v11; *i-- = 0 )
        {
          if ( *i == 92 )
            break;
        }
      }
      strcat(v11, (const char *)(v2 + 1164));
    }
    sub_4BFC20((int)Destination, Source, v34);
    sub_4BFC20((int)v11, v27, v30);
    sub_4BFC20(0, v18, v24);
    v6 = sub_505E80(Source, v27, v18, 0);
    v7 = sub_505E80(v34, v30, v24, 0);
    if ( (v6 || v7)
      && dword_75CBA8 != 5
      && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_11, 443) )
    {
      v8 = *(CHAR **)v2;
      if ( !v8 )
        v8 = &byte_629120;
      sub_500FE0((int)&unk_7D7920, aUnableToLoadPi, (char)v8);
    }
  }
  sub_506060(Buffer);
  return sub_506060(v15);
}
