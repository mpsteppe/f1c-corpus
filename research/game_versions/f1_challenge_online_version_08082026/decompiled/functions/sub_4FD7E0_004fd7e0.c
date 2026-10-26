double __thiscall sub_4FD7E0(float *this, float a2)
{
  double v4; // st7
  int v5; // eax
  double v6; // st6
  float v7; // [esp+10h] [ebp+4h]

  if ( a2 >= 3.75 )
    return this[40];
  v4 = a2 * 4.0;
  v7 = v4;
  sub_5895A2(v4);
  v5 = sub_587BDC(v4);
  v6 = this[v5 + 25];
  return (this[v5 + 26] - v6) * (v7 - v4) + v6;
}
