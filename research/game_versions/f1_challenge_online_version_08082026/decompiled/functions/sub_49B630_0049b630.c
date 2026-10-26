int __stdcall sub_49B630(float a1, _DWORD *a2, float *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = sub_587BDC(a1);
  result = sub_587BDC((double)v4 * 0.016666668);
  *a2 = result;
  *a3 = a1 - (double)result * 60.0;
  return result;
}
