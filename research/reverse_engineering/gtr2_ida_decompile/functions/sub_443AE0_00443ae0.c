void __thiscall sub_443AE0(double *this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // [esp+0h] [ebp-8h]
  double v5; // [esp+0h] [ebp-8h]

  v4 = this[1071];
  v1 = v4;
  if ( v4 <= this[903] )
  {
    if ( this[903] <= v4 )
      goto LABEL_5;
    v1 = v4;
  }
  this[903] = v1;
LABEL_5:
  v5 = this[1072];
  v2 = v5;
  if ( v5 > this[906] )
  {
LABEL_8:
    this[906] = v2;
    goto LABEL_9;
  }
  if ( this[906] > v5 )
  {
    v2 = v5;
    goto LABEL_8;
  }
LABEL_9:
  v3 = this[1070];
  this[960] = v3 * this[905] * v3 + v3 * this[904] + this[903];
  this[986] = v3 * this[908] * v3 + v3 * this[907] + this[906];
}
