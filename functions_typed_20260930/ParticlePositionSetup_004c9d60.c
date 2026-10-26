int __thiscall sub_4C9D60(int this, float a2, float a3, float a4, float a5)
{
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st6
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st6
  double v17; // st5
  unsigned __int8 v19; // c2
  unsigned __int8 v20; // c3
  long double v21; // st4
  int result; // eax
  float v23; // [esp+14h] [ebp+10h]
  float v24; // [esp+14h] [ebp+10h]

  v6 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.2;
  *(float *)(this + 16) = (v6 + 1.0) * a2;
  v7 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.2;
  v8 = (v7 + 1.0) * a3;
  v9 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v10 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v23 = (v10 * 0.2 + 1.0) * a5;
  *(float *)(this + 20) = v8;
  v11 = (v9 * 0.2 + 1.0) * a4 + v8;
  *(float *)(this + 24) = v11;
  *(float *)(this + 28) = v11 + v23;
  if ( v8 == 0.0 )
    *(_DWORD *)(this + 32) = 0;
  else
    *(float *)(this + 32) = 1.0 / v8;
  if ( v23 == 0.0 )
    *(_DWORD *)(this + 36) = 0;
  else
    *(float *)(this + 36) = 1.0 / v23;
  v12 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 40.0;
  v13 = v12 + 214.0;
  *(float *)(this + 40) = v13;
  v24 = v13;
  *(_DWORD *)(this + 96) = ((int)v24 << 24) + 0xFFFFFF;
  v14 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  *(float *)(this + 104) = v14 * 0.2 + 1.0;
  v15 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v16 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v17 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  *(float *)(this + 72) = v17;
  *(float *)(this + 76) = v16;
  *(float *)(this + 80) = v15;
  if ( v20 | v19 )
  {
    *(_DWORD *)(this + 72) = 0;
    *(_DWORD *)(this + 76) = 1065353216;
    *(_DWORD *)(this + 80) = 0;
  }
  else
  {
    v21 = sqrt(
            *(float *)(this + 72) * *(float *)(this + 72)
          + *(float *)(this + 76) * *(float *)(this + 76)
          + *(float *)(this + 80) * *(float *)(this + 80));
    *(float *)(this + 72) = 1.0 / v21 * *(float *)(this + 72);
    *(float *)(this + 76) = 1.0 / v21 * *(float *)(this + 76);
    *(float *)(this + 80) = 1.0 / v21 * *(float *)(this + 80);
  }
  result = RandLCGRandomNumberGenerator(0) % 16;
  *(_DWORD *)(this + 84) = result;
  return result;
}

