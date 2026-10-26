double *__thiscall sub_61CF70(_DWORD *this)
{
  double *v1; // eax
  double *v2; // edx
  double v3; // st7
  double *result; // eax
  double *v5; // ecx
  double v6; // st7

  v1 = (double *)this[2];
  v2 = (double *)this[1];
  v3 = v2[6];
  v2 += 4;
  v1[3] = v3 * v1[2] + v2[1] * v1[1] + *v2 * *v1;
  v1[4] = v2[5] * v1[2] + v2[4] * v1[1] + v2[3] * *v1;
  v1[5] = v2[8] * v1[2] + v2[7] * v1[1] + v2[6] * *v1;
  result = (double *)this[4];
  v5 = (double *)this[3];
  v6 = v5[6];
  v5 += 4;
  result[3] = v6 * result[2] + v5[1] * result[1] + *v5 * *result;
  result[4] = v5[5] * result[2] + v5[4] * result[1] + v5[3] * *result;
  result[5] = v5[8] * result[2] + v5[7] * result[1] + v5[6] * *result;
  return result;
}
