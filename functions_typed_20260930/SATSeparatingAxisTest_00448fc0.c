char __stdcall sub_448FC0(int a1, float *a2)
{
  int v2; // edx
  double *i; // ecx

  v2 = 0;
  for ( i = (double *)(a1 + 16); *a2 * *(i - 2) + a2[3] * *(i - 1) > *i; i += 3 )
  {
    if ( ++v2 >= 3 )
      return 1;
  }
  return 0;
}

