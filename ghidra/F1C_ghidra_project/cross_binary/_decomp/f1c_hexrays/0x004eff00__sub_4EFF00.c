// f1c  0x004eff00  size=196
double __thiscall sub_4EFF00(float *this)
{
  float v2; // edx
  long double v3; // st7
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]

  if ( this[3387] == 0.0 && this[3388] == 0.0 && this[3389] == 0.0 )
    return 0.0;
  v2 = this[3388];
  v4 = this[3387];
  v7 = this[3389];
  v3 = 1.0 / sqrt(v7 * v7 + v2 * v2 + v4 * v4);
  v5 = v4 * v3;
  v6 = v2 * v3;
  return -(v3 * v7 * this[3380] + v6 * this[3377] + v5 * this[3374]);
}
