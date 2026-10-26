unsigned __int64 __fastcall sub_6153C0(_DWORD *a1, float *a2, float a3)
{
  unsigned __int64 result; // rax

  result = (unsigned __int64)(a3 * 0.016666668);
  *a1 = result;
  *a2 = a3 - (double)(int)result * 60.0;
  return result;
}
