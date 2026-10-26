float *__thiscall sub_4F88A0(float *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st7
  double v6; // st6
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  float v11; // [esp+4h] [ebp-8h]
  float v12; // [esp+8h] [ebp-4h]

  v2 = *(float *)(*(_DWORD *)this + 14752) / *(float *)(*(_DWORD *)this + 14756);
  if ( v2 >= 0.0 )
  {
    if ( v2 > 1.0 )
      v2 = 1.0;
  }
  else
  {
    v2 = 0.0;
  }
  v3 = v2;
  v4 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v12 = v3 * 0.85000002 + 0.15000001 + v4 * 0.050000001;
  v5 = sub_4F1B10((float *)(*(_DWORD *)this + 12));
  v6 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v8 = sub_5884ED(v7);
  if ( v8 >= 10922 )
    v9 = (v8 < 21844) + 12;
  else
    v9 = 14;
  v11 = v6 * 0.050000001 + (v5 - 0.25) * 0.5 + 1.0;
  return sub_4F87C0(this, v9, 1, v12, v11);
}
