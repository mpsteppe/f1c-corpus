int __thiscall sub_4CFE90(int this, float *a2)
{
  int v3; // edx
  int v4; // eax
  __int16 v5; // si
  int result; // eax
  float v7; // [esp+Ch] [ebp+4h]
  float v8; // [esp+Ch] [ebp+4h]

  if ( *a2 <= 63.96875 )
  {
    if ( *a2 >= -63.96875 )
    {
      v7 = *a2 * 32.0;
      v3 = (int)v7;
    }
    else
    {
      LOWORD(v3) = -2047;
    }
  }
  else
  {
    LOWORD(v3) = 2047;
  }
  if ( a2[2] <= 63.96875 )
  {
    if ( a2[2] >= -63.96875 )
    {
      v8 = a2[2] * 32.0;
      v4 = (int)v8;
    }
    else
    {
      v4 = -2047;
    }
  }
  else
  {
    v4 = 2047;
  }
  v5 = (v3 & 0xFFF) + ((_WORD)v4 << 12);
  result = v4 >> 4;
  *(_WORD *)(this + 25) = v5;
  *(_BYTE *)(this + 27) = result;
  return result;
}
