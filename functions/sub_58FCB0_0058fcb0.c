_DWORD *__cdecl sub_58FCB0(_DWORD *a1, _BYTE *a2)
{
  _DWORD *v2; // ecx
  char v3; // al
  int v4; // eax
  int v5; // eax
  _BYTE *v6; // edi
  _BYTE *v7; // ecx
  int v8; // edx
  int v9; // eax
  _DWORD *result; // eax

  v2 = a1;
  if ( ((unsigned __int8)a1 & 3) == 0 )
    goto LABEL_4;
  do
  {
    v3 = *(_BYTE *)v2;
    v2 = (_DWORD *)((char *)v2 + 1);
    if ( !v3 )
    {
LABEL_9:
      v6 = (char *)v2 - 1;
      goto LABEL_13;
    }
  }
  while ( ((unsigned __int8)v2 & 3) != 0 );
  while ( 1 )
  {
    do
    {
LABEL_4:
      v4 = (*v2 + 2130640639) ^ ~*v2;
      ++v2;
    }
    while ( (v4 & 0x81010100) == 0 );
    v5 = *(v2 - 1);
    if ( !(_BYTE)v5 )
      break;
    if ( !BYTE1(v5) )
    {
      v6 = (char *)v2 - 3;
      goto LABEL_13;
    }
    if ( (v5 & 0xFF0000) == 0 )
    {
      v6 = (char *)v2 - 2;
      goto LABEL_13;
    }
    if ( (v5 & 0xFF000000) == 0 )
      goto LABEL_9;
  }
  v6 = v2 - 1;
LABEL_13:
  v7 = a2;
  if ( ((unsigned __int8)a2 & 3) == 0 )
    goto LABEL_18;
  while ( 1 )
  {
    LOBYTE(v8) = *v7++;
    if ( !(_BYTE)v8 )
      break;
    *v6++ = v8;
    if ( ((unsigned __int8)v7 & 3) == 0 )
    {
      while ( 1 )
      {
LABEL_18:
        v9 = (*(_DWORD *)v7 + 2130640639) ^ ~*(_DWORD *)v7;
        v8 = *(_DWORD *)v7;
        v7 += 4;
        if ( (v9 & 0x81010100) != 0 )
        {
          if ( !(_BYTE)v8 )
            goto LABEL_26;
          if ( !BYTE1(v8) )
          {
            *(_WORD *)v6 = (unsigned __int8)v8;
            return a1;
          }
          if ( (v8 & 0xFF0000) == 0 )
          {
            *(_WORD *)v6 = v8;
            result = a1;
            v6[2] = 0;
            return result;
          }
          if ( (v8 & 0xFF000000) == 0 )
          {
            *(_DWORD *)v6 = v8;
            return a1;
          }
        }
        *(_DWORD *)v6 = v8;
        v6 += 4;
      }
    }
  }
LABEL_26:
  *v6 = v8;
  return a1;
}
