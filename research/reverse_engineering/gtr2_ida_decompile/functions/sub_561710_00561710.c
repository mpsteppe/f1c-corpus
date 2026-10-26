int sub_561710()
{
  int result; // eax

  sub_48B790();
  result = 4;
  if ( NP_UnregisterWindowHandle )
    return NP_UnregisterWindowHandle();
  return result;
}
