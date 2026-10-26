// f1c  0x00407d40  size=144
int __thiscall sub_407D40(int this, _DWORD *a2, float *a3)
{
  double v3; // st6
  long double v4; // st5
  long double v5; // st7
  int result; // eax
  float v7; // [esp+10h] [ebp-4h]
  float v8; // [esp+10h] [ebp-4h]
  float v9; // [esp+18h] [ebp+4h]

  *(_DWORD *)(this + 88) = *a2;
  *(_DWORD *)(this + 92) = a2[1];
  *(_DWORD *)(this + 96) = a2[2];
  *(float *)(this + 100) = *a3;
  *(float *)(this + 104) = a3[1];
  *(float *)(this + 108) = a3[2];
  v7 = -cos(a3[1]);
  v9 = -sin(*a3) * 0.0;
  v3 = v9 - v7;
  v4 = sin(a3[1]);
  v5 = v7 * 0.0 - v4 * 0.0;
  v8 = v4 - v9;
  result = LODWORD(v8);
  *(float *)(this + 120) = v8;
  *(float *)(this + 112) = v3;
  *(float *)(this + 116) = v5;
  return result;
}
