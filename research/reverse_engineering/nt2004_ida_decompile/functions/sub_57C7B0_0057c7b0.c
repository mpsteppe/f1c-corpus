double *__thiscall sub_57C7B0(int this, double *a2, double *a3)
{
  double *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st7
  double v8; // [esp+8h] [ebp-10h]

  result = a3;
  *(double *)(this + 308) = *a3 + *(double *)(this + 308);
  *(double *)(this + 316) = a3[1] + *(double *)(this + 316);
  *(double *)(this + 324) = a3[2] + *(double *)(this + 324);
  v4 = *a2 - *(double *)(this + 4);
  v5 = a2[1] - *(double *)(this + 12);
  v6 = a2[2] - *(double *)(this + 20);
  v8 = v6 * *result - v4 * result[2];
  v7 = v4 * result[1] - v5 * *result;
  *(double *)(this + 332) = v5 * a3[2] - v6 * a3[1] + *(double *)(this + 332);
  *(double *)(this + 340) = v8 + *(double *)(this + 340);
  *(double *)(this + 348) = v7 + *(double *)(this + 348);
  return result;
}
