double *__thiscall sub_45D210(double *this, double *a2, float *a3)
{
  double *v3; // esi
  float v5; // [esp+0h] [ebp-14h]
  float v6; // [esp+4h] [ebp-10h]

  v3 = (double *)sub_45D190(this, (int)a2);
  if ( v3 )
  {
    v6 = a2[2];
    v5 = *a2;
    sub_45A280(v3, v5, v6, a3);
  }
  return v3;
}
