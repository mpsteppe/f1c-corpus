int __thiscall sub_51A3B0(int *this, float *a2)
{
  int v3; // esi
  int v4; // edi
  int result; // eax
  float v6; // [esp+0h] [ebp-14h]
  float v7; // [esp+0h] [ebp-14h]
  float v8; // [esp+0h] [ebp-14h]

  if ( *a2 <= 32767.98 )
  {
    if ( *a2 >= -32767.98 )
    {
      v6 = *a2 * 64.0;
      v3 = sub_4015C0(v6);
    }
    else
    {
      v3 = -2097151;
    }
  }
  else
  {
    v3 = 0x1FFFFF;
  }
  if ( a2[1] <= 4095.9919 )
  {
    if ( a2[1] >= -4095.9919 )
    {
      v7 = a2[1] * 128.0;
      v4 = sub_4015C0(v7);
    }
    else
    {
      v4 = -524287;
    }
  }
  else
  {
    v4 = 0x7FFFF;
  }
  if ( a2[2] <= 32767.98 )
  {
    if ( a2[2] >= -32767.98 )
    {
      v8 = a2[2] * 64.0;
      result = sub_4015C0(v8);
    }
    else
    {
      result = -2097151;
    }
  }
  else
  {
    result = 0x1FFFFF;
  }
  *this = v3 & 0x3FFFFF ^ (v4 << 22);
  this[1] = (v4 << 12) ^ (result ^ (v4 << 12)) & 0x3FFFFF;
  return result;
}
