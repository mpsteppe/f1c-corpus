void __thiscall sub_443150(_DWORD *this, int a2, double *a3)
{
  int v3; // esi
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // [esp+10h] [ebp-50h]
  double v13; // [esp+18h] [ebp-48h] BYREF
  double v14; // [esp+20h] [ebp-40h]
  double v15; // [esp+28h] [ebp-38h]
  double v16[2]; // [esp+30h] [ebp-30h] BYREF
  double v17; // [esp+40h] [ebp-20h]
  double v18[3]; // [esp+48h] [ebp-18h] BYREF

  if ( *(_BYTE *)a2 )
  {
    qmemcpy(v18, (const void *)(a2 + 76), sizeof(v18));
    v3 = this[1404];
    Matrix3x3VectorMultiply((double *)(v3 + 28), v18, &v13);
    v4 = v15 * *(double *)(v3 + 132) - v14 * *(double *)(v3 + 140);
    v5 = v13 * *(double *)(v3 + 140) - v15 * *(double *)(v3 + 124);
    v17 = v14 * *(double *)(v3 + 124) - v13 * *(double *)(v3 + 132);
    v16[0] = v4 + *(double *)(v3 + 100);
    v16[1] = v5 + *(double *)(v3 + 108);
    v17 = v17 + *(double *)(v3 + 116);
    Mat3x3MulVec((double *)(v3 + 28), v16, v18);
    v18[0] = v18[0] - *a3;
    v6 = v18[2] - a3[2];
    if ( v6 < 0.0 )
    {
      v7 = v6 * v6;
      v12 = v7;
      v8 = v18[0] * v18[0] + v7;
      if ( v8 <= 0.0 )
        v9 = 1.0;
      else
        v9 = 1.0 - (1.0 - v7 / v8 * (v7 / v8) * (v7 / v8 * (v7 / v8))) * *(double *)(a2 + 68);
      v10 = v9 * *(double *)(a2 + 52) * v12;
      v11 = *(double *)(a2 + 60) * v12;
      v18[0] = v11 * *(double *)(v3 + 44) + v10 * *(double *)(v3 + 36) + *(double *)(v3 + 28) * 0.0;
      v18[1] = v11 * *(double *)(v3 + 68) + v10 * *(double *)(v3 + 60) + *(double *)(v3 + 52) * 0.0;
      v18[2] = v11 * *(double *)(v3 + 92) + v10 * *(double *)(v3 + 84) + *(double *)(v3 + 76) * 0.0;
      AccumulateAngularMomentum(&v13, v18);
    }
  }
}

