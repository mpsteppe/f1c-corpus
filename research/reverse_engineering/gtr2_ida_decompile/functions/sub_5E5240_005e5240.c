void __thiscall sub_5E5240(int this, int a2, float a3, __int16 a4)
{
  long double v4; // st7
  long double v5; // st7
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  double v10; // st5
  double v11; // st6
  long double v12; // rt1
  long double v13; // st5
  float v14; // [esp+0h] [ebp-8h]
  float v15; // [esp+4h] [ebp-4h]
  float v16; // [esp+10h] [ebp+8h]
  float v17; // [esp+10h] [ebp+8h]
  float v18; // [esp+14h] [ebp+Ch]

  if ( (a4 & 0x200) != 0 || *(float *)(this + 128) != a3 )
  {
    *(float *)(this + 128) = a3;
    *(float *)(this + 48) = a3 * 57.29578;
    v4 = a3 * 0.5;
    v16 = v4;
    v5 = tan(v4);
    v6 = atan2((double)*(int *)(this + 100) / (double)*(int *)(this + 104) * v5, 1.0);
    v7 = v6 + v6;
    *(float *)(this + 124) = v7;
    *(float *)(this + 44) = 57.29578 * v7;
    *(_DWORD *)(this + 232) = 0;
    *(_DWORD *)(this + 236) = 0;
    v8 = v7 * 0.5;
    *(_DWORD *)(this + 240) = 1065353216;
    v15 = v8;
    v18 = sin(v8);
    v9 = cos(v8);
    v14 = sin(v16);
    v17 = cos(v16);
    *(float *)(this + 244) = -*(float *)(this + 40);
    *(_DWORD *)(this + 216) = 0;
    *(_DWORD *)(this + 220) = 0;
    *(_DWORD *)(this + 224) = -1082130432;
    *(_DWORD *)(this + 228) = *(_DWORD *)(this + 36);
    *(float *)(this + 152) = -v9;
    v10 = -v18;
    *(_DWORD *)(this + 156) = 0;
    *(float *)(this + 160) = v10;
    *(_DWORD *)(this + 164) = 0;
    *(_DWORD *)(this + 172) = 0;
    *(float *)(this + 168) = v9;
    *(_DWORD *)(this + 180) = 0;
    *(float *)(this + 176) = v10;
    *(_DWORD *)(this + 184) = 0;
    *(float *)(this + 188) = v17;
    v11 = -v14;
    *(_DWORD *)(this + 196) = 0;
    *(float *)(this + 192) = v11;
    *(_DWORD *)(this + 200) = 0;
    *(float *)(this + 204) = -v17;
    *(float *)(this + 208) = v11;
    *(_DWORD *)(this + 212) = 0;
    v12 = tan(v15) * *(float *)(this + 40);
    v13 = v5 * *(float *)(this + 40);
    *(float *)(this + 136) = sqrt(v13 * v13 + v12 * v12);
  }
}
