char __thiscall sub_573770(char *this, int a2, double a3, double a4, const void *a5, int a6)
{
  double v6; // st7
  char result; // al

  if ( a2 != *(_DWORD *)this )
    return 0;
  v6 = a3 - *(double *)(this + 4);
  if ( v6 >= 2.0 )
    return 0;
  *((_DWORD *)this + 4) = LODWORD(a3);
  result = 1;
  this[12] = 1;
  *((_DWORD *)this + 5) = HIDWORD(a3);
  *((double *)this + 3) = v6 * 0.5 + a4;
  if ( a6 <= 0 || a6 >= 255 )
  {
    *((_DWORD *)this + 72) = 0;
  }
  else
  {
    *((_DWORD *)this + 72) = a6;
    qmemcpy(this + 32, a5, a6);
  }
  return result;
}
