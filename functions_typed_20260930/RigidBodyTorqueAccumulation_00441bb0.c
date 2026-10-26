int __thiscall sub_441BB0(int this)
{
  int v2; // esi
  double v3; // st7
  int v4; // eax
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v14; // [esp+10h] [ebp-70h]
  long double v15; // [esp+18h] [ebp-68h]
  double v16; // [esp+20h] [ebp-60h] BYREF
  double v17; // [esp+28h] [ebp-58h]
  double v18; // [esp+30h] [ebp-50h]
  double v19[3]; // [esp+38h] [ebp-48h] BYREF
  long double v20; // [esp+50h] [ebp-30h]
  long double v21; // [esp+58h] [ebp-28h]
  long double v22; // [esp+60h] [ebp-20h]
  double v23[3]; // [esp+68h] [ebp-18h] BYREF

  v2 = *(_DWORD *)(this + 5616);
  Matrix3x3VectorMultiply((double *)(v2 + 28), (double *)(this + 444), &v16);
  v3 = v16 + *(double *)(v2 + 4);
  v4 = *(_DWORD *)(this + 468);
  v5 = v17 + *(double *)(v2 + 12);
  v23[2] = v18 + *(double *)(v2 + 20);
  v6 = v18 * *(double *)(v2 + 132) - v17 * *(double *)(v2 + 140);
  v7 = v16 * *(double *)(v2 + 140) - v18 * *(double *)(v2 + 124);
  v19[2] = v17 * *(double *)(v2 + 124) - v16 * *(double *)(v2 + 132);
  v19[0] = v6 + *(double *)(v2 + 100);
  v19[1] = v7 + *(double *)(v2 + 108);
  v19[2] = v19[2] + *(double *)(v2 + 116);
  v23[0] = v3 - *(double *)(v4 + 4);
  v8 = v5 - *(double *)(v4 + 12);
  v9 = v23[2] - *(double *)(v4 + 20);
  v10 = v19[0] - *(double *)(v4 + 100);
  v11 = v19[1] - *(double *)(v4 + 108);
  v19[2] = v19[2] - *(double *)(v4 + 116);
  v12 = *(double *)(v4 + 172);
  v14 = v12 * *(double *)(this + 472);
  v15 = sqrt(v14 * v12) * *(double *)(this + 480);
  v20 = v10 * v15;
  v21 = v11 * v15;
  v22 = v19[2] * v15;
  v23[0] = v23[0] * v14;
  v23[1] = v8 * v14;
  v19[0] = v23[0] + v20;
  v19[1] = v21 + v23[1];
  v19[2] = v22 + v9 * v14;
  qmemcpy(v23, v19, sizeof(v23));
  *(double *)(v4 + 308) = v19[0] + *(double *)(v4 + 308);
  *(double *)(v4 + 316) = v23[1] + *(double *)(v4 + 316);
  *(double *)(v4 + 324) = v23[2] + *(double *)(v4 + 324);
  return F_3DVectorSubtractWithCrossProduct(&v16, v23);
}

