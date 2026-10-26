int __cdecl _ftelli64_lk(int a1)
{
  int v2; // esi
  __int64 v3; // rax
  int v4; // ebx
  unsigned int v6; // eax
  int v7; // edx
  int v8; // ecx
  _BYTE *i; // ecx
  int v10; // ecx
  _DWORD *v11; // ebx
  int v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // ecx
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  __int64 Offset; // [esp+Ch] [ebp-10h]
  int FileHandle; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]
  unsigned int v21; // [esp+24h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 16);
  FileHandle = v2;
  if ( *(int *)(a1 + 4) < 0 )
    *(_DWORD *)(a1 + 4) = 0;
  v3 = _lseeki64(v2, 0, 1);
  v4 = v3;
  Offset = v3;
  if ( v3 < 0 )
    return -1;
  if ( (*(_WORD *)(a1 + 12) & 0x108) == 0 )
    return v3 - *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)a1;
  v7 = *(_DWORD *)(a1 + 8);
  v20 = *(_DWORD *)a1 - v7;
  v8 = *(_DWORD *)(a1 + 12);
  if ( (v8 & 3) != 0 )
  {
    if ( *(char *)(dword_8003E0[v2 >> 5] + 36 * (v2 & 0x1F) + 4) < 0 )
    {
      for ( i = *(_BYTE **)(a1 + 8); (unsigned int)i < v6; ++i )
      {
        if ( *i == 10 )
          ++v20;
      }
    }
    v4 = Offset;
    goto LABEL_17;
  }
  if ( (v8 & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
LABEL_17:
  if ( !(HIDWORD(Offset) | v4) )
    return v20;
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 4);
    if ( v10 )
    {
      v21 = v10 + v6 - v7;
      v11 = (_DWORD *)(4 * (v2 >> 5) + 8389600);
      v12 = 36 * (v2 & 0x1F);
      if ( *(char *)(v12 + *v11 + 4) < 0 )
      {
        if ( _lseeki64(FileHandle, 0, 2) == Offset )
        {
          v13 = *(_BYTE **)(a1 + 8);
          v14 = &v13[v21];
          while ( v13 < v14 )
          {
            if ( *v13 == 10 )
              ++v21;
            ++v13;
          }
          v15 = (*(_BYTE *)(a1 + 13) & 0x20) == 0;
        }
        else
        {
          _lseeki64(FileHandle, Offset, 0);
          v16 = 512;
          if ( v21 > 0x200 || (v17 = *(_DWORD *)(a1 + 12), (v17 & 8) == 0) || (v17 & 0x400) != 0 )
            v16 = *(_DWORD *)(a1 + 24);
          v21 = v16;
          v15 = (*(_BYTE *)(v12 + *v11 + 4) & 4) == 0;
        }
        if ( !v15 )
          ++v21;
      }
      LODWORD(Offset) = Offset - v21;
    }
    else
    {
      v20 = 0;
    }
  }
  return Offset + v20;
}
