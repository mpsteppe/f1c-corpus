int __thiscall sub_4B2750(_WORD *this, float *a2)
{
  __int16 v3; // ax
  int result; // eax
  int v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]

  if ( *a2 <= 63.998047 )
  {
    if ( *a2 >= -63.998047 )
    {
      v6 = *a2 * 512.0;
      v3 = (int)v6;
    }
    else
    {
      v3 = -32767;
    }
  }
  else
  {
    v3 = 0x7FFF;
  }
  this[20] = v3;
  if ( a2[2] <= 63.998047 )
  {
    if ( a2[2] >= -63.998047 )
    {
      v7 = a2[2] * 512.0;
      v5 = (int)v7;
      result = (__int16)v5;
      this[21] = v5;
    }
    else
    {
      result = -32767;
      this[21] = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    this[21] = 0x7FFF;
  }
  return result;
}
