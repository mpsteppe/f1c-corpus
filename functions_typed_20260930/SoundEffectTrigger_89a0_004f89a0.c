float *__thiscall sub_4F89A0(float *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st6
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  float v10; // [esp+4h] [ebp-8h]
  float v11; // [esp+8h] [ebp-4h]

  v2 = RatioComputationWithClamping((float *)(*(_DWORD *)this + 12));
  v3 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.050000001;
  v11 = v3 + v2 * 0.85000002 + 0.15000001;
  v4 = RatioComputationWithClamping((float *)(*(_DWORD *)this + 12));
  v5 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v7 = RandLCGRandomNumberGenerator(v6);
  if ( v7 >= 10922 )
    v8 = (v7 < 21844) + 15;
  else
    v8 = 17;
  v10 = v5 * 0.050000001 + (v4 - 0.25) * 0.5 + 1.0;
  return HUDElementConfig(this, v8, 1, v11, v10);
}

