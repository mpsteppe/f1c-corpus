int sub_451B50()
{
  int result; // eax

  result = sub_4634F0(&unk_764D70);
  if ( !(_BYTE)result )
  {
    do
      result = ShowCursor(1);
    while ( result <= 0 );
  }
  return result;
}
