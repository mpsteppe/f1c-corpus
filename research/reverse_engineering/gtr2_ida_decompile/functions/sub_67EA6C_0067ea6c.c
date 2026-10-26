int __stdcall sub_67EA6C(float *a1, unsigned __int16 *a2)
{
  int result; // eax

  result = sub_67E1E1(a1, a2);
  if ( result >= 0 )
  {
    result = sub_67CC69(a1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
