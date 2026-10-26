int __cdecl sub_51588C(float *a1, unsigned __int16 *a2)
{
  int result; // eax

  result = sub_5151AF(a1, a2);
  if ( result >= 0 )
  {
    result = BatchClampToMax(a1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
