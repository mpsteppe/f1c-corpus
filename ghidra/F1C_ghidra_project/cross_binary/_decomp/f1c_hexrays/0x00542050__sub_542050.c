// f1c  0x00542050  size=422
char __thiscall sub_542050(int this, float a2, float a3, int a4)
{
  double v4; // st7
  long double v5; // st6
  long double v6; // st7
  long double v7; // st7
  long double v8; // st6
  long double v9; // st7
  long double v10; // st6
  char result; // al
  float v12; // [esp+0h] [ebp-8h]
  float v13; // [esp+4h] [ebp-4h]
  float v14; // [esp+Ch] [ebp+4h]
  float v15; // [esp+Ch] [ebp+4h]
  float v16; // [esp+10h] [ebp+8h]
  float v17; // [esp+14h] [ebp+Ch]

  *(float *)(this + 108) = a2;
  if ( a4 )
    v4 = a3;
  else
    v4 = (double)dword_8B8DD8 / (double)dword_8B8DD4 * 1.33334 * a2 * 0.80385852;
  *(float *)(this + 112) = v4;
  v5 = a2 * 0.5;
  v14 = v5;
  v12 = tan(v5);
  *(float *)(this + 28) = v12;
  v6 = v4 * 0.5;
  v17 = v6;
  v13 = tan(v6);
  *(float *)(this + 32) = v13;
  v7 = sin(v14);
  v8 = cos(v14);
  v16 = sin(v17);
  v15 = cos(v17);
  *(float *)(this + 12) = (double)*(int *)(this + 84) * 0.5 / v12;
  *(float *)(this + 16) = (double)*(int *)(this + 88) * 0.5 / v13;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = -1082130432;
  *(float *)(this + 248) = -*(float *)(this + 8);
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 224) = 0;
  *(_DWORD *)(this + 228) = 1065353216;
  *(_DWORD *)(this + 232) = *(_DWORD *)(this + 4);
  *(float *)(this + 156) = -v8;
  *(float *)(this + 164) = v7;
  *(_DWORD *)(this + 160) = 0;
  *(_DWORD *)(this + 168) = 0;
  *(float *)(this + 172) = v8;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(float *)(this + 180) = v7;
  *(float *)(this + 192) = v15;
  *(_DWORD *)(this + 188) = 0;
  *(float *)(this + 196) = v16;
  *(_DWORD *)(this + 200) = 0;
  *(float *)(this + 208) = -v15;
  *(_DWORD *)(this + 204) = 0;
  *(float *)(this + 212) = v16;
  *(_DWORD *)(this + 216) = 0;
  v9 = tan(*(float *)(this + 108) * 0.5) * *(float *)(this + 8);
  v10 = tan(*(float *)(this + 112) * 0.5) * *(float *)(this + 8);
  result = *(_BYTE *)(this + 128);
  *(float *)(this + 120) = sqrt(v10 * v10 + v9 * v9);
  if ( (result & 0x10) != 0 )
    *(float *)(this + 12) = -*(float *)(this + 12);
  return result;
}
