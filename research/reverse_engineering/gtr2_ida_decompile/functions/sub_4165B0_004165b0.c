int __thiscall sub_4165B0(__int16 *this, float *a2)
{
  __int16 v3; // ax
  __int16 v4; // ax
  int result; // eax
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+0h] [ebp-Ch]

  if ( *a2 <= 255.99001 )
  {
    if ( *a2 >= -255.99001 )
    {
      v6 = *a2 * 128.0;
      v3 = sub_4015C0(v6);
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
  *this = v3;
  if ( a2[1] <= 255.99001 )
  {
    if ( a2[1] >= -255.99001 )
    {
      v7 = a2[1] * 128.0;
      v4 = sub_4015C0(v7);
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
  this[1] = v4;
  if ( a2[2] <= 255.99001 )
  {
    if ( a2[2] >= -255.99001 )
    {
      v8 = a2[2] * 128.0;
      result = (__int16)sub_4015C0(v8);
      this[2] = result;
    }
    else
    {
      result = -32767;
      this[2] = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    this[2] = 0x7FFF;
  }
  return result;
}
