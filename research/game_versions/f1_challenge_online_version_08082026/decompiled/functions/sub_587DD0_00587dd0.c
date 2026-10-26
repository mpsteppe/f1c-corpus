_BYTE *__cdecl sub_587DD0(_BYTE *a1, char *a2, unsigned int a3)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // edi
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // edx

  v3 = a3;
  if ( !a3 )
    return a1;
  v4 = a3;
  v5 = a2;
  v6 = a1;
  if ( ((unsigned __int8)a2 & 3) == 0 )
  {
    v7 = a3 >> 2;
    if ( a3 >> 2 )
      goto LABEL_21;
LABEL_10:
    while ( 1 )
    {
      v8 = *v5++;
      *v6++ = v8;
      if ( !v8 )
        break;
      if ( !--v4 )
        return a1;
    }
    while ( --v4 )
LABEL_17:
      *v6++ = v8;
    return a1;
  }
  do
  {
    v8 = *v5++;
    *v6++ = v8;
    if ( !--v3 )
      return a1;
    if ( !v8 )
    {
      while ( ((unsigned __int8)v6 & 3) != 0 )
      {
        *v6++ = 0;
        if ( !--v3 )
          return a1;
      }
      v4 = v3;
      v10 = v3 >> 2;
      if ( !v10 )
        goto LABEL_17;
      goto LABEL_31;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( !v7 )
  {
LABEL_9:
    v4 &= 3u;
    if ( v4 )
      goto LABEL_10;
    return a1;
  }
  while ( 1 )
  {
LABEL_21:
    v11 = (*(_DWORD *)v5 + 2130640639) ^ *(_DWORD *)v5 ^ 0xFFFFFFDE;
    v12 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v11 & 0x81010100) == 0 )
      goto LABEL_20;
    if ( !(_BYTE)v12 )
      break;
    if ( !BYTE1(v12) )
    {
      *(_DWORD *)v6 = (unsigned __int8)v12;
      goto LABEL_30;
    }
    if ( (v12 & 0xFF0000) == 0 )
    {
      *(_DWORD *)v6 = (unsigned __int16)v12;
      goto LABEL_30;
    }
    if ( (v12 & 0xFF000000) == 0 )
    {
      *(_DWORD *)v6 = v12;
      goto LABEL_30;
    }
LABEL_20:
    *(_DWORD *)v6 = v12;
    v6 += 4;
    if ( !--v7 )
      goto LABEL_9;
  }
  *(_DWORD *)v6 = 0;
LABEL_30:
  v6 += 4;
  v8 = 0;
  v10 = v7 - 1;
  if ( v10 )
  {
LABEL_31:
    v8 = 0;
    do
    {
      *(_DWORD *)v6 = 0;
      v6 += 4;
      --v10;
    }
    while ( v10 );
  }
  v4 &= 3u;
  if ( v4 )
    goto LABEL_17;
  return a1;
}
