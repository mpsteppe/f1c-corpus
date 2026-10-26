char __thiscall sub_5A3B50(double *this, int a2, double a3, double a4, const void *a5, int a6)
{
  double v6; // st7
  char result; // al

  if ( a2 != *(_DWORD *)this )
    return 0;
  v6 = a3 - this[1];
  if ( v6 >= 2.0 )
    return 0;
  result = 1;
  *((_BYTE *)this + 16) = 1;
  this[4] = v6 * 0.5 + a4;
  this[3] = a3;
  if ( a6 <= 0 || a6 >= 255 )
  {
    *((_DWORD *)this + 74) = 0;
  }
  else
  {
    *((_DWORD *)this + 74) = a6;
    qmemcpy(this + 5, a5, a6);
  }
  return result;
}
