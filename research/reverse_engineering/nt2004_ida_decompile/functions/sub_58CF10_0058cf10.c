unsigned __int8 __cdecl sub_58CF10(_BYTE *a1, unsigned __int8 a2)
{
  unsigned __int8 result; // al
  int v3; // eax
  int v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // al
  unsigned __int8 *v7; // edi

  result = a1[6];
  if ( result )
  {
    v3 = (unsigned __int8)a1[5];
    v4 = 0;
    v5 = (unsigned int)&a1[4 * (a1[4] & 0xF) + ((v3 * ((a1[4] & 0xF) + 2) + 15) & 0xFFFFFFFC)];
    if ( (char)a1[4] < 0 )
      v4 = (v3 + 7) / 8 + 1;
    v6 = *(_BYTE *)(v4 + v5);
    v7 = (unsigned __int8 *)(v5 + v4);
    if ( v6 < a1[6] )
      v7[v6 + 1] = a2;
    result = v6 + 1;
    if ( result >= a1[6] )
      result = 0;
    *v7 = result;
  }
  return result;
}
