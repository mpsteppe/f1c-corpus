int __stdcall sub_4E42B0(float a1, _DWORD *a2, float *a3)
{
  unsigned __int64 v3; // rax

  v3 = (unsigned __int64)((double)(int)(unsigned __int64)a1 * 0.016666668);
  *a2 = v3;
  *a3 = a1 - (double)(int)v3 * 60.0;
  return v3;
}
