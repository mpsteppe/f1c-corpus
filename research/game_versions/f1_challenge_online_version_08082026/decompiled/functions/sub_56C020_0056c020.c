void __thiscall sub_56C020(double *this, double *a2)
{
  long double v2; // st7
  long double v3; // st7
  long double v4; // st6
  long double v5; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // st5
  long double v9; // st7
  long double v10; // st5
  double v11; // st4
  double v12; // st3
  double v13; // st2
  double v14; // st4
  double v15; // st3
  double v16; // st2
  double v17; // rax
  long double v18; // [esp+0h] [ebp-98h]
  long double v19; // [esp+0h] [ebp-98h]
  long double v20; // [esp+0h] [ebp-98h]
  double v21; // [esp+0h] [ebp-98h]
  long double v22; // [esp+8h] [ebp-90h]
  double v23; // [esp+8h] [ebp-90h]
  long double v24; // [esp+20h] [ebp-78h]
  long double v25; // [esp+28h] [ebp-70h]
  long double v26; // [esp+30h] [ebp-68h]
  long double v27; // [esp+38h] [ebp-60h]
  long double v28; // [esp+40h] [ebp-58h]
  long double v29; // [esp+48h] [ebp-50h]
  long double v30; // [esp+68h] [ebp-30h]
  long double v31; // [esp+70h] [ebp-28h]
  long double v32; // [esp+78h] [ebp-20h]
  long double v33; // [esp+80h] [ebp-18h]
  long double v34; // [esp+88h] [ebp-10h]
  long double v35; // [esp+90h] [ebp-8h]

  v2 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( v2 > 0.0 )
  {
    v18 = sqrt(v2);
    v22 = 1.0 / v18;
    v3 = v22 * *a2;
    v4 = v22 * a2[1];
    v5 = v22 * a2[2];
    v6 = sin(v18);
    v7 = cos(v18);
    v19 = 1.0 - v7;
    v26 = v6 * v3;
    v27 = v6 * v4;
    v25 = v6 * v5;
    v28 = v5 * v5;
    v29 = v19 * v4 * v3;
    v8 = v5 * v19;
    v20 = v8 * v3;
    v24 = v8 * v4;
    v9 = (1.0 - v3 * v3) * v7 + v3 * v3;
    v10 = v20 + v27;
    v30 = v29 + v25;
    v31 = (1.0 - v4 * v4) * v7 + v4 * v4;
    v32 = v24 - v26;
    v33 = v20 - v27;
    v34 = v24 + v26;
    v35 = (1.0 - v28) * v7 + v28;
    v11 = *this;
    v12 = this[3];
    v13 = this[6];
    *this = v13 * (v20 + v27) + v12 * (v29 - v25) + v11 * v9;
    this[3] = v32 * v13 + v12 * v31 + v11 * v30;
    this[6] = v13 * v35 + v12 * v34 + v11 * v33;
    v14 = this[1];
    v15 = this[4];
    v16 = this[7];
    this[1] = v16 * (v20 + v27) + v15 * (v29 - v25) + v14 * v9;
    this[4] = v32 * v16 + v15 * v31 + v14 * v30;
    this[7] = v16 * v35 + v15 * v34 + v14 * v33;
    v23 = this[2];
    v21 = this[5];
    v17 = this[8];
    this[2] = v17 * v10 + v21 * (v29 - v25) + v23 * v9;
    this[5] = v17 * v32 + v21 * v31 + v23 * v30;
    this[8] = v17 * v35 + v21 * v34 + v23 * v33;
  }
}
