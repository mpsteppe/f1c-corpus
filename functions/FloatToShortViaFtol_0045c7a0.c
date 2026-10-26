int __stdcall sub_45C7A0(float a1, _WORD *a2)
{
  int result; // eax

  result = CRTFtol(a1 * 999.99994 + 0.5);
  *a2 = result;
  return result;
}
