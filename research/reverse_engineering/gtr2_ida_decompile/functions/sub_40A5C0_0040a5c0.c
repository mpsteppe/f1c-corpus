int __thiscall sub_40A5C0(int this, _DWORD *a2, float *a3)
{
  long double v3; // st7
  long double v4; // rt0
  int result; // eax
  float v6; // [esp+8h] [ebp-18h]
  float v7; // [esp+Ch] [ebp-14h]
  float v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+24h] [ebp+4h]

  *(_DWORD *)(this + 88) = *a2;
  *(_DWORD *)(this + 92) = a2[1];
  *(_DWORD *)(this + 96) = a2[2];
  *(float *)(this + 100) = *a3;
  *(float *)(this + 104) = a3[1];
  *(float *)(this + 108) = a3[2];
  v3 = sin(a3[1]);
  v4 = -cos(a3[1]);
  v9 = -sin(*a3) * 0.0;
  v6 = v9 - v4;
  v7 = v4 * 0.0 - v3 * 0.0;
  *(float *)(this + 112) = v6;
  v8 = v3 - v9;
  result = LODWORD(v7);
  *(float *)(this + 116) = v7;
  *(float *)(this + 120) = v8;
  return result;
}
