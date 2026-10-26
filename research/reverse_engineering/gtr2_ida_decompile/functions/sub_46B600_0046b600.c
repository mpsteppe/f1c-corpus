char __thiscall sub_46B600(float *this, float a2, int a3, float a4)
{
  double v4; // st7
  char result; // al
  double v6; // st7
  float v7; // [esp+8h] [ebp+4h]

  v4 = 0.5;
  if ( a3 == 1 )
    v4 = 2.0;
  result = LOBYTE(a2);
  if ( !LOBYTE(a2) )
    v4 = v4 * -1.0;
  v6 = v4 * a4;
  v7 = v6;
  this[41] = fmod(v6 + this[41], 6.283185482025146);
  this[48] = fmod(v7 + this[48], 6.283185482025146);
  return result;
}
