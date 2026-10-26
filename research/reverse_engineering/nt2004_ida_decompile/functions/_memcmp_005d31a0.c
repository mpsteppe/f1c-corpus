int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  size_t v3; // eax
  char *v4; // esi
  char *v5; // edi
  bool v6; // cf
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  int result; // eax
  bool v10; // zf
  size_t v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // ecx
  unsigned int v19; // edx

  v3 = Size;
  if ( !Size )
    return retnull_0(Buf1, Buf2, 0);
  v4 = (char *)Buf1;
  v5 = (char *)Buf2;
  if ( (((unsigned __int8)Buf2 | (unsigned __int8)Buf1) & 3) != 0 )
  {
    if ( (Size & 1) != 0 )
    {
      v6 = *(_BYTE *)Buf1 < *(_BYTE *)Buf2;
      if ( *(_BYTE *)Buf1 == *(_BYTE *)Buf2 )
      {
        v4 = (char *)Buf1 + 1;
        v5 = (char *)Buf2 + 1;
        v3 = Size - 1;
        if ( Size != 1 )
          goto main_loop_3;
        return retnull_0(Buf1, Buf2, Size);
      }
    }
    else
    {
main_loop_3:
      while ( 1 )
      {
        v6 = (unsigned __int8)*v4 < (unsigned __int8)*v5;
        if ( *v4 != *v5 )
          break;
        v7 = v4[1];
        v8 = v5[1];
        v6 = v7 < v8;
        if ( v7 != v8 )
          break;
        v5 += 2;
        v4 += 2;
        v3 -= 2;
        if ( !v3 )
          return retnull_0(Buf1, Buf2, Size);
      }
    }
    return -v6 - (v6 - 1);
  }
  v11 = Size >> 2;
  v10 = Size >> 2 == 0;
  if ( Size >> 2 )
  {
    do
    {
      if ( !v11 )
        break;
      v10 = *(_DWORD *)v4 == *(_DWORD *)v5;
      v4 += 4;
      v5 += 4;
      --v11;
    }
    while ( v10 );
    if ( !v10 )
    {
      v12 = *((_DWORD *)v4 - 1);
      v13 = *((_DWORD *)v5 - 1);
      v6 = (unsigned __int8)v12 < (unsigned __int8)v13;
      if ( (_BYTE)v12 == (_BYTE)v13 )
      {
        v6 = BYTE1(v12) < BYTE1(v13);
        if ( BYTE1(v12) == BYTE1(v13) )
        {
          v14 = HIWORD(v12);
          v15 = HIWORD(v13);
          v6 = (unsigned __int8)v14 < (unsigned __int8)v15;
          if ( (_BYTE)v14 == (_BYTE)v15 )
            v6 = BYTE1(v14) < BYTE1(v15);
        }
      }
      return -v6 - (v6 - 1);
    }
  }
  if ( (Size & 3) == 0 )
    return retnull_0(Buf1, Buf2, Size);
  v16 = *(_DWORD *)v4;
  v17 = *(_DWORD *)v5;
  v6 = (unsigned __int8)*(_DWORD *)v4 < (unsigned __int8)*(_DWORD *)v5;
  if ( (unsigned __int8)*(_DWORD *)v4 != (unsigned __int8)*(_DWORD *)v5 )
    return -v6 - (v6 - 1);
  result = (Size & 3) - 1;
  if ( (Size & 3) != 1 )
  {
    v6 = BYTE1(v16) < BYTE1(v17);
    if ( BYTE1(v16) != BYTE1(v17) )
      return -v6 - (v6 - 1);
    result = (Size & 3) - 2;
    if ( (Size & 3) == 2 )
      return result;
    v18 = v17 & 0xFF0000;
    v19 = v16 & 0xFF0000;
    v6 = v19 < v18;
    if ( v19 != v18 )
      return -v6 - (v6 - 1);
    return (Size & 3) - 3;
  }
  return result;
}
