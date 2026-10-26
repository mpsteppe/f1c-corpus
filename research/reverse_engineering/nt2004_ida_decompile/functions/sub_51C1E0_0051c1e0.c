int __thiscall sub_51C1E0(float *this, float *a2, _DWORD *a3)
{
  int v3; // ecx
  double v4; // st7
  double v5; // st6
  int result; // eax
  float v7; // [esp+0h] [ebp-Ch] BYREF
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  sub_51BCE0(this, (int)&v7);
  v4 = v9 * *(float *)(v3 + 17492);
  v5 = v8 * *(float *)(v3 + 17488);
  v3 += 17532;
  *a2 = v4 + v5 + v7 * *(float *)(v3 - 48);
  a2[1] = v9 * *(float *)(v3 - 28) + v7 * *(float *)(v3 - 36) + v8 * *(float *)(v3 - 32);
  a2[2] = v9 * *(float *)(v3 - 16) + v7 * *(float *)(v3 - 24) + v8 * *(float *)(v3 - 20);
  *a2 = *a2 + *(float *)(v3 - 12);
  a2[1] = *(float *)(v3 - 8) + a2[1];
  a2[2] = *(float *)(v3 - 4) + a2[2];
  *a3 = *(_DWORD *)v3;
  result = *(_DWORD *)(v3 + 4);
  a3[1] = result;
  a3[2] = *(_DWORD *)(v3 + 8);
  return result;
}
