int __cdecl sub_58D0E0(_BYTE *a1)
{
  int result; // eax
  int v2; // eax
  int v3; // edi
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // edi

  result = -1;
  if ( dword_7E483C )
  {
    if ( a1[6] )
    {
      v2 = (unsigned __int8)a1[5];
      v3 = 0;
      v4 = (unsigned int)&a1[4 * (a1[4] & 0xF) + ((v2 * ((a1[4] & 0xF) + 2) + 15) & 0xFFFFFFFC)];
      if ( (char)a1[4] < 0 )
        v3 = (v2 + 7) / 8 + 1;
      if ( *(_BYTE *)(v4 + v3) )
        return -1;
      v5 = 0;
      if ( a1[6] )
      {
        v6 = v4 + v3 + 1;
        while ( *(_BYTE *)(v6 + v5) == 0xFF )
        {
          if ( ++v5 >= (unsigned __int8)a1[6] )
            goto LABEL_10;
        }
        return -1;
      }
    }
LABEL_10:
    v7 = sub_58D190();
    if ( v7 >= 0 )
    {
      if ( (char)a1[4] < 0 )
        sub_58D060((int)a1);
      *(_DWORD *)(dword_7E483C + 4 * v7) = a1;
    }
    return v7;
  }
  return result;
}
