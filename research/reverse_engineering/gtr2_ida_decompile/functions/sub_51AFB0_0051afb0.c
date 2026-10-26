int __thiscall sub_51AFB0(int this, float *a2)
{
  __int16 v3; // bx
  __int16 v4; // si
  int v5; // eax
  int v6; // ecx
  unsigned __int8 v7; // bl
  int result; // eax
  float v9; // [esp+0h] [ebp-14h]
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+0h] [ebp-14h]

  if ( *a2 <= 255.875 )
  {
    if ( *a2 >= -255.875 )
    {
      v9 = *a2 * 8.0;
      v3 = sub_4015C0(v9);
    }
    else
    {
      v3 = -2047;
    }
  }
  else
  {
    v3 = 2047;
  }
  if ( a2[1] <= 63.875 )
  {
    if ( a2[1] >= -63.875 )
    {
      v10 = a2[1] * 8.0;
      v4 = sub_4015C0(v10);
    }
    else
    {
      v4 = -511;
    }
  }
  else
  {
    v4 = 511;
  }
  if ( a2[2] <= 255.875 )
  {
    if ( a2[2] >= -255.875 )
    {
      v11 = a2[2] * 8.0;
      v5 = sub_4015C0(v11);
    }
    else
    {
      v5 = -2047;
    }
  }
  else
  {
    v5 = 2047;
  }
  v6 = (v3 & 0xFFF) + (((v4 & 0x3FF) + (v5 << 10)) << 12);
  v7 = *(_BYTE *)(this + 12);
  *(_DWORD *)(this + 8) = v6;
  result = (v7 ^ (unsigned __int8)(v5 >> 10)) & 3;
  *(_WORD *)(this + 12) ^= result;
  return result;
}
