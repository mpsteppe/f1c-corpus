double __thiscall sub_4962C0(float *this, float a2, float a3)
{
  unsigned int v4; // esi
  double v5; // st7
  float v7; // [esp+0h] [ebp-8h]
  float v9; // [esp+Ch] [ebp+4h]

  v4 = sub_587BDC(a2 * 16.0);
  sub_58957A(a2);
  if ( v4 >= 0x10 )
    return 1.0;
  v9 = this[v4 + 1419];
  if ( v4 == 15 )
    v5 = 1.0;
  else
    v5 = this[v4 + 1420];
  v7 = v5;
  if ( a3 >= 0.0 )
  {
    sub_5881F0(v9);
    v5 = v7;
    sub_5881F0(v7);
  }
  return (v5 - v9) * (a2 * 16.0) + v9;
}
