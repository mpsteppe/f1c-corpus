void __fastcall sub_579360(float *a1, float *a2)
{
  double v2; // st7
  double v3; // st5
  double v4; // st4
  double v5; // st7
  double v6; // st6
  float v7; // [esp+0h] [ebp-1Ch]
  float v8; // [esp+4h] [ebp-18h]
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+Ch] [ebp-10h]
  float v11; // [esp+10h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-8h]
  float v13; // [esp+18h] [ebp-4h]

  v2 = a1[1] + a1[1];
  v3 = a1[2] + a1[2];
  v13 = v3 * a1[2];
  v4 = a1[3] + a1[3];
  v9 = v4 * a1[3];
  v10 = v4 * a1[1];
  v8 = v3 * a1[1];
  v11 = v3 * *a1;
  v12 = v2 * *a1;
  v5 = v2 * a1[1];
  v7 = v4 * *a1;
  v6 = v4 * a1[2];
  *a2 = 1.0 - (v9 + v13);
  a2[1] = v8 - v7;
  a2[2] = v11 + v10;
  a2[3] = v7 + v8;
  a2[4] = 1.0 - (v9 + v5);
  a2[5] = v6 - v12;
  a2[6] = v10 - v11;
  a2[7] = v6 + v12;
  a2[8] = 1.0 - (v13 + v5);
}
