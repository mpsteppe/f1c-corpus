int __thiscall sub_4CF5A0(_DWORD *this, float *a2)
{
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int result; // eax
  float v7; // [esp+10h] [ebp+4h]
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+10h] [ebp+4h]

  if ( *a2 <= 32767.98 )
  {
    if ( *a2 >= -32767.98 )
    {
      v7 = *a2 * 64.0;
      v3 = (int)v7;
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
      v8 = a2[1] * 128.0;
      v4 = (int)v8;
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
      v9 = a2[2] * 64.0;
      v5 = (int)v9;
    }
    else
    {
      v5 = -2097151;
    }
  }
  else
  {
    v5 = 0x1FFFFF;
  }
  result = v5 & 0x3FFFFF;
  *this = (v3 & 0x3FFFFF) + (v4 << 22);
  this[1] = result + ((v4 & 0xFFFFFC00) << 12);
  return result;
}
