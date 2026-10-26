int __cdecl sub_513C38(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // ecx

  v3 = a3;
  if ( a3 <= 8 )
  {
    if ( !a3 )
      return 0;
  }
  else
  {
    v3 = 8;
  }
  if ( a2 > 7 )
    return 0;
  if ( a2 + v3 > 8 )
    v3 = 8 - a2;
  return memcmp((const char *)(a1 + a2), &byte_5AF564[a2], v3);
}
