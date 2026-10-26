// f1c  0x0043e980  size=240
void __thiscall sub_43E980(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  this[769] = a2 * 0.23 + this[769];
  this[771] = a2 * 0.18 + this[771];
  v4 = this[900] + 0.25;
  v2 = this[900];
  if ( v2 <= this[769] )
  {
    if ( this[769] > v4 )
      this[769] = v4;
  }
  else
  {
    this[769] = v2;
  }
  v5 = this[901] + 0.2;
  v3 = this[901];
  if ( v3 <= this[771] )
  {
    if ( this[771] > v5 )
      this[771] = v5;
  }
  else
  {
    this[771] = v3;
  }
  sub_43BBD0(this, this[899]);
}
