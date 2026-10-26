int __thiscall sub_5D7630(float *this, int a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st5
  double v5; // st4
  double v6; // st7
  double v7; // st6
  float v8; // [esp+0h] [ebp-1Ch]
  float v9; // [esp+4h] [ebp-18h]
  float v10; // [esp+8h] [ebp-14h]
  float v11; // [esp+Ch] [ebp-10h]
  float v12; // [esp+10h] [ebp-Ch]
  float v13; // [esp+14h] [ebp-8h]
  float v14; // [esp+18h] [ebp-4h]

  result = a2;
  v3 = *this + *this;
  v4 = this[1] + this[1];
  v14 = v4 * this[1];
  v5 = this[2] + this[2];
  v10 = v5 * this[2];
  v11 = v5 * *this;
  v9 = v4 * *this;
  v12 = v4 * this[3];
  v13 = v3 * this[3];
  v6 = v3 * *this;
  v8 = v5 * this[3];
  v7 = v5 * this[1];
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)a2 = 1.0 - (v10 + v14);
  *(float *)(a2 + 4) = v9 - v8;
  *(float *)(a2 + 8) = v12 + v11;
  *(float *)(a2 + 16) = v8 + v9;
  *(float *)(a2 + 20) = 1.0 - (v10 + v6);
  *(float *)(a2 + 24) = v7 - v13;
  *(float *)(a2 + 32) = v11 - v12;
  *(float *)(a2 + 36) = v7 + v13;
  *(float *)(a2 + 40) = 1.0 - (v14 + v6);
  return result;
}
