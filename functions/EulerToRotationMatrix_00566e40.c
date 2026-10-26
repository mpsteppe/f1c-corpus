void __fastcall sub_566E40(float *a1, float *a2)
{
  long double v2; // st7
  long double v3; // st6
  long double v4; // st5
  long double v5; // st4
  long double v6; // st3
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v2 = sin(*a1);
  v3 = cos(*a1);
  v4 = sin(a1[1]);
  v7 = cos(a1[1]);
  v5 = sin(a1[2]);
  v6 = cos(a1[2]);
  v9 = v6 * v7;
  v8 = v5 * v7;
  *a2 = v4 * v2 * v5 + v9;
  a2[1] = v4 * v2 * v6 - v8;
  a2[2] = v4 * v3;
  a2[3] = v5 * v3;
  a2[4] = v6 * v3;
  a2[5] = -v2;
  a2[6] = v8 * v2 - v6 * v4;
  a2[7] = v5 * v4 + v9 * v2;
  a2[8] = v7 * v3;
}
