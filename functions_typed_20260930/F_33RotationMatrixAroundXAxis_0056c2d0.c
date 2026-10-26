void __thiscall sub_56C2D0(void *this, long double a2, int a3)
{
  long double v3; // st7
  long double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st5
  double v9; // st4
  double v10; // st5
  double v11; // st4
  double v12; // st7
  long double v13; // st7
  long double v14; // st6

  v3 = sin(a2);
  v5 = cos(a2);
  v6 = *((double *)this + 1);
  v7 = *((double *)this + 2);
  *((long double *)this + 1) = v6 * v5 + v7 * v3;
  *((long double *)this + 2) = v7 * v5 - v6 * v3;
  v8 = *((double *)this + 4);
  v9 = *((double *)this + 5);
  *((long double *)this + 4) = v8 * v5 + v9 * v3;
  *((long double *)this + 5) = v9 * v5 - v8 * v3;
  v10 = *((double *)this + 7);
  v11 = *((double *)this + 8);
  *((long double *)this + 7) = v10 * v5 + v11 * v3;
  *((long double *)this + 8) = v11 * v5 - v10 * v3;
  if ( a3 )
  {
    v12 = *((double *)this + 5);
    FloatConvertWrapper(this);
    *(double *)a3 = -v12;
    if ( fabs(*((double *)this + 5)) == 1.0 )
    {
      v13 = -*((double *)this + 6);
      v14 = *(double *)this;
      *(_DWORD *)(a3 + 16) = 0;
      *(_DWORD *)(a3 + 20) = 0;
      *(long double *)(a3 + 8) = atan2(v13, v14);
    }
    else
    {
      *(long double *)(a3 + 8) = atan2(*((double *)this + 2), *((double *)this + 8));
      *(long double *)(a3 + 16) = atan2(*((double *)this + 3), *((double *)this + 4));
    }
  }
}

