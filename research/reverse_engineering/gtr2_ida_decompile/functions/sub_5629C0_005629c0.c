int __thiscall sub_5629C0(float *this, int a2)
{
  float v3; // edi
  float v4; // ebp
  int result; // eax
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+14h] [ebp+4h]
  float v10; // [esp+14h] [ebp+4h]
  float v11; // [esp+14h] [ebp+4h]

  if ( *(float *)&a2 != 0.0 )
  {
    v6 = this[64] * 0.0;
    v9 = this[65] * 0.0;
    v3 = v9;
    v8 = this[64] * 1280.0;
    v7 = this[65] * 50.0;
    sub_5EDF20(a2, 0, v6, v9, 1.0, 0.0, 0.0, 0x80000000);
    v10 = v7 + v9;
    v4 = v10;
    sub_5EDF20(a2, 1, v6, v10, 1.0, 0.0, 1.0, 0x80000000);
    v11 = v8 + v6;
    sub_5EDF20(a2, 2, v11, v4, 1.0, 1.0, 1.0, 0x80000000);
    return sub_5EDF20(a2, 3, v11, v3, 1.0, 1.0, 0.0, 0x80000000);
  }
  return result;
}
