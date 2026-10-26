int __cdecl FixedPointDivisionWithSignHandling(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v2 = 0;
  v3 = a1;
  if ( a1 < 0 )
  {
    v2 = 1;
    v3 = -a1;
  }
  result = ((__int64)v3 << 16) / a2;
  if ( v2 )
    return -result;
  return result;
}

