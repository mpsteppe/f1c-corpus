int __thiscall sub_5E4C80(float *this, float a2, float a3, float a4)
{
  double v4; // st7
  int v5; // ecx
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v4 = a4 + this[21];
  v5 = (int)(this + 86);
  v9 = v4;
  v8 = a3 + *(float *)(v5 - 264);
  v7 = a2 + *(float *)(v5 - 268);
  return sub_5D7330(v5, v7, v8, v9);
}
