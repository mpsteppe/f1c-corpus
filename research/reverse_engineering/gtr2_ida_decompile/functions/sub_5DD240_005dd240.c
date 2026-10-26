void __thiscall sub_5DD240(float *this, float a2)
{
  if ( a2 >= 0.0 && a2 <= 1.0 )
  {
    this[61] = a2;
    *(_DWORD *)this |= 4u;
  }
}
