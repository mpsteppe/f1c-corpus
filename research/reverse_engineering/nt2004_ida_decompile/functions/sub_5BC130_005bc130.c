int __fastcall sub_5BC130(int a1, int a2)
{
  int result; // eax
  char v3; // bl

  result = 0;
  if ( a2 <= 0 )
    return -1;
  while ( 1 )
  {
    v3 = *(_BYTE *)(result + a1);
    ++result;
    if ( !v3 )
      break;
    if ( result >= a2 )
      return -1;
  }
  return result;
}
