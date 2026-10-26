void __thiscall sub_43EAE0(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  this[763] = a2 * 0.23 + this[763];
  this[766] = a2 * 0.18 + this[766];
  v4 = this[904] + 0.25;
  v2 = this[904];
  if ( v2 <= this[763] )
  {
    if ( this[763] > v4 )
      this[763] = v4;
  }
  else
  {
    this[763] = v2;
  }
  v5 = this[905] + 0.2;
  v3 = this[905];
  if ( v3 <= this[766] )
  {
    if ( this[766] > v5 )
      this[766] = v5;
  }
  else
  {
    this[766] = v3;
  }
  sub_43BB80(this, this[903]);
}
