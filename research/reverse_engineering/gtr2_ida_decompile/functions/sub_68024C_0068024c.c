int __thiscall sub_68024C(_DWORD *this, char *Block, size_t Size, int a4, _DWORD *a5)
{
  unsigned int v5; // edi
  _DWORD *v6; // esi
  int i; // eax
  char **v9; // ebx
  char *v10; // eax
  char *v11; // ecx
  char ***v12; // ecx

  v5 = Size;
  v6 = this;
  if ( Size && !Block )
    return -2147467259;
  if ( Size == -1 )
  {
    Size = strlen(Block) + 1;
    v5 = Size;
  }
  if ( (a4 & 1) == 0 )
    a4 |= 2u;
  if ( (a4 & 2) != 0 )
  {
    for ( i = v6[2]; i; i = *(_DWORD *)(i + 16) )
    {
      if ( (*(_BYTE *)(i + 8) & 2) != 0 && v5 == *(_DWORD *)(i + 4) )
      {
        if ( !memcmp(Block, *(const void **)i, v5) )
        {
          if ( a5 )
            *a5 = *(_DWORD *)(i + 12);
          if ( (a4 & 1) != 0 && (a4 & 8) != 0 )
            j__free(Block);
          return 0;
        }
        v5 = Size;
        v6 = this;
      }
    }
  }
  v9 = (char **)operator new(0x14u);
  if ( !v9 )
    return -2147024882;
  if ( (a4 & 1) != 0 )
  {
    *v9 = Block;
  }
  else
  {
    v10 = (char *)operator new(v5);
    *v9 = v10;
    if ( !v10 )
    {
      j__free(v9);
      return -2147024882;
    }
    qmemcpy(v10, Block, v5);
    v5 = Size;
    v6 = this;
  }
  if ( (a4 & 4) == 0 )
    v6[1] = (v6[1] + 3) & 0xFFFFFFFC;
  v11 = (char *)v6[1];
  v9[2] = (char *)a4;
  v9[4] = 0;
  v9[3] = v11;
  v9[1] = (char *)v5;
  v12 = (char ***)v6[3];
  v6[1] += v5;
  *v12 = v9;
  v6[3] = v9 + 4;
  if ( a5 )
    *a5 = v9[3];
  return 0;
}
