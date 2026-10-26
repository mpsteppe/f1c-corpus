void __thiscall sub_57F060(void *this, long double a2, int a3)
{
  long double v3; // st7
  long double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st5
  double v8; // st4
  double v9; // st5
  double v10; // st4
  long double v11; // st7
  long double v12; // st6

  v3 = sin(a2);
  v4 = cos(a2);
  v5 = *((double *)this + 1);
  v6 = *((double *)this + 2);
  *((long double *)this + 1) = v5 * v4 + v6 * v3;
  *((long double *)this + 2) = v6 * v4 - v5 * v3;
  v7 = *((double *)this + 4);
  v8 = *((double *)this + 5);
  *((long double *)this + 4) = v7 * v4 + v8 * v3;
  *((long double *)this + 5) = v8 * v4 - v7 * v3;
  v9 = *((double *)this + 7);
  v10 = *((double *)this + 8);
  *((long double *)this + 7) = v9 * v4 + v10 * v3;
  *((long double *)this + 8) = v10 * v4 - v9 * v3;
  if ( a3 )
  {
    *(long double *)a3 = -asin(*((double *)this + 5));
    if ( fabs(*((double *)this + 5)) == 1.0 )
    {
      v11 = -*((double *)this + 6);
      v12 = *(double *)this;
      *(_DWORD *)(a3 + 16) = 0;
      *(_DWORD *)(a3 + 20) = 0;
      *(long double *)(a3 + 8) = atan2(v11, v12);
    }
    else
    {
      *(long double *)(a3 + 8) = atan2(*((double *)this + 2), *((double *)this + 8));
      *(long double *)(a3 + 16) = atan2(*((double *)this + 3), *((double *)this + 4));
    }
  }
}
