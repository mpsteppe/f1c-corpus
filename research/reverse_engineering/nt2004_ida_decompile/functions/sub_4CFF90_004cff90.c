int __thiscall sub_4CFF90(_WORD *this, int a2, float a3, float a4)
{
  int v4; // edx
  long double v5; // st7
  int v6; // esi
  int v7; // eax
  int v8; // edx
  long double v9; // st7
  int v10; // eax
  int result; // eax
  float v12; // [esp+4h] [ebp-4h]
  float v13; // [esp+4h] [ebp-4h]
  float v14; // [esp+10h] [ebp+8h]
  float v15; // [esp+10h] [ebp+8h]
  float v16; // [esp+10h] [ebp+8h]
  float v17; // [esp+10h] [ebp+8h]

  v4 = a3 < 0.0;
  v5 = fabs(a3);
  if ( v5 >= 0.12304688 )
  {
    v12 = (v5 - 0.125) * 64.0;
    LOWORD(v7) = 31;
    if ( (int)v12 <= 31 )
      v7 = (int)v12;
    LOWORD(v6) = ((_WORD)v4 << 6) + v7 + 32;
  }
  else
  {
    v14 = v5 * 256.0;
    v6 = (int)v14 + (v4 << 6);
  }
  v8 = a4 < 0.0;
  v9 = fabs(a4);
  if ( v9 >= 19.875 )
  {
    if ( v9 >= 83.5 )
    {
      v13 = (v9 - 84.0) * 0.25;
      LOWORD(v10) = 63;
      if ( (int)v13 <= 63 )
        v10 = (int)v13;
      LOWORD(v8) = ((_WORD)v8 << 8) + v10 + 192;
    }
    else
    {
      v17 = v9 - 20.0;
      v8 = (v8 << 8) + (int)v17 + 128;
    }
  }
  else if ( v9 >= 3.96875 )
  {
    v16 = (v9 - 4.0) * 4.0;
    v8 = (v8 << 8) + (int)v16 + 64;
  }
  else
  {
    v15 = v9 * 16.0;
    v8 = (int)v15 + (v8 << 8);
  }
  result = a2;
  this[a2 + 4] = v6 + ((_WORD)v8 << 7);
  return result;
}
