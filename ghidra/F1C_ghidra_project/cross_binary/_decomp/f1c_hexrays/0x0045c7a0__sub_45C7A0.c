// f1c  0x0045c7a0  size=31
int __stdcall sub_45C7A0(float a1, _WORD *a2)
{
  int result; // eax

  result = sub_587BDC(a1 * 999.99994 + 0.5);
  *a2 = result;
  return result;
}
