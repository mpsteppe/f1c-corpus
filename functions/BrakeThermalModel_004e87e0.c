double __thiscall sub_4E87E0(float *this)
{
  double result; // st7
  float v2; // [esp+0h] [ebp-4h]

  if ( this[3698] == 0.0 )
    return 0.0;
  if ( this[3691] == 0.0 )
    return 0.0;
  v2 = this[3392] - (this[3736] * this[3380] + this[3735] * this[3377] + this[3374] * this[3734]);
  result = (v2 * this[3921] * v2 * this[3920] / this[3698] - this[3690]) / this[3691];
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
