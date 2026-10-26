int *__stdcall sub_477B50(_DWORD *a1)
{
  int *result; // eax

  result = dword_76A67C;
  do
  {
    if ( *result == *a1 && result[1] == a1[1] )
    {
      *result = 0;
      result[1] = 89;
    }
    result += 7;
  }
  while ( (int)result < (int)&dword_76AD28 );
  return result;
}
