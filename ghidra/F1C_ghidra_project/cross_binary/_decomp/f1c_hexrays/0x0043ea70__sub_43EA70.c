// f1c  0x0043ea70  size=108
void __thiscall sub_43EA70(double *this, double a2)
{
  double v2; // st7
  double v3; // [esp+4h] [ebp+4h]

  this[888] = a2 * 0.37 + this[888];
  v3 = this[902] + 0.4;
  v2 = this[902];
  if ( v2 <= this[888] )
  {
    if ( this[888] > v3 )
      this[888] = v3;
  }
  else
  {
    this[888] = v2;
  }
}
