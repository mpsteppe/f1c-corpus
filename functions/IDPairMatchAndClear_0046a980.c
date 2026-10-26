int *__stdcall sub_46A980(_DWORD *a1)
{
  int *result; // eax

  result = dword_7D1B08;
  do
  {
    if ( *result == *a1 && result[1] == a1[1] )
    {
      *result = 0;
      result[1] = 89;
    }
    result += 7;
  }
  while ( (int)result < (int)&dword_7D1FD8 );
  return result;
}
