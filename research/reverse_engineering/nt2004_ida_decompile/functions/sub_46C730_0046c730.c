__int64 __thiscall sub_46C730(int this, int a2)
{
  double v2; // st7
  __int64 result; // rax

  *(_DWORD *)(this + 268) = a2;
  if ( a2 < 625000 )
  {
    if ( a2 < 28800 )
    {
      if ( a2 < 7200 )
      {
        if ( a2 < 2975 )
          v2 = 6.0;
        else
          v2 = 10.0;
      }
      else
      {
        v2 = 16.0;
      }
    }
    else
    {
      v2 = 20.0;
    }
  }
  else
  {
    v2 = 32.0;
  }
  result = (__int64)(1.0 / v2 / 0.0049999999);
  *(_BYTE *)(this + 278) = result;
  return result;
}
