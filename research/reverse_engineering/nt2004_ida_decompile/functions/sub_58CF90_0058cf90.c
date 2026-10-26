int __cdecl sub_58CF90(_BYTE *a1, int a2)
{
  int result; // eax
  int v3; // ebp
  char v4; // al
  int v5; // edi
  int v6; // esi
  unsigned __int8 *v7; // eax
  int v8; // esi
  int v9; // ecx
  unsigned __int8 *v10; // eax

  result = 0;
  v3 = (unsigned __int8)a1[6];
  if ( a1[6] )
  {
    v4 = a1[4];
    v5 = (unsigned __int8)a1[5];
    v6 = 0;
    if ( v4 < 0 )
      v6 = (v5 + 7) / 8 + 1;
    v7 = &a1[4 * (v4 & 0xF) + ((v5 * ((v4 & 0xF) + 2) + 15) & 0xFFFFFFFC) + v6];
    v8 = 0;
    v9 = *v7;
    v10 = v7 + 1;
    if ( a1[6] )
    {
      while ( 1 )
      {
        if ( --v9 < 0 )
          v9 = v3 - 1;
        if ( v10[v9] == a2 )
          break;
        if ( ++v8 >= v3 )
          return 0;
      }
      return v8 + 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
