int __cdecl x_ismbbtype(unsigned __int8 a1, int a2, unsigned __int8 a3)
{
  int result; // eax

  if ( (a3 & (unsigned __int8)byte_FBB281[a1]) != 0 )
    return 1;
  result = a2 ? (unsigned __int16)(a2 & off_913150[a1]) : 0;
  if ( result )
    return 1;
  return result;
}
