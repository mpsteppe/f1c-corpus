int __thiscall sub_4B31A0(_WORD *this, float *a2)
{
  __int16 v3; // ax
  __int16 v4; // ax
  int result; // eax
  int v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]

  if ( *a2 <= 15.999512 )
  {
    if ( *a2 >= -15.999512 )
    {
      v7 = *a2 * 2048.0;
      v3 = (int)v7;
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
  this[6] = v3;
  if ( a2[1] <= 15.999512 )
  {
    if ( a2[1] >= -15.999512 )
    {
      v8 = a2[1] * 2048.0;
      v4 = (int)v8;
    }
    else
    {
      v4 = -32767;
    }
  }
  else
  {
    v4 = 0x7FFF;
  }
  this[7] = v4;
  if ( a2[2] <= 15.999512 )
  {
    if ( a2[2] >= -15.999512 )
    {
      v9 = a2[2] * 2048.0;
      v6 = (int)v9;
      result = (__int16)v6;
      this[8] = v6;
    }
    else
    {
      result = -32767;
      this[8] = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    this[8] = 0x7FFF;
  }
  return result;
}

