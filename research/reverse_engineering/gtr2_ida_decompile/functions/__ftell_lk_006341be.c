int __cdecl _ftell_lk(unsigned int *a1)
{
  int v2; // esi
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edx
  _BYTE *v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // ebx
  int v11; // esi
  _BYTE *v12; // eax
  _BYTE *v13; // ecx
  bool v14; // zf
  int v15; // eax
  unsigned int v16; // ecx
  int FileHandle; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+10h] [ebp-8h]
  int Offset; // [esp+14h] [ebp-4h]
  unsigned int v20; // [esp+20h] [ebp+8h]

  v2 = a1[4];
  FileHandle = v2;
  if ( (a1[1] & 0x80000000) != 0 )
    a1[1] = 0;
  v3 = _lseek(v2, 0, 1);
  Offset = v3;
  if ( v3 < 0 )
    return -1;
  v4 = a1[3];
  if ( (v4 & 0x108) == 0 )
    return v3 - a1[1];
  v6 = *a1;
  v7 = a1[2];
  v18 = *a1 - v7;
  if ( (v4 & 3) != 0 )
  {
    if ( *(char *)(dword_FBB4E0[v2 >> 5] + 36 * (v2 & 0x1F) + 4) < 0 )
    {
      v8 = (_BYTE *)a1[2];
      if ( v7 < v6 )
      {
        do
        {
          if ( *v8 == 10 )
            ++v18;
          ++v8;
        }
        while ( (unsigned int)v8 < *a1 );
      }
    }
    goto LABEL_12;
  }
  if ( (v4 & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
LABEL_12:
  if ( !Offset )
    return v18;
  if ( (a1[3] & 1) != 0 )
  {
    v9 = a1[1];
    if ( v9 )
    {
      v20 = v9 + v6 - v7;
      v10 = (_DWORD *)(4 * (v2 >> 5) + 16495840);
      v11 = 36 * (v2 & 0x1F);
      if ( *(char *)(v11 + *v10 + 4) < 0 )
      {
        if ( _lseek(FileHandle, 0, 2) == Offset )
        {
          v12 = (_BYTE *)a1[2];
          v13 = &v12[v20];
          while ( v12 < v13 )
          {
            if ( *v12 == 10 )
              ++v20;
            ++v12;
          }
          v14 = (*((_BYTE *)a1 + 13) & 0x20) == 0;
        }
        else
        {
          _lseek(FileHandle, Offset, 0);
          v15 = 512;
          if ( v20 > 0x200 || (v16 = a1[3], (v16 & 8) == 0) || (v16 & 0x400) != 0 )
            v15 = a1[6];
          v20 = v15;
          v14 = (*(_BYTE *)(v11 + *v10 + 4) & 4) == 0;
        }
        if ( !v14 )
          ++v20;
      }
      Offset -= v20;
    }
    else
    {
      v18 = 0;
    }
  }
  return Offset + v18;
}
