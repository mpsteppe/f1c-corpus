double __thiscall sub_514000(float *this)
{
  double result; // st7
  float v2; // [esp+0h] [ebp-4h]

  if ( this[4697] == 0.0 )
    return 0.0;
  if ( this[4690] == 0.0 )
    return 0.0;
  v2 = this[4391] - (this[4735] * this[4379] + this[4734] * this[4376] + this[4373] * this[4733]);
  result = (v2 * this[4923] * v2 * this[4922] / this[4697] - this[4689]) / this[4690];
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
