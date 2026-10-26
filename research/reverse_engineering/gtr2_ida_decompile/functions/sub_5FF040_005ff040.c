void __thiscall sub_5FF040(float *this, float a2)
{
  long double v2; // st7
  int v4; // ecx
  long double v5; // st7
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]

  v2 = a2 * 1.3;
  v4 = *((_DWORD *)this + 68);
  this[58] = v2;
  v5 = fabs(atan2(v2, this[56]));
  this[57] = v5 + v5;
  if ( v4 )
  {
    *(float *)&v7 = a2 * 100.0 + this[56];
    *(float *)&v6 = this[56] - a2 * 2.5;
    sub_5E54E0(v4, v6, v7);
    sub_5E5240(*((_DWORD *)this + 68), *((_DWORD *)this + 57), this[57], 0);
    *(_DWORD *)this |= 8u;
  }
}
