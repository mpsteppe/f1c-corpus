double __thiscall sub_515510(float *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  double v4; // st6
  double result; // st7
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]

  v1 = this[4799] - this[4380];
  v2 = this[4800] - this[4381];
  v3 = this[4801] - this[4382];
  v6 = v3 * this[4377] + v2 * this[4374] + v1 * this[4371];
  v7 = v3 * this[4378] + v2 * this[4375] + v1 * this[4372];
  v4 = v3 * this[4379] + v2 * this[4376] + v1 * this[4373];
  result = sqrt(v4 * v4 + v7 * v7 + v6 * v6) + 3.2;
  if ( this[4805] > result )
    return this[4805];
  return result;
}
