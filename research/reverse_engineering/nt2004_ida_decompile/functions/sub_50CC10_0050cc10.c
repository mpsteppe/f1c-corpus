int __thiscall sub_50CC10(float *this, int a2, float *a3, float a4, float a5, float a6)
{
  int v6; // ebx
  double v7; // st7
  float *v8; // esi
  float *v9; // esi
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]

  v6 = (int)&this[76 * a2 + 55];
  v11 = *a3 - this[18];
  v12 = a3[1] - this[19];
  v7 = a3[2] - this[20];
  v8 = &this[76 * a2 + 86];
  *v8 = v11;
  v13 = v7;
  v8[1] = v12;
  v8[2] = v13;
  *(float *)(v6 + 192) = v11;
  *(float *)(v6 + 196) = v12;
  *(float *)(v6 + 200) = v13;
  *(float *)(v6 + 260) = a4;
  *(float *)(v6 + 256) = a5;
  *(float *)(v6 + 208) = a5;
  v9 = &this[76 * a2 + 109];
  *(_DWORD *)(v6 + 204) = 0;
  *(float *)(v6 + 212) = a6;
  sub_5798E0(a5, a6);
  qmemcpy((void *)(v6 + 148), v9, 0x24u);
  return sub_579B50(a4, v6 + 136);
}
