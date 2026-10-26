unsigned __int8 *__cdecl sub_58F100(unsigned __int8 *a1)
{
  unsigned __int8 *result; // eax
  int v2; // ecx
  unsigned __int8 *v3; // esi

  result = a1;
  v2 = 0;
  v3 = &a1[(((a1[4] >> 2) + 3) & 0xFFFFFFFC) + 8 + ((4 * a1[6] + 3) & 0xFFFFFFFC)];
  if ( a1[5] )
  {
    do
    {
      *(_DWORD *)v3 = 0;
      ++v2;
      v3 += 4;
    }
    while ( v2 < a1[5] );
  }
  return result;
}
