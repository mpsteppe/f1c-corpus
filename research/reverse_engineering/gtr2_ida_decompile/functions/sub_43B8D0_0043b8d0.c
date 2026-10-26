void __thiscall sub_43B8D0(double *this, double *a2, double *a3, double *a4, double *a5)
{
  double *v5; // eax
  double v6; // st7
  int v7; // eax
  double *v8; // eax
  double v9; // st7
  int v10; // eax
  double *v11; // eax
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // [esp+20h] [ebp-48h]
  double v18; // [esp+20h] [ebp-48h]
  double v19; // [esp+28h] [ebp-40h]
  double v20; // [esp+30h] [ebp-38h]
  double v21; // [esp+38h] [ebp-30h]
  double v22; // [esp+40h] [ebp-28h]
  double v23; // [esp+48h] [ebp-20h]
  double v24; // [esp+60h] [ebp-8h]

  v5 = &this[3 * (*a2 <= 0.0)];
  v6 = *a2 * *a2;
  v21 = v6 * *v5;
  v22 = v6 * v5[1];
  v23 = v6 * v5[2];
  v7 = 2;
  if ( a2[1] <= 0.0 )
    v7 = 3;
  v8 = &this[3 * v7];
  v9 = a2[1] * a2[1];
  v17 = v9 * *v8;
  v19 = v9 * v8[1];
  v20 = v9 * v8[2];
  v10 = 4;
  if ( a2[2] <= 0.0 )
    v10 = 5;
  v11 = &this[3 * v10];
  v12 = a2[2] * a2[2];
  v24 = v12 * v11[2];
  v18 = v12 * *v11 + v17 + v21;
  v13 = v12 * v11[1];
  *a4 = v18;
  a4[1] = v13 + v19 + v22;
  a4[2] = v24 + v20 + v23;
  v14 = this[18] * *a3 * *a3;
  *a5 = v14;
  if ( *a3 > 0.0 )
    *a5 = -v14;
  v15 = this[19] * a3[1] * a3[1];
  a5[1] = v15;
  if ( a3[1] > 0.0 )
    a5[1] = -v15;
  v16 = this[20] * a3[2] * a3[2];
  a5[2] = v16;
  if ( a3[2] > 0.0 )
    a5[2] = -v16;
}
