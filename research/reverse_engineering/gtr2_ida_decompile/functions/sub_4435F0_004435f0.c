void __thiscall sub_4435F0(double *this, double a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // [esp+4h] [ebp+4h]
  double v6; // [esp+4h] [ebp+4h]

  this[903] = a2 * 0.23 + this[903];
  this[906] = a2 * 0.18 + this[906];
  v5 = this[1071] + 0.25;
  v2 = this[1071];
  if ( v2 <= this[903] )
  {
    if ( this[903] <= v5 )
      goto LABEL_5;
    v2 = v5;
  }
  this[903] = v2;
LABEL_5:
  v6 = this[1072] + 0.2;
  v3 = this[1072];
  if ( v3 > this[906] )
  {
LABEL_8:
    this[906] = v3;
    goto LABEL_9;
  }
  if ( this[906] > v6 )
  {
    v3 = v6;
    goto LABEL_8;
  }
LABEL_9:
  v4 = this[1070];
  this[960] = v4 * this[905] * v4 + v4 * this[904] + this[903];
  this[986] = v4 * this[908] * v4 + v4 * this[907] + this[906];
}
