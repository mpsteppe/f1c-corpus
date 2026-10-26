void __thiscall sub_438950(double *this, double *a2, double *a3, double *a4, double *a5)
{
  double *v5; // eax
  double v6; // st7
  double v7; // st7
  int v8; // eax
  double *v9; // eax
  double v10; // st6
  double v11; // st6
  int v12; // eax
  double *v13; // eax
  double v14; // st5
  double v15; // st4
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19[3]; // [esp+8h] [ebp-48h] BYREF
  double v20; // [esp+20h] [ebp-30h]
  double v21; // [esp+28h] [ebp-28h]
  double v22; // [esp+30h] [ebp-20h]
  double v23; // [esp+40h] [ebp-10h]
  double v24; // [esp+48h] [ebp-8h]

  v5 = &this[3 * (*a2 <= 0.0)];
  v6 = *a2 * *a2;
  v19[0] = v6 * *v5;
  v19[1] = v6 * v5[1];
  v7 = v6 * v5[2];
  v8 = 2;
  if ( a2[1] <= 0.0 )
    v8 = 3;
  v9 = &this[3 * v8];
  v10 = a2[1] * a2[1];
  v20 = v10 * *v9;
  v21 = v10 * v9[1];
  v11 = v10 * v9[2];
  v12 = 4;
  if ( a2[2] <= 0.0 )
    v12 = 5;
  v13 = &this[3 * v12];
  v14 = a2[2] * a2[2];
  v15 = v14 * *v13;
  v23 = v14 * v13[1];
  v24 = v14 * v13[2];
  v21 = v19[1] + v21;
  v22 = v7 + v11;
  v19[0] = v20 + v19[0] + v15;
  v19[1] = v23 + v21;
  v19[2] = v24 + v22;
  qmemcpy(a4, v19, 0x18u);
  v16 = this[18] * *a3 * *a3;
  *a5 = v16;
  if ( *a3 > 0.0 )
    *a5 = -v16;
  v17 = this[19] * a3[1] * a3[1];
  a5[1] = v17;
  if ( a3[1] > 0.0 )
    a5[1] = -v17;
  v18 = this[20] * a3[2] * a3[2];
  a5[2] = v18;
  if ( a3[2] > 0.0 )
    a5[2] = -v18;
}
