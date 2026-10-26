int sub_45DE00()
{
  int result; // eax

  result = sub_473630(&dword_B6CBA8);
  if ( !(_BYTE)result )
  {
    do
      result = ShowCursor(0);
    while ( result >= 0 );
  }
  return result;
}
