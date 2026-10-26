float *__stdcall sub_4E42F0(float a1, int *a2, _DWORD *a3, float *a4)
{
  double v4; // st7
  unsigned __int64 v5; // rax
  double v6; // st6
  float *result; // eax
  int v8; // [esp+0h] [ebp-4h]

  v8 = (unsigned __int64)((double)(int)(unsigned __int64)a1 * 0.00027777778);
  *a2 = v8;
  v4 = a1 - (double)v8 * 3600.0;
  v5 = (unsigned __int64)((double)(int)(unsigned __int64)v4 * 0.016666668);
  v6 = (double)(int)v5;
  *a3 = v5;
  result = a4;
  *a4 = v4 - v6 * 60.0;
  return result;
}
