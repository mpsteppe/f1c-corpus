int __fastcall sub_5676C0(_DWORD *a1, float *a2, float a3)
{
  int result; // eax

  result = CRTFtol(a3 * 0.016666668);
  *a1 = result;
  *a2 = a3 - (double)result * 60.0;
  return result;
}

