int __thiscall sub_415CD0(float *this)
{
  int v1; // eax

  if ( *(_DWORD *)this != 4 )
    return *(_DWORD *)this;
  v1 = *((_DWORD *)this + 34);
  this[39] = dbl_FB1D10 + this[39];
  this[38] = dbl_FB1D10 + this[38];
  if ( v1 )
    return off_16C962C();
  *this = NAN;
  return *(_DWORD *)this;
}
