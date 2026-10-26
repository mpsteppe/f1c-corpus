double *__thiscall sub_56D020(_DWORD *this)
{
  double *v2; // ecx
  double *v3; // eax
  double v4; // st7
  double *v5; // edx
  double v6; // st6
  double *v7; // eax
  double *v8; // eax
  double *v9; // eax
  double *v10; // ecx
  double v11; // st7
  double *result; // eax
  double *v13; // esi
  double v14; // st7

  sub_435E00((double *)(this[1] + 28), (double *)(this[2] + 24), (double *)(this[2] + 72));
  sub_435E00((double *)(this[1] + 28), (double *)(this[2] + 48), (double *)(this[2] + 96));
  v2 = (double *)this[3];
  v3 = (double *)(this[2] + 72);
  v4 = *(double *)((char *)v2 + 76) * *(double *)(this[2] + 88);
  v5 = (double *)(this[4] + 24);
  v6 = *(double *)((char *)v2 + 52);
  v2 = (double *)((char *)v2 + 28);
  *v5 = v4 + v6 * *(double *)(this[2] + 80) + *v2 * *v3;
  v5[1] = v2[1] * *v3 + v2[7] * v3[2] + v2[4] * v3[1];
  v5[2] = v2[2] * *v3 + v2[8] * v3[2] + v2[5] * v3[1];
  v7 = (double *)this[4];
  v7[6] = v7[1] * v7[5] - v7[2] * v7[4];
  v7[7] = v7[2] * v7[3] - *v7 * v7[5];
  v7[8] = *v7 * v7[4] - v7[1] * v7[3];
  v8 = (double *)this[4];
  v8[3] = v8[7] * v8[2] - v8[8] * v8[1];
  v8[4] = v8[8] * *v8 - v8[6] * v8[2];
  v8[5] = v8[6] * v8[1] - v8[7] * *v8;
  v9 = (double *)this[4];
  v10 = (double *)this[3];
  v11 = *(double *)((char *)v10 + 44);
  v10 = (double *)((char *)v10 + 28);
  v9[9] = v11 * v9[5] + v10[1] * v9[4] + *v10 * v9[3];
  v9[10] = v10[5] * v9[5] + v10[4] * v9[4] + v10[3] * v9[3];
  v9[11] = v10[8] * v9[5] + v10[7] * v9[4] + v10[6] * v9[3];
  result = (double *)this[4];
  v13 = (double *)this[3];
  v14 = *(double *)((char *)v13 + 44);
  v13 = (double *)((char *)v13 + 28);
  result[12] = v14 * result[8] + v13[1] * result[7] + *v13 * result[6];
  result[13] = v13[5] * result[8] + v13[4] * result[7] + v13[3] * result[6];
  result[14] = v13[8] * result[8] + v13[7] * result[7] + v13[6] * result[6];
  return result;
}
