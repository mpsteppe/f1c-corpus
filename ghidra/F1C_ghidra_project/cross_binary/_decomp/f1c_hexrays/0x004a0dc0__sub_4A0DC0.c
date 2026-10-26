// f1c  0x004a0dc0  size=26
int sub_4A0DC0()
{
  int result; // eax

  byte_7CE260 = 1;
  do
    result = ShowCursor(0);
  while ( result >= 0 );
  return result;
}
