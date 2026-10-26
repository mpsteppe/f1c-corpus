int __fastcall sub_507AC0(float *a1, float *a2, float *a3, float *a4)
{
  int v4; // esi
  double v5; // st7
  double v6; // st6
  long double v7; // st5
  long double v8; // st5
  double v10; // [esp+8h] [ebp-48h]
  double v11; // [esp+10h] [ebp-40h]
  double v12; // [esp+18h] [ebp-38h]
  double v13; // [esp+20h] [ebp-30h]
  double v14; // [esp+28h] [ebp-28h]
  double v15; // [esp+30h] [ebp-20h]
  double v16; // [esp+40h] [ebp-10h]

  v4 = 0;
  v13 = *a1 - *a2;
  v14 = a1[1] - a2[1];
  v15 = a1[2] - a2[2];
  v10 = *a3 - *a2;
  v11 = a3[1] - a2[1];
  v12 = a3[2] - a2[2];
  v5 = v12 * v14 - v11 * v15;
  v16 = v10 * v15 - v12 * v13;
  v6 = v11 * v13 - v10 * v14;
  v7 = v6 * v6 + v16 * v16 + v5 * v5;
  if ( v7 <= 0.0 )
  {
    v4 = -1;
    v8 = 1.0;
  }
  else
  {
    v8 = 1.0 / sqrt(v7);
  }
  *a4 = v8 * v5;
  a4[1] = v16 * v8;
  a4[2] = v8 * v6;
  return v4;
}
