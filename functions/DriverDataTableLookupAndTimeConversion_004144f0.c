void __thiscall sub_4144F0(float *this, int a2, int a3, int a4, int a5, int a6, float a7, float a8)
{
  double v9; // st7

  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 6) = a5;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 5) = a4;
  *((_DWORD *)this + 7) = a6;
  if ( a6 == -1 )
    *((_DWORD *)this + 7) = dword_5BF9A0[5 * a2];
  if ( a7 == -2.0 )
    a7 = flt_5BF9A8[5 * a2];
  if ( a8 == -2.0 )
    a8 = flt_5BF9A4[5 * a2];
  v9 = (double)CRTFtol((dbl_8AFEA8 + a7) * 5.0) * 0.2;
  this[2] = v9;
  if ( a8 == -1.0 )
    this[3] = -1.0;
  else
    this[3] = v9 + a8 + 0.2;
}
