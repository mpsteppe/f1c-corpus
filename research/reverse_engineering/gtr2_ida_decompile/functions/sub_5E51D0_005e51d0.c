int __thiscall sub_5E51D0(float *this, float a2, float a3, float a4, float a5, float a6, float a7)
{
  int v8; // edi
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+0h] [ebp-14h]
  float v12; // [esp+4h] [ebp-10h]
  float v13; // [esp+4h] [ebp-10h]
  float v14; // [esp+8h] [ebp-Ch]
  float v15; // [esp+8h] [ebp-Ch]

  v8 = (int)(this + 86);
  v14 = a7 + this[24];
  v12 = a6 + this[23];
  v10 = a5 + this[22];
  sub_5D73C0((int)(this + 86), v10, v12, v14);
  v15 = a4 + this[21];
  v13 = a3 + this[20];
  v11 = a2 + this[19];
  return sub_5D7330(v8, v11, v13, v15);
}
