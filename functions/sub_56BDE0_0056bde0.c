void __thiscall sub_56BDE0(char *this, double *a2, int a3)
{
  double *v4; // ecx
  long double v5; // st4
  long double v6; // st7
  long double v7; // st6
  long double v8; // st5
  long double v9; // st4
  int v10; // eax
  double *v11; // edx
  long double v12; // st7
  long double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  double v17; // st7
  long double v18; // st7
  long double v19; // st6
  long double v20; // [esp+8h] [ebp-90h]
  long double v21; // [esp+8h] [ebp-90h]
  long double v22; // [esp+10h] [ebp-88h]
  long double v23; // [esp+10h] [ebp-88h]
  double v24; // [esp+20h] [ebp-78h]
  double v25; // [esp+28h] [ebp-70h]
  long double v26; // [esp+30h] [ebp-68h]
  double v27; // [esp+38h] [ebp-60h]
  double v28; // [esp+48h] [ebp-50h]
  double v29; // [esp+50h] [ebp-48h]
  double v30; // [esp+70h] [ebp-28h]
  double v31; // [esp+78h] [ebp-20h]

  v4 = a2;
  v5 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( v5 > 0.0 )
  {
    v22 = sqrt(v5);
    v20 = -1.0 / v22;
    v6 = v20 * *a2;
    v7 = v20 * a2[1];
    v8 = v20 * a2[2];
    v21 = sin(v22);
    v23 = cos(v22);
    v26 = v21 * v6;
    v24 = v21 * v7;
    v25 = v21 * v8;
    v28 = v7 * v6 * (1.0 - v23);
    v27 = v8 * v6 * (1.0 - v23);
    v9 = v8 * v7 * (1.0 - v23);
    v29 = (1.0 - v6 * v6) * v23 + v6 * v6;
    v30 = (1.0 - v7 * v7) * v23 + v7 * v7;
    v31 = v26 + v9;
    v10 = 0;
    v11 = (double *)(this + 16);
    v4 = (double *)(this + 8);
    v12 = v9 - v26;
    v13 = (1.0 - v8 * v8) * v23 + v8 * v8;
    do
    {
      v14 = *(double *)&this[8 * v10];
      v15 = *v4;
      v16 = *v11;
      v10 += 3;
      v4 += 3;
      v11 += 3;
      *(double *)&this[8 * v10 - 24] = (v27 + v24) * v16 + v15 * (v28 - v25) + v14 * v29;
      *(long double *)&this[8 * v10 - 16] = v16 * v12 + v15 * v30 + v14 * (v28 + v25);
      *(long double *)&this[8 * v10 - 8] = v16 * v13 + v15 * v31 + v14 * (v27 - v24);
    }
    while ( v10 < 9 );
  }
  if ( a3 )
  {
    v17 = *((double *)this + 5);
    FloatConvertWrapper(v4);
    *(double *)a3 = -v17;
    if ( fabs(*((double *)this + 5)) == 1.0 )
    {
      v18 = -*((double *)this + 6);
      v19 = *(double *)this;
      *(_DWORD *)(a3 + 16) = 0;
      *(_DWORD *)(a3 + 20) = 0;
      *(long double *)(a3 + 8) = atan2(v18, v19);
    }
    else
    {
      *(long double *)(a3 + 8) = atan2(*((double *)this + 2), *((double *)this + 8));
      *(long double *)(a3 + 16) = atan2(*((double *)this + 3), *((double *)this + 4));
    }
  }
}
