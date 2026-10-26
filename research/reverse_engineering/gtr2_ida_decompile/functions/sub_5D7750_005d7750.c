void __stdcall sub_5D7750(float *a1)
{
  long double v1; // st4

  v1 = sqrt(*a1 * *a1 + a1[1] * a1[1] + a1[2] * a1[2]);
  if ( 0.0 != v1 )
  {
    *a1 = 1.0 / v1 * *a1;
    a1[1] = 1.0 / v1 * a1[1];
    a1[2] = 1.0 / v1 * a1[2];
  }
}
