double *__thiscall sub_57C860(int this, double *a2, double *a3)
{
  double *result; // eax
  double v5; // st6
  double v6; // [esp+10h] [ebp-8h]

  result = a3;
  *(double *)(this + 308) = *(double *)(this + 308) + *a3;
  *(double *)(this + 316) = a3[1] + *(double *)(this + 316);
  *(double *)(this + 324) = a3[2] + *(double *)(this + 324);
  v5 = a2[2] * *result - result[2] * *a2;
  v6 = result[1] * *a2 - *result * a2[1];
  *(double *)(this + 332) = a3[2] * a2[1] - a3[1] * a2[2] + *(double *)(this + 332);
  *(double *)(this + 340) = v5 + *(double *)(this + 340);
  *(double *)(this + 348) = v6 + *(double *)(this + 348);
  return result;
}
