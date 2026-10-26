int __thiscall sub_573990(char *this, float *a2)
{
  char v3; // al
  char v4; // al
  int result; // eax
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+0h] [ebp-Ch]

  if ( *a2 <= 1.0 )
  {
    if ( *a2 >= -1.0 )
    {
      v6 = *a2 * 127.0;
      v3 = sub_4015C0(v6);
    }
    else
    {
      v3 = -127;
    }
  }
  else
  {
    v3 = 127;
  }
  *this = v3;
  if ( a2[1] <= 1.0 )
  {
    if ( a2[1] >= -1.0 )
    {
      v7 = a2[1] * 127.0;
      v4 = sub_4015C0(v7);
    }
    else
    {
      v4 = -127;
    }
  }
  else
  {
    v4 = 127;
  }
  this[1] = v4;
  if ( a2[2] <= 1.0 )
  {
    if ( a2[2] >= -1.0 )
    {
      v8 = a2[2] * 127.0;
      result = (char)sub_4015C0(v8);
      this[2] = result;
    }
    else
    {
      result = -127;
      this[2] = -127;
    }
  }
  else
  {
    result = 127;
    this[2] = 127;
  }
  return result;
}
