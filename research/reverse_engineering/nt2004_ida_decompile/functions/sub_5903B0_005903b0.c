float *__stdcall sub_5903B0(int a1, float *a2)
{
  float *result; // eax

  result = a2;
  a2[2] = (double)(unsigned __int8)a1 * 0.0039215689;
  a2[1] = (double)BYTE1(a1) * 0.0039215689;
  *a2 = (double)BYTE2(a1) * 0.0039215689;
  return result;
}
