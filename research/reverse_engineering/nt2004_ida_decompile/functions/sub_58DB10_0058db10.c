int __cdecl sub_58DB10(unsigned int a1)
{
  int result; // eax
  int v2; // ecx
  unsigned int i; // eax

  result = a1;
  if ( a1 < 0x10 && !word_7FFAAC[48 * a1] )
  {
    byte_7FFAAA[96 * a1] = 0;
    v2 = (unsigned __int8)byte_7FFAAB[96 * a1];
    if ( a1 == dword_7FFA80[v2] )
      dword_7FFA80[v2] = -1;
    if ( a1 == dword_7FFA60[v2] )
      dword_7FFA60[v2] = -1;
    for ( i = word_7FFAAE[48 * a1]; i != -1; i = word_7FFAAE[48 * i] )
    {
      if ( i >= 0x10 || !word_7FFAAC[48 * i] || !byte_7FFAAA[96 * i] )
        break;
      if ( i == dword_7FFA60[v2] )
        dword_7FFA60[v2] = -1;
      byte_7FFAAA[96 * i] = 0;
    }
    if ( !word_7FFAAC[48 * a1] )
      --dword_7FFA40[v2];
    result = 4 * v2 + 8387136;
    if ( dword_7FFA40[v2] < 0 )
      dword_7FFA40[v2] = 0;
  }
  return result;
}
