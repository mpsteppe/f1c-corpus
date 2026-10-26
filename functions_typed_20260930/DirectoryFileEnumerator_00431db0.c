char __thiscall sub_431DB0(char *this, int a2)
{
  char *v3; // eax
  char *v4; // eax
  const char *v5; // edi
  unsigned int v6; // kr04_4
  _DWORD *v7; // esi
  _DWORD *v8; // ebp
  void *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  void *v12; // edi
  _DWORD *v13; // edi
  const CHAR *v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  int i; // edx
  CHAR *v19; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // esi
  int v23; // eax
  _DWORD *v24; // esi
  char v25; // [esp+Fh] [ebp-351h]
  LPCSTR lpFileName[2]; // [esp+10h] [ebp-350h] BYREF
  _DWORD *v27; // [esp+18h] [ebp-348h]
  HANDLE hFindFile; // [esp+1Ch] [ebp-344h]
  _WIN32_FIND_DATAA FindFileData; // [esp+20h] [ebp-340h] BYREF
  _BYTE v30[256]; // [esp+160h] [ebp-200h] BYREF
  _BYTE v31[256]; // [esp+260h] [ebp-100h] BYREF

  v27 = this;
  v25 = 1;
  lpFileName[0] = (LPCSTR)OperatorNewNhMallocWrapper(128);
  *lpFileName[0] = 0;
  lpFileName[1] = (LPCSTR)128;
  if ( a2 )
  {
    StringCopyWithBufferRealloc(a2);
  }
  else
  {
    v3 = *(char **)this;
    if ( !*(_DWORD *)this )
      v3 = &byte_5EA438;
    StringCopyWithBufferRealloc(v3);
    v4 = (char *)*((_DWORD *)this + 2);
    if ( !v4 )
      v4 = &byte_5EA438;
    sub_5665B0(v4);
  }
  v5 = lpFileName[0];
  if ( !lpFileName[0] )
    v5 = &byte_5EA438;
  v6 = strlen(v5) + 1;
  if ( (int)(v6 - 1) > 0 && NullSafePointerDereference((char **)lpFileName)[v6 - 2] != 92 )
    sub_5665B0(&word_5C2AAC);
  sub_5665B0(dword_5C2AB8);
  v7 = (_DWORD *)*((_DWORD *)this + 8);
  v8 = this + 32;
  while ( v7 )
  {
    v9 = v7;
    v7 = (_DWORD *)v7[1];
    DoublePointerFree(v9);
    FreeWrapper_7bcf(v9);
  }
  v10 = v27 + 12;
  *v8 = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v11 = (_DWORD *)*v10;
  if ( *v10 )
  {
    do
    {
      v12 = v11;
      v11 = (_DWORD *)v11[1];
      DoublePointerFree(v12);
      FreeWrapper_7bcf(v12);
    }
    while ( v11 );
  }
  v13 = v27;
  v14 = lpFileName[0];
  v15 = lpFileName[0] == 0;
  v27[12] = 0;
  v13[13] = 0;
  v13[14] = 0;
  v13[15] = 0;
  if ( v15 )
    v14 = &byte_5EA438;
  hFindFile = FindFirstFileA(v14, &FindFileData);
  if ( hFindFile == (HANDLE)-1 )
  {
    v25 = 0;
  }
  else
  {
    do
    {
      if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
      {
        if ( strcmp(FindFileData.cFileName, (const char *)&word_5BEB48) && strcmp(FindFileData.cFileName, "..") )
        {
          sub_568910(256);
          v21 = (_DWORD *)OperatorNewNhMallocWrapper(8);
          v22 = v21;
          if ( v21 )
          {
            *v21 = 0;
            v21[1] = -1;
            StringCopyWithBufferRealloc(v30);
          }
          else
          {
            v22 = 0;
          }
          if ( v22 )
          {
            if ( OperatorNewNhMallocWrapper(12) )
              v23 = ShortComputation_ac20(v22, 1);
            else
              v23 = 0;
            if ( *v8 )
            {
              *(_DWORD *)(v8[1] + 4) = v23;
            }
            else
            {
              *v8 = v23;
              v8[2] = v23;
            }
            v8[1] = v23;
            ++v8[3];
          }
        }
      }
      else
      {
        sub_568910(256);
        v24 = (_DWORD *)OperatorNewNhMallocWrapper(8);
        if ( v24 )
        {
          *v24 = 0;
          v24[1] = -1;
          StringCopyWithBufferRealloc(v31);
        }
        else
        {
          v24 = 0;
        }
        DoublyLinkedListAppend(v24, 1);
      }
    }
    while ( FindNextFileA(hFindFile, &FindFileData) );
    FindClose(hFindFile);
    v13 = v27;
  }
  v16 = LinkedListMergeSort_4290(*v8);
  v17 = v16;
  *v8 = v16;
  if ( v16 )
  {
    for ( i = *(_DWORD *)(v16 + 4); i; i = *(_DWORD *)(i + 4) )
      v17 = i;
  }
  v8[1] = v17;
  v8[2] = v16;
  LinkedListMergeSort(1);
  v19 = (CHAR *)lpFileName[0];
  ++v13[7];
  if ( v19 )
    FreeWrapper_7bcf(v19);
  return v25;
}

