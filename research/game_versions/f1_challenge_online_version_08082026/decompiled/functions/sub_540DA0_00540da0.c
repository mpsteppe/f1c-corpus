int __stdcall sub_540DA0(_DWORD *a1, char a2)
{
  int result; // eax

  if ( a1 )
  {
    if ( (a2 & 4) != 0 )
    {
      result = sub_540F90(a1[7]);
      a1[8] = 0;
    }
    if ( (a2 & 8) != 0 )
    {
      result = sub_5410F0(a1[9]);
      a1[10] = 0;
    }
  }
  return result;
}
