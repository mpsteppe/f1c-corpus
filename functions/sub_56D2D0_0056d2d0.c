double *__thiscall sub_56D2D0(int this)
{
  double *v2; // ecx
  int v3; // eax
  double v4; // st7
  double *v5; // edx
  double v6; // st6
  double v7; // st5
  double *result; // eax
  double v9; // st5
  double v10; // st6
  long double v11; // st7
  double v12[3]; // [esp+Ch] [ebp-48h] BYREF
  double v13[3]; // [esp+24h] [ebp-30h] BYREF
  double v14; // [esp+4Ch] [ebp-8h]

  Matrix3x3VectorMultiply(
    (double *)(*(_DWORD *)(this + 4) + 28),
    *(double **)(this + 8),
    (double *)(*(_DWORD *)(this + 8) + 24));
  Matrix3x3VectorMultiply(
    (double *)(*(_DWORD *)(this + 12) + 28),
    *(double **)(this + 16),
    (double *)(*(_DWORD *)(this + 16) + 24));
  v2 = *(double **)(this + 16);
  v3 = *(_DWORD *)(this + 12);
  v4 = v2[3] + *(double *)(v3 + 4);
  v5 = *(double **)(this + 8);
  v6 = v2[4] + *(double *)(v3 + 12);
  v7 = v2[5] + *(double *)(v3 + 20);
  result = (double *)(*(_DWORD *)(this + 4) + 4);
  v14 = v7;
  v9 = *result + v5[3];
  v12[1] = v5[4] + result[1];
  v12[2] = v5[5] + result[2];
  v13[0] = v9 - v4;
  v13[1] = v12[1] - v6;
  v10 = v12[2] - v14;
  v13[2] = v12[2] - v14;
  qmemcpy(v12, v13, sizeof(v12));
  v11 = 1.0 / sqrt(v10 * v10 + v13[1] * v13[1] + v13[0] * v13[0]);
  v12[0] = v13[0] * v11;
  v12[1] = v12[1] * v11;
  v12[2] = v12[2] * v11;
  qmemcpy(v5 + 8, v12, 0x18u);
  qmemcpy((void *)(*(_DWORD *)(this + 16) + 64), v12, 0x18u);
  return result;
}
