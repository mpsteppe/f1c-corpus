int __thiscall sub_4D90D0(int this, float a2)
{
  double v2; // st7
  float v3; // edi
  float v4; // ebp
  int result; // eax
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+14h] [ebp+4h]
  float v10; // [esp+14h] [ebp+4h]
  float v11; // [esp+14h] [ebp+4h]

  if ( a2 != 0.0 )
  {
    if ( *(_DWORD *)(this + 8) == -1 )
      v2 = 0.0;
    else
      v2 = 140.0;
    v6 = *(float *)(this + 228) * 0.0;
    v9 = v2 * *(float *)(this + 232);
    v3 = v9;
    v8 = *(float *)(this + 228) * 1280.0;
    v7 = *(float *)(this + 232) * 50.0;
    sub_553650(0, v6, v9, 1.0, 0.0, 0.0, 0x80000000);
    v10 = v7 + v9;
    v4 = v10;
    sub_553650(1, v6, v10, 1.0, 0.0, 1.0, 0x80000000);
    v11 = v8 + v6;
    sub_553650(2, v11, v4, 1.0, 1.0, 1.0, 0x80000000);
    return sub_553650(3, v11, v3, 1.0, 1.0, 0.0, 0x80000000);
  }
  return result;
}

