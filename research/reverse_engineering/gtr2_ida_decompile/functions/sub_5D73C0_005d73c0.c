int __thiscall sub_5D73C0(int this, float a2, float a3, float a4)
{
  long double v4; // st7
  int result; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // rt1
  double v14; // st5
  double v15; // st7
  double v16; // st6
  float v17; // [esp+0h] [ebp-10h]
  float v18; // [esp+4h] [ebp-Ch]
  float v19; // [esp+4h] [ebp-Ch]
  float v20; // [esp+8h] [ebp-8h]
  float v21; // [esp+8h] [ebp-8h]
  float v22; // [esp+Ch] [ebp-4h]
  float v23; // [esp+14h] [ebp+4h]
  float v24; // [esp+18h] [ebp+8h]
  float v25; // [esp+1Ch] [ebp+Ch]

  v20 = fmod(a2, 6.283185482025146);
  *(float *)(this + 84) = v20;
  v18 = fmod(a3, 6.283185482025146);
  *(float *)(this + 88) = v18;
  v4 = fmod(a4, 6.283185482025146);
  *(float *)(this + 92) = v4;
  v23 = sin(v20);
  v24 = cos(v20);
  v25 = sin(v18);
  v21 = cos(v18);
  v17 = sin(v4);
  v19 = cos(v4);
  if ( *(_DWORD *)(this + 68) == 2 )
  {
    result = 0;
    v6 = v25 * v23;
    *(_DWORD *)(this + 16) = 0;
    v7 = v19 * v21;
    v8 = v17 * v21;
    *(float *)(this + 4) = v6 * v17 + v7;
    *(float *)(this + 8) = v17 * v24;
    *(float *)(this + 12) = v23 * v8 - v19 * v25;
    *(_DWORD *)(this + 32) = 0;
    *(float *)(this + 20) = v6 * v19 - v8;
    *(float *)(this + 24) = v19 * v24;
    *(float *)(this + 28) = v7 * v23 + v17 * v25;
    *(_DWORD *)(this + 48) = 0;
    *(float *)(this + 36) = v25 * v24;
    *(float *)(this + 40) = -v23;
    *(float *)(this + 44) = v21 * v24;
  }
  else
  {
    v9 = v19 * v21;
    result = 0;
    *(_DWORD *)(this + 16) = 0;
    v10 = v17 * v21;
    v11 = v19 * v25;
    v12 = v17 * v25;
    v22 = v12;
    *(float *)(this + 4) = v9 - v12 * v23;
    *(float *)(this + 8) = v23 * v11 + v10;
    *(float *)(this + 12) = -(v25 * v24);
    *(float *)(this + 28) = v23;
    *(_DWORD *)(this + 32) = 0;
    *(float *)(this + 20) = -(v17 * v24);
    *(float *)(this + 24) = v19 * v24;
    *(_DWORD *)(this + 48) = 0;
    v13 = v11;
    v14 = v10 * v23;
    *(float *)(this + 36) = v13 + v14;
    *(float *)(this + 40) = v22 - v9 * v23;
    *(float *)(this + 44) = v21 * v24;
    *(float *)(this + 52) = (v13 + v14) * *(float *)(this + 80)
                          + *(float *)(this + 72) * *(float *)(this + 4)
                          + *(float *)(this + 20) * *(float *)(this + 76);
    *(float *)(this + 56) = *(float *)(this + 24) * *(float *)(this + 76)
                          + *(float *)(this + 72) * *(float *)(this + 8)
                          + *(float *)(this + 80) * *(float *)(this + 40);
    v15 = *(float *)(this + 80) * *(float *)(this + 44) + *(float *)(this + 72) * *(float *)(this + 12);
    v16 = *(float *)(this + 28) * *(float *)(this + 76);
    *(_DWORD *)(this + 64) = 1065353216;
    *(float *)(this + 60) = v15 + v16;
  }
  return result;
}
