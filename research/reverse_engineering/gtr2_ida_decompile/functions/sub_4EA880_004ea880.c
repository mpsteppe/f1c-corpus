char __stdcall sub_4EA880(char a1)
{
  char result; // al

  result = a1;
  if ( byte_B6F118 != a1 )
  {
    byte_B6F118 = a1;
    dword_B6F114 = 0;
  }
  return result;
}
