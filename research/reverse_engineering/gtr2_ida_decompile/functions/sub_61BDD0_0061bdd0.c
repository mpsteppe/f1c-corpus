void __fastcall sub_61BDD0(double *a1, double *a2, double *a3, double *a4)
{
  double *v4; // esi
  double v5; // st7
  long double v6; // st4
  double v7; // st7
  double v8; // st6
  double v9; // st7
  long double v10; // st7
  long double v11; // st4
  long double v12; // [esp+8h] [ebp-60h]
  double v13; // [esp+10h] [ebp-58h]
  double v14; // [esp+18h] [ebp-50h]
  double v15; // [esp+20h] [ebp-48h] BYREF
  char v16; // [esp+38h] [ebp-30h] BYREF
  char v17; // [esp+50h] [ebp-18h] BYREF

  if ( !a2 )
    a2 = (double *)&v16;
  v4 = a3;
  if ( !a3 )
    v4 = &v15;
  if ( !a4 )
    v4 = (double *)&v17;
  *a2 = *a1;
  a2[1] = a1[1];
  v5 = a1[2];
  a2[2] = v5;
  v6 = 1.0 / sqrt(*a2 * *a2 + a2[1] * a2[1] + v5 * v5);
  v12 = v6 * *a2;
  *a2 = v12;
  v13 = v6 * a2[1];
  a2[1] = v13;
  v14 = v6 * a2[2];
  a2[2] = v14;
  v15 = 0.0;
  v7 = 0.0;
  if ( fabs(v12) >= 0.7 )
  {
    v7 = 1.0;
    v8 = v15;
  }
  else
  {
    v8 = 1.0;
  }
  *v4 = v13 * 0.0 - v14 * v7;
  v4[1] = v8 * a2[2] - *a2 * 0.0;
  v9 = v7 * *a2 - v8 * a2[1];
  v4[2] = v9;
  *a4 = v9 * a2[1] - v4[1] * a2[2];
  a4[1] = *v4 * a2[2] - *a2 * v4[2];
  a4[2] = *a2 * v4[1] - a2[1] * *v4;
  v10 = 1.0 / sqrt(*v4 * *v4 + v4[1] * v4[1] + v4[2] * v4[2]);
  *v4 = v10 * *v4;
  v4[1] = v10 * v4[1];
  v4[2] = v10 * v4[2];
  v11 = 1.0 / sqrt(*a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2]);
  *a4 = v11 * *a4;
  a4[1] = v11 * a4[1];
  a4[2] = v11 * a4[2];
}
