int sub_45DDE0()
{
  int result; // eax

  result = sub_473630(&dword_B6CBA8);
  if ( !(_BYTE)result )
  {
    do
      result = ShowCursor(1);
    while ( result <= 0 );
  }
  return result;
}
