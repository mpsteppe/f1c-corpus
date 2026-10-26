void __fastcall sub_567030(float *a1, float *a2)
{
  long double v2; // st7
  long double v3; // st6
  long double v4; // st5
  long double v5; // rt1
  long double v6; // st4
  long double v7; // st3
  long double v8; // st3
  long double v9; // st5
  float v10; // [esp+0h] [ebp-10h]
  float v11; // [esp+4h] [ebp-Ch]
  float v12; // [esp+8h] [ebp-8h]
  float v13; // [esp+8h] [ebp-8h]
  float v14; // [esp+Ch] [ebp-4h]

  v2 = cos(*a1 * 0.5);
  v3 = sin(*a1 * 0.5);
  v4 = a1[1] * 0.5;
  v5 = cos(v4);
  v6 = sin(v4);
  v7 = a1[2] * 0.5;
  v12 = cos(v7);
  v14 = sin(v7);
  v10 = v12 * v5;
  v8 = v14 * v6;
  v11 = v8;
  *a2 = v8 * v3 + v10 * v2;
  a2[1] = v10 * v3 + v11 * v2;
  v13 = v12 * v6;
  v9 = v5 * v14;
  a2[2] = v13 * v2 - v9 * v3;
  a2[3] = v9 * v2 - v13 * v3;
}

