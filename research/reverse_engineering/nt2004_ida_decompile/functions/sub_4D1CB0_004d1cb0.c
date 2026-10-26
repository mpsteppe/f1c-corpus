int __cdecl sub_4D1CB0(float *a1, float *a2)
{
  if ( *a1 > (double)*a2 )
    return 1;
  if ( *a1 >= (double)*a2 )
    return 0;
  return -1;
}
