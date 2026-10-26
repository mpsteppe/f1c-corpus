void __thiscall sub_4A00E0(_DWORD *this)
{
  int v1; // eax
  double v2; // st7

  v1 = this[99];
  this[94] = 0;
  if ( v1 )
  {
    v2 = (double)(int)this[96];
    if ( v2 > 0.0 )
      this[94] = (__int64)((double)(int)this[95] / v2 * (double)v1 + 0.5);
  }
}
