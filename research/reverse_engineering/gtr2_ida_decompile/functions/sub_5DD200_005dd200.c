int __thiscall sub_5DD200(float *this, float a2)
{
  int result; // eax

  if ( a2 < (double)this[62] )
  {
    result = *(_DWORD *)this | 4;
    this[63] = this[62];
    *(_DWORD *)this = result;
  }
  else
  {
    result = LODWORD(a2);
    this[63] = a2;
    *(_DWORD *)this |= 4u;
  }
  return result;
}
