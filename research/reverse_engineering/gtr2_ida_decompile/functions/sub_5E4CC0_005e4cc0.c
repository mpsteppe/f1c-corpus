int __thiscall sub_5E4CC0(float *this, float a2, float a3, float a4)
{
  double v4; // st7
  int v5; // ecx
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v4 = a4 + this[24];
  v5 = (int)(this + 86);
  v9 = v4;
  v8 = a3 + *(float *)(v5 - 252);
  v7 = a2 + *(float *)(v5 - 256);
  return sub_5D73C0(v5, v7, v8, v9);
}
