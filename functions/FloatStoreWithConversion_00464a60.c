int __thiscall sub_464A60(int this, int a2)
{
  double v3; // st7
  int result; // eax

  *(_DWORD *)(this + 544) = a2;
  if ( a2 < 625000 )
  {
    if ( a2 < 28800 )
    {
      if ( a2 < 7200 )
      {
        if ( a2 < 2975 )
          v3 = 6.0;
        else
          v3 = 10.0;
      }
      else
      {
        v3 = 16.0;
      }
    }
    else
    {
      v3 = 20.0;
    }
  }
  else
  {
    v3 = 32.0;
  }
  result = CRTFtol(1.0 / v3 / 0.0049999999);
  *(_BYTE *)(this + 554) = result;
  return result;
}
