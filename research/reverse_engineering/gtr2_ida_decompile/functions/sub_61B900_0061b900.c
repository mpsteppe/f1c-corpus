void __thiscall sub_61B900(double *this, double *a2, int a3)
{
  long double v3; // st4
  long double v4; // st7
  long double v5; // st6
  long double v6; // st5
  long double v7; // st4
  int v8; // eax
  char *v9; // edx
  long double v10; // st7
  long double v11; // st6
  double v12; // st5
  int v13; // eax
  double v14; // st4
  char *v15; // edx
  double v16; // st3
  long double v17; // [esp+0h] [ebp-90h]
  long double v18; // [esp+0h] [ebp-90h]
  long double v19; // [esp+8h] [ebp-88h]
  long double v20; // [esp+8h] [ebp-88h]
  double v21; // [esp+18h] [ebp-78h]
  double v22; // [esp+20h] [ebp-70h]
  long double v23; // [esp+28h] [ebp-68h]
  double v24; // [esp+30h] [ebp-60h]
  double v25; // [esp+40h] [ebp-50h]
  double v26; // [esp+48h] [ebp-48h]
  double v27; // [esp+68h] [ebp-28h]
  double v28; // [esp+70h] [ebp-20h]

  v3 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( v3 > 0.0 )
  {
    v19 = sqrt(v3);
    v17 = -1.0 / v19;
    v4 = v17 * *a2;
    v5 = v17 * a2[1];
    v6 = v17 * a2[2];
    v18 = sin(v19);
    v20 = cos(v19);
    v23 = v18 * v4;
    v21 = v18 * v5;
    v22 = v18 * v6;
    v25 = v5 * v4 * (1.0 - v20);
    v24 = v6 * v4 * (1.0 - v20);
    v7 = v6 * v5 * (1.0 - v20);
    v26 = (1.0 - v4 * v4) * v20 + v4 * v4;
    v27 = (1.0 - v5 * v5) * v20 + v5 * v5;
    v28 = v23 + v7;
    v8 = 0;
    v9 = (char *)(this + 2);
    v10 = v7 - v23;
    v11 = (1.0 - v6 * v6) * v20 + v6 * v6;
    do
    {
      v12 = this[v8];
      v13 = v8 + 1;
      v14 = this[v13];
      v15 = v9 + 8;
      v16 = *((double *)v15 - 1);
      v8 = v13 + 2;
      v9 = v15 + 16;
      this[v8 - 3] = (v24 + v21) * v16 + v14 * (v25 - v22) + v12 * v26;
      this[v8 - 2] = v16 * v10 + v14 * v27 + v12 * (v25 + v22);
      this[v8 - 1] = v16 * v11 + v14 * v28 + v12 * (v24 - v21);
    }
    while ( v8 < 9 );
  }
  if ( a3 )
    sub_43A2B0((int)this, a3);
}
