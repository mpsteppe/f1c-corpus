int __cdecl sub_58FB60(__int16 a1, int a2, __int16 a3)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  _WORD *v6; // edx
  int v7; // edi
  __int16 *v8; // ecx

  result = -1;
  if ( a2 > 32 )
    a2 = 32;
  v4 = 0;
  v5 = 0;
  v6 = (_WORD *)(4 * dword_7E4CB8 + 8386912);
  v7 = 0;
  v8 = (__int16 *)(4 * dword_7E4CB8 + 8386914);
  do
  {
    if ( v4 >= a2 )
    {
      v7 = 1;
    }
    else if ( *v8 == a3 )
    {
      ++v4;
      if ( *v6 == a1 )
      {
        v7 = 1;
        result = v4 - 1;
      }
    }
    v8 -= 2;
    v6 -= 2;
    if ( (int)v8 < (int)&word_7FF962 )
    {
      v8 += 64;
      v6 += 64;
    }
    ++v5;
  }
  while ( v5 <= 32 && !v7 );
  return result;
}
