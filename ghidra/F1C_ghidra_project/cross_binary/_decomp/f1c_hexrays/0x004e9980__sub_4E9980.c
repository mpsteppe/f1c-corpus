// f1c  0x004e9980  size=188
double __thiscall sub_4E9980(float *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  double v4; // st6
  double result; // st7
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]

  v1 = this[3800] - this[3381];
  v2 = this[3801] - this[3382];
  v3 = this[3802] - this[3383];
  v6 = v3 * this[3378] + v2 * this[3375] + v1 * this[3372];
  v7 = v3 * this[3379] + v2 * this[3376] + v1 * this[3373];
  v4 = v3 * this[3380] + v2 * this[3377] + v1 * this[3374];
  result = sqrt(v4 * v4 + v7 * v7 + v6 * v6) + 3.2;
  if ( this[3803] > result )
    return this[3803];
  return result;
}
