int __cdecl sub_596E0F(unsigned __int8 a1, int a2, unsigned __int8 a3)
{
  int result; // eax

  if ( (a3 & (unsigned __int8)byte_8D47E1[a1]) != 0 )
    return 1;
  result = a2 ? (unsigned __int16)(a2 & word_5E69D2[a1]) : 0;
  if ( result )
    return 1;
  return result;
}
