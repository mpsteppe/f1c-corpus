// f1c  0x0043e890  size=240
void __thiscall sub_43E890(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  this[757] = a2 * 0.23 + this[757];
  this[760] = a2 * 0.18 + this[760];
  v4 = this[897] + 0.25;
  v2 = this[897];
  if ( v2 <= this[757] )
  {
    if ( this[757] > v4 )
      this[757] = v4;
  }
  else
  {
    this[757] = v2;
  }
  v5 = this[898] + 0.2;
  v3 = this[898];
  if ( v3 <= this[760] )
  {
    if ( this[760] > v5 )
      this[760] = v5;
  }
  else
  {
    this[760] = v3;
  }
  sub_43BB30(this, this[896]);
}
