int __thiscall sub_51ABA0(_WORD *this, int a2, float a3, float a4)
{
  int v5; // esi
  long double v6; // st7
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  long double v10; // st7
  int result; // eax
  int v12; // eax
  float v13; // [esp+0h] [ebp-14h]
  float v14; // [esp+0h] [ebp-14h]
  float v15; // [esp+0h] [ebp-14h]
  float v16; // [esp+0h] [ebp-14h]
  float v17; // [esp+1Ch] [ebp+8h]
  float v18; // [esp+1Ch] [ebp+8h]

  v5 = a3 < 0.0;
  v6 = fabs(a3);
  if ( v6 >= 0.12304688 )
  {
    v17 = (v6 - 0.125) * 64.0;
    if ( sub_4015C0(v17) <= 31 )
      v8 = sub_4015C0(v17);
    else
      v8 = 31;
    v7 = (v5 << 6) + v8 + 32;
  }
  else
  {
    v13 = v6 * 256.0;
    v7 = (v5 << 6) + sub_4015C0(v13);
  }
  v9 = a4 < 0.0;
  v10 = fabs(a4);
  if ( v10 >= 19.875 )
  {
    if ( v10 >= 83.5 )
    {
      v18 = (v10 - 84.0) * 0.25;
      if ( sub_4015C0(v18) <= 63 )
        v12 = sub_4015C0(v18);
      else
        v12 = 63;
      result = v7 + (((v9 << 8) + v12 + 192) << 7);
      this[a2 + 4] = result;
    }
    else
    {
      v16 = v10 - 20.0;
      result = v7 + ((sub_4015C0(v16) + (v9 << 8) + 128) << 7);
      this[a2 + 4] = result;
    }
  }
  else
  {
    if ( v10 >= 3.96875 )
    {
      v15 = (v10 - 4.0) * 4.0;
      result = v7 + ((sub_4015C0(v15) + (v9 << 8) + 64) << 7);
    }
    else
    {
      v14 = v10 * 16.0;
      result = v7 + (((v9 << 8) + sub_4015C0(v14)) << 7);
    }
    this[a2 + 4] = result;
  }
  return result;
}
