int __fastcall sub_51C850(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6

  v3 = *a2 - *a1;
  v4 = *a3 - *a1;
  if ( (a2[2] - a1[2]) * v4 + 0.000001 >= (a3[2] - a1[2]) * v3 )
    return (a2[2] - a1[2]) * v4 - 0.000001 > (a3[2] - a1[2]) * v3;
  else
    return 2;
}
