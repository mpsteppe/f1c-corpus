void __thiscall sub_57EB70(char *this, double *a2, int a3)
{
  long double v4; // st7
  long double v5; // st7
  long double v6; // st6
  long double v7; // st5
  long double v8; // st4
  int v9; // eax
  double *v10; // edx
  double *v11; // ecx
  long double v12; // st7
  long double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  long double v17; // st7
  long double v18; // st6
  long double v19; // [esp+8h] [ebp-90h]
  long double v20; // [esp+8h] [ebp-90h]
  long double v21; // [esp+10h] [ebp-88h]
  long double v22; // [esp+10h] [ebp-88h]
  double v23; // [esp+20h] [ebp-78h]
  double v24; // [esp+28h] [ebp-70h]
  long double v25; // [esp+30h] [ebp-68h]
  double v26; // [esp+38h] [ebp-60h]
  double v27; // [esp+48h] [ebp-50h]
  double v28; // [esp+50h] [ebp-48h]
  double v29; // [esp+70h] [ebp-28h]
  double v30; // [esp+78h] [ebp-20h]

  v4 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( v4 > 0.0 )
  {
    v21 = sqrt(v4);
    v19 = -1.0 / v21;
    v5 = v19 * *a2;
    v6 = v19 * a2[1];
    v7 = v19 * a2[2];
    v20 = sin(v21);
    v22 = cos(v21);
    v25 = v20 * v5;
    v23 = v20 * v6;
    v24 = v20 * v7;
    v27 = v6 * v5 * (1.0 - v22);
    v26 = v7 * v5 * (1.0 - v22);
    v8 = v7 * v6 * (1.0 - v22);
    v28 = (1.0 - v5 * v5) * v22 + v5 * v5;
    v29 = (1.0 - v6 * v6) * v22 + v6 * v6;
    v30 = v25 + v8;
    v9 = 0;
    v10 = (double *)(this + 16);
    v11 = (double *)(this + 8);
    v12 = v8 - v25;
    v13 = (1.0 - v7 * v7) * v22 + v7 * v7;
    do
    {
      v14 = *(double *)&this[8 * v9];
      v15 = *v11;
      v16 = *v10;
      v9 += 3;
      v11 += 3;
      v10 += 3;
      *(double *)&this[8 * v9 - 24] = (v26 + v23) * v16 + v15 * (v27 - v24) + v14 * v28;
      *(long double *)&this[8 * v9 - 16] = v16 * v12 + v15 * v29 + v14 * (v27 + v24);
      *(long double *)&this[8 * v9 - 8] = v16 * v13 + v15 * v30 + v14 * (v26 - v23);
    }
    while ( v9 < 9 );
  }
  if ( a3 )
  {
    *(long double *)a3 = -asin(*((double *)this + 5));
    if ( fabs(*((double *)this + 5)) == 1.0 )
    {
      v17 = -*((double *)this + 6);
      v18 = *(double *)this;
      *(_DWORD *)(a3 + 16) = 0;
      *(_DWORD *)(a3 + 20) = 0;
      *(long double *)(a3 + 8) = atan2(v17, v18);
    }
    else
    {
      *(long double *)(a3 + 8) = atan2(*((double *)this + 2), *((double *)this + 8));
      *(long double *)(a3 + 16) = atan2(*((double *)this + 3), *((double *)this + 4));
    }
  }
}
