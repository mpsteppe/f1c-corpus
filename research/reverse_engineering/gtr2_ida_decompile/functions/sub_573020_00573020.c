double __thiscall sub_573020(float *this)
{
  double result; // st7
  float v2; // [esp+0h] [ebp-4h]

  if ( this[4316] == 0.0 )
    return 0.0;
  if ( this[4309] == 0.0 )
    return 0.0;
  v2 = this[4004] - (this[4354] * this[3992] + this[4353] * this[3989] + this[3986] * this[4352]);
  result = (v2 * this[4595] * v2 * this[4594] / this[4316] - this[4308]) / this[4309];
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
