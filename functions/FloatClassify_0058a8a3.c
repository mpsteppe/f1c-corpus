int __cdecl sub_58A8A3(double a1)
{
  int v1; // eax
  int v2; // eax
  int v4; // eax
  int v5; // eax

  if ( (HIWORD(a1) & 0x7FF0) == 0x7FF0 )
  {
    v1 = UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1)) - 1;
    if ( v1 )
    {
      v2 = v1 - 1;
      if ( !v2 )
        return 4;
      if ( v2 == 1 )
        return 2;
      return 1;
    }
    else
    {
      return 512;
    }
  }
  else if ( (HIWORD(a1) & 0x7FF0) == 0 && ((HIDWORD(a1) & 0xFFFFF) != 0 || LODWORD(a1)) )
  {
    v4 = -((HIWORD(a1) & 0x8000) != 0);
    LOBYTE(v4) = v4 & 0x90;
    return v4 + 128;
  }
  else
  {
    v5 = -((HIWORD(a1) & 0x8000) != 0);
    LOBYTE(v5) = 0;
    if ( a1 == 0.0 )
      return v5 + 64;
    else
      return v5 + 256;
  }
}
