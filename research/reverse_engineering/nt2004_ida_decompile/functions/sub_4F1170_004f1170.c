int __thiscall sub_4F1170(int this, float a2, float a3, float a4, float a5, float a6, float a7)
{
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st6
  double v13; // st5
  double v14; // st5
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st6
  double v21; // st5
  unsigned __int8 v23; // c2
  unsigned __int8 v24; // c3
  long double v25; // st4
  int result; // eax
  float v27; // [esp+14h] [ebp+10h]
  float v28; // [esp+14h] [ebp+10h]

  v8 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.2;
  *(float *)(this + 16) = (v8 + 1.0) * a2;
  v9 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.2;
  v10 = (v9 + 1.0) * a3;
  v11 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v12 = (v11 * 0.2 + 1.0) * a4;
  v13 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v27 = (v13 * 0.2 + 1.0) * a5;
  v14 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
  if ( v14 < a6 )
  {
    *(float *)(this + 16) = a7 * *(float *)(this + 16);
    v12 = v12 * a7;
    v27 = v27 * a7;
  }
  *(float *)(this + 20) = v10;
  v15 = v12 + v10;
  *(float *)(this + 24) = v15;
  *(float *)(this + 28) = v15 + v27;
  if ( v10 == 0.0 )
    *(_DWORD *)(this + 32) = 0;
  else
    *(float *)(this + 32) = 1.0 / v10;
  if ( v27 == 0.0 )
    *(_DWORD *)(this + 36) = 0;
  else
    *(float *)(this + 36) = 1.0 / v27;
  v16 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 40.0;
  v17 = v16 + 214.0;
  *(float *)(this + 40) = v17;
  v28 = v17;
  *(_DWORD *)(this + 96) = ((int)v28 << 24) + 0xFFFFFF;
  v18 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  *(float *)(this + 104) = v18 * 0.2 + 1.0;
  v19 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v20 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v21 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  *(float *)(this + 72) = v21;
  *(float *)(this + 76) = v20;
  *(float *)(this + 80) = v19;
  if ( v24 | v23 )
  {
    *(_DWORD *)(this + 72) = 0;
    *(_DWORD *)(this + 76) = 1065353216;
    *(_DWORD *)(this + 80) = 0;
  }
  else
  {
    v25 = sqrt(
            *(float *)(this + 72) * *(float *)(this + 72)
          + *(float *)(this + 76) * *(float *)(this + 76)
          + *(float *)(this + 80) * *(float *)(this + 80));
    *(float *)(this + 72) = 1.0 / v25 * *(float *)(this + 72);
    *(float *)(this + 76) = 1.0 / v25 * *(float *)(this + 76);
    *(float *)(this + 80) = 1.0 / v25 * *(float *)(this + 80);
  }
  result = rand() % 16;
  *(_DWORD *)(this + 84) = result;
  return result;
}
