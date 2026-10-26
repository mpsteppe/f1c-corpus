int __thiscall sub_456F70(float *this, char a2, int a3, float a4)
{
  double v4; // st7
  float v6; // [esp+0h] [ebp-4h]

  v4 = 0.40000001;
  if ( a3 == 1 )
    v4 = 6.0;
  if ( !a2 )
    v4 = v4 * -1.0;
  v6 = v4 * a4 + this[43];
  return sub_456FB0(LODWORD(v6));
}
