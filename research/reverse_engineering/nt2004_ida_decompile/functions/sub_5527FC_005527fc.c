int __cdecl sub_5527FC(float *a1, unsigned __int16 *a2)
{
  int result; // eax

  result = sub_5520BF(a1, a2);
  if ( result >= 0 )
  {
    result = sub_550D42(a1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
