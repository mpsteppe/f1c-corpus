int __thiscall sub_42FCE0(int this, int a2)
{
  long double v2; // st7
  int v3; // ebx
  float v5; // [esp+0h] [ebp-C4h]
  float v6[16]; // [esp+4h] [ebp-C0h] BYREF
  _BYTE v7[64]; // [esp+44h] [ebp-80h] BYREF
  _BYTE v8[64]; // [esp+84h] [ebp-40h] BYREF

  v5 = **(float **)(this + 16);
  v2 = sin(v5);
  v3 = *(_DWORD *)(this + 12);
  v6[1] = 0.0;
  v6[3] = 0.0;
  v6[4] = 0.0;
  v6[5] = 1.0;
  v6[6] = 0.0;
  v6[7] = 0.0;
  v6[9] = 0.0;
  memset(&v6[11], 0, 16);
  v6[15] = 1.0;
  v6[0] = cos(v5);
  v6[2] = -v2;
  v6[8] = v2;
  v6[10] = v6[0];
  qmemcpy(v7, sub_42FBC0((char *)v6, v8, (float *)(v3 + 68)), sizeof(v7));
  return sub_5C0560(v3, v7);
}
