int __thiscall sub_569480(float *this, int a2, float *a3, float a4, float a5, float a6)
{
  int v6; // ebx
  double v7; // st7
  float *v8; // esi
  float *v9; // esi
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]

  v6 = (int)&this[74 * a2 + 88];
  v11 = *a3 - this[19];
  v12 = a3[1] - this[20];
  v7 = a3[2] - this[21];
  v8 = &this[74 * a2 + 117];
  *v8 = v11;
  v13 = v7;
  v8[1] = v12;
  v8[2] = v13;
  *(float *)(v6 + 184) = v11;
  *(float *)(v6 + 188) = v12;
  *(float *)(v6 + 192) = v13;
  *(float *)(v6 + 252) = a4;
  *(float *)(v6 + 248) = a5;
  *(float *)(v6 + 200) = a5;
  v9 = &this[74 * a2 + 140];
  *(_DWORD *)(v6 + 196) = 0;
  *(float *)(v6 + 204) = a6;
  sub_614EF0(a5, a6);
  qmemcpy((void *)(v6 + 140), v9, 0x24u);
  return sub_615100(a4, v6 + 128);
}
