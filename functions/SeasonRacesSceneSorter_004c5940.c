_DWORD *SeasonRacesSceneSorter()
{
  _DWORD *result; // eax
  int v1; // eax
  int v2; // edx
  int v3; // edi
  _DWORD *v4; // ebx
  int v5; // ebp
  int v6; // esi
  _BYTE *i; // ebp
  _DWORD *v8; // eax
  char *v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  void *v15; // eax
  int v16; // [esp+4h] [ebp-198h]
  int v17; // [esp+4h] [ebp-198h]
  int v18; // [esp+8h] [ebp-194h]
  int v19; // [esp+Ch] [ebp-190h]
  _BYTE v20[396]; // [esp+10h] [ebp-18Ch] BYREF

  result = (_DWORD *)AudioChannelStop(dword_8AD3B4, aSeasonraces);
  if ( result )
  {
    v16 = LinkedListCount(result);
    v1 = OperatorNewNhMallocWrapper(4 * dword_8AC488);
    v2 = dword_8AC488;
    v3 = 0;
    v4 = (_DWORD *)v1;
    if ( dword_8AC488 > 0 )
    {
      v5 = 0;
      v18 = 0;
      do
      {
        v6 = 0;
        for ( i = (_BYTE *)(dword_8AC490 + v5 + 260); v6 < v16; ++v6 )
        {
          v8 = (_DWORD *)NullCheckWrapper(v6);
          v9 = StringPointerAccessor(v8);
          if ( !sub_588410(v9, i) )
            break;
        }
        v4[v3] = v6;
        v2 = dword_8AC488;
        ++v3;
        v5 = v18 + 396;
        v18 += 396;
      }
      while ( v3 < dword_8AC488 );
    }
    v10 = 0;
    if ( v2 > 0 )
    {
      v17 = 0;
      do
      {
        v11 = v10 + 1;
        v12 = v10;
        if ( v10 + 1 < v2 )
        {
          v13 = v10;
          v19 = v10;
          do
          {
            if ( v4[v11] < v4[v13] )
            {
              v12 = v11;
              v13 = v11;
            }
            v2 = dword_8AC488;
            ++v11;
          }
          while ( v11 < dword_8AC488 );
          if ( v12 != v10 )
          {
            v14 = v4[v12];
            v4[v12] = v4[v19];
            v4[v19] = v14;
            v15 = (void *)(dword_8AC490 + 396 * v12);
            qmemcpy(v20, v15, sizeof(v20));
            qmemcpy(v15, (const void *)(dword_8AC490 + v17), 0x18Cu);
            qmemcpy((void *)(dword_8AC490 + v17), v20, 0x18Cu);
            v2 = dword_8AC488;
          }
          v11 = v10 + 1;
        }
        v10 = v11;
        v17 += 396;
      }
      while ( v11 < v2 );
    }
    return (_DWORD *)FreeWrapper_7bcf(v4);
  }
  return result;
}
