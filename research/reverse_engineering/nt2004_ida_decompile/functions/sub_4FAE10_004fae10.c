void __thiscall sub_4FAE10(float *this)
{
  double v1; // st7

  v1 = this[88] - dbl_7DA9C8;
  this[88] = v1;
  if ( v1 <= 0.0 )
  {
    this[88] = 1.0;
    sub_4F87B0((int)(this + 89));
  }
}
