int __thiscall sub_5E4D00(int this, float a2, float a3, float a4)
{
  int v5; // edi
  double v6; // st7
  double v7; // st7
  double v8; // st7
  float v10; // [esp+0h] [ebp-20h]
  float v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+8h] [ebp-18h]
  float v13; // [esp+14h] [ebp-Ch] BYREF
  float v14; // [esp+18h] [ebp-8h] BYREF
  float v15; // [esp+1Ch] [ebp-4h] BYREF

  v5 = this + 344;
  sub_5D7600((_DWORD *)(this + 344), &v15, &v14, &v13);
  v15 = v15 - *(float *)(this + 88);
  v6 = v14;
  *(float *)(this + 88) = a2;
  v7 = v6 - *(float *)(this + 92);
  *(float *)(this + 92) = a3;
  v14 = v7;
  v8 = v13 - *(float *)(this + 96);
  *(float *)(this + 96) = a4;
  v13 = v8;
  v12 = v13 + a4;
  v11 = v14 + a3;
  v10 = v15 + a2;
  return sub_5D73C0(v5, v10, v11, v12);
}
