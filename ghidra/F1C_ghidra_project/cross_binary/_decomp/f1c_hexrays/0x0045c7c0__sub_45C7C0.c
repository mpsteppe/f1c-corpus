// f1c  0x0045c7c0  size=28
int __stdcall sub_45C7C0(__int16 a1, float *a2)
{
  int result; // eax

  result = a1;
  *a2 = (double)a1 * 0.001;
  return result;
}
