void __thiscall sub_43BB60(double *this, int a2)
{
  bool v2; // zf
  double *v3; // edx

  v2 = *(_BYTE *)a2 == 0;
  *(_BYTE *)this = *(_BYTE *)a2;
  if ( !v2 )
  {
    this[1] = *(double *)(a2 + 32);
    this[2] = *(double *)(a2 + 40);
    this[3] = *(double *)(a2 + 48);
    this[4] = *(double *)(a2 + 8);
    this[5] = *(double *)(a2 + 16);
    this[6] = *(double *)(a2 + 24);
    sub_439420(this + 9, *(double *)(a2 + 56), *(double *)(a2 + 64), *(double *)(a2 + 72));
    v3[13] = 0.0;
    v3[14] = 0.0;
    v3[15] = 0.0;
  }
}
