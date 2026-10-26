int __cdecl sub_58A947(unsigned int a1, int a2)
{
  int result; // eax

  if ( a1 > 0xFFFFFFE0 )
    return 0;
  while ( 1 )
  {
    result = sub_58A973(a1);
    if ( result || !a2 )
      break;
    if ( !sub_593DB8(a1) )
      return 0;
  }
  return result;
}
