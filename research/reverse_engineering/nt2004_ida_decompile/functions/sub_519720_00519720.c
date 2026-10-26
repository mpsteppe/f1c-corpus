void __thiscall sub_519720(int this, float a2)
{
  double v2; // st7
  double v3; // st7
  float v4; // [esp+4h] [ebp+4h]

  v2 = a2 * 0.22499999 + *(float *)(this + 18952);
  *(float *)(this + 18952) = v2;
  v4 = *(float *)(this + 18964) + 0.44999999;
  if ( v2 > v4 )
    *(float *)(this + 18952) = v4;
  if ( *(float *)(this + 18964) + 0.15000001 < *(float *)(this + 18952) )
  {
    if ( !*(_DWORD *)(this + 19720) )
      *(_DWORD *)(this + 19720) = 1;
    v3 = (*(float *)(this + 18972) + *(float *)(this + 18956)) * 0.5;
    if ( v3 < *(float *)(this + 18956) )
      *(float *)(this + 18956) = v3;
  }
  if ( *(float *)(this + 18964) + 0.30000001 < *(float *)(this + 18952) )
    *(_DWORD *)(this + 18956) = *(_DWORD *)(this + 18972);
  sub_513830(this, 0);
}
