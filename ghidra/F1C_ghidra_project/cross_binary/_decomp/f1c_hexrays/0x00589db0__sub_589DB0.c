// f1c  0x00589db0  size=188
char *__cdecl sub_589DB0(char *a1, unsigned __int8 a2)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax

  v2 = a1;
  if ( ((unsigned __int8)a1 & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == a2 )
        return v2 - 1;
      if ( !v3 )
        return 0;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto LABEL_5;
    }
  }
  else
  {
    while ( 1 )
    {
LABEL_5:
      while ( 1 )
      {
        v4 = ((a2 << 8) | a2 | (((a2 << 8) | a2) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return 0;
      }
      v9 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v9 == a2 )
        break;
      if ( !(_BYTE)v9 )
        return 0;
      if ( BYTE1(v9) == a2 )
        return v2 - 3;
      if ( !BYTE1(v9) )
        return 0;
      v10 = HIWORD(v9);
      if ( (_BYTE)v10 == a2 )
        return v2 - 2;
      if ( !(_BYTE)v10 )
        return 0;
      if ( BYTE1(v10) == a2 )
        return v2 - 1;
      if ( !BYTE1(v10) )
        return 0;
    }
    return v2 - 4;
  }
}
