double *__thiscall sub_57C400(int this, double *a2, double *a3)
{
  double v3; // st7
  double *result; // eax
  double v6; // st6
  double v7; // [esp+8h] [ebp-10h]
  double v8; // [esp+10h] [ebp-8h]
  double v9; // [esp+10h] [ebp-8h]

  v3 = *(double *)(this + 180);
  result = a2;
  v7 = v3 * a2[1];
  v8 = v3 * a2[2];
  *(double *)(this + 100) = v3 * *a2 + *(double *)(this + 100);
  *(double *)(this + 108) = v7 + *(double *)(this + 108);
  *(double *)(this + 116) = v8 + *(double *)(this + 116);
  v6 = *a3 * result[2] - a3[2] * *result;
  v9 = a3[1] * *result - result[1] * *a3;
  *(double *)(this + 148) = a2[1] * a3[2] - a3[1] * a2[2] + *(double *)(this + 148);
  *(double *)(this + 156) = v6 + *(double *)(this + 156);
  *(double *)(this + 164) = v9 + *(double *)(this + 164);
  *(double *)(this + 124) = *(double *)(this + 252) * *(double *)(this + 164)
                          + *(double *)(this + 244) * *(double *)(this + 156)
                          + *(double *)(this + 148) * *(double *)(this + 236);
  *(double *)(this + 132) = *(double *)(this + 260) * *(double *)(this + 148)
                          + *(double *)(this + 276) * *(double *)(this + 164)
                          + *(double *)(this + 268) * *(double *)(this + 156);
  *(double *)(this + 140) = *(double *)(this + 284) * *(double *)(this + 148)
                          + *(double *)(this + 300) * *(double *)(this + 164)
                          + *(double *)(this + 292) * *(double *)(this + 156);
  return result;
}
