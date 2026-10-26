int __stdcall sub_4FEAA0(float a1)
{
  int result; // eax

  if ( a1 < 0.61650002 )
    return 2;
  if ( a1 < 0.69999999 )
    return 3;
  result = 4;
  if ( a1 >= 0.88 )
    return 5;
  return result;
}
