double __thiscall sub_529A00(int this, int a2)
{
  double result; // st7
  float v3; // [esp+4h] [ebp+4h]

  if ( a2 == 1 )
  {
    if ( (*(_BYTE *)(this + 36) & 2) != 0 )
    {
      return *(float *)(this + 32);
    }
    else
    {
      result = *(float *)(this + 28) + 4.5;
      if ( result >= *(float *)(this + 128) )
        result = *(float *)(this + 128);
      *(float *)(this + 32) = result;
    }
  }
  else if ( a2 )
  {
    if ( a2 == 3 )
    {
      return *(float *)(this + 228);
    }
    else if ( a2 == 4 )
    {
      return *(float *)(this + 232);
    }
    else
    {
      return 0.0;
    }
  }
  else if ( (*(_BYTE *)(this + 36) & 1) != 0 )
  {
    return *(float *)(this + 28);
  }
  else
  {
    if ( *(float *)(this + 128) <= 4.5 )
      result = *(float *)(this + 128) - 4.5;
    else
      result = 0.0;
    v3 = -*(float *)(this + 124);
    if ( result < v3 )
      result = v3;
    *(float *)(this + 28) = result;
  }
  return result;
}
