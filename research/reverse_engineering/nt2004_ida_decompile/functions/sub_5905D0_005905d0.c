int __thiscall sub_5905D0(int this, float a2, float a3, float a4)
{
  long double v4; // st7
  int result; // eax
  long double v6; // st6
  long double v7; // st5
  long double v8; // rt0
  long double v9; // st4
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+Ch] [ebp+8h]
  float v14; // [esp+Ch] [ebp+8h]
  float v15; // [esp+10h] [ebp+Ch]

  v11 = fmod(a2, 6.283185482025146);
  *(float *)(this + 16) = v11;
  v13 = fmod(a3, 6.283185482025146);
  *(float *)(this + 20) = v13;
  v4 = fmod(a4, 6.283185482025146);
  *(float *)(this + 24) = v4;
  result = 0;
  v6 = sin(v11);
  *(_DWORD *)(this + 52) = 0;
  v12 = cos(v11);
  v7 = sin(v13);
  v14 = cos(v13);
  v8 = sin(v4);
  v9 = cos(v4);
  v10 = v9 * v14;
  v15 = v8 * v14;
  *(float *)(this + 40) = v7 * v6 * v8 + v10;
  *(float *)(this + 44) = v8 * v12;
  *(float *)(this + 48) = v15 * v6 - v9 * v7;
  *(_DWORD *)(this + 68) = 0;
  *(float *)(this + 56) = v7 * v6 * v9 - v15;
  *(float *)(this + 60) = v9 * v12;
  *(float *)(this + 64) = v10 * v6 + v8 * v7;
  *(_DWORD *)(this + 84) = 0;
  *(float *)(this + 72) = v7 * v12;
  *(float *)(this + 76) = -v6;
  *(float *)(this + 80) = v14 * v12;
  return result;
}
