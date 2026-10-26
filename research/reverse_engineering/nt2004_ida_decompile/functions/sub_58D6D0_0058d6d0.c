int *sub_58D6D0()
{
  int *result; // eax

  result = dword_8000C4;
  do
  {
    *(result - 1) = 0;
    *result = 0;
    result += 2;
  }
  while ( (int)result < (int)&dword_800104 );
  return result;
}
