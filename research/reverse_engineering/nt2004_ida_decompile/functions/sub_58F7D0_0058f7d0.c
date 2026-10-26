BOOL __cdecl sub_58F7D0(unsigned int a1, int a2, char a3)
{
  BOOL result; // eax

  result = 0;
  if ( ((a1 >> (2 * a3)) & 3) == 1 )
    return a2 != 0;
  if ( ((a1 >> (2 * a3)) & 3) == 2 )
    return a2 != -1;
  return result;
}
