void __thiscall sub_4CE550(_DWORD *this)
{
  int v1; // eax
  double v2; // st7

  v1 = this[144];
  this[139] = 0;
  if ( v1 )
  {
    v2 = (double)(int)this[141];
    if ( v2 > 0.0 )
      this[139] = (unsigned __int64)((double)(int)this[140] / v2 * (double)v1 + 0.5);
  }
}
