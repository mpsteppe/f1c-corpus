int __cdecl sub_515869(float *a1, unsigned __int16 *a2)
{
  int result; // eax

  result = sub_51512C(a1, a2);
  if ( result >= 0 )
  {
    result = BatchClampToMax(a1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
