int *sub_58D340()
{
  int *result; // eax

  result = &dword_800104;
  do
  {
    *((_WORD *)result - 2) = -1;
    *result = 0;
    result += 2;
  }
  while ( (int)result < (int)dword_800144 );
  return result;
}
