float *__fastcall sub_615400(int *a1, int *a2, float a3, float *a4)
{
  double v4; // st7
  float *result; // eax
  int v6; // [esp+0h] [ebp-4h]
  int v7; // [esp+8h] [ebp+4h]

  v6 = (unsigned __int64)(a3 * 0.00027777778);
  *a1 = v6;
  v4 = a3 - (double)v6 * 3600.0;
  v7 = (unsigned __int64)(0.016666668 * v4);
  *a2 = v7;
  result = a4;
  *a4 = v4 - (double)v7 * 60.0;
  return result;
}
