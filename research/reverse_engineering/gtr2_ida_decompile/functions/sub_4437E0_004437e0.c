void __thiscall sub_4437E0(double *this, double a2)
{
  double v2; // st7
  double v3; // [esp+4h] [ebp+4h]

  this[1049] = a2 * 0.37 + this[1049];
  v3 = this[1076] + 0.4;
  v2 = this[1076];
  if ( v2 <= this[1049] )
  {
    if ( this[1049] <= v3 )
      return;
    v2 = v3;
  }
  this[1049] = v2;
}
