void __thiscall sub_438AF0(double *this, int a2, int a3, double a4, double a5)
{
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  this[1] = a4 + a4;
  if ( a4 <= 0.0 )
  {
    *((_DWORD *)this + 4) = 0;
    *((_DWORD *)this + 5) = 0;
  }
  else
  {
    this[2] = 3.141592653589793 / a4;
  }
  this[3] = (a5 - 1.0) * 0.5;
}
