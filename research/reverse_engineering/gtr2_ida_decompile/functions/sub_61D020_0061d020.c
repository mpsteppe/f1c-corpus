double *__thiscall sub_61D020(_DWORD *this)
{
  double *v1; // eax
  double *v2; // edx
  double v3; // st7
  double *v4; // eax
  double *v5; // edx
  double v6; // st7
  double *v7; // esi
  double *v8; // edx
  double *v9; // eax
  double v10; // st7
  double *v11; // eax
  double *v12; // eax
  double *v13; // eax
  double *v14; // edx
  double v15; // st7
  double *result; // eax
  double *v17; // ecx
  double v18; // st7

  v1 = (double *)this[2];
  v2 = (double *)this[1];
  v3 = v2[6];
  v2 += 4;
  v1[9] = v3 * v1[5] + v2[1] * v1[4] + *v2 * v1[3];
  v1[10] = v2[5] * v1[5] + v2[4] * v1[4] + v2[3] * v1[3];
  v1[11] = v2[8] * v1[5] + v2[7] * v1[4] + v2[6] * v1[3];
  v4 = (double *)this[2];
  v5 = (double *)this[1];
  v6 = v5[6];
  v5 += 4;
  v4[12] = v6 * v4[8] + v5[1] * v4[7] + *v5 * v4[6];
  v4[13] = v5[5] * v4[8] + v5[4] * v4[7] + v5[3] * v4[6];
  v4[14] = v5[8] * v4[8] + v5[7] * v4[7] + v5[6] * v4[6];
  v7 = (double *)(this[4] + 24);
  v8 = (double *)this[3];
  v9 = (double *)(this[2] + 72);
  v10 = v8[10] * *(double *)(this[2] + 88);
  v8 += 4;
  *v7 = v10 + v8[3] * *(double *)(this[2] + 80) + *v8 * *v9;
  v7[1] = v8[7] * v9[2] + v8[4] * v9[1] + v8[1] * *v9;
  v7[2] = v8[8] * v9[2] + v8[5] * v9[1] + v8[2] * *v9;
  v11 = (double *)this[4];
  v11[6] = v11[5] * v11[1] - v11[4] * v11[2];
  v11[7] = v11[3] * v11[2] - v11[5] * *v11;
  v11[8] = v11[4] * *v11 - v11[3] * v11[1];
  v12 = (double *)this[4];
  v12[3] = v12[2] * v12[7] - v12[1] * v12[8];
  v12[4] = v12[8] * *v12 - v12[2] * v12[6];
  v12[5] = v12[1] * v12[6] - v12[7] * *v12;
  v13 = (double *)this[4];
  v14 = (double *)this[3];
  v15 = v14[6];
  v14 += 4;
  v13[9] = v15 * v13[5] + v14[1] * v13[4] + *v14 * v13[3];
  v13[10] = v14[3] * v13[3] + v14[5] * v13[5] + v14[4] * v13[4];
  v13[11] = v14[6] * v13[3] + v14[8] * v13[5] + v14[7] * v13[4];
  result = (double *)this[4];
  v17 = (double *)this[3];
  v18 = v17[6];
  v17 += 4;
  result[12] = v18 * result[8] + v17[1] * result[7] + *v17 * result[6];
  result[13] = v17[5] * result[8] + v17[4] * result[7] + v17[3] * result[6];
  result[14] = v17[8] * result[8] + v17[7] * result[7] + v17[6] * result[6];
  return result;
}
