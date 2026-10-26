int __thiscall sub_680391(int *this, int *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v6; // edx
  int v7; // eax
  unsigned int v8; // [esp+10h] [ebp+8h]
  char *i; // [esp+14h] [ebp+Ch]

  v3 = a3;
  if ( a3 == -1 )
  {
    v3 = ((unsigned int)(this[1] + 3) >> 2) + 2;
  }
  else if ( a3 < ((unsigned int)(this[1] + 3) >> 2) + 2 )
  {
    return -2147467259;
  }
  if ( v3 > 0x8000 )
    return -2147467259;
  v8 = 0;
  *a2 = ((((_WORD)v3 - 1) & 0x7FFF) << 16) | 0xFFFE;
  a2[1] = *this;
  v6 = this[2];
  for ( i = (char *)(a2 + 2); v6; v8 += v7 )
  {
    if ( (*(_BYTE *)(v6 + 8) & 4) == 0 )
    {
      memset(i, 0xABu, ((v8 + 3) & 0xFFFFFFFC) - v8);
      i += ((v8 + 3) & 0xFFFFFFFC) - v8;
      v8 = (v8 + 3) & 0xFFFFFFFC;
    }
    qmemcpy(i, *(const void **)v6, *(_DWORD *)(v6 + 4));
    v7 = *(_DWORD *)(v6 + 4);
    v6 = *(_DWORD *)(v6 + 16);
    i += v7;
  }
  memset(i, 0xABu, 4 * v3 - 8 - v8);
  return 0;
}
